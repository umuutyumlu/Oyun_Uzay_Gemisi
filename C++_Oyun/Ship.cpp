//
// Created by hilal on 12.03.2024.
//

#include "Ship.h"
#include <iostream>

using namespace std;

void Ship::setEscapeCoefficent() {
    cout<<"setEscapeCoefficent called.";
}
void Ship::setDamageCoefficent() {
    cout<<"setDamageCoefficent called.";
}

float Ship::getFuel() const {
    return fuel;
}

void Ship::setFuel(float fuel) {
    Ship::fuel = fuel;
}

float Ship::getHealth() const {
    return health;
}

void Ship::setHealth(float health) {
    Ship::health = health;
}

float Ship::getMoney() const {
    return money;
}

void Ship::setMoney(float money) {
    Ship::money = money;
}

Ship::Ship(float fuel, float health, float money) {
    this->fuel = fuel;
    this->health = health;
    this->money = money;
    this->damageCoefficent = 1;
    this->escapeCoefficent = 1;


}

float Ship::getEscapeCoefficent() const {
    return escapeCoefficent;
}

float Ship::getDamageCoefficent() const {
    return damageCoefficent;
}

void Ship::getDamage() {
    float realDamage = 10 * this->getDamageCoefficent();
    float initialHealth = this->getHealth();
    float lastHealth = initialHealth - realDamage;
    this->setHealth(lastHealth);
}

void Ship::getDamageFromPirates(){
    float damage = 30 * this->getDamageCoefficent();
    float newHealth = this->getHealth() - damage;
    this->setHealth(newHealth);
}

void Ship::collectMoney() {
    this->money = this->getMoney() + 10;
}

float Ship::calculateGamePoints(){
    float gamePoint = (this->getFuel() * 5)+ (this->getHealth() * 10)+(this->getMoney() * 10);
    return gamePoint;
}

void Ship::loseFuel() {
    float newFuel = this->getFuel() - 33;
    this->setFuel(newFuel);
}
void Ship::dealWithSpacePirates() {
    if(this->getFuel() <= 0){
        cout<<"Yakit Kamadi Oyun Bitti !!!";
        return;
    }
    int chosenState = this->selectPirateState();
    //chosenState 1=>escape from pirates; 2=> fight with pirates; 3=> agree with pirates
    if(chosenState == 1){
            float newFuel = this->getFuel() - 33;
            int escapeRandomNumber = (rand() %100)+1;
            if(escapeRandomNumber <=this->getEscapeCoefficent() * 50 && escapeRandomNumber >0){
                //escape is success.
                cout<<"Korsanlardan Kactin!"<<endl;
            }
            else{
                //escape is failed.
            cout<<"Korsanlardan Kacamadin !!!"<<endl;
            return this->dealWithSpacePirates();
            }
            this->loseFuel();
    }
    else if(chosenState ==2){
        //fight with pirates.
        float fightRandomNumber = (rand() %100)+1;
        if(fightRandomNumber <= this->getEscapeCoefficent() * 50 && fightRandomNumber >0){
            cout<<"Savasi Kazandin !"<<endl;
        }else{
            this->getDamageFromPirates();
            cout<<"Savasi Kaybettin Canin : "<< this->getHealth()<<endl;

        }
    }
    else if(chosenState ==3){
        int bargainRandomNumber = (rand() % 3)+1;
        if(bargainRandomNumber ==1){
            this->loseMoney(10);
        }else if(bargainRandomNumber ==2){
            this->loseMoney(20);
        }
        else if(bargainRandomNumber ==3){
            this->loseMoney(30);
        }

    }
}

void Ship::showShip(){
    cout<<"********************"<<endl;
    cout<<"Gemi Cani : "<<this->getHealth()<<endl;
    cout<<"Gemi Yakiti : "<<this->getFuel()<<endl;
    cout<<"Gemi Parasi : "<<this->getMoney()<<endl;
    cout<<"********************"<<endl;
}


int Ship::selectPirateState(){
    int state;
    bool isStated = false;
    while(!isStated){
        cout<<"****Uzay Korsanlariyla Karsilastin Secimini Yap !****"<<endl;
        cout<<"****1) Kac"<<endl;
        cout<<"****2) Savas"<<endl;
        cout<<"****3) Pazarlik Et"<<endl;
        cin>>state;
        switch (state) {
            case 1:
                if(this->getFuel() >=33){
                    isStated = true;
                    return 1;
                } else{
                    cout<<"Kacmak Icin Yeterli Yakit Yok ! Savas Veya Pazarlik Et";
                    isStated= false;
                    break;
                }


            case 2:
                isStated = true;
                return 2;

            case 3:
                isStated = true;
                return 3;

            default:
                isStated = false;
                cout<<"Yanlis Secim Yaptiniz.";
                break;
        }
    }


}


void Ship::loseMoney(float loseMoney){
    float newMoney = this->getMoney() - loseMoney;
    this->setMoney(newMoney);
}

