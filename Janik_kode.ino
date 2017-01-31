int state = 0;
int buttonmem = 0;
int voltage = 0;
int threshhold = 64;
int axon = 1;
int led = 10;
int clk = 5;
int btn = 6;
int vscaled;
void setup() {
  pinMode(axon, OUTPUT);
  pinMode(led, OUTPUT);
  for (int i = 2; i<9; i++){
  pinMode((i), INPUT);
  }
}
//1: axon, 2-4: dendrit, 5:clk, 6:btn, 7,8:bryter, 10:led,

void loop() {
  if(!state && digitalRead(clk)){
   readinputs();
   state=1;
  }
  else if(state && !digitalRead(clk)){
  writeoutputs();
  state=0;
  buttonmem = 0;
  }
  if(digitalRead(btn) && buttonmem){
  buttonmem = 1;
  }
}

void writeoutputs(){
  if(buttonmem || ((threshhold*64)<=voltage)){
  digitalWrite(axon, LOW);
  voltage = 0;
  } else{
  digitalWrite(axon, HIGH);
  }
}

void readinputs(){
  voltage=-16;
  for (int i = 2; i < 5; i++){
  if (!digitalRead(i)){
    if (voltage<64){
      voltage+=128;
    }else if(voltage < 128){
      voltage+=64;
    }else{
      voltage+=16;
    }
  }
  }
  vscaled = (5-threshhold)*voltage;
  analogWrite(led, vscaled);
}
