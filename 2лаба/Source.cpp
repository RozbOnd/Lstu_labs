#include <iostream>
#include <clocale>
#include "match_search.h"
#include "interval.h"
#include <algorithm>

using namespace std;

/*
apple huh 5 3.14
banana jojo 2 0.43
potato lol 63 6.32
cola jojo 5 9.64
candy trot 3 2.3243
jelly jel 9 4.65
*/

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������� ���-�� ��������� (�� 1 �� 100): ";
	while (cin >> n) {
		if (n < 1 || n > 100) {
			cout << "������������ ����.\n";
			cout << "������� ���-�� ��������� (�� 1 �� 100): ";
			continue;
		}
		break;
	}

	cout << "������� ��������: \n";
	element* els = new element[n];
	for (int i = 0; i < n; i++) cin >> els[i].a >> els[i].b >> els[i].c >> els[i].d;

	element* els_char = copy_arr(els, n);
	element* els_int = copy_arr(els, n);
	element* els_float = copy_arr(els, n);
	sort_Shell(els, n, comp_a);
	sort_Shell(els_char, n, comp_b);
	sort_Shell(els_int, n, comp_c);
	sort_Shell(els_float, n, comp_d);

	while (1) {
		cout << "1 - ������������� ����� �� ����������, 2 - ������������� ����� �� ���������, 3 - ���������.\n";
		int ch;
		while (cin >> ch) {
			if (ch != 1 && ch != 2 && ch != 3) {
				cout << "����������� ����.\n";
				cout << "1 - ������������� ����� �� ����������, 2 - ������������� ����� �� ���������, 3 - ���������.\n";
				continue;
			}
			break;
		}
		if (ch == 3)
			break;
		cout << "1 - ����� �� ����� (�����), 2 - ����� �� �����, 3 - ����� �� ������ �����, 4 - ����� �� �������� �����.\n";
		int ch2;
		while (cin >> ch2) {
			if (ch2 != 1 && ch2 != 2 && ch2 != 3 && ch2 != 4) {
				cout << "����������� ����.\n";
				cout << "1 - ����� �� ����� (�����), 2 - ����� �� �����, 3 - ����� �� ������ �����, 4 - ����� �� �������� �����.\n";
				continue;
			}
			break;
		}
		if (ch == 1) {
			if (ch2 == 1) {
				cout << "������� �����: ";
				char* str = new char[20];
				cin >> str;
				match_search_a(els, n, str);
			}
			else if (ch2 == 2) {
				cout << "������� �����: ";
				char* str = new char[40];
				cin >> str;
				match_search_b(els_char, n, str);
			}
			else if (ch2 == 3) {
				cout << "������� ����� �����: ";
				int num;
				cin >> num;
				match_search_c(els_int, n, num);
			}
			else {
				cout << "������� ������� �����: ";
				float num;
				cin >> num;
				match_search_d(els_float, n, num);
			}
		}

		else if (ch == 2) {
			if (ch2 == 1) {
				cout << "������� ������ ����� : ";
				char* str1 = new char[20];
				cin >> str1;
				cout << "������� ������ ����� : ";
				char* str2 = new char[20];
				cin >> str2;
				interval_search_a(els, n, str1, str2);
			}
			else if (ch2 == 2) {
				cout << "������� ������ ����� : ";
				char* str1 = new char[40];
				cin >> str1;
				cout << "������� ������ ����� : ";
				char* str2 = new char[40];
				cin >> str2;
				interval_search_b(els_char, n, str1, str2);
			}
			else if (ch2 == 3) {
				cout << "������� ������ ����� �����: ";
				int num1;
				cin >> num1;
				cout << "������� ������ ����� �����: ";
				int num2;
				cin >> num2;
				interval_search_c(els_int, n, num1, num2);
			}
			else {
				cout << "������� ������ ������� �����: ";
				float num1;
				cin >> num1;
				cout << "������� ������ ������� �����: ";
				float num2;
				cin >> num2;
				interval_search_d(els_float, n, num1, num2);
			}
		}
	}
	return 0;
}