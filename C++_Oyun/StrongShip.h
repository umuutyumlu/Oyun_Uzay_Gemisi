//
//
//

#ifndef UNTITLED3_STRONGSHIP_H
#define UNTITLED3_STRONGSHIP_H

#include "Ship.h"

class StrongShip : public Ship{
public:
    StrongShip(float fuel,float health,float money);
    void setDamageCoefficent() override;
    void setEscapeCoefficent() override;
};


#endif //UNTITLED3_STRONGSHIP_H
