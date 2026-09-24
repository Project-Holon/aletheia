/*
 * function: func_021DDB10
 * address:  0x021DDB10
 * packet:   pkt_021DDB10
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DD98C  0x021DD98C  arm
 *   func_021DDA98  0x021DDA98  arm
 *
 * Store the +0x20 flag, run the +0x08 side of the pair and, when it comes
 * back empty, tear the object down and report 0.
 */

extern int func_021DD98C(void);
extern void func_021DDA98(void *);

int func_021DDB10(void *p, int v)
{
    int r;

    *(int *)((char *)p + 0x20) = v;
    r = func_021DD98C();
    if (r)
        return r;
    func_021DDA98(p);
    return 0;
}

