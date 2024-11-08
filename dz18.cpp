#include <iostream>
#include <string>
#include <algorithm> 
#include <cstring> 
using namespace std;


//struct Book {
//    string title;
//    string author;
//    string publisher;
//    string genre;
//};
//
//
//void printBooks(const Book books[], int size) {
//    for (int i = 0; i < size; ++i) {
//        cout << "Книга " << i + 1 << ":\n";
//        cout << "Назва: " << books[i].title << "\n";
//        cout << "Автор: " << books[i].author << "\n";
//        cout << "Видавництво: " << books[i].publisher << "\n";
//        cout << "Жанр: " << books[i].genre << "\n\n";
//    }
//}
//
//
//void editBook(Book& book) {
//    cout << "Введіть нову назву: ";
//    getline(cin, book.title);
//    cout << "Введіть нового автора: ";
//    getline(cin, book.author);
//    cout << "Введіть нове видавництво: ";
//    getline(cin, book.publisher);
//    cout << "Введіть новий жанр: ";
//    getline(cin, book.genre);
//}
//
//
//void searchByAuthor(const Book books[], int size, const string& author) {
//    for (int i = 0; i < size; ++i) {
//        if (books[i].author == author) {
//            cout << "Знайдено книгу:\n";
//            cout << "Назва: " << books[i].title << "\n\n";
//        }
//    }
//}
//
//
//bool compareByTitle(const Book& a, const Book& b) {
//    return a.title < b.title;
//}
//
//int main() {
//    Book books[3] = {
//        {"Book1", "Author1", "Publisher1", "Genre1"},
//        {"Book2", "Author2", "Publisher2", "Genre2"},
//        {"Book3", "Author1", "Publisher3", "Genre3"}
//    };
//
//    printBooks(books, 3);
//}









//union CarNumber {
//    int numeric;             
//    char text[9];            
//};
//
//struct Car {
//    string color;
//    string model;
//    CarNumber number;
//    bool isNumeric;          
//};
//
//void fillCar(Car& car) {
//    cout << "Введіть колір: ";
//    cin >> car.color;
//    cout << "Введіть модель: ";
//    cin >> car.model;
//
//    cout << "Введіть тип номера (1 - числовий, 2 - текстовий): ";
//    int choice;
//    cin >> choice;
//    if (choice == 1) {
//        cout << "Введіть п'ятизначний номер: ";
//        cin >> car.number.numeric;
//        car.isNumeric = true;
//    }
//    else {
//        cout << "Введіть текстовий номер (до 8 символів): ";
//        cin >> car.number.text;
//        car.isNumeric = false;
//    }
//}
//
//
//void printCar(const Car& car) {
//    cout << "Колір: " << car.color << "\n";
//    cout << "Модель: " << car.model << "\n";
//    cout << "Номер: ";
//    if (car.isNumeric) {
//        cout << car.number.numeric << "\n";
//    }
//    else {
//        cout << car.number.text << "\n";
//    }
//}
//
//void editCar(Car& car) {
//    cout << "Редагуємо машину:\n";
//    fillCar(car);
//}
//
//
//void printAllCars(const Car cars[], int size) {
//    for (int i = 0; i < size; ++i) {
//        cout << "\nМашина " << i + 1 << ":\n";
//        printCar(cars[i]);
//    }
//}
//
//void searchCarByNumber(const Car cars[], int size) {
//    cout << "Введіть номер для пошуку: ";
//    char search[9];
//    cin >> search;
//
//    for (int i = 0; i < size; ++i) {
//        if ((cars[i].isNumeric && cars[i].number.numeric == atoi(search)) ||
//            (!cars[i].isNumeric && strcmp(cars[i].number.text, search) == 0)) {
//            cout << "\nЗнайдено машину:\n";
//            printCar(cars[i]);
//            return;
//        }
//    }
//
//    cout << "Машину з таким номером не знайдено.\n";
//}
//
//int main() {
//    const int size = 10;
//    Car cars[size];
//
//    for (int i = 0; i < size; ++i) {
//        cout << "Заповнення машини " << i + 1 << ":\n";
//        fillCar(cars[i]);
//    }
//
//    cout << "\nДрук усіх машин:\n";
//    printAllCars(cars, size);
//
//    cout << "\nПошук машини за номером:\n";
//    searchCarByNumber(cars, size);
//
//    return 0;
//}















enum EntityType { BIRD, CATTLE, HUMAN };


union Characteristic {
    double flightSpeed;  
    bool isClovenHoofed; 
    int iqLevel;         
};


struct LivingEntity {
    double speed;
    EntityType type;
    string color;
    Characteristic characteristic;
};


void inputEntity(LivingEntity& entity) {
    cout << "Швидкість пересування: ";
    cin >> entity.speed;
    cout << "Колір: ";
    cin >> entity.color;

    cout << "Тип (0 - птах, 1 - худоба, 2 - людина): ";
    int typeInput;
    cin >> typeInput;
    entity.type = static_cast<EntityType>(typeInput);

    if (entity.type == BIRD) {
        cout << "Швидкість польоту: ";
        cin >> entity.characteristic.flightSpeed;
    }
    else if (entity.type == CATTLE) {
        cout << "Парнокопитна (1 - так, 0 - ні): ";
        cin >> entity.characteristic.isClovenHoofed;
    }
    else if (entity.type == HUMAN) {
        cout << "Рівень IQ: ";
        cin >> entity.characteristic.iqLevel;
    }
}


void printEntity(const LivingEntity& entity) {
    cout << "Швидкість: " << entity.speed << ", Колір: " << entity.color << ", Тип: ";

    if (entity.type == BIRD) {
        cout << "Птах, Швидкість польоту: " << entity.characteristic.flightSpeed << "\n";
    }
    else if (entity.type == CATTLE) {
        cout << "Худоба, Парнокопитна: " << (entity.characteristic.isClovenHoofed ? "Так" : "Ні") << "\n";
    }
    else if (entity.type == HUMAN) {
        cout << "Людина, IQ: " << entity.characteristic.iqLevel << "\n";
    }
}

void searchByType(const LivingEntity entities[], int size, EntityType searchType) {
    cout << "Результати пошуку:\n";
    for (int i = 0; i < size; ++i) {
        if (entities[i].type == searchType) {
            printEntity(entities[i]);
        }
    }
}

int main() {
    const int size = 5;
    LivingEntity entities[size];


    for (int i = 0; i < size; ++i) {
        cout << "\nСутність " << i + 1 << ":\n";
        inputEntity(entities[i]);
    }

 
    cout << "\nУсі сутності:\n";
    for (int i = 0; i < size; ++i) {
        printEntity(entities[i]);
    }


    cout << "\nПошук за типом (0 - птах, 1 - худоба, 2 - людина): ";
    int searchType;
    cin >> searchType;
    searchByType(entities, size, static_cast<EntityType>(searchType));

    return 0;
}
