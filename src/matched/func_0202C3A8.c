/*
 * function: func_0202C3A8
 * address:  0x0202C3A8
 * packet:   pkt_0202C3A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern int func_0202C538(int v);
void func_0202C3A8(char *p, int a1)
{
    int i;
    for (i = 0; i < 9; i++)
        *(int *)(p + 0x18 + i * 4) = func_0202C538(a1);
}
