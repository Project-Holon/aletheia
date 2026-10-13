/*
 * function: func_021A150C
 * address:  0x021A150C
 * packet:   pkt_ov021_021A150C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   REPORT_UpdateWindows  0x021EFFB4  thumb  ov034
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void REPORT_UpdateWindows(int *p);

void func_021A150C(u32 *p)
{
    REPORT_UpdateWindows((int *)p[8]);
}
