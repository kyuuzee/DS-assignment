#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include <cstddef>     // for NULL
#include <new>         // for bad_alloc
#include<vector>
#include<stack>
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
public:
    int getLength() const;
    void add_item();
    void edit_item();
    void search_brand();
    void search_id();
    void search_type();
    void delete_item();
    void warning_inventory();
    void warning_date();
    void load()
        throw( ListException );
    void retrieve(int index, ListItemType& dataItem) const
	    throw(ListIndexOutOfRangeException);
    void sort_id(stack<string> &s);
    void sort_brand(stack<string> &s);
    void sort_qty(stack<string> &s);
    void sort_type(stack<string> &s);
    void sort_date();
    void reverse_stack(stack<string> &s);
    void print_stack(stack<string> &s);
};
