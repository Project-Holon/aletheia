/*
 * function: func_021A8324
 * address:  0x021A8324
 * packet:   pkt_ov021_021A8324
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_02012374  0x02012374  thumb
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int pad10[10];
    int f38;
    int f3c;
    int f40;
} R;

extern int func_021BE8D4(int a, int b, int c, int d);
extern void func_02012374(int a, int b);

void func_021A8324(int a, R **r)
{
    R *p = *r;
    int t;
    if (p->f40 != 0) {
        t = func_021BE8D4(p->f4, p->fc, 0, 0);
    } else {
        t = func_021BE8D4(p->f4, p->fc, p->f38, 0);
    }
    func_02012374(a, t);
}
