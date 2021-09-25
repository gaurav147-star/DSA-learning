#include <iostream>
using namespace std;
const int m = 50;

class Item
{

    int itemCode[m];
    float itemPrice[m];
    int count;

public:
    void CNT(void) { count = 0; }
    void getitem(void);
    void displaySum(void);
    void remove(void);
    void displayItems(void);
};

void Item::getitem(void)
{
    cout << "Enter item code : ";
    cin >> itemCode[count];
    cout << "Enter the cost : ";
    cin >> itemPrice[count];
    count++;
}

void Item::displaySum(void)
{
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum = sum + itemPrice[i];
    }
    cout << "\nTotal value : " << sum << endl;
}

void Item::remove(void)
{
    int a;
    cout << "Enter item code : ";
    cin >> a;
    for (int i = 0; i < count; i++)
    {
        if (itemCode[i] == a)
        {
            itemPrice[i] = 0;
        }
    }
}
void Item::displayItems(void)
{
    cout << "\nCode Price\n";
    for (int i = 0; i < count; i++)
    {
        cout << "\n"
             << itemCode[i];
        cout << " " << itemPrice[i];
    }
    cout << endl;
}

int main()
{
    Item order;
    order.CNT();
    int x;
    do
    {
        cout << "\nYou can do the following;"
             << "Enter appropriate number \n";
        cout << "\n1: Add an item ";
        cout << "\n2: Display total value";
        cout << "\n3: Delete an item";
        cout << "\n4: Display all items";
        cout << "\n5: Quit";

        cin >> x;
        switch (x)
        {
        case 1:
            order.getitem();
            break;
        case 2:
            order.displaySum();
            break;
        case 3:
            order.remove();
            break;
        case 4:
            order.displayItems();
            break;
        case 5:
            break;

        default:
            cout << "\nError in input try again";
        }
    } while (x != 5);
}
