/*
 * function: func_021DEBF4
 * address:  0x021DEBF4
 * packet:   pkt_ov175_021DEBF4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: sakeiGetSpecificRecordsValidateInput
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.
 *
 * symbols:
 *   func_021DE14C  0x021DE14C  arm  ov175
 */

typedef unsigned int u32;

extern int func_021DE14C(char **, int);

int func_021DEBF4(u32 ctx)
{
    u32 *p = *(u32 **)((char *)ctx + 8);

    if (p[0] == 0)
        return 4;
    if ((int)p[2] <= 0)
        return 0xd;
    if (p[1] == 0)
        return 0xc;
    if ((int)p[4] <= 0)
        return 6;
    if (p[3] == 0)
        return 5;
    return func_021DE14C((char **)p[3], p[4]);
}
