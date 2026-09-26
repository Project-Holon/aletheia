/*
 * function: func_021C1C98
 * address:  0x021C1C98
 * packet:   pkt_ov114_021C1C98
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021CE7B0    0x021CE7B0  data  a4
 *   d_021CE713    0x021CE713  data  a1
 *   d_021CED3C    0x021CED3C  data  a4
 *   func_0217EAE0 0x0217EAE0  arm
 *   func_0217D254 0x0217D254  arm
 */

extern char d_021CE7B0[];
extern char d_021CE713[];
extern char d_021CED3C[];

extern void func_0217EAE0(void *);
extern void func_0217D254(int, int, int, void *, ...);

int func_021C1C98(int unused, unsigned int *p)
{
    func_0217D254(8, 4, 0xf, d_021CED3C, d_021CE7B0, d_021CE713, 0x4d5);
    if (p != 0) {
        unsigned int *q = (unsigned int *)p[0];
        if (q != 0) {
            if (q[0] != 0)
                func_0217EAE0((void *)q[0]);
            func_0217EAE0(q);
            p[0] = 0;
        }
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
    }
    return 1;
}
