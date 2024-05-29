#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardNumber = get_long("What is your card Number?\n");

    int cardNumLength = 0;

    int singleDigitSum = 0;
    int doubleDigitSum = 0;

    int startNum = 0;
    int sum;

    bool isDoubleDigit = false;

    while (cardNumber > 0)
    {
        int tail = cardNumber % 10;
        cardNumber = cardNumber / 10;
        cardNumLength += 1;

        if (!isDoubleDigit)
        {
            singleDigitSum += tail;
            isDoubleDigit = !isDoubleDigit;
        }
        else
        {
            int doubledDigit = tail * 2;
            if (tail > 4)
            {
                doubleDigitSum += doubledDigit % 10 + 1;
            }
            else
            {
                doubleDigitSum += doubledDigit;
            }
            isDoubleDigit = !isDoubleDigit;
        }

        if (cardNumber < 100 && cardNumber > 9)
        {
            startNum = cardNumber;
        }
    }

    bool isSumZero = (doubleDigitSum + singleDigitSum) % 10 == 0;

    // printf("cardNumLength: %i\n", cardNumLength);
    // printf("startNum: %i\n", startNum/10);check50 cs50/problems/2024/x/credit

    // printf("doubleDigitSum: %i\n", doubleDigitSum);
    // printf("singleDigitSum: %i\n", singleDigitSum);
    // printf("isSumZero: %i\n", isSumZero);

    if (isSumZero)
    {
        if (cardNumLength == 15 && (startNum == 34 || startNum == 37))
        {
            printf("AMEX\n");
        }
        else if (cardNumLength == 16 && (startNum >= 51 && startNum <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((cardNumLength == 13 || cardNumLength == 16) && startNum / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
