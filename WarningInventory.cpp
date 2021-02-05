#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<string>

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
    friend void warning_inventory();
};

void warning_inventory(){
    string temp;
    string quantity;
    int x;
    int low = 0;
    bool nolow = 0;
    fstream itemfile ("item.txt");
    itemfile.seekg(0);
    //transfer everything in the text file into the string temp.
    while(getline(itemfile, temp)){
            quantity = temp.substr(35,10);
            cout<<quantity;
            x = stoi(quantity);
            if (x<50){
            low++;
            nolow = 1;
            }
   }
   if (nolow){
    cout<< "There are " << low <<" items below 50 in quantity. \n";
   }
   else if (!nolow){
    system("cls");
    cout << "No items are below 50 in quantity. \n";
   }
   system("pause");
   itemfile.close();
}

int main(){
    warning_inventory();
}
