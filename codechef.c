#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int perimeter = 2 * (x + y);
    if (perimeter >= 1000) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
