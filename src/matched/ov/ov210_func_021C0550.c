/*
 * function: func_021C0550
 * address:  0x021C0550
 * packet:   pkt_ov210_021C0550
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B796C 0x021B796C thumb ov067
 *   func_02045808 0x02045808 arm
 * Addresses are Black-image addresses.
 */

extern void func_021B796C(int h);
extern void func_02045808(int h);

void func_021C0550(int p)
{
    unsigned i;

    func_021B796C(*(int *)(p + 0x1e0));
    *(int *)(p + 0x1e0) = 0;
    for (i = 0; i < 0x32; i++) {
        int *q = (int *)(p + i * 4);

        if (q[0x79] != 0) {
            func_02045808(q[0x79]);
            q[0x79] = 0;
        }
    }
}
