# Proyecto Análisis de consumo PC Gamer en casa
Este proyecto se basa en la obtención de los datos del sensor PZEM004T-V1, que nos permite ver la potencia activa que consume en este caso, el computador.
Lo anterior se pudo realizar gracias a que se usó un programa llamado CoolTerm, que nos permite conectarnos al serial del Arduino y obtener los datos impresos, los cuales se imprimen separados por comas y en cierto orden:
```
 Serial.print(v);Serial.print(",");Serial.print(i);Serial.print(",");Serial.print(p);Serial.print(",");Serial.print(s);Serial.print(",");Serial.print(q);Serial.print(",");Serial.println(fp);  
```
Lo anterior se hizo de esta manera para poder visualizar correctamente el archivo csv y así mismo ser importado por medio de Python para una correcta visualización.
## Montaje y Conexión 
El montaje se relaciona con la imagen a continuación:
[GitHub Logo](./images/montaje.jpeg)

