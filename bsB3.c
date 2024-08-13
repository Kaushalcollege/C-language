#include <stdio.h>

long long SOD(int n) {
    long long sodsum = 0;
    for (int i = 2; i <= n; i++) {
        sodsum = sodsum + (n / i - 1) * i;
    }
    return sodsum;
}

int main() {
    int hehe;
    scanf("%d", &hehe);
    while (hehe--) {
        int n;
        scanf("%d", &n);
        if (n <= 1) {
            printf("0\n");
        } else {
            printf("%lld\n", SOD(n));
        }
    }
    return 0;
}
