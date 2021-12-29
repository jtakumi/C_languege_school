#include<stdio.h>
int c = 0;
int n=6;

void disp(int n, int x[]) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", x[i]);
        if (i % 10 == 9) {
            printf("\n");
        }
    }
    printf("\n");
}

void swap(int* x, int* y) {  //���ȏ��ł��łɏK����swap�֐����g��
    int wk;
    wk = *x;
    *x = *y;
    *y = wk;
    c++;
}

void qsort(int left, int right, int x[]) {
    int L, R, p;
    L = left;
    R = right;
    p = x[left];
    if (c == 1) {
        printf("L=%d,R=%d\n", L, R);
    }
    while (1) {
        while (x[L] < p) {
            L++;
        }
        while (x[R] > p) {
            R--;
        }
        if (L >= R) {
            break;
        }
        swap(&x[L], &x[R]);
        if (c == 1) {
            printf("1���swap��\n");
            disp(n, x);
        }
        L++; R--;
    }
    if (left < L - 1) {
        qsort(left, L - 1, x);
    }
    if (R + 1 < right) {
        qsort(R + 1, right, x);
    }
}

void main(void) {
    int x[] = { 32,11,45,10,51,97 };
    printf("�\�[�g�O\n");
    disp(n, x);
    qsort(0, n - 1, x);
    printf("�\�[�g��\n");
    disp(n, x);
    printf("swap�֐��Ăяo����%d��\n", c);
}