//
//  main.cpp
//  HelloWorld
//
//  Created by Yu on 07/04/16.
//  Copyright © 2016 Yu. All rights reserved.
//


#include "Header.h"

int main(int argc, const char * argv[]) {
    int AgeChicken=2;
    Animal *pAni= new chicken;
    pAni->SetAge(AgeChicken);
    cout<<"The chicken is "<<pAni->GetAge()<<" years old.\n";
    cout<<"There are "<<pAni->howmanyani()<<" animals.\n";
   // cout<<"There are "<<pAni->howmanyani()<<"chickens.\n";
    Animal *pAni2= new Pig;
    cout<<"The pig is "<<pAni2->GetAge()<<" years old.\n";
    cout<<"There are "<<pAni2->howmanyani()<<" animals.\n";
    delete pAni;
    cout<<"There are "<<pAni2->howmanyani()<<" animals.\n";
    delete pAni2;

    return 0;
    
}

