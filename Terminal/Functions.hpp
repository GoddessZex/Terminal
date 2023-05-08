#include <filesystem>
#include <fstream>
#include <sstream>
#include <map>
#include <functional>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

void help(const string& args) {
    cout << "Available commands:" << endl;
    cout << "  help - Show this help message" << endl;
    cout << "  exit - Exit the terminal" << endl;
    cout << "  ls - List files in the current directory" << endl;
    cout << "  pwd - Print the current working directory" << endl;
    cout << "  cd [dir] - Change the current directory to [dir]" << endl;
    cout << "  mkdir [dir] - Create a new directory" << endl;
    cout << "  rmdir [dir] - Remove an empty directory" << endl;
    cout << "  touch [file] - Create a new file" << endl;
    cout << "  rm [file] - Remove a file" << endl;
    cout << "  echo [message] - Print [message] to the console" << endl;
}

void list_files(const string& args) {
    cout << "Files in the current directory:" << endl;
    for (const auto& entry : fs::directory_iterator(".")) {
        cout << entry.path().filename() << endl;
    }
}

void print_working_dir(const string& args) {
    cout << "Current working directory: " << fs::current_path().string() << endl;
}

void change_directory(const string& args) {
    try {
        fs::current_path(args);
        cout << "Changing directory to " << args << endl;
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}

void make_directory(const string& args) {
    try {
        fs::create_directory(args);
        cout << "Created directory " << args << endl;
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}

void remove_directory(const string& args) {
    try {
        fs::remove(args);
        cout << "Removed directory " << args << endl;
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}

void make_file(const string& args) {
    try {
        std::ofstream file(args);
        file.close();
        cout << "Created file " << args << endl;
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}

void remove_file(const string& args) {
    try {
        fs::remove(args);
        cout << "Removed file " << args << endl;
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}

void echo(const string& args) {
    cout << args << endl;
}