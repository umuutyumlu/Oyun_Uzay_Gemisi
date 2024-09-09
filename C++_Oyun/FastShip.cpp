//
// Created by hilal on 12.03.2024.
//

#include "FastShip.h"
#include <iostream>

using namespace std;
void FastShip::setDamageCoefficent() {
    this->damageCoefficent = this->getDamageCoefficent() * 1.5;
    //cout<<"Fast Ship Damage Coeeficent : "<< this->getDamageCoefficent()<<endl;

}
void FastShip::setEscapeCoefficent() {
    this->escapeCoefficent = this->getEscapeCoefficent() * 1.5;
    //cout<<"Fast Ship Escape Coeeficent : "<< this->getEscapeCoefficent()<<endl;
}

FastShip::FastShip(float fuel, float health, float money): Ship(fuel,health,money) {

    this->setDamageCoefficent();
    this->setEscapeCoefficent();
}