#include <stdio.h>

#include <math.h>

#include <ctype.h>

#include <string.h>

#include <conio.h>

int isInt(char a[31]) {
  int i = 0;
  for (i = 0; i < strlen(a); i++) {
    if (!isdigit(a[i])) return 0;
  }
  return 1;
}

int isDou(char a[31]) {
  int i = 0;
  int dot = 0;
  for (i = 0; i < strlen(a); i++) {
    if (a[i] == '.') {
      dot = dot + 1;
      if (dot == 2) return 0;
    }
    if (!isdigit(a[i]) && a[i] != '.') return 0;
  }
  if (dot == 0) return 0;
  return 1;
}

int isChar(char a[31]) {
  if (strlen(a) != 1) return 0;
  return 1;
}

int isValidIntArr(char arr[][31], int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    if (!isInt(arr[i])) return 0;;
  }
  return 1;
}

int isValidDouArr(char arr[][31], int n) {
  int i = 0;
  for (i = 0; i < n; i++)
    if (!isDou(arr[i])) return 0;
  return 1;
}

int isValidCharArr(char arr[][31], int n) {
  int i = 0;
  for (i = 0; i < n; i++)
    if (!isChar(arr[i])) return 0;
  return 1;
}

int isValidArr(char arr[][31], int n, int choice) {
  if (choice == 1 && isValidIntArr(arr, n)) return 1;
  if (choice == 2 && isValidDouArr(arr, n)) return 1;
  if (choice == 3 && isValidCharArr(arr, n)) return 1;
  return 0;
}

int getChoice() {
  int choice = 0;
  printf("1.Int\n2.Dou\n3.Char\n");
  printf("Enter the number of type:");
  do {
    scanf("%d", & choice);
    if ((choice != 1) && (choice != 2) && (choice != 3)) printf("Enter again:");
  } while ((choice != 1) && (choice != 2) && (choice != 3));
  return choice;
}

int InputArr(char arr[][31], int n, int choice) {

  do {
    int i = 0;
    for (i = 0; i < n; i++) {
      do {
        printf("Enter the %d of set:", i);
        scanf("%s", & arr[i]);
        if (ExistInArray(arr, n, i)) printf("This element is exist! Enter again!\n");
      } while (ExistInArray(arr, n, i));
    }
    if (isValidArr(arr, n, choice)) {
      printf("It is a valid set\n");
      return 1;
    } else {
      printf("It is not a valid set\n");
    }
  } while (!isValidArr(arr, n, choice));
}

void swap(char a[], char b[]) {
  char temp[31];
  strcpy(temp, a);
  strcpy(a, b);
  strcpy(b, temp);
}

void selectionSort(char arr[][31], int n, int choice) {
  int i, j, min_idx;
  char temp[31];

  // One by one move boundary of unsorted subarray 
  for (i = 0; i < n - 1; i++) {

    // Find the minimum element in unsorted array 
    min_idx = i;
    for (j = i + 1; j < n; j++)
      switch (choice) {
      case 1:
        {
          if (atoi(arr[j]) < atoi(arr[min_idx]))
            min_idx = j;
          break;
        }
      case 2:
        {
          if (atof(arr[j]) < atof(arr[min_idx]))
            min_idx = j;
          break;
        }
      default:
        if ((char) arr[j][0] < (char) arr[min_idx][0])
          min_idx = j;
      }

    // Swap the found minimum element 
    // with the first element 
    swap(arr[min_idx], arr[i]);
  }
}

void unSelectionSort(char arr[][31], int n, int choice) {
  int i, j, min_idx;
  char temp[31];
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      switch (choice) {
      case 1:
        {
          if (atoi(arr[j]) > atoi(arr[min_idx]))
            min_idx = j;
          break;
        }
      case 2:
        {
          if (atof(arr[j]) > atof(arr[min_idx]))
            min_idx = j;
          break;
        }
      default:
        if ((char) arr[j][0] > (char) arr[min_idx][0])
          min_idx = j;
      }
    swap(arr[min_idx], arr[i]);
  }
}

void printArr(char arr[][31], int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("Element %d: %s\n", i, arr[i]);
  }
}

int same(char a[], char b[]) {

  if (strlen(a) != strlen(b)) return 0;
  int i = 0;
  for (i = 0; i < strlen(a); i++) {
    if ((char) a[i] != (char) b[i]) return 0;
  }
  return 1;
}

void copyElement(char a[], char b[]) {
  strcpy(b, a);
}

int equal(char arr1[][31], int n, char arr2[][31], int m) {
  if (n != m) return 0;
  int i, j, check = 0;
  for (i = 0; i < n; i++) {
    check = 0;
    for (j = 0; j < n; j++) {
      if (same(arr1[i], arr2[j])) check = 1;
    }
    if (check == 0) return 0;
  }
  return 1;
}

void CheckEqual(char arr1[][31], int n, char arr2[][31], int m) {
  if (equal(arr1, n, arr2, m)) printf("It is equal to the first array\n");
  else printf("It is not equal to the first array\n");
}

int subset(char arr1[][31], int n, char arr2[][31], int m) {
  int i, j, check = 0;
  for (i = 0; i < n; i++) {
    check = 0;
    for (j = 0; j < m; j++) {
      if (same(arr1[i], arr2[j])) check = 1;
    }
    if (check == 0) return 0;
  }
  return 1;
}

void CheckSubset(char arr1[][31], int n, char arr2[][31], int m) {
  if (subset(arr1, n, arr2, m)) printf("The first array is a true subset of the second array\n");
  else printf("The first array is not a true subset of the second array\n");
}

int lengthOfUnionArr(char arr1[][31], int n, char arr2[][31], int m) {
  int count = 0;
  while (count < n) count++;
  int i = 0;
  for (i = 0; i < m; i++) {
    if (!ExistN(arr1, n, arr2[i])) count++;
  }
  return count;
}

int lengthOfIntersectionArr(char arr1[][31], int n, char arr2[][31], int m) {
  int count = 0;
  int i = 0;
  for (i = 0; i < n; i++) {
    if (ExistN(arr1, n, arr2[i])) {
      count++;
    }
  }
  return count;
}

int lengthOfDiffArr(char arr1[][31], int n, char arr2[][31], int m) {
  return lengthOfUnionArr(arr1, n, arr2, m) - lengthOfIntersectionArr(arr1, n, arr2, m);
}

void Union(char arr1[][31], int n, char arr2[][31], int m, char newArr[][31]) {
  int count = 0;
  while (count < n) {
    copyElement(arr1[count], newArr[count]);
    count++;
  }
  int i = 0;
  for (i = 0; i < m; i++) {
    if (!ExistN(arr1, n, arr2[i])) {
      copyElement(arr2[i], newArr[count]);
      count++;
    }
  }
}

void Intersection(char arr1[][31], int n, char arr2[][31], int m, char newArr[][31]) {
  int count = 0;
  int i = 0;
  for (i = 0; i < n; i++) {
    if (ExistN(arr2, m, arr2[i])) {
      copyElement(arr1[i], newArr[count]);
      count++;
    }
  }
}

void Different(char arr1[][31], int n, char arr2[][31], int m, char newArr[][31]) {
  int count = 0;
  int i = 0;
  for (i = 0; i < n; i++) {
    if (!ExistN(arr2, m, arr1[i])) {
      copyElement(arr1[i], newArr[count]);
      count++;
    }
  }
  for (i = 0; i < m; i++) {
    if (!ExistN(arr1, n, arr2[i])) {
      copyElement(arr2[i], newArr[count]);
      count++;
    }
  }
}

void greatestSubArray(char arr[][31], int n, char arr1[][31], int m) {
  int i = 0;
  for (i = 0; i < m; i++) {
    copyElement(arr[n - 1 - i], arr1[i]);
  }
}

int ExistN(char arr[][31], int n, char a[]) {
  int i = 0;
  for (i = 0; i < n; i++) {
    if (same(arr[i], a)) return 1;
  }
  return 0;
}

int ExistInArray(char arr[][31], int n, int j) {
  int i = 0;
  for (i = 0; i < j; i++) {
    if (same(arr[i], arr[j])) return 1;
  }
  return 0;
}

void execute() {
  int choice = getChoice();
  int n = 0;
  printf("Enter the number of value:");
  scanf("%d", & n);
  char arr[n][31];
  if (InputArr(arr, n, choice)) {

    printf("=====All the members of array in ascending order=====\n");
    selectionSort(arr, n, choice);
    printArr(arr, n);

    printf("=====All the members of array in descending order=====\n");
    unSelectionSort(arr, n, choice);
    printArr(arr, n);

    printf("=====Check if something is a member of array=====\n");
    char something[31];
    printf("Enter the number:");
    scanf("%s", & something);
    if (ExistN(arr, n, something)) printf("It is a member of array\n");
    else printf("It is not a member of array\n");

    printf("=====Enter another array and check if it is equal to the first array =====\n");
    int choice2 = getChoice();
    int m = 0;
    printf("Enter the number of value of second array:");
    scanf("%d", & m);
    char arr1[m][31];
    if (InputArr(arr1, m, choice2)) CheckEqual(arr, n, arr1, m);

    printf("---Check if the first is a true subset of the secound---\n");
    CheckSubset(arr, n, arr1, m);

    printf("---Find union of first and second array\n");
    int newLen = lengthOfUnionArr(arr, n, arr1, m);
    char newArr[newLen][31];
    Union(arr, n, arr1, m, newArr);
    printArr(newArr, newLen);

    printf("---Find intersection of first and second array\n");
    int newLen1 = lengthOfIntersectionArr(arr, n, arr1, m);
    char newArr1[newLen1][31];
    Intersection(arr, n, arr1, m, newArr1);
    printArr(newArr1, newLen1);

    printf("---Find different of first and second array\n");
    int newLen2 = lengthOfDiffArr(arr, n, arr1, m);
    char newArr2[newLen2][31];
    Different(arr, n, arr1, m, newArr2);
    printArr(newArr2, newLen2);

    printf("---Enter number n to find the greatest subset of the first array---\n");
    int k = 0;
    do {
      printf("Number n: ");
      scanf("%d", & k);
      if (k > n) {
        printf("Number n must be less than the number of element of the first array! ");
      }
    } while (k > n);
    char newArr3[k][31];
    selectionSort(arr, n, choice);
    greatestSubArray(arr, n, newArr3, k);
    printf("The greatest subset of the first array:\n");
    printArr(newArr3, k);
  }
}

int main() {
  execute();
  return 0;
}
