#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void task1() {
    int n;
    printf(" Завдання 102:\n");

    printf("Введiть розмiр масиву n: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Помилка: Розмiр масиву має бути додатним числом!\n\n");
        return;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Помилка видiлення пам'ятi!\n\n");
        return;
    }

    printf("Введiть %d цiлих чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    int del_idx = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 6 != 0) {
            del_idx = i;
            break;
        }
    }

    if (del_idx == -1) {
        printf("Елементи видалення не знайденi.\n\n");
    }
    else {
        for (int i = del_idx; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;

        printf("Оновлений масив пiсля видалення:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    free(arr);
}

void task2() {
    int n, k;
    printf(" Завдання 109:\n");

    printf("Введiть розмiр масиву n: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Помилка: Розмiр масиву має бути додатним числом!\n\n");
        return;
    }

    double* arr = (double*)malloc((n + 1) * sizeof(double));
    if (arr == NULL) {
        printf("Помилка видiлення пам'ятi!\n\n");
        return;
    }

    printf("Введiть %d дiйсних чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%lf", &arr[i]);
    }

    printf("Введiть позицiю k для вставки (вiд 1 до %d): ", n + 1);
    scanf_s("%d", &k);

    if (k < 1 || k > n + 1) {
        printf("Помилка: Позицiя k має бути вiд 1 до %d!\n\n", n + 1);
        free(arr);
        return;
    }

    double max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    for (int i = n; i >= k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k - 1] = max_val;
    n++;

    printf("Оновлений масив пiсля вставки %.2lf на %d-те мiсце:\n", max_val, k);
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n\n");

    free(arr);
}

void task3() {
    int n;
    printf(" Завдання 128:\n");

    printf("Введiть розмiр масиву n: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Помилка: Розмiр масиву має бути додатним числом!\n\n");
        return;
    }

    double* arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Помилка видiлення пам'ятi!\n\n");
        return;
    }

    printf("Введiть %d дiйсних чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%lf", &arr[i]);
    }

    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }

    arr[max_idx] = 0.0;

    printf("Оновлений масив (перший максимум на позицiї %d замiнено нулем):\n", max_idx + 1);
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n\n");

    free(arr);
}

void task4() {
    int n;
    double d;
    printf(" Завдання 165:\n");

    printf("Введiть кiлькiсть днiв n: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Помилка: Кiлькiсть днiв має бути додатною!\n\n");
        return;
    }

    double* orig = (double*)malloc(n * sizeof(double));
    double* sorted = (double*)malloc(n * sizeof(double));
    if (orig == NULL || sorted == NULL) {
        printf("Помилка видiлення пам'ятi!\n\n");
        free(orig);
        free(sorted);
        return;
    }

    printf("Введiть значення тиску для %d днiв (у межах 740..780):\n", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%lf", &orig[i]);
        sorted[i] = orig[i];
    }

    printf("Введiть величину тиску d: ");
    scanf_s("%lf", &d);

    int max_idx = 0, min_idx = 0, count_d = 0;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        if (orig[i] > orig[max_idx]) max_idx = i;
        if (orig[i] < orig[min_idx]) min_idx = i;
        sum += orig[i];
        if (orig[i] > d) count_d++;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sorted[j] > sorted[j + 1]) {
                double temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    printf("\nВихiдний (початковий) масив:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", orig[i]);
    }

    printf("\nВпорядкований масив за зростанням:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", sorted[i]);
    }

    printf("\nа) Максимальний тиск: %.2lf (день %d), мiнiмальний тиск: %.2lf (день %d)\n",
        orig[max_idx], max_idx + 1, orig[min_idx], min_idx + 1);
    printf("б) Середнє значення тиску: %.2lf\n", sum / n);
    printf("в) Кiлькiсть днiв, коли тиск перевищував %.2lf: %d\n\n", d, count_d);

    free(orig);
    free(sorted);
}

void task5() {
    int n;
    double a, b;
    printf(" Завдання 16:\n");

    printf("Введiть розмiр масиву n: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Помилка: Розмiр масиву має бути додатним числом!\n\n");
        return;
    }

    double* arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Помилка видiлення пам'ятi!\n\n");
        return;
    }

    printf("Введiть %d елементiв масиву:\n", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%lf", &arr[i]);
    }

    printf("Введiть число a: ");
    scanf_s("%lf", &a);
    printf("Введiть число b: ");
    scanf_s("%lf", &b);

    printf("а) Збiльшити у 2 рази: ");
    for (int i = 0; i < n; i++) printf("%.2lf ", arr[i] * 2.0);
    printf("\n");

    printf("б) Зменшити на число a: ");
    for (int i = 0; i < n; i++) printf("%.2lf ", arr[i] - a);
    printf("\n");

    printf("в) Роздiлити на перший елемент: ");
    if (arr[0] == 0.0) {
        printf("Дiлення на нуль неможливе");
    }
    else {
        for (int i = 0; i < n; i++) printf("%.2lf ", arr[i] / arr[0]);
    }
    printf("\n");

    printf("г) Зменшити на 20: ");
    for (int i = 0; i < n; i++) printf("%.2lf ", arr[i] - 20.0);
    printf("\n");

    printf("д) Помножити на останнiй елемент: ");
    for (int i = 0; i < n; i++) printf("%.2lf ", arr[i] * arr[n - 1]);
    printf("\n");

    printf("е) Збiльшити на число b: ");
    for (int i = 0; i < n; i++) printf("%.2lf ", arr[i] + b);
    printf("\n\n");

    free(arr);
}

void task6() {
    int n, val;
    printf(" Завдання 107:\n");

    printf("Введiть розмiр масиву n (не менше 9): ");
    scanf_s("%d", &n);

    if (n < 9) {
        printf("Помилка: Для вставки на 10-те мiсце масив має мiстити щонайменше 9 елементiв!\n\n");
        return;
    }

    int* arr = (int*)malloc((n + 1) * sizeof(int));
    if (arr == NULL) {
        printf("Помилка видiлення пам'ятi!\n\n");
        return;
    }

    printf("Введiть %d цiлих чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    printf("Введiть цiле число для вставки на 10-те мiсце: ");
    scanf_s("%d", &val);

    for (int i = n; i >= 10; i--) {
        arr[i] = arr[i - 1];
    }
    arr[9] = val;
    n++;

    printf("Оновлений масив пiсля вставки %d на 10-те мiсце:\n", val);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    free(arr);
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    task1();
    task2();
    task3();
    task4();
    task5();
    task6();

    return 0;
}