/*
 * function: func_021B81A0
 * address:  0x021B81A0
 * packet:   pkt_ov071_021B81A0
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6C54  0x021B6C54  thumb  ov071
 *   func_021B6A0C  0x021B6A0C  thumb  ov071
 *   func_020355C4  0x020355C4  arm
 *   func_021B6B98  0x021B6B98  thumb  ov071
 *   d_021BA978     0x021BA978  data  a4
 *   d_021BA9A4     0x021BA9A4  data  a4
 */

typedef unsigned char u8;

extern unsigned d_021BA978[];
extern int d_021BA9A4[][3];

extern void func_021B6C54(void *a);
extern void func_021B6A0C(int a, void *b, int c, int d, int e, int f, int g, int h);
extern int func_020355C4(void);
extern void func_021B6B98(void *p, void *tbl, int n, int sel, int c);

void func_021B81A0(int *a, u8 *p)
{
    unsigned i;
    unsigned k;

    func_021B6C54(a);
    for (i = 0; i < d_021BA978[p[0x32]]; i++) {
        k = p[0x32];
        if (k == 1) {
            func_021B6A0C(a[1], p + i * 16, 1, 1, 0x80, d_021BA9A4[k][i], i + 1, 0);
        } else if (k == 0) {
            func_021B6A0C(a[1], p + i * 16, 1, 1, 0x80, d_021BA9A4[k][i], i + 2, 0);
        } else if (k == 2) {
            func_021B6A0C(a[1], p + i * 16, 1, 1, 0x80, d_021BA9A4[k][i], i == 0 ? 1 : 3, 0);
        }
    }
    if (func_020355C4() == 0) {
        func_021B6B98(a, p, d_021BA978[p[0x32]], 0, 3);
        p[0x33] = 0;
    } else {
        p[0x33] = 1;
    }
}
