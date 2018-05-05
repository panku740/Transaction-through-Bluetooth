#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<EEPROM.h>
String state,otp;
#define a 4
#define b 5
#define c 8
#define d 7
#define e 6
#define f 3
#define g 2
int otp1,flag=0,money=0,t,num,i,j,ran;
void beep(int p)
{
  for(j=0;j<p;j++)
  {
    digitalWrite(9,1);
    delay(100);
    digitalWrite(9,0);
    delay(100);
  }
}
 void display1(int n1)
{
  if(n1=='1')
  {
    digitalWrite(b,1);
    digitalWrite(c,1);
   // delay(2000);
  }
   else if(n1=='2')
   {digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(g,1);
    digitalWrite(e,1);
    digitalWrite(d,1);
   }
   else if(n1=='3')
   {digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(g,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
   }
   else if(n1=='4')
   {digitalWrite(f,1);
    digitalWrite(b,1);
    digitalWrite(g,1);
    digitalWrite(c,1);
   }
   else if(n1=='5')
   {digitalWrite(a,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
   }
   else if(n1=='6')
   {digitalWrite(a,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
    digitalWrite(c,1);
    digitalWrite(e,1);
    digitalWrite(d,1);
   }
   else if(n1=='7')
   {digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
   }
   else if(n1=='8')
   {digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
   }
   else if(n1=='9')
   {digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
   }
   else if(n1=='0')
   {digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
   }
}
void off()
{   digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);
}
void timer()
{
  for(i=57;i>=48;i--)
  {display1(i);
  delay(1000);
  off();
  if(Serial.available()>0)
  break;
  }
  if(i==47)
  {
  Serial.print("\nTimes Up. Try again");
  flag=1;
  }
  else
  flag=0;
}
void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13,0);
  pinMode(9,OUTPUT);
  pinMode(a,OUTPUT);
 pinMode(b,OUTPUT);
 pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);
  Serial.begin(9600);
  delay(100);
  ran=random(10000,99999);
  Serial.print("\nYour OTP is:");
  Serial.print(ran);
  Serial.print("\nShow it to the Merchant");
  timer();
 /* num=Serial.available();
  Serial.print(num);
  if(num==0)
  {
  otp=Serial.readString();
  otp1=otp.toInt();
  Serial.print(otp1);
  if(otp1==ran)
  flag=0;
  else
  flag=1;*/
  //num=0;
  }

void loop() {
   if(flag==0)
   {
    while(Serial.available()) 
 {
  
  //num=Serial.available();  
  state=Serial.readString();
  //state[state.length()]='\0';
  t=state.toInt();
  if(t<5000&&money<20000)
  {
  money=money+t;
  EEPROM.update(128,money);
    Serial.println("Payment Recieved of ");
    Serial.print(state);
    Serial.print("\nTotal Money:");
    Serial.print(EEPROM.read(128));
    Serial.println("\nTransaction Successful");
    beep(1);
  }
  else
  {
  Serial.print("\nPlease Enter amount less than 5000\n"); 
  beep(3);
  }
  }
   }
   else
   setup();
 }
