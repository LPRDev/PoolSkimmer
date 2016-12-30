
#include "Ultrasonic.h"
#include "MSMotorShield.h"

MS_DCMotor motor1(1);//forwards 
MS_DCMotor motor2(2);//backwards
MS_DCMotor prop3(3);//left
MS_DCMotor prop4(4);//right

#define trigPin 0
#define echoPin 1
boolean isWall= false;
long randNum =0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  motor1.setSpeed(1000);
  motor2.setSpeed(1500);
  prop3.setSpeed(1000);
  prop4.setSpeed(1000);
  
  // 1st ten seconds will be a test to see if the sensor if working
  // This requires soeone to place a hand in front of the sesnsor and see if the ruuder moves right
  delay(5000);
  long startTime = millis();
  while(millis() < (startTime + 10000)){
    if(obstacle()){
      forwardRight();
    }
    else{
      forwardLeft();
    }  
  }
  halt();
  delay(2000);
}

void loop() {
  
  if(obstacle()){    // Check for an obstacle
         backOut();    // Then back out
         forwardRight();  // and go forward the opposite direction to pull away fro the wall
         delay(8000);        
  }//end if
  
  else if(wall()){          // Then  loook for a wall and turn left if we find one
     forwardLeft();
      delay(4000);
      halt();              // halt so we can see we can tell when the snesor sees a wall
      delay (1000);
  }
  
  else{                    // Otherwise move forward
    moveForward();
     delay(1500);
    if (randomEvent()) 
    {
       forwardRight();
       delay(3000);
    }
    else if(randomEvent())
   {
     forwardLeft();
       delay(5000);
   } 
    }//end else if
}//end loop

void moveForward() {
   motor1.run(FORWARD);
   motor2.run(RELEASE);
   prop3.run(RELEASE);
   prop4.run(RELEASE); 
}

boolean randomEvent()
{
  randNum = random(0,100);
    if (randNum > 85) return true;
    else return false;
}
void halt() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  prop3.run(RELEASE);
  prop4.run(RELEASE);
  //delay(700);
}

/**
Go straight backward until we have cleared the obsacle 
Then turn left so we dont hit it again.
*/
void backOut(){
   backwardLeft();
  
  while(wall())  // check for the wall once a second
    delay(1000);
    delay(3000); // Let it go back a little longer
      halt();

}
void stopTurning() {
  prop3.run(RELEASE);
  prop4.run(RELEASE);
}  

void forwardRight() {
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  prop3.run(FORWARD);
  prop4.run(RELEASE);
}

void forwardLeft(){
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  prop3.run(RELEASE);
  prop4.run(FORWARD); 
}

void backwardRight() {
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  prop3.run(RELEASE);
  prop4.run(FORWARD);
}

void backwardLeft(){
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  prop3.run(FORWARD);
  prop4.run(RELEASE);
}

/**
An Obstacle is an object in the path that cannot be avoided by turninng (about 100 cm)
If true, the skimmer should attempt to turn around.
*/
boolean obstacle(){

  if (obstacleSearch() < 100){ //less than 82cm
  //  delay(500);         // wait a few milliseconds to try again so we can weed out false positives
    if (obstacleSearch() < 100) //less than 82cm
        return true;
    else  return false;
  }
  else  return false;

}

/*
    if a wall can be found early enough the skimmer can turn to avoid it (200cm)
*/
 boolean wall(){
   if (obstacleSearch() < 200){
       //delay(100);         // wait a few milliseconds to try again so we can weed out false positives
    if (obstacleSearch() < 200) //less than 82cm
        return true;
    else  return false;
  }
  else return false;
  
}

/*
The distance sensor is used to determine the distance
*/
long obstacleSearch(){
  long duration,distance;
  digitalWrite(trigPin, LOW);//begin sensor pulse
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);//actual pulse
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);//end sensor pulse
  duration = pulseIn(echoPin, HIGH);//take pulse numbers
  distance = (duration/2)/29.1;//calculate distance
  return distance;
}
