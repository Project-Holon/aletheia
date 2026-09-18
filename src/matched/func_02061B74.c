/*
 * unit:     no
 * function: func_02061B74
 * address:  0x02061B74
 * packet:   pkt_02061B2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned short u16;
extern int func_02061860(void *p);
extern int func_02061840(void *p, int v);
int func_02061B74(char *p)
{
    int v;
    if (func_02061860(p))
        return 0;
    v = func_02061840(p, *(u16 *)(p + 0xa));
    *(volatile u16 *)(p + 0xa) = (u16)v;
    *(volatile u16 *)(p + 0xc) = (u16)(*(volatile u16 *)(p + 0xc) + 1);
    return 1;
}

