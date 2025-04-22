#include <iostream>
#include <limits>
#include <stdexcept>

long long factorial(int n) {
if (n < 0) {
throw std::invalid_argument("Факториал не определен для отрицательных чисел.");
}
else if (n == 0 || n == 1) {
return 1;
}
else {
long long result = 1;
for (int i = 2; i <= n; ++i) {
if (std::numeric_limits<long long>::max() / i < result) {
throw std::overflow_error("Переполнение при вычислении факториала.");
}
result *= i;
}
return result;
}
}

int readInteger() {
int n;
while (true) {
std::cout << "Введите целое число: ";
if (std::cin >> n) {
if (std::cin.peek() != '\n') {
std::cerr << "Вы ввели нецелое число. Пожалуйста, введите целое число." << std::endl;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
else {
return n;
}
}
else {
std::cerr << "Неправильный ввод. Пожалуйста, введите целое число." << std::endl;
std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
}
}

int main() {
int n = readInteger();

try {
long long fact = factorial(n);
std::cout << "Факториал числа " << n << " равен: " << fact << std::endl;
}
catch (const std::invalid_argument& e) {
std::cerr << "Ошибка: " << e.what() << std::endl;
}
catch (const std::overflow_error& e) {
std::cerr << "Ошибка: " << e.what() << std::endl;
}
catch (const std::exception& e) {
std::cerr << "Неизвестная ошибка: " << e.what() << std::endl;
}

return 0;
}
