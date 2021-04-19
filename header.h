#ifndef HEADER_H
#define HEADER_H

#endif // HEADER_H
#include <QList>
#include <QString>
#include <stdio.h>
#include <iostream>

using namespace std;

class Company
{
 protected:
    QString Name;
    QList<QString> Owners;
    double Income;
    double S;
    int Num_Emp;

 public:
    Company(){ Name="0"; Owners = {"0"}; Income=S=Num_Emp=0; };
    Company(QString N, QList<QString> O, double I, double SS, int Num)
    {
       Name=N;
       Owners=O;
       Income=I;
       S=SS;
       Num_Emp=Num;
    };

    enum Type {A=1,B,C};

    QString Get_Name () {return Name;}
    QList<QString> Get_Owners() {return Owners;}
    double Get_Income() {return Income;}
    double Get_S() {return S;}
    int Get_Num_Emp(){return Num_Emp;}

    void Set_Name(QString NewName) { Name = NewName;}
    void Set_Owner(QList<QString> NewOwners) {Owners = NewOwners;}
    void Set_Income(double NewIncome) {Income=NewIncome;}
    void Set_S(double NewS){S=NewS;}
    void Set_Num(int NewNum){Num_Emp=NewNum;}

    virtual Type Get_Type()=0;
    virtual double Get_Tax()=0;
};


class ReestrP //  класс реестр предприятий
{
public:
    QList<Company*> Company_List;
    void Delete_P (Company Comp);// 7
    void Add_P (Company Comp);// 7
    Company Get_P (int i); // ?
    int Size_Reester ();

};

class Company_A: public Company
{
public:
    Type Get_Type() {return A;}
    double Get_Tax() {return ((Income+S+Num_Emp)*15/100); }
};


class Company_B: public Company
{
public:
    Type Get_Type() {return B;}
    double Get_Tax() {return ((Income+S)*20/100); }
};


class Company_C: public Company
{
public:
    Type Get_Type() {return C;}
    double Get_Tax() {return ((Income+Num_Emp)*30/100); }
};
