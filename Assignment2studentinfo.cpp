// #include <iostream>
// #include <fstream>
// #include <cstdio>

// using namespace std;

// class student
// {
// public:
//     int roll_no;
//     char name[40];
//     char divison[50];
//     char addrress[80];

//     void set_data()
//     {
//         cout << "Enter Roll no :- ";
//         cin >> roll_no;
//         cout << endl;
//         cout << "Enter your division:- " << endl;
//         cin >> divison;
//         cout << endl;
//         cout << "Enter the name of the Student :- ";
//         cin >> name;
//         cout << endl;
//         cout << "Enter you Addrress :- ";
//         cin >> addrress;
//         cout << endl;
//     }

//     void show_data()
//     {
//         cout << " Student Details " << endl;
//         cout << endl
//              << "Name of the student is :- " << name << endl;
//         cout << "Roll no is :- " << roll_no << endl;
//         cout << "Division of that student:- " << divison << endl;
//         cout << "Addrress :- " << addrress << endl;
//     }
//     int retAdmno()
//     {
//         return roll_no;
//     }
// };

// void insert_data()
// {

//     ofstream newfile;
//     newfile.open("student_data.txt", ios::binary | ios::app);

//     student object;
//     object.set_data();

//     newfile.write((char *)&object, sizeof(object));

//     newfile.close();
// }

// void display_data()
// {

//     ifstream input_file;
//     input_file.open("student_data.txt", ios::binary);

//     student object;

//     while (input_file.read((char *)&object, sizeof(object)))
//     {
//         object.show_data();
//         break;
//     }

//     input_file.close();
// }

// bool search_rollno(int n)
// {

//     ifstream input_file;
//     bool flag = false;
//     input_file.open("student_data.txt", ios::binary);

//     student object;

//     while (input_file.read((char *)&object, sizeof(object)))
//     {

//         if (object.roll_no == n)
//         {
//             flag = true;
//             object.show_data();
//             return true;
//             break;
//         }
//     }

//     cout << "Record of Roll No " << n << " not found in the database" << endl;
//     return false;
// }

// void delete_record(int n)
// {

//     student object;

//     ifstream input_file;
//     input_file.open("student_data.txt", ios::binary);

//     ofstream output_file;
//     output_file.open("temp.txt", ios::out | ios::binary);

//     int a = search_rollno(n);
//     if (a)
//     {
//         while (input_file.read((char *)&object, sizeof(object)))
//         {

//             if (object.roll_no != n)
//             {
//                 output_file.write((char *)&object, sizeof(object));
//             }
//         }
//         input_file.close();
//         output_file.close();
//         remove("student_data.txt");
//         rename("temp.txt", "student_data.txt");
//     }
//     else
//     {
//         cout << " Data of Roll No " << n << " Not present , Hence canot perform delete operation" << endl;
//     }
// }

// void update(int n)
// {
//     fstream file;
//     file.open("student_data.txt", ios::in | ios::out);
//     student obj;

//     while (file.read((char *)&obj, sizeof(obj)))
//     {
//         if (obj.retAdmno() == n)
//         {
//             cout << "\n Enter the new details of student:- " << endl;
//             obj.set_data();

//             int pos = (sizeof(obj));
//             file.seekp(pos, ios::cur);
//             file.write((char *)&obj, sizeof(obj));
//         }
//     }
//     file.close();
// }

// int main()
// {

//     int choice;

//     do
//     {
//         cout << endl
//              << "Enter The File Operation that you want to perform" << endl
//              << endl;
//         cout << "1. Add Data to file" << endl;
//         cout << "2. Display Data of file" << endl;
//         cout << "3. Search Data " << endl;
//         cout << "4. Delete Data of a student" << endl;
//         cout << "5.Update the Data of file:- " << endl;
//         cout << "6. Exit" << endl;

//         cout << endl
//              << "Enter you choice :- ";
//         cin >> choice;
//         cout << endl;

//         switch (choice)
//         {
//         case 1:
//             cout << "Enter number of Records you want to Add :- ";
//             int num;
//             cin >> num;
//             cout << endl;
//             for (int i = 0; i < num; i++)
//             {
//                 cout << "\n Enter the " << i + 1 << " student details :\n";

//                 insert_data();
//             }
//             break;

//         case 2:
//             cout << endl
//                  << " List Of Students and thier Data" << endl;
//             display_data();
//             break;

//         case 3:
//             cout << "Enter Roll No of student :- ";
//             int rollno;
//             cin >> rollno;
//             cout << endl;
//             search_rollno(rollno);
//             break;

//         case 4:
//             cout << "Enter the roll no to be deleted :- ";
//             int roll;
//             cin >> roll;
//             delete_record(roll);
//             break;

//         case 5:
//             cout << "Enter the roll no to be update:- " << endl;
//             int m;
//             cin >> m;
//             update(m);
//             break;
//         }
//     } while (choice < 6);

//     cout << endl
//          << "Successfully Performed the Operations" << endl;

//     return 0;
// }
#include <iostream>
#include <fstream>
using namespace std;
class Student
{
public:
    int roll;
    char name[20];
    char div;
    char address[20];
    void input()
    {
        cout << "Enter roll no. ";
        cin >> roll;
        cout << "Enter name ";
        cin >> name;
        cout << "Enter div ";
        cin >> div;
        cout << "Enter address ";
        cin >> address;
    }
    void output()
    {
        cout << "Roll no. is " << roll << endl;
        cout << "Name is " << name << endl;
        cout << "Div is " << div << endl;
        cout << "Address is " << address << endl;
        cout << "\n";
    }
    void write()
    {
        ofstream File;
        File.open("File.dat", ios::binary | ios::app);
        Student obj;
        obj.input();
        File.write((char *)&obj, sizeof(obj));
        File.close();
    }
    void display()
    {
        ifstream File;
        File.open("File.dat", ios::binary);
        Student obj;
        while (File.read((char *)&obj, sizeof(obj)))
        {
            obj.output();
        }
        File.close();
    }
    void search(int n)
    {
        ifstream File;
        File.open("File.dat", ios::binary);
        int fl = 0;
        Student obj;
        while (File.read((char *)&obj, sizeof(obj)))
        {
            if (obj.roll == n)
            {
                obj.output();
                fl = 1;
                break;
            }
        }
        if (fl == 0)
            cout << "No records";
        File.close();
    }
    void Delete(int n)
    {
        Student obj;
        ifstream File;
        File.open("File.dat", ios::binary);
        ofstream Temp;
        Temp.open("TempFile.dat", ios::binary);
        while (File.read((char *)&obj, sizeof(obj)))
        {
            if (obj.roll != n)
            {
                Temp.write((char *)&obj, sizeof(obj));
            }
        }
        File.close();
        Temp.close();
        remove("File.dat");
        rename("TempFile.dat", "File.dat");
    }
};
int main()
{
    int choice;
    char ch;
    int n, rolln, search;
    Student obj;
    do
    {
        cout << "1.Add records\n2.Display records\n3.Search record\n4.Delete record" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter how many records? ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                obj.write();
                cout << endl;
            }
            break;
        case 2:
            obj.display();
            cout << endl;
            break;
        case 3:
            cout << "enter roll no. to search ";
            cin >> search;
            obj.search(search);
            cout << endl;
            break;
        case 4:
            cout << "\nEnter the rollno. to delete ";
            cin >> rolln;
            obj.Delete(rolln);
            cout << endl;
            break;
        default:
            cout << "invalid choice";
            break;
        }
        cout << "Do you want to continue? press y else n ";
        cin >> ch;
    } while (ch == 'y');
}
