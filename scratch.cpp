#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

class student
{
    private:
        int id,age;
        std::string name;

    public:
        student(int sId, std::string sName, int sAge) //constructor
        {
            id=sId;
            name = sName;
            age = sAge;
        }

        //Open Record Functions
        int getId()
            {return id;}
        std::string getName()
            {return name;}
        int getAge()
            {return age;}

        //Update Records Functions
        void setId(int sId)
            {id = sId;}
        void setName(std::string sName)
            {name=sName;}
        void setAge(int sAge)
            {age=sAge;}

        //Print Record
        void printStudent()
        {
            std::cout<<"\t\t| "<<id<<"| "<<name<<"| "<<age<<"|\n";
        }

};

void showStudents(std::vector<student> &students)
{
    if(students.empty())
    {
        std::cout<<"\t\t No students found \t\t\n";
    }
    else
    {
        for(int i=0; i<students.size(); i++)
        {
            students[i].printStudent();
        }
    }
}

void searchStudent(std::vector<student> &students)
{
    int sId;
    bool found = false;

    std::cout<<"\t\t Enter student ID:";
    std::cin>>sId;

    for(int i=0; i<students.size(); i++)
    {
        if(students[i].getId() == sId)
        {
            found = true;
            std::cout<<"\t\t --------Student Found ------------"<<"\n";
            students[i].printStudent();
        }
    }

    if(!found)
    {
        std::cout<<"\t\t Record Not Found"<<"\n";
        return;
    }

}

void updateStudent(std::vector<student> &students)
{
    std::string sName;
    bool found = true;
    int choice;

    std::cout<<"\t\tEnter Name to Update Record :";
    std::cin.ignore();
    std::cin>>sName;

    for(int i=0; i<students.size(); i++)
    {
        if(students[i].getName()==sName)
        {
            found = true;

            std::cout<<"\t\t---Student Found -----"<<"\n";
			std::cout<<"\t\t 1. Update ID "<<"\n";
			std::cout<<"\t\t 2. Update Name "<<"\n";
			std::cout<<"\t\t 3. Update Age "<<"\n";
			std::cout<<"\t\t Enter Your Choice :";
            std::cin>>choice;

            switch (choice)
            {
                case 1:
                {
                    int num;
				    std::cout<<"\t\t Enter New ID :";
				    std::cin>>num;
				    students[i].setId(num);
                    break;
                }
                case 2:
                {
                    std::string name;
				    std::cout<<"\t\t Enter New Name :";
                    std::cin.ignore();
				    std::cin>>name;
				    students[i].setName(name);
                    break;
                }
                case 3:
                {
                    int num;
				    std::cout<<"\t\t Enter New Age :";
				    std::cin>>num;
				    students[i].setAge(num);
                    break;
                }
                default:
                    std::cout<<"\t\t Invalid Number\n";
                    break;
            }
        }
    }

    if(!found)
    {
        std::cout<<"\t\t Record Not Found"<<"\n";
        return;
    }
}

void addStudent(std::vector<student> &students)
{
    int Id,age;
	std::string name;
	std::cout<<"\t\t Enter ID :";
	std::cin>>Id;

	//check if student already exit
	for(int i = 0; i<students.size();i++)
    {
		if(students[i].getId() == Id)
        {
			std::cout<<"\t\t Student Already Exists"<<"\n";
			return;
		}

	}

	std::cout<<"\t\t Enter Name : ";
	std::cin>>name;
	std::cout<<"\t\t Enter Age : ";
	std::cin>>age;

	student newStudent(Id,name,age);
	students.push_back(newStudent);
}

void deleteStudent(std::vector<student> &students)
{
    std::string name;
    bool found = false;
	std::cout<<"\t\t Enter Name to Delete :";
	std::cin.ignore();
	getline(std::cin,name);

	for(int i = 0; i<students.size();i++)
    {
		if(students[i].getName() == name)
        {
            found = true;
			students.erase((students.begin()+i));
			std::cout<<"\t\t Student Remove Successfully\n";
		}

	}
    if(!false)
    {
        std::cout<<"\t\t Record Not Found\n";
        return;
    }
}

int main()
{
    std::vector <student> students;
	students.push_back(student(1,"Ali",13));
	char choice;
    
    do{

		//system("cls");
		int op;
		std::cout<<"\n\t\t--------------------------------\n";
		std::cout<<"\t\t*** Student Management System ***\n";
		std::cout<<"\t\t--------------------------------\n";
		std::cout<<"\t\t 1. Add New Student\n";
		std::cout<<"\t\t 2. Display All Student\n";
		std::cout<<"\t\t 3. Search Student\n";
		std::cout<<"\t\t 4. Update Student\n";
		std::cout<<"\t\t 5. Delete Student\n";
		std::cout<<"\t\t 6. Exit\n";
		std::cout<<"\t\t Enter Your Choice : ";
		std::cin>>op;

		switch(op)
        {
			case 1:
				addStudent(students);
				break;
			case 2:
				showStudents(students);
				break;
			case 3:
				searchStudent(students);
				break;	
			case 4:
			    updateStudent(students);
				break;	
			case 5:
			     deleteStudent(students);
				 break;	
			case 6:
				exit(1);
			default:
				std::cout<<"\t\t Invalid Number\n";		
	   }

	   std::cout<<"\t\t Do You Want to Continue [Yes/No] ? :";
	   std::cin>>choice;
	}while(choice == 'y'||choice=='Y');	


    return 0;
}