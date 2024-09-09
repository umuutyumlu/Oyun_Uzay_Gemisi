//
//
//

#ifndef UNTITLED3_FASTSHIP_H
#define UNTITLED3_FASTSHIP_H

#include "Ship.h"

class FastShip : public Ship{
public:
     FastShip(float fuel,float health,float money);
     void setDamageCoefficent() override;
     void setEscapeCoefficent() override;
};


#endif //UNTITLED3_FASTSHIP_H
