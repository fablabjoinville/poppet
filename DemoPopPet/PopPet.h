#ifndef POPPET_H
#define POPPET_H

#include "Arduino.h"
#include <Servo.h>

class PopPet{
  private:
    long duracao;
    long distancia;
    int pinTrigger;
    int pinEcho;
    int pinMotor1;
    int pinMotor2;
    Servo s1;
    Servo s2;

  public:
    PopPet(int pinEcho, int pinTrigger, int pinMotor1, int pinMotor2);
    void Initialize();
    void VirarEsquerda();
    void VirarDireita();
    void AndarFrente();
    void AndarTras();
    void Parar();
    long Distancia();
};

#endif
