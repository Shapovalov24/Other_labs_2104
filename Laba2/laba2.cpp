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


int y_or_n_check(string user_input) {
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
        else cout << "!! Please write something !!" << endl;
    }

    while (true) {
        cout << "Pipe length ~ ";
        getline(cin, new_pipe_len);

        if (int_input_check(new_pipe_len) == 1) {
            if (stoi(new_pipe_len) > 0) break;

            else cout << "!! Incorrect value !!" << endl;
        }
        else cout << "!! Incorrect value !!" << endl;
    }

    while (true) {
        cout << "Pipe dimameter ~ ";
        getline(cin, new_pipe_dim);

        if (int_input_check(new_pipe_dim) == 1) {
            if (stoi(new_pipe_dim) > 0) break;

            else cout << "!! Incorrect value !!" << endl;
        }
        else cout << "!! Incorrect value !!" << endl;
    }

    while (true) {
        cout << "Repair status [Y/N] ~ ";
        getline(cin, new_pipe_stat);

        bool_input_check = y_or_n_check(new_pipe_stat);

        if (bool_input_check == 2) cout << "!! Incorrect value !!" << endl;

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
    << "\nRepair status: " << pipe_vector[pipe_vector.size()-1].repair_status << endl;  
}


void add_cs() {
    bool correct_input{0};
    string new_cs_name, new_cs_workshops, new_cs_workshops_in_work, new_cs_efficiency;

    while (true) {
        cout << "Compressor Station name ~ ";
        getline(cin, new_cs_name);

        if (new_cs_name.length() > 0) break;
        else cout << "!! Please write something !!" << endl;
    }

    while (correct_input != 1) {
        cout << "Workshops ~ ";
        getline(cin, new_cs_workshops);

        correct_input = int_input_check(new_cs_workshops);

        if (correct_input == 0) cout << "!! Incorrect value !!" << endl;
    }

    while (true) {
        cout << "Workshops in work ~ ";
        getline(cin, new_cs_workshops_in_work);

        correct_input = int_input_check(new_cs_workshops_in_work);

        if (correct_input == 0) cout << "!! Incorrect value !!" << endl;

        else if (correct_input == 1) {
            if (stoi(new_cs_workshops_in_work) > stoi(new_cs_workshops)) {
                cout << "!! Number of workshops in work can't exceed the total number of workshops !!" << endl;
            }
            else break;
        }
    }

    while (true) {
        cout << "Efficiency in percentage ~ ";
        getline(cin, new_cs_efficiency);

        correct_input = int_input_check(new_cs_efficiency);

        if (correct_input == 0) cout << "!! Incorrect value !!" << endl;
        
        else if (correct_input == 1) {
            if (stoi(new_cs_efficiency) >= 0 && stoi(new_cs_efficiency)<= 100) break;

            else cout << "!! Percentage value should be between (0, 100) !!" << endl;
        }
    }

    cs_vector.push_back(cs_structure{new_cs_name,stoi(new_cs_workshops),
    stoi(new_cs_workshops_in_work), stoi(new_cs_efficiency)});

    cout << "\nNew Compressor station #" << cs_vector.size()<<"\nName: " 
    << cs_vector[cs_vector.size()-1].name << "\nWorkshops: "<< cs_vector[cs_vector.size()-1].workshops
    << "\nWorkshops in work: " << cs_vector[cs_vector.size()-1].workshops_in_work <<
    "\nEfficiency: " << cs_vector[cs_vector.size()-1].efficiency << endl;
}


void view_all_objects() {
    bool view_menu_flag = 1;
    string view_menu_choice, search_pipe_by, pipe_search_name, pipe_search_stat, pipe_search_id,
    search_cs_by, cs_search_name, cs_search_id, cs_search_percentage, cs_percentage_low_or_high;

    while (view_menu_flag) {
        cout << "\n1 - Search pipe\n2 - Search station\n3 - Display full list\n > ";
        getline(cin, view_menu_choice);
        if (int_input_check(view_menu_choice) == 1) {
            if (stoi(view_menu_choice) >= 1 && stoi(view_menu_choice) <= 3) view_menu_flag = 0;
            else cout << "!! Value should be between (1, 3) !!" << endl;
        }
        else cout << "!! Value should be between (1, 3) !!" << endl;
    }

    switch (stoi(view_menu_choice)) {
    case 1:
        while (true) {
            cout << "\n1 - By name\n2 - By index\n3 - By repair status\n > ";
            getline(cin, search_pipe_by);

            if (int_input_check(search_pipe_by) == 1) {
                if (stoi(search_pipe_by) == 1 || stoi(search_pipe_by) == 2 || stoi(search_pipe_by) == 3) break;
                else cout << "!! Value should be between (1, 3) !!" << endl;
            }
            else cout << "!! Value should be between (1, 3) !!" << endl;
        }

        switch (stoi(search_pipe_by)) {
        case 1:
            while (true) {
                cout << "Name (press enter to exit)\n ~ ";
                getline(cin,pipe_search_name);
                if (pipe_search_name.length() != 0) {
                    for (int i = 0; i < pipe_vector.size(); i++) {
                        if (pipe_vector[i].name == pipe_search_name){
                            cout << pipe_vector[i].name << endl;
                            cout << pipe_vector[i].length << endl;
                            cout << pipe_vector[i].diameter << endl;
                            cout << pipe_vector[i].repair_status << endl;
                            cout << "\n" << endl;
                        }
                    }
                    break;
                }
                else break;
            }
            break;

        case 2:
            while (true) {
                cout << "Index (press enter to exit)\n" << "Pipes: " << pipe_vector.size()
                << endl;
                getline(cin, pipe_search_id);
                if (int_input_check(pipe_search_id) == 1) {
                    if (stoi(pipe_search_id) - 1 >= 0 && stoi(pipe_search_id) - 1 < pipe_vector.size()) {
                        cout << pipe_vector[stoi(pipe_search_id) - 1].name << endl;
                        cout << pipe_vector[stoi(pipe_search_id) - 1].length << endl;
                        cout << pipe_vector[stoi(pipe_search_id) - 1].diameter << endl;
                        cout << pipe_vector[stoi(pipe_search_id) - 1].repair_status << endl;
                        cout << "\n" << endl;
                    }
                    break;
                }
            }
            break;

        case 3:
            while (true) {
                cout << "Repair status [Y/N] (press enter to exit)\n" << endl;
                getline(cin, pipe_search_stat);
                string pipe_tolower = pipe_search_stat;
                string temp_pipe_stat_to_upper = pipe_search_stat;
                transform(pipe_tolower.begin(),
                    pipe_tolower.end(), pipe_tolower.begin(),
                    [](unsigned char c_pipe_stat)
                    {return tolower(c_pipe_stat);});
                transform(temp_pipe_stat_to_upper.begin(),
                    temp_pipe_stat_to_upper.end(), temp_pipe_stat_to_upper.begin(),
                    [](unsigned char c_pipe_stat)
                    {return tolower(c_pipe_stat);});
                for (int i = 0; i < pipe_vector.size(); i++) {
                    if (pipe_vector[i].repair_status == pipe_tolower 
                    || pipe_vector[i].repair_status == temp_pipe_stat_to_upper) {
                        cout << pipe_vector[i].name << endl;
                        cout << pipe_vector[i].length << endl;
                        cout << pipe_vector[i].diameter << endl;
                        cout << pipe_vector[i].repair_status << endl;
                        cout << "\n" << endl;
                    }
                }
                break; 
            }
            break;
        }
        break;

    case 2:
        while (true) {
            cout << "\n1 - By name\n2 - By index\n3 - By percentage of unused workshops\n ~ ";
            getline(cin, search_cs_by);

            if (int_input_check(search_cs_by) == 1) {
                if (stoi(search_cs_by) == 1 || stoi(search_cs_by) == 2 || stoi(search_cs_by) == 3) break;
                else cout << "!! Value should be between (1, 3) !!" << endl;
            }
            else cout << "!!! Value should be between (1, 3) !!" << endl;
        }

        switch (stoi(search_cs_by)) {
        case 1:
            while(true) {
                cout << "Name (press enter to exit)\n ~ ";
                getline(cin,cs_search_name);
                if (cs_search_name.length() != 0) {
                    for (int i = 0; i < cs_vector.size(); i++) {
                        if (cs_vector[i].name == cs_search_name) {
                            cout << cs_vector[i].name << endl;
                            cout << cs_vector[i].workshops << endl;
                            cout << cs_vector[i].workshops_in_work << endl;
                            cout << cs_vector[i].efficiency << endl;
                            cout << "\n" << endl;
                        }
                    }
                    break;
                } 

                else break;
            }
            break;

        case 2:
            while (true) {
                cout << "Index (press enter to exit)\n" << "Stations: " << cs_vector.size() << endl;
                getline(cin, cs_search_id);
                if (int_input_check(cs_search_id) == 1) {
                    if (stoi(cs_search_id)-1 >= 0 && stoi(cs_search_id)-1 < cs_vector.size()){
                        cout << cs_vector[stoi(cs_search_id)-1].name << endl;
                        cout << cs_vector[stoi(cs_search_id)-1].workshops << endl;
                        cout << cs_vector[stoi(cs_search_id)-1].workshops_in_work << endl;
                        cout << cs_vector[stoi(cs_search_id)-1].efficiency << endl;
                        cout << "\n" << endl;
                    }
                    break;
                }
            }
            break;

        case 3:
            while (true) {
                cout << "Enter percentage of unused workshops: ";
                getline(cin, cs_search_percentage);
                if (int_input_check(cs_search_percentage) == 1) {
                    if (stoi(cs_search_percentage) >= 0 || stoi(cs_search_percentage) <= 100) break;
                    else cout << "!! Out of range !!" << endl;
                } 

                else cout << "!! Incorrect value !!" << endl;
            }

            while (true) {
                cout << "1 - Lower than " << cs_search_percentage << "%\n2 - Higher than " << cs_search_percentage << "%\n ~ ";
                getline(cin, cs_percentage_low_or_high);

                if (int_input_check(cs_percentage_low_or_high) == 1) {
                    if (stoi(cs_percentage_low_or_high) == 1) {
                        for (int i = 0; i < cs_vector.size(); i++) {
                            if ((cs_vector[i].workshops - cs_vector[i].workshops_in_work)/cs_vector[i].workshops < stoi(cs_percentage_low_or_high)) {
                                cout << cs_vector[i].name << endl;
                                cout << cs_vector[i].workshops << endl;
                                cout << cs_vector[i].workshops_in_work << endl;
                                cout << cs_vector[i].efficiency << endl;
                                cout << "\n" << endl;
                            }
                        }
                        break;
                    }

                    else if (stoi(cs_percentage_low_or_high) == 2) {
                        for (int i = 0; i < cs_vector.size(); i++) {
                            if ((cs_vector[i].workshops - cs_vector[i].workshops_in_work)/cs_vector[i].workshops > stoi(cs_percentage_low_or_high)) {
                                cout << cs_vector[i].name << endl;
                                cout << cs_vector[i].workshops << endl;
                                cout << cs_vector[i].workshops_in_work << endl;
                                cout << cs_vector[i].efficiency << endl;
                                cout << "\n" << endl;
                            }
                        }
                        break;
                    }

                    else cout << "!! Out of range !!" << endl;
                }
            }       
            break;
        }
        break;

    case 3:
        cout << "Pipes:\n" << endl;
        for (int i = 0; i < pipe_vector.size(); i++) {
            cout << pipe_vector[i].name << endl;
            cout << pipe_vector[i].length << endl;
            cout << pipe_vector[i].diameter << endl;
            cout << pipe_vector[i].repair_status << endl;
            cout << "\n" << endl;
        }
        cout << "Compressor stations:\n" << endl;
        for (int i = 0; i < cs_vector.size(); i++) {
            cout << cs_vector[i].name << endl;
            cout << cs_vector[i].workshops << endl;
            cout << cs_vector[i].workshops_in_work << endl;
            cout << cs_vector[i].efficiency << endl;
            cout << "\n" << endl;
        }
        break;
    }    
}


void edit_pipe() {
    string pipe_id_to_edit, pipe_parameter_to_edit, new_pipe_name, new_pipe_lenght, new_pipe_diameter, new_pipe_repair_stat, pipe_tolower;

    while (true) {
        cout << "Id of pipe ("<< pipe_vector.size()<<" pipes in stock)\n(press enter to exit) ~ ";
        getline(cin, pipe_id_to_edit);
        if (pipe_id_to_edit.length() == 0) break;

        else if (int_input_check(pipe_id_to_edit) == 1) {
            if (stoi(pipe_id_to_edit)-1 >= 0 && stoi(pipe_id_to_edit)-1 < pipe_vector.size()) break;
            else cout << "!! Out of range !!" << endl;
        }
        else cout << "!! Integer expected !!" << endl;
    }

    if (pipe_id_to_edit.length() != 0) {
        cout << "Pipe #" << pipe_id_to_edit << ":"<< endl;
        cout << pipe_vector[stoi(pipe_id_to_edit)-1].name << endl;
        cout << pipe_vector[stoi(pipe_id_to_edit)-1].length << endl;
        cout << pipe_vector[stoi(pipe_id_to_edit)-1].diameter << endl;
        cout << pipe_vector[stoi(pipe_id_to_edit)-1].repair_status << endl;
        cout << "\n" << endl;
    }
    else return;

    while (true) {
        cout << "Select parameter of pipe:\n1 - Name\n2 - Length\n3 - Diameter\n4 - Repair status\n ~ ";
        getline(cin, pipe_parameter_to_edit);

        if (int_input_check(pipe_parameter_to_edit) == 1) {
            if (stoi(pipe_parameter_to_edit) >= 1 && stoi(pipe_parameter_to_edit) <= 4) break;
            else cout << "!! Out of range !!" << endl;
        }
        else cout << "!! Incorrect value !!" << endl;
    }

    switch (stoi(pipe_parameter_to_edit)) {

    case 1:
        while (true) {
            cout << "New pipe name ~ ";
            getline(cin, new_pipe_name);

            if (new_pipe_name.length() > 0) {
                pipe_vector[stoi(pipe_id_to_edit)-1].name = new_pipe_name;
                break;
            } 
            else cout << "!! Name can't be empty !!" << endl;
        }
        break;

    case 2:
        while (true) {
            cout << "New pipe length ~ ";
            getline(cin, new_pipe_lenght);

            if (int_input_check(new_pipe_lenght) == 1) {
                if (stoi(new_pipe_lenght) > 0) {
                    pipe_vector[stoi(pipe_id_to_edit)-1].length = stoi(new_pipe_lenght);
                    break;
                }
                else cout << "!! Length should be bigger than 0 !!";
            } 
            else cout << "!! Incorrect value !!" << endl;
        }
        break;

    case 3:
        while (true) {
            cout << "New pipe diameter ~ ";
            getline(cin, new_pipe_diameter);

            if (int_input_check(new_pipe_diameter) == 1) {
                if (stoi(new_pipe_diameter) > 0) {
                    pipe_vector[stoi(pipe_id_to_edit)-1].diameter = stoi(new_pipe_diameter);
                    break;
                } 
                else cout << "!! Diameter should be bigger than 0 !!";
            } 
            else cout << "!! Incorrect value !!" << endl;
        }
        break;

    case 4:
        while(true) {
            cout << "Repair status [Y/N] ~ ";
            getline(cin, new_pipe_repair_stat);

            if (y_or_n_check(new_pipe_repair_stat) != 2) {
                pipe_tolower = new_pipe_repair_stat;
                transform(pipe_tolower.begin(),
                    pipe_tolower.end(), pipe_tolower.begin(),
                    [](unsigned char c_pipe_stat)
                    {return tolower(c_pipe_stat);});
                pipe_vector[stoi(pipe_id_to_edit)-1].repair_status = pipe_tolower;
                break;
            }
            else cout << "!! Incorrect value !!" << endl;
        }
        break;
    }
}


void edit_cs() {

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

            else cout << "\n!! Incorrect value !!\n" << endl;
        }

        else cout << "\n!! Incorrect value !!\n" << endl;
    }
    return stoi(user_menu_insert);
}


int main() {
    int user_choice_in_main_menu;
    bool program_cycle{1}, file_saved_status{1};
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
                view_all_objects();
                break;
            case 4:
                edit_pipe();
                file_saved_status = 0;
                break;
            case 5:
                edit_cs();
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