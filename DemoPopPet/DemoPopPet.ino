#include "PopPet.h"

//Cria um novo Pet
// 7 - Porta Echo
// 8 - Porta Trigger
// 6 - Porta Motor 1
// 5 - Porta Motor 2
PopPet pet(7,8,6,5);

//Variável para
//guardar a distancia
int distancia = 0;

void setup ()
{
  //Configura a comunicação 
  //com o computador
  Serial.begin(9600);

  //Inicializa o pet
  pet.Initialize();
}
 
void loop()
{
   //Captura a distancia do
   //sensor ultrasonico
   distancia = pet.Distancia();

   //Mostra a distância no 
   //computador
   Serial.print("Distancia: ");
   Serial.println(distancia);

   //Se a distância for menor que 20cm
   if(distancia < 20){
     //Anda para a frente por 400ms
     pet.AndarFrente(400);
   }else{
    //Senão, para o robô
    pet.Parar();
   }
 
}
