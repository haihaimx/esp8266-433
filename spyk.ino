#define BLINKER_WIFI
#include <Blinker.h>

  // 点灯科技key
  // WiFi账号
  // WiFi密码


#include <RCSwitch.h>

BlinkerButton Button1("km");
char auth[] = "点灯科技key";
char ssid[] = "WiFi账号";
char pswd[] = "WiFi密码";
BlinkerButton Button2("gm");
RCSwitch mySwitch = RCSwitch();
BlinkerButton Button3("zt");
BlinkerButton Button4("sd");

void Button1_callback(const String & state) {
  if (state == "tap") {
    // 输入接收到的十进制数据

    mySwitch.send(十进制数据, 24);
    Blinker.wechat("已开门");

  }
}
void Button2_callback(const String & state1) {
  if (state1 == "tap") {
    // 输入接收到的十进制数据
    mySwitch.send(十进制数据, 24);
    Blinker.wechat("已关门");

  }
}
void Button3_callback(const String & state2) {
  if (state2 == "tap") {
    // 输入接收到的十进制数据
    mySwitch.send(十进制数据, 24);
    Blinker.wechat("已暂停");

  }
}
void Button4_callback(const String & state3) {
  if (state3 == "tap") {
    // 输入接收到的十进制数据
    mySwitch.send(十进制数据, 24);
    Blinker.wechat("已锁门");

  }
}

void setup(){
  Button1.attach(Button1_callback);
  Blinker.begin(auth,ssid,pswd);

  Button2.attach(Button2_callback);
  Serial.begin(9600);
  mySwitch.enableTransmit(5);
  mySwitch.setPulseLength(300);
  pinMode(0, INPUT);
  pinMode(14, INPUT);
  pinMode(2, INPUT);
  Button3.attach(Button3_callback);
  Button4.attach(Button4_callback);
  mySwitch.enableReceive(4);
}

void loop(){
  Blinker.run();

  if (mySwitch.available()) {
    Blinker.wechat(mySwitch.getReceivedValue());
    Serial.println(mySwitch.getReceivedValue());
    Serial.println(mySwitch.getReceivedBitlength());
    Serial.println(mySwitch.getReceivedDelay());
    Serial.println(mySwitch.getReceivedProtocol());
    mySwitch.resetAvailable();

  }

}