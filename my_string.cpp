// хочу свою строку изменяемого размера!
// добавление символа в конец
// удаление символа с конца

// С английскими буквами все ок. С русскими не очень... (из-за кодировки (не все буквы 1 байт)?)

// Добавить сложение строк
// не очень удобно передавать везде длину. Надо делать структуру
// Что бы при создании выделять память надо СДЕЛАТЬ НОВУЮ ФУНКЦИЮ, чтоб она возвращала структуру String

#include <stdio.h>
#include <malloc.h>


struct String
{
    char* the_string;
    int size;
};


String new_str(int size); // С вводом или без? Если без, тогда добавление (начальное) только циклом через getchar()

void print_str(const String str_1);
void clear_buffer();
bool add_elem(char elem, String* str_1);
bool pop_elem(String* str_1);

// bool sum_str();


int main()
{
    printf("Введите начальную длину строки:\n");

    int str_size = 0;
    scanf("%d", &str_size);
    str_size++;

    String str_1 = new_str(str_size);
    clear_buffer();


    // Ввод начальной строки
    for (int i = 0; i < (str_size - 1); i++)
    {
        char c = '0';
        c = getchar();
        str_1.the_string[i] = c;
    }
    str_1.the_string[str_size - 1] = '\0';

    clear_buffer();

    // Вывод начальной строки (проверка)
    print_str(str_1);



    // это можно в add_elem тоже добавить, но тогда функция будет не очень в использовании
    printf("Введите добавляемый символ:\n");
    char sim = '0';
    scanf("%c", &sim);

    clear_buffer();

    // Добавляю символ
    if (!add_elem(sim, &str_1)) printf("Слишком большая строка. Не удалось расширить.");

    print_str(str_1);

    // Удаляю добавленный
    if (!pop_elem(&str_1)) printf("Не удалось уменьшить строку.");

    print_str(str_1);


    free(str_1.the_string); str_1.the_string = NULL;
}


String new_str(int size)
{
    String strin = {NULL, 0}; // норм ли будет менять указатель на NULL? В чате что-то было...
    strin.size = size;

    strin.the_string = (char*) calloc(size, sizeof(char));
    if (strin.the_string == NULL)
    {
        printf("Неудалось выделить память заданного размера\n"); // не очень сообщение об ошибке. Надо бы заканчивать ф-ию
        strin.size = 0;
    }

    return strin;
}


void print_str(const String str_1) // коприрование!
{
    puts(str_1.the_string);
}


bool add_elem(char elem, String* str_1)
{
    (*str_1).the_string = (char*) realloc((*str_1).the_string, ((*str_1).size + 1) * sizeof(char));
    if ((*str_1).the_string == NULL) return false;

    ((*str_1).the_string)[(*str_1).size - 1] = elem;
    ((*str_1).the_string)[(*str_1).size] = '\0';

    ((*str_1).size)++;

    return true;
}


bool pop_elem(String* str_1)
{
    (*str_1).the_string = (char*) realloc((*str_1).the_string, ((*str_1).size - 1) * sizeof(char)); // уменьшаю размер
    if ((*str_1).the_string == NULL) return false;

    ((*str_1).the_string)[(*str_1).size - 2] = '\0';

    ((*str_1).size)--;

    return true;
}


void clear_buffer()
{
    int c = 0;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        continue;
    }
}
