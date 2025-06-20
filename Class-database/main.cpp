#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

class Student{
    private:
    int roll;
    std::string name;
    std::string program;
    std::string batch;
    char class_Section;

    public:
    //setters
    void setname(std::string name )              { this-> name = name; }
    void setprogram(std::string program )        { this-> program = program; }
    void setroll(int roll )                      { this-> roll = roll; }
    void setbatch(std::string batch )            { this-> batch = batch; }
    void setsection(char class_Section)          { this-> class_Section = class_Section; }

    //getters
    std::string getname()            { return this->name; }
    std::string getprogram()         { return this->program; }
    int getroll()                    { return this->roll; }
    std::string getbatch()           { return this->batch; }
    char getsection()                { return this->class_Section; }

    //Student data in a constructor
    Student(std::string name, std::string program, char class_Section, int roll, std::string batch)
    {
        this-> name = name;
        this-> program = program;
        this-> roll = roll;
        this-> batch = batch;
        this-> class_Section = class_Section;
    }
    //deafult constructor
    Student() {}
    
    void serialize(std::ofstream &outFile) const
    {
        size_t N_len = name.length();
        size_t P_len = program.length();
        size_t B_len = batch.length();
        outFile.write(reinterpret_cast <const char*>(&roll), sizeof(roll)); 
        outFile.write(reinterpret_cast <const char*>(&class_Section), sizeof(class_Section));
        outFile.write(reinterpret_cast <const char*>(&N_len), sizeof(N_len)); 
        outFile.write(reinterpret_cast <const char*>(&P_len), sizeof(P_len));
        outFile.write(reinterpret_cast <const char*>(&B_len), sizeof(B_len));  
        outFile.write(name.c_str(), N_len);  
        outFile.write(program.c_str(), P_len); 
        outFile.write(batch.c_str(), B_len);

        return;
    }
    
    void Deserialize(std::ifstream &inFile)
    {
        if (inFile.eof())
        {
            std::cout<<"Nothing to read.."<<std::endl;
            return;
        }else
        { 
        
            size_t N_len;
            size_t P_len;
            size_t B_len;
            inFile.read(reinterpret_cast <char*>(&roll), sizeof(roll)); 
            inFile.read(reinterpret_cast <char*>(&class_Section), sizeof(class_Section));
            inFile.read(reinterpret_cast <char*>(&N_len), sizeof(N_len)); 
            inFile.read(reinterpret_cast <char*>(&P_len), sizeof(P_len));
            inFile.read(reinterpret_cast <char*>(&B_len), sizeof(B_len)); 
            name.resize(N_len);    
            program.resize(P_len); 
            batch.resize(B_len);                              
            inFile.read(&name[0], N_len);
            inFile.read(&program[0], P_len);
            inFile.read(&batch[0], B_len);

        }
        return;
    }
    
};

void char_to_upper(char &char_in)
{
    if(char_in > 'Z')
    {
        char_in = int(char_in) - 32;
    }
}
void str_to_upper(std::string &in_str)
{
    std::string n_str = "";
    for(char c : in_str)
    {
        char_to_upper(c);
        n_str += c;
    }
    in_str = n_str;
    return;
}
class StudentManagementSystem{
        
    public:

    //remove Student
    void removeStudent(int rollNumber, std::ifstream &inFile)
    {

        if(inFile.peek() == EOF )
        {
            std::cout << "Empty file" << std::endl;
            return;
        }else
        {
           
            std::ofstream outFile("student.bin", std::ios::binary | std::ios::trunc);
            while(inFile.peek() != EOF)
            {  
                Student S;
                S.Deserialize(inFile);
                if(S.getroll()== rollNumber)
                { 
                    std::cout << "Student with roll no. " << rollNumber<< " has been removed successfully." << std::endl;  
                    continue;
                }
                S.serialize(outFile);
                
            }
            
            outFile.close();
       
        }

            
        std::cout << "Student with roll no. " << rollNumber<< " NOT found!" << std::endl;

        return; 

        
        
    }

    //read objects from binary

    void Show_all_Students(std::ifstream &inFile, std::string dep, std::string bat, char sec)
    {   
    
        int Sno = 1;
        std::cout << "Displaying students of " << dep << " batch " << bat << " section: " << sec << std::endl;
        while(inFile.peek() != EOF)
        {  
            Student S;
            S.Deserialize(inFile);
            if(S.getprogram() == dep && S.getbatch() == bat && S.getsection() == sec)
            {
                std::cout << "S.No: " << Sno<< '\n' << std::endl;
                std::cout << "      Roll:    " << S.getroll()<<std::endl;
                std::cout << "      Name:    " << S.getname()<<std::endl;
                std::cout << "      Depart.: " << S.getprogram()<<std::endl;
                std::cout << "      Section: " << S.getsection()<<std::endl;
                std::cout << "      Session: " << S.getbatch()<<std::endl;
                std::cout << std::string(35,'_') << std::endl;
                Sno++;
            }
            
        }
        if(Sno == 1)
        {
            std::cout << "Nothing to show.."<< std::endl;
        }
        
        return;
    }

    //Show Student details
    void show_Student(int roll, std::ifstream &inFile)
    {
        if(inFile.is_open() == false )
        {
            std::cout << " error openning" << std::endl;
            return;
        }else
        {
            while(inFile.peek() != EOF)
            {  
                Student S;
                S.Deserialize(inFile);
                if(S.getroll() == roll)
                {
                    std::cout << "      Roll: " << S.getroll()<< std::endl;
                    std::cout << "      Name: " << S.getname()<<std::endl;
                    std::cout << "      Depart.: " << S.getprogram()<<std::endl;
                    std::cout << "      Section: " << S.getsection()<<std::endl;
                    std::cout << "      Session: " << S.getbatch()<<std::endl;
                    std::cout << std::string(35,'_') << std::endl;
                }
                
            }
        }
        return;
    }

    //check Student in database
    bool verify_Student(int roll, std::ifstream &inFile)
    {   
        while(inFile.peek() != EOF)
        {  
            Student S;
            S.Deserialize(inFile);
            if(S.getroll() == roll)
            {
                return true;
            }
            
        }
        return false;
    } 
    
    //verify Student
    bool verify_Student(int S_roll, std::string S_program, std::string S_batch, char S_class_Section, std::ifstream &inFile)
    {   
        while(inFile.peek() != EOF)
        {  
            Student S;
            S.Deserialize(inFile);
            if(S.getroll() == S_roll)
            {
            
                if( S.getprogram() == S_program && S.getbatch() == S_batch && S.getsection() == S_class_Section)
                {
                    return true;
                }
            }
        }
            
        return false;
    } 
    
    //replace old data

    void Editinfo(int rollNumber, Student NewStudent, std::ifstream &inFile)
    {

        if(inFile.peek() == EOF)
        {
            std::cout<<"File Empty .."<< std::endl;
            return;
        }else
        {
            std::ofstream outFile("student.bin", std::ios::binary | std::ios::trunc);
            while(inFile.peek() != EOF)
            {  
                Student S;
                S.Deserialize(inFile);
                if(S.getroll()== rollNumber)
                {   
                    NewStudent.serialize(outFile);
                    continue;
                }
                S.serialize(outFile);
                
            }
            
            outFile.close();
       
        }

        return;
    }

    void Header()
    {
        std::cout << "__________ ICIT RECORDS ___________"<<std::endl;

    }

    void open_c(std::ifstream &inFile)
    {
        if(!inFile)
        {
            std::ofstream outFile("student.bin", std::ios::binary | std::ios::trunc);
            outFile.close();
            std::cout << "Error opening file!" << std::endl;
            return ;
        }
    }

    void menu()
    {
        std::cout << "________________Home_______________" << std::endl;
        std::cout << "\nChose an operation" << std::endl;
        std::cout << "1. Add Student\n2. Remove Student\n3. Search\n4. Display all\n5. Edit info\n6. Erase all\n7. Export data\n8. Exit" << std::endl;
        return;
    }

    void flag()
    {
        std::cout << "Input Error " << std::endl;
        return;
    }

    bool input_d(std::string &name, std::string &program, std::string &batch, char &class_Section, int &rollNumber)
    {
        std::cout << "Enter Student Roll No : ";
        std::cin >> rollNumber;
        if(std::cin.fail())
        {
            flag();
            std::cin.clear();
            std::cin.ignore();
            return true;
        }
        std::cin.ignore();
        std::cout << "Enter Student full name: ";
        getline(std::cin, name);
        std::cout << "Enter Student program: ";
        getline(std::cin, program);
        str_to_upper(program);
        
        std::cout << "Enter Student Session (Y_From-To): ";
        getline(std::cin,batch );
        std::cout << "Enter Student class_Section (A,B,C): ";
        std::cin >> class_Section;
        char_to_upper(class_Section);
        if(std::cin.fail() || class_Section > 'Z' || class_Section < 'A')
        {
            flag();
            std::cin.clear();
            std::cin.ignore();
            return true;
        }
        
        return false;

    }

    bool exportdata(std::ofstream &outFile, std::ifstream &inFile )
    {
        if(inFile.peek() == EOF)
        {
            std::cout << "Nothing to export" << std :: endl;
            return true;
        }
        Student s;
        outFile << '\n';
        outFile <<std::setw(41) << "Gomal University D.I.K" << '\n';
        outFile <<"Roll No." << std::setw(12);
        outFile <<"Name" << std::setw(18);
        outFile <<"Program" << std::setw(9);
        outFile <<"Batch" << std::setw(14);
        outFile <<"Section" << '\n';
        outFile << std::string(61,'_');
        
        while(inFile.peek() != EOF)
        {
            s.Deserialize(inFile);
            outFile << '\n';
            outFile << s.getroll() << std::setw(20);
            outFile << s.getname() << std::setw(10);
            outFile << s.getprogram() << std::setw(12);
            outFile << s.getbatch() << std::setw(10);
            outFile << s.getsection() ;
            
        }
        return false;
    }

    
};




int main()
{
    
    
    StudentManagementSystem SMS;
    char choice = '0', choice2;
    std::string name, program, batch;
    char class_Section;
    int rollNumber;
    while(true)
    {    
        switch(choice)
        {
            case '0':
            {
                SMS.Header();
                SMS.menu();
                std::cin >> choice ;
            }break;
            case '1':
            {
               SMS.Header();
                std::cout << "______________Add Data_____________" << std::endl;
                std::ifstream inFile;
                inFile.open("student.bin", std::ios::binary);
                if(inFile.is_open() == false)
                {
                    std::cout << "File not found.." << std::endl;
                    choice = '6';
                    break;
                }

                bool In = SMS.input_d(name, program, batch, class_Section, rollNumber);
                if( In == true )
                {
                    continue;
                }
                SMS.open_c(inFile);  
                if(SMS.verify_Student(rollNumber, program, batch, class_Section, inFile) == true)
                {
                    std::cout << "Student already exist.." <<std::endl;
                    inFile.clear();
                    inFile.seekg(0, std::ios::beg);
                    SMS.show_Student(rollNumber,inFile);
                    std::cout << "1. Add another \n2. Edit info\n0. Home" << std::endl;
                    std::cin >> choice2;
                    (choice2 == '1')? choice = '1' : (choice2 == '2')? choice = '2' : choice = '0';
                }else{
                    std::cout << "Added successfully.."<<std::endl;

                    Student s1(name, program, class_Section, rollNumber, batch);
                    std::ofstream outFile("student.bin", std::ios::binary | std::ios::app); 
                    s1.serialize(outFile);
                    std::cout << "1. Add another\n0. Home" << std::endl;
                    std::cin >> choice2;
                    (choice2 == '1')? choice = '1' : choice = '0';
                }
                inFile.close();
            }break;
            case '2':
            {                
                std::cout << "___________Remove Data__________" << std::endl;
                std::cout << "\nEnter roll number > ";
                std::cin.ignore();
                std::cin >> rollNumber;
                std::ifstream inFile("student.bin", std::ios::binary ); 
                SMS.removeStudent(rollNumber, inFile);
                
                std::cout << "1. Remove another\n0. Home" << std::endl;
                std::cin >> choice2;
                (choice2 == '1')? choice = '2' : choice = '0';

                inFile.close();

            }break;
            case '3':
            {
                SMS.Header();
                std::cout << "_______________Search______________" << std::endl;
                std::cin.clear();
                std::ifstream inFile;
                inFile.open("student.bin", std::ios::binary );
                if(inFile.peek() == EOF)
                {
                    std::cout << "File is empty!" << std::endl;
                    std::cout << "1. Add Student\n0. Home" << std::endl;
                    std::cin >> choice2 ;  
                    inFile.close();  
                    (choice2 == '1')? choice = '1' : choice = '0';
                    break;
                }
                std::cout << "\nEnter roll number > ";
                std::cin >> rollNumber;
                std::cout << "Verifying..."<<std::endl;
                if(SMS.verify_Student(rollNumber, inFile) == true)
                {
                    std::cout << "Student found..."<<std::endl;
                    inFile.clear();
                    inFile.seekg(0, std::ios::beg);
                    SMS.show_Student(rollNumber, inFile);
                }else
                {
                    std::cout<<"Student with roll number '"<<rollNumber<<"' NOT found"<<std::endl;
                }
                
                std::cout << "1. Search another\n0. Home" << std::endl;
                
                std::cin >> choice2;
                (choice2 == '1')? choice = '3' : choice = '0';
                inFile.close();

            }break;
            case '4':
            {
                SMS.Header();
                std::cout << "_____________View List_____________\n" << std::endl;
                std::ifstream inFile;
                inFile.open("student.bin", std::ios::binary ); 
                if (inFile.peek() == EOF)
                {
                    std::cout<<"Nothing to read.."<< std::endl;
                    inFile.close();
                    std::cout << "1. Add Student\n0. Home" << std::endl;
                    std::cin >> choice2;
                    (choice2 == '1')? choice = '1' : choice = '0';
                    break;
                }

                std::cout << "Enter Student program: ";
                std::cin.ignore();
                getline(std::cin, program);
                str_to_upper(program);
                std::cout << "Enter Student Session (Y_From-To): ";
                getline(std::cin,batch );
                std::cout << "Enter Student class_Section (A,B,C): ";
                std::cin >> class_Section;
                char_to_upper(class_Section);
                if(std::cin.fail() || class_Section > 'Z' || class_Section < 'A')
                {
                    SMS.flag();
                    std::cin.clear();
                    std::cin.ignore();
                    choice = '4';
                }
                
                SMS.Show_all_Students(inFile, program, batch, class_Section);
                std::cout << "1. Try again \n2. Add Student\n0. Home" << std::endl;
                std::cin >> choice2;
                (choice2 == '1')? choice = '4' : ((choice2 == '2' )? choice = '1' : choice = '0') ; 

                inFile.close();
                
                
            }break;
            case '5':
            {
                SMS.Header();
                std::ifstream inFile;
                std::cout << "_____________Edit Data_____________\n" << std::endl;
                std::cout << "Enter roll number > ";
                std::cin >> rollNumber;
                if(std::cin.fail())
                {
                    SMS.flag();
                    std::cin.clear();
                    std::cin.ignore();
                    continue;
                }
                std::cout << "Verifying..."<<std::endl;
                inFile.open("student.bin", std::ios::binary ); 
                bool status = SMS.verify_Student(rollNumber, inFile);
                inFile.close();
                if(status == false )
                {
                    std::cout << "Student with roll no. " << rollNumber<< " NOT found!" << std::endl;
                    std::cout << "1. Try another Roll no\n2. Add new Student\n0. Home" << std::endl;
                    std::cin >> choice2;
                    (choice2 == '1')? choice = '5' : (choice2 == '2')? choice = '1' : choice = '0'; 
                   
                }else{

                    std::ifstream inFile2;
                    inFile2.open("student.bin", std::ios::binary ); 
                    SMS.show_Student(rollNumber, inFile2);
                    inFile2.close();
                    int new_rollnumber;
                    std::cout << "Enter new credentials.." << std::endl;

                    bool In = SMS.input_d(name, program, batch, class_Section, new_rollnumber);
                    if( In == true )
                {
                    continue;
                }
                    Student S(name, program, class_Section, new_rollnumber, batch);
                    std::ifstream inFile3("student.bin", std::ios::binary);
                    SMS.Editinfo(rollNumber, S , inFile3);
                    inFile3.close();
                    std::cout << "changes have been saved successfully" << std::endl;
                    std::cout << "1. make another change\n0. Home" << std::endl;
                    std::cin >> choice2;
                    (choice2 == '1')? choice = '5' : choice = '0';

                }             
                
                

            }break;
            case '6':
            {
                SMS.Header();
                std::ofstream newfile("student.bin", std::ios::binary | std::ios::trunc);
                std::cout << "Clean file" << std::endl;
                choice = '0';
                
            }break;
            case '7':
            {
                SMS.Header();
                std::cout << "Exporting Student data in .txt file... " <<std::endl;
                std::ofstream outFile;
                outFile.open("student_record.txt");
                std::ifstream inFile4;
                inFile4.open("student.bin", std::ios::binary);
                inFile4.seekg(0, std::ios::beg);
                bool state1 = SMS.exportdata(outFile,inFile4);
                if(state1 == false)
                {
                    std::cout << "Export successful" << std::endl;
                }else
                {
                    std::cout << "Export failed.." << std::endl;
                }
                outFile.close();
                inFile4.close();
                std::cout << "1. Home\n0. Exit" << std::endl;
                std::cin >> choice2;
                (choice2 == '1')? choice = '0' : choice = '8';

            }break;
            case '8':
            {
                
                std::cout << "exiting...";
                return 0;

            }break;
            default:
            {
                
                choice = '0';
            }
        }
    }

    return 0;
}