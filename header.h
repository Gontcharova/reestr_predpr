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
 public:
    QString Name;
    QList<QString> Owners;
    double Income;
    double S;
    int Num_Emp;

    QString Get_Name ();
    QList<QString> Get_Owners();
    double Get_Income();
    double Get_S();
    int Get_Num_Emp();

    void Set_Name(QString NewName);
    void Set_Owner(QString NewOwners);
    void Set_Income(double NewIncome);
    void Set_S(double NewS);
    void Set_Num(int NewNum);

    virtual QString Get_Type()=0;
    virtual double Get_Tax()=0;
};


class ReestrP //  класс реестр предприятий
{
public:
    QList<QString> Company_List;
    void Delete_P (QString Company);// 7
    void Create_P (QString Company);// 7
    int Get_P (QString Company); // ?
    int Size_Reester ();

};
