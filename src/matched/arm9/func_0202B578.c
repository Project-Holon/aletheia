/*
 * function: ISS_SYS_GetSwitchSys
 * address:  0x0202B578
 * packet:   pkt_0202B578
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned int u32;

u32 ISS_SYS_GetSwitchSys(u32 *p)
{
    return p[8];
}
