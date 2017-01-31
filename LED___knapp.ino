const int buttonPin = 2;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

int buttonState = 0;
int btnState = 0;
 
void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  

  pinMode(buttonPin, INPUT);

  setLED(0);
}
 
void loop(){
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
    if(btnState == 0){
      setLED(0);
      btnState = 1;
    }else{
      setLED(1);
      btnState = 0;
    }
  }
}
 
void setColor(int red, int green, int blue){
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
void setLED(int state){
  if(state == 0){
    setColor(255, 255, 255);
  }else if(state == 1){
    setColor(255, 0, 0);
  }else if(state == 2){
    setColor(0, 255, 0);
  }else if(state == 3){
    setColor(0, 0, 255);
  }
}

