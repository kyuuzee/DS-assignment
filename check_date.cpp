// C++ program to find Current Day, Date
// and Local Time
#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;

bool isLeap(int year)
{
// Return true if year
// is a multiple pf 4 and
// not multiple of 100.
// OR year is multiple of 400.
return (((year % 4 == 0) &&
         (year % 100 != 0)) ||
         (year % 400 == 0));
}

// Returns true if given
// year is valid or not.
bool isValidDate(int d, int m, int y)
{
    // If year, month and day
    // are not in given range
    if (y > MAX_VALID_YR ||
        y < MIN_VALID_YR)
    return false;
    if (m < 1 || m > 12)
    return false;
    if (d < 1 || d > 31)
    return false;

    // Handle February month
    // with leap year
    if (m == 2)
    {
        if (isLeap(y))
        return (d <= 29);
        else
        return (d <= 28);
    }

    // Months of April, June,
    // Sept and Nov must have
    // number of days less than
    // or equal to 30.
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);

    return true;
}


void check_date()
{

char datecont;
	//ofstream outFile;

    filebuf buffer;
    ostream output(&buffer);
    istream input(&buffer);


    const int MAXLEN = 80;
    char s[MAXLEN];
    time_t t = time(0);
    strftime(s, MAXLEN, "%d/%m/%Y", localtime(&t));
    cout << "\n\n\tCurrent date : "<<s << '\n';

cout << "\n\n\tDo you want to change the date..?(y/n) : ";
cin >> datecont;


while(datecont != 'y' && datecont != 'n' && datecont != 'Y' && datecont != 'N')
{
    cout << "\n\n\tInvalid input ! please enter only (y/n) ";
    cout << "\n\n\tDo you want to change the date..?(y/n) : ";
cin >> datecont;
}

if(datecont == 'y' || datecont == 'Y')
    {

    char ans;
    string dd, mm, yy;
int x,y,z;

    do {
             try{
        cout<<"\n\tEnter Date: \t";
        cin>> dd;

        cout<<"\n\tEnter Month: \t";
        cin>> mm;

        cout<<"\n\tEnter Year: \t";
        cin>> yy;

         x = stoi(dd);
         if (x>0 && x<10){
            dd = "0" +dd;
        }
         y = stoi(mm);
         if (y>0 && y<10){
            mm = "0" +mm;
        }
         z = stoi(yy);

        if (isValidDate(x, y, z))
       {

            cout<<"\n\n\tThe date "<<x<<'/'<<y<<'/'<<z<<" is valid"<<endl;

//write into file
  buffer.open ("current_date.dat", ios::in | ios::out | ios::trunc);
 output <<dd<<'/'<<mm<<'/'<<yy<< endl;

        // Just to make sure it is written into file
        //input.seekg(0);          // seek to the beginning
        //char c;
        //cout <<"\noutput frm file"<< endl;
        //while (input.get(c)) {
         //   cout.put(c);
        //}
        //cout << endl;
     //end


            //cout << "\n\n\tDate record Has Been Created\n\n ";

            buffer.close();
            cin.ignore();
       } else
            cout<<"\n\n\tThe date "<<x<<'/'<<y<<'/'<<z<<" is invalid"<<endl;
             }
              catch(const invalid_argument& ia){
            cout<< "\n\tPlease enter an integer value.\n";
        }

    } while (!(isValidDate(x, y, z)));



      }
else if(datecont == 'n' || datecont == 'N')
{
   buffer.open ("current_date.dat", ios::in | ios::out | ios::trunc);
    output <<s<< endl;

        // Just to make sure it is written into file
        //input.seekg(0);          // seek to the beginning
        //char c;
        //cout <<"\n\noutput frm file"<< endl;
        //while (input.get(c)) {
            //cout.put(c);
        //}
        //cout << endl;
      // end



            //cout << "\n\n\tDate record Has Been Created\n\n ";

            buffer.close();
            cin.ignore();

}









}

