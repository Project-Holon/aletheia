/*
 * function: func_021769E0
 * address:  0x021769E0
 * packet:   pkt_ov009_021769E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GetResvDenyReasonString (dwc_match.o)
 *
 * symbols:
 *   g_021A21C8     0x021A21C8  data
 *   g_021A21E8     0x021A21E8  data
 *   g_021A2208     0x021A2208  data
 *   g_021A222C     0x021A222C  data
 *   g_021A224C     0x021A224C  data
 *   g_021A2280     0x021A2280  data
 *   g_021A22C4     0x021A22C4  data
 *   g_021A22F0     0x021A22F0  data
 *   g_021A2324     0x021A2324  data
 *   g_021A2340     0x021A2340  data
 */

extern char g_021A21C8[];
extern char g_021A21E8[];
extern char g_021A2208[];
extern char g_021A222C[];
extern char g_021A224C[];
extern char g_021A2280[];
extern char g_021A22C4[];
extern char g_021A22F0[];
extern char g_021A2324[];
extern char g_021A2340[];

char *func_021769E0(unsigned char denyReason)
{
    switch (denyReason) {
    case 0x10:
        return g_021A21C8;
    case 0x11:
        return g_021A21E8;
    case 0x12:
        return g_021A2208;
    case 0x13:
        return g_021A222C;
    case 0x14:
        return g_021A224C;
    case 0x15:
        return g_021A2280;
    case 0x16:
        return g_021A22C4;
    case 0x17:
        return g_021A22F0;
    case 0x18:
        return g_021A2324;
    default:
        return g_021A2340;
    }
}
