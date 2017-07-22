#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <math.h>

static const int RXPin = 10, TXPin = 11;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

int D0 = 2;
int D1 = 3;
int D2 = 4;
int D3 = 5;
int D00 = 6;
int D11 = 7;
int D22 = 8;
int D33 = 9;

void setup() 
{
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(8, OUTPUT); 
 pinMode(9, OUTPUT);
 digitalWrite(D0, HIGH);
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D00, HIGH);
 digitalWrite(D11, HIGH);
 digitalWrite(D22, HIGH);
 digitalWrite(D33, HIGH);
 Serial.begin(115200);
 ss.begin(GPSBaud);
 Serial.println("setup");
 
}

void loop() {
  if (gps.speed.isUpdated())
  {
  disp(gps.speed.mph());
  Serial.println(gps.speed.mph(), gps.speed.isValid());
  }
  
}

void disp(float d) {
  d = roundf(d);
  int dd = (int) d;
  int ones = (dd%10);
  int tens = ((dd/10)%10);

  switch(ones){
    case 0:
    {
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    
    }
    break; 
    case 1:
    {
    digitalWrite(D0, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW); 
    
    }
    break;
    case 2:
    {
    digitalWrite(D0, LOW);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
     
    }
    break;
    case 3:
    {
    digitalWrite(D0, HIGH);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
     
    }
    break;
    case 4:
    {
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW); 
    
    }
    break;
    case 5:
    {
    digitalWrite(D0, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    
    }
    break;
    case 6:
    {
    digitalWrite(D0, LOW);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
      
    }
    break;
    case 7:
    {
    digitalWrite(D0, HIGH);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
     
    }
    break;
    case 8:
    {
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
     
    }
    break;
    case 9:
    {
    digitalWrite(D0, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    
    }
    break;
    
  }
  switch(tens){
     case 0:
    {
    digitalWrite(D00, LOW);
    digitalWrite(D11, LOW);
    digitalWrite(D22, LOW);
    digitalWrite(D33, LOW);
    
    }
    break; 
    case 1:
    {
    digitalWrite(D00, HIGH);
    digitalWrite(D11, LOW);
    digitalWrite(D22, LOW);
    digitalWrite(D33, LOW);
    
    }
    break;
    case 2:
    {
    digitalWrite(D00, LOW);
    digitalWrite(D11, HIGH);
    digitalWrite(D22, LOW);
    digitalWrite(D33, LOW);
     
    }
    break;
    case 3:
    {
    digitalWrite(D00, HIGH);
    digitalWrite(D11, HIGH);
    digitalWrite(D22, LOW);
    digitalWrite(D33, LOW); 
   
    }
    break;
    case 4:
    {
    digitalWrite(D00, LOW);
    digitalWrite(D11, LOW);
    digitalWrite(D22, HIGH);
    digitalWrite(D33, LOW); 
    
    }
    break;
    case 5:
    {
    digitalWrite(D00, HIGH);
    digitalWrite(D11, LOW);
    digitalWrite(D22, HIGH);
    digitalWrite(D33, LOW); 
    
    }
    break;
    case 6:
    {
    digitalWrite(D00, LOW);
    digitalWrite(D11, HIGH);
    digitalWrite(D22, HIGH);
    digitalWrite(D33, LOW);
      
    }
    break;
    case 7:
    {
    digitalWrite(D00, HIGH);
    digitalWrite(D11, HIGH);
    digitalWrite(D22, HIGH);
    digitalWrite(D33, LOW); 
     
    }
    break;
    case 8:
    {
    digitalWrite(D00, LOW);
    digitalWrite(D11, LOW);
    digitalWrite(D22, LOW);
    digitalWrite(D33, HIGH); 
     
    }
    break;
    case 9:
    {
    digitalWrite(D00, HIGH);
    digitalWrite(D11, LOW);
    digitalWrite(D22, LOW);
    digitalWrite(D33, HIGH);
    
    }
    break;
  }
  
}
