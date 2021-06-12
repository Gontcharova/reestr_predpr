
#define HEADER_H

#include "header.h"

// класс реестра

ReestrP::ReestrP(){};

void ReestrP::Delete_P(Company Comp)
{

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
