#include<iostream>
#include<string>
using namespace std;

class Publication
{
public:
    string title;
    float price;

    void getPublication()
    {
        cout << "\nEnter Title: ";
        cin.ignore();
            getline(cin, title);

        cout << "\nEnter Price: ";
        cin >> price;

        if (price < 0)
            throw price;
    }

    void displayPublication()
    {
        cout << "\nTitle: " << title;
        cout << "\nPrice: " << price;
    }
    void reset()
    {
        title = "";
        price = 0;
    }
};

class Book : public Publication
{
    int pages;

public:

    void getBook()
    {
        try
        {
            getPublication();

            cout << "Enter Number of pages: ";
            cin >> pages;

            if (pages < 0)
                throw pages;
        }
        catch (...)
        {
            cout << "\nException Caught......\nInvalid input";

            reset();
            pages = 0;
        }
    }
    void displayBook()
    {
        displayPublication();
        cout << "\nPages: " << pages;
    }
};

class tape : public Publication
{
    float time;

public:
    void getTape()
    {
        try
        {
            getPublication();

            cout << "Enter Playing time: ";
            cin >> time;

            if (time < 0)
                throw time;
        }
        catch (...)
        {
            cout << "\nException Caught......\nInvalid input";

            reset();
            time = 0;
        }
    }
    void displayTape()
    {
        displayPublication();

        cout << "\nPlaying time: " << time;
    }
};

int main()
{
    Book b;
    tape t;

    cout << "\nEnter book details: \n";
    b.getBook();

    cout << "\nEnter tape details: \n";
    t.getTape();

    cout << "\nBook details: \n";
    b.displayBook();

    cout << "\nTape details: \n";
    t.displayTape();
    return 0;
}
