#include <iostream>
#include <vector>

struct Polynomial
{
    std::vector<double> coefs;
    int degree;
};

Polynomial integral (Polynomial p)
{
    // Cria o novo polinômio para armazenar a integral
    Polynomial integral;
    integral.degree = p.degree + 1;
    integral.coefs.resize (integral.degree + 1);

    // Calcula os coeficientes da integral
    for (auto i = 0; i <= p.degree; i++)
        integral.coefs[i + 1] = p.coefs[i] / (i + 1);

    return integral;
}

int main()
{
    // Cria um polinômio de grau 2
    Polynomial p;
    p.degree = 2;
    p.coefs = {1, 2, 3}; // 3*x^2 + 2*x +1

    // Calcula a integral do polinômio
    Polynomial integral_p = integral (p);

    // Imprime o polinômio integral
    std::cout << "f(x) = ";
    for (auto i = integral_p.degree; i >= 0; i--)
        std::cout << integral_p.coefs[i] << "x^" << i << " + ";
    std::cout << std::endl;

    return 0;
}
