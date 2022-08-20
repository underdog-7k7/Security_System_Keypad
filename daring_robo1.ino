#include<Keypad.h>

const byte row=4;
const byte col=4;
const int redled=12;
const int greenled=13;
const int buzzer=11;

char numpad[4][4]={
  {'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};

byte rowpin[4]={9,8,7,6};
byte colpin[4]={5,4,3,2};

String password="8811";
String vstup="";

Keypad mykeypad= Keypad(makeKeymap(numpad),rowpin,colpin,4,4);

void setup(){
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(buzzer,OUTPUT);
  digitalWrite(redled,HIGH);
  Serial.begin(9600);
  Serial.print("Enter Passcode: ");
}

void loop(){
  char mypass=mykeypad.getKey();
  if(mypass){
    if(vstup.length()<4){
      Serial.print("*");
      vstup +=mypass;}}
  
  if(vstup.length()==4){
    delay(500);
    if(password==vstup){
      Serial.println("\nEnter:");
      digitalWrite(redled,LOW);
      digitalWrite(greenled,HIGH);
      tone(buzzer,500);
      delay(100);
      noTone(buzzer);
    }
    else{
      Serial.println("\nWRONG PASSCODE!");
      digitalWrite(redled,HIGH);
      digitalWrite(greenled,LOW);
      tone(buzzer,1000);
      delay(800);
      tone(buzzer,1000);
      delay(800);
      noTone(buzzer);
    }
    delay(1500);
    vstup="";
    Serial.println("Enter Passcode:");
    digitalWrite(redled,HIGH);
    digitalWrite(greenled,LOW);
  }
}
      