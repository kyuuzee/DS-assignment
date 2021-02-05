#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include <cstddef>     // for NULL
#include <new>         // for bad_alloc
#include "ListException.h"
#include "ListIndexOutOfRangeException.h"
typedef string ListItemType;

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
    friend void search_brand();
    bool isEmpty() const;
    int getLength() const;
    void load()
        throw( ListException );
    void retrieve(int index, ListItemType& dataItem) const
	    throw(ListIndexOutOfRangeException);
private:
      /** A node on the list. */
      struct ListNode
      {
         /** A data item on the list. */
         ListItemType item;
         /** Pointer to next node. */
         ListNode    *next;
      }; // end ListNode

      /** Number of items in list. */
      int       size;
      /** Pointer to linked list of items. */
      ListNode *head;

      /** Locates a specified node in a linked list.
       * @pre index is the number of the desired node.
       * @post None.
       * @param index The index of the node to locate.
       * @return A pointer to the index-th node. If index < 1
       *         or index > the number of nodes in the list,
       *         returns NULL. */
      ListNode *find(int index) const;
};
int Inventory::getLength() const
{
   return size;
}

Inventory::ListNode *Inventory::find(int index) const
{
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

void Inventory::load() throw( ListException )
{
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
   throw(ListIndexOutOfRangeException)
{
   if ( (index < 1) || (index > getLength()) )
      throw ListIndexOutOfRangeException(
	    "ListIndexOutOfRangeException: retrieve index out of range");
   else
   {  // get pointer to node, then data in node
      ListNode *cur = find(index);
      dataItem = cur->item;
   }  // end if
}

int main(){
    Inventory alist;
    alist.load();
    ListItemType ch, content;
    cout<<left <<setw(10)<<"ID" <<left <<setw(25)<< "Brand"<<left <<setw(10)<<"Quantity"<<left <<setw(20)<< "Expiration Date"
            <<left <<"Inventory Type\n";

         //WRITE CODE HERE
  		 // display all items in list
    for(int i = 1; i <= alist.getLength(); ++i){
        alist.retrieve(i, content);
        cout << content;
        cout << endl;
    }

}

