#include <iostream>
#include <fstream>

bool checkPNGFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cout << "Cannot open" << std::endl;
        return false;
    }
    
    char header[8];
    file.read(header, 8);
    
    if (file.gcount() < 8) {
        std::cout << "Too short file" << std::endl;
        return false;
    }
    
    return (header[0] == -119 && header[1] == 'P' && header[2] == 'N' && header[3] == 'G');
}

int main() {
    std::string filePath;
    std::cout << "Enter file path: ";
    std::cin >> filePath;
    
    if (checkPNGFile(filePath)) {
        std::cout << "File is PNG" << std::endl;
    } 
}