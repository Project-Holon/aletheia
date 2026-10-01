/*
 * function: func_0218BC40
 * address:  0x0218BC40
 * packet:   pkt_ov021_0218BC40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02046DB8  0x02046DB8  arm
 *   func_0218D0D8  0x0218D0D8  thumb  ov021
 *   func_020470A8  0x020470A8  arm
 */

int func_02046DB8(int a, int b);
void func_0218D0D8(int h, int c);
int func_020470A8(int h);

/* The trailing guard is the function exit: only its cmp survives. */
void func_0218BC40(unsigned char *p, int a, int b, int c)
{
    *(int *)(p + 0x1D0) = func_02046DB8(a, b);
    if (c != 0)
        func_0218D0D8(*(int *)(p + 0x1D0), c);
    if (func_020470A8(*(int *)(p + 0x1D0)) == 0)
        return;
}
