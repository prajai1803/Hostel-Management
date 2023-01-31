#include<iostream>
#include<fstream>
#include <string>

class Authentication
{
private:
    bool isLoged = false;
public:
   void createUser(string username,string password);
   bool login(string username,string password);
   void logout();
   bool getStatus();
};

void Authentication::createUser(string username,string password) {
    ifstream input("database/Admin.txt");
    if (input.fail()){
        ofstream admin("database/Admin.txt",ios::app);
        admin<<username<<" "<<password;
        system("clear");
        std::cout<<"Registration Successfully.";
    }
    else{
        std::cout<<"User Alredy Registered, Thanks.";
    }
}

bool Authentication::login(string username,string password){
    int exist;
    string u,p;
    ifstream input("database/Admin.txt");

    while (input>>u>>p)
    {
       if (u==username && p == password){
            exist = 1;
       }
    }
    input.close();
    if (exist == 1){
        cout<<"Hello "<<username<<"\nWe're glad you are here.";
        return true;
    }
    else {
        cout<<"Login Failed\n";
        cout<<"If you haven't registered, register first\n";
        return false;
    }
   
    
}

void Authentication::logout() {

}

bool Authentication::getStatus() {
    ifstream input("database/Admin.txt");
    if (input.fail()) {
        return true;
    }
    else{
        return false;
    }
}





