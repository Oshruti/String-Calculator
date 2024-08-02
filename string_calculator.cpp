#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    if(digit=='0'||digit=='1'||digit=='2'||digit=='3'||digit=='4'||digit=='5'
    ||digit=='6'||digit=='7'||digit=='8'||digit=='9'){
        return digit - '0';
    }
    else{
        throw std::invalid_argument("not decimal");
    }
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    if(decimal>9){
        throw std::invalid_argument("Not a digit");
    }
    char digit = decimal + '0';
    return digit;
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
    unsigned int i = 0;
    if(num.at(0)=='-'){
        i = 1;
    }
    while(i<num.size()&&num.at(i)== '0' ){
        i++;
    }
    if(i==num.size()){return "0";}
    if(num.at(0)=='-'){
        num = num.erase(1, i-1);
    }
    else{
        num = num.erase(0, i);
    }
    return num;
}

string add(string lhs, string rhs) {
    // TODO(student): implement
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    string lhs1 =  lhs;
    string rhs1 = rhs;
    if(lhs.at(0)=='-' && rhs.at(0)=='-'){
        lhs = lhs.substr(1);
        rhs = rhs.substr(1);
    }

    unsigned int i=1;
    string solution = "";
    int additive = 0;
    int digit=0;
    do{

        int digit = digit_to_decimal(lhs.at(lhs.size()-i))+digit_to_decimal(rhs.at(rhs.size()-i))+additive;
        if(digit<9){
            solution.insert(0, string(1, decimal_to_digit(digit)));
            additive = 0;
        }
        else{
            solution.insert(0, string(1, decimal_to_digit(digit%10)));
            additive = digit/10;
        }
        i++;
    }while(i<=lhs.size()&&i<=rhs.size());

    if(rhs.size()==lhs.size()&&additive!=0){
        solution.insert(0, string(1, decimal_to_digit(additive)));
    }

    if(rhs.size()>lhs.size()){
        unsigned int j = 1;
        while(j<=rhs.size()-lhs.size()){
            digit = digit_to_decimal(rhs.at(rhs.size()-lhs.size()-j))+additive;
            if(digit<9){
                solution.insert(0, string(1, decimal_to_digit(digit)));
                additive = 0;
            }
            else{
                solution.insert(0, string(1, decimal_to_digit(digit%10)));
                additive = digit/10;
            }
            j++;
        }
        if(additive!=0){
            solution.insert(0, string(1, decimal_to_digit(additive)));
        }
    }

    if(lhs.size()>rhs.size()){
        unsigned int j = 1;
        while(j<=lhs.size()-rhs.size()){
            digit = digit_to_decimal(lhs.at(lhs.size()-rhs.size()-j))+additive;
            if(digit<9){
                solution.insert(0, string(1, decimal_to_digit(digit)));
                additive = 0;
            }
            else{
                solution.insert(0, string(1, decimal_to_digit(digit%10)));
                additive = digit/10;
            }
            j++;
        }
        if(additive!=0){
            solution.insert(0, string(1, decimal_to_digit(additive)));
        }
    }
    
    if(lhs1.at(0)=='-' && rhs1.at(0)=='-'){
        solution.insert(0, string(1, '-'));
    }
    return solution;
}

string multiply(string lhs, string rhs) {
    // TODO(student): implement
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    string lhs1 =  lhs;
    string rhs1 = rhs;

    string solution = "0";
    int digit = 0;
    int additive = 0;
    int counter=0;

    if(lhs.at(0)=='-' && rhs.at(0)=='-'){
        lhs = lhs.substr(1);
        rhs = rhs.substr(1);
    }
    else if(lhs.at(0)=='-'){
        lhs = lhs.substr(1);
    }
    else if(rhs.at(0)=='-'){
        rhs = rhs.substr(1);
    }

    if(lhs.size()>=rhs.size()){
        for(int i=rhs.size()-1; i>=0; i--){

            string partial_solution;

            for(int j=lhs.size()-1; j>=0; j--){
                digit = digit_to_decimal(rhs.at(i))*digit_to_decimal(lhs.at(j))+additive;
                if(digit<9){
                    partial_solution.insert(0, string(1, decimal_to_digit(digit)));
                    additive = 0;
                }
                else{
                    partial_solution.insert(0, string(1, decimal_to_digit(digit%10)));
                    additive = digit/10;
                }
            }
            if(additive!=0){partial_solution.insert(0, string(1, decimal_to_digit(additive)));}
            
            for(int i=0; i<counter; i++){
                partial_solution.append("0");
            }   
            solution = add(solution, partial_solution);
            counter++;
            additive=0;
        }
    }
    else{
        for(int i=lhs.size()-1; i>=0; i--){

            string partial_solution;

            for(int j=rhs.size()-1; j>=0; j--){
                digit = digit_to_decimal(lhs.at(i))*digit_to_decimal(rhs.at(j))+additive;
                if(digit<9){
                    partial_solution.insert(0, string(1, decimal_to_digit(digit)));
                    additive = 0;
                }
                else{
                    partial_solution.insert(0, string(1, decimal_to_digit(digit%10)));
                    additive = digit/10;
                }
            }
            if(additive!=0){partial_solution.insert(0, string(1, decimal_to_digit(additive)));}
            
            for(int i=0; i<counter; i++){
                partial_solution.append("0");
            }   
            solution = add(solution, partial_solution);
            counter++;
            additive=0;
        }
    }
    if(solution=="0"){
        return solution;
    }
    if((lhs1.at(0)=='-' && rhs1.at(0)!='-') || (lhs1.at(0)!='-' && rhs1.at(0)=='-')){
        solution.insert(0, string(1, '-'));
    }
    return solution;
}
