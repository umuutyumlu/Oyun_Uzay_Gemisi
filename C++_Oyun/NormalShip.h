//
// Created by hilal on 12.03.2024.
//

#ifndef UNTITLED3_NORMALSHIP_H
#define UNTITLED3_NORMALSHIP_H

#include "Ship.h"

class NormalShip : public Ship{
public:
    NormalShip(float fuel,float health,float money);
    void setDamageCoefficent() override;
    void setEscapeCoefficent() override;
};


#endif //UNTITLED3_NORMALSHIP_H
