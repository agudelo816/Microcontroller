/*******************************************************************************
 *
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTY AND SUPPORT
 * IS APPLICABLE TO THIS SOFTWARE IN ANY FORM. CYTRON TECHNOLOGIES SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL
 * DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ********************************************************************************
 *
 * SHIELD-MD10 EXAMPLE SOURCE CODE
 *
 *
 *
 * DESCRIPTION:
 *
 * This is an example to control the motor by using SHIELD-MD10.
 * The speed of the motor will ramp up from 0 to full speed,
 * and then ramp down back to 0 in both CW and CCW direction.
 *
 *
 *
 * AUTHOR   : Kong Wai Weng
 * COMPANY  : Cytron Technologies Sdn Bhd
 * REVISION : 1.0
 * DATE     : 22/10/2012
 *
 *******************************************************************************/



/*******************************************************************************
 * IO DEFINITION                                                                *
 *******************************************************************************/

// PWM is connected to pin 3.
const int pinPwmA = 3;
const int pinPwmB = 3;

//const int pinPwmB = 6;

// DIR is connected to pin 2.
const int pinDirA = 2;
//const int pinDirB = 7;
const int pinDirB = 2;




/*******************************************************************************
 * PRIVATE GLOBAL VARIABLES                                                     *
 *******************************************************************************/

// Speed of the motor.
static int iSpeed = 0;
static int iSpeedB = 0;


// Acceleration of the motor.
static int iAcc = 10;


/*******************************************************************************
 * FUNCTIONS                                                                    *
 *******************************************************************************/

// The setup routine runs once when you press reset.
void setup() {                
  Serial.begin(9600);      // open the serial port at 9600 bps:    
  // Initialize the PWM and DIR pins as digital outputs.
  pinMode(pinPwmA, OUTPUT);
  pinMode(pinDirA, OUTPUT);
  pinMode(pinPwmB, OUTPUT);
  pinMode(pinDirB, OUTPUT);
}



// The loop routine runs over and over again forever.
void loop() {
  
  Serial.println(iSpeed, DEC);      

  
  // Control the motor according to the speed value.
  // Positive speed value = CW,
  // Negative speed value = CCW.
  
  if (iSpeed >= 0) {
    //Serial.print("iSpeed >= 0");       // prints a label
/*
    analogWrite(pinPwmA, iSpeed);
    digitalWrite(pinDirA, LOW); */

    analogWrite(pinPwmB, iSpeed);
    digitalWrite(pinDirB, LOW);
  } 
  else {

  //  Serial.print("iSpeed < 0");       // prints a label
    /*
    analogWrite(pinPwmA, -iSpeed);
    digitalWrite(pinDirA, HIGH);
    */

    analogWrite(pinPwmB, -iSpeed);
    digitalWrite(pinDirB, HIGH);
  }
  
  
  // Increase/Decrease the speed according to the acceleration.
  iSpeed += iAcc;
  
  // Change the acceleration sign when full speed is reached.
  if ((iSpeed >= 250) || (iSpeed <= -250)) {
    iAcc = -iAcc;
   
  }
  delay(500);
  
}

