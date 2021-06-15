
#define HEADER_H

#include "header.h"
#include <QString>

// класс реестра

ReestrP::ReestrP()
{

}

ReestrP::~ReestrP()
{
    while(!Company_List.empty())
        {
            delete Company_List.takeFirst();
        }
}

void ReestrP::Delete_P(int i)
{
    if(i >= 0 && i < Company_List.size())
        Company_List.removeAt(i);
}

void ReestrP::Add_P(Company* Comp)
{
    Company_List.push_back(Comp);
}

Company* ReestrP::Get_P (int i)
{
    if(i >= 0 && i < Company_List.size())
            return Company_List[i];
    else return nullptr;
}

int ReestrP::Size_Reester ()
{
    return Company_List.size();
}

ReestrP &ReestrP::getInst()
{
    static ReestrP Object;
    return Object;
}

// класс Company_A

Company_A:: Company_A() :Company()
{

}

Company_A:: Company_A(QString N, QList<QString> O, double I, double SS, int Num) :Company (N, O, I, SS, Num)
{

}

Company:: Type Company_A:: Get_Type()
{
    return Type::A;
}

// класс Company_B

Company_B:: Company_B() :Company()
{

}
Company_B:: Company_B(QString N, QList<QString> O, double I, double SS, int Num) :Company (N, O, I, SS, Num)
{

}

Company:: Type Company_B:: Get_Type()
{
    return Type::B;
}

// класс Company_A

Company_C:: Company_C() :Company()
{

}

Company_C:: Company_C(QString N, QList<QString> O, double I, double SS, int Num) :Company (N, O, I, SS, Num)
{

}
Company:: Type Company_C:: Get_Type()
{
    return Type::C;
}
