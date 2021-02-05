#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<vector>
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
    friend void add_item();
};

void add_item(){
    int x;
    int y;
    int z;
    Inventory a;
    cout << "Please enter the following information for the item: \n";
    cout << "ID: \n";
    getline (cin, a.id);
    cout << "Brand: \n";
    getline (cin, a.brand);
    cout << "Quantity: \n";
    cin >> a.quantity;
    while(!cin){
        cout << "Please enter an integer: ";
        cin.clear();
        cin.ignore();
        cin >> a.quantity;
    }
    cout << "Expiration date: \n";
    do{
        try{
        cout << "Year: ";
        cin >> a.year;
        x = stoi(a.year);
        cout << "Month: ";
        cin >> a.month;
        y = stoi(a.month);
        if (y>0 && y<10){
            a.month = "0" +a.month;
        }
        cout << "Day: ";
        cin >> a.day;
        z = stoi(a.day);
        if (z>0 && z<10){
            a.day = "0" +a.day;
        }
        }
        catch(const invalid_argument& ia){
            cout<< "Please enter an integer value.\n";
        }
    }while(!(isValidDate(z, y, x)));
    cout << "Inventory type: \n";
    cout << "1.Fridge \n";
    cout << "2.Pantry \n";
    cout << "3.Freezer \n";
    cin >> a.choice;
    while((a.choice != '1') && (a.choice != '2') && (a.choice != '3')){
        cout << "Please enter 1,2 or 3: ";
        cin >> a.choice;
    }
    if(a.choice == '1'){
        a.inventory_type = "Fridge";
    }
    else if (a.choice == '2'){
        a.inventory_type = "Pantry";
    }
    else if (a.choice == '3'){
        a.inventory_type = "Freezer";
    }
    system("cls");

    //storing values in a file
    fstream itemfile ("item.txt",ios::app);
    //left and setw to ensure the value stored in text file looks nice
    itemfile <<left <<setw(10)<<a.id <<left<<setw(25)<<a.brand<<left<<setw(10)<<a.quantity
            <<left <<setw(2)<<a.day<<left <<setw(1)<<"/"<<left<<setw(2)<<a.month<<left <<setw(1)<<"/"<<left<<setw(14)<<a.year
            <<left<<setw(10)<<a.inventory_type<<"\n";
    cout << "Record is successfully added\n";
    system("pause");
    itemfile.close();
}

int main(){
     add_item();
}
