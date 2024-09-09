#include <iostream>
#include <string>
#include <cstdlib>
#include "Ship.h"
#include "FastShip.h"
#include "StrongShip.h"
#include "NormalShip.h"

using namespace std;
void spacePirates(Ship* mySelectedShip){
    //
}


int main() {
    int secim;
    bool isSelected = false;
    Ship* mySelectedShip;
    string shipType;

    /*FastShip fastShip(100,100,0);
    cout<<"******************"<<endl;
    StrongShip strongShip(100,100,0);
    cout<<"******************"<<endl;
    NormalShip normalShip(100,100,0);
    cout<<"******************"<<endl;*/
    while(!isSelected){
    cout<<"Gemi Seciniz "<<endl;
    cout<<"********************"<<endl;
    cout<<"1) Hizli Gemi"<<endl;
    cout<<"2) Guclu Gemi"<<endl;
    cout<<"3) Normal Gemi"<<endl;
    cout<<"********************"<<endl;
    cout<<"Seciminiz : ";
    cin>>secim;
    switch (secim) {
        case 1:
            // hızlı gemi oluştur.
            mySelectedShip = new FastShip(100,100,0);
            shipType = "Fast Ship";
            isSelected = true;
            break;
        case 2:
            mySelectedShip = new StrongShip(100,100,0);
            shipType = "Strong Ship";
            isSelected = true;
            break;
        case 3:
            mySelectedShip = new NormalShip(100,100,0);
            shipType = "Normal Ship";
            isSelected = true;
            break;
        default:
            cout<<"Lutfen Gecerli Bir Gemi Secin !";
            isSelected = false;



    }
}


    /*cout<<"Ship Damage Coefficent : "<<mySelectedShip->getDamageCoefficent()<<endl;
    cout<<"Ship Escape Coefficent : "<<mySelectedShip->getEscapeCoefficent()<<endl;

    cout<<"Ship Health Before Damage : "<<mySelectedShip->getHealth()<<endl;
    mySelectedShip->getDamage();
    cout<<"Ship Health After Damage : "<<mySelectedShip->getHealth()<<endl;
*/
   for(int evenCount =0;evenCount < 5;evenCount++){
       cout<<"Gerceklestirilen Olay Sirasi : "<<evenCount + 1<<endl;
       if(mySelectedShip->getHealth() <=0){
           cout<<"Canınız Bitti"<<endl<<"Puanınız : 0"<<endl;
           return 0;
       }
       //get a random number between 0-2
       //1 => Asteroids
       //2 => Abandoned Planet
       //3 => Space Pirates
       int randomEventNumber = (rand() % 3)+1;
       //cout<<"Random Genrated Number : "<<randomEventNumber<<endl;
        if(randomEventNumber == 1){
            //get a random number 1 or 2 for lose health 3 times
            for(int asteroidCount =0;asteroidCount <3;asteroidCount++){
                int asteroidCollapseState = (rand() % 2) +1;
                if(asteroidCollapseState == 1){
                    //if ship can not escape from Asteroids
                    cout<<"Asteroide Carptin, Canin Azaldi."<<endl;
                    mySelectedShip->getDamage();
                    mySelectedShip->showShip();
                }else{
                    cout<<"Asteroide Carpmadin."<<endl;
                }
            }
        }else if(randomEventNumber == 2){
            int abandonedPlanetRandomNumber = (rand() % 2) +1;
            cout<<"Terk Edilmis Gezegene Gittin."<<endl;
            if (abandonedPlanetRandomNumber ==1){
                cout<<"10 Para Kazandin."<<endl;
                mySelectedShip->collectMoney();
                mySelectedShip->showShip();
            } else{
                mySelectedShip->dealWithSpacePirates();
                mySelectedShip->showShip();
            }

        }else if(randomEventNumber == 3){
            mySelectedShip->dealWithSpacePirates();
            mySelectedShip->showShip();
        } else{
            cout<<"Beklenmeyen Senaryo Gerceklesti."<<endl;
            return 0;
        }

        if(mySelectedShip->getFuel() <= 0 && mySelectedShip->getHealth() >0){
            mySelectedShip->showShip();
            cout<<"Yakit Kamadi Oyun Bitti !!!";
            float gamePoint = mySelectedShip->calculateGamePoints();
            cout<<"Oyun Skorunuz : "<<gamePoint<<endl;
            return 0 ;
        }

   }

    float gamePoint = mySelectedShip->calculateGamePoints();
    cout<<"5 Olay Gerceklesti Oyun Bitti !"<<endl;
    cout<<"Oyun Skorunuz : "<<gamePoint<<endl;

    return 0;
}

