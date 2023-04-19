#include <SoftwareSerial.h> //Thư viện sử dụng bất kỳ 2 chân digital nào để làm chân TX RX
#include <Servo.h>
SoftwareSerial mybluetooth(0,1); // Khai báo tên Bluetooth và chân TX RX (2-TX, 3-RX)
Servo myservo;

String incomingByte ; 
int led = 9;   
int triggerPin = 7; 
int echoPin = 8; 
char docgiatri; //Biến docgiatri kiểu char
int pos = 0;
int cb1Pin = A5;  int cb1 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(cb1Pin, INPUT); 
  pinMode(led, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(6);
  mybluetooth.begin(9600); //Kết nối Bluetooth với tốc độ baud là 9600
}
void loop() {
  sensor();
  
  cb1 = analogRead(cb1Pin);
//  Serial.print(cb1); Serial.println();
  
  if(mybluetooth.available() > 0) {
    docgiatri = mybluetooth.read(); //Đọc các giá trị trên app được kết nối qua bluetooth và gán vào docgiatri
    if (docgiatri == ('1')) {digitalWrite(led,HIGH);}
    if (docgiatri == ('2')) {digitalWrite(led,LOW);}
    if (docgiatri == ('3')) {if (pos == 0){for(pos = 0; pos < 120; pos += 1){ myservo.write(pos); delay(20);}}}
    if (docgiatri == ('4')) {if (pos == 120){for(pos = 120; pos >= 1; pos -= 1){myservo.write(pos);delay(20);}}}
    Serial.println(docgiatri);
  }
  
}

void sensor() { 
  
  int duration, distance;   
  
  digitalWrite(triggerPin, HIGH); 
  delay(10);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); 
  distance = (duration/2) / 29.1; 
  
  Serial.print(distance);    
  Serial.print("cm");       
  Serial.println(" ");     
  
}
