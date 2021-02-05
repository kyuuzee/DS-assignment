#include "Inventory.h"
#include "check_date.cpp"

void Inventory::add_item(){
    int x;
    int y;
    int z;
    Inventory a;
    cin.get();
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

int Inventory::getLength() const{
   return size;
}

Inventory::ListNode *Inventory::find(int index) const{
   if ( (index < 1) || (index > getLength()) )
      return NULL;

   else  // count from the beginning of the list.
   {
      ListNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }  // end if
}


void Inventory::edit_item(){
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
    cin.get();
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

void Inventory::search_brand(){
    string keyword;
    string temp;
    bool notfound = 0;
    cin.get();
    cout << "Enter the brand of the food: \n";
    getline(cin, keyword);
    fstream itemfile ("item.txt");
    itemfile.seekg(0);
    //will display the columns on the top of the output panel so the display will look like a table
    cout<<left <<setw(10)<<"ID" <<left <<setw(25)<< "Brand"<<left <<setw(10)<<"Quantity"<<left <<setw(20)<< "Expiration Date"
            <<left <<"Inventory Type\n";
    //transfer everything in the text file into the string temp. find function will find the name user input
    while(getline(itemfile, temp)){
            size_t found = temp.find(keyword);
            if (found != string::npos && found >9 &&found<35){  //it will only look at the first 10 characters to ensure it will only check the id section
            cout <<temp << "\n"; //result that is obtained is printed out
            notfound = 1;
        }
   }
   if (!notfound){
    system("cls");
    cout << "There is no item with this brand. \n";
   }
   system("pause");
   itemfile.close();
}

void Inventory::search_id(){
    string keyword;
    string temp;
    bool notfound = 0;
    cin.get();
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

void Inventory::search_type(){
    string keyword;
    string temp;
    char option;
    bool notfound = 0;
    cin.get();
    cout << "Choose inventory where the food is stored: \n";
    cout << "1.Fridge \n";
    cout << "2.Pantry \n";
    cout << "3.Freezer \n";
    cin >> option;
    while((option != '1') && (option != '2') && (option != '3')){
        cout << "Please enter 1,2 or 3: ";
        cin >> option;
    }
    if(option == '1'){
        keyword = "Fridge";
    }
    else if (option == '2'){
        keyword = "Pantry";
    }
    else if (option == '3'){
        keyword = "Freezer";
    }
    fstream itemfile ("item.txt");
    itemfile.seekg(0);
    //will display the columns on the top of the output panel so the display will look like a table
    cout<<left <<setw(10)<<"ID" <<left <<setw(25)<< "Brand"<<left <<setw(10)<<"Quantity"<<left <<setw(20)<< "Expiration Date"
            <<left <<"Inventory Type\n";
    //transfer everything in the text file into the string temp. find function will find the name user input
    while(getline(itemfile, temp)){
            size_t found = temp.find(keyword);
            if (found != string::npos && found >64){  //it will only look at the first 10 characters to ensure it will only check the id section
            cout <<temp << "\n"; //result that is obtained is printed out
            notfound = 1;
        }
   }
   if (!notfound){
    system("cls");
    cout << "There is no such inventory in this shop. \n";
   }
   system("pause");
   itemfile.close();
}

void Inventory::delete_item(){
    string keyword;
    string temp;
    string del;
    char decision;
    bool notfound = 0;
    cin.get();
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

void Inventory::warning_inventory(){
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
            x = stoi(quantity);
            if (x<50){
            low++;
            nolow = 1;
            }
   }
   if (nolow){
    cout<< "WARNING: There are " << low <<" items below 50 in quantity. \n";
   }
   else if (!nolow){
    system("cls");
    cout << "No items are below 50 in quantity. \n";
   }
   system("pause");
   itemfile.close();
}

void Inventory::warning_date(){
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
    cout<< "WARNING: There are " << already_expire <<" items that have already expired and "<<expire_soon<<" items are expiring this month. \n";
   }
   else if (!noexpire){
    system("cls");
    cout << "No items are within 1 month of expiring. \n";
   }
   system("pause");
   itemfile.close();
}

void Inventory::load() throw( ListException ){
   ifstream itemfile("item.txt");
   ListNode *tail;
   string temp;

   size = 0;
       if (getline(itemfile, temp)) // Is file empty?
       {  // File not empty:
          try
          {
             head = new ListNode;
             // Add the first integer to the list.
             head->item = temp;
             head->next = NULL;
             tail = head;
             size = size + 1;

             // Add remaining integers to linked list.
             while (getline(itemfile, temp))
             {
                tail->next = new ListNode;
                tail = tail->next;
                tail->item = temp;
                tail->next = NULL;
                size = size + 1;
             }  // end while
          }  // end try
          catch (bad_alloc e)
          {
              throw ListException(
             "ListException: restore cannot allocate memory.");
          }  // end catch
       }  // end if
   itemfile.close();
}

void Inventory::retrieve(int index,
                    ListItemType& dataItem) const
   throw(ListIndexOutOfRangeException){
   if ( (index < 1) || (index > getLength()) )
      throw ListIndexOutOfRangeException(
	    "ListIndexOutOfRangeException: retrieve index out of range");
   else
   {  // get pointer to node, then data in node
      ListNode *cur = find(index);
      dataItem = cur->item;
   }  // end if
}

void Inventory::sort_id(stack<string> &s){
    string tmp, min, min_substr, tmp_substr;
    stack<string> t1, t2;
    //see if there is only one element in the whole stack
    string line;
    ifstream file("item.txt");

    while (getline(file, line)) {
        if(line.size() > 0){
            s.push(line);
        }
    }
    tmp = s.top();
    s.pop();
    if(s.empty()){
        s.push(tmp);
        return;
    }

    //push tmp so we get the original stack back
    s.push(tmp);
    for(int i=0;i<s.size();i++){
    //copying s to t stack
    while(!s.empty()){
        tmp = s.top();
        s.pop();
        t1.push(tmp);
    }

    //min is the first t.top and then after t is popped tmp becomes the
    //current t.top. Then compare min_substr and tmp_substr. If tmp_substr<min_substr, then min = tmp
    //and t1 will have another copy of tmp.
    while(!t1.empty()){
        min = t1.top();
        min_substr = min.substr(0,10);

        t1.pop();
        t2.push(min);


        while(!t1.empty()){
            tmp  = t1.top();
            tmp_substr = tmp.substr(0,10);
            t1.pop();

            if(tmp_substr < min_substr){
                min = tmp;
            }

            t2.push(tmp); // reserve a copy
        }

        //basically what happened is they'd find the lowest value in t1 stack,
        //set as min and put them in the original stack. Then the same code run again but
        //with size-1 and find the lowest value in the unsorted stack. And then the min val
        //will be pushed into the original stack again.
        while(!t2.empty()){

            tmp = t2.top();
            t2.pop();

            if(min == tmp){
                s.push(tmp);
            }
            else{
                t1.push(tmp);
            }
        }
    }
    }
    file.close();
}

void Inventory::sort_brand(stack<string> &s){
    string tmp, min, min_substr, tmp_substr;
    stack<string> t1, t2;

    //see if there is only one element in the whole stack
    string line;
    ifstream file("item.txt");

    while (getline(file, line)) {
        if(line.size() > 0){
            s.push(line);
        }
    }
    tmp = s.top();
    s.pop();
    if(s.empty()){
        s.push(tmp);
        return;
    }

    //push back so we get the original stack back
    s.push(tmp);

    //copying s to t stack
    for(int i=0;i<s.size();i++){
    while(!s.empty()){
        tmp = s.top();
        s.pop();
        t1.push(tmp);
    }

    //min is the first t.top and then after t is popped tmp becomes the
    //current t.top. Then compare min and tmp. If tmp<min, then min = tmp
    //and t1 will have another copy of tmp.

    while(!t1.empty()){
        min = t1.top();
        min_substr = min.substr(10,25);
        t1.pop();
        t2.push(min);


        while(!t1.empty()){
            tmp  = t1.top();
            tmp_substr = tmp.substr(10,25);
            t1.pop();

            if(tmp_substr < min_substr){
                min = tmp;
            }

            t2.push(tmp); // reserve a copy
        }

        //basically what happened is in a they'd find the lowest value in a stack,
        //set as min and put them in the original stack. Then the same code run again but
        //with size-1 and find the lowest value in the unsorted stack. And then the min val
        //will be pushed into the original stack again.
        while(!t2.empty()){

            tmp = t2.top();
            t2.pop();

            if(min == tmp){
                s.push(tmp);
            }
            else{
                t1.push(tmp);
            }
        }
    }
    }
    file.close();
}

void Inventory::sort_qty(stack<string> &s){
    string tmp, min;
    int min_substr, tmp_substr; //change to int bcs need to compare qty
    stack<string> t1, t2;
    string line;
    ifstream file("item.txt");

    while (getline(file, line)) {
        if(line.size() > 0){
            s.push(line);
        }
    }

    //see if there is only one element in the whole stack
    tmp = s.top();
    s.pop();
    if(s.empty()){
        s.push(tmp);
        return;
    }

    //push so we get the original stack back
    s.push(tmp);

    //copying s to t stack
    for(int i=0;i<s.size();i++){
    while(!s.empty()){
        tmp = s.top();
        s.pop();
        t1.push(tmp);
    }

    //min is the first t.top and then after t is popped tmp becomes the
    //current t.top. Then compare min and tmp. If tmp<min, then min = tmp
    //and t1 will have another copy of tmp.

    while(!t1.empty()){
        min = t1.top();
        min_substr = stoi(min.substr(35,10)); //has stoi bcs need to change to int for comparison
        t1.pop();
        t2.push(min);


        while(!t1.empty()){
            tmp  = t1.top();
            tmp_substr = stoi(tmp.substr(35,10)); //has stoi bcs need to change to int for comparison
            t1.pop();

            if(tmp_substr < min_substr){
                min = tmp;
            }

            t2.push(tmp); // reserve a copy
        }

        //basically what happened is in a they'd find the lowest value in a stack,
        //set as min and put them in the original stack. Then the same code run again but
        //with size-1 and find the lowest value in the unsorted stack. And then the min val
        //will be pushed into the original stack again.
        while(!t2.empty()){

            tmp = t2.top();
            t2.pop();

            if(min == tmp){
                s.push(tmp);
            }
            else{
                t1.push(tmp);
            }
        }
    }
    }
    file.close();
}

void Inventory::sort_type(stack<string> &s){
    string tmp, min, min_substr, tmp_substr;
    stack<string> t1, t2;
    string line;
    ifstream file("item.txt");

    while (getline(file, line)) {
        if(line.size() > 0){
            s.push(line);
        }
    }

    //see if there is only one element in the whole stack
    tmp = s.top();
    s.pop();
    if(s.empty()){ // do not need sort if one element
        s.push(tmp);
        return;
    }

    //push back so we get the original stack back
    s.push(tmp);

    //copying s to t stack
    for(int i=0;i<s.size();i++){
    while(!s.empty()){
        tmp = s.top();
        s.pop();
        t1.push(tmp);
    }

    //min is the first t.top and then after t is popped tmp becomes the
    //current t.top. Then compare min and tmp. If tmp<min, then min = tmp
    //and t1 will have another copy of tmp.

    while(!t1.empty()){
        min = t1.top();
        min_substr = min.substr(65,10);
        t1.pop();
        t2.push(min);


        while(!t1.empty()){
            tmp  = t1.top();
            tmp_substr = tmp.substr(65,10);
            t1.pop();

            if(tmp_substr < min_substr){
                min = tmp;
            }

            t2.push(tmp); // reserve a copy
        }

        //basically what happened is in a they'd find the lowest value in a stack,
        //set as min and put them in the original stack. Then the same code run again but
        //with size-1 and find the lowest value in the unsorted stack. And then the min val
        //will be pushed into the original stack again.
        while(!t2.empty()){

            tmp = t2.top();
            t2.pop();

            if(min == tmp){
                s.push(tmp);
            }
            else{
                t1.push(tmp);
            }
        }
    }
    }
    file.close();
}

void Inventory::sort_date() {

    vector<string> s;
    string line;
    ifstream file("item.txt");


    //place text file into vector
    while (getline(file, line)) {
        if(line.size() > 0){
            s.push_back(line);
        }
    }

    //change the date format from 01/12/2000 to 20001201 and append them into the string
    for (int i=0; i<s.size(); i++){
        s[i].append(s[i].substr(51,4) + s[i].substr(48,2) + s[i].substr(45,2));
    }

    //sort the date with new format
    for (int i=0; i<s.size();i++) {
        for(int j=0; j<(s.size()-1); j++) {
            if (s[j].substr(75,10) > s[j+1].substr(75,10)) {
                string temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    //print only the line before the date with new format
    for (int i=0; i<s.size(); i++){
        cout << s[i].substr(0,74) + "\n";
    }
    file.close();


}

//Because stack is LIFO the first item is at the bottom when we're printing.
//To view it normally, we need to reverse the stack
void Inventory::reverse_stack(stack<string> &s){
    string v, min;
    stack<string> t;

    while(!s.empty()){
        v = s.top();
        s.pop();

        t.push(v);
    }
    s = t;
}

void Inventory::print_stack(stack<string> &s) {
    while(!s.empty()){
        string v;
        v = s.top();
        s.pop();
        cout << v << endl;
    }
}
