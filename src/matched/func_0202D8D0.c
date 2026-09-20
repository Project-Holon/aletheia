/*
 * unit:     no
 * function: func_0202D8D0
 * address:  0x0202D8D0
 * packet:   pkt_0202D7D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02017E88  0x02017E88  thumb
 *   func_02017EB4  0x02017EB4  thumb
 *   func_0202D7D8  0x0202D7D8  thumb
 */

extern int func_02017E88(void *obj, int which, int zero);
extern int func_02017EB4(void *obj);
extern int func_0202D7D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                          unsigned short a8, unsigned short a9);

int func_0202D8D0(int a0, void *a1, int a2, int a3, unsigned short a8, unsigned short a9)
{
    int v1 = func_02017E88(a1, 5, 0);
    int v2 = func_02017E88(a1, 0x6f, 0);
    int v3 = func_02017E88(a1, 0x6e, 0);
    int v4 = func_02017EB4(a1);
    int v5 = func_02017E88(a1, 0x4c, 0);

    return func_0202D7D8(a0, v1, v2, v3, v4, a2, v5, a3, a8, a9);
}
