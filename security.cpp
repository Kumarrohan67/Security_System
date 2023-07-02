#include<iostream>
#include<fstream>//for file hanhling ops
#include<sstream>//provides templetes for inter-ops between string buffers and string objects 
#include<string>
using namespace std;
int main(){
    int a,i=0;
    string text,old,password1,password2,pass,name,password0,age,user,word,word1;
    string creds[2],cp[2];

    cout<<"      Security System"<<'\n';
    cout<<"______________________________"<<endl<<endl;
    cout<<"|         1.Register         |"<<'\n';
    cout<<"|         2.login            |"<<'\n';
    cout<<"|         3.Change Password  |"<<'\n';
    cout<<"|_________4.End Program______|"<<'\n'<<'\n';

 do{
    cout<<'\n'<<'\n';
    cout<<"Enter your coice:-";
    cin>>a;
    switch(a){
        case 1:{
            cout<<"_________________________"<<'\n'<<'\n';
            cout<<"|-------Register--------|"<<'\n';
            cout<<"|_______________________|"<<'\n'<<'\n';
            cout<<"Please Enter Your Username:-";
            cin>>name;
            cout<<"Please Enter the Password:-";
            cin>>password0;
            cout<<"Enter Your Age:-";
            cin>>age;

            ofstream of1;//Creating an object of ofstream(As we need to store things, if we had to only read then we would had created ifstream) class
            of1.open("file.txt");
            if(of1.is_open()){
                of1<<name<<"\n";
                of1<<password0;
                cout<<"Registration Successfull"<<'\n';
            }

            break;
        }
        case 2:{
            i=0;
            cout<<"_______________________________"<<'\n'<<'\n';
            cout<<"|------------Login____________|"<<'\n';
            cout<<"|_____________________________|"<<'\n'<<"\n";

            ifstream of2;
            of2.open("file.txt");
            cout<<"Please Enter the Username:-";
            cin>>user;
            cout<<"Please Enter the Password:-";
            cin>>pass;

            if(of2.is_open()){
                //here while loop together with the getline  is used to read the file line by line
              while(!of2.eof()){
                while(getline(of2,text)){
                    istringstream iss(text);//this object used to stream the string and store the string using the extraction operator
                    iss>>word;
                    creds[i]=word;
                    i++;

                }
                if(user==creds[0] && pass==creds[1]){
                    cout<<"-------Login Successfull-------";
                    cout<<'\n'<<'\n';
                    cout<<" Details:  "<<'\n';
                    cout<<" Username: "+ name<<'\n';
                    cout<<" Password: "+ pass<<'\n';
                    cout<<" Age: "+ age<<'\n';
                }
                else{
                    cout<<'\n'<<'\n';
                    cout<<"Incorrect Credentials"<<'\n';
                    cout<<"|   1. Press 2 to login    |"<<'\n';
                    cout<<"|   2. Press 3 to change password    |"<<'\n';
                    break;
                }

              }
            }
            break;
        }
        case 3:{
         i=0;
         cout<<"-----------------Change Password-------------"<<'\n';
         ifstream of0;
         of0.open("file.txt");
         cout<<"Enter the old Password:-";
         cin>>old;
         if(of0.is_open()){
          while(of0.eof()){
            while(getline(of0,text)){
                istringstream iss(text);
                iss>>word1;
                cp[i]=word;
                i++;
            }
            if(old==cp[1]){
                of0.close();
                ofstream of1;
                if(of1.is_open()){
                    cout<<"Enter Your New Password:-";
                    cin>>password1;
                    cout<<"Enter Your password again:-";
                    cin>>password2;
                    if(password1==password2){
                        of1<<cp[0]<<'\n';
                        of1<<password1;
                        cout<<"password change successfull"<<'\n';
                    }
                    else{
                        of1<<cp[0]<<'\n';
                        of1<<old;
                        cout<<"password do not match"<<'\n';
                    }
                }
            }
            else{
                cout<<"Please Enter a valid password";
                break;
            }
          }
         }
            break;
        }
        case 4:{
            cout<<"___________Thankyou!_________";
            break;
        }
        default:
        cout<<"Enter a valid choice";
    }
 }
 while(a!=4);
 return 0;
}
