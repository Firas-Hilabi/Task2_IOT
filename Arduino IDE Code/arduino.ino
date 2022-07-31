
#This code is used in Arduino IDE


#include <Servo.h>
Servo gripper;
Servo wrist;
Servo elbow;
Servo shoulder;
Servo base;

double base_angle=90;
double shoulder_angle=90;
double elbow_angle=90;
double wrist_angle=90;


void setup() {
 Serial.begin(9600);
   pinMode(LED_BUILTIN, OUTPUT);

   base.attach(8);
  shoulder.attach(9); 
  elbow.attach(10);
  wrist.attach(11);
  gripper.attach(12); 

  base.write(base_angle);
  shoulder.write(shoulder_angle);
  elbow.write(elbow_angle);
  wrist.write(wrist_angle);

}



String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(100);
  String computerText = Serial.readStringUntil('@');
  computerText.trim();
  if (computerText.length() == 0) {
    return;
  }
  // 92-0-130
  String command = getValue(computerText, ' ',0);

    if (command == "يمين") {
      base.write(base_angle -= 20);
    }
    if (command == "يسار") {
     base.write(base_angle += 20);
    }

    if (command == "أعلى") {
      shoulder.write(shoulder_angle -= 20);
    }

   if (command == "أسفل") {
     shoulder.write(shoulder_angle += 20);
    }
    Serial.println(command);
  Serial.println("WORKING");
  delay(1000);

}
