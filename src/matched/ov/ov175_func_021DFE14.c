/*
 * function: scDestroyReport
 * address:  0x021DFE14
 * packet:   pkt_021DFE14
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sciDestroyReport  0x021DFF30  arm
 *   sciDestroyReport  0x_021DFF30  arm  ov175
 *
 * ARM tail jump to sciDestroyReport in the ov175 prologue group.
 */

typedef unsigned int   u32;
extern int sciDestroyReport(u32 *p);

int scDestroyReport(u32 *a0)
{
    return sciDestroyReport(a0);
}

