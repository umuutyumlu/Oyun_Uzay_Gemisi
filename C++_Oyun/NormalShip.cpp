//
// Created by hilal on 12.03.2024.
//

#include "NormalShip.h"
#include <iostream>

using namespace std;

void NormalShip::setDamageCoefficent() {
    this->damageCoefficent = this->getDamageCoefficent() * 1;
    //cout<<"Fast Ship Damage Coeeficent : "<< this->getDamageCoefficent()<<endl;

}

void NormalShip::setEscapeCoefficent() {
this->escapeCoefficent = this->getEscapeCoefficent() * 1;
//cout<<"Fast Ship Escape Coeeficent : "<< this->getEscapeCoefficent()<<endl;
}

NormalShip::NormalShip(float fuel, float health, float money): Ship(fuel,health,money) {

    this->setDamageCoefficent();
    this->setEscapeCoefficent();
}
