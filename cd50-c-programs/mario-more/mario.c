#include <cs50.h>
#include <stdio.h>

void printRow(int numOfSpace, int numOfHashes);

int main(void)
{
    int height;

    do
    {
        height = get_int("height: ");
    }
    while (height < 1 || height > 9);

    for (int i = 0; i < height; i++)
    {
        int hashes = i + 1;
        int spaces = height - hashes;

        printRow(spaces, hashes);
    }
}

void printRow(int numOfSpace, int numOfHashes)
{
    for (int i = 0; i < numOfSpace; i++)
    {
        printf(" ");
    }

    for (int j = 0; j < numOfHashes * 2; j++)
    {
        printf("#");
        if (j + 1 == numOfHashes)
        {
            printf("  ");
        }
    }
    printf("\n");
}
