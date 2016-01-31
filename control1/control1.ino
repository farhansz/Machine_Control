int actuator1[] = {52, 53};
int actuator2[] = {46, 47};
int rotate[] = {48, 49};
int analogPin = 9;
int motorspeed;
char state;
int ddelay;
String state2;
String motor_rotate_cw ="CW";
String motor_rotate_ccw ="CCW";
String actuator_pos_fw="FW";
String actuator_pos_bw="BW";
String first_actuator="Actuator1";
String second_actuator="Actuator2";
String motor="Motor";
boolean str_chr=false;
boolean str_chr2=false;
String firstValue;
String secondValue;
String thirdValue;
String fourthValue;

void setup() {
  // put your setup code here, to run once:
    int i;
    for( i = 0; i < 2; i++){
    pinMode(actuator1[i], OUTPUT);
    pinMode(actuator2[i], OUTPUT);
    pinMode(rotate[i], OUTPUT);
    }
    Serial.begin(9600);
}
// --------------------------------------------------------------------------- Loop
void loop() {
  // put your main code here, to run repeatedly:
   if (Serial.available() > 0){     
     String temp = Serial.readStringUntil('\n');
     
     if(temp.length()==1 && temp.length()!=0){
       //state = temp();
       char ch[10];
       temp.toCharArray(ch,10);
       state=ch[0];
       str_chr=true;
     }
     else{
       state2 = temp;
       
       int commaIndex = state2.indexOf(',');

       //  Search for the next comma just after the first
       int secondCommaIndex = state2.indexOf(',', commaIndex+1);
       int thirdCommaIndex = state2.indexOf(',', secondCommaIndex+1);
       firstValue = state2.substring(0, commaIndex);
       secondValue = state2.substring(commaIndex+1, secondCommaIndex);
       thirdValue = state2.substring(secondCommaIndex+1,thirdCommaIndex);
       fourthValue = state2.substring(thirdCommaIndex+1);
       
       ddelay = thirdValue.toInt();
       motorspeed = fourthValue.toInt();
       
       Serial.println(firstValue);
       Serial.println(secondValue);
       Serial.println(thirdValue);
       Serial.println(fourthValue);
       //Serial.print("Delay: ");
       //Serial.println(ddelay);
       //Serial.print("Motorspeed: ");
       //Serial.println(motorspeed);
       str_chr2=true;
     }
    }
    if(str_chr){
      if (state == 'a') {
      actuator1_up();
      delay(1000);
      actuator1_stop();
      Serial.println("Actuator 1 going up");
      } 
      else if (state == 'b') {
      actuator1_down();
      delay(1000);
      actuator1_stop();
      Serial.println("Actuator 1 going down");
      }
      else if (state == 'c') {
      actuator2_up();
      delay(1000);
      actuator2_stop();
      Serial.println("Actuator 2 going up");
      } 
      else if (state == 'd') {
      actuator2_down();
      delay(1000);
      actuator2_stop();
      Serial.println("Actuator 2 going down");
      }
      else if (state == 'l') {
      rotate_left();
      delay(1000);
      rotate_stop();
      Serial.println("Rotating Left");
      } 
      else if (state == 'r') {
      rotate_right();
      delay(1000);
      rotate_stop();
      Serial.println("Rotating Right");
      } 
      else if(state =='s'){
      actuator1_stop();
      actuator2_stop();
      rotate_stop();
      //Serial.println("Stopping All");
      }
      str_chr=false;
    }
    else if( str_chr2 == true && str_chr == false ) {
      //Serial.println("I am inside String");
            if(motor == firstValue){
              if (motor_rotate_cw == secondValue){
              rotate_right();
              Serial.println("I am rorating CW");
              delay(ddelay);
              rotate_stop();
              }
              else if(motor_rotate_ccw == secondValue){
              rotate_left();
              Serial.println("I am rorating CCW");
              delay(ddelay);
              rotate_stop();
              }
            }
             else if(first_actuator == firstValue){
              if (actuator_pos_fw == secondValue){
              actuator1_up();
              Serial.println("I am going up now");
              delay(ddelay);
              actuator1_stop();
              }
              else if(actuator_pos_bw == secondValue){
              actuator1_down();
              Serial.println("I am going down now");
              delay(ddelay);
              actuator1_stop();
              }
            }
            else if(second_actuator == firstValue){
              if (actuator_pos_fw == secondValue){
              actuator2_up();
              Serial.println("I am going up now");
              delay(ddelay);
              actuator2_stop();
              }
              else if(actuator_pos_bw == secondValue){
              actuator2_down();
              Serial.println("I am going down now");
              delay(ddelay);
              actuator2_stop();
              }
            }
              else if(state2=="Stop"){
              actuator1_stop();
              actuator2_stop();
              rotate_stop();
              //Serial.println("Stopping All");
              }
            str_chr2=false;
          } 
   }
 // --------------------------------------------------------------------------- Drive
  void actuator1_up(){
  digitalWrite(actuator1[0], HIGH);
  digitalWrite(actuator1[1], LOW);
  }
  void actuator1_down(){
  digitalWrite(actuator1[0], LOW);
  digitalWrite(actuator1[1], HIGH);
  }
  void actuator1_stop(){
  digitalWrite(actuator1[0], LOW);
  digitalWrite(actuator1[1], LOW);
  Serial.println("Stopping......");
  }

  void actuator2_up(){
  digitalWrite(actuator2[0], HIGH);
  digitalWrite(actuator2[1], LOW);
  }
  void actuator2_down(){
  digitalWrite(actuator2[0], LOW);
  digitalWrite(actuator2[1], HIGH);
  }
  void actuator2_stop(){
  digitalWrite(actuator2[0], LOW);
  digitalWrite(actuator2[1], LOW);
  Serial.println("Stopping......");
  }

  void rotate_right(){
  digitalWrite(rotate[0], HIGH);
  digitalWrite(rotate[1], LOW);
  analogWrite(analogPin, motorspeed);
  }
  void rotate_left(){
  digitalWrite(rotate[0], LOW);
  digitalWrite(rotate[1], HIGH);
  
  analogWrite(analogPin,motorspeed);
  
 
  }
  void rotate_stop(){
  digitalWrite(rotate[0], LOW);
  digitalWrite(rotate[1], LOW);
  Serial.println("Stopping......");
  }
  // ---------------------------------------------------------------------------
