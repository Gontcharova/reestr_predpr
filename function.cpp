
#define HEADER_H

#include "header.h"


// класс реестра

ReestrP::ReestrP(){};

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

// класс Company_A

Company:: Type Company_A:: Get_Type()
{
    return Type::A;
}

// класс Company_B

Company:: Type Company_B:: Get_Type()
{
    return Type::B;
}

// класс Company_A

Company:: Type Company_C:: Get_Type()
{
    return Type::C;
}
