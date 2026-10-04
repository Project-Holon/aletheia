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

typedef unsigned int   u32;
void *func_02046DB8(u32 a0, u32 a1);
int func_0218D0D8(void *a, void *b);
u32 func_020470A8(void *p);

/* The trailing guard is the function exit: only its cmp survives. */
void func_0218BC40(unsigned char *p, int a, int b, int c)
{
    *(int *)(p + 0x1D0) = (int)func_02046DB8(a, b);
    if (c != 0)
        func_0218D0D8((void *)(*(int *)(p + 0x1D0)), (void *)c);
    if (func_020470A8((void *)(*(int *)(p + 0x1D0))) == 0)
        return;
}
