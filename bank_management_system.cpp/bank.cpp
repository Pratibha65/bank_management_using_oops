#include<bits/stdc++.h>
#include<conio.h> //getch()
#include <windows.h>
using namespace std;

class bank{
private:
  float balance;
  string id,pass,name,fname,address,phone, pin;
public:
  void menu();
  void bank_management();
  void atm_management();
  void new_user();
  void already_user();
  void deposit();
  void withdraw();
  void transfer();
  void payment();
  void search();
  void edit();
  void del();
  void show_records();
  void show_payments();
  void user_balance();
  void with_atm();
  void acc_details();
};

void introduction(){
  cout<<"\n\n\n\n\n\t ";
  for(int i=0;i<59;i++) cout<<"*";
  cout<<"\n\t  ";
  for(int i=0;i<57;i++) cout<<"*";
  cout<<"\n\t   ";
  for(int i=0;i<55;i++) cout<<"*";
  cout<<"\n\t ";
  cout<<"\n\n\t\t\t  Bank & ATM Management System\n\n\t\t\t\t Project In C++\n\n\t   ";
  for(int i=0;i<55;i++) cout<<"*";
  cout<<"\n\t  ";
  for(int i=0;i<57;i++) cout<<"*";
  cout<<"\n\t ";
  for(int i=0;i<59;i++) cout<<"*";
  cout<<"\n\t ";
  getch();
  system("cls");

}

void bank::menu(){
  p:
  system("cls");
  int choice;
  char ch1;
  string pin,pass,email;
  cout<<"\n\n\t\t\tControl Panel"<<endl;
  cout<<"\n\n1. Bank Management"<<endl;
  cout<<"\n\n2. ATM Management"<<endl;
  cout<<"\n\n3. Exit"<<endl;

  cout<<"\n\n Enter your choice : "<<endl;
  cin>>choice;
  switch(choice){
    case 1:
      system("cls");
      cout<<"\n\n\t\t\tLogin Account"<<endl;
      cout<<"\n\n E-mail : ";
      cin>>email;
      cout<<"\n\n Pin Code : ";
      for(int i=1;i<=5;i++){
        ch1 = getch();
        pin += ch1;
        cout<<"*";
      }
      cout<<"\n\n Password : ";
      for(int i=1;i<=5;i++){
        ch1 = getch();
        pass+=ch1;
        cout<<"*";
      }
      if(email=="a" && pin=="12345" &&pass=="12345"){
        bank_management();
      }
      else{
        cout<<"\n\n Your E-mail, Pin & Password is wrong"<<endl;
      }
      break;
    case 2:
      atm_management();
      break;
    case 3:
      exit(0);
    default:
    cout<<"\n\n Invalid Value"<<endl;
  }
  getch();
  goto p;
}

void bank::bank_management(){
  p:
  system("cls");
  int choice;
  cout<<"\n\n Bank Management System";
  cout<<"\n\n1. New User";
  cout<<"\n\n2. Already User";
  cout<<"\n\n3. Deposit option";
  cout<<"\n\n4. Withdraw option";
  cout<<"\n\n5. Transfer option";
  cout<<"\n\n6. Payment option";
  cout<<"\n\n7. Search User Record";
  cout<<"\n\n8. Edit User Record";
  cout<<"\n\n9. Delete User Record";
  cout<<"\n\n10. Show All Records";
  cout<<"\n\n11. Show All Payments";
  cout<<"\n\n12. Go Back";


  cout<<"\n\n Enter your choice : ";
  cin>>choice;
  switch(choice){
    case 1:
      new_user();
      break;
    case 2:
      already_user();
      break;
    case 3:
      deposit();
      break;
    case 4:
      withdraw();
      break;
    case 5:
      transfer();
      break;
    case 6:
      payment();
      break;
    case 7:
      search();
      break;
    case 8:
      edit();
      break;
    case 9:
      del();
      break;
    case 10:
      show_records();
      break;
    case 11:
      show_payments();
      break;
    case 12:
      menu();
    default:
      cout<<"\n\n Invalid Value";
  }
  getch();
  goto p;
}

void bank::atm_management(){
  p:
  system("cls");
  int choice;
  cout<<"\n\n ATM Management System"<<endl;
  cout<<"\n\n1. User Login Check Balanace"<<endl;
  cout<<"\n\n2. Withdraw Amount"<<endl;
  cout<<"\n\n3. Account Details"<<endl;
  cout<<"\n\n4. Go Back"<<endl;

  cout<<"\n\n Enter your choice"<<endl;
  cin>>choice;
  switch(choice){
    case 1:
      user_balance();
      break;
    case 2:
      with_atm();
      break;
    case 3:
      acc_details();
      break;
    case 4:
      menu();
    default:
      cout<<"\n\n Invalid Value";
  }
  getch();
  goto p;
}

void bank::new_user(){
  p:
  system("cls");
  fstream file;
  int p;
  float b;
  string n,f,pa,a,ph,i;
  cout<<"\n\n\t\t\tAdd New User";
  cout<<"\n\n User ID : ";
  cin>>id;
  cout<<"\n\n User name : ";
  cin>>name;
  cout<<"\n\n Father's name : ";
  cin>>fname;
  cout<<"\n\n Address : ";
  cin>>address;
  cout<<"\n\n Pin Code (5 digit) : ";
  cin>>pin;
  cout<<"\n\n Password (5 digit) : ";
  cin>>pass;
  cout<<"\n\n Phone No. : ";
  cin>>phone;
  cout<<"\n\n Current Balance : $";
  cin>>balance;
  file.open("bank.txt",ios::in); //in mode - id alredy exists or not
  if(!file){
    file.open("bank.txt",ios::app|ios::out);//appmode,outmode - to write on file
    file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
    file.close();
  }
  else{
    file>>i>>n>>f>>a>>p>>pa>>ph>>b;//input to file
    while(!file.eof()){
      if(i==id){
        cout<<"\n\n User ID already exists.";
        getch();
        goto p;
      }
      file>>i>>n>>f>>a>>p>>pa>>ph>>b;
    }
    file.close();
    file.open("bank.txt",ios::app|ios::out);//appmode,outmode - to write on file
    file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
    file.close();
  }
  cout<<"\n\n Added new user successfully !!";
}

void bank::already_user(){
  system("cls");
  fstream file;
  string t_id;
  int found=0;
  cout<<"\n\n Already User Account";
  file.open("bank.txt",ios::in);//read appmode
  if(!file){
    cout<<"\n\n File Opening Error !";
  }
  else{
    cout<<"\n\n User ID : ";
    cin>>t_id;
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
      if(t_id == id){
        system("cls");
        cout<<"\n\n\t\t User Already Present";
        cout<<"\n\n User ID : "<<id<<"   Pin Code : "<<pin<<"   Password : "<<pass<<endl;
        found++;
        break;
      }
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    if(found==0)
    cout<<"\n\n User ID cannot be found.";
  }
}

void bank::deposit(){
  system("cls");
  fstream file,file1;
  string t_id;
  int found=0;
  float dep;
  cout<<"\n\n\t\t\tDeposit Amount Option";
  file.open("bank.txt",ios::in);
  if(!file){
    cout<<"\n\n File Opening Error !";
  }
  else{
    cout<<"\n\n User ID : ";
    cin>>t_id;
    file1.open("file1.txt",ios::app|ios::out);
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
      if(t_id == id){
        system("cls");
        cout<<"\n\n Enter amount to deposit : $";
        cin>>dep;
        balance+=dep;
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        found++;
        cout<<"\n\n\t\t\t Your Amount $"<<dep<<" Deposited successfully !";
        cout<<"\n\n\t\t\t Your current balance is : $"<<balance;
      }
      else{
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
      }
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("file1.txt","bank.txt");
    if(found==0)
    cout<<"\n\n User not found !";
  }
}

void bank::withdraw(){
  system("cls");
  fstream file,file1;
  string t_id;
  int found=0;
  float with;
  cout<<"\n\n\t\t\tWithdraw Amount Option";
  file.open("bank.txt",ios::in);//read mode
  if(!file){
    cout<<"\n\n File Opening Error !";
  }
  else{
    cout<<"\n\n User ID : ";
    cin>>t_id;
    file1.open("file1.txt",ios::app|ios::out);//write mode
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
      if(t_id == id){
        system("cls");
        cout<<"\n\n Enter amount to withdraw : $";
        cin>>with;
        if(balance>=with){
          balance-=with;
          file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
          cout<<"\n\n\t\t\t Your Amount $"<<with<<" withdrawed successfully !";
          cout<<"\n\n\t\t\t Your current balance is : $"<<balance;
        }
        else{
          file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
          cout<<"\n\n\t\t\t Your Current Balance $"<<balance<<" is LOW!! ";
        }
      }
      else{
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
      }
      found++;
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("file1.txt","bank.txt");
    if(found==0)
    cout<<"\n\n User not found !";
  }
}

void bank::transfer(){
  system("cls");
  fstream file,file1;
  string s_id,r_id;
  float amt;
  int found=0;
  cout<<"\n\n\t\t Payment Transfer Option";
  file.open("bank.txt",ios::in);//read mode
  if(!file){
    cout<<"\n\n File Opening Error !";
  }
  else{
    cout<<"\n\n Sender User ID for transaction : ";
    cin>>s_id;
    cout<<"\n\n Receiver User ID for transaction : ";
    cin>>r_id;
    cout<<"\n\n Amount to transfer : $";
    cin>>amt;
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
      if(s_id==id and amt<=balance){
        found++;
      }
      else if(r_id==id){
        found++;
      }
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    if(found==2){
      file.open("bank.txt",ios::in);
      file1.open("bank1.txt",ios::app|ios::out);
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
      while(!file.eof()){
        if(s_id==id){
          balance -= amt;
          cout<<"\n\n Current Sender's balance is : $"<<balance<<endl;
          file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        }
        else if(r_id==id){
          balance += amt;
          cout<<"\n\n Current Receiver's balance is : $"<<balance<<endl;
          file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        }
        else{
          file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        }
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
      }
      file.close();
      file1.close();
      remove("bank.txt");
      rename("bank1.txt","bank.txt");
    }
    else{
      cout<<"\n\n\t\t Both transaction User IDs not found or balance invalid.";
    }
}
}

void bank::payment(){
    system("cls");
    fstream file,file1;
    int found=0;
    string t_id,b_name;
    float b_amt;
    SYSTEMTIME x;
    cout<<"\n\n\t\t Bills Payment Option";
    file.open("bank.txt",ios::in);
    if(!file){
      cout<<"\n\n File Opening Error !!";
    }
    else{
      cout<<"\n\n Enter User ID : ";
      cin>>t_id;
      cout<<"\n\n Bill Name : ";
      cin>>b_name;
      cout<<"\n\n Bill Amount : $";
      cin>>b_amt;
      file1.open("bank1.txt",ios::app|ios::out);
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

      while(!file.eof()){
        if(t_id == id and b_amt<=balance){
          balance -= b_amt;
          cout<<"\n\n Your current balance is : $"<<balance<<endl;
          found++;
          file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        }
        else{
          file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        }
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
      }
      file.close();
      file1.close();
      remove("bank.txt");
      rename("bank1.txt","bank.txt");
      if(found==1){
        GetSystemTime(&x);
        file.open("bill.txt",ios::app|ios::out);
        file<<t_id<<" "<<b_name<<" "<<b_amt<<" "<<x.wDay<<" "<<x.wMonth<<" "<<x.wYear<<"\n";
        file.close();
        cout<<"\n\n Bill Payed Successfully !!";
      }
      else{
        cout<<"\n\n USER ID or Payment amount invalid !";
      }
    }

}

void bank::search(){
  system("cls");
  cout<<"\n\n\t\t\t Search User Record";
  fstream file;
  int found=0;
  string t_id;
  file.open("bank.txt",ios::in);
  if(!file){
    cout<<"\n\n File Opening Error !!";
  }
  else{
    cout<<"\n\n User ID : ";
    cin>>t_id;
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
      if(t_id==id){
        found++;
        system("cls");
        cout<<"\n\n\t\t\t Record Found !";
        cout<<"\n\n\n User ID : "<<id<<" \tName : "<<name;
        cout<<"\n\n\n "<<"Father's Name : "<<fname<<" \tAddress : "<<address;
        cout<<"\n\n\n"<<" PinCode : "<<pin<<" \tPassword : "<<pass;
        cout<<"\n\n\n Phone No.: "<<phone<<" \tBalance : $"<<balance;
        break;
      }
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    if(found==0)
    cout<<"\n\n User ID not found...!";
  }
}

void bank::edit(){
  system("cls");
  fstream file,file1;
  string t_id;
  int found = 0;
  int p;
  string pa,n,f,a,ph;
  cout<<"\n\n\t\t\tEdit User Record";
  file.open("bank.txt",ios::in);
  if(!file){
    cout<<"\n\n File Opening Error !!";
  }
  else{
    cout<<"\n\n User ID : ";
    cin>>t_id;
    file1.open("bank1.txt",ios::app|ios::out);
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
      if(t_id==id){
        cout<<"\n\n User name : ";
        cin>>n;
        cout<<"\n\n Father's name : ";
        cin>>f;
        cout<<"\n\n Address : ";
        cin>>a;
        cout<<"\n\n Pin Code (5 digit) : ";
        cin>>p;
        cout<<"\n\n Password : ";
        cin>>pa;
        cout<<"\n\n Phone No. : ";
        cin>>ph;
        file1<<" "<<id<<" "<<n<<" "<<f<<" "<<a<<" "<<p<<" "<<pa<<" "<<ph<<" "<<balance<<"\n";
        cout<<"\n\n Record Successfully Updated !!";
        found++;
      }
      else{
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
      }
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("bank1.txt","bank.txt");

    if(found==0)
    cout<<"\n\n User ID not found !!";
  }
}

void bank::del(){
  system("cls");
  fstream file,file1;
  string t_id;
  int found = 0;
  cout<<"\n\n\t\t\tDelete User Record";
  file.open("bank.txt",ios::in);
  if(!file){
    cout<<"\n\n File Opening Error !!";
  }
  else{
    cout<<"\n\n User ID : ";
    cin>>t_id;
    file1.open("bank1.txt",ios::app|ios::out);
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
      if(t_id==id){
        cout<<"\n\n Record Successfully Deleted !!";
        found++;
      }
      else{
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
      }
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("bank1.txt","bank.txt");

    if(found==0)
    cout<<"\n\n User ID not found !!";
  }
}

void bank::show_records(){
  system("cls");
  cout<<"\n\n\t\t\tShow All User Records !";
  fstream file;
  int found=0;
  file.open("bank.txt");
  if(!file){
    cout<<"\n\n File Opening Error !";
  }
  else{
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){

        cout<<"\n\n\n User ID : "<<id;
        cout<<"\n\n\n Name : "<<name;
        cout<<"\n\n\n Father Name : "<<fname;
        cout<<"\n\n\n Address : "<<address;
        cout<<"\n\n\n PinCode : "<<pin;
        cout<<"\n\n\n password : "<<pass;
        cout<<"\n\n\n Phone No. : "<<phone;
        cout<<"\n\n\n Current Balance : "<<balance;
        cout<<"\n\n==================================================";
        found++;
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
      }

    }
    file.close();
    if(found==0)
    cout<<"\n\n Data Base Empty !!";
  }


void bank::show_payments(){
  system("cls");
  cout<<"\n\n\t\t\tShow All Payment Records !";
  fstream file;
  int found=0,c_date,c_month,c_year;
  float b_amt;
  string t_id,b_name;
  file.open("bill.txt",ios::in);
  if(!file){
    cout<<"\n\n File Opening Error !";
  }
  else{
    file>>t_id>>b_name>>b_amt>>c_date>>c_month>>c_year;
    while(!file.eof()){

        cout<<"\n\n\n User ID : "<<t_id;
        cout<<"\n\n\n Bill Name : "<<b_name;
        cout<<"\n\n\n Bill Amount : "<<b_amt;
        cout<<"\n\n\n Date : "<<c_date<<"/"<<c_month<<"/"<<c_year;

        cout<<"\n\n==================================================";
        found++;
        file>>t_id>>b_name>>b_amt>>c_date>>c_month>>c_year;
      }
  }
  file.close();
  if(found==0)
  cout<<"\n\n Data Base Empty !!";
}

void bank::user_balance(){
  system("cls");
  fstream file;
  string t_id,t_pass,t_pin;
  char ch;
  int found=0;
  cout<<"\n\n\t\t\t User Login and Check Balance";
  file.open("bank.txt",ios::in);
  if(!file){
    cout<<"\n\n file Opening Error";
  }
  else{
    cout<<"\n\n User ID : ";
    cin>>t_id;
    cout<<"\n\n Pin Code : ";
    for(int i=1;i<=5;i++){
      ch = getch();
      t_pin += ch;
      cout<<"*";
    }
    cout<<"\n\n Password : ";
    for(int i=1;i<=5;i++){
      ch = getch();
      t_pass += ch;
      cout<<"*";
    }

    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
        if(t_id == id and t_pin == pin and t_pass == pass){
          cout<<"\n\n\t\t\t Current Balance : $"<<balance;
          found++;
        }
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
      }
      file.close();
      if(found==0)
      cout<<"\n\n\t\t\t User ID, Pin and Password not matching !!";
  }
}

void bank::with_atm(){
  system("cls");
  cout<<"\n\n\t\t\t Withdraw Amount";
  fstream file,file1;
  string t_id,t_pin,t_pass;
  int found=0;
  char ch;
  float with;
  file.open("bank.txt",ios::in);//read mode
  if(!file){
    cout<<"\n\n File Opening Error !";
  }
  else{
    cout<<"\n\n User ID : ";
    cin>>t_id;
    cout<<"\n\n Pin Code : ";
    for(int i=0;i<5;i++){
      ch = getch();
      t_pin += ch;
      cout<<"*";
    }
    cout<<"\n\n Password : ";
    for(int i=0;i<5;i++){
      ch = getch();
      t_pass += ch;
      cout<<"*";
    }
    file1.open("file1.txt",ios::app|ios::out);//write mode
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
      if(t_id == id and t_pin == pin and t_pass == pass){
        system("cls");
        cout<<"\n\n Enter amount to withdraw : $";
        cin>>with;
        if(balance>=with){
          balance-=with;
          file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
          cout<<"\n\n\t\t\t Your Amount $"<<with<<" withdrawed successfully !";
          cout<<"\n\n\t\t\t Your current balance is : $"<<balance;
        }
        else{
          file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
          cout<<"\n\n\t\t\t Your Current Balance $"<<balance<<" is LOW!! ";
        }
      }
      else{
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
      }
      found++;
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("file1.txt","bank.txt");
    if(found==0)
    cout<<"\n\n User not found !";
  }
}

void bank::acc_details(){
  system("cls");
  cout<<"\n\n\t\t\t Account Details";
  fstream file;
  string t_id,t_pin,t_pass;
  int found=0;
  char ch;
  file.open("bank.txt",ios::in);//read mode
  if(!file){
    cout<<"\n\n File Opening Error !";
  }
  else{
    cout<<"\n\n User ID : ";
    cin>>t_id;
    cout<<"\n\n Pin Code : ";
    for(int i=0;i<5;i++){
      ch = getch();
      t_pin += ch;
      cout<<"*";
    }
    cout<<"\n\n Password : ";
    for(int i=0;i<5;i++){
      ch = getch();
      t_pass += ch;
      cout<<"*";
    }
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
      if(t_id == id and t_pin == pin and t_pass == pass){
        system("cls");
        cout<<"\n\n Account Details : ";
        cout<<"\n\n\n User ID : "<<id;
        cout<<"\n\n\n Name : "<<name;
        cout<<"\n\n\n Father Name : "<<fname;
        cout<<"\n\n\n Address : "<<address;
        cout<<"\n\n\n PinCode : "<<pin;
        cout<<"\n\n\n password : "<<pass;
        cout<<"\n\n\n Phone No. : "<<phone;
        cout<<"\n\n\n Current Balance : "<<balance;
        cout<<"\n\n==================================================";
        found++;
      }
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    if(found==0)
    cout<<"\n\n User not found !";
  }
}


int main(){
  bank obj;
  introduction();
  obj.menu();
}
