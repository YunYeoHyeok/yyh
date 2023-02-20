#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
# define SIZE 3

struct data{
	char name[100];
	int number;
	char callnumber[100];
	char address[100];
	int a[6];
	double sales;
	int max[3];
	int min[3];
};
struct data s[100];
int cnt = 0;
void option1() {
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("������ �̸� : ");
		scanf(" %s", s[i].name);
		printf("���� �ø��� �ѹ� : ");
		scanf(" %d", &s[i].number);
		printf("���� �ּ� : ");
		scanf(" %s", s[i].address);
		printf("���� ��ȭ��ȣ : ");
		scanf(" %s", s[i].callnumber);
		for (int j = 0; j < 6; j++) {
			printf("%d ���� ����� : ", j + 1);
			scanf("%d", &s[i].a[j]);
		}
	}
	
}
void maxmin() {
	int i, k;
	double Min = s[0].sales;

	for (i = 0; i < SIZE; i++) {
		double Min = s[i].sales;
		if (s[i].number != 0) {
			s[i].sales = ((double)s[i].a[0] + s[i].a[1] + s[i].a[2] + s[i].a[3] + s[i].a[4] + s[i].a[5]);
		}
		for (i = 0; i < SIZE; i++) {
			if (Min > s[i].sales) {
				Min = s[i].sales;
			}
		}
		double Max = s[0].sales;
		for (i = 0; i < SIZE; i++) {
			if (Max < s[i].sales) {
				Max = s[i].sales;
			}
		}
	}
}
void option2() {
	int i;
	for (i = 0; i < SIZE; i++) {
		if (s[i].number != 0) {
			s[i].sales = ((double)s[i].a[0] + s[i].a[1] + s[i].a[2] + s[i].a[3] + s[i].a[4] + s[i].a[5]);
			printf("�����̸� = %s �ø���ѹ� = %d ������ �ּ� = %s ��ȭ��ȣ = %s \n1������� = %d 2������� = %d 3������� = %d 4������� = %d 5������� = %d 6������� = %d \n�� ����� = %.3lf \n"
				, s[i].name, s[i].number, s[i].address, s[i].callnumber, s[i].a[0], s[i].a[1], s[i].a[2], s[i].a[3], s[i].a[4], s[i].a[5], s[i].sales);
		}
		else
			printf("�Է��� �� �Ǿ��ֽ��ϴ�. \n");
	}
}
void option3() {
	int i;
	char a[100];
	printf("������ �̸��� �Է��ϼ��� : ");
	scanf("%s", a);
	for (i = 0; i < SIZE; i++) {
		if (strcmp(s[i].name, a) == 0) {
			printf("�����̸� = %s �ø���ѹ� = %d ������ �ּ� = %s ��ȭ��ȣ = %s 1������� = %d 2������� = %d 3������� = %d 4������� = %d 5������� = %d 6������� = %d �� ����� = %.3lf\n"
				, s[i].name, s[i].number, s[i].address, s[i].callnumber, s[i].a[0], s[i].a[1], s[i].a[2], s[i].a[3], s[i].a[4], s[i].a[5], s[i].sales);
		}
	}
}
void option4() {
	int i, n;
	printf("������ �ø��� �ѹ��� �Է��ϼ��� : ");
	scanf_s("%d", &n);
	for (i = 0; i < SIZE; i++) {
		if (s[i].number == n) {
			printf("�����̸� = %s �ø���ѹ� = %d ������ �ּ� = %s ��ȭ��ȣ = %s 1������� = %d 2������� = %d 3������� = %d 4������� = %d 5������� = %d 6������� = %d �� ����� = %.3lf\n"
				, s[i].name, s[i].number, s[i].address, s[i].callnumber, s[i].a[0], s[i].a[1], s[i].a[2], s[i].a[3], s[i].a[4], s[i].a[5], s[i].sales);
		}
	}
}

void option5() {
	maxmin();
	int index;
	struct data temp;
	int i, k;
	for (i = 0; i < SIZE - 1; i++) {
		index = i;
		for (k = i + 1; k < SIZE; k++) {
			if (s[k].sales < s[index].sales) {
				index = k;
			}
		}
		temp = s[index];
		s[index] = s[i];
		s[i] = temp;
	}
		printf("������� ���� ���� ���� �̸� = %s ��ȭ��ȣ = %s �� ����� = %.3lf\n", s[i].name, s[i].callnumber, s[i].sales);

}
void option6() {
	char snumber[300];
	int i;
	int max = SIZE;
	printf("�����Ͻ� �ø��� �ѹ��� �Է��ϼ��� : ");
	scanf_s("%d", &snumber);
	for (i = 0; i < max; i++) {
		if (snumber == s[i].number) {
			printf("�ùٸ� �ø��� �ѹ�(%d)�Դϴ�. ", snumber);
			break;
		}
	}
	if (i == max) {
		printf("�ø��� �ѹ�(%d)�� �����ϴ� .", snumber);
		return 0;
	}
	for (int j = i; i < max; j++) {
		s[j] = s[j + 1];
	}
	--max;
	printf("�ø��� �ѹ�(%d)�� �����͸� �����߽��ϴ� \n", snumber);
}
void option7() {
	int i, k;
	printf("������ �ø��� ��ȣ�� �Է��ϼ��� : ");
	scanf_s("%d", &k);
	for (i = 0; i < SIZE; i++) {
		if (s[i].number == k) {
			printf("������ �̸� : ");
			scanf(" %s", s[i].name);
			printf("���� �ø��� �ѹ� : ");
			scanf(" %d", &s[i].number);
			printf("���� �ּ� : ");
			scanf(" %s", s[i].address);
			printf("���� ��ȭ��ȣ : ");
			scanf(" %s", s[i].callnumber);
			for (int j = 0; j < 6; j++) {
				printf("%d ���� ����� : ", j + 1);
				scanf("%d", &s[i].a[j]);
			}
		}
	}
}
void option8() {
	FILE* fp;
	int number;
	int k,j;
	fp = fopen("C:\/Users/82108/newfile/test.txt", "w");
	printf("������ �������� �ø��� �ѹ��� �Է��ϼ��� : ");
	scanf_s("%d", &k);
	for (j = 0; j < SIZE; j++) {
		if (s[j].number == k) {
			fprintf(fp, "������ �̸� = %s ���� �ø��� �ѹ� = %d ���� �ּ� = %s ���� ��ȭ��ȣ = %s 1�� ����� = %d 2�� ����� = %d 3�� ����� = %d 4�� ����� = %d 5�� ����� = %d 6�� ����� = %d", s[j].name, s[j].number, s[j].address, s[j].callnumber, s[j].a[0], s[j].a[1], s[j].a[2], s[j].a[3], s[j].a[4], s[j].a[5]);
			fclose(fp);
			printf(" ���忡 �����߽��ϴ�. \n");
		}
		else if (s[j].number !=k) {
			printf(" ���忡 �����߽��ϴ�. \n");
			//exit(1);
		}
	}
}
void option9() {
	FILE* fp;
	fp = fopen("C:\/Users/82108/newfile/test.txt", "r");
	char buffer[1000] = { 0, };
	fread(buffer,1,1000,fp);
	printf("%s\n", buffer);

	fclose(fp);
}
void menu() {
	printf("�޴��� �����ϼ��� \n");
	printf("1. ������ �Է�\n");
	printf("2. �Է��� ��� ���� ���\n");
	printf("3. ���� �̸����� �˻��ϱ�\n");
	printf("4. ������ �ø��� �ѹ��� �˻��ϱ�\n");
	printf("5. �� ������� ���� ���� ���� �̸��� ��ȭ��ȣ, ����� ���\n");
	printf("6. �ø��� ��ȣ�� ���� �����ϱ�\n");
	printf("7. �ø��� ��ȣ�� ���� �����ϱ�\n");
	printf("8. ���Ϸ� �����ϱ�\n");
	printf("9. ���Ͽ��� �о����\n");
	printf("'q' �Ǵ� 'Q' �Է½� ����\n");
}
int main(void) {
	char c;
	int p = 0;
	menu();
	while (1) {
		printf("�޴� �Է� : ");
		c = getchar();
		if (c == 'q' || c == 'Q') {
			printf("���α׷��� ���� �մϴ� ");
			break;
		}
		else if (c == '1')
			option1();
		else if (c == '2')
			option2();
		else if (c == '3')
			option3();
		else if (c == '4')
			option4();
		else if (c == '5')
			option5();
		else if (c == '6')
			option6();
		else if (c == '7')
			option7();
		else if (c == '8')
			option8();
		else if (c == '9')
			option9();
		getchar();
	}
}