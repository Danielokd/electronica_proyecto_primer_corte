# Proyecto Análisis de consumo PC Gamer en casa
Este proyecto se basa en la obtención de los datos del sensor PZEM004T-V1, que nos permite ver la potencia activa que consume en este caso, el computador.

Podemos acceder directamente a los datos de corriente y potencia activa que detecta el sensor, usando métodos de la librería:
```
//Corriente RMS 
  float i = pzem.current(ip);
  //Potencia Promedio o activa 
  float p = pzem.power(ip);
```
Con estos datos, y basándonos en las fórmulas vistas en clase, obtenemos los datos restantes solicitados realizando estos cálculos:
```
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
```
Acto seguido tratamos de conectarnos al serial de arduino para poder guardar los datos que se están mostrando por este medio.
Lo anterior se pudo realizar gracias a que se usó un programa llamado CoolTerm, que nos permite conectarnos al serial del Arduino y obtener los datos impresos, los cuales se imprimen separados por comas y en cierto orden:
```
 Serial.print(v);Serial.print(",");Serial.print(i);Serial.print(",");Serial.print(p);Serial.print(",");Serial.print(s);Serial.print(",");Serial.print(q);Serial.print(",");Serial.println(fp);  
```
Lo anterior se hizo de esta manera para poder visualizar correctamente el archivo csv y así mismo ser importado por medio de Python para una correcta visualización.
## Montaje y Conexión 
El montaje se relaciona con la imagen a continuación:
[Ver Conexión](./images/montaje.jpeg)
## Funcionalidades
Para poder detectar de manera correcta el comportamiento a través del tiempo, se tomaron alrededor de 500 datos a lo largo de un día  completo en tiempos de uso y desuso del equipo. 
De la misma manera, dependiendo de las actividades que se estuvieran realizando, el consumo del equipo es variado.


