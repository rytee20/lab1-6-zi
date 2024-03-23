#include <iostream>
#include <fstream>
#include <vector>

void processFile(const std::string& inputFileName, const std::string& outputFileName, const std::vector<unsigned char>& key, bool encrypt) {
    std::ifstream inputFile(inputFileName, std::ios::binary);
    std::ofstream outputFile(outputFileName, std::ios::binary);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return;
    }

    char byte;
    size_t keyIndex = 0;

    while (inputFile.get(byte)) {
        if (encrypt) {
            // Шифрование: замена каждого байта с использованием ключа
            byte ^= key[keyIndex];
        }
        else {
            // Расшифрование: замена каждого байта с использованием ключа
            byte ^= key[keyIndex];
        }

        outputFile.put(byte);

        // Переход к следующему элементу ключа (циклический сдвиг)
        keyIndex = (keyIndex + 1) % key.size();
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    std::string keyFileName = "D:\\VisualStudioProjects\\ZI\\LAB1\\key.txt";
    std::vector<unsigned char> key;

    // Загрузка ключа из файла
    std::ifstream keyFile(keyFileName, std::ios::binary);
    if (!keyFile.is_open()) {
        std::cerr << "Error opening key file." << std::endl;
        return 1;
    }

    char keyByte;
    while (keyFile.get(keyByte)) {
        key.push_back(static_cast<unsigned char>(keyByte));
    }

    keyFile.close();

    // Выбор режима работы программы
    char mode;
    std::cout << "Enter 'e' for encryption or 'd' for decryption: ";
    std::cin >> mode;

    if (mode == 'e' || mode == 'E' || mode == 'd' || mode == 'D') {
        std::string inputFileName, outputFileName;
        std::cout << "Enter input file name: ";
        std::cin >> inputFileName;
        std::cout << "Enter output file name: ";
        std::cin >> outputFileName;

        bool encrypt = (mode == 'e' || mode == 'E');

        // Обработка файла в соответствии с выбранным режимом
        processFile(inputFileName, outputFileName, key, encrypt);

        std::cout << (encrypt ? "Encryption" : "Decryption") << " completed successfully." << std::endl;
    }
    else {
        std::cerr << "Invalid mode. Please enter 'e' or 'd'." << std::endl;
        return 1;
    }

    return 0;
}
