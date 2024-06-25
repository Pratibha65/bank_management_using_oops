#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
        int rollno,age;
        string name;
    public:
        Student(int stdrollno,int stdage,string stdname){
            rollno = stdrollno;
            name = stdname;
            age=stdage;
            }

            void setRollno(int stdrollno){
                rollno = stdrollno;
            }
            int getRollno(){return rollno;}

            void setName(string stdname){
                name = stdname;
            }
            string getName(){return name;}
            void setAge(int stdage){
                age=stdage;
            }
            int getAge(){return age;}
            void displayStudent(){
              cout<<"RollNO : "<<rollno<<endl;
              cout<<"Name : "<<name<<endl;
              cout<<"Age : "<<age<<endl;
            }
};

void deleteStudent(vector<Student>& students){
  string name;
  cout<<"Enter name to delete record : "<<endl;
  cin.ignore();
  getline(cin,name);
  for(int i=0;i<students.size();i++){
    if(students[i].getName()==name){
      students.erase((students.begin()+i));
      return;
    }
  }
  cout<<"\t\t Not found"<<endl;
  return;
}

void updateStudent(vector<Student>& students){
  // int rollno,age;
  // cout<<"\t\t Enter rollno : "<<endl;
  // cin>>rollno;
  // string name;
  //
  // for(int i=0;i<students.size();i++){
  //   if(students[i].getRollno()==rollno){
  //     cout<<"Enter updated name : "<<endl;
  //     cin>>name;
  //     cout<<"Enter updated age : "<<endl;
  //     cin>>age;
  //     students[i].setName(name);
  //     students[i].setAge(age);
  //     cout<<"\t\t --------------Updation successful-----------"<<endl;
  //     students[i].displayStudent();
  //     return;
  //   }
  // }
    string sname;
    bool found=false;
    cout<<"\t\t Enter name to update record : "<<endl;
    cin.ignore();
    getline(cin,sname);

    for(int i=0;i<students.size();i++){
      if(students[i].getName()==sname){
        found=true;
        cout<<"\t\t ------------Student Found-----------"<<endl;
        cout<<"\t\t 1.Update Roll No"<<endl;
        cout<<"\t\t 2.Update Name"<<endl;
        cout<<"\t\t 3.Update Age"<<endl;

        cout<<"Enter your choice : "<<endl;
        int choice;cin>>choice;

        switch(choice){
          case 1:{
            int rno;
            cout<<"\t\t Enter your roll no : "<<endl;
            cin>>rno;
            students[i].setRollno(rno);
            break;
          }
          case 2:{
            string name;
            cout<<"\t\t Enter new Name : "<<endl;
            cin.ignore();
            getline(cin,name);
            students[i].setName(name);
            break;
          }
          case 3:{
            int age;
            cout<<"\t\t Enter new Age : "<<endl;
            cin>>age;
            students[i].setAge(age);
            break;
          }
          default:
            cout<<"\t\t Invalid Number"<<endl;
        }
      }}
if(!found){
        cout<<"\t\t Record not found"<<endl;
      }
        return;



}

void searchStudent(vector<Student>& students){
  int rollno;
  cout<<"\t\t Enter Roll No : "<<endl;
  cin>>rollno;

  for(int i=0;i<students.size();i++){
    cout<<"yes"<<" "<<students.size()<<endl;

    cout<<students[i].getRollno()<<endl;
    if(students[i].getRollno()==rollno){
      cout<<"\t\t --------------------Student Found--------------------"<<endl;
      students[i].displayStudent();
      return;
    }

  }

    cout<<"\t\t ---------Student not found------------"<<endl;
    return;

}

void displayAllStudent(vector<Student>& students){
  if(students.empty()){
    cout<<"\t\t No registrations"<<endl;
    return;
  }
  for(int i=0;i<students.size();i++){
    students[i].displayStudent();
    cout<<endl;
  }
}
void addNewStudent(vector<Student> &students){
    int rollno,age;
    string name;
    cout<<"Enter RollNo."<<endl;
    cin>>rollno;

    //check if rollno. unique
    for(int i=0;i<students.size();i++){
      if(students[i].getRollno()==rollno){
        cout<<"\t\t Student already registered"<<endl;
        return;
      }
    }

    cout<<"Enter Name"<<endl;
    cin>>name;
    cout<<"Enter Age"<<endl;
    cin>>age;

    Student newStudent(rollno,age,name);
    students.push_back(newStudent);

    cout<<"\t\t Successful"<<endl;

}
int main(){
    vector<Student> students;
    students.push_back(Student(1,20,"Anshika"));

    char choice;
    do{
      system("cls");
      int op;
      cout<<"\t\t ---------------------------------------------"<<endl;
      cout<<"\t\tStudent Management System"<<endl;
      cout<<"\t\t ---------------------------------------------"<<endl;

      cout<<"\t\t 1.Add new student"<<endl;
      cout<<"\t\t 2.Display all students"<<endl;
      cout<<"\t\t 3.Search student"<<endl;
      cout<<"\t\t 4.Update students"<<endl;
      cout<<"\t\t 5.Delete students"<<endl;
      cout<<"\t\t 6.Exit"<<endl;
      cout<<"\t\t Enter your options"<<endl;
      cin>>op;
      switch(op){
        case 1:
          addNewStudent(students);
          break;
        case 2:
          displayAllStudent(students);
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
        daefault:
          cout<<"\t\tInvalid Number"<<endl;
      }
      cout<<"\t\t Do you want to continue [Yes/No] ? : ";
      cin>>choice;
    }while(choice=='y'||choice=='Y');

}
