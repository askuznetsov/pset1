#include <cs50.h>
#include <string.h>
#include <stdio.h>
//иницилизируем константы
const int CONST_MAX_CARD_NUMBER = 16;
const char CONST_FIRST_NUMBER_IS_4 = '4';
const char CONST_FIRST_NUMBER_IS_3 = '3';
const char CONST_FIRST_NUMBER_IS_5 = '5';
const char CONST_SECOND_NUMBER_IS_4 = '4';
const char CONST_SECOND_NUMBER_IS_7 = '7';
const char CONST_SECOND_NUMBER_IS_1 = '1';
const char CONST_SECOND_NUMBER_IS_5 = '5';
//инициализируем фукнцию суммы цыфр
int summary(int temp_number);
// Иницилизируем алгоритм Люна.
bool Luhn(char *temp_numb);
// возьмем положительный long long с клавиатуры
long long read_card(const char *temp_number_card);

int main (void)
{
    long long number;
    number = read_card("Number of the card: ");
    //создаем строку и конвертируем в нее наш номер карты
    char card_str[const_max_card_number];
    sprintf(card_str,"%lld", number);
    //проверяем условия, для каждого типа карт и выводим результат
    if (card_str[0] == const_first_number_is_4 && Luhn(card_str)) printf("VISA\n");
    else if (card_str[0] == const_first_number_is_3 && (card_str[1] == const_second_number_is_4 || card_str[1] == const_second_number_is_4) && Luhn(card_str)) printf("AMEX\n");
    else if (card_str[0] == const_first_number_is_5 && (card_str[1] >= const_second_number_is_1 || card_str[1] <= const_second_number_is_5) && Luhn(card_str)) printf("MASTERCARD\n");
    else printf("INVALID\n");
    return 0;
}

int summary(int temp_number)
{
    return (temp_number / 10) + (temp_number % 10);
}

long long read_card(const char *temp_number_card)
{
    long long result;
    do
    {
        printf("%s", temp_number_card);
        result = GetLongLong();
    }while (result <= 0);
    return result;
}

bool Luhn(char *temp_numb)
{
    int digit;
    bool even = true;
    int sum = 0;
    for (int i = strlen(temp_numb) - 1; i >= 0; i--)
    {
        digit = temp_numb[i] - '0';
        if (even) 
        { 
        sum =sum + digit; 
        } 
        else
        { 
          sum = sum + summary(digit * 2); 
        };
      even = !even;
    }
    if (!(sum%10)) return true;
    else return false;
}
