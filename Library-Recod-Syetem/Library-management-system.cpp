//Libray Management System
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

std::string toLowerCase(std::string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

class Book{
    private:
    int copies;
    std::string phone_num;
    std::string title, author, ISBN, name, date, remarks;

    public:
    //setters
    void settitle(std::string title )       { this-> title = title;  }
    void setauthor(std::string author )     { this-> author = author; }
    void setcopies(int copies )             { this-> copies = copies;}
    void setISBN(std::string ISBN )         { this-> ISBN = ISBN;    }

    //getters
    std::string gettitle()       { return this->title; }
    std::string getauthor()      { return this->author;}
    int getcopies()              { return this->copies;}
    std::string getISBN()        { return this->ISBN;  }
    std::string getphone()       { return this->phone_num;}
    std::string getdate()        { return this->date;}
    std::string getremarks()     { return this-> remarks; }
    std::string getname()        { return this-> name; }

    //creat Book data in a constructor
    Book(std::string title, std::string author, std::string ISBN, int copies)
    {
        this-> title = title;
        this-> author = author;
        this-> copies = copies;
        this-> ISBN = ISBN;
    }

    //issue book form
    Book(std::string name, std::string title, std::string date, std::string phone_number, std::string remarks)
    {
        this-> title = title;
        this-> name = name;
        this-> date = date;
        this-> phone_num = phone_number;
        this-> remarks = remarks;
    }
    //recieve book
    Book(std::string name, std::string title, std::string date, std::string remarks)
    {
        this-> title = title;
        this-> name = name;
        this-> date = date;
        this-> remarks = remarks;
    }

    //deafult constructor
    Book() {}
};

class bookRecod{
    private:
    std::vector <Book> BookRecod;
    public:
    //issue book
    void issueBook(std::string name, std::string title, std::string date, std::string phone_number, std:: string remarks)
    {
        Book tempobj(name, title, date, phone_number, remarks);
        BookRecod.push_back(tempobj);
        return;
    }

    //Recieve book
    void recieveBook(std::string name, std::string title, std::string date, std::string phone_number, std::string remarks)
    {
        {
            Book tempobj(name, title, date, phone_number , remarks);
            BookRecod.push_back(tempobj);
            return;
        }
    }

    bool choice(std::string Title)
    {
        if(BookRecod.empty())
        {
            return true;
        }else
        { 
            for(auto it = BookRecod.begin(); it != BookRecod.end(); it++)
            {
                if( toLowerCase(it->gettitle()) == toLowerCase(Title))
                {
                    {return false;}
                }
            }
           return true; 
        }
    }
    
    //Record register
    void displayrecod()
    {
        if(BookRecod.empty())
        {
            std::cout << "NO book has been Issued/Recieved yet." << std::endl;
            return;
        }else
        {  
            int Sno = 1;  
            for( auto temp : BookRecod)
            {
                std::cout << "Sr.no: " << Sno<<std::endl;
                if(temp.getname() != "")
                {std::cout << "      Name: " << temp.getname()<<std::endl;}
                std::cout << "      Title: " << temp.gettitle()<<std::endl;
                if(temp.getphone() != "")
                {std::cout << "      Phone: " << temp.getphone()<<std::endl;}
                std::cout << "      Date: " << temp.getdate()<<std::endl;
                std::cout << "      Remarks: " << temp.getremarks()<<std::endl;
                std::cout << "___________________________________" << std::endl;
                Sno++;
            }
            return;
        }
    }
    

};

class BookManagementSystem{
    private:
    std::vector <Book> Books;
    public:

    //add Book
    void addBook(Book& Book)
    {    
        Books.push_back(Book);
    }

    //remove Book
    void removeBook(std::string Title)
    {
        for(auto it = Books.begin(); it != Books.end(); it++)
        {
            if(toLowerCase(it->gettitle())== toLowerCase(Title))
            {
                Books.erase(it);
                std::cout << "The book '" << Title<< "' has been removed successfully." << std::endl;
                return;
            }
        }
    }

    //display all Books in the system
    void displayBooks()
    {
        if(Books.empty())
        {
            std::cout << "There is NO Book in the system." << std::endl;
            return;
        }else
        {  
            int Sno = 1;  
            for( auto temp : Books)
            {
                std::cout << "BKn: " << Sno<<std::endl;
                std::cout << "      Title: " << temp.gettitle()<<std::endl;
                std::cout << "      Author.: " << temp.getauthor()<<std::endl;
                std::cout << "      ISBN: " << temp.getISBN()<<std::endl;
                std::cout << "      copies: " << temp.getcopies()<<std::endl;
                std::cout << "___________________________________" << std::endl;
                Sno++;
            }
            return;
        }
    }

    //Show Book details
    void show_Book(std::string Title)
    {
        for(auto it = Books.begin(); it != Books.end(); it++)
        {
            if(toLowerCase(it->gettitle())== toLowerCase(Title))
            {
                std::cout << "Title: " << it->gettitle()<<std::endl;
                std::cout << "Author.: " << it->getauthor()<<std::endl;
                std::cout << "copies: " << it->getcopies()<<std::endl;
                std::cout << "ISBN: " << it->getISBN()<<std::endl;
                std::cout << "___________________________________" << std::endl;
                return;
            }
        }
        return;
    }

    //choice Book in database
    bool verify_Book(std::string Title)
    {   
        for(auto it = Books.begin(); it != Books.end(); it++)
        {
            if(toLowerCase(it->gettitle())== toLowerCase(Title))
            {
                return true; 
            }
        }
        return false;
    } 
    
    //verify Book
    bool verify_Book(std::string S_title, std::string S_author, std::string S_ISBN)
    {   
        for(auto it = Books.begin(); it != Books.end(); it++)
        {
            if(toLowerCase(it->gettitle())== toLowerCase(S_title) && toLowerCase(it->getauthor()) == toLowerCase(S_author) && toLowerCase(it->getISBN()) == toLowerCase(S_ISBN))
            {
                return true;
            }
        }
        return false;
    } 
    
    //choice availabilty
    bool choice(std::string Title)
    {
        if(Books.empty())
        {
            return true;
        }else
        { 
            for(auto it = Books.begin(); it != Books.end(); it++)
            {
                if( toLowerCase(it->gettitle())== toLowerCase(Title))
                {
                    if(it->getcopies()==0)  {return true;}
                }
            }
           return false; 
        }
    } 

    //replace old data
    void addcopy(std::string Title, int copy)
    {
        for(auto it = Books.begin(); it != Books.end(); it++)
        {
            if(toLowerCase(it->gettitle())== toLowerCase(Title))
            {   
                it->setcopies(it->getcopies() + copy);
                return;
            }
        }
        return;
    }

    //Home content
    void showHeader()
    {
        std::cout << "\nICIT Library Management System" << std::endl;
        std::cout << "___________________________________" << std::endl;
    }

    //issue book
    void issueBook(std::string Title)
    {
        for(auto it = Books.begin(); it != Books.end(); it++)
        {
            if(toLowerCase(it->gettitle())== toLowerCase(Title))
            {  
                it->setcopies(it->getcopies() - 1);
                return;
            }
        }
    }

    //recieve book
    void recieveBook(std::string Title)
    {
        for(auto it = Books.begin(); it != Books.end(); it++)
        {
            if(toLowerCase(it->gettitle())== toLowerCase(Title))
            {   
                it->setcopies(it->getcopies() + 1);
                return;
            }
        }
    }
};

int main()
{
    BookManagementSystem SMS;
    bookRecod NR;
    Book B1;
    int state = 0, state2, copies, choice;
    std::string title, author, ISBN;
    std::string name, phone_no, date;
    
    while(true)
    {    
        switch(state)
        {
            case 0:
            {
               SMS.showHeader();
                std::cout << "________________Home_______________" << std::endl;
                std::cout << "\nChose an operation" << std::endl;
                std::cout << "1. Add Book\n2. Remove Book\n3. Search\n4. Displayall\n5. Add new copies\n6. Issue book\n7. Recieve book\n8. View register\n9. Exit" << std::endl;
                std::cout << "--> ";
                choice = getch();
                if(int(choice) > 57 |  int(choice) < 48)  //input validation 
                { 
                    std::cout<<"\n\nInvalid entry . Redirecting....";
                    state = 0; 
                }else
                {
                    state = int(choice) - 48 ;
                }

            }break;
            case 1:
            {
                SMS.showHeader();
                std::cout << "______________Add Data_____________" << std::endl;
                std::cin.ignore();
                std::cout << "\nEnter Book full title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Book author: ";
                std::getline(std::cin, author);
                std::cout << "Enter Book number of copies: ";
                std::cin >> copies;
                std::cout << "Enter Book ISBN : ";
                std::cin.ignore();
                std::getline(std::cin, ISBN);
                std::cout << "Verifying..."<<std::endl;
                if(SMS.verify_Book(title, author, ISBN) == true)
                {
                    std::cout << "Book already exist.. add copies instead" <<std::endl;
                    SMS.show_Book(title);
                    std::cout << "1. Add another \n0. Home\n--> " ;
                    std::cin >> state2;
                    (state2 == 1)? state = 1 : state = 0;
                }else{
                    std::cout << "Added successfully.."<<std::endl;
                    Book s1(title, author, ISBN, copies);
                    SMS.addBook(s1);
                    std::cout << "1. Add another\n0. Home\n--> " ;
                    std::cin >> state2;
                    (state2 == 1)? state = 1 : state = 0;
                }
            }break;
            case 2:
            {    
                SMS.showHeader();   
                std::cout << "____________Remove Book____________" << std::endl;
                std::cout << "\nEnter Book name > ";
                std::cin.ignore();
                std::getline(std::cin,title);
                if(SMS.verify_Book(title) == false )
                {
                    std::cout << "The book  '" << title<< "' NOT found!" << std::endl;
                    std::cout << "1. Remove another\n0. Home\n--> " ;
                    std::cin >> state2;
                    (state2 == 1)? state = 2 : state = 0;
                }else{
                    SMS.removeBook(title);
                    std::cout << "1. Remove another\n0. Home\n--> " ;
                    std::cin >> state2;
                    (state2 == 1)? state = 2 : state = 0;
                }  

            }break;
            case 3:
            {
                SMS.showHeader();
                std::cout << "____________Search Book____________" << std::endl;
                std::cout << "\nEnter Book Name > ";
                std::cin.ignore();
                std::getline(std::cin,title);
                SMS.showHeader();
                if(SMS.verify_Book(title) == true)
                {
                    std::cout << "Book found..."<<std::endl;
                    SMS.show_Book(title);
                }else
                {
                    std::cout<<"The Book '"<<title<<"' NOT found!"<<std::endl;
                }
                
                std::cout << "1. Search another\n0. Home\n--> " ;
                std::cin >> state2;
                (state2 == 1)? state = 3 : state = 0;

            }break;
            case 4:
            {
                SMS.showHeader();
                std::cout << "__________View All Books___________\n" << std::endl;
                SMS.displayBooks();
                std::cout << "1. Add Book\n9. Exit\n0. Home\n--> " ;
                std::cin >> state2;
                (state2 == 9)? state = 9 : ((state2 == 1)? state = 1 : state = 0);

            }break;
            case 5:
            {
                SMS.showHeader();
                std::cout << "___________Add New copies__________" << std::endl;
                std::cout<< "\nSearch for Book!\nEnter book name > ";
                std::cin.ignore();
                std::getline(std::cin, title);

                if(SMS.verify_Book(title) == false )
                {
                    std::cout << "The book '" << title<< "' NOT found!" << std::endl;
                    std::cout << "1. Try another name\n2. Add new Book\n0. Home\n--> " ;
                    std::cin >> state2;
                    (state2 == 1)? state = 5 : ((state2 == 2)? state = 1 : state = 0);
                }else{
                    SMS.show_Book(title);
                    std::cout << "Enter NEW copies no: ";
                    int new_copies;
                    std::cin >> new_copies;
                    SMS.addcopy(title ,new_copies);
                    std::cout << "Now book '"<<title<<"' has '"<<new_copies<<"' more copies." << std::endl;
                    std::cout << "1. make another change\n0. Home\n--> " ;
                    std::cin >> state2;
                    (state2 == 1)? state = 5 : state = 0;
                }                

            }break;
            case 6:
            {
                //issue book
                SMS.showHeader();
                std::cout << "____________Issue Book_____________" << std::endl;
                std::cout << "Enter book name: ";
                std::cin.ignore();
                std::getline(std::cin, title);

                if(SMS.choice(title) == true)
                {
                    std::cout << "This book is currently unavailable ."<<std::endl;
                    std::cout << "1. Issue another\n0. Home\n->";
                    std::cin >> state2;
                    (state2 == 1)? state = 6 : state = 0;
                }else{
                    std::cout << "Enter reciever's name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    
                    std::cout << "Enter issue date(d-m-y): ";
                    std::getline(std::cin, date);
                    std::cout << "Enter Phone number: ";
                    std::getline(std::cin, phone_no);
                    std::string remarks = "Issued";
                    NR.issueBook(name, title, date, phone_no, remarks);
                    SMS.issueBook(title);
                    std::cout << "Book '"<<title<<"' Issued to '"<<name<<"' "<<std::endl;
                    std::cout << "1. Issue another \n0. Home\n--> " ;
                    std::cin >> state2;
                    (state2 == 1)? state = 6 : state = 0;
                }

            }break;
            case 7:
            {
                //Recieve book
                SMS.showHeader();
                std::cout << "____________Recieve Book___________" << std::endl;
                std::cout << "Enter book name: ";
                std::cin.ignore();
                std::getline(std::cin, title);

                if(NR.choice(title) == true)
                {
                    std::cout<<"No book named '"<<title<<"' has been issued"<<std::endl;
                    std::cout << "1. Recieve another\n0. Home\n--> " ;
                    std::cin >> state2;
                    (state2 == 1)? state = 7 : state = 0;
                }else
                {
                    std::cout << "Enter reciever's name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    
                    std::cout << "Enter recive date: ";
                    std::getline(std::cin, date);
                    std::cout << "Enter Handover's phone: ";
                    std::getline(std::cin, phone_no);
                    std::string remarks = "Recieved";
                    NR.recieveBook(name, title, date, phone_no, remarks);
                    SMS.recieveBook(title);
                    std::cout << "Book '"<<title<<"' Recieved from '"<<name<<"' "<<std::endl;
                    std::cout << "1. Recieve another\n0. Home\n--> " ;
                    std::cin >> state2;
                    (state2 == 1)? state = 7 : state = 0;
                }

            }break;
            case 8:
            {
                SMS.showHeader();
                std::cout << "___________Book Register___________" << std::endl;
                NR.displayrecod();
                std::cout << "1. Issue a book\n0. Home\n--> " ;
                std::cin >> state2;
                (state2 == 1)? state = 6 : state = 0;

            }break;
            case 9:
            {
                SMS.showHeader();
                std::cout << "exiting..";
                return 0;

            }break;
            default:
            {
                SMS.showHeader();
                std::cout << "wrong state.! Redirecting..." << std::endl;
                getch();
                state = 0;
            }
        }
    }

    return 0;
}