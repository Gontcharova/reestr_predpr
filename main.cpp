
#define HEADER_H
#include <QTextStream>
#include <QCoreApplication>
#include "header.h"

QTextStream cout(stdout);
QTextStream cin(stdin);

ReestrP& reestr=ReestrP::getInst();

void ByType(Company::Type T)
{
    QTextStream cout(stdout);
    if(T>0 && T<=3)

        for(int i=0; i<reestr.Size_Reester();i++)
        {
            Company* P=reestr.Get_P(i);
            if(P->Get_Type()==T)
               cout<<P->Get_Name()<<Qt::endl;
        }
    else cout<<"incorrect type"<<Qt::endl;
    cout<<Qt::endl;
}

void ByOwners(QString O)
{
    QTextStream cout(stdout);
    int count=0;
    for(int i=0;i<reestr.Size_Reester();i++)
    {
        Company* P=reestr.Get_P(i);
        if(P->Get_Owners().contains(O))
        {
             cout<<P->Get_Name()<<Qt::endl;
             count++;
        }

    }
    if (count==0) cout<<"no"<<Qt::endl;
    cout<<Qt::endl;
}

void Avg()
{
    QTextStream cout(stdout);

    for(int t=1; t<=3; t++)
    {
        double AVG_Income=0;
        double AVG_S=0;
        int AVG_Num_Emp=0;
        int count=0;
        cout<< "Type "<< t <<": "<< Qt::endl;

        for(int i=0; i<reestr.Size_Reester();i++)
        {
            Company* P=reestr.Get_P(i);
            if( P->Get_Type() == t )
            {
                AVG_Income+=P->Get_Income();
                AVG_S+=P->Get_S();
                AVG_Num_Emp+=P->Get_Num_Emp();
                count++;
            }

        }
        if (count)
        {
            cout<<"AVG_Income: "<<AVG_Income/count<<Qt::endl;
            cout<<"AVG_S: "<<AVG_S/count<<Qt::endl;
            cout<<"AVG_Num_Emp: "<<AVG_Num_Emp/count<<Qt::endl<<Qt::endl;
        }
        else cout<<"Empty"<<Qt::endl;
      }
}


int main(int argc, char *argv[])
{
     QTextStream out(stdout);
     QTextStream cin(stdin);

    // заполнение базы

    Company_A* A1= new Company_A("Kotopes", QList<QString>{"Kot", "Pes"}, 100, 30, 10);
    Company_A* A2= new Company_A("Ferma", QList<QString>{"Vanay", "Lecha"}, 500, 50, 40);

    reestr.Add_P(A1);
    reestr.Add_P(A2);

    Company_B* B1= new Company_B("GYM", QList<QString>{"Macha"}, 400, 20, 8);
    Company_B* B2= new Company_B("Store", QList<QString>{"Lee", "Ken", "Mark"}, 700, 200, 150);
    Company_B* B3= new Company_B("TopShop", QList<QString>{"Vasya"}, 150, 55, 4);

    reestr.Add_P(B1);
    reestr.Add_P(B2);
    reestr.Add_P(B3);

    Company_C* C1= new Company_C("Dog Party", QList<QString>{"Lee", "Kody"}, 70, 40, 2);
    Company_C* C2= new Company_C("Kat Party", QList<QString>{"May"}, 300, 70, 15);

    reestr.Add_P(C1);
    reestr.Add_P(C2);

    //1. Вывести в консоль информацию о предприятиях определённого типа

    /*int T;
    out << "Enter company's type: ";
    cin >> T;*/
    ByType(Company::Type(1));

    //2. Вывести в консоль все предприятия, принадлежащие определённому владельцу.

    ByOwners("Lee");

    //3. Вывести в консоль средние показатели (доход, площадь, число сотрудников) предприятий для каждого из типов.

    Avg();

}
