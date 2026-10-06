extern int g(int, int);
int swap2(int a, int b)
{
    int x = a + 1;
    int y = b * 3;
    int t;
    t = x; x = y; y = t;
    return g(x, y) + x - y;
}
