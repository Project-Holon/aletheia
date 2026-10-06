/*
 * function: func_021CD338
 * address:  0x021CD338
 * packet:   pkt_021CD338
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D55A4  0x021D55A4  arm
 *   func_021D603C  0x021D603C  arm
 *   func_021C0EA0  0x021C0EA0  arm
 *   func_021C0E40  0x021C0E40  arm
 *   func_021CD3B8  0x021CD3B8  arm
 */

extern void func_021D55A4(int a, int b, int c, int d);
extern void func_021D603C(int a, int b);
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern void func_021C0E40(unsigned int v);
extern void func_021CD3B8(void);

void func_021CD338(void)
{
    int v;

    func_021D55A4(2, 0, 0x15, 8);
    func_021D603C(0, 0x15);
    func_021C0EA0(0, (unsigned int *)(&v));
    if (v == 0) {
        func_021D55A4(2, 1, 1, 8);
        func_021D603C(1, 1);
    }
    func_021C0E40((unsigned int)func_021CD3B8);
}
