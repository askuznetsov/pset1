#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int all_rows;
    int space;
    int hash;
    int height = 0;
    do
    {
        printf("Height: ");
        height = get_int();
    } while (height < 0 || height > 23);
    //цыкл пирамиды слева
    for(all_rows = 1; all_rows <= height; all_rows++)
    {
        //делаем пробелы
        for(space = 0; space < height - all_rows; space++)
        {
            printf(" ");
        }
        //и рисуем '#'
        for(hash = 0; hash < all_rows; hash++)
        {
            printf("#");
        }
        //создаем поле между полу - пирамидами
        printf("  ");
        //цыкл пирамиды направо
        for(int i = 0; i < all_rows; i++)
        {
           printf("#");
        }
        printf("\n");
    }
    
}
