#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GROUP_SIZE 6

/* Ключ - группа перестановки (Таблица 3, вариант 1) */
int perm[GROUP_SIZE] = {3, 5, 2, 6, 1, 4};

/* Функция шифрования текста методом перестановки */
char* encrypt(const char* input, int* out_len) {
    int len = strlen(input);
    /* Дополняем до кратности GROUP_SIZE пробелами */
    int padded = ((len + GROUP_SIZE - 1) / GROUP_SIZE) * GROUP_SIZE;
    char* result = (char*)malloc(padded + 1);
    if (!result) return NULL;

    /* Копируем вход, дополняя пробелами */
    for (int i = 0; i < padded; i++) {
        result[i] = (i < len) ? input[i] : ' ';
    }
    result[padded] = '\0';

    /* Шифруем блоками */
    for (int b = 0; b < padded; b += GROUP_SIZE) {
        char block[GROUP_SIZE];
        /* Сохраняем оригинальный блок */
        for (int i = 0; i < GROUP_SIZE; i++)
            block[i] = result[b + i];
        /* Переставляем: на позицию i ставим символ из позиции perm[i]-1 */
        for (int i = 0; i < GROUP_SIZE; i++)
            result[b + i] = block[perm[i] - 1];
    }

    *out_len = padded;
    return result;
}

/* Функция дешифрования - обратная перестановка */
char* decrypt(const char* cipher, int len) {
    char* result = (char*)malloc(len + 1);
    if (!result) return NULL;

    for (int i = 0; i < len; i++)
        result[i] = cipher[i];
    result[len] = '\0';

    for (int b = 0; b < len; b += GROUP_SIZE) {
        char block[GROUP_SIZE];
        for (int i = 0; i < GROUP_SIZE; i++)
            block[i] = result[b + i];
        /* Обратная перестановка */
        for (int i = 0; i < GROUP_SIZE; i++)
            result[b + perm[i] - 1] = block[i];
    }
    return result;
}

int main(void) {
    /* Исходный текст (латиница, т.к. вариант с ASCII) */
    const char* original = "INFORMATION SECURITY";

    printf("=== Лабораторная работа №1 ===\n");
    printf("Метод: перестановка\n");
    printf("Группа перестановки: ");
    for (int i = 0; i < GROUP_SIZE; i++)
        printf("%d ", perm[i]);
    printf("\n\n");

    printf("Исходный текст:\n  \"%s\"\n", original);
    printf("Длина: %d символов\n\n", (int)strlen(original));

    /* Коды исходного текста (ASCII) */
    printf("ASCII-коды исходного текста:\n  ");
    for (int i = 0; original[i]; i++)
        printf("%d ", (unsigned char)original[i]);
    printf("\n\n");

    /* Шифрование */
    int clen;
    char* cipher = encrypt(original, &clen);
    if (!cipher) { printf("Ошибка памяти\n"); return 1; }

    printf("Криптограмма:\n  \"%s\"\n", cipher);
    printf("ASCII-коды криптограммы:\n  ");
    for (int i = 0; i < clen; i++)
        printf("%d ", (unsigned char)cipher[i]);
    printf("\n\n");

    /* Дешифрование */
    char* restored = decrypt(cipher, clen);
    if (!restored) { printf("Ошибка памяти\n"); free(cipher); return 1; }

    printf("Расшифрованный текст:\n  \"%s\"\n", restored);
    printf("ASCII-коды:\n  ");
    for (int i = 0; i < clen; i++)
        printf("%d ", (unsigned char)restored[i]);
    printf("\n\n");

    /* Проверка */
    if (strncmp(original, restored, strlen(original)) == 0)
        printf(">>> Проверка пройдена: исходный текст восстановлен.\n");
    else
        printf(">>> Ошибка: текст восстановлен неверно.\n");

    free(cipher);
    free(restored);
    return 0;
}