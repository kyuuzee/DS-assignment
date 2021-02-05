#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<vector>
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
    friend void search_id();
};

void search_id(){
    string keyword;
    string temp;
    bool notfound = 0;
    cout << "Enter the ID of the food: \n";
    getline(cin, keyword);
    fstream itemfile ("item.txt");
    itemfile.seekg(0);
    //will display the columns on the top of the output panel so the display will look like a table
    cout<<left <<setw(10)<<"ID" <<left <<setw(25)<< "Brand"<<left <<setw(10)<<"Quantity"<<left <<setw(20)<< "Expiration Date"
            <<left <<"Inventory Type\n";
    //transfer everything in the text file into the string temp. find function will find the name user input
    while(getline(itemfile, temp)){
            size_t found = temp.find(keyword);
            if (found != string::npos && found <10){  //it will only look at the first 10 characters to ensure it will only check the id section
            cout <<temp << "\n"; //result that is obtained is printed out
            notfound = 1;
        }
   }
   if (!notfound){
    system("cls");
    cout << "There is no item with this id. \n";
   }
   system("pause");
   itemfile.close();
}

int main(){
    search_id();
}
