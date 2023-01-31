#include<iostream>
#include<string>


#include "./logo.h"
#include "./auth/authentication.h"
#include "./hostel.h"


using namespace std;


void hostelBuild(){
    int n,pre,flag=0;

    hostel ob1;

    ob1.get_roominfo();
    ob1.get_studentinfo();

    ob1.welcome();
    ob1.header();

    printf("\t\t\t\tPlease Select Any Option: ");


    while(cin >> n)
    {
        pre=n;
        printf("\n\t==========================================================================================================\n\n");
        flag=0;
        //student option
        if(pre==11)
        {

            ob1.display_student();
        }
        else if(pre==12)
        {
            ob1.add_student();

        }
        else if(pre==13)
        {
            ob1.search_student();
        }

        else if(pre==14)
        {
            ob1.update_student();
        }
        else if(pre==15)
        {
            ob1.delete_student();
        }

        //ens student option

        else if(pre==21)
        {
            ob1.display_room();
        }
        else if(pre==22)
        {
            ob1.add_room();
        }
        else if(pre==23)
        {
            ob1.search_room();
        }
        else if(pre==24)
        {
            ob1.update_room();
        }
        else if(pre==25)
        {
            ob1.delete_room();
        }
        else if(pre==31)
        {
            ob1.available_room();
        }
        else if(pre==32)
        {
            ob1.search_student();
        }

        //end room object

        else if(pre==0)
        {
            ob1.program_close();
            break;
        }
        else if(pre==1)
        {
            flag=1;
            ob1.header();
        }
        else
        {
            flag=1;
            printf("\t\t\t\t\t\tYou Press Wrong Option\n\n");
            ob1.header();
        }

        if(flag!=1)
            printf("\n\t\t\t\tAre You Want To See Dashboard if Yes) 1 or No) 0 : ");
        else     printf("\t\t\t\tPlease Select Any Option: ");

    }
}

void loginPage() {
    Authentication auth;
    system("clear");
    string username,password;
    cout<<"Enter Username : ";
    cin>>username;
    cout<<"Enter Password : ";
    cin>>password;
    if (auth.login(username,password)){
        system("clear");
        system("cls");
        hostelBuild();
    }
}

void registerPage(){
    Authentication auth;
    if (auth.getStatus()){
        system("clear");
        string username,password;
        cout<<"Enter Username : ";
        cin>>username;
        cout<<"Enter Password : ";
        cin>>password;
        auth.createUser(username,password);
    }
    else{
        std::cout<<"user already register";
    }
    
    
}


void AuthenticationPage() {
    int choice;
    cout<<"########### LOGIN ###########\n";
    cout<<"1.Login\n";
    cout<<"2.Register\n";
    cout<<"3.Exit\n\n\n";
    cout<<"Enter Your Choice :";
    cin>>choice;
    switch (choice)
    {
    case 1:
        loginPage();
        break;
    case 2:
        registerPage();
        break;
    case 3:
        cout<<"Thanks for using.";
        break;
    
    default:
        cout<<"\n\nYou have selected wrong choice select again \n\n\n.";
        AuthenticationPage();
    }
}





int main() {
    Authentication auth;
    Logo l;
    l.show();
    AuthenticationPage();

    return 0;
}