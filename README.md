ArduinoLED点阵显示屏小作业
=====================

> 组员：达庭 雅琳 彦禧

# 序言

你会用一个LED点阵做些什么呢？

显示一个倒计时？

一个图案？

还是为好朋友做一个简单节日祝福？

led点阵有很多尺寸，其中8\*8是最基础的，因为基础所以是Arduino初学者特别好的尝试对象。

我的工具箱里有几个点阵，我一直想用它们做点什么。正好恰逢朋友生日，可以利用led点阵和蜂鸣器DIY一个装置。

它带有显示内容和播放音乐的功能。接下来跟着我一起制作吧。

# 

# 演示


图一为笑脸程序（主要用于检验线路的正确和每个灯泡的好坏），图二为生日快乐程序
 
![image2](https://user-images.githubusercontent.com/92968854/210182360-178e0b95-6b78-4c21-92ae-5794cca45dee.gif)
![image3](https://user-images.githubusercontent.com/92968854/210182363-e4d1f1ff-7cdd-4a1c-9b59-7330a1a66fb0.gif)

完整展示视频

[生日快乐演示视频](https://www.bilibili.com/video/BV14A411Q7vM/?spm_id_from=333.999.0.0)

只需要小小改改代码，即可得到元旦快乐版本，此代码可自行学习修改得来

![image4](https://user-images.githubusercontent.com/92968854/210182452-69510a7a-0e25-4799-8b37-3edd082ce909.gif)


# 材料清单：

-   共阴极8\*8LED点阵

-   无源蜂鸣器

-   220欧电阻x17（颜色为红红棕）

-   Arduino UNO R3

-   杜邦线若干

-   两块面包板

-   [购买链接](https://new.m.taobao.com/detail.htm?id=601125598796&price=38-899&sourceType=item&suid=30f2c20d-b702-47ab-82f0-c89e0a3e964f&shareUniqueId=19492954953&ut_sk=1.YiCYyuolfCkDAMUvNTeOfAeC_21646297_1672363063444.Copy.1&un=723ecfb424c3b5fb3f17511656f2f575&share_crt_v=1&un_site=0&spm=a2159r.13376460.0.0&sp_abtk=gray_1_code_simpleAndroid2&tbSocialPopKey=shareItem&sp_tk=Y2hVbWQ0bWllM0M%3D&bc_fl_src=share-104936900039786-2-1&cpp=1&shareurl=true&short_name=h.UkKj18g&bxsign=scdyttoLCH0z3x5Hr1lzJUKpyYTXXY4rV1rJrakWkrq8qTBJjx9fWOrjrdhKaKwjR9njZ-Ksr4EfzZJB_RZIvFPniGY7hxHwVUkD35nBD4QzDWQkm92cs2xBbS5wonRfcux&tk=chUmd4mie3C&app=weixin)

<img width="604" alt="image" src="https://user-images.githubusercontent.com/92968854/210182878-4ba0f63a-49fc-40ad-bac9-a06143e6a580.png">

# 制作过程

其实制作过程算是比简单的，主要分以下几步

### 1. 购买元器件

购买器材可参考上文中提到的一些元器件，淘宝上很多淘宝店都是有卖的。

### 2. 安装对应的软件

这里我们主要用到的软件是
arduino，我们同学用过了当然可以跳过，初学者也可以接着往下看

安装 Arduino

通过官网下载 Arduino IDE，解压后运行 arduino.exe
就表示安装完成了。下载地址如下：**ARDUINO IDE 1.8.12**

-   Arduino IDE Windows安装版
    [百度云盘下载](https://pan.baidu.com/s/12WvXdl7MHz7WA1ujfk2bVg)
    提取码：0ig4 /
    [Arduino官网下载（网站服务器不在中国）](https://www.arduino.cc/en/Main/Software)

-   Arduino IDE 苹果电脑Mac OSX 安装版
    [百度云盘下载](https://pan.baidu.com/s/1Me9mw-wzTJSwvlnU16C8JA)
    提取码：mumo /
    [Arduino官网下载（网站服务器不在中国）](https://www.arduino.cc/en/Main/Software)

如果链接失效，请在官网自行下载，下载选项选 Windows ZIP file

### 3.电路连接

<img width="603" alt="image" src="https://user-images.githubusercontent.com/92968854/210182867-8b69b78d-cb3b-4609-aeab-c0a3062aa1c8.png">


PS:1，注意接线的顺序，防止不必要的错误，细心。

2，点阵和蜂鸣器要连电阻，建议220欧

### 

### 4.输入代码

将代码复制粘贴入arduino ide

###### 笑脸测试代码(主要用于检验led灯珠的好坏）
```
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

```

###### 生日快乐歌＋生日快乐祝福

```
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

// change this to make the song slower or faster
int tempo = 140;

// change this to whichever pin you want to use
int buzzer = A5;
int melody[] = {

  // Happy Birthday
  // Score available at https://musescore.com/user/8221/scores/26906

  NOTE_C4,4, NOTE_C4,8, 
  NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4,
  NOTE_E4,-2, NOTE_C4,4, NOTE_C4,8, 
  NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4,
  NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8,

  NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4, 
  NOTE_E4,-4, NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8,
  NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
  NOTE_F4,-2,
 
};
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;
//引脚
int ROWS[] ={10,11,12,13,A0,A1,A2,A3};
int COLS[] ={2,3,4,5,6,7,8,9};
// //1=关,0=开
byte smile11[8][8] ={
  1,0,0,0,0,0,0,1,
  1,1,1,1,1,1,0,1,
  1,1,1,1,1,1,0,1,
  1,0,0,0,0,0,0,1,   
  1,1,1,1,1,1,0,1,
  1,1,1,1,1,1,0,1,
  1,0,0,0,0,0,0,1,
  1,1,1,1,1,1,1,1,
};
byte smile22[8][8] ={
  1,1,1,1,1,1,1,1,
  1,0,0,0,0,0,0,1,
  1,1,1,1,1,1,0,1,
  1,1,1,1,1,1,0,1,   
  1,0,0,0,0,0,0,1,
  1,0,1,1,1,1,1,1,
  1,0,1,1,1,1,1,1,
  1,0,0,0,0,0,0,1,
};
byte smile33[8][8] ={
  1,1,1,0,1,1,1,1,
  1,1,0,0,1,1,1,1,
  1,1,1,0,1,1,1,1,
  1,1,1,0,1,1,1,1,   
  1,1,1,0,1,1,1,1,
  1,1,1,0,1,1,1,1,
  1,0,0,0,0,0,0,1,
  1,1,1,1,1,1,1,1,
};
byte smile[8][8] ={
  1,0,0,0,0,0,0,1,
  1,1,1,1,1,1,1,1,
  0,0,0,0,0,0,0,0,
  1,1,0,1,1,0,1,1,
  1,1,0,1,1,0,1,1,
  1,1,0,1,1,0,1,1,
  1,1,0,1,1,0,1,0 ,
  0,0,0,1,1,0,0,0,
};
byte smile2[8][8] ={
  1,0,0,0,0,0,0,1,
  1,0,1,1,1,1,0,1,
  1,0,0,0,0,0,0,1,
  1,0,1,1,1,1,0,1,
  1,0,1,1,1,1,0,1,
  1,0,0,0,0,0,0,1,
  1,1,1,1,1,1,1,1 ,
  0,0,0,0,0,0,0,0,
};
byte smile3[8][8] ={
  1,0,1,1,0,1,1,1,
  1,0,1,0,0,0,0,1,
  1,0,1,1,0,1,0,1,
  0,0,0,0,0,1,0,0,   
  0,0,0,1,0,0,1,1,
  1,0,0,1,0,1,0,1,
  1,0,1,1,0 ,1,0,1,
  1,0,1,0,1,1,1,0,
};
byte smile4[8][8] ={
  1,0,0,0,0,0,0,0,
  1,0,1,1,0,1,1,1,
  1,0,1,1,0,1,1,1,
  1,0,0,0,0,0,0,0,   
  1,1,1,1,0,1,1,1,
  1,0,1,1,0,1,0,1,
  1,0,1,1,0,1,0,1,
  0,1,1,0,0,1,1,0,
};
byte smile5[8][8] ={
  1,1,1,1,1,1,1,1,
  1,0,0,1,1,0,0,1,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,   
  0,0,0,0,0,0,0,0,
  1,0,0,0,0,0,0,1,
  1,1,0,0,0,0,1,1,
  1,1,1,0,0,1,1,1,
};
byte smile6[8][8] ={
  1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,
  1,1,0,1,1,0,1,1,
  1,0,0,0,0,0,0,1,   
  1,0,0,0,0,0,0,1,
  1,1,0,0,0,0,1,1,
  1,1,1,0,0,1,1,1,
  1,1,1,1,1,1,1,1,
};
byte smile7[8][8] ={
  1,1,1,1,1,1,1,1,
  1,0,0,1,1,0,0,1,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,   
  0,0,0,0,0,0,0,0,
  1,0,0,0,0,0,0,1,
  1,1,0,0,0,0,1,1,
  1,1,1,0,0,1,1,1,
};



// 初始化设置
void setup(){
for(int i = 0;i < 8; i++){
  pinMode(COLS[i],OUTPUT);
  
  pinMode(ROWS[i], OUTPUT);
}
 // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
   
}

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }

}
void loop() {
  for(int i = 0;i < 100; i++){
  displayLed(smile11);
};
delay(1000);  
  for(int i = 0;i < 100; i++){
  displayLed(smile22);
};
delay(1000);   
  for(int i = 0;i < 100; i++){
  displayLed(smile33);
};
delay(1000);   
for(int i = 0;i < 100; i++){
  displayLed(smile);
};
delay(100);
for(int i = 0;i < 100; i++){
  displayLed(smile2);
};
delay(100);

for(int i = 0;i < 100; i++){
  displayLed(smile3);
};
delay(100);

for(int i = 0;i < 100; i++){
  displayLed(smile4);
};
delay(100);
for(int i = 0;i < 100; i++){
  displayLed(smile5);
};
delay(50);
for(int i = 0;i < 100; i++){
  displayLed(smile6);
};
delay(100);
for(int i = 0;i < 100; i++){
  displayLed(smile7);
};
delay(50);

}
void displayLed(unsigned char dat[8][8]){
for (int c = 0;c < 8;c++) {
  digitalWrite(COLS[c],HIGH);
  for (int r = 0; r < 8; r++){
    digitalWrite(ROWS[r],dat[r][c]);
  }
    delay(1);
    clearLed();
  }
}
// 
void clearLed(){
for (int i = 0;i <8; i++){
digitalWrite(ROWS[i], HIGH);
digitalWrite(COLS[i], LOW);
};
}

```

### 5.选择开发板

工具 \--\> 开发板 \--\> arduino uno

​

### 6.选择端口

工具 \--\> 端口 \--\> 选择我们串口设备对应的端口

### 7.写入程序

项目 \--\> 上传 或 点左侧的 → 箭头

### 8.测试 & 检验

过程是先编译在上传

这里列举个人处理过程中遇到比较多的问题：

-   ######  程序编译失败

编译失败检查一下编译报错的地方即可

-   ###### 程序上传失败

上传失败基本就是串口没选对或者开发板没有选对，正确连接加上安装驱动即可

-   ###### 上传成功后无任何显示

这里就需要检查自己的接线是否正确。（此操作请断开电源后进行）

​

# 讲解程序

<img width="604" alt="image" src="https://user-images.githubusercontent.com/92968854/210182781-0c452992-4d52-40ec-8b53-5eab50b50b95.png">


图为共阴极led点阵原理图，先简单了解

### 笑脸测试代码(用于检验led灯珠的好坏）

-   检查接线是否正确

-   扫描需要点亮的LED

-   清除余晖效应

### 生日快乐祝福

-   蜂鸣器接入，先用预处理命令将歌词写入

-   再编写好想要表现的图案

-   即可上传

# 成品展示

<img width="263" alt="image" src="https://user-images.githubusercontent.com/92968854/210182740-446088de-8c48-494c-88d9-1b69fb899c5a.png"> <img width="257" alt="image" src="https://user-images.githubusercontent.com/92968854/210182748-f9381042-cc58-4203-9326-c87eaad073ed.png"> ![image10](https://user-images.githubusercontent.com/92968854/210182759-d003db6a-6c7f-4dd0-9f54-99a45bec4ba6.gif)


[笑脸程序](https://www.bilibili.com/video/BV1kD4y1773o/?spm_id_from=333.999.0.0)

[元旦快乐小程序](https://www.bilibili.com/video/BV1sv4y1z7z5/?spm_id_from=333.999.0.0)（元旦快乐版）

[[生日快乐演示视频]{.ul}](https://www.bilibili.com/video/BV14A411Q7vM/?spm_id_from=333.999.0.0)

# 自我评价

这个项目（也算是一个极小项目吧）我做了两天，虽说也有很多人搞这种点阵屏，但是我个人觉得自己真的去实践就会发现没有那么简单，而且别人做的你也未必会理解，自己去做更能去从中学习到一些东西。在此讲讲个人感悟：本人通过这次作业，认识到虽然平常也有积累一些相关的知识，但是远不如系统性学习来的高效，所以如果真的要学习这个还是要系统性的看一些视频来学习，其次就是就是实践，但是却不知道如何去使用，所以需要不断的去实践来理解自己所掌握的技能。

最后感谢各位组员

###### 缺点

1.  没有将音乐和图案同时进行

2.  过于简单，并没有做外壳，没有理线

# 结语

这就是我的小教程，衷心感谢每一个看完我的教程的，因为是第一个，所以也没什么干货，主要是给像我一样的初学者一个小参考。

我猜此刻你一定是有很多想法吧，那么去利用这个程序为你的父母或者好朋友做个小祝福吧!

