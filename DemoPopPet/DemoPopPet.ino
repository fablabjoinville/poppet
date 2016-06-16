#include "PopPet.h"

PopPet pet(7,8,6,5);

void setup ()
{
  Serial.begin(9600);
  pet.Initialize();
  
}
 
void loop()
{
   
   Serial.print("Distancia: ");
   Serial.println(pet.Distancia());
  
   if(pet.Distancia() < 15){
     while(pet.Distancia() < 20){
      pet.AndarTras();
     }
   }else if(pet.Distancia() > 15 && pet.Distancia() < 20){
    pet.VirarDireita();
   }else{
    pet.AndarFrente();
   }
   
   delay(100);
}
