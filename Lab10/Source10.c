#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define PI 3.14

void main() {
	setlocale(LC_ALL, "RUS");
	// task_1();
	// task_2();
	// task_3();
	homework();
	return 0;
}

double fa(double x) {
	double y;
	if (x <= 3) y = pow(x, 2) - 3 * x + 9;
	else y = 1.0 / (pow(x, 3) + 3);
	return y;
}

double fb(double x) {
	double y;
	y = x * exp(sin(pow(x, 2)));
	return y;
}

int task_1() {
	double x;
	int choice;
	printf("введите значение x: \n");
	scanf("%lf", &x);
	printf("выберите действие: \n");
	printf("1. вычислить fa(x)\n");
	printf("2. вычислить fb(x)\n");
	printf("3. вычислить произведение, разность, удвоенную сумму\n");
	printf("ваш выбор: \n");
	scanf("%d", &choice);
	switch (choice) {
	case 1: {
		printf("fa(x) = %lf\n", fa(x));
		break;
	}
	case 2: {
		printf("fb(x) = %lf\n", fb(x));
		break;
	}
	case 3: {
		printf("произведение = %lf, разность квадратов = %lf, удвоенная сумма = %lf\n", fa(x) * fb(x), pow(fa(x), 2) - pow(fb(x), 2), 2 * (fa(x) + fb(x)));
		break;
	}
	default:
		printf("неверный выбор\n");
	}
	return 0;
}

double sin_n(double x, int N) {
	double sum = 0.0;
	double term = x;

	for (int k = 1; k <= N; k++)
	{
		sum += term;

		// вычисление следующего члена ряда
		term *= -x * x / ((2.0 * k) * (2.0 * k + 1));
	}

	return sum;
}

double sin_eps(double x, double eps)
{
	double sum = 0.0;
	double term = x;
	int k = 1;

	while (fabs(term) > eps)
	{
		sum += term;

		term *= -x * x / ((2.0 * k) * (2.0 * k + 1));
		k++;
	}

	return sum;
}

int task_2() {
	double x, eps;
	int N;

	printf("--- вычисление функции sin(x) тремя способами --- \n");

	printf("введите значение x (в радианах): ");
	scanf("%lf", &x);

	printf("введите количество членов ряда N: ");
	scanf("%d", &N);

	printf("введите точность eps: ");
	scanf("%lf", &eps);

	// проверка введенных значений
	if (N <= 0 || eps <= 0.0)
		printf("ошибка: N и eps должны быть положительными.\n");

	// Вычисление тремя способами
	double result_lib = sin(x);
	double result_n = sin_n(x, N);
	double result_eps = sin_eps(x, eps);

	printf("\nРезультаты вычислений:\n");

	printf("----------------------------------------------------------\n");
	printf("%-25s %-20s %-15s\n", "способ вычисления", "результат", "отклонение");
	printf("----------------------------------------------------------\n");

	printf("%-25s %-20.10f %-15.10e\n", "стандартная функция", result_lib, 0.0);

	printf("%-25s %-20.10f %-15.10e\n", "ряд из N членов", result_n, fabs(result_lib - result_n));

	printf("%-25s %-20.10f %-15.10e\n", "ряд с точностью eps", result_eps, fabs(result_lib - result_eps));

	printf("----------------------------------------------------------\n");

	return 0;
}

double coef(int n)
{
	if (n == 1)
		return 1.0 / 3.0;
	double c = 0.0;
	for (int i = 1; i < n; i++)
		c += coef(i) * coef(n - i);
	return c / (2.0 * n + 1);
}

// вычисление котангенса
double cot(double x, int N)
{
	double sum = 0.0;
	double power = x;
	if (fabs(x) < PI && x != 0.0) {
		for (int k = 1; k <= N; k++) {
			sum += coef(k) * power;
			power *= x * x;
		}
	}
	else {
		printf("ошибка\n");
		return 0.0;
	}
	return 1.0 / x - sum;
}

int task_3() {
	double x;
	int N;

	printf("Введите x: ");
	scanf("%lf", &x);

	printf("введите количество членов ряда N : ");
	scanf("%d", &N);

	printf("cot(x) = %.10f\n", cot(x, N));

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
