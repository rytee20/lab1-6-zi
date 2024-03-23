#include <iostream>
#include <fstream>
#include <unordered_map>

int main() {
    setlocale(LC_ALL,"RUS");

    // Запрос имени файла у пользователя
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    // Открываем файл в двоичном режиме
    std::ifstream file(filename, std::ios::binary);

    // Проверяем, успешно ли открылся файл
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return 1;
    }

    // Используем unordered_map для подсчета частот байтов
    std::unordered_map<unsigned char, int> byteFrequency;

    // Считываем байты из файла и увеличиваем соответствующие частоты
    char byte;
    while (file.get(byte)) {
        byteFrequency[static_cast<unsigned char>(byte)]++;
    }

    // Закрываем файл
    file.close();

    // Выводим результаты
    std::cout << "Относительные частоты байтов в файле:" << std::endl;
    for (const auto& pair : byteFrequency) {
        std::cout << "Байт 0x" << std::hex << static_cast<int>(pair.first) << ": "
            << std::dec << pair.second << " раз" << std::endl;
    }

    return 0;
}
