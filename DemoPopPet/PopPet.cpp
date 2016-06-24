#include "PopPet.h"

PopPet::PopPet(int pinEcho, int pinTrigger, int pinMotor1, int pinMotor2){
  this->pinMotor1 = pinMotor1;
  this->pinMotor2 = pinMotor2;
  this->pinEcho = pinEcho;
  this->pinTrigger = pinTrigger;
}

void PopPet::Initialize(){
  pinMode(this->pinTrigger, OUTPUT);
  pinMode(this->pinEcho, INPUT);
}

void PopPet::VirarEsquerda(){
  s1.attach(pinMotor1);
  s2.attach(pinMotor2);
  s1.write(0);
  s2.write(0);
}

void PopPet::VirarDireita(){
  s1.attach(pinMotor1);
  s2.attach(pinMotor2);
  s1.write(200);
  s2.write(200);
}

void PopPet::AndarFrente(){
  s1.attach(pinMotor1);
  s2.attach(pinMotor2);
  s1.write(0);
  s2.write(200);
}

void PopPet::AndarTras(){
  s1.attach(pinMotor1);
  s2.attach(pinMotor2);
  s1.write(200);
  s2.write(0);
}

void PopPet::VirarEsquerda(int tempo){
  s1.attach(pinMotor1);
  s2.attach(pinMotor2);
  s1.write(0);
  s2.write(0);
  delay(tempo);
  Parar();
}

void PopPet::VirarDireita(int tempo){
  s1.attach(pinMotor1);
  s2.attach(pinMotor2);
  s1.write(200);
  s2.write(200);
  delay(tempo);
  Parar();
}

void PopPet::AndarFrente(int tempo){
  s1.attach(pinMotor1);
  s2.attach(pinMotor2);
  s1.write(0);
  s2.write(200);
  delay(tempo);
  Parar();
}

void PopPet::AndarTras(int tempo){
  s1.attach(pinMotor1);
  s2.attach(pinMotor2);
  s1.write(200);
  s2.write(0);
  delay(tempo);
  Parar();
}

void PopPet::Parar(){
  s1.detach();
  s2.detach();
}

long PopPet::Distancia(){
  digitalWrite(this->pinTrigger, LOW); 
   delayMicroseconds(2); 
  
   digitalWrite(this->pinTrigger, HIGH);
   delayMicroseconds(10); 
   
   digitalWrite(this->pinTrigger, LOW);
   this->duracao = pulseIn(this->pinEcho, HIGH);
   
   //Calculate the distance (in cm) based on the speed of sound.
   this->distancia = duracao/58.2;

   return this->distancia;
}

