
int a,s,d;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int i, x =0;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{ Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("start");
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop()
{
//if(Serial.available()){ 
//  Serial.println(Serial.read());
//}
  for(x=0;x<3;x++)
{
  if(Serial.available()){ 
//    char c = Serial.read();
//    if (c == '#') {break;} //Exit the loop when the # is detected after the word
//  d += c; //Shorthand for voice = voice + c
//if(Serial.available() == "20")
//{
//a = 0;
//s = 0;
//d = 0;
//}



if(x==0)
{
a = Serial.read();
Serial.print("A: ");
Serial.println(a);

}

else if(x==1)
{
  s = Serial.read();
  Serial.print("S: ");
Serial.println(s);

}
else if(x==2)
{
  d = Serial.read();
  Serial.print("D: ");
Serial.println(d);

}
}
}
x=0;

if(a==12)
{
  a = 0;
  s = 0;
  d = 0;
}
//  setColor(255, 0, 0);  // red
//  delay(1000);
//  setColor(0, 255, 0);  // green
//  delay(1000);
//  setColor(0, 0, 255);  // blue
//  delay(1000);
//  setColor(255, 255, 0);  // yellow
//  delay(1000);  
//  setColor(80, 0, 80);  // purple
//  delay(1000);
//  setColor(0, 255, 255);  // aqua
//  delay(1000);
//  setColor(255, 0, 255); //Pink
//  delay(1000);
//  //setColor(160, 160, 160); //Grey
//  //delay(1000);
//  setColor(255, 140, 0); //Grey
//  delay(1000);
//
setColor(a,s,d);
delay(1000);  
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
