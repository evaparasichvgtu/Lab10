#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

void main() {
	setlocale(LC_ALL, "RUS");
	task_1();
	task_2();
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

int task_2() {
	int a;
	return 0;
}