#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void art(int arr[]) {
    const int height = 50;
    const int elemInArray = 100;
    char table[height][elemInArray];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < elemInArray; j++)
        {
            if ((arr[j]/2) == i)
            {
                table[i][j] = 'O';
            } else {
                table[i][j] = ' ';
            }
        }
    }
    // output
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < elemInArray; j++)
        {
            printf("%c", table[i][j]);
        }
        printf("\n");   
    }
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
    printf ("\033[0d\033[2J");
    art(array);
    usleep(250000);     // тут слипим наш код
    if (low < high) {
    int pi = partition(array, low, high);   
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d- ", array[i]);
  }
}

int main() {
    int array[] = {39, 27, 68, 92, 79, 64, 24, 13, 47, 54, 1, 85, 65, 9, 66, 18, 64, 16, 86, 97, 68, 49, 72, 66, 47, 20, 2, 50, 33, 27, 39, 51, 30, 91, 51, 0, 45, 56, 92, 29, 8, 72, 21, 5, 52, 70, 82, 38, 37, 64, 0, 88, 58, 2, 78, 51, 32, 4, 80, 71, 15, 67, 64, 79, 30, 86, 93, 79, 85, 41, 85, 0, 60, 47, 40, 72, 95, 52, 78, 59, 59, 21, 63, 22, 52, 29, 45, 28, 56, 58, 65, 14, 14, 66, 91, 80, 30, 28, 89, 22};
    int n = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, n - 1);
    printArray(array, n);
}