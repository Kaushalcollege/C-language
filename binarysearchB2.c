#include <stdio.h>
#include <math.h>

long long SOD(int x) {
    long long sodsum = 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            if (i == x / i) {
                sodsum += i;
            } else {
                sodsum += i + (x / i);
            }
        }
    }
    return sodsum;
}

long long CSOD(int y) {
    long long csodsum = 0;
    for (int i = 1; i <= y; i++) {
        csodsum += SOD(i);
    }
    return csodsum;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", CSOD(n));
    }
    return 0;
}
