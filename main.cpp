#include "Inventory.cpp"

int main(){
    char choice;
    stack<string> s;
    string line;
    ListItemType ch, content;
    Inventory alist;
    check_date();
    system("cls");
    alist.warning_date();
    system("cls");
    alist.warning_inventory();
    system("cls");
    do {
        cout<<"Welcome to MMU Inventory" <<endl
        <<"Please choose which actions you wish to perform." <<endl
        <<"1. Add" <<endl
        <<"2. Edit" <<endl
        <<"3. Search" <<endl
        <<"4. List" <<endl
        <<"5. Delete" <<endl
        <<"6. Exit" << endl
        <<"Choice:";
        cin>> choice; //ask for user's input
        system("cls");
        switch(choice) {
            case '1' :
                alist.add_item();
                system("cls");
                break;
            case '2':
                alist.edit_item();
                system("cls");
                break;
            case '3':
                cout<<"How will you like to search for an item." <<endl
                <<"a. ID" <<endl
                <<"b. Brand" <<endl
                <<"c. Storage Location" <<endl
                <<"Choice:";
                cin>> choice; //ask for user's input
                system("cls");
                switch (choice) {
                    case 'a':
                        alist.search_id();
                        break;
                    case 'b':
                        alist.search_brand();
                        break;
                    case 'c':
                        alist.search_type();
                        break;
                    default:
                        cout<< "Invalid input" <<endl;
                        system("pause");
                        system("cls");
                        break;
                }
                system("cls");
                break;
            case '4':
                cout<<"How will you like to list the items." <<endl
                <<"a. Without Sorting" <<endl
                <<"b. Sort by ID" <<endl
                <<"c. Sort by Brand" <<endl
                <<"d. Sort by Quantity" <<endl
                <<"e. Sort by Expiration Date" <<endl
                <<"f. Sort by Storage Type" <<endl
                <<"Choice:";
                cin>> choice; //ask for user's input
                system("cls");
                switch (choice) {
                    case 'a':
                        alist.load();
                        cout<<left <<setw(10)<<"ID" <<left <<setw(25)<< "Brand"<<left <<setw(10)<<"Quantity"<<left <<setw(20)<< "Expiration Date"
                        <<left <<"Inventory Type\n";
                        for(int i = 1; i <= alist.getLength(); ++i){
                            alist.retrieve(i, content);
                            cout << content;
                            cout << endl;
                        }
                        system("pause");
                        break;
                    case 'b':
                        alist.sort_id(s);
                        alist.reverse_stack(s);
                        cout<<left <<setw(10)<<"ID" <<left <<setw(25)<< "Brand"<<left <<setw(10)<<"Quantity"<<left <<setw(20)<< "Expiration Date"
                        <<left <<"Inventory Type\n";
                        alist.print_stack(s);
                        system("pause");
                        break;
                    case 'c':
                        alist.sort_brand(s);
                        alist.reverse_stack(s);
                        cout<<left <<setw(10)<<"ID" <<left <<setw(25)<< "Brand"<<left <<setw(10)<<"Quantity"<<left <<setw(20)<< "Expiration Date"
                        <<left <<"Inventory Type\n";
                        alist.print_stack(s);
                        system("pause");
                        break;
                    case 'd':
                        alist.sort_qty(s);
                        alist.reverse_stack(s);
                        cout<<left <<setw(10)<<"ID" <<left <<setw(25)<< "Brand"<<left <<setw(10)<<"Quantity"<<left <<setw(20)<< "Expiration Date"
                        <<left <<"Inventory Type\n";
                        alist.print_stack(s);
                        system("pause");
                        break;
                    case 'e':
                        alist.sort_date();
                        system("pause");
                        break;
                    case 'f':
                        alist.sort_type(s);
                        alist.reverse_stack(s);
                        cout<<left <<setw(10)<<"ID" <<left <<setw(25)<< "Brand"<<left <<setw(10)<<"Quantity"<<left <<setw(20)<< "Expiration Date"
                        <<left <<"Inventory Type\n";
                        alist.print_stack(s);
                        system("pause");
                        break;
                    default:
                        cout<< "Invalid input" <<endl;
                        system("pause");
                        system("cls");
                        break;
                }
                system("cls");
                break;
            case '5':
                alist.delete_item();
                system("cls");
                break;
            case '6':
                break; //break straight away for exit
            default:
                cout<<"Invalid option. \n";
                system("pause");
                system("cls");
                break;
        }

    } while (choice !='6');

return 0;
}
