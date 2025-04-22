#!/bin/bash
set -e

APP=$1

if [ ! -f "$APP" ]; then
echo "Error: binary not found!"
exit 1
fi

run_test() {
local input=$1
local expected=$2
local test_num=$3

output=$(echo "$input" | $APP 2>&1 | grep -oP "Факториал числа \d+ равен: \d+|Ошибка: .*|Неправильный ввод.*|Переполнение.*")

if [[ "$output" == *"$expected"* ]]; then
echo "Тест $test_num: Успех"
return 0
else
echo "Тест $test_num: Неудача. Ожидалось '$expected', получено '$output'"
return 1
fi
}

echo "Запуск тестов..."

run_test "5" "Факториал числа 5 равен: 120" 1
run_test "0" "Факториал числа 0 равен: 1" 2
run_test "1" "Факториал числа 1 равен: 1" 3
run_test "10" "Факториал числа 10 равен: 3628800" 4
run_test "-5" "Факториал не определен для отрицательных чисел." 5
run_test "25" "Переполнение при вычислении факториала." 6

exit 0
