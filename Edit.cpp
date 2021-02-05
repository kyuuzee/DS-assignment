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
    friend void edit_item();
};

void edit_item(){
    string keyword;
    string temp;
    string Year;
    string Month;
    string Day;
    string edit;
    int choice;
    int w;
    int x;
    int y;
    int z;
    char ans;
    char option;
    bool notfound = 0;
    bool modify = 0;
    cout << "Enter the ID of the item you want to edit: \n";
    getline(cin, keyword);
    system("cls");
    fstream itemfile ("item.txt");
    ofstream tmpfile ("tmp.txt");
    itemfile.seekg(0);
    tmpfile.seekp(0);
    cout<<left <<setw(10)<<"ID" <<left <<setw(25)<< "Brand"<<left <<setw(10)<<"Quantity"<<left <<setw(20)<< "Expiration Date"
        <<left <<"Inventory Type\n";

    while(getline(itemfile, temp)){
            size_t found = temp.find(keyword);
            if (found != string::npos && found <10){
                cout <<temp << "\n";
            notfound = 1;
            cout<<endl;
            cout << "Select the field you want to edit: \n"
                 << "1. ID\n"
                 << "2. Brand\n"
                 << "3. Quantity\n"
                 << "4. Expiration Date\n"
                 << "5. Inventory Type\n"
                 << "Choice:" ;
            cin >> choice;
            cout << endl;
            cin.get();
                switch (choice)
                {
                case 1:
                    cout << "Enter the new ID of the item: \n";
                    getline(cin, edit);
                    edit.resize(10); //resize the edit size to ensure consistency
                    temp.replace(0,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n"; //the edited line is stored into the tmpfile
                    modify =1;
                    break;
                case 2:
                    cout << "Enter the new brand of the item: \n";
                    getline(cin, edit);
                    edit.resize(25);
                    temp.replace(10,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 3:
                    cout << "Enter the new quantity of the item: \n";
                    cin >> w;
                    while(!cin){
                        cout << "Please enter an integer: ";
                        cin.clear();
                        cin.ignore();
                        cin >> w;
                    }
                    edit = to_string(w);
                    edit.resize(10);
                    temp.replace(35,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 4:
                    cout << "Enter the new expiration date of the item: \n";
                    do{
                        try{
                        cout << "Year: ";
                        cin >> Year;
                        x = stoi(Year);
                        cout << "Month: ";
                        cin >> Month;
                        y = stoi(Month);
                        if (y>0 && y<10){
                            Month = "0" +Month;
                        }
                        cout << "Day: ";
                        cin >> Day;
                        z = stoi(Day);
                        if (z>0 && z<10){
                            Day = "0" +Day;
                        }
                        }
                        catch(const invalid_argument& ia){
                            cout<< "Please enter an integer value.\n";
                        }
                    }while(!(isValidDate(z, y, x)));
                    edit = Day+"/"+Month+"/"+Year;
                    edit.resize(20);
                    temp.replace(45,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 5:
                    cout << "Select the new inventory type of the item: \n";
                    cout << "Inventory type: \n";
                    cout << "1.Fridge \n";
                    cout << "2.Pantry \n";
                    cout << "3.Freezer \n";
                    cin >> option;
                    while((option != '1') && (option != '2') && (option != '3')){
                    cout << "Please enter 1,2 or 3: ";
                    cin >> option;
                    }
                    if(option == '1'){
                    edit = "Fridge";
                    }
                    else if (option == '2'){
                    edit = "Pantry";
                    }
                    else if (option == '3'){
                    edit = "Freezer";
                    }
                    edit.resize(10);
                    temp.replace(65,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                default:
                    cout << "Invalid option.";
                }
            system("pause");
        }
   }
   if (!notfound){
    system("cls");
    cout << "There is no item with this id. \n";
    system("pause");
   }
   itemfile.close();
   tmpfile.close();
   if (modify){
        fstream itemfile ("item.txt");
        ofstream tmpfile ("tmp.txt",ios::app);
        itemfile.seekg(0);
        tmpfile.seekp(0);

        while (getline(itemfile, temp)){
            if (temp.substr(0,keyword.size()) != keyword) //anything that doesn't have the keyword will be transfer to the tmp file
                tmpfile<<temp<<"\n";
        }
        itemfile.close();
        tmpfile.close();
        remove("item.txt");
        rename("tmp.txt", "item.txt");
   }
}

int main(){
    edit_item();
}
