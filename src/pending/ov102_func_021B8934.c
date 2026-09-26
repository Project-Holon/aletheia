/*
 * function: func_021B8934
 * address:  0x021B8934
 * packet:   pkt_ov102_021B8934
 * region:   ov102
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Blocker: codegen only, register colouring.  The original keeps the base
 *          parameter `a` in r6 and the third parameter `c` in r5; every
 *          spelling tried makes mwccarm colour them the other way (a->r5,
 *          c->r6), which also changes whether the loop-bound pointer `p`
 *          is spilled to [sp,#8] or rematerialised.  128 vs 132 bytes.
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0200A8AC  0x0200A8AC  thumb
 *   func_021B78EC  0x021B78EC  thumb  ov102
 *   func_02005728  0x02005728  thumb
 *   func_0200A8F8  0x0200A8F8  thumb
 *   func_021B8810  0x021B8810  thumb  ov102
 */

extern void func_02082BCC(int, int, int);
extern int func_0200A8AC(int);
extern int func_021B78EC(int, int);
extern int func_02005728(int);
extern int func_0200A8F8(int, int);
extern void func_021B8810(int, int, int, int);

void func_021B8934(int a, int b, int c, int d)
{
    unsigned short *p;
    int i;

    func_02082BCC(a, 0, 0x350);
    if (c == 0)
        *(unsigned short *)(a + 0x34e) = 0x1e;
    else
        *(unsigned short *)(a + 0x34e) = func_0200A8AC(c);
    p = (unsigned short *)(a + 0x34e);
    for (i = 0; i < *p; i++) {
        int t = func_021B78EC(b, i);
        int u;

        if (c == 0)
            u = func_02005728(2);
        else
            u = (func_0200A8F8(c, i) == 1);
        func_021B8810(a + i * 0x1c, t, u, d);
    }
}
