#include <iostream>
#include <cmath>

void masterTheorem(int a, float b, float c, float d, int k)
{
    float logba = log(a) / log(b);
    float logba_rounded = std::round(logba * 10.0) / 10;

    if (logba > d)
    {
        if (logba_rounded == 0)
        {
            std::cout << "T(n) = \u0398(1)" << std::endl;
        }
        else if (logba_rounded == 1)
        {
            std::cout << "T(n) = \u0398(n)" << std::endl;
        }
        else
        {
            std::cout << "T(n) = \u0398(n^" << logba_rounded << ")" << std::endl;
        }
    }
    else if (logba == d)
    {
        if (logba_rounded == 0)
        {
            if (k == -1)
            {
                std::cout << "T(n) = \u0398(1)" << std::endl;
            }
            else if (k == 0)
            {
                std::cout << "T(n) = \u0398(log n)" << std::endl;
            }
            else
            {
                std::cout << "T(n) = \u0398(log^" << k + 1 << " n)" << std::endl;
            }
        }
        else if (logba_rounded == 1)
        {
            if (k == -1)
            {
                std::cout << "T(n) = \u0398(n)" << std::endl;
            }
            else if (k == 0)
            {
                std::cout << "T(n) = \u0398(n log n)" << std::endl;
            }
            else
            {
                std::cout << "T(n) = \u0398(n log^" << k + 1 << " n)" << std::endl;
            }
        }
        else
        {
            if (k == -1)
            {
                std::cout << "T(n) = \u0398(n^" << logba_rounded << ")" << std::endl;
            }
            else if (k == 0)
            {
                std::cout << "T(n) = \u0398(n^" << logba_rounded << " log n)" << std::endl;
            }
            else
            {
                std::cout << "T(n) = \u0398(n^" << logba_rounded << " log^" << k + 1 << " n)" << std::endl;
            }
        }
    }
    else
    {
        if (d == 0)
        {
            if (k == 0)
            {
                std::cout << "T(n) = \u0398(1)" << std::endl;
            }
            else if (k == 1)
            {
                std::cout << "T(n) = \u0398(log n)" << std::endl;
            }
            else
            {
                std::cout << "T(n) = \u0398(log^" << k << " n)" << std::endl;
            }
        }
        else if (d == 1)
        {
            if (k == 0)
            {
                std::cout << "T(n) = \u0398(n)" << std::endl;
            }
            else if (k == 1)
            {
                std::cout << "T(n) = \u0398(n log n)" << std::endl;
            }
            else
            {
                std::cout << "T(n) = \u0398(n log^" << k << " n)" << std::endl;
            }
        }
        else
        {
            if (k == 0)
            {
                std::cout << "T(n) = \u0398(n^" << d << ")" << std::endl;
            }
            else if (k == 1)
            {
                std::cout << "T(n) = \u0398(n^" << d << " log n)" << std::endl;
            }
            else
            {
                std::cout << "T(n) = \u0398(n^" << d << " log^" << k << " n)" << std::endl;
            }
        }
    }
}

int main()
{
    int TC, a, k;
    float b, c, d;
    std::cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        std::cin >> a >> b >> c >> d >> k;
        masterTheorem(a, b, c, d, k);
    }
    return 0;
}