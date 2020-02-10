#include <stdio.h>

// 算法
void sort(int *data, int n) {
    for (int i = 0; i < n; ++i) {
        // 这里注意上限是n - i - 1
        // (- i )因为每次循环必然在最上面会新增一个已排序的元素
        for (int j = 0; j < n - i - 1; ++j) {
            // 比较相邻元素，如果比后一个元素更大，则swap
            if (data[j] > data[j+1] ) {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }
}

int main() {
    int a[5] = {3,5,7,2,4};
    sort(a, 5);
    for (int i : a) {
        printf("%d\n", i);
    }
}
