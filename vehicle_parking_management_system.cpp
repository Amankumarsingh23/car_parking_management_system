#include<iostream>
using namespace std;
int main (){
    int user_input;
    int amount=0;
    int count =0;
    while(true){
        cout<<"\n";
        cout<<"VEHICLE---------PARKING----------SYSTEM"<<endl;
        cout<<"\nEnter the number accordingly to park your vehicle\n";
        cout<<"1. For AutoRickshaw"<<endl;
        cout<<"2. For Car"<<endl;
        cout<<"3. For Bus"<<endl;
        cout<<"4. To show Record"<<endl;
        cout<<"5. To delete Record"<<endl;
        cout<<"6. To exit\n"<<endl;

        cin >>user_input;

        if (user_input==1){
            count ++;
            amount+=100;
            cout<<"AutoRickshaw parked\n"<<endl;


        }
        else if (user_input==2){
            count ++;
            amount+=200;
            cout<<"Car parked\n"<<endl;
        }
        else if (user_input ==3){
            count ++;
            amount+=300;
            cout<<"Bus parked\n"<<endl;
        }
        else if (user_input ==4){
            cout<<"TOTAL AMOUNT IS :"<< amount <<endl;
            cout<< "THE NUMBER OF VEHICLE PARKED IS : "<< " "<<count<<endl;

        }
        else if (user_input ==5){
            amount =0;
            count =0;
        }
        else if (user_input ==6){
            cout<<"THANK YOU\n"<<endl;
        }
        else{
            cout<<"Invalid input\n"<<endl;
        }
        


    


    }
}