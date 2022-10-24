#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

struct pipe_structure {
    string name;
    int length;
    int diameter;
    string repair_status;
};

vector <pipe_structure> pipe_vector;

struct cs_structure {
    string name;
    int workshops;
    int workshops_in_work;
    int efficiency;
};

vector <cs_structure> cs_vector;

bool int_input_check(string inserted_num) {
    bool inserted_flag{0};

    if (inserted_num.length() > 0 ) {
        inserted_flag = 1;
        for (int x = 0; x < inserted_num.length(); x++) {
                if (isdigit(inserted_num[x]) == false) {
                    inserted_flag = 0;
                    break;
                }
            }
        if (inserted_flag == 1) {
            if (stoi(inserted_num) <= 0) inserted_flag = 0;  
        }
    }
    return inserted_flag;
}

int y_or_n_check(string user_input){
    int user_input_flag;

    if (user_input == "y" || user_input == "n" || user_input == "Y" || user_input == "N") {
        if (user_input == "y" || user_input == "Y") user_input_flag = 1;

        else if (user_input == "n" || user_input == "N") user_input_flag = 0;
    }

    else user_input_flag = 2;

    return user_input_flag;
}


void add_pipe() {

    bool correct_input{0};
    int bool_input_check;
    string new_pipe_name, new_pipe_dim, new_pipe_len, new_pipe_stat, pipe_tolower;

    while (true) {
        cout << "Pipe name ~ ";
        getline(cin, new_pipe_name);

        if (new_pipe_name.length() > 0) break;
    }

    while (true) {
        cout << "Pipe length ~ ";
        getline(cin, new_pipe_len);

        if (int_input_check(new_pipe_len) == 1) {
            if (stoi(new_pipe_len) > 0) break;

            else cout << "Invalid value" << endl;
        }
        else cout << "!!! Length should be an integer" << endl;
    }

    while (true) {
        cout << "Pipe dimameter ~ ";
        getline(cin, new_pipe_dim);

        if (int_input_check(new_pipe_dim) == 1) {
            if (stoi(new_pipe_dim) > 0) break;

            else cout << "Invalid value" << endl;
        }
        else cout << "!!! Diameter should be an integer" << endl;
    }

    while (true) {
        cout << "Repair status [Y/N] ~ ";
        getline(cin, new_pipe_stat);

        bool_input_check = y_or_n_check(new_pipe_stat);

        if (bool_input_check == 2) cout << "!!! Invalid value" << endl;

        else {
            pipe_tolower = new_pipe_stat;

            transform(pipe_tolower.begin(), pipe_tolower.end(), pipe_tolower.begin(),
                [](unsigned char c_pipe_stat) {return tolower(c_pipe_stat);});

            correct_input = bool_input_check;
            break;
        }
    }

    pipe_vector.push_back(pipe_structure{new_pipe_name,stoi(new_pipe_len), stoi(new_pipe_dim), pipe_tolower});

    cout << "\nNew pipe #" << pipe_vector.size()<< "\nName: " 
    << pipe_vector[pipe_vector.size()-1].name <<"\nLength: " 
    << pipe_vector[pipe_vector.size()-1].length 
    << "\nDiameter: "<<pipe_vector[pipe_vector.size()-1].diameter
    << "\nRepair status: " << pipe_vector[pipe_vector.size()-1].repair_status
    << "\nhas been added successfully\n" << endl;
    
}

void add_cs(){
    bool correct_input{0};
    string new_cs_name, new_cs_workshops, new_cs_workshops_in_work, new_cs_efficiency;

    while (true) {
        cout << "Compressor Station name ~ ";
        getline(cin, new_cs_name);

        if (new_cs_name.length() > 0) break;
    }

    while (correct_input != 1) {
        cout << "Workshops ~ ";
        getline(cin, new_cs_workshops);

        correct_input = int_input_check(new_cs_workshops);

        if (correct_input == 0) cout << "!!! Number of workshops should be an integer" << endl;
    }

    while (true) {
        cout << "Workshops in work ~ ";
        getline(cin, new_cs_workshops_in_work);

        correct_input = int_input_check(new_cs_workshops_in_work);

        if (correct_input == 0) cout << "!!! Number of workshops should be an integer" << endl;

        else if (correct_input == 1) {
            if (stoi(new_cs_workshops_in_work) > stoi(new_cs_workshops)) {
                cout << "!!! Number of workshops in work cannot exceed the total number of workshops" << endl;
            }
            else break;
        }
    }

    while (true) {
        cout << "Efficiency in percentage > ";
        getline(cin, new_cs_efficiency);

        correct_input = int_input_check(new_cs_efficiency);

        if (correct_input == 0) cout << "!!! Efficiency should be an integer" << endl;
        
        else if (correct_input == 1) {
            if (stoi(new_cs_efficiency) >= 0 && stoi(new_cs_efficiency)<= 100) break;

            else cout << "Percentage value must be between 0 and 100" << endl;
        }
    }

    cs_vector.push_back(cs_structure{new_cs_name,stoi(new_cs_workshops),
    stoi(new_cs_workshops_in_work), stoi(new_cs_efficiency)});

    cout << "\nNew Compressor station #" << pipe_vector.size()<<"\nName: " 
    << cs_vector[cs_vector.size()-1].name << "\nWorkshops: "<< cs_vector[cs_vector.size()-1].workshops
    << "\nWorkshops in work: " << cs_vector[cs_vector.size()-1].workshops_in_work <<
    "\nEfficiency: " << cs_vector[cs_vector.size()-1].efficiency<< "\nhas been added successfully\n"
    << endl;
}

int menu() {
    bool main_menu_flag{1};
    string user_menu_insert;

    while (main_menu_flag) {

        bool menu_number_isdig{1};

        cout << "\n1. Add Pipe" << endl;
        cout << "2. Add Compressor station" << endl;
        cout << "3. View object list" << endl;
        cout << "4. Edit Pipe" << endl;
        cout << "5. Edit Compressor station" << endl;
        cout << "6. Save" << endl;
        cout << "7. Load" << endl;
        cout << "0. Exit" << endl;
        cout << "~ ";

        getline(cin, user_menu_insert);

        if (user_menu_insert.length() > 0) {
            for (int i = 0; i < user_menu_insert.length(); i++) {
                if (isdigit(user_menu_insert[i]) == false) {
                    menu_number_isdig = 0;
                    break;
                }
            }

            if (menu_number_isdig == 1) {
                if (stoi(user_menu_insert) <= 7 && stoi(user_menu_insert) >= 0) main_menu_flag = 0;
            }

            else cout << "\nInvalid value!\n" << endl;
        }

        else cout << "\nInvalid value!\n" << endl;
    }

    return stoi(user_menu_insert);
}

int main() {
    int user_choice_in_main_menu;
    bool program_cycle{1},file_saved_status{1};
    string load_without_saving_string;

    while (program_cycle) {
        user_choice_in_main_menu = menu();

        switch (user_choice_in_main_menu) {
            case 0:
                if (file_saved_status == 0) cout << "Not saved" << endl;
                program_cycle = 0;
                break;
            case 1:
                add_pipe();
                file_saved_status = 0;
                break;
            case 2:
                add_cs();
                file_saved_status = 0;
                break;
            case 3:
                // some func to view();
                break;
            case 4:
                // func to edit pipes();
                file_saved_status = 0;
                break;
            case 6:
                // func to save();
                file_saved_status = 1;
                break;
            case 7:
                break;
        }
    }
    return 0;
}