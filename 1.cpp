#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "RUS");

    // Укажите путь к файлу DOC
    const char* filePath = "D:/VisualStudioProjects/ZI/LAB1/first.doc";

    // Открываем файл в бинарном режиме
    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    // Определяем размер файла
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::cout << "Размер файла " << filePath << ": " << fileSize << " байт" << std::endl;

    // Закрываем файл
    file.close();

    return 0;
}
