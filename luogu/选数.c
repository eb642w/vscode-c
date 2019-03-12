#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int a[20];
int prm(long long x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i < sqrt(x); i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int n, k, m = 0, p = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        m += a[i];
    }
    if (k == 19 || k == n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (prm(m - a[i]))
                p++;
        }
    }
    else if (k == 20 || n == k)
    {
        if (prm(m))
            p++;
    }
    else if (k == 1)
    {
        for (int i = 0; i < n; i++)
            if (prm(a[i]))
                p++;
    }
    else if (k == 2)
    {
        for (int i = 0; i < n - 1; i++)
            for (int i1 = i + 1; i1 < n; i1++)
                if (prm(a[i] + a[i1]))
                    p++;
    }
    else if (k == 3)
    {
        for (int i = 0; i < n - 2; i++)
            for (int i1 = i + 1; i1 < n - 1; i1++)
                for (int i2 = i1 + 1; i2 < n; i2++)
                    if (prm(a[i] + a[i1] + a[i2]))
                        p++;
    }
    else if (k == 4)
    {
        for (int i = 0; i < n - 3; i++)
            for (int i1 = i + 1; i1 < n - 2; i1++)
                for (int i2 = i1 + 1; i2 < n - 1; i2++)
                    for (int i3 = i2 + 1; i3 < n; i3++)
                        if (prm(a[i] + a[i1] + a[i2] + a[i3]))
                            p++;
    }
    else if (k == 5)
    {
        for (int i = 0; i < n - 4; i++)
            for (int i1 = i + 1; i1 < n - 3; i1++)
                for (int i2 = i1 + 1; i2 < n - 2; i2++)
                    for (int i3 = i2 + 1; i3 < n - 1; i3++)
                        for (int i4 = i3 + 1; i4 < n; i4++)
                            if (prm(a[i] + a[i1] + a[i2] + a[i3] + a[i4]))
                                p++;
    }
    else if (k == 6)
    {
        for (int i = 0; i < n - 5; i++)
            for (int i1 = i + 1; i1 < n - 4; i1++)
                for (int i2 = i1 + 1; i2 < n - 3; i2++)
                    for (int i3 = i2 + 1; i3 < n - 2; i3++)
                        for (int i4 = i3 + 1; i4 < n - 1; i4++)
                            for (int i5 = i4 + 1; i5 < n; i5++)
                                if (prm(a[i] + a[i1] + a[i2] + a[i3] + a[i4] + a[i5]))
                                    p++;
    }
    else if (k == 7)
    {
        for (int i = 0; i < n - 6; i++)
            for (int i1 = i + 1; i1 < n - 5; i1++)
                for (int i2 = i1 + 1; i2 < n - 4; i2++)
                    for (int i3 = i2 + 1; i3 < n - 3; i3++)
                        for (int i4 = i3 + 1; i4 < n - 2; i4++)
                            for (int i5 = i4 + 1; i5 < n - 1; i5++)
                                for (int i6 = i5 + 1; i6 < n; i6++)
                                    if (prm(a[i] + a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6]))
                                        p++;
    }
    else if (k == 8)
    {
        for (int i = 0; i < n - 7; i++)
            for (int i1 = i + 1; i1 < n - 6; i1++)
                for (int i2 = i1 + 1; i2 < n - 5; i2++)
                    for (int i3 = i2 + 1; i3 < n - 4; i3++)
                        for (int i4 = i3 + 1; i4 < n - 3; i4++)
                            for (int i5 = i4 + 1; i5 < n - 2; i5++)
                                for (int i6 = i5 + 1; i6 < n - 1; i6++)
                                    for (int i7 = i6 + 1; i7 < n; i7++)
                                        if (prm(a[i] + a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7]))
                                            p++;
    }
    else if (k == 9)
    {
        for (int i = 0; i < n - 8; i++)
            for (int i1 = i + 1; i1 < n - 7; i1++)
                for (int i2 = i1 + 1; i2 < n - 6; i2++)
                    for (int i3 = i2 + 1; i3 < n - 5; i3++)
                        for (int i4 = i3 + 1; i4 < n - 4; i4++)
                            for (int i5 = i4 + 1; i5 < n - 3; i5++)
                                for (int i6 = i5 + 1; i6 < n - 2; i6++)
                                    for (int i7 = i6 + 1; i7 < n - 1; i7++)
                                        for (int i8 = i7 + 1; i8 < n; i8++)
                                            if (prm(a[i] + a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8]))
                                                p++;
    }
    else if (k == 10)
    {
        for (int i = 0; i < n - 9; i++)
            for (int i1 = i + 1; i1 < n - 8; i1++)
                for (int i2 = i1 + 1; i2 < n - 7; i2++)
                    for (int i3 = i2 + 1; i3 < n - 6; i3++)
                        for (int i4 = i3 + 1; i4 < n - 5; i4++)
                            for (int i5 = i4 + 1; i5 < n - 4; i5++)
                                for (int i6 = i5 + 1; i6 < n - 3; i6++)
                                    for (int i7 = i6 + 1; i7 < n - 2; i7++)
                                        for (int i8 = i7 + 1; i8 < n - 1; i8++)
                                            for (int i9 = i8 + 1; i9 < n; i9++)
                                                if (prm(a[i] + a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9]))
                                                    p++;
    }
    else if (k == 11)
    {
        for (int i = 0; i < n - 8; i++)
            for (int i1 = i + 1; i1 < n - 7; i1++)
                for (int i2 = i1 + 1; i2 < n - 6; i2++)
                    for (int i3 = i2 + 1; i3 < n - 5; i3++)
                        for (int i4 = i3 + 1; i4 < n - 4; i4++)
                            for (int i5 = i4 + 1; i5 < n - 3; i5++)
                                for (int i6 = i5 + 1; i6 < n - 2; i6++)
                                    for (int i7 = i6 + 1; i7 < n - 1; i7++)
                                        for (int i8 = i7 + 1; i8 < n; i8++)
                                            if (prm(m - (a[i] + a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8])))
                                                p++;
    }
    else if (k == 12)
    {
        for (int i = 0; i < n - 7; i++)
            for (int i1 = i + 1; i1 < n - 6; i1++)
                for (int i2 = i1 + 1; i2 < n - 5; i2++)
                    for (int i3 = i2 + 1; i3 < n - 4; i3++)
                        for (int i4 = i3 + 1; i4 < n - 3; i4++)
                            for (int i5 = i4 + 1; i5 < n - 2; i5++)
                                for (int i6 = i5 + 1; i6 < n - 1; i6++)
                                    for (int i7 = i6 + 1; i7 < n; i7++)
                                        if (prm(m - (a[i] + a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7])))
                                            p++;
    }
    else if (k == 13)
    {
        for (int i = 0; i < n - 6; i++)
            for (int i1 = i + 1; i1 < n - 5; i1++)
                for (int i2 = i1 + 1; i2 < n - 4; i2++)
                    for (int i3 = i2 + 1; i3 < n - 3; i3++)
                        for (int i4 = i3 + 1; i4 < n - 2; i4++)
                            for (int i5 = i4 + 1; i5 < n - 1; i5++)
                                for (int i6 = i5 + 1; i6 < n; i6++)
                                    if (prm(m - (a[i] + a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6])))
                                        p++;
    }
    else if (k == 14)
    {
        for (int i = 0; i < n - 5; i++)
            for (int i1 = i + 1; i1 < n - 4; i1++)
                for (int i2 = i1 + 1; i2 < n - 3; i2++)
                    for (int i3 = i2 + 1; i3 < n - 2; i3++)
                        for (int i4 = i3 + 1; i4 < n - 1; i4++)
                            for (int i5 = i4 + 1; i5 < n; i5++)
                                if (prm(m - (a[i] + a[i1] + a[i2] + a[i3] + a[i4] + a[i5])))
                                    p++;
    }
    else if (k == 15)
    {
        for (int i = 0; i < n - 4; i++)
            for (int i1 = i + 1; i1 < n - 3; i1++)
                for (int i2 = i1 + 1; i2 < n - 2; i2++)
                    for (int i3 = i2 + 1; i3 < n - 1; i3++)
                        for (int i4 = i3 + 1; i4 < n; i4++)
                            if (prm(m - (a[i] + a[i1] + a[i2] + a[i3] + a[i4])))
                                p++;
    }
    else if (k == 16)
    {
        for (int i = 0; i < n - 3; i++)
            for (int i1 = i + 1; i1 < n - 2; i1++)
                for (int i2 = i1 + 1; i2 < n - 1; i2++)
                    for (int i3 = i2 + 1; i3 < n; i3++)
                        if (prm(m - (a[i] + a[i1] + a[i2] + a[i3])))
                            p++;
    }
    else if (k == 17)
    {
        for (int i = 0; i < n - 2; i++)
            for (int i1 = i + 1; i1 < n - 1; i1++)
                for (int i2 = i1 + 1; i2 < n; i2++)
                    if (prm(m - (a[i] + a[i1] + a[i2])))
                        p++;
    }
    else if (k == 18)
    {
        for (int i = 0; i < n - 1; i++)
            for (int i1 = i + 1; i1 < n; i1++)
                if (prm(m - (a[i] + a[i1])))
                    p++;
    }
    printf("%d", p);
    system("pause");
    return 0;
}
