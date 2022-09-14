#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

fstream config;

bool saved = false;
string fillpipe(string arr[]);
string line;
int linecount;

void public_pipe(string name, int& len, int& dim, string rep){
    /*string strlen = to_string(len);
    string strdim = to_string(dim);
    string pipe[4] = {name, strlen, strdim, rep};
    
    string pipearr = fillpipe(pipe);*/
}

//Pipe

string pipname;
int pipelen;
int pipediameter;
char piperepair;

//Cs
string csname;
int workshops;
int workshopsinwork;
int efficiency;
string path = "C:/Users/batut/OneDrive/Documents/GitHub/crossplatform/Task2/config.csv";


void main_menu(int& pipes, int& css){

    int menuvall;

    cout << "\n1. Add pipe" << endl;
    cout << "2. Add compressor station" << endl;
    cout << "3. View object list" << endl;
    cout << "4. Edit pipe" << endl;
    cout << "5. Edit compressor station" << endl;
    cout << "6. Save" << endl;
    cout << "7. Load" << endl;
    cout << "0. Exit" << endl;
    cout << "-> ";
    cin >> menuvall;

    if (menuvall <= 7 && menuvall >= 0){
        switch (menuvall) {
            case 1:
                if (pipes == 0){
                //cout << "1";

                
                cout << "Title: ";
                cin >> pipname;

                
                cout << "Length: ";
                cin >> pipelen;

                
                cout << "Diameter: ";
                cin >> pipediameter;

                while (true){
                
                cout << "Under repair (Y/N):";
                cin >> piperepair;

                if (tolower(piperepair) == 'y' || tolower(piperepair) == 'n'){
                    /*config << pipname << ", "
                        << pipelen << ", "
                        << pipediameter << ", "
                        << piperepair << "\n"; */
                    piperepair = toupper(piperepair);
                    break;
                }
                }
                //cin.ignore();
                pipes += 1;
                
                } else if (pipes == 1){
                    cout << "Pipe already exists" << endl;
                }
                main_menu(pipes, css);
                break;
            case 2:
                if (css == 0) {
                    
                    cout << "Title: ";
                    cin >> csname;

                    
                    cout << "Number of workshops: ";
                    cin >> workshops;

                    
                    cout << "Number of workshops in work: ";
                    cin >> workshopsinwork;

                    
                    cout << "Efficiency: ";
                    cin >> efficiency;

                    /*config << csname << ", "
                            << workshops << ", "
                            << workshopsinwork << ", "
                            << efficiency << "\n";*/
                    css += 1;
                } else if (css == 1) {
                    cout << "Compressor station already exists" << endl;
                }

                main_menu(pipes, css);
                break;
            case 3:
                
                config.open(path, ios::in);

                if (config.is_open()){
                    linecount = 0;
                    while (getline(config, line)){

                        if (linecount == 0){
                            cout << "\nPipe:" << endl;
                        } else if (linecount == 1) {
                            cout << "\nCompressor station:" << endl;
                        }

                        cout << line << endl;
                        linecount+=1;
                    }
                }

                config.close();
                main_menu(pipes, css);
                break;
            case 4:
                if (pipes == 1){
                int pipeedit;
                while (true){
                    cout << "Select option:" << endl;
                    cout << "1 - title" << endl;
                    cout << "2 - length" << endl;
                    cout << "3 - diameter" << endl;
                    cout << "4 - repair status" << endl;
                    cout << "-> ";
                    cin >> pipeedit;
                    if (pipeedit <= 4 && pipeedit >= 1){
                        break;
                    }
                }
                switch (pipeedit){
                    case 1:
                        cout << "Enter new title: ";
                        cin >> pipname;
                        break;
                    case 2:
                        cout << "Enter new length: ";
                        cin >> pipelen;
                        break;
                    case 3:
                        cout << "Enter new diameter: ";
                        cin >> pipediameter;
                        break;
                    case 4: 
                        while (true){
                            cout << "Enter new repair status (Y/N): ";
                            cin >> piperepair;
                            if (tolower(piperepair) == 'y' || tolower(piperepair) == 'n'){
                                piperepair = toupper(piperepair);
                                break;
                            }
                        }
                        break;
                }
                } else if (pipes == 0){
                    cout << "Pipe does not exist" << endl;
                }
                //cout << pipeedit << endl;
                main_menu(pipes, css);
                break;
            case 5:
                if (css == 1){
                int csedit;
                while (true){
                    cout << "Select option:" << endl;
                    cout << "1 - title" << endl;
                    cout << "2 - length" << endl;
                    cout << "3 - diameter" << endl;
                    cout << "4 - repair status" << endl;
                    cout << "-> ";
                    cin >> csedit;
                    if (csedit <= 4 && csedit >= 1){
                        break;
                    }
                }
                switch (csedit){
                    case 1:
                        cout << "Enter new title: ";
                        cin >> csname;
                        break;
                    case 2:
                        cout << "Enter new number of workshops: ";
                        cin >> workshops;
                        break;
                    case 3:
                        cout << "Enter new number of workshops in work: ";
                        cin >> workshopsinwork;
                        break;
                    case 4: 
                        cout << "Enter new efficiency: ";
                        cin >> efficiency;
                        break;
                }
                } else if (css == 0){
                    cout << "Compressor station does not exist" << endl;
                }
                main_menu(pipes, css);
                break;
            case 6:
                while(true){

                char savestat;
                cout << "Are you sure you want to save this data? (Y/N): ";
                cin >> savestat;

                if (tolower(savestat) == 'y' || tolower(savestat) == 'n'){
                
                if (tolower(savestat) == 'y'){
                config.open(path, ios::out);
                if (pipes == 1){
                    config << pipname << ", "
                        << pipelen << ", "
                        << pipediameter << ", "
                        << piperepair;
                } else if (pipes == 0){
                    config << "";
                }
                if (css == 1){
                    config << "\n" << csname << ", "
                            << workshops << ", "
                            << workshopsinwork << ", "
                            << efficiency;
                } else if (css == 0){
                    config << "";
                }
                config.close();
                saved = true;
                }
                break;
                }
                }
                main_menu(pipes, css);
                break;
            case 7:
                char newpath;
                while (true){
                cout << "Enter new path or type \"?\" to open file explorer: ";
                cin >> newpath;
                if (tolower(newpath) == '?'){
                    system("explorer C:\\");
                } else {
                    path = newpath;
                    break;
                }                
                }
                main_menu(pipes, css);
                break;
            case 0:
                if (saved == false){
                    
                    while (true){

                        char exitstat;
                        cout << "Are you sure you want to exit without saving? (Y/N): ";
                        cin >> exitstat;

                        if (tolower(exitstat) == 'y' || tolower(exitstat) == 'n'){
                            if (tolower(exitstat) == 'n') {
                                main_menu(pipes, css);
                            }
                            break;
                        }
                    }
                    
                }
                break;

    }
    } else {
        cout << "\n[ERROR] invalid number" << endl;
        main_menu(pipes, css);
    }
    

}


int main(int argc, char** argv){
    
    int pipe_count {0};
    int cs_count {0};
    
    main_menu(pipe_count, cs_count);
    config.close();

}