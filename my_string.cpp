// хочу свою строку изменяемого размера!
// добавление символа в конец
// удаление символа с конца

#include <stdio.h>
#include <malloc.h>


void print_str(char* the_string);
void clear_buffer();
bool add_elem(char elem, char** the_string, int* str_size);


int main()
{
    printf("Введите начальную длину строки:\n");

    int str_size = 0;
    scanf("%d", &str_size);
    str_size++;
    char* the_string = (char*) calloc(str_size, sizeof(char));
    if (the_string == NULL)
    {
        printf("Неудалось выделить память заданного размера\n");
    }

    //printf("%d\n", str_size);

    clear_buffer();

    for (int i = 0; i < (str_size - 1); i++)
    {
        char c = '0';
        c = getchar();
        the_string[i] = c;
        //printf("%d, %c\n", i, c);
    }
    the_string[str_size - 1] = '\0';

    clear_buffer();

    print_str(the_string);

    printf("Введите добавляемый символ:\n");
    char sim = '0';
    scanf("%c", &sim);

    //printf("what\n");

    if (!add_elem(sim, &the_string, &str_size)) printf("Слишком большая строка. Не удалось расширить.");
    //printf("%c\n", the_string[str_size - 1]);
    //printf("%d\n", str_size);
    //for(int i = 0; i < str_size; i++)
    //{printf("%c\n", the_string[i]);}

    print_str(the_string);

    free(the_string); the_string = NULL;


}

void print_str(char* the_string)
{
    puts(the_string);
}


bool add_elem(char elem, char** the_string, int* str_size)
{
    //printf("bbbbbbbb");
    *the_string = (char*) realloc(*the_string, (*str_size + 1) * sizeof(char));
    //printf("aaaaaaaaaa");
    if (*the_string == NULL) return false;

    //(*str_size)++;

    (*the_string)[*str_size - 1] = elem;
    (*the_string)[*str_size] = '\0';
    (*str_size)++;
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
