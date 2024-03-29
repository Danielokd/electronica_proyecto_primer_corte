#include <SoftwareSerial.h> // Arduino IDE <1.6.6
#include <PZEM004T.h>


PZEM004T pzem(2,3);  // (RX,TX) connect to TX,RX of PZEM
IPAddress ip(192,168,1,1);

void setup() {
  Serial.begin(9600);
  pzem.setAddress(ip);        
}

void loop() {
  //voltaje RMS

  float v = pzem.voltage(ip);
  // Si hay error de comunicacion el voltaje = -1 por ello la condicion
  if (v < 0.0) v = 0.0;
  //Corriente RMS 
  float i = pzem.current(ip);
  //Potencia Promedio o activa 
  float p = pzem.power(ip);
  //potencia aparente
  float s= v*i;
  // reactive power
  float p2= pow(p,2);
  float s2= pow(s,2);
  float s2p2=s2-p2;
  bool complejo=false;
  if(s2p2<0){
    s2p2=abs(s2p2);
    complejo=true ;
    }
  float q = sqrt(s2p2);
  //factor de potencia
  float fp=p/s;
  if(i>0){
    Serial.print(v);Serial.print(",");Serial.print(i);Serial.print(",");Serial.print(p);Serial.print(",");Serial.print(s);Serial.print(",");Serial.print(q);Serial.print(",");Serial.println(fp);  
  }
  else{
    Serial.println("No hay una carga conectada");  
  }
  delay(172800); // Mil datos al cabo de 2 días 
}
