#pragma once
#include "Sorting.h"

using namespace std;

void match_search_a(element* els, int size, char str[]) {
    int left = 0;
    int right = size - 1;
    bool f = 0;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        int cmp = strcmp(els[mid].a, str);

        if (cmp == 0) { f = 1; break; }
        else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    if (f == 0) cout << "� ������� ��� �������� � ����� ��������� ����� :(\n";
    else {
        cout << "������ � ������ " << str << ":\n";
        els[mid].print();
    }
}

void match_search_b(element* els, int size, char* str) {
    int left = 0;
    int right = size - 1;
    bool f = 0;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        int cmp = strcmp(els[mid].b, str);

        if (cmp == 0) { f = 1; break; }
        else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    if (f == 0) cout << "� ������� ��� �������� � ����� ��������� char* :(\n";
    else {
        cout << "������ � char* " << str << ":\n";
        els[mid].print();
    }
}

void match_search_c(element* els, int size, int num) {
    int left = 0;
    int right = size - 1;
    bool f = 0;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (els[mid].c == num) { f = 1; break; }
        else if (els[mid].c < num) left = mid + 1;
        else right = mid - 1;
    }
    if (f == 0) cout << "� ������� ��� �������� � ����� ��������� int :(\n";
    else {
        cout << "������ � int " << num << ":\n";
        els[mid].print();
    }
}

void match_search_d(element* els, int size, float num) {
    int left = 0;
    int right = size - 1;
    bool f = 0;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (els[mid].d == num) { f = 1; break; }
        else if (els[mid].d < num) left = mid + 1;
        else right = mid - 1;
    }
    if (f == 0) cout << "� ������� ��� �������� � ����� ��������� float :(\n";
    else {
        cout << "������ � float " << num << ":\n";
        els[mid].print();
    }
}