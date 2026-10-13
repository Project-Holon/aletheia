/*
 * function: scCreateReport
 * address:  0x021DFC8C
 * packet:   pkt_ov175_021DFC8C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: scCreateReport (TwlDWC/libdwcgssc.TWL.HYB.a, scimain.o),
 * ov175.  Guard the handle and the out-parameter, then forward to
 * sciCreateReport and publish the new record on success.
 *
 * symbols:
 *   sciCreateReport  0x021DFE2C  arm  ov175
 */

typedef unsigned int u32;

extern int sciCreateReport(void *, int, int, int, void **);

int scCreateReport(u32 *p, int a1, int a2, int a3, void **out)
{
    void *tmp = 0;
    int r;

    if (p == 0)
        return 2;
    if (out == 0)
        return 2;
    r = sciCreateReport((char *)p + 0x5c, a1, a2, a3, &tmp);
    if (r == 0)
        *out = tmp;
    return r;
}
