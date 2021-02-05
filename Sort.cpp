#include<iostream>
#include<stack>
#include<fstream>
#include<vector>

using namespace std;

//function to sort id by using stack
void sort_id(stack<string> &s)
{
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


//function to sort brand by using stack
void sort_brand(stack<string> &s)
{
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


//function to sort quantity by using stack
void sort_qty(stack<string> &s)
{
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


//function to sort type by using stack
void sort_type(stack<string> &s)
{
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


//function to sort date by using vector
void sort_date() {

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
void reverse_stack(stack<string> &s)
{
    string v, min;
    stack<string> t;

    while(!s.empty()){
        v = s.top();
        s.pop();

        t.push(v);
    }
    s = t;
}

void print_stack(stack<string> &s) {
    while(!s.empty()){
        string v;
        v = s.top();
        s.pop();
        cout << v << endl;
    }
}

int main()
{
    stack<string> s;




    sort_id(s);
    //sort_brand(s);
    //sort_qty(s);
    //sort_type(s);

    reverse_stack(s);
    print_stack(s);

    //sort_date();

    return 0;
}
