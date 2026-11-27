# Домашнее задание к работе 10

# Вариант 18

# Условие задачи
Составьте программу, которая для заданной пользователем фигуры (параллелограмма) предлагает меню выбора одной из операций:
1) рассчитать площадь;
2) вывести определение фигуры;
3) нарисовать фигуру.

# Блок схема
<img width="607" height="816" alt="image" src="https://github.com/user-attachments/assets/2c5981bc-1f9a-415c-957d-8d4fd6d9b800" />
<img width="702" height="1332" alt="Диаграмма без названия drawio" src="https://github.com/user-attachments/assets/de682717-32fd-4ad0-a79d-9281d97a0b92" />

# Код

```c
#include <stdio.h>
#include <math.h>

	// 18

void main() {
	setlocale(LC_ALL, "RUS");
	homework();
	return 0;
}

	float area_parallelogram(float a, float h) { // вычисление площади параллелограмма
	return a * h;
}

void definition_parallelogram() { // вывод определения параллелограмма
	printf("Параллелограмм – это четырехугольник, у которого противоположные стороны попарно параллельны.\n");
}

void draw_parallelogram(int h, int a, char ch, int A) { // рисование параллелограмма
	double shift, rad_A;

	rad_A = A * PI / 180.0;
	shift = tan(rad_A);

	for (int row = 1; row <= h; row++) {
		int sp = (int)(row * shift);
		for (int i = 0; i < sp; i++) {
			printf(" ");
		}
		for (int col = 1; col <= a; col++) {
			printf("%c", ch);
		}
		printf("\n");
	}
}

int homework() {
	char ch;
	int h, a, A;
	int choice;

	printf("--- параллелограмм ---\n");

	printf("введите символ для рисования: ");
	scanf(" %c", &ch);

	printf("введите высоту параллелограмма: ");
	scanf("%d", &h);

	printf("введите значение стороны a: ");
	scanf("%d", &a);

	printf("введите значение острого угла A (< 90 градусов): ");
	scanf("%d", &A);

	printf("выберите операцию:\n");
	printf("1 – вассчитать площадь\n");
	printf("2 – вывести определение фигуры\n");
	printf("3 – нарисовать фигуру\n");
	printf("ваш выбор: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		printf("площадь параллелограмма: %.2f\n",
			area_parallelogram(a, h));
		break;

	case 2:
		definition_parallelogram();
		break;

	case 3:
		printf("\n");
		draw_parallelogram(h, a, ch, A);
		break;

	default:
		printf("ошибка: такой операции нет.\n");
	}
	return 0;
}

```
