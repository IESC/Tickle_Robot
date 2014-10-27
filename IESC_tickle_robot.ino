  /*
  Find the Robot's tickle spot
   By: 
   Sruti Chigullapalli 
   Shammi Jayaraj
   Romana Flores
   Oliver Chen
   Dustin Bryers
   10/27/2014. 
 
  Objective: Blink led based on touch sensor 

 Digital Input: touch sensor 
 Digital Output: LED blinking rapidly
 LCD prints: "Ha  ha" "Stop tickling me"
 
 
  */
 
  #include <Wire.h>   //does I2C
  #include "rgb_lcd.h" //plug lcd into I2C below D7
  
  
  // digital input
  const int touchPin1=A2;
  const int touchPin2=A3;

 
  //digital output
  const int ledPin1=3;
  const int ledPin2=4;

  //use pwm pins 3,5,6,9,10,11
  int buzzerPin=6;
    
  
  //Servo groveServo; //create a object
  rgb_lcd lcd;
  // set background color of lcd any integer 0-255
  int red= 255;
  int green= 255;
  int blue= 255;
  
  /* 
  // useful commands for lcd
  lcd.begin(numCols,numRows);// set up the LCD's number of columns and rows
  lcd.home();// go to (0,0)
  lcd.setCursor(thisRow,thisCol);// set the cursor position
  lcd.write(thisLetter);// print the letter
  lcd.setRGB(red, green, blue);//set color
  lcd.leftToRight();// go left for the next letter
  lcd.rightToLeft();// go right for the next letter
  */
  
  char dtaUart[15];
  char dtaLen = 0;
  
  
  const int debug=1;  //print data to serial monitor

int touchState1,touchState2;
int touchState_1_old, touchState_2_old;


  void setup() {
    // put your setup code here, to run once:
    
  // input pins - digital read
  pinMode(touchPin1,INPUT);
  pinMode(touchPin2,INPUT);
      
   
  //output pins - digital write, pwm
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);

  pinMode(buzzerPin,OUTPUT);
    
  
  lcd.begin(16, 2);
  lcd.print(" Ready Ready");
  Serial.begin(115200);
  }
  
  void loop() {
    // turn led on using button or touch
        
         touchState1=digitalRead(touchPin1); // read input from touch sensor 1
         touchState2=digitalRead(touchPin2); // read input from touch sensor 2

         if (touchState1==1 && touchState2==0){
           digitalWrite(ledPin1,HIGH);           
           digitalWrite(ledPin2,LOW); 
           lcd.clear();
          lcd.print("HA HA");
          lcd.setRGB(0, 0, 255); //green
          }
         else if (touchState1==0 && touchState2==1){
           digitalWrite(ledPin1,LOW);
           digitalWrite(ledPin2,HIGH);
          lcd.clear();
          lcd.print("HA HA");
          lcd.setRGB(0, 0, 255); //blue
         }
         else if (touchState1==1 && touchState2==1){
           digitalWrite(ledPin1,HIGH);
           digitalWrite(ledPin2,HIGH);
           lcd.clear();
          lcd.print("STOP Tickling me");
          lcd.setRGB(0, 255, 0); //GREEN
         }
        else if (touchState1==0 && touchState2==0){
           digitalWrite(ledPin1,LOW);
           digitalWrite(ledPin2,LOW);
          lcd.clear();
          lcd.print("You Lose");
          lcd.setRGB(255, 255, 0); 
        }
        delay(200);

      if (debug==1){
        //Serial.println("button state 1= "+String(buttonState1)+";  button state 2= "+String(buttonState2));
        Serial.println("touch state 1"+String(touchState1)+";  touch state 2= "+String(touchState2));
      }
  
 /*
  if (touchState==1 && touchState!= touchStateOld){
  //write to LCD
  lcd.clear();
  lcd.print("LED is ON");
   lcd.setRGB(0, 255, 0); //green
  }
  else if(touchState==0 && touchState!= touchStateOld && buttonState==0){ 
  lcd.clear();
  lcd.print("LED is OFF"); 
  lcd.setRGB(255, 0, 50); //pink
  }
  else if (buttonState==1 && buttonState!= buttonStateOld){
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print("LED blinks"); 
  lcd.setRGB(red, green, blue); //white
  }
  else if (buttonState==0 && buttonState!= buttonStateOld && touchState==0){
   lcd.clear();
   lcd.setCursor(2,1);
   lcd.print("LED is OFF"); 
   lcd.setRGB(red, green, blue); //white
  }
   else if (buttonState==1 && touchState==1)
   {lcd.clear(); 
   lcd.print("Temp=");
  lcd.print(temperature);
  lcd.print(" oC");
    lcd.setRGB(0, 0, 255); //blue display
   }
  if (debug==1){
    Serial.println(temperature);
  }
 
 buttonState_1_old=buttonState1;
 buttonState_2_old=buttonState2;
 */
 touchState_1_old=touchState1;
 touchState_2_old=touchState2;
  }
