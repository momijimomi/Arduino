#include <OneWire.h>
#include <DallasTemperature.h>
 
// Data to Arduino pin
#define ONE_WIRE_BUS 13
 

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);



  
// マスターからを受信
void receiveEvent(int howmany) {
  while(Wire.available()) {        // 送信された全てのデータを受信
    event = Wire.read();
  }
  //Serial.println(event);
  //Serial.println(ReceivedSetpoint);
}

// マスターからのリクエストに対するデータ送信
void requestEvent() {
  //Serial.println("1");
  if (event == 0) {                 
  }   
  if (event == 1) {                 //temp1
    String str = String(temp1);
    char buf[16];
    int len = str.length(); 
    str.toCharArray(buf, len+1);
    Wire.write(buf, len); 
  } 
  if (event == 2) {                 //temp2
    String str = String(temp2);
    char buf[16];
    int len = str.length(); 
    str.toCharArray(buf, len+1);
    Wire.write(buf, len); 
  } 
  if (event == 3) {                 //temp3
    String str = String(temp3);
    char buf[16];
    int len = str.length(); 
    str.toCharArray(buf, len+1);
    Wire.write(buf, len); 
  } 
  if (event == 4) {                 //temp4
    String str = String(temp4);
    char buf[16];
    int len = str.length(); 
    str.toCharArray(buf, len+1);
    Wire.write(buf, len); 
  }
  if (event == 5) {                 //temp5
    String str = String(temp5);
    char buf[16];
    int len = str.length(); 
    str.toCharArray(buf, len+1);
    Wire.write(buf, len);   
  }
  if (event == 6) {                 //temp6
    String str = String(temp6);
    char buf[16];
    int len = str.length(); 
    str.toCharArray(buf, len+1);
    Wire.write(buf, len);   
  }            
}

void ds18b20(){
  sensors.requestTemperatures(); // Send the command to get temperatures
  String temp1 = String(sensors.getTempCByIndex(0),DEC);
  String temp2 = String(sensors.getTempCByIndex(1),DEC);
  String temp3 = String(sensors.getTempCByIndex(2),DEC);
  String temp4 = String(sensors.getTempCByIndex(3),DEC);
  String temp5 = String(sensors.getTempCByIndex(4),DEC);
  String temp6 = String(sensors.getTempCByIndex(5),DEC);
  Serial.print(temp1); 
  Serial.print("  ");   
  Serial.print(temp2); 
  Serial.print("  ");   
  Serial.print(temp3); 
  Serial.print("  ");   
  Serial.print(temp4); 
  Serial.print("  ");   
  Serial.print(temp5); 
  Serial.print("  ");   
  Serial.println(temp6); 
}


void setup(void)
{
  Serial.begin(9600);
  // Start up the library
  sensors.setResolution(12);  
  sensors.begin();
  Wire.begin(0x10) ;                 // Ｉ２Ｃの初期化、自アドレスを10とする
  Wire.onReceive(receiveEvent) ;     // マスタからのデータ送信対応のコールバック関数登録
  Wire.onRequest(requestEvent) ;     // マスタからのデータ取得要求のコールバック関数登録
 
}
 
 
void loop(void)
{
  ds18b20();
}
