#include <stdio.h>
#include "my_malloc.h"

int main() {
    printf("--- Тест 1: Перше виділення ---\n");
    int *ptr1 = (int*)my_malloc(sizeof(int));
    if (!ptr1) {
        printf("Помилка: не вдалося виділити пам'ять!\n");
        return 1;
    }
    *ptr1 = 42;
    printf("Адреса ptr1: %p, Значення: %d\n", (void*)ptr1, *ptr1);

    printf("\n--- Тест 2: Друге виділення (новий блок) ---\n");
    int *ptr2 = (int*)my_malloc(sizeof(int));
    *ptr2 = 100;
    printf("Адреса ptr2: %p, Значення: %d\n", (void*)ptr2, *ptr2);

    printf("\n--- Тест 3: Звільнення першого блоку ---\n");
    my_free(ptr1);
    printf("ptr1 звільнено. Зараз спробуємо виділити пам'ять знову...\n");

    printf("\n--- Тест 4: Повторне використання пам'яті ---\n");
    int *ptr3 = (int*)my_malloc(sizeof(int));
    printf("Адреса ptr3: %p (Має бути такою ж, як ptr1!)\n", (void*)ptr3);

    if (ptr1 == ptr3) {
        printf("Успіх! Мій malloc переміг фрагментацію і використав блок повторно.\n");
    } else {
        printf("Щось пішло не так: створено новий блок замість старого.\n");
    }

    return 0;
}
