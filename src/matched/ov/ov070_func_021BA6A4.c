/*
 * function: func_021BA6A4
 * address:  0x021BA6A4
 * packet:   pkt_ov070_021BA6A4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0202EE0C  0x0202EE0C  thumb
 */

typedef struct {
    unsigned short a, b;
} Pt;

extern int func_021B61C8(char *);
extern void func_0204B454(int, Pt *, int);
extern void func_0204B404(int, Pt *, int);
extern int func_0202EE0C(int, int, int, int, int);

void func_021BA6A4(char *p)
{
    Pt pt;
    int n = func_021B61C8(p);
    if (n >= 7) {
        func_0204B454(*(int *)(p + 0x6A8), &pt, 0xFFFF);
        pt.b = func_0202EE0C(n - 6, *(int *)(p + 0x814) + 1, 0x1A, 0x8E, 0);
        func_0204B404(*(int *)(p + 0x6A8), &pt, 0xFFFF);
    }
}
