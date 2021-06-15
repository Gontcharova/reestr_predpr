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
    Company(){ Name="0"; Owners = {"0"}; Income=S=Num_Emp=0.0; };
    Company(QString N, QList<QString> O, double I, double SS, int Num)
    {
       Name=N;
       Owners=O;
       Income=I;
       S=SS;
       Num_Emp=Num;
    };

    virtual ~Company(){ };

    enum Type {A=1,B,C};

    QString Get_Name () {return Name;}
    QList<QString> Get_Owners() {return Owners;}
    double Get_Income() {return Income;}
    double Get_S() {return S;}
    int Get_Num_Emp(){return Num_Emp;}

    void Set_Name(QString NewName) { Name = NewName;} //(const QString &name)
    void Set_Owner(QList<QString>& NewOwners) {Owners = NewOwners;} // const?
    void Set_Income(double NewIncome) {Income=NewIncome;}
    void Set_S(double NewS){S=NewS;}
    void Set_Num(int NewNum){Num_Emp=NewNum;}

    virtual Type Get_Type()=0;
    virtual double Get_Tax()=0;
};


class ReestrP //  класс реестр предприятий
{
private:
    QList<Company*> Company_List;
    ReestrP();

public:

   ~ReestrP();
    void Delete_P (int i);
    void Add_P (Company* Comp);
    Company* Get_P (int i);
    int Size_Reester ();

};

class Company_A: public Company
{
public:
    Company_A();
    Company_A(QString N, QList<QString> O, double I, double SS, int Num);
    Type Get_Type() override;
    double Get_Tax() override {return ((Income+S+Num_Emp)*15/100); }
};


class Company_B: public Company
{
public:
    Company_B();
    Company_B(QString N, QList<QString> O, double I, double SS, int Num);
    Type Get_Type() override;
    double Get_Tax() override {return ((Income+S)*20/100); }
};


class Company_C: public Company
{
public:
    Company_C();
    Company_C(QString N, QList<QString> O, double I, double SS, int Num);
    Type Get_Type() override;
    double Get_Tax() override {return ((Income+Num_Emp)*30/100); }
};
