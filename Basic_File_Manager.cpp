/*
    creator: vinayak-kumar-sharma
    Task: Basic file manager CLI 

*/





#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem> //file handling
#include <vector> // for data structure
#include <algorithm> //for algorithm
using namespace std;
namespace fs =filesystem;

void displayPrompt ( string& currentPath ) {
    cout << "Command-Line File Manager\n";
    cout << "Current Directory: " << currentPath << "\n";
    cout << "$ ";
}

// function to list down files and folder
void listFilesAndDirectories (const string& path ) {
    for (const auto& entry : fs::directory_iterator(path)) {
        cout << entry.path().filename() << "\n";
    }
}

// function to create file and folder
void createDirectory (const string& path, const string& dirName ) {
    fs::create_directory( path + "/" + dirName );
    cout << "Directory created successfully.\n";
}

// function to copy file and folder
void copyFile (const string& sourcePath, const string& destinationPath ) {
    copy_file ( sourcePath, destinationPath, fs::copy_options::overwrite_existing );
    cout << "File copied successfully.\n";
}

// function move file and folder
void moveFile (const string& sourcePath, const string& destinationPath ) {
    fs::rename(sourcePath, destinationPath);
    cout << "File moved successfully.\n";
}

// function to remove file and folders.
void removeFileOrDirectory (const string& path ) {
    fs::remove_all(path);
    cout << "File or directory removed successfully.\n";
}

// this function helps to view file
void viewFile( const string &filePath ) {
    ifstream file(filePath);
    if (file)
    {
        cout << filePath<<"\n";
        cout <<endl;
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        cout <<endl;
        file.close();
    }
    else
    {
        cout << "Error: Unable to open file.\n";
    }
}

//  this is a help funuction
void displayHelp() {
    cout << "Available Commands:\n";
    cout << "ls           : List files and directories\n";
    cout << "cd <dir>     : Change directory\n";
    cout << "mkdir <dir>  : Create directory\n";
    cout << "cp <source> <destination> : Copy file\n";
    cout << "mv <source> <destination> : Move file\n";
    cout << "rm <file/dir>: Remove file or directory\n";
    cout << "cat <file>  : View file contents\n"; 
    cout << "help         : Display available commands and their usage\n";
    cout << "exit         : Exit the file manager\n";
}

int main () {
    string currentPath = ".";  // Initial path is the current directory


//  control flow statements for commands 
    while ( true ) {
        displayPrompt( currentPath );

        string command;
        cin >> command;

        if ( command == "ls" ) {
            listFilesAndDirectories(currentPath);
        } 
        else if ( command == "cd" ) {
            string newDir;
            cin >> newDir;
            currentPath = fs::canonical(currentPath + "/" + newDir).string();
        } 
        else if ( command == "mkdir" ) {
            string dirName;
            cin >> dirName;
            createDirectory( currentPath, dirName );
        } 
        else if ( command == "cp" ) {
            string sourceFile, destFile;
            cin >> sourceFile >> destFile;
            copyFile ( currentPath + "/" + sourceFile, currentPath + "/" + destFile );
        } 
        else if ( command == "mv" ) {
            string sourceFile, destFile;
            cin >> sourceFile >> destFile;
            moveFile ( currentPath + "/" + sourceFile, currentPath + "/" + destFile );
        } 
        else if ( command == "rm" ) {
            string target;
            cin >> target;
            removeFileOrDirectory ( currentPath + "/" + target );
        } 
        else if ( command == "cat" ) {
            string target;
            cin >> target;
            viewFile(currentPath + "/" + target);
        } 
        else if ( command == "help" ) {
            displayHelp ();
        }
        else if ( command == "exit" ) {
            cout << "Exiting the file manager.\n";
            break;
        }
        else {
            cout << command <<"  invalid command, try again. Type 'help' for command usage.\n";
        }
    }

    return 0;
}
