/*
 * unit:     no
 * function: func_0202D934
 * address:  0x0202D934
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
 *   func_0202D81C  0x0202D81C  thumb
 */

typedef unsigned int   u32;
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02017EB4(void *p);
extern int func_0202D81C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                          int a8, unsigned short a9);

int func_0202D934(int a0, void *a1, int a2, int a3, unsigned short a9)
{
    int v1 = func_02017E88(a1, 5, 0);
    int v2 = func_02017E88(a1, 0x6f, 0);
    int v3 = func_02017E88(a1, 0x6e, 0);
    int v_eb4 = func_02017EB4(a1);
    int v4 = func_02017E88(a1, 0x4c, 0);
    int v5 = func_02017E88(a1, 0, 0);

    return func_0202D81C(a0, v1, v2, v3, v_eb4, a2, v4, v5, a3, a9);
}
