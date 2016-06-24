#include "PopPet.h"

PopPet pet(7,8,6,5);

int distancia = 0;

void setup ()
{
  Serial.begin(9600);
  pet.Initialize();
  
}
 
void loop()
{
   distancia = pet.Distancia();
   Serial.print("Distancia: ");
   Serial.println(distancia);

   
   if(distancia < 20){
     pet.AndarFrente(400);
   }else{
    pet.Parar();
   }
 
}
