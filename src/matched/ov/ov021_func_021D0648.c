/*
 * function: func_021D0648
 * address:  0x021D0648
 * packet:   pkt_ov021_021D0648
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046F50  0x02046F50  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   d_021DB95C     0x021DB95C  data  a4
 *   d_021DB950     0x021DB950  data  ov021  a4
 *   d_021DB954     0x021DB954  data  ov021  a4
 */

typedef unsigned short u16;

typedef struct S {
    int f0;
    int a[3];
    int f10;
    int b[2];
    int f1c;
} S;

extern int func_021ABE24(int a);
extern int func_02046E24(int a, int b);
extern int func_02046F50(int a, int b);
extern void func_02046FF8(int a);
extern int func_02047400(int a, int b, int c);
extern int func_02047564(int a, int b, int c);
extern int func_0204767C(int a, int *b, int c);
extern void func_020477A4(int a, u16 b);

extern int d_021DB95C[3];
extern int d_021DB950;
extern int d_021DB954[2];

void func_021D0648(S *p)
{
    int h;
    int i;
    int j;
    int k;

    h = func_021ABE24(p->f0);
    for (i = 0; i < 3; i++) {
        p->a[i] = func_02046E24(h, d_021DB95C[i]);
        if (func_02046F50(p->a[i], 2)) {
            func_02046FF8(p->a[i]);
        }
    }
    j = 0;
    p->f10 = func_02047400(p->a[d_021DB950], 0, p->a[d_021DB950]);
    k = j;
    for (i = 0; i < 2; i++) {
        p->b[i] = func_02047564(p->f10, p->a[d_021DB954[i]], k);
    }
    p->f1c = func_0204767C(p->f10, p->b, 2);
    for (k = 0; k < 2; k++) {
        func_020477A4(p->f1c, k);
    }
}
