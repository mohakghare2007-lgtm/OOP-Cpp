 
        #include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class staff
{
private:
    int staff_id;
    string name;
    float basic_salary;
    float DA, HRA, ITax, NetSalary;

public:
    void accept()
    {
        cout << "\nEnter Staff ID : ";
        cin >> staff_id;

        cout << "Enter Staff Name : ";
        cin >> name;

        cout << "Enter Basic Salary : ";
        cin >> basic_salary;
    }

    void calculate()
    {
        DA = basic_salary * 0.25;
        HRA = 800;
        ITax = basic_salary * 0.15;
        NetSalary = basic_salary + DA + HRA - ITax;
    }

    void display()
    {
        cout << "\n--------------------------------";
        cout << "\nStaff ID      : " << staff_id;
        cout << "\nName          : " << name;
        cout << "\nBasic Salary  : " << basic_salary;
        cout << "\nDA (25%)      : " << DA;
        cout << "\nHRA           : " << HRA;
        cout << "\nIncome Tax    : " << ITax;
        cout << "\nNet Salary    : " << NetSalary;
        cout << "\n--------------------------------";
    }

    string getName()
    {
        return name;
    }
};

int main()
{
    int n;

    cout << "Enter number of staff: ";
    cin >> n;

    staff *s = new staff[n];

    // Accept and calculate
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Details of Staff " << i + 1 << endl;
        s[i].accept();
        s[i].calculate();
    }

    // Sort by name
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i].getName() > s[j].getName())
            {
                swap(s[i], s[j]);
            }
        }
    }

    // Display
    cout << "\n=========== STAFF PAY SLIP ===========";

    for (int i = 0; i < n; i++)
    {
        s[i].display();
    }

    delete[] s;

    return 0;
}
