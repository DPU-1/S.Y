#include <iostream>
#include <string>

using namespace std;

class Telephone
{
    long long key;
    string name[10];
    int address;
    int size; // size of telephone directory
    long long contact[10];

public:
    Telephone()
    {
        for (int i = 0; i < 10; i++)
        {
            contact[i] = 0;
            name[i] = "-";
        }
    }

    void insert()
    {
        cout << "Enter the number of records you want to insert:- " << endl;
        cin >> size;

        while (size--)
        {
            cout << "Enter the telephone no:- " << endl;
            cin >> key;

            address = hash_func(key);

            if (contact[address] == 0)
            {
                contact[address] = key;
                cout << "Enter the name of the person:- "
                     << "\n";
                cin >> name[address];
                cout << endl;
            }
            else
            {
                char ch ;

                    cout << " Enter L for Linear Probing and Q for quadratic Probing";
                    cin >> ch;

                    if (ch == 'l' || ch == 'L')
                    {
                        linear_Probing(contact, key, name);
                    
                    }
                    else if (ch == 'q' || ch == 'Q')
                    {
                        quadrating_Probing(contact, key, name);
                    }
                    else
                    {
                        cout << "\n Invalid Input";
                        insert();
                    }
            }
        }
    }
    void linear_Probing(long long contact[], long long key, string name[])
    {
        int adr = key % 10;
        while ((contact[adr % 10] != 0)) // searching for the location to insert
        {
            adr++; // incremnting address by one
        }
        contact[adr % 10] = key;
        cout << "Enter the name of person:- "
             << "\n";
        cin >> name[adr % 10];
    }

    void quadrating_Probing(long long contact[], long long key, string name[])
    {
        int adr = hash_func(key);
        int i = 0;
        while (contact[adr % 10] != 0 && i < 10) // 10 is MAX
        {
            adr = (adr + i * i) % 10;
            i++;
        }
        contact[adr % 10] = key;
        cout << "Enter the name of person:- " << endl;
        cin >> name[adr % 10];
    }

    void display()
    {
        cout << "Index\tName\tContact No" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i << "\t" << name[i] << "\t" << contact[i] << "\t"
                 << "\n";
        }
    }

    int hash_func(long long key)
    {
        return (key % 10);
    }
};

int main()
{

    Telephone t1;

    int choice;
    char ch;

    do
    {
        cout << "****Telephone Directory****" << endl;
        cout << "1. Insert record in Directory" << endl;
        cout << "2. Display Telephone Directory" << endl;
        cout << "3. Exit" << endl;

        cout << endl
             << "Enter your choice :- ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            t1.insert();
            break;
        case 2:
            t1.display();
            break;
        }
    } while (choice < 3);
    return 0;
}