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
                table[i][j] = '@';
            } else {
                table[i][j] = '-';
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
    usleep(200000);     // тут слипим наш код
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
    int array[] = {51,30,74,20,61,71,42,12,10,69,22,29,22,72,56,96,88,91,91,14,11,94,47,99,46,8,78,87,52,39,87,7,38,24,16,6,84,43,7,40,21,55,97,19,74,7,56,84,74,6,9,50,88,45,95,85,30,27,33,64,57,40,2,59,14,33,23,39,69,34,73,32,39,42,73,76,72,80,45,66,75,68,33,70,4,25,32,48,3,65,57,92,53,63,15,90,27,20,4,2};
    int n = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, n - 1);
    printArray(array, n);
}