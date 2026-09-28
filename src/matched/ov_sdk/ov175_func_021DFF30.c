/*
 * function: func_021DFF30
 * address:  0x021DFF30
 * packet:   pkt_ov175_021DFF30
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: sciDestroyReport (TwlDWC/libdwcgssc.TWL.HYB.a, scireport.o),
 * ov175.  Free the record buffer, clear the report, then free the report
 * object itself.
 *
 * symbols:
 *   func_0217EAE0  0x0217EAE0  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0217EAE0(void *);

int func_021DFF30(u32 *p)
{
    u32 *q = (u32 *)p[0x124 / 4];

    p[0] = 0;
    *(u16 *)(p + 2) = 0;
    p[1] = 0;
    p[4] = 0;
    p[3] = 0;
    func_0217EAE0(q);
    p[0x124 / 4] = 0;
    p[0x11c / 4] = 0;
    p[0x118 / 4] = 0;
    p[0x120 / 4] = 0;
    func_0217EAE0(p);
    return 0;
}
