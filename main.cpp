#include <iostream>
#include <map>
#include <array>

void displayMenu() {
    std::cout << "[1] Wyswietl kontakty" << std::endl;
    std::cout << "[2] Znajdz kontakt" << std::endl;
    std::cout << "[3] Edytuj kontakt" << std::endl;
    std::cout << "[4] Dodaj kontakt" << std::endl;
    std::cout << "[5] Usun kontakt" << std::endl;
    std::cout << "[6] Wyjscie" << std::endl << std::endl;
}

int choice() {
    displayMenu();

    int choice;

    std::cout << "Wybierz opcje [1-6]: ";
    std::cin >> choice;
    std::cout << std::endl;

    return choice;
}

void displayContacts(std::map<std::string, std::string> &addressBook) {
    int index = 1;

    if (addressBook.empty()) {
        std::cout << "Nie znaleziono kontaktow!" << std::endl << std::endl;
    } else {
        std::cout << "============= KONTAKTY =============" << std::endl;
        for(auto &it : addressBook) {
            std::cout << "[" << index << "] " << it.first << " : " << it.second << std::endl;
            index++;
        }
        std::cout << "============= KONTAKTY =============" << std::endl << std::endl;
    }

}

std::string addContactName() {
    std::string contactName;

    while(true) {
        std::cout << "Nazwa kontaktu: ";
        std::cin >> contactName;

        if (contactName.length() < 3 || contactName.length() > 12) {
            std::cout << "Nazwa kontaktu powinna posiadac od 3 do 12 znakow!" << std::endl << std::endl;
            continue;
        } else {
            return contactName;
        }
    }
}

std::string addPhoneNumber() {
    std::string phoneNumber;

    while(true) {
        std::cout << "Numer telefonu: ";
        std::cin >> phoneNumber;

        if (phoneNumber.length() != 9) {
            std::cout << "Numer telefonu musi obejmowac 9 cyfr!" << std::endl << std::endl;
            continue;
        } else {
            return phoneNumber;
        }
    }
}

std::string findContact() {
    std::string contact;

    while(true) {
        std::cout << "Wprowadz kontakt do wyszukania: ";
        std::cin >> contact;
        std::cout << std::endl;

        return contact;

    }
}

void editContact(std::map<std::string, std::string> &addressBook) {
    std::string contact;
    std::string newNumber;

    std::cout << "Podaj nazwe kontaktu, ktory chcesz edytowac: ";
    std::cin >> contact;

    auto it = addressBook.find(contact);

    while(true) {
        if(it != addressBook.end()) {
            std::cout << "Podaj nowy numer telefonu dla tego kontaktu: ";
            std::cin >> newNumber;

            if(newNumber.length() != 9) {
                std::cout << "Numer musi zawierac 9 cyfr!" << std::endl;
                continue;
            }
            addressBook[contact] = newNumber;
            std::cout << std::endl << "Pomyslnie zmieniono numer telefonu dla kontaktu " << contact << std::endl << std::endl;
            break;
        } else {
            std::cout << "Nie odnaleziono takiego kontaktu!" << std::endl << std::endl;
            break;
        }
    }

}

void deleteContact(std::map<std::string, std::string> &addressBook) {
    std::string contact;

    std::cout << "Podaj nazwe kontaktu, ktory chcesz usunac: ";
    std::cin >> contact;
    std::cout << std::endl;

    auto it = addressBook.find(contact);

    if (it != addressBook.end()) {
        addressBook.erase(contact);
        std::cout << "Pomyslnie usunieto kontakt " << contact << std::endl << std::endl;
    } else {
        std::cout << "Nie znaleziono kontaktu, ktory chcesz usunac!" << std::endl << std::endl;
    }
}

int main() {
    std::map<std::string, std::string> addressBook;

    while(true) {
        int userChoice = choice();

        switch(userChoice) {
            case 1:
                displayContacts(addressBook);
                break;
            case 2: {
                while(true) {
                    std::string contact = findContact();

                    auto it = addressBook.find(contact);

                    if(it != addressBook.end()) {
                        std::cout << "====================================================" << std::endl;
                        std::cout << "Wyszukany kontakt: " << it->first << " ---> " << it->second << std::endl;
                        std::cout << "====================================================" << std::endl;
                        std::cout << std::endl;
                        break;
                    } else {
                        std::cout << "Nie znaleziono kontaktu!" << std::endl << std::endl;
                        break;
                    }
                }
                break;
            }
            case 3:
                editContact(addressBook);
                break;
            case 4: {
                std::string contactName = addContactName();
                std::string phoneNumber = addPhoneNumber();
                std::cout << "Pomyslnie dodano nowy kontakt!" << std::endl << std::endl;

                addressBook.insert(std::make_pair(contactName, phoneNumber));
                break;
            }
            case 5:
                deleteContact(addressBook);
                break;
            case 6:
                std::exit(0);
            default:
                std::cout << "Nieprawidlowa wartosc! Wprowadz wartosc [1-6]" << std::endl << std::endl;
                break;
        }
    }
}

// Prosta książka adresowa (kontakt : numer telefonu) i podstawowe operacje na niej