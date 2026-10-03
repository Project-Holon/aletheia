/*
 * function: func_021C5B58
 * address:  0x021C5B58
 * packet:   pkt_ov021_021C5B58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5A28  0x021C5A28  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0216C0C0  0x0216C0C0  thumb  ov010
 */

typedef unsigned short u16;

extern int func_021C5A28(int a, int b, int c, int d);
extern void func_02012374(int a, int b);
extern void func_02017E40(int a, int b, int c);
extern int func_020120F4(int a);
extern int func_02012F2C(int a);
extern void func_02008DF0(int a, int b);
extern int func_0216C0C0(int a0);

int func_021C5B58(int a, int *st, int *c)
{
    int *q;
    int f;

    switch (*st) {
    case 0:
        func_02012374(a, func_021C5A28(c[0], c[1], c[2], c[5]));
        (*st)++;
        break;
    case 1:
        q = (int *)c[2];
        if (q[7] != 1) {
            func_02017E40(c[3], 0x73, q[8]);
        }
        f = 1;
        if (((int *)c[2])[7] == 1) {
            f = 0;
        }
        *(u16 *)c[4] = f;
        if (*(u16 *)c[4] == 1) {
            func_02008DF0(func_02012F2C(func_020120F4(c[0])), 0x1e);
        }
        func_0216C0C0(c[2]);
        return 1;
    }
    return 0;
}
