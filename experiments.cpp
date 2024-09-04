#include <stdio.h>

int main()
{
    char s = 'A';
    printf("%d\n", s);
    printf("%c\n", s);
    // printf("%s\n", s); ошибка

    char* uk = NULL;
    uk = &s; // указатель на char

    char ps_str[4] = ""; // '\0' '\0' '\0' '\0'
    // ps_str[1] = 'a';
    // puts(ps_str + 1);  вывод через + указатели

    char ps2[4] = "abc";
    puts(ps2);           // abc
    puts(ps2 + 1);       // bc
    // Изменяю строку... Процесс копирования..! (Сначала в сегмент констант, а это копия?)
    ps2[1] = 'q';
    puts(ps2);

    char ps3[] = "qwerty";
    puts(ps3); // qwerty
    // Добавление символов..? Занимаем рандомные куски памяти, это норм?
    ps3[6] = 'u';
    ps3[7] = '\0';
    puts(ps3); // qwertyu
    // ps3++; неизменяемый
    puts(ps3);

    const char* strin = "EDA";

    printf("%c\n", *(strin + 1));
    printf("%c\n", strin[1]);
    printf("%d\n", *(strin + 1));

    printf("%c\n", *("ABC" + 1)); // B
    printf("%c\n", 1["ABC"]);
    // puts(1["AKC"]); - не работает, так как разименовали
    puts(&(1["AKC"])); // KC (передали ссылку! на начало + 1 (K))







}
