#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}


//TODO
//Напоминаю! Использовать scanf для ввода данных запрещено, если иное не обговорено в условии!
//На каждое ДЗ надо сделать хотя бы 2 Run Config с тестовыми данными и сохранить их как файлы проекта.
//Также при выполнении каждого задания использовать разделение на файлы.
// В main.c должна находится только функция main() и #include "main.h". В других .c файлах находятся
// только сами функции. Все остальные вещи должны быть вынесены в соответствующий .h файл

// 1. Разработать программу, которая выводит разницу
// во времени между двумя введенными датами. Даты вводятся с помощью аргументов в формате
// calc_dates "DD.MM.YYYY HH:MM:SS" "DD.MM.YYYY HH:MM:SS"
// calc_dates "01.01.1970 13:37:42" "31.12.1988 23:58:00"