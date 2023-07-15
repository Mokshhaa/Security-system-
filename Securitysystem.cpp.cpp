#include<iostream>//lib for I/O operations
#include<fstream>//to work on files i.e file handling
#include<sstream>//for string handling i.e string buffers and string files
#include<string>

using namespace std;

int main()
{
    int a, i=0;
    string text, old, pwd1, pwd2, pass, name, pwd0, age, user, word, word1;
    string creds[2], cp[2];

    cout<<"     Security System   "<<endl;       //For the interface. design of your choice
    cout<<"|__________________________________|"<<endl;
    cout<<"|             1.Register           |"<<endl;
    cout<<"|             2.Login              |"<<endl;
    cout<<"|             3.Change Password    |"<<endl;
    cout<<"|_____________4.End Program________|"<<endl<<endl;
    
    do{  //To ask the user to select one of the 4 options above
        cout<<endl<<endl;
        cout<<"Enter your choice:  ";
        cin>>a;
        switch(a){
            case 1:{
                cout<<"|______________________________|"<<endl<<endl;// create another interface for registration
                cout<<"|-----------Register-----------|"<<endl;
                cout<<"|______________________________|"<<endl<<endl;
                cout<<"Please enter username: ";
                cin>>name;
                cout<<"Please enter your password: ";
                cin>>pwd0;
                cout<<"Please enter your age: ";
                cin>>age;//can take any personel details you want
                                             //We have to store these details in a file so we have to do file handling operations
                ofstream of1;// create an object of1 to open ofstream class. ofstream class is used for wrinting purpose
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<pwd0;
                    cout<<"Registration successfull"<<endl;
                }
              break;
            }
            case 2:{
                i=0;

                cout<<"|_________________________________|"<<endl<<endl;
                cout<<"|------------Login----------------|"<<endl;
                cout<<"|_________________________________|"<<endl<<endl;

                //ifstream is used to read from files
                ifstream of2;
                of2.open("file.txt");
                cout<<"Please enter the username: ";
                cin>>user;
                cout<<"Please enter the Password: ";
                cin>>pass;

                if(of2.is_open()){
                    while(!of2.eof())               //endoffile function to detect when eof is reached. It returns non zero when eof is reached else returns 0
                    {
                        while(getline(of2, text)){    //getline is used to read the file line by line
                        istringstream iss(text);      //istringstream iss is used to stram the string and store it
                         iss>>word;                    //extraction operator to store the string
                         creds[i]=word;            //store the credentials i.e an array    //word is the extraction operator 
                         i++;                           //To increment. 1st username will be stored then pwd so we need to increment that
                    }

                    if(user==creds[0] && pass==creds[1]){
                        cout<<"|-----Log in Successfull-----|";//username entered must be at the 0th position             //check if reg user name matches with the entered username. same with pwd
                        cout<<endl<<endl;

                        cout<<"Details: "<<endl;

                        cout<<"Username: "+ name<<endl;
                        cout<<"Password: "+ pass<<endl;
                        cout<<"Age: "+age<<endl;
                    }
                    else{
                        cout<<endl<<endl;
                        cout<<"Incorrect Credentials"<<endl;
                        cout<<"|          1. Press 2 to Login                 |"<<endl;
                        cout<<"|          2. Press 3 to change password       |"<<endl;
                        break;
                    }
                }
            }
            break;
            }
            case 3:{
                i=0;
                cout<<"|--------------------Change password-----------------|"<<endl;

                ifstream of0;
                of0.open("file.txt");       //
                cout<<"Enter the old password: ";
                cin>>old;
                if(of0.is_open()){
                    while(of0.eof()){
                        while(getline(of0, text)){
                            istringstream iss(text);
                            iss>>word1;                 //store string in word1
                            cp[i]=word1;
                            i++;
                        }

                        if(old==cp[1]){
                            of0.close();     //if old pw= new close that file and open another
                            ofstream of1;
                            if(of1.is_open())
                            {
                                cout<<"Enter your new password: ";
                                cin>>pwd1;
                                cout<<"Enter your password again: ";
                                cin>>pwd2;
                                if(pwd1==pwd2){
                                    of1<<cp[0]<<"\n";
                                    of1<<pwd1;
                                    cout<<"Password changed successfully"<<endl;
                                }
                                else{
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password does not match"<<endl;
                                }
                            }
                        }
                        else{
                            cout<<"Please enter a valid password"<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                cout<<"|_______________Thank you!_________________|";
                break;
            }
                default:
                cout<<"Enter a valid choice";
        }
        }

while(a!=4);                  //while of do created at the first keeps on repeating until a !=4
return 0;
}
