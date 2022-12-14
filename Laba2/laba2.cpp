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

struct cs_structure {
    string name;
    int workshops;
    int workshops_in_work;
    int efficiency;
};

vector <pipe_structure> pipe_vector;
vector <cs_structure> cs_vector;

bool int_check(string inserted_num) {
    bool inserted_flag{0};

    if (inserted_num.length() > 0 ) {
        inserted_flag = 1;
        for (int i = 0; i < inserted_num.length(); i++) {
                if (isdigit(inserted_num[i]) == false) {
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
        cout << "Название Трубы ~ ";
        getline(cin, new_pipe_name);

        if (new_pipe_name.length() > 0) break;
        else cout << "!! Пожалуйста напишите что-нибудь !!" << endl;
    }

    while (true) {
        cout << "Длина Трубы ~ ";
        getline(cin, new_pipe_len);

        if (int_check(new_pipe_len) == 1) {
            if (stoi(new_pipe_len) > 0) break;

            else cout << "!! Некорректное значение !!" << endl;
        }
        else cout << "!! Некорректное значение !!" << endl;
    }

    while (true) {
        cout << "Диаметр Трубы ~ ";
        getline(cin, new_pipe_dim);

        if (int_check(new_pipe_dim) == 1) {
            if (stoi(new_pipe_dim) > 0) break;

            else cout << "!! Некорректное значение !!" << endl;
        }
        else cout << "!! Некорректное значение !!" << endl;
    }

    while (true) {
        cout << "В ремонте [Y/N] ~ ";
        getline(cin, new_pipe_stat);

        bool_input_check = y_or_n_check(new_pipe_stat);

        if (bool_input_check == 2) cout << "!! Некорректное значение !!" << endl;

        else {
            pipe_tolower = new_pipe_stat;

            transform(pipe_tolower.begin(), pipe_tolower.end(), pipe_tolower.begin(),
                [](unsigned char c_pipe_stat) {return tolower(c_pipe_stat);});

            correct_input = bool_input_check;
            break;
        }
    }

    pipe_vector.push_back(pipe_structure{new_pipe_name,stoi(new_pipe_len), stoi(new_pipe_dim), pipe_tolower});

    cout << "\nТруба #" << pipe_vector.size()<< "\nНазвание: " 
    << pipe_vector[pipe_vector.size() - 1].name << "\nДлина: " 
    << pipe_vector[pipe_vector.size() - 1].length 
    << "\nДиаметр: "<< pipe_vector[pipe_vector.size() - 1].diameter
    << "\nВ ремонте: " << pipe_vector[pipe_vector.size() - 1].repair_status << endl;  
}


void add_cs() {
    bool correct_input{0};
    string new_cs_name, new_cs_workshops, new_cs_workshops_in_work, new_cs_efficiency;

    while (true) {
        cout << "Название КС ~ ";
        getline(cin, new_cs_name);

        if (new_cs_name.length() > 0) break;
        else cout << "!! Пожалуйста напишите что-нибудь !!" << endl;
    }

    while (correct_input != 1) {
        cout << "Кол-во заводов ~ ";
        getline(cin, new_cs_workshops);

        correct_input = int_check(new_cs_workshops);

        if (correct_input == 0) cout << "!! Некорректное значение !!" << endl;
    }

    while (true) {
        cout << "Кол-во работающих заводов ~ ";
        getline(cin, new_cs_workshops_in_work);

        correct_input = int_check(new_cs_workshops_in_work);

        if (correct_input == 0) cout << "!! Некорректное значение !!" << endl;

        else if (correct_input == 1) {
            if (stoi(new_cs_workshops_in_work) > stoi(new_cs_workshops)) {
                cout << "!! Кол-во рабочих заводов не может превышать общее кол-во заводов !!" << endl;
            }
            else break;
        }
    }

    while (true) {
        cout << "Эффективность (%) ~ ";
        getline(cin, new_cs_efficiency);

        correct_input = int_check(new_cs_efficiency);

        if (correct_input == 0) cout << "!! Некорректное значение !!" << endl;
        
        else if (correct_input == 1) {
            if (stoi(new_cs_efficiency) >= 0 && stoi(new_cs_efficiency)<= 100) break;

            else cout << "!! Значение должно быть в пределах (0, 100) !!" << endl;
        }
    }

    cs_vector.push_back(cs_structure{new_cs_name,stoi(new_cs_workshops), stoi(new_cs_workshops_in_work), stoi(new_cs_efficiency)});

    cout << "\nКомпрессорная Станция #" << cs_vector.size() << "\nНазвание: " 
    << cs_vector[cs_vector.size() - 1].name << "\nКол-во заводов: " << cs_vector[cs_vector.size() - 1].workshops
    << "\nКол-во работающих заводов: " << cs_vector[cs_vector.size()-1].workshops_in_work <<
    "\nЭффективность: " << cs_vector[cs_vector.size() - 1].efficiency << endl;
}


void out_pipe(int id, string name, int len, int dim, string stat) {
    cout << "\n\tТруба #" << id + 1<< ":"<< endl;
    cout << "\tНазвание: " << name << endl;
    cout << "\tДлина: " << len << endl;
    cout << "\tДиаметр: " << dim << endl;
    cout << "\tВ ремонте: " << stat << endl;
}


void out_cs(int id, string name, int ws, int ws_i, int eff) {
    cout << "\n\tКС #" << id + 1<< ":"<< endl;
    cout << "\tНазвание: " << name << endl;
    cout << "\tКол-во заводов: " << ws << endl;
    cout << "\tКол-во работающих заводов: " << ws_i << endl;
    cout << "\tЭффективность: " << eff << endl; 
}


void view_all_objects() {
    bool view_menu_flag = 1;
    string view_menu_choice, search_pipe_by, pipe_search_name, pipe_search_stat, pipe_search_id,
    search_cs_by, cs_search_name, cs_search_id, cs_search_percentage, cs_percentage_low_or_high;

    while (view_menu_flag) {
        cout << "\n1 - Найти Трубу\n2 - Найти КС\n3 - Все объекты\n ~ ";
        getline(cin, view_menu_choice);
        if (int_check(view_menu_choice) == 1) {
            if (stoi(view_menu_choice) >= 1 && stoi(view_menu_choice) <= 3) view_menu_flag = 0;
            else cout << "!! Значение должно быть в пределах (1, 3) !!" << endl;
        }
        else cout << "!! Значение должно быть в пределах (1, 3) !!" << endl;
    }

    switch (stoi(view_menu_choice)) {
    case 1:
        while (true) {
            cout << "\n1 - По имени\n2 - По индексу\n3 - По статусу 'В ремонте'\n~ ";
            getline(cin, search_pipe_by);

            if (int_check(search_pipe_by) == 1) {
                if (stoi(search_pipe_by) == 1 || stoi(search_pipe_by) == 2 || stoi(search_pipe_by) == 3) break;
                else cout << "!! Значение должно быть в пределах (1, 3) !!" << endl;
            }
            else cout << "!! Значение должно быть в пределах (1, 3) !!" << endl;
        }

        switch (stoi(search_pipe_by)) {
        case 1:
            while (true) {
                cout << "Название\n~ ";
                getline(cin,pipe_search_name);
                if (pipe_search_name.length() != 0) {
                    for (int i = 0; i < pipe_vector.size(); i++){
                        if (pipe_vector[i].name == pipe_search_name){
                            out_pipe(i, pipe_vector[i].name,pipe_vector[i].length,
                            pipe_vector[i].diameter, pipe_vector[i].repair_status);
                        }
                    }
                    break;
                }
                else break;
            }
            break;

        case 2:
            while (true) {
                cout << "Всего Труб: " << pipe_vector.size() << "\nИндекс Трубы ~ ";
                getline(cin, pipe_search_id);
                if (int_check(pipe_search_id) == 1) {
                    if (stoi(pipe_search_id) - 1 >= 0 && stoi(pipe_search_id) - 1 < pipe_vector.size()) {
                        out_pipe(stoi(pipe_search_id)-1, pipe_vector[stoi(pipe_search_id)-1].name,
                        pipe_vector[stoi(pipe_search_id)-1].length,
                        pipe_vector[stoi(pipe_search_id)-1].diameter, 
                        pipe_vector[stoi(pipe_search_id)-1].repair_status);
                    }
                    break;
                }
            }
            break;

        case 3:
            while (true) {
                cout << "В ремонте [Y/N]?\n~ ";
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
                    if (pipe_vector[i].repair_status == pipe_tolower || pipe_vector[i].repair_status == temp_pipe_stat_to_upper) {
                        out_pipe(i, pipe_vector[i].name, pipe_vector[i].length,
                        pipe_vector[i].diameter, pipe_vector[i].repair_status);
                    }
                }
                break; 
            }
            break;
        }
        break;

    case 2:
        while (true) {
            cout << "\n1 - По имени\n2 - По индексу\n3 - По неработающим заводам\n~ ";
            getline(cin, search_cs_by);

            if (int_check(search_cs_by) == 1) {
                if (stoi(search_cs_by) == 1 || stoi(search_cs_by) == 2 || stoi(search_cs_by) == 3) break;
                else cout << "!! Значение должно быть в пределах (1, 3) !!" << endl;
            }
            else cout << "!! Значение должно быть в пределах (1, 3) !!" << endl;
        }

        switch (stoi(search_cs_by)) {
        case 1:
            while (true) {
                cout << "Название\n~ ";
                getline(cin,cs_search_name);
                if (cs_search_name.length() != 0) {
                    for (int i = 0; i < cs_vector.size(); i++) {
                        if (cs_vector[i].name == cs_search_name) {
                            out_cs(i, cs_vector[i].name, cs_vector[i].workshops,
                            cs_vector[i].workshops_in_work, cs_vector[i].efficiency);
                        }
                    }
                    break;
                } 

                else break;
            }
            break;

        case 2:
            while (true) {
                cout << "Всего КС: " << cs_vector.size() << "\nИндекс ~";
                getline(cin, cs_search_id);
                if (int_check(cs_search_id) == 1) {
                    if (stoi(cs_search_id) - 1 >= 0 && stoi(cs_search_id) - 1 < cs_vector.size()) {
                        out_cs(stoi(cs_search_id) - 1, cs_vector[stoi(cs_search_id) - 1].name,
                        cs_vector[stoi(cs_search_id) - 1].workshops,
                        cs_vector[stoi(cs_search_id) - 1].workshops_in_work,
                        cs_vector[stoi(cs_search_id) - 1].efficiency);
                    }
                    break;
                }
            }
            break;

        case 3:
            while (true) {
                cout << "Введите процент неработающих заводов ~ ";
                getline(cin, cs_search_percentage);
                if (int_check(cs_search_percentage) == 1) {
                    if (stoi(cs_search_percentage) >= 0 || stoi(cs_search_percentage) <= 100) break;
                    else cout << "!! Некорректное значение !!" << endl;
                } 

                else cout << "!! Некорректное значение !!" << endl;
            }

            while (true) {
                cout << "1 - Меньше чем " << cs_search_percentage << "%\n2 - Больше чем " << cs_search_percentage << "%\n~ ";
                getline(cin, cs_percentage_low_or_high);

                if (int_check(cs_percentage_low_or_high) == 1) {
                    if (stoi(cs_percentage_low_or_high) == 1) {
                        for (int i = 0; i < cs_vector.size(); i++) {
                            if ((cs_vector[i].workshops - cs_vector[i].workshops_in_work)/cs_vector[i].workshops < stoi(cs_percentage_low_or_high)) {
                                out_cs(i, cs_vector[i].name, cs_vector[i].workshops, cs_vector[i].workshops_in_work, cs_vector[i].efficiency);
                            }
                        }
                        break;
                    }

                    else if (stoi(cs_percentage_low_or_high) == 2) {
                        for (int i = 0; i < cs_vector.size(); i++) {
                            if ((cs_vector[i].workshops - cs_vector[i].workshops_in_work)/cs_vector[i].workshops > stoi(cs_percentage_low_or_high)) {
                                out_cs(i, cs_vector[i].name, cs_vector[i].workshops, cs_vector[i].workshops_in_work, cs_vector[i].efficiency);
                            }
                        }
                        break;
                    }

                    else cout << "!! Некорректное значение !!" << endl;
                }
            }       
            break;
        }
        break;

    case 3:
        cout << "Трубы:\n" << endl;
        for (int i = 0; i < pipe_vector.size(); i++) out_pipe(i, pipe_vector[i].name, pipe_vector[i].length, pipe_vector[i].diameter, pipe_vector[i].repair_status);
        
        cout << "КС:\n" << endl;
        for (int i = 0; i < cs_vector.size(); i++) out_cs(i, cs_vector[i].name, cs_vector[i].workshops, cs_vector[i].workshops_in_work,cs_vector[i].efficiency);

        break;
    }    
}


void edit_pipe() {
    string pipe_id_to_edit, pipe_parameter_to_edit, new_pipe_name, new_pipe_lenght, new_pipe_diameter, new_pipe_repair_stat, pipe_tolower;

    while (true) {
        cout << "Номер Трубы (Всего Труб: "<< pipe_vector.size()<<")\n~ ";
        getline(cin, pipe_id_to_edit);
        if (pipe_id_to_edit.length() == 0) break;

        else if (int_check(pipe_id_to_edit) == 1) {
            if (stoi(pipe_id_to_edit) - 1 >= 0 && stoi(pipe_id_to_edit) - 1 < pipe_vector.size()) break;
            else cout << "!! Некорректное значение !!" << endl;
        }
        else cout << "!! Некорректное значение !!" << endl;
    }

    if (pipe_id_to_edit.length() != 0) {
        out_pipe(stoi(pipe_id_to_edit) - 1, pipe_vector[stoi(pipe_id_to_edit) - 1].name, pipe_vector[stoi(pipe_id_to_edit) - 1].length,
        pipe_vector[stoi(pipe_id_to_edit) - 1].diameter, pipe_vector[stoi(pipe_id_to_edit) - 1].repair_status);
    }
    else return;

    while (true) {
        cout << "Выберите параметр Трубы:\n1 - Название\n2 - Длина\n3 - Диаметр\n4 - В ремонте\n ~ ";
        getline(cin, pipe_parameter_to_edit);

        if (int_check(pipe_parameter_to_edit) == 1) {
            if (stoi(pipe_parameter_to_edit) >= 1 && stoi(pipe_parameter_to_edit) <= 4) break;
            else cout << "!! Значение должно быть в пределах (1, 4) !!" << endl;
        }
        else cout << "!! Некорректное значение !!" << endl;
    }

    switch (stoi(pipe_parameter_to_edit)) {
    case 1:
        while (true) {
            cout << "Название Трубы ~ ";
            getline(cin, new_pipe_name);

            if (new_pipe_name.length() > 0) {
                pipe_vector[stoi(pipe_id_to_edit)-1].name = new_pipe_name;
                break;
            } 
            else cout << "!! Название не может быть пустым !!" << endl;
        }
        break;
    case 2:
        while (true) {
            cout << "Длина Трубы ~ ";
            getline(cin, new_pipe_lenght);

            if (int_check(new_pipe_lenght) == 1) {
                if (stoi(new_pipe_lenght) > 0) {
                    pipe_vector[stoi(pipe_id_to_edit)-1].length = stoi(new_pipe_lenght);
                    break;
                }
                else cout << "!! Длина должна быть больше 0 !!";
            } 
            else cout << "!! Некорректное значение !!" << endl;
        }
        break;

    case 3:
        while (true) {
            cout << "Диаметр Трубы ~ ";
            getline(cin, new_pipe_diameter);

            if (int_check(new_pipe_diameter) == 1) {
                if (stoi(new_pipe_diameter) > 0) {
                    pipe_vector[stoi(pipe_id_to_edit) - 1].diameter = stoi(new_pipe_diameter);
                    break;
                } 
                else cout << "!! Диаметр должен быть больше 0 !!";
            } 
            else cout << "!! Некорректное значение !!" << endl;
        }
        break;

    case 4:
        while(true) {
            cout << "В ремонте [Y/N] ~ ";
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
            else cout << "!! Некорректное значение !!" << endl;
        }
        break;
    }
}


void edit_cs() {
    string cs_id_to_edit, cs_parameter_to_edit, new_cs_name, new_cs_workshops, new_cs_workshops_in_work, new_cs_efficiency;
    bool correct_input{0};

    while (true) {
        cout << "Номер КС (Всего КС: "<< cs_vector.size()<<")\n~ ";
        getline(cin, cs_id_to_edit);
        if (cs_id_to_edit.length() == 0) break;
        
        else if (int_check(cs_id_to_edit) == 1) {
            if (stoi(cs_id_to_edit)-1 >= 0 && stoi(cs_id_to_edit)-1 < cs_vector.size()){
                break;
            }
            else cout << "!! Некорректное значение !!" << endl;
        }
        else cout << "!! Некорректное значение !!" << endl;
    }
    if (cs_id_to_edit.length() != 0) {
        out_cs(stoi(cs_id_to_edit) - 1, cs_vector[stoi(cs_id_to_edit) - 1].name,
        cs_vector[stoi(cs_id_to_edit) - 1].workshops, cs_vector[stoi(cs_id_to_edit) - 1].workshops_in_work,
        cs_vector[stoi(cs_id_to_edit) - 1].efficiency);

    }
    else return;

    while (true) {
        cout << "\nВыберите параметр КС:\n1 - Название\n2 - Кол-во заводов\n3 - Кол-во работающих заводов"
        << "\n4 - Эффективность\n ~ ";
        getline(cin, cs_parameter_to_edit);

        if (int_check(cs_parameter_to_edit) == 1) {
            if (stoi(cs_parameter_to_edit) >= 1 && stoi(cs_parameter_to_edit) <= 4) break;
            else cout << "!! Значение должно быть в пределах (1, 4) !!" << endl;
        } 
        else cout << "!! Некорректное значение !!" << endl;
    }

    switch (stoi(cs_parameter_to_edit)) {
    case 1:
        while (true) {
            cout << "Название КС ~ ";
            getline(cin, new_cs_name);

            if (new_cs_name.length() > 0) break;
            else cout << "!! Название не может быть пустым !!"; 
        }
        cs_vector[stoi(cs_id_to_edit)-1].name = new_cs_name;
        break;
    case 2:
        while(correct_input != 1) {
            cout << "Кол-во заводов ~ ";
            getline(cin, new_cs_workshops);

            correct_input = int_check(new_cs_workshops);

            if (correct_input == 0) cout << "!! Некорректное значение !!" << endl;
        }
        cs_vector[stoi(cs_id_to_edit) - 1].workshops = stoi(new_cs_workshops);
        break;
    case 3:
        while (true) {
            cout << "Кол-во работающих заводов ~ ";
            getline(cin, new_cs_workshops_in_work);
            correct_input = int_check(new_cs_workshops_in_work);
            if (correct_input == 0) cout << "!! Некорректное значение !!" << endl;
            else if (correct_input == 1) {
                if (stoi(new_cs_workshops_in_work) > cs_vector[stoi(cs_id_to_edit) - 1].workshops) 
                cout << "!! Кол-во рабочих заводов не может превышать общее кол-во заводов !!" << endl;
                else break;
            }
        }
        cs_vector[stoi(cs_id_to_edit) - 1].workshops_in_work = stoi(new_cs_workshops_in_work);
        break;
    case 4:
        while(true) {
            cout << "Эффективность (%) ~ ";
            getline(cin, new_cs_efficiency);

            correct_input = int_check(new_cs_efficiency);

            if (correct_input == 0) cout << "!! Некорректное значение !!" << endl;
            else if (correct_input == 1) {
                if (stoi(new_cs_efficiency) >= 0 && stoi(new_cs_efficiency)<= 100) break;
                else cout << "!! Значение должно быть в пределах (0, 100) !!" << endl;
            }
        }
        cs_vector[stoi(cs_id_to_edit) - 1].efficiency = stoi(new_cs_efficiency);
        break;
    }
}


inline bool for_save_files (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    }
    else return false; 
}


void save_file() {
    fstream config;
    string config_name, rewrite_status;
    bool rewrite_status_check{1};

    cout << "\nИмя файла ~ ";
    getline(cin, config_name);

        if (for_save_files(config_name+".txt") == 1) {
        while (true) {
            cout << "Вы точно хотите заменить файл? [Y/N] ~ ";
            getline(cin, rewrite_status);

            if (y_or_n_check(rewrite_status) == 1){
                rewrite_status_check = 1;
                break;
            }
            else if (y_or_n_check(rewrite_status) == 0) {
                rewrite_status_check = 0;
                break;
            } 
            else cout << "!! Некорректное значение !!" << endl;
        }            
    }

    if (rewrite_status_check == 1){
        config.open(config_name + ".txt", ios::out);

        for (int i = 0; i < pipe_vector.size(); i++) {
        config << ", p," << pipe_vector[i].name << "," << pipe_vector[i].length <<
        "," <<  pipe_vector[i].diameter << "," << pipe_vector[i].repair_status << endl;
        }
        for (int i = 0; i < cs_vector.size(); i++) {
            config << ", c," << cs_vector[i].name << "," << cs_vector[i].workshops <<
            "," <<  cs_vector[i].workshops_in_work << "," << cs_vector[i].efficiency << endl;
        }
        config.close();
    }
}


int load_file() {
    string loadname, tempstr, line;
    ifstream loadfile;
    int wordcount;
    bool file_load_suc_status;

    cout << "Имя файла ~ ";
    getline(cin, loadname);

    loadfile.open(loadname + ".txt");

    if (loadfile) {
        while (loadfile >> tempstr) {
            string ptempname, ptemplen, ptempdim, ptempstat,
            ctempname, ctempwork, ctempworkon, ctempeff;

            getline(loadfile, line);
            wordcount = 0;

            if (string(1, line[1]) == "p") {
                for (int i = 3; i < line.length(); i++) {
                    if (string(1, line[i]) != "," && wordcount == 0) ptempname += string(1, line[i]);
                    else if (string(1, line[i]) == ",") wordcount += 1;
                    else if (string(1, line[i]) != "," && wordcount == 1) ptemplen += string(1, line[i]);
                    else if (string(1, line[i]) != "," && wordcount == 2) ptempdim += string(1, line[i]);
                    else if (string(1, line[i]) != "," && wordcount == 3) ptempstat += string(1, line[i]);
                }
                pipe_vector.push_back(pipe_structure{ptempname,stoi(ptemplen), stoi(ptempdim), ptempstat});
            }

            else if (string(1, line[1]) == "c") {
                for (int i = 3; i < line.length(); i++) {
                    if (string(1, line[i]) != "," && wordcount == 0) ctempname += string(1, line[i]);
                    else if (string(1, line[i]) == ",") wordcount += 1;
                    else if (string(1, line[i]) != "," && wordcount == 1) ctempwork += string(1, line[i]);
                    else if (string(1, line[i]) != "," && wordcount == 2) ctempworkon += string(1, line[i]);
                    else if (string(1, line[i]) != "," && wordcount == 3) ctempeff += string(1, line[i]);
                }
                cs_vector.push_back(cs_structure{ctempname, stoi(ctempwork), stoi(ctempworkon), stoi(ctempeff)});
            }
        }
        loadfile.close();
        return 1;
    }

    else {
        cout << "!! Файл с таким именем не найден !!" << endl;
        return 0;
    }
}


int menu() {
    bool main_menu_flag{1};
    string user_menu_insert;

    while (main_menu_flag) {

        bool menu_number_isdig{1};

        cout << "\n1. Добавить Трубу" << endl;
        cout << "2. Добавить Компрессорную Станцию" << endl;
        cout << "3. Список всех объектов" << endl;
        cout << "4. Редактировать Трубу" << endl;
        cout << "5. Редактировать Компрессорную Станцию" << endl;
        cout << "6. Сохранить" << endl;
        cout << "7. Загрузить" << endl;
        cout << "0. Выход" << endl;
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

            else cout << "\n!! Некорректное значение !!\n" << endl;
        }

        else cout << "\n!! Некорректное значение !!\n" << endl;
    }
    return stoi(user_menu_insert);
}


int main() {
    int user_choice_in_main_menu;
    bool program_cycle{1}, file_saved_status{1}, load_without_save{0}, success_load;
    string load_without_saving_string, exit_without_saving_string;
 
    while (program_cycle) {
        user_choice_in_main_menu = menu();

        switch (user_choice_in_main_menu) {
            case 0:
                if (file_saved_status == 0) cout << "!! Не сохранено !!" << endl;
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
                save_file();
                file_saved_status = 1;
                break;
            case 7:
                load_without_save = 0;
                if (file_saved_status == 0){
                    while (true) {
                        cout << "Are you sure you want to load file without saving? [Y/N] ~ ";
                        getline(cin , load_without_saving_string);
                        if (y_or_n_check(load_without_saving_string) == 1) {
                            load_without_save = 1;
                            break;
                        } 
                        else if (y_or_n_check(load_without_saving_string) == 0){
                            load_without_save = 0;
                            break;
                        } 
                        else cout << "!! Некорректное значение !!" << endl;
                    }
                }
                if (file_saved_status == 1 || load_without_save == 1) {        
                    success_load = load_file();
                    if (success_load == 1) file_saved_status = 0;
                }
                break;
        }
    }
    return 0;
}