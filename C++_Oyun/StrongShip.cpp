//
// Created by hilal on 12.03.2024.
//

#include "StrongShip.h"
#include <iostream>

using namespace std;
void StrongShip::setDamageCoefficent() {
    this->damageCoefficent = this->getDamageCoefficent() * 0.5;
    //cout<<"Fast Ship Damage Coeeficent : "<< this->getDamageCoefficent()<<endl;

}

void StrongShip::setEscapeCoefficent() {
this->escapeCoefficent = this->getEscapeCoefficent();
//cout<<"Fast Ship Escape Coeeficent : "<< this->getEscapeCoefficent()<<endl;
}

StrongShip::StrongShip(float fuel, float health, float money): Ship(fuel,health,money) {

    this->setDamageCoefficent();
    this->setEscapeCoefficent();
}