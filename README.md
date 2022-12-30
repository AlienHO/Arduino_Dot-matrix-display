---
**ArduinoLED点阵显示屏小作业**
---

> 组员：广美艺科 岑达庭，何雅琳，余彦禧

# 序言

你会用一个LED点阵做些什么呢？

显示一个倒计时？

一个图案？

还是为好朋友做一个简单节日祝福？

![descript](vertopal_af579750c18c4c4b8a9c5d5290ca8ec1/media/image1.jpg){width="3.5251312335958005in"
height="3.0234186351706036in"}

led点阵有很多尺寸，其中8\*8是最基础的，因为基础所以是Arduino初学者特别好的尝试对象。我的工具箱里有几个点阵，我一直想用它们做点什么。正好恰逢朋友生日，可以利用led点阵和蜂鸣器DIY一个装置。它带有显示内容和播放音乐的功能。接下来跟着我一起制作吧。

# 

# 演示

###### 视频

左一为笑脸程序（主要用于检验线路的正确和每个灯泡的好坏），左二为生日快乐程序

![descript](vertopal_af579750c18c4c4b8a9c5d5290ca8ec1/media/image2.gif){width="2.817707786526684in"
height="3.756942257217848in"}![descript](vertopal_af579750c18c4c4b8a9c5d5290ca8ec1/media/image3.gif){width="2.8020833333333335in"
height="3.736111111111111in"}

完整展示视频

[生日快乐演示视频](https://www.bilibili.com/video/BV14A411Q7vM/?spm_id_from=333.999.0.0)

只需要小小改改代码，即可得到元旦快乐版本，此代码可自行学习修改得来

![descript](vertopal_af579750c18c4c4b8a9c5d5290ca8ec1/media/image4.gif){width="2.78125in"
height="3.7083333333333335in"}

###### 图片

![descript](vertopal_af579750c18c4c4b8a9c5d5290ca8ec1/media/image5.jpg){width="6.299305555555556in"
height="3.5426673228346455in"}

# 材料清单：

-   共阴极8\*8LED点阵

-   无源蜂鸣器

-   220欧电阻x17（颜色为红红棕）

-   Arduino UNO R3

-   杜邦线若干

-   两块面包板

-   购买链接

<https://new.m.taobao.com/detail.htm?id=601125598796&price=38-899&sourceType=item&suid=30f2c20d-b702-47ab-82f0-c89e0a3e964f&shareUniqueId=19492954953&ut_sk=1.YiCYyuolfCkDAMUvNTeOfAeC_21646297_1672363063444.Copy.1&un=723ecfb424c3b5fb3f17511656f2f575&share_crt_v=1&un_site=0&spm=a2159r.13376460.0.0&sp_abtk=gray_1_code_simpleAndroid2&tbSocialPopKey=shareItem&sp_tk=Y2hVbWQ0bWllM0M%3D&bc_fl_src=share-104936900039786-2-1&cpp=1&shareurl=true&short_name=h.UkKj18g&bxsign=scdyttoLCH0z3x5Hr1lzJUKpyYTXXY4rV1rJrakWkrq8qTBJjx9fWOrjrdhKaKwjR9njZ-Ksr4EfzZJB_RZIvFPniGY7hxHwVUkD35nBD4QzDWQkm92cs2xBbS5wonRfcux&tk=chUmd4mie3C&app=weixin>

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

![descript](vertopal_af579750c18c4c4b8a9c5d5290ca8ec1/media/image6.jpg){width="6.299305555555556in"
height="3.547227690288714in"}

PS:1，注意接线的顺序，防止不必要的错误，细心。

2，点阵和蜂鸣器要连电阻，建议220欧

### 

### 4.输入代码

将代码复制粘贴入arduino ide

###### 笑脸测试代码(主要用于检验led灯珠的好坏）

###### 生日快乐歌＋生日快乐祝福

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

![descript](vertopal_af579750c18c4c4b8a9c5d5290ca8ec1/media/image7.png){width="6.299305555555556in"
height="2.5352154418197723in"}

图为共阴极led点阵原理图，先简单了解

### 笑脸测试代码(用于检验led灯珠的好坏）

-   检查接线是否正确

-   扫描需要点亮的LED

-   清除余晖效应

### 生日快乐祝福

-   蜂鸣器接入，先用预处理命令将歌词写入

```{=html}
<!-- -->
```
-   再编写好想要表现的图案

-   即可上传

# 成品展示

![descript](vertopal_af579750c18c4c4b8a9c5d5290ca8ec1/media/image8.jpg){width="2.767034120734908in"
height="2.5240474628171476in"}![descript](vertopal_af579750c18c4c4b8a9c5d5290ca8ec1/media/image9.jpg){width="2.7829035433070866in"
height="2.498125546806649in"}

![descript](vertopal_af579750c18c4c4b8a9c5d5290ca8ec1/media/image10.gif){width="5.0in"
height="2.8125in"}

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

![descript](vertopal_af579750c18c4c4b8a9c5d5290ca8ec1/media/image11.png){width="6.299305555555556in"
height="3.5433595800524933in"}
