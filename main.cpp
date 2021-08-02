#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define NUMBER_OF_LIBRARIANS 4

int request;

char anotherRequest;
bool validAccount = false;
bool bookFound = false;
string bookTitle;

struct date
{
    int day;
    int month;
    int year;

};
struct userDetails
{
    int id;
    string name;
    string email;
    string password;
    string accountType;
    date creationDate;
    int contactNumber1;
    int contactNumber2;
    int contactNumber3;


}user;
struct users
{
    int id;
    string name;
    string email;
    string password;
    string accountType;
    date creationDate;


}user1[10];
struct booksDetails
{
    string title;
    int productionYear;
    int nCopies;
    string category;
    int edition;
}book[6];
void isUserValid()
{
        cout<<"Enter username and password"<<endl;

    string username, librarianUsername[NUMBER_OF_LIBRARIANS] ;

    int password, LibrarianPassword[NUMBER_OF_LIBRARIANS];

    cin >> username >> password;
    ifstream librarians("LibrariansRecord.txt");

    for(int i = 0 ; i < NUMBER_OF_LIBRARIANS ; i ++)
    {
        while(librarians>>librarianUsername[i]>>LibrarianPassword[i])
        {
            if(librarianUsername[i]==username && LibrarianPassword[i]==password)
            {
                validAccount = true;

            }
        }

    }
    if(validAccount==false )
    {
        isUserValid();
    }
    validAccount=false;

}

void createAccount()
{
    int nContactNumbers;

    cout<<"Enter user's id, name, email, password, account type (student/staff/guest), and today's date"<<endl;

    cin >> user.id >> user.name >> user.email >> user.password ;
    cin>> user.accountType >> user.creationDate.day >> user.creationDate.month >> user.creationDate.year;

    ofstream usersRecord;
    usersRecord.open("UsersDetails.txt",ios::app);
    usersRecord<<endl<<user.id <<" "<< user.name <<" "<< user.email <<" "<< user.password <<" "<< user.accountType <<" "<<
    user.creationDate.day <<" "<< user.creationDate.month <<" "<< user.creationDate.year<<" ";

    cout<<"Number of contact numbers ? (maximum 3 )"<<endl;

    cin>>nContactNumbers;
    cout<<"Enter "<<nContactNumbers<<" contact numbers"<<endl;

    switch (nContactNumbers)
    {
    case 1 :
        cin >> user.contactNumber1;
        break;
    case 2 :
        cin >> user.contactNumber1;
        cin >> user.contactNumber2;
        break;
    case 3 :
        cin >> user.contactNumber1;
        cin >> user.contactNumber2;
        cin >> user.contactNumber3;
        break;

    }


}
void searchBook()
{
    char searchTitle;
    bool isTitle=false;
    int bookProductionYear;
   cout<<"Do you want to search using the book's title ? 'Y/N'"<<endl;
    cin>>searchTitle;
    if(searchTitle=='Y' || searchTitle=='y' )
    {
        isTitle=true;
        cout<<"Enter book's title"<<endl;
        cin>>bookTitle;
    }
    else if(searchTitle=='N' || searchTitle=='n')
    {
        cout<<"Enter production year "<<endl;
        cin>>bookProductionYear;
    }
    if(isTitle==true)
    {
    for(int i = 1 ; i <=5 ; i ++)
    {
        if(bookTitle==book[i].title)
        {
            bookFound=true;
            cout<<"Title: "<<book[i].title <<endl;
            cout <<"Production Year: " <<  book[i].productionYear <<endl;
            cout<<"Number of available copies: "<< book[i].nCopies <<endl
            <<"Category: "<< book[i].category <<endl
            <<"Edition: "<< book[i].edition<<endl;
        }
    }

    }
    else
    {
        for(int i = 1 ; i <=5 ; i ++)
    {
        if(bookProductionYear==book[i].productionYear)
        {
            bookFound=true;
            cout<<"Title: "<<book[i].title <<endl;
            cout <<"Production Year: " <<  book[i].productionYear <<endl;
            cout<<"Number of available copies: "<< book[i].nCopies <<endl
            <<"Category: "<< book[i].category <<endl
            <<"Edition: "<< book[i].edition<<endl;
        }
    }
    }

    if(bookFound==false)
    {
        cout<<"Not Available"<<endl;
    }
    bookFound=false;
}
void buyBook()
{
    bool isValid = false ;
    int userId;
    cout<<"Enter user's ID"<<endl;
    cin>>userId;
    ifstream usersRecord("UsersDetails.txt");
    for(int i = 0 ; i < 10 ; i ++)
    {
    while(usersRecord>>user1[i].id>>user1[i].name >>user1[i].email>>user1[i].password>>user1[i].accountType>>user1[i].creationDate.day
          >>user1[i].creationDate.month>>user1[i].creationDate.year)
    {
        if(userId==user1[i].id && user1[i].accountType=="staff")
        {
            isValid = true;
         }
    }

    }
    if(isValid)
    {
    cout<<"Enter book title"<<endl;
    cin>>bookTitle;
     for(int i = 1 ; i <=5 ; i ++)
    {
        if(bookTitle==book[i].title)
        {
            if(book[i].nCopies>=1)
            {
            bookFound=true;
            book[i].nCopies--;
            cout<<"Done"<<endl;

            }
            else{
                    bookFound=true;
                cout<<"No available copies"<<endl;
            }
        }
    }
}
else
{
    cout<<"Not valid "<<endl;
    return;
}

    if(bookFound==false)
    {
        cout<<"Not available"<<endl;
    }
    bookFound=false;
    isValid=false;


}
void showReport()
{
    int day, month, year ;
    cout<<"Enter the date of today"<<endl;
    cin>>day>>month>>year;
    ifstream usersRecord("UsersDetails.txt");
    for(int i = 0 ; i < 10 ; i ++)
    {
    while(usersRecord>>user1[i].id>>user1[i].name >>user1[i].email>>user1[i].password>>user1[i].accountType>>user1[i].creationDate.day
          >>user1[i].creationDate.month>>user1[i].creationDate.year)
          {
              if(user1[i].creationDate.month==month &&
                 user1[i].creationDate.year==year &&
                 user1[i].creationDate.day>=(day-7) &&
                  user1[i].creationDate.day<=day)
              {
                    cout<<user1[i].id<<" "<<user1[i].name <<" "<<user1[i].email<<" "<<
                    user1[i].password<<" "<<user1[i].accountType<<" "<<user1[i].creationDate.day
                    <<" "<<user1[i].creationDate.month<<" "<<user1[i].creationDate.year<<endl;

              }
          }

   }
}
int main()
{
    book[1].title="Ash";
    book[1].productionYear=2020;
    book[1].nCopies=1;
    book[1].category="Drama";
    book[1].edition=3;

    book[2].title="Annabel";
    book[2].productionYear=2019;
    book[2].nCopies=10;
    book[2].category="Thriller";
    book[2].edition=2;

    book[3].title="Magic";
    book[3].productionYear=2010;
    book[3].nCopies=0;
    book[3].category="Adventure";
    book[3].edition=3;

    book[4].title="Beloved";
    book[4].productionYear=2009;
    book[4].nCopies=4;
    book[4].category="Drama";
    book[4].edition=2;

    book[5].title="Deathless";
    book[5].productionYear=2001;
    book[5].nCopies=5;
    book[5].category="Romance";
    book[5].edition=1;

    cout<<"\t"<<"Library Management System"<<endl;
    cout<<endl;
    isUserValid();
    do
    {
        validAccount=false;
        cout<<"Enter 1 to create an account"<<endl;
        cout<<"Enter 2 to search for a book"<<endl;
        cout<<"Enter 3 to buy a book"<<endl;
        cout<<"Enter 4 to view the report for the last 7 days"<<endl;
        cin >> request;
        switch (request)
        {
        case 1:
            createAccount();
               break;
        case 2 :
            searchBook();
            break;
        case 3 :
            buyBook();
            break;


        case 4 :
            showReport();


        }
        cout<<endl;
        cout<<"Do you have another request ? 'Y/N'"<<endl;
        cin>>anotherRequest;
    }
    while(anotherRequest=='Y' || anotherRequest=='y');


    return 0;

}
