#include <iostream>
#include "core.hpp"

int main(int argC, char* argV[]) {
    std::string fileExt = "";
    std::string desiredFileExt = "";
    if (argC == 1) {
        std::cout << "What file extension you want to change : ";
        std::cin >> fileExt;
        std::cout << "What extension you want to change this extension to : ";
        std::cin >> desiredFileExt;
    } else if (argC < 3) {
        std::cout << "What extension you want to change this extension to : ";
        fileExt = argV[1];
        std::cin >> desiredFileExt;
    } else if (argC == 3) {
        fileExt = argV[1];
        desiredFileExt = argV[2];
    }
    fileExt = (fileExt[0] == '.') ? fileExt : '.' + fileExt;
    desiredFileExt = (desiredFileExt[0] == '.') ? desiredFileExt : '.' + desiredFileExt;
    changeFilesExtensions(fs::current_path(), fileExt, desiredFileExt);
    return 0;
}