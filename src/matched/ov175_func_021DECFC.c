/*
 * function: func_021DECFC
 * address:  0x021DECFC
 * packet:   pkt_ov175_021DECFC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: sakeiGetMyRecordsValidateInput
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.
 *
 * symbols:
 *   func_021DE14C  0x021DE14C  arm  ov175
 */

typedef unsigned int u32;

extern int func_021DE14C(char **, int);

int func_021DECFC(u32 ctx)
{
    u32 *p = *(u32 **)((char *)ctx + 8);

    if (p[0] == 0)
        return 4;
    if ((int)p[2] <= 0)
        return 6;
    if (p[1] == 0)
        return 5;
    return func_021DE14C((char **)p[1], p[2]);
}
