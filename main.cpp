#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;


int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    cout<<">>";

    string num1 = "start";
    string num2;
    char op;

    cout << " ";
    cin >> num1;
    if(num1!="q"&&num1!="quit"){
        cin >> op;
        cin >> num2;
        cout<<endl;
    }
    else{
        cout<<">>"<< endl;
        cout << "farvel!" << endl;
        cout<<endl;
        return 0;
    }
    // TODO(student): implement the UI
    while(num1!="quit" ||num1!="q"){
        if(op=='+'){
            cout<<"ans ="<<endl;
            cout<<endl;
            try{
                cout << "    " << add(num1, num2) <<endl;
                cout<<endl;
            }
            catch(...){
                cout << "exception caught";
            }
            cout<<">>";
        }
        if(op=='*'){
            cout<<"ans ="<<endl;
            cout<<endl;
            try{
                cout << "    " << multiply(num1, num2) <<endl;
                cout<<endl;
            }
            catch(...){
                cout << "exception caught";
                cout<<endl;
            }
            cout<<">>";
        }
        cout << " ";
        cin >> num1;
        if(num1!="q"&&num1!="quit" ){
        cin >> op;
        cin >> num2;
        cout << endl;
        }
        else{
            cout<<endl;
            cout << "farvel!" << endl;
            return 0;
        }
    }
    
}

