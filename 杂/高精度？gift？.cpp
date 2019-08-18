#include <cstdio>
const int MAXN = 10;
int a[MAXN];
int main()
{
    int i, j, T;
    unsigned long long s,temp;
    scanf("%d", &T);
    while (T--)
    {
        s = 0;
        for (i = 1; i <= 8; i++)
        {
            scanf("%d", &a[i]);
            s += (1LL<<a[i]);
        }
        scanf("%llu", &temp);
        if (s != 1LL << 63 || temp != s)
        printf("%llu\n", s + temp);
        else puts("18446744073709551616");
    }
}
