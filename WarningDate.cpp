#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include "check_date.cpp"
using namespace std;

class Inventory{
private:
    int quantity;
    char choice;
    string year;
    string day;
    string month;
    string id;
    string brand;
    string inventory_type;
public:
    friend void warning_date();
};

void warning_date(){
    string temp;
    string date;
    string dd;
    string mm;
    string yy;
    string m;
    string y;
    string d;
    int a;
    int b;
    int c;
    int w;
    int x;
    int z;
    int expire_soon = 0;
    int already_expire = 0;
    bool noexpire = 0;
    fstream itemfile ("item.txt");
    fstream datefile ("current_date.dat");
    itemfile.seekg(0);
    datefile.seekg(0);
    getline(datefile,date);
    dd=date.substr(0,2);
    c=stoi(dd);
    mm=date.substr(3,2);
    a=stoi(mm);
    yy=date.substr(6,4);
    b=stoi(yy);
    //transfer everything in the text file into the string temp.
    while(getline(itemfile, temp)){
            d = temp.substr(45,2);
            m = temp.substr(48,2);
            y = temp.substr(51,4);
            w=stoi(d);
            x=stoi(m);
            z=stoi(y);
            if (z<b){
                already_expire++;
                noexpire = 1;
            }
            else if(z==b && x<a){
                already_expire++;
                noexpire = 1;
            }
            else if(w<c && x==a && z==b){
                already_expire++;
                noexpire = 1;
            }
            else if(w>c && x==a && z==b){
                    expire_soon++;
                    noexpire = 1;
            }
   }
   if (noexpire){
    cout<< "There are " << already_expire <<" items that have already expired and "<<expire_soon<<" items are expiring this month. \n";
   }
   else if (!noexpire){
    system("cls");
    cout << "No items are within 1 month of expiring. \n";
   }
   system("pause");
   itemfile.close();
}

int main(){
    check_date();
    warning_date();
}
