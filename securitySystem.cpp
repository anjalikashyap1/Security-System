#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
 using namespace std;

 int main()
 {

int a,i=0;
string text,old,password1,password2,pass,name,password0,age,user,word,word1;
string creds[2],cp[2];

cout<<"\n\n\t\t\t ________________________________________________________________________________________";
 cout<<"\n\t\t\t|                                                                                        |";                    
 cout<<"\n\t\t\t|---------------------------------SECURITY SYSTEM----------------------------------------|";                            
 cout<<"\n\t\t\t|________________________________________________________________________________________|";
 cout<<"\n\t\t\t|                                                                                        |";
 cout<<"\n\t\t\t|  1) Registration                                                                       |";
 cout<<"\n\t\t\t|  2) Login                                                                              |";
 cout<<"\n\t\t\t|  3) Change Password                                                                    |";
 cout<<"\n\t\t\t|  4) Exit                                                                               |";
 cout<<"\n\t\t\t|________________________________________________________________________________________|";
 

    do{
        cout<<"\n\n\n\t\t\tEnter your Choice: ";
        cin>>a;

        switch(a)
        {
            case 1:
               {
                cout<<"\n\n\t\t\t ______________________________________________________________________________";
                 cout<<"\n\t\t\t|------------------------------------Registration------------------------------|";                                           
                 cout<<"\n\t\t\t|______________________________________________________________________________|";
                 cout<<"\n\t\t\t|  Please Enter Username:  ";
                 cin>>name;
                 cout<<"\n\t\t\t|______________________________________________________________________________|";
                 cout<<"\n\t\t\t|  Please Enter Password:  ";
                 cin>>password0;
                 cout<<"\n\t\t\t|______________________________________________________________________________|";
                 cout<<"\n\t\t\t|  Please Enter Your Age:   ";
                 cin>>age;
                 cout<<"\n\t\t\t|______________________________________________________________________________|";

                 ofstream of1;
                 of1.open("file.txt");
                 if(of1.is_open())
                 {
                    of1<<name<<"\n";
                    of1<<password0<<"\n";
                    cout<<"\n\n\t\t\t ______________________________________________________________________________";
                     cout<<"\n\t\t\t|----------------------------Registration Successful !-------------------------|";                                           
                     cout<<"\n\t\t\t|______________________________________________________________________________|";
                 }
                 break;
               }

             case 2:
                 {
                    cout<<"\n\n\t\t\t ______________________________________________________________________________";
                     cout<<"\n\t\t\t|------------------------------------Login-------------------------------------|";                                           
                     cout<<"\n\t\t\t|______________________________________________________________________________|";
                     cout<<"\n\t\t\t|  Please Enter Username:  ";
                    cin>>user;
                     cout<<"\n\t\t\t|______________________________________________________________________________|";
                     cout<<"\n\t\t\t|  Please Enter Password:  ";
                     cin>>pass;
                     cout<<"\n\t\t\t|______________________________________________________________________________|";

                     ifstream of2;
                     of2.open("file.txt");
                     if(of2.is_open())
                     {
                        while(!of2.eof())
                        {
                             for (int j = 0; j < 2; j++)
                             {
                              creds[j] = "";
                             }
                                i = 0;
                            while(getline(of2,text))
                            {
                                istringstream iss(text);
                                string word;
                                iss>>word;
                                creds[i]=word;
                                i++;
                            }
                            if(creds[0]==user && creds[1]==pass)
                            {
                                cout<<"\n\n\t\t\t ______________________________________________________________________________";
                                 cout<<"\n\t\t\t|--------------------------Login Successful------------------------------------|";  
                                 cout<<"\n\t\t\t|______________________________________________________________________________|";                                         
                                 cout<<"\n\t\t\t|______________________________Details_________________________________________|";
                                 cout<<"\n\n\t\t\tUser Name: "<<name;
                                 cout<<"\n\t\t\t  Password : "<<pass;
                                 cout<<"\n\t\t\t      Age  : "<<age;
                                 
                            }
                            else
                            {
                                cout<<"\n\n\t\t\tWrong Credentials !";
                                cout<<"|\n\n\t\t\tPress 2 to login              |";
                                cout<<"|\n\n\t\t\tPress 3 change password       |";
                                break;
                            
                            }

                        }
                     }

                     break;
                 }  
                 case 3:
                    {
                        i=0;
                        cout<<"\n\n\t\t\t--------------------------------Change Password---------------------------------------";

                        ifstream of0;
                        of0.open("file.txt");
                        cout<<"\n\n\t\t\tEnter the old password:  ";
                        cin>>old;
                        if(of0.is_open())
                        {
                            while(!of0.eof())
                            {
                                while(getline(of0,text)){
                                 istringstream iss(text);
                                iss>>word1;
                                cp[i]=word1;
                                i++;
                                }

                            if(old==cp[1])
                            {
                                of0.close();
                                ofstream of1("file.txt");
                                if(of1.is_open())
                                {
                                    cout<<"\n\n\t\t\tEnter new password:       ";
                                    cin>>password1;
                                    cout<<"\n\n\t\t\tEnter new password again: ";
                                    cin>>password2;

                                    if(password1==password2)
                                    {
                                       of1<<cp[0]<<"\n";
                                       of1<<password1;
                                       cout<<"\n\n\t\t\t-------------------Password change successfully---------------------";

                                    }
                                    else
                                    {
                                       of1<<cp[0]<<"\n";
                                       of1<<old;
                                       cout<<"\n\n\t\t\t--------------------Password do not match---------------------------";
                                    }

                               }
                                
                            }
                            else
                            {
                                cout<<"\n\n\t\t\t-----Please Enter valid password !";
                                break;
                            }
                        }
                        }
                        break;
                    }
                    case 4:
                    {
                        cout<<"\n\n\t\t\t______________________________________THANK YOU___________________________________________";
                        break;
                    }
                    default:
                        cout<<"\n\n\t\t\tPlease Enter VAlid Choice !";    
        }
    }
    while(a!=4);
    return 0;
 }