# Домашнее задание к работе 10

# Вариант 18

# Условие задачи
Составьте программу, которая для заданной пользователем фигуры (параллелограмма) предлагает меню выбора одной из операций:
1) рассчитать площадь;
2) вывести определение фигуры;
3) нарисовать фигуру.

# Блок схема
<img width="607" height="816" alt="image" src="https://github.com/user-attachments/assets/2c5981bc-1f9a-415c-957d-8d4fd6d9b800" />


# Код

```c
#include <stdio.h>
#include <math.h>
int main() {
	// 18
	char ch;
	int h, a, A;
	double shift, rad_A;
	const int b = 5;
	printf("\n--- рисование параллелограмма ---\n");
	printf("введите символ: \n");
	scanf("%c", &ch);
	printf("введите высоту параллелограмма: \n");
	scanf("%d", &h);
	printf("введите значение стороны а: \n");
	scanf("%d", &a);
	printf("введите значение острого угла А (< 90 градусов): \n");
	scanf("%d", &A);
	rad_A = A * M_PI / 180.0;
	shift = tan(rad_A); //наклон параллелограмма
	for (int row = 1; row <= h; row++) {
		int sp = (int)(row * shift); //сколько пробелов нужно сделать
		for (int i = 0; i < sp; i++) {
			printf(" ");
		}
		for (int col = 1; col <= a; col++) {
			printf("%c", ch);
		}
		printf("\n");
	}

	return 0;
}
```
