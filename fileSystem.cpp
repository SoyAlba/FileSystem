#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <dirent.h>
void crateFile();
void reaadFile();
void listFiles();
void renameFile();
void deleteFile();
bool fileExists(char nameFile[100]);
void menu();
int main(){
    menu();
    system("pause");
    return 0;
}
void menu(){
    int opcion;
    retrunMenu:
    system("cls");
    std::cout<<"1.- List files\n";
    std::cout<<"2.- Read files\n";
    std::cout<<"3.- Create file\n";
    std::cout<<"4.- Remove file\n";
    std::cout<<"5.- Rename file\n";
    std::cout<<"6.- Exit\n";
    std::cout<<"Select Select an option:";
    std::cin>>opcion;
    std::cin.ignore();
    switch (opcion)
    {
    case 1:
        listFiles();
        system("pause");
        goto retrunMenu;
        break;
    case 2:
        reaadFile();
        system("pause");
        goto retrunMenu;
        break;
    case 3:
        crateFile();
        system("pause");
        goto retrunMenu;
        break;
    case 4:
        deleteFile();
        system("pause");
        goto retrunMenu;
        break;
    case 5:
        renameFile();
        system("pause");
        goto retrunMenu;
        break;

    default:
        return;
        break;
    }
}
void reaadFile(){
    std::string text;
    std::fstream file;
    char fileName[50];
    std::cout<<"path of the file you want to see:";
    std::cin>> fileName;
    file.open(fileName,std::ios::in);
    if(file.fail()==true){
        std::cout<<"your file could not be read: "<<strerror(errno)<<"\n";
        return;
    }
    while (!file.eof()){
        std::getline(file, text);
        std::cout<< text<<"\n";
    }
    

}
void crateFile(){
    char nameFile[100],fileText[100];
    std::cout<<"enter your file name: ";
    std::cin.getline(nameFile,100,'\n');
    std::cout<<"enter the text of your file:\n";
    std::cin.getline(fileText,100,'\n');
    std::fstream file;
    file.open(nameFile,std::ios::out);
    if(file.fail()==true){
        std::cout<<"your file could not be created (for some reason the programmer did not want to describe).\n";
        return;
    }
    file<< fileText;
}

void listFiles(){
    std::string dir,elem;
    DIR * direction;
    struct dirent *elements;
    std::cout<<"Enter the path:";
    std::getline(std::cin,dir);
    if(direction =opendir(dir.c_str())){
        while (elements =readdir(direction)){
            if(elements->d_name!="." && elements->d_name!=".." ){
                std::cout<< elements->d_name<<"\n";
            }
        }
    }
    closedir(direction);
}
void renameFile(){
    char originalName[100],newName[100];
    std::cout << "enter the name of the file to rename:";
    std::cin>> originalName;
    if(fileExists(originalName)==true){
        std::cout<<"enter the new name:";
        std::cin>> newName;
        if(rename(originalName, newName)==0){
            std::cout<<"Your file "<< originalName <<" was renamed as "<< newName <<"\n";
        }
    }else{
        std::cout<<"the file " << originalName << " does not exist.\n";
    }
}
void deleteFile(){
    char fileName[100];
    std::cout<<"enter the name of the file to delete:";
    std::cin>> fileName;
    if(fileExists(fileName)==true){
        if(remove(fileName)==0){
            std::cout<<"your file "<< fileName <<" was deleted successfully\n";
        }
    }else{
        std::cout<<"the file " << fileName << " does not exist\n";
    }
}
bool fileExists(char nameFile[100]){
    std::fstream file;
    file.open(nameFile,std::ios::in);
    if(file.good()==true){
        return true;
    }else{
        return false;
    }
}