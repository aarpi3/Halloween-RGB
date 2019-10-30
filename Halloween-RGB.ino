int PIR = 2;
int sound = 4;

#define RED_LED 6
#define BLUE_LED 5

int ledcolor = 6;

const int randcolor[] = {6, 6, 6, 5};  //global variable

int brightness = 255;

int rBright = 0;
int bBright = 0;

int fadeSpeed = 10;

void setup() {
  Serial.begin(9600);
   pinMode(PIR, INPUT);
   pinMode(sound, OUTPUT);   
   pinMode(RED_LED, OUTPUT);
   pinMode(BLUE_LED, OUTPUT);
   digitalWrite(sound, LOW);
   Serial.println("Turning on");
   TurnOn();
   delay(1000);
}

void TurnOn() { 
   for (int i = 0; i < 256; i++) {
       analogWrite(RED_LED, rBright);
       rBright +=1;
       delay(fadeSpeed);
   }
   analogWrite(RED_LED, 0);
 
   for (int i = 0; i < 256; i++) {
       analogWrite(BLUE_LED, bBright);
       bBright += 1;
       delay(fadeSpeed);
   } 
   analogWrite(BLUE_LED, 0);
   
}

void loop() {
  if (digitalRead(PIR) == HIGH){
    Serial.println("Motion Detected");
    digitalWrite(sound, HIGH);
    // put your main code here, to run repeatedly:
    int flashCount = random (5, 25);        // Min. and max. number of flashes each loop
    int flashBrightnessMin =  100;           // LED flash min. brightness (0-255)
    int flashBrightnessMax =  255;          // LED flash max. brightness (0-255)
  
    int flashDurationMin = 1;               // Min. duration of each seperate flash
    int flashDurationMax = 50;              // Max. duration of each seperate flash
  
    int nextFlashDelayMin = 1;              // Min, delay between each flash and the next
    int nextFlashDelayMax = 150;            // Max, delay between each flash and the next
  
    for (int flash = 0 ; flash <= flashCount; flash += 1) { // Flashing LED strip in a loop, random count
      ledcolor = randcolor[random(0, 4)];  
      analogWrite(ledcolor, random (flashBrightnessMin, flashBrightnessMax)); // Turn LED strip on, random brightness
      delay(random(flashDurationMin, flashDurationMax)); // Keep it tured on, random duration
  
      analogWrite(ledcolor, 0); // Turn the LED strip off
      delay(random(nextFlashDelayMin, nextFlashDelayMax)); // Random delay before next flash
    }
    delay(5000);
  }
  else{
    Serial.println("Stoped");
    digitalWrite(sound, LOW);
    analogWrite(BLUE_LED, 0);
    analogWrite(BLUE_LED, 0);
    delay(1000);
  }
}
