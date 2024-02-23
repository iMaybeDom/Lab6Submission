#include <stdio.h>
#include <stdlib.h>

/*

 * Dominick Amaral
 * COP 3502C
 * Lab Assignment 6
 * 2/22/24

 */

int search(int numbers[], int low, int high, int value)
{
    if (low > high) {
        return -1;  // Element not found
    }

    int mid = low + (high - low) / 2;

    if (numbers[mid] == value) {
        return mid;  // Element found at mid-index
    } else if (numbers[mid] < value) {
        return search(numbers, mid + 1, high, value);  // Search in the right
    } else {
        return search(numbers, low, mid - 1, value);   // Search in the left
    }
}

void printArray(int numbers[], int sz)
{
    int i;
    printf("Number array : ");
    for (i = 0; i < sz; ++i)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void)
{
    int i, numInputs;
    float average;
    int value;
    int index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt", "r");

    if (inFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int *)malloc(countOfNums * sizeof(int));
        average = 0;
        for (i = 0; i < countOfNums; i++)
        {
            fscanf(inFile, " %d", &value);
            numArray[i] = value;
            average += numArray[i];
        }

        printArray(numArray, countOfNums);
        value = average / countOfNums;
        index = search(numArray, 0, countOfNums - 1, value);
        if (index >= 0)
        {
            printf("Item %d exists in the number array at index %d\n", value, index);
        }
        else
        {
            printf("Item %d doesn't exist in the number array\n", value);
        }

        free(numArray);
    }

    fclose(inFile);

    return 0;
}
