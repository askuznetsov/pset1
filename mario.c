#include <cs50.h>
#include <stdio.h>

void pyramids(int h);
void right_pyramid(int tmp);

int main (void)
{
    int height = 0;
    do
    {
        printf("Height: ");
        height = get_int();
    } while (height < 0 || height > 23);
    //цыкл пирамиды 
    pyramids(height);
}           

void right_pyramid(int tmp)
{
    for(int i = 0; i < tmp; i++)
        {
           printf("#");
        }
        printf("\n");
}
 void pyramids(int h)
 {
    int all_rows;
    int space;
    int hash;
     for(all_rows = 1; all_rows <= h; all_rows++)
    {
        //делаем пробелы
        for(space = 0; space < h - all_rows; space++)
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
        right_pyramid(all_rows);
    }
 }
