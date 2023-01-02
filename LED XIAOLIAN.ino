//申明引脚
int ROWS[] ={10,11,12,13,A0,A1,A2,A3};
int COLS[] ={2,3,4,5,6,7,8,9};
// 定义笑脸图案//1=开，0=关
unsigned char smile[8][8] ={
  0,0,0,0,0,0,0,0,
  0,0,1,0,0,1,0,0,
  0,0,1,0,0,1,0,0,
  0,0,1,0,0,1,0,0,
  0,0,0,0,0,0,0,0,
  0,1,0,0,0,0,1,0,
  0,0,1,1,1,1,0,0,
  0,0,0,0,0,0,0,0,
};

// 从左往右逐个点亮LED测试接线是否有问题
void checkPin(){
for(int r = 0; r < 8; r++){
digitalWrite(ROWS[r], LOW);
for(int c = 0 ; c < 8 ; c++){
digitalWrite(COLS[c], HIGH);
delay(200);
digitalWrite(COLS[c], LOW);
}
digitalWrite(ROWS[r], HIGH);
}
}
// 逐行扫描方法
void displayLed(unsigned char dat[8][8]){
for(int r=0; r<8;r++){
digitalWrite(ROWS[r], LOW);
for(int c=0;c<8;c++){
digitalWrite(COLS[c],dat[c][r]);
};
delay(1);
clearLed();
};
}
// 重置LED状态，清除余晖效应
void clearLed(){
for (int i = 0;i <8; i++){
digitalWrite(ROWS[i], HIGH);
digitalWrite(COLS[i], LOW);
};
}
// 初始化设置
void setup(){
for(int i = 0;i < 8; i++){
  pinMode(COLS[i],OUTPUT);
  pinMode(ROWS[i], OUTPUT);
};
clearLed();
checkPin();
}
void loop() {
  for(int i=0;i<100;i++){
  displayLed(smile);
};
delay(1000);
}
