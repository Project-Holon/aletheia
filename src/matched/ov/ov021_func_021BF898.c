/*
 * function: func_021BF898
 * address:  0x021BF898
 * packet:   pkt_ov021_021BF898
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE92C 0x021BE92C thumb ov021
 *   func_021BE9A0 0x021BE9A0 thumb ov021
 *   func_021BF8DC 0x021BF8DC thumb ov021
 */

typedef unsigned char u8;

extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *func_021BE9A0(void *p, int a1, int a2, int a3, int a4, int a5);
extern void func_021BF8DC(u8 *);

void *func_021BF898(int *q)
{
    int c = q[23];
    int a = q[0];
    int b = q[1];

    if (c != 0) {
        return func_021BE9A0((void *)a, b, (u8)q[24], (u8)q[25], (int)func_021BF8DC, (int)q);
    }
    return (void *)func_021BE92C((void *)a, b, 1, 1, 1, 0, 0);
}
