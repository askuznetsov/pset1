#include <cs50.h>
#include <string.h>
#include <stdio.h>
//назначим максимальную длину числа - 16
const int const_max_card_number = 16;
//инициализируем фукнцию суммы цыфр
int summary(int temp_number)
{
    return (temp_number / 10) + (temp_number % 10);
}
// возьмем положительный long long с клавиатуры
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
// Иницилизируем алгоритм Люна.
bool Luhn(char *temp_numb)
{
    int digit;
    bool even = true;
    int sum = 0;
    // Идем налево с последней цыфры
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
    // если sum кратна 10 - то правильно
    if (!(sum%10)) return true;
    else return false;
}

int main (void)
{
// Берем номер карточки от пользователя
    long long number;
    number = read_card("Number of the card: ");
    //создаем строку и конвертируем в нее наш номер карты
    char card_str[const_max_card_number];
    sprintf(card_str,"%lld", number);
    //проверяем условия, для каждого типа карт и выводим результат
    if (card_str[0] == '4' && Luhn(card_str)) printf("VISA\n");
    else if (card_str[0] == '3' && (card_str[1] == '4' || card_str[1] == '7') && Luhn(card_str)) printf("AMEX\n");
    else if (card_str[0] == '5' && (card_str[1] >= '1' || card_str[1] <= '5') && Luhn(card_str)) printf("MASTERCARD\n");
    else printf("INVALID\n");
    return 0;
}
