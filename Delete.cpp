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
    friend void delete_item();
};

void delete_item(){
    string keyword;
    string temp;
    string del;
    char decision;
    bool notfound = 0;
    cout << "Enter the ID of the item you want to delete: \n";
    getline(cin, keyword);
    system("cls");
    fstream itemfile ("item.txt");
    itemfile.seekg(0);
    cout<<left <<setw(10)<<"ID" <<left <<setw(25)<< "Brand"<<left <<setw(10)<<"Quantity"<<left <<setw(20)<< "Expiration Date"
        <<left <<"Inventory Type\n";
    while(getline(itemfile, temp)){
            size_t found = temp.find(keyword);
            if (found != string::npos && found <10){
            cout <<temp << "\n";
            notfound = 1;
            itemfile.close();
            cout << "Are you sure you want to delete this record?(Y/N)\n";
            cin >> decision;
            if (decision == 'Y' || decision =='y'){
                fstream itemfile ("item.txt");
                ofstream tmpfile ("tmp.txt");
                itemfile.seekg(0);
                tmpfile.seekp(0);
                //if (tmpfile.is_open()){
                //cout << "No problem \n";}
                while (getline(itemfile, del)){
                if (del.substr(0,keyword.size()) != keyword)
                tmpfile<<del<<"\n"; //information that is not the keyword will be stored in the tmpfile temporarily
                }
                itemfile.close();
                tmpfile.close();
                remove("item.txt");
                rename("tmp.txt", "item.txt");
                cout << "Record successfully deleted.\n";
                system("pause");
            }
        }
   }
   if (!notfound){
    cout << "There is no item with this id in this hospital. \n";
    system("pause");
   }
   itemfile.close();
}

int main(){
    delete_item();
}
