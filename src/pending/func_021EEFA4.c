/*
 * function: func_021EEFA4
 * address:  0x021EEFA4
 * packet:   pkt_021EEFA4
 * region:   ov188
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Blocker: register allocation.  The original keeps the 0xC38 constant in
 *   r6, a in r7 and i in r5, and recomputes `a + i*4 + 0x24` each pass;
 *   mwcc folds a+0x24 into a base register and reallocates the rest.
 *
 * symbols:
 *   func_02082BCC   0x02082BCC  arm
 *   func_021EEED8   0x021EEED8  thumb
 *
 * Clear 0xA90 bytes at p+0xC38, then release each non-null entry of the
 *   four-record table at a+0x24.
 */


extern void func_02082BCC(int, int, int);
extern void func_021EEED8(int, char *);

void func_021EEFA4(int a, char *p)
{
    unsigned int i;
    char *base;
    func_02082BCC((int)(p + 0xC38), 0, 0xA90);
    base = p + 0xC38;
    for (i = 0; i < 4; i++) {
        int v = *(int *)(a + 0x24 + i * 4);
        if (v != 0)
            func_021EEED8(v, base + i * 0x2A4);
    }
}
