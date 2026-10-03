/*
 * function: func_0217B4D8
 * address:  0x0217B4D8
 * packet:   pkt_ov018_0217B4D8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02175BE4  0x02175BE4  thumb  ov011
 *   func_0217B044  0x0217B044  thumb  ov018
 *   func_0217B1DC  0x0217B1DC  thumb  ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_02012138();
extern u8 *func_02158344();
extern int func_0203D1B4();
extern int func_02175BE4(void *a);
extern void *func_0217B044(void *a, int b, int c, int d, int e, int f);
extern void *func_0217B1DC();

void *func_0217B4D8(int a0, int a1, int a2, int *a3, int a4, u16 a5)
{
    u8 *p;
    int r;
    int col;
    int x;
    int n;
    int sub;

    p = func_02158344(func_02012138(a0));
    r = 9;
    x = *a3;
    n = 1;
    if (p)
        n = p[0x902];
    if (x <= 0) {
        x += n << 22;
    } else if (x >= n << 22) {
        x -= n << 22;
    }
    col = ((x >> 12) / 16) % 64;
    sub = x % 0x400000;
    if (a5 == 2) {
        if ((a4 != 3 || (a4 == 3 && sub <= 0x8000)) && col == 0)
            r = 2;
    } else if (a5 == 3) {
        if ((a4 != 2 || (a4 == 2 && sub >= 0x3F8000)) && col == 0x3F)
            r = 3;
    }
    if (r != 9) {
        if (p == 0 || func_0203D1B4() <= 1 || p[0x902] < 2)
            return func_0217B044((void *)a0, a1, a2, a4, r, 0);
        if (func_02175BE4(p + 0x1AC) == 1)
            return func_0217B044((void *)a0, a1, a2, a4, r, 1);
        return func_0217B1DC(a0, a1, a2, r);
    }
    return 0;
}
