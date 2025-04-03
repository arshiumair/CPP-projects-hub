#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
class Student{
    private:
    int roll;
    std::string name, department, batch;
    char class_Section;

    public:
    //setters
    void setname(std::string name )              { this-> name = name; }
    void setdepartment(std::string department )  { this-> name = department; }
    void setroll(int roll )                 { this-> roll = roll; }
    void setbatch(std::string batch )            { this-> batch = batch; }
    void setsection(char class_Section)     { this-> class_Section = class_Section; }

    //getters
    std::string getname()            { return this->name; }
    std::string getdepartment()      { return this->department; }
    int getroll()               { return this->roll; }
    std::string getbatch()           { return this->batch; }
    char getsection()           { return this->class_Section; }

    //creat Student data in a constructor
    Student(std::string name, std::string department, char class_Section, int roll, std::string batch)
    {
        this-> name = name;
        this-> department = department;
        this-> roll = roll;
        this-> batch = batch;
        this-> class_Section = class_Section;
    }
    //deafult constructor
    Student() {}
};
class StudentManagementSystem{
    private:
    std::vector <Student> Students;
    public:

    //add Student
    void addStudent(Student& Student)
    {    
        Students.push_back(Student);
    }

    //remove Student
    void removeStudent(int roll)
    {
        for(auto it = Students.begin(); it != Students.end(); it++)
        {
            if(it->getroll()== roll)
            {
                Students.erase(it);
                std::cout << "Student with roll no. " << roll<< " has been removed successfully." << std::endl;
                return;
            }
        }
        std::cout << "Student with roll no. " << roll<< " NOT found!" << std::endl;
        return;
    }

    //display all Students in the system
    void displayStudents()
    {
        if(Students.empty())
        {
            std::cout << "There is NO Student in the system." << std::endl;
            return;
        }else
        {  
            int Sno = 1;  
            for( auto temp : Students)
            {
                std::cout << "Std: " << Sno<<std::endl;
                std::cout << "      Roll: " << temp.getroll()<<std::endl;
                std::cout << "      Name: " << temp.getname()<<std::endl;
                std::cout << "      Depart.: " << temp.getdepartment()<<std::endl;
                std::cout << "      class_Section: " << temp.getsection()<<std::endl;
                std::cout << "      Session: " << temp.getbatch()<<std::endl;
                std::cout << "___________________________________" << std::endl;
                Sno++;
            }
        }
    }

    //Show Student details
    void show_Student(int roll)
    {
        for(auto it = Students.begin(); it != Students.end(); it++)
        {
            if(it->getroll()== roll)
            {
                std::cout << "Roll: " << it->getroll()<<std::endl;
                std::cout << "Name: " << it->getname()<<std::endl;
                std::cout << "Depart.: " << it->getdepartment()<<std::endl;
                std::cout << "class_Section: " << it->getsection()<<std::endl;
                std::cout << "Batch: " << it->getbatch()<<std::endl;
                std::cout << "___________________________________" << std::endl;
                return;
            }
        }
        return;
    }

    //check Student in database
    bool verify_Student(int roll)
    {   
        for(auto it = Students.begin(); it != Students.end(); it++)
        {
            if(it->getroll()== roll)
            {
                return true;
            }
        }
        return false;
    } 
    
    //verify Student
    bool verify_Student(int S_roll, std::string S_department, std::string S_batch, char S_class_Section)
    {   
        for(auto it = Students.begin(); it != Students.end(); it++)
        {
            if(it->getroll()== S_roll && it->getdepartment() == S_department && it->getbatch() == S_batch && it->getsection() == S_class_Section)
            {
                return true;
            }
        }
        return false;
    } 
    
    //replace old data

    void Editinfo(int rollNumber, Student NewStudent)
    {
        for(auto it = Students.begin(); it != Students.end(); it++)
        {
            if(it->getroll()== rollNumber)
            {   int index = distance(Students.begin(),it);
                Students[index]=NewStudent;
            }
        }
    }

    //Home content
    void showHeader()
    {
        std::cout << "ICIT Database for Student record" << std::endl;
        std::cout << "___________________________________" << std::endl;
    }
};

int main()
{
    StudentManagementSystem SMS;
    int choice = 0, choice2;
    std::string name, department, batch;
    char class_Section;
    int rollNumber;
    while(true)
    {    
        switch(choice)
        {
            case 0:
            {
               SMS.showHeader();
                std::cout << "________________Home_______________" << std::endl;
                std::cout << "\nChose an operation" << std::endl;
                std::cout << "1. Add Student\n2. Remove Student\n3. Search\n4. Displayall\n5. Edit info\n6. Exit" << std::endl;
                std::cin >> choice;
            }break;
            case 1:
            {
               SMS.showHeader();
                std::cout << "______________Add Data_____________" << std::endl;
                std::cout << "\nEnter Student full name: ";
                std::cin.ignore();
                getline(std::cin, name);
                std::cout << "Enter Student department: ";
                std::cin >> department;
                std::cout << "Enter Student Roll No : ";
                std::cin >> rollNumber;
                std::cout << "Enter Student Session (Y_From-To): ";
                std::cin >> batch;
                std::cout << "Enter Student class_Section (A,B,C): ";
                std::cin >> class_Section;
                std::cout << "Verifying..."<<std::endl;
                if(SMS.verify_Student(rollNumber, department, batch, class_Section) == true)
                {
                    std::cout << "Student already exist.." <<std::endl;
                    SMS.show_Student(rollNumber);
                    std::cout << "1. Add another \n0. Home" << std::endl;
                    std::cin >> choice2;
                    (choice2 == 1)? choice = 1 : choice = 0;
                }else{
                    std::cout << "Added successfully.."<<std::endl;
                    Student s1(name, department, class_Section, rollNumber, batch);
                    SMS.addStudent(s1);
                    std::cout << "1. Add another\n0. Home" << std::endl;
                    std::cin >> choice2;
                    (choice2 == 1)? choice = 1 : choice = 0;
                }
            }break;
            case 2:
            {                
                std::cout << "___________Remove Data__________" << std::endl;
                std::cout << "\nEnter roll number > ";
                std::cin >> rollNumber;
                SMS.removeStudent(rollNumber);
                getch();
                std::cout << "1. Remove another\n0. Home" << std::endl;
                std::cin >> choice2;
                (choice2 == 1)? choice = 2 : choice = 0;

            }break;
            case 3:
            {
                SMS.showHeader();
                std::cout << "_______________Search______________" << std::endl;
                std::cout << "\nEnter roll number > ";
                std::cin >> rollNumber;
                SMS.showHeader();
                std::cout << "_______________Search______________" << std::endl;
                if(SMS.verify_Student(rollNumber) == true)
                {
                    std::cout << "Student found..."<<std::endl;
                    SMS.show_Student(rollNumber);
                }else
                {
                    std::cout<<"Student with roll number '"<<rollNumber<<"' NOT found"<<std::endl;
                }
                
                getch();
                std::cout << "1. Search another\n0. Home" << std::endl;
                std::cin >> choice2;
                (choice2 == 1)? choice = 3 : choice = 0;

            }break;
            case 4:
            {
                SMS.showHeader();
                std::cout << "_____________View List_____________\n" << std::endl;
                SMS.displayStudents();
                getch();
                std::cout << "1. Add Student\n9. Exit\n0. Home" << std::endl;
                std::cin >> choice2;
                if(choice2 == 9)
                {
                    choice = 6;
                }else
                {
                   (choice2 == 1)? choice = 1 : choice = 0; 
                }
                
            }break;
            case 5:
            {
                SMS.showHeader();
                std::cout << "____________Edit Record____________" << std::endl;
                std::cout<< "\nSearch for Student!\nEnter roll no > ";
                std::cin >> rollNumber;
                bool status = SMS.verify_Student(rollNumber);
                if(status == false )
                {
                    std::cout << "Student with roll no. " << rollNumber<< " NOT found!" << std::endl;
                    std::cout << "1. Try another Roll no\n2. Add new Student\n0. Home" << std::endl;
                    std::cin >> choice2;
                    if(choice2 == 1)
                    {
                        choice = 5;
                    }else
                    {
                       (choice2 == 2)? choice = 1 : choice = 0; 
                    }
                }else{
                    SMS.show_Student(rollNumber);
                    std::cout << "Enter new credentials.." << std::endl;
                    std::cout << "Enter NEW name: ";
                    int new_rollnumber;
                    std::cin.ignore();
                    getline(std::cin, name);
                    std::cout << "Enter NEW department: ";
                    std::cin >> department;
                    std::cout << "Enter NEW roll no: ";
                    std::cin >> new_rollnumber;
                    std::cout << "Enter NEW Session: ";
                    std::cin >> batch;
                    std::cout << "Enter NEW Setion: ";
                    std::cin >> class_Section;
                    Student tempobj(name, department, class_Section, new_rollnumber, batch);
                    SMS.Editinfo(rollNumber ,tempobj);
                    std::cout << "changes have been saved successfully" << std::endl;
                    std::cout << "1. make another change\n0. Home" << std::endl;
                    std::cin >> choice2;
                    (choice2 == 1)? choice = 5 : choice = 0;
                }                

            }break;
            case 6:
            {
                SMS.showHeader();
                std::cout << "exiting..";
                return 0;
            }break;
            default:
            {
                SMS.showHeader();
                std::cout << "wrong input.! Redirecting..." << std::endl;
                getch();
                choice = 0;
            }
        }
    }

    return 0;
}