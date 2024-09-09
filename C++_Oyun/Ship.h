//
// Created by hilal on 12.03.2024.
//

#ifndef UNTITLED3_SHIP_H
#define UNTITLED3_SHIP_H


class Ship {
protected:
    float fuel;
    float health ;
    float money;
    float escapeCoefficent;
    float damageCoefficent;

public:

    float getFuel() const;
    Ship(float fuel,float health,float money);

    float calculateGamePoints();
    int selectPirateState();
    void getDamage();
    void collectMoney();
    void loseMoney(float loseMoney);
    void loseFuel();
    void dealWithSpacePirates();
    void getDamageFromPirates();
    float getEscapeCoefficent() const;
    float getDamageCoefficent() const;
    virtual void setEscapeCoefficent();
    virtual void setDamageCoefficent();
    void setFuel(float fuel);

    void showShip();

    float getHealth() const;

    void setHealth(float health);

    float getMoney() const;

    void setMoney(float money);

};


#endif //UNTITLED3_SHIP_H
