#include <Servo.h>
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPL43fcGLgdj"
#define BLYNK_TEMPLATE_NAME "slider2"
#define BLYNK_AUTH_TOKEN "02yt1upeF_ca36dDW7P2CcKbMohOHb_s"
#include <BlynkSimpleStream.h>

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial1
#define SERVO_1_PIN 10
#define SERVO_2_PIN 11


char auth[] = BLYNK_AUTH_TOKEN;
int light_slider_value = 0;
int up_down_slider_value = 0;
// define servo 1
Servo servo1;
int pos_servo1 = 90;

// define second servo
Servo servo2;
int pos_servo2 = 90;

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 0
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V0 to a variable
  up_down_slider_value = pinValue;
  servo2.write(up_down_slider_value);
}



// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  light_slider_value = pinValue;
}

void setup()
{
  // Debug console (terminal)
  Serial1.begin(115200);

  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);

  servo1.attach(SERVO_1_PIN);
  servo2.attach(SERVO_2_PIN);
  Serial1.println("Hello Brother");
  //Serial1.println("afalkmal");
  //Blynk.begin(auth);
  Blynk.begin(Serial, auth);
  //Blynk.begin(Serial, BLYNK_AUTH_TOKEN);

  Serial1.println("Blynk began");
  // Wait until connected to Blynk
  while (Blynk.connect() == false) {
    // Wait until connected
  }

  Serial1.println("Connected to Blynk!");
  
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
  int ldr = analogRead(A0);
  int ldrRange = map(ldr,0,1023,0,100);
  Serial1.print("light sensor value: ");
  Serial1.println(ldrRange);
  Serial1.print("desired light: ");
  Serial1.println(light_slider_value);
  Serial1.print("up down: ");
  Serial1.println(up_down_slider_value);
  int val = ldrRange - light_slider_value;
  if (val > 0 ){
    Serial1.print("Changing to:"); 
    Serial1.println(val);
    servo2.write(val);
  }else{
    Serial1.print("Changing to:"); 
    Serial1.println(0);
    servo2.write(0);
  }
  // i deleted delay!!!
  delay(5000);
}
