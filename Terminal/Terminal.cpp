#include "Functions.hpp"

using namespace std;
namespace fs = std::filesystem;

/////////////////////////////////////
void help(const string& args);
void list_files(const string& args);
void print_working_dir(const string& args);
void change_directory(const string& args);
void make_directory(const string& args);
void remove_directory(const string& args);
void make_file(const string& args);
void remove_file(const string& args);
void echo(const string& args);
/////////////////////////////////////

int main() {
    string username = "root";
    string hostname = "Zex";
    string input;
    string prompt = "$";  // prompt symbol

    map<string, function<void(string)>> commands = {
        {"help", help},
        {"exit", [](string) { exit(0); }},
        {"ls", list_files},
        {"pwd", print_working_dir},
        {"cd", change_directory},
        {"mkdir", make_directory},
        {"rmdir", remove_directory},
        {"touch", make_file},
        {"rm", remove_file},
        {"echo", echo},
    };

    while (true) {
        // set text color to cyan and background color to black
        cout << "\033[1;36m\033[40m" << username << "@" << hostname << ":~" << prompt << " ";
        // set text color back to white and background color back to black
        cout << "\033[0m";

        getline(cin, input);

        istringstream iss(input);
        string command;
        iss >> command;

        if (command.empty()) {
            continue;
        }

        auto it = commands.find(command);
        if (it != commands.end()) {
            string args;
            getline(iss, args);
            it->second(args);
        }
        else {
            cout << "\033[1;31m" << command << ": command not found" << endl;
            // set text color back to white and background color back to black
            cout << "\033[0m";
        }
    }
    return 0;
}
