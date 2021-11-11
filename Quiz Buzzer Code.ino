#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define BACKLIGHT_PIN 13

//defining pin numbers for buttons and leds.
int wButton=2;
int wLed= 3;

int buzz=11;

int oLed=4;
int oButton=5;

int yLed=7;
int yButton=6;

int resetButton=8;

int lLed=9;
int lButton=10;

# define uint unsigned  char
uint  flag=0;

//Defining variables to store states of buttons
uint  ls,ws,os,ys,rs=0;


void setup() {

lcd.begin (); 
lcd.backlight();
lcd.clear();

pinMode(wLed,OUTPUT);
pinMode(wButton,INPUT_PULLUP);

pinMode(buzz,OUTPUT);


pinMode(oLed,OUTPUT);
pinMode(oButton,INPUT_PULLUP);

pinMode(yLed,OUTPUT);
pinMode(yButton,INPUT_PULLUP);

 pinMode(lLed,OUTPUT);
pinMode(lButton,INPUT_PULLUP);

pinMode(resetButton,INPUT_PULLUP);


digitalWrite(wLed,HIGH);
delay(1000);
digitalWrite(oLed,HIGH);
delay(1000);
digitalWrite(yLed,HIGH);
delay(1000);
digitalWrite(lLed,HIGH);
delay(1000);

}

void loop() {
              digitalWrite(wLed,LOW);
              digitalWrite(oLed,LOW);
              digitalWrite(yLed,LOW);
              digitalWrite(lLed,LOW);

              rs=digitalRead(resetButton);
              if(rs==0){
                          if (rs==0){
                                      flag=1;
                                      tone(buzz,300,200);
                                      lcd.clear();
                                      lcd.setCursor(6,0);
                                      lcd.print("RESET!");
                                      digitalWrite(wLed,LOW);
                                       digitalWrite(yLed,LOW);
                                       digitalWrite(oLed,LOW);
                                       digitalWrite(lLed,LOW);
                            
                                    }
                        }



              if(flag==1){
                            ws=digitalRead(wButton);
                            os=digitalRead(oButton);
                            ys=digitalRead(yButton);
                            ls=(digitalRead(lButton));
                            ;
                            if(ws==0){
                                       flag=0;
                                       
                                       tone(buzz,200,700);
                                       lcd.clear();
                                       lcd.setCursor(6,0);
                                       lcd.print("RED!");
                                       digitalWrite(wLed,HIGH);
                                       digitalWrite(yLed,LOW);
                                       digitalWrite(oLed,LOW);
                                       while(digitalRead(resetButton));
                                      }
                              if(os==0){
                                       flag=0;
                                       
                                       tone(buzz,200,700);
                                       lcd.clear();
                                       lcd.setCursor(4,0);
                                       lcd.print("ORANGE!");
                                       digitalWrite(oLed,HIGH);
                                       digitalWrite(yLed,LOW);
                                       digitalWrite(wLed,LOW);
                                       while(digitalRead(resetButton));
                                      }

                                if(ys==0){
                                       flag=0;
                                       
                                       tone(buzz,200,700);
                                       lcd.clear();
                                       lcd.setCursor(6,0);
                                       lcd.print("BLUE!");
                                       digitalWrite(yLed,HIGH);
                                       digitalWrite(wLed,LOW);
                                       digitalWrite(oLed,LOW);
                                       while(digitalRead(resetButton));
                                      }


                                 if(ls==0){
                                       flag=0;
                                     
                                       tone(buzz,200,700);
                                       lcd.clear();
                                       lcd.setCursor(5,0);
                                       lcd.print("GREEN!");
                                       digitalWrite(lLed,HIGH);
                                       digitalWrite(wLed,LOW);
                                       digitalWrite(oLed,LOW);
                                       while(digitalRead(resetButton));
                                      }
                          }
             }
