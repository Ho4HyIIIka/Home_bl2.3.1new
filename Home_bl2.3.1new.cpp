#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

class Addres {
private:
    std::string sity;
    std::string street;
    int home;
    int apart;
public:
    void set_init(std::string sity, std::string street, int home, int apart) {
        this->sity = sity;
        this->street = street;
        this->home = home;
        this->apart = apart;
    }
    int conv(std::string a) {
        int a2 = 0;
        a2 = std::stoi(a);
        return a2;
    }
    std::string get_sity() {
        std::string b = sity;
        return b;
    }
    std::string get_street() {
        std::string b = street;
        return b;
    }
    int get_home() {
        int b = home;
        return b;
    }
    int get_apart() {
        int b = apart;
        return b;
    }
};

int main()
{
    std::ifstream file("TextFile1.txt");
    int c = 0;
    file >> c;

    Addres* C = new Addres[c];

    for (int i = 0; i < c; i++) {
        std::string d1, d2, d3, d4;
        int d5 = 0, d6 = 0;
        file >> d1 >> d2 >> d3 >> d4;

        d5 = C[i].conv(d3);
        d6 = C[i].conv(d4);

        C[i].set_init(d1, d2, d5, d6);
    }

    std::ofstream file_off("out.txt");
    file_off << c << std::endl;
    for (int i = c - 1; i > -1; i--) {
        file_off << C[i].get_sity() << ", " << C[i].get_street() << ", " << C[i].get_home() << ", " << C[i].get_apart() << std::endl;;
        std::cout << C[i].get_sity() << ", " << C[i].get_street() << ", " << C[i].get_home() << ", " << C[i].get_apart() << std::endl;

    }

    delete[]C;
    file.close();
    file_off.close();

    return 0;
}