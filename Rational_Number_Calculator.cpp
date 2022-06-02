
// Program Name: Rational_Number_Calculator_20210475_20211078_20210294.cpp
// Program Description: Rational_Number_Calculator
// Last Modification Date: 29/3/2022
// Yousef Abdalla Attia  email :yabdalla43@gmail.com



#include<iostream>
#include<string>
#include<regex>

using namespace std;

// starter vairables
int NUM_result = 0;
int DEN_result = 0;
string num_op_num, num1, num2, n1_str, n2_str, d1_str, d2_str;
int no1, no2, do1, do2;
// take inputs and define every part
void input_and_string_split(){
    cout << "Please enter the two numbers and the operation between them\n";
    getline(cin>>ws, num_op_num);
    for (int i = 0; i < num_op_num.length(); i++){
        if (num_op_num[i] != ' ' && num_op_num[i] != '+' && num_op_num[i] != '-' && num_op_num[i] != '/' && num_op_num[i] != '*' && num_op_num[i] != '0' && num_op_num[i] != '1' && num_op_num[i] != '2' && num_op_num[i] != '3' && num_op_num[i] != '4' && num_op_num[i] != '5' && num_op_num[i] != '6' && num_op_num[i] != '7' && num_op_num[i] != '8' && num_op_num[i] != '9'){
            cout << "Invalid input. Please try again\n";
            input_and_string_split();
        }
    }
        for (int i = 0; i < num_op_num.length(); i++){
            if((num_op_num[i] == '+' || num_op_num[i] == '-' || num_op_num[i] == '*' || num_op_num[i] == '/') && (num_op_num[i-1] == ' ' && num_op_num[i+1] == ' ')){
                num1 = num_op_num.substr(0, (i-1));
                num2 = num_op_num.substr(i+2);
            }
        }
    }
//check if it is valid int
bool is_valid_int(string& str1, string& str2){
    regex int_format ("[-+]?[0-9]+");
    return regex_match (str1, int_format);
    return regex_match (str2, int_format);
}
//check if it is valid rational
bool is_valid_rational(string& str1, string& str2){
    regex rational_format ("[-+]?[0-9]+(\\/[0-9]+)?");
    return regex_match (str1, rational_format);
    return regex_match (str2, rational_format);
}
//find every part
void check_available_numbers(){
        if (is_valid_rational(num1, num2)){
        int check1 = 0;
        int check2 = 0;
        for (int i = 0; i < num1.length(); i++){
            if (num1[i] == '/'){
                check1 += 1;
                break;
            }
        }
        for (int i = 0; i < num2.length(); i++){
            if (num2[i] == '/'){
                check2 += 1;
                break;
            }
        }

        if (check1 == 0 && check2 == 0){
            n1_str = num1;
            n2_str = num2;
            d1_str = "1";
            d2_str = "1";
            no1 = stoi (n1_str);
            no2 = stoi (n2_str);
            do1 = stoi (d1_str);
            do2 = stoi (d2_str);
        }
        else if (check1 == 0 && check2 == 1){
            n1_str = num1;
            n2_str = num2.substr(0, (num2.find("/")));
            d1_str = "1";
            d2_str = num2.substr((num2.find("/")+1));
            no1 = stoi (n1_str);
            no2 = stoi (n2_str);
            do1 = stoi (d1_str);
            do2 = stoi (d2_str);
        }
        else if (check1 == 1 && check2 == 0){
            n1_str = num1.substr(0, (num1.find("/")));
            n2_str = num2;
            d1_str = num2.substr((num1.find("/")+1));
            d2_str = "1";
            no1 = stoi (n1_str);
            no2 = stoi (n2_str);
            do1 = stoi (d1_str);
            do2 = stoi (d2_str);
        }
        else if (check1 == 1 && check2 == 1){
            n1_str = num1.substr(0, (num1.find("/")));
            n2_str = num2.substr(0, (num2.find("/")));
            d1_str = num1.substr((num1.find("/")+1));
            d2_str = num2.substr((num2.find("/")+1));
            no1 = stoi (n1_str);
            no2 = stoi (n2_str);
            do1 = stoi (d1_str);
            do2 = stoi (d2_str);
        }
    }
}
//calculating
void calculate_and_printresult(){
        for (int i = 0; i < num_op_num.length(); i++){
        if (num_op_num[i] == '+' && num_op_num[i-1] == ' ' && num_op_num[i+1] == ' '){
            NUM_result= (no1 * do2) +(no2 * do1);
            DEN_result= do1* do2;
            for (int i = 100; i >= 1; i--){
                if (NUM_result % i == 0 && DEN_result % i == 0){
                    NUM_result = NUM_result / i;
                    DEN_result = DEN_result / i;
                }
            }
            if (NUM_result == DEN_result){
                cout << "1";
                break;
            }
            else if (DEN_result == 1){
                cout << NUM_result;
                break;
            }
            else if (DEN_result == 0){
                cout << "Undefined number!!";
                break;
            }
            else{
            cout <<NUM_result<<'/'<<DEN_result<<endl;
            break;
            }
        }
        else if (num_op_num[i] == '-' && num_op_num[i-1] == ' ' && num_op_num[i+1] == ' '){
            NUM_result = (no1 * do2) - (no2 * do1);
            DEN_result= do1 * do2;
            for (int i = 100; i >= 1; i--){
                if (NUM_result % i == 0 && DEN_result % i == 0){
                    NUM_result = NUM_result / i;
                    DEN_result = DEN_result / i;
                }
            }
            if (NUM_result == DEN_result){
                cout << "1";
                break;
            }
            else if (DEN_result == 1){
                cout << NUM_result;
                break;
            }
            else if (DEN_result == 0){
                cout << "Undefined number!!";
                break;
            }
            else{
            cout <<NUM_result<<'/'<<DEN_result<<endl;
            break;
            }
        }
        else if (num_op_num[i] == '*' && num_op_num[i-1] == ' ' && num_op_num[i+1] == ' '){
            NUM_result = no1 * no2;
            DEN_result= do1 * do2;
            for (int i = 100; i >= 1; i--){
                if (NUM_result % i == 0 && DEN_result % i == 0){
                    NUM_result = NUM_result / i;
                    DEN_result = DEN_result / i;
                }
            }
            if (NUM_result == DEN_result){
                cout << "1";
                break;
            }
            else if (DEN_result == 1){
                cout << NUM_result;
                break;
            }
            else if (DEN_result == 0){
                cout << "Undefined number!!";
                break;
            }
            else{
            cout <<NUM_result<<'/'<<DEN_result<<endl;
            break;
            }
        }
        else if (num_op_num[i] == '/' && num_op_num[i-1] == ' ' && num_op_num[i+1] == ' '){
            NUM_result = no1 * do2;
            DEN_result = no2 * do1;
            for (int i = 100; i >= 1; i--){
                if (NUM_result % i == 0 && DEN_result % i == 0){
                    NUM_result = NUM_result / i;
                    DEN_result = DEN_result / i;
                }
            }
            if (NUM_result == DEN_result){
                cout << "1";
                break;
            }
            else if (DEN_result == 1){
                cout << NUM_result;
                break;
            }
            else if (DEN_result == 0){
                cout << "Undefined number!!";
                break;
            }
            else{
            cout <<NUM_result<<'/'<<DEN_result<<endl;
            break;
            }
        }
    }
}

void defensive_programming(){
    for (int i = 0; i < num_op_num.length(); i++){
        if (num_op_num[i] != ' ' || num_op_num[i] != '+' || num_op_num[i] != '-' || num_op_num[i] != '/' || num_op_num[i] != '*' || num_op_num[i] != '0' || num_op_num[i] != '1' || num_op_num[i] != '2' || num_op_num[i] != '3' || num_op_num[i] != '4' || num_op_num[i] != '5' || num_op_num[i] != '6' || num_op_num[i] != '7' || num_op_num[i] != '8' || num_op_num[i] != '9'){
            cout << "Invalid input. Please try again\n";
        }
    }
}

//start
int main(){
    bool start=1;
    cout<<"Welcome to FCAI Complex Number Calculator"<<endl;
    while(start){
    cout<<"any number for start , 0 for End"<<endl;
    cin>>start;
    if (start==0){
        start=0;
        break;
    }

    input_and_string_split();
    check_available_numbers();
    calculate_and_printresult();
    cout<<endl;
    }

    cout<<"Thanks or using FCAI Complex Number Calculator" <<endl;
}
