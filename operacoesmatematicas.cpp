#include <iostream>
#include <cstdlib>
#include <iomanip>

int main()
{
    int a;
    float b;
    char c;
    bool d;

    a = 5;
    b = 2.3;
    c = 'a';
    d = true;

    std::cout << std::fixed << std::setprecision(1);

    std::cout << "\n 0 valor de a = " << a;
    std::cout << "\n 0 valor de b = " << b;
    std::cout << "\n 0 valor de c = " << c;

    std::cout << "\n 0 valor de d = " << d << "\n";


    std::cout << "\nDigite um valor para 'a' (int): ";
    std::cin >> a;
    std::cout << "Digite um valor para ' b' (float): ";
    std::cin >> b;
    std::cout << "Digite um valor para 'c' (char):";
    std::cin >> c; // std::cin por padrão já ignora espaços em branco antes do char
    std::cout << "Digite um valor para 'd' (0 ou 1): ";
    std::cin >> d; // std::cin lê 0 como false e 1 (ou qualquer outro não-zero) como true


    std::cout << "\n O valor de a = " << a;
    std::cout << "\n O valor de b = " << b;
    std::cout << "\n O valor de c = " << c;
    std::cout << "\n O valor de d = " << d << "\n";

    system("pause");

    return 0;

}