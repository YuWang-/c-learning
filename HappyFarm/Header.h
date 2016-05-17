//
//  Header.h
//  HappyFarm
//
//  Created by Yu on 07/04/16.
//  Copyright © 2016 Yu. All rights reserved.
//

#ifndef Header_h
#define Header_h


#endif /* Header_h */
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
enum foods{fishfood, birdfood,mammalfood};
class Animal
{public:
    Animal(){HowManycats++;};
    Animal(int age, int weight):itsAge(age),itsWeight(weight){HowManycats++;}
    virtual ~Animal(){HowManycats--;}
    
    //animal as an abstract data type(ADT),

    virtual void eat(int n, int mineat,int GainweightQuan,int loseweightquan);// 实现虚函数，提供通用
    //void die(int maxAge)
    virtual void speak(){};//
    virtual void move(){};
    virtual void reproduce(){};
    
    virtual int GetAge(){return itsAge;}
    virtual void SetAge(int age){itsAge=age;}
    virtual int GetWeight(){return itsWeight;}
    virtual void SetWeight(int weight){ itsWeight=weight;}
    
    virtual int howmanyani(){return HowManycats;}

    
protected:
    int itsAge;
    int itsWeight;
    static int HowManycats;
    
};
int Animal::HowManycats=0;
void Animal::eat(int n, int mineat,int GainweightQuan,int loseweightquan){
    itsWeight=(n<mineat)?(itsWeight-loseweightquan):(itsWeight+GainweightQuan);
};

class fish: public Animal//虚基类
{
public:
    fish():Animal(0,3){FishNumber++;}
    fish(int Age, int weight):Animal(Age,weight){FishNumber++;}
    virtual ~fish(){FishNumber--;}
    
    virtual void reproduce(){cout<<"fish is laying eggs.\n";}
    virtual void speak(){cout<<"A fish is always in silence.\n";}
    virtual void move(){cout<<"I'm siwmming in the pool.\n";}
    virtual void eat(foods foodfeed,int quan);

    
private:
    static int FishNumber;
    const int Fishmineat=5,FishGain=2,FishLose=3;
};
int fish::FishNumber=0;// set the original fish number to 0;
void fish::eat(foods foodfeed,int quan){
    if (foodfeed==fishfood)
        Animal::eat(quan,Fishmineat,FishGain,FishLose);// 使用纯虚函数的提供的通用方法
    else
        cout<<"I need Fish FOOD!\n";
};


class bird: public Animal{
public:
    bird(){Animal(0,10);birdNumber++;}
    bird(int Age, int weight){Animal(Age,weight);birdNumber++;}
    virtual ~bird(){birdNumber--;}
    
    virtual void reproduce(int NewbornNum){cout<<"I'm laying "<< NewbornNum <<" eggs.\n";}
    
private:
    static int birdNumber;
    // fish is in maximal 10 yesrs old.
    //  const int birdmineat=5,birdGain=2,birdLose=3,MaxAge = 10;
    
};
int bird::birdNumber=0;

class Mammal: public Animal{
public:
    Mammal(int Age, int weight){Animal(Age,weight);MammalNumber++;}
    virtual ~Mammal(){MammalNumber--;}
    
    virtual void reproduce(int NewbornNum){cout<<"I'm delievinging "<<NewbornNum<<" babies.\n";}
    
private:
    static int MammalNumber;
    // fish is in maximal 10 yesrs old.
    //const int Mammalmineat=5,MammalGain=2,birdLose=3,MaxAge = 10;
    
};
int Mammal::MammalNumber=0;

class Horse:public Mammal{
    Horse():Mammal(0,10){HorseNumber++;}
    Horse(int Age, int weight):Mammal(Age,weight){HorseNumber++;}
    virtual ~Horse(){HorseNumber--;}
    
    virtual void speak(){cout<<"Beeeep.\n";}
    virtual void move(){cout<<"I'm running in the blue field.\n";}
    virtual void eat(foods foodfeed,int quan);
    // virtual void reproduce(NewbornNum){cout<<"I'm delievinging "<<NewbornNum<<" horses.\n";}
    
private:
    static int HorseNumber;
    // fish is in maximal 10 yesrs old.
    const int Horsemineat=5,HorseGain=2,HorseLose=3,MaxAge = 10;
    
};
int Horse::HorseNumber=0;

void Horse::eat(foods foodfeed,int quan){
    if (foodfeed==mammalfood)
        Animal::eat(quan,Horsemineat,HorseGain,HorseLose);
    else
        cout<<"I need bird FOOD!\n";
};
class Pig:public Mammal{
public:
    Pig():Mammal(0,10){PigNumber++;}
    Pig(int Age, int weight):Mammal(Age,weight){PigNumber++;}
    virtual ~Pig(){PigNumber--;}
    
    virtual void speak(){cout<<"Beeeep.\n";}
    virtual void move(){cout<<"I'm running in the blue field.\n";}
    virtual void eat(foods foodfeed,int quan);
    virtual void reproduce(){cout<<"Bird is laying eggs.\n";}
    
private:
    static int PigNumber;
    // fish is in maximal 10 yesrs old.
    const int Pigmineat=5,PigGain=2,PigLose=3,MaxAge = 10;
    
};
int Pig::PigNumber=0;

void Pig::eat(foods foodfeed,int quan){
    if (foodfeed==mammalfood)
        Animal::eat(quan,Pigmineat,PigGain,PigLose);
    else
        cout<<"I need bird FOOD!\n";
};

class chicken:public bird{
public:
    chicken():bird(0,10){chickenNumber++;}
    chicken(int Age, int weight):bird(Age,weight){chickenNumber++;}
    virtual ~chicken(){chickenNumber--;}
    virtual void speak(){cout<<"ji.\n";}
    virtual void move(){cout<<"I'm running in the blue field.\n";}
    virtual void eat(foods foodfeed,int quan);
    virtual void reproduce(int NewbornNum){bird::reproduce(NewbornNum);}
private:
    static int chickenNumber;
    // fish is in maximal 10 yesrs old.
    const int chickenmineat=5,chickenGain=2,chickenLose=3,MaxAge = 10;
    //int NewbornNum;
    
};
int chicken::chickenNumber=0;

void chicken::eat(foods foodfeed,int quan){
    if (foodfeed==birdfood)
        Animal::eat(quan,chickenmineat,chickenGain,chickenLose);
    else
        cout<<"I need bird FOOD!\n";
};





