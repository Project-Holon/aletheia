/*
 * function: WIH_SetGgid
 * address:  0x02178E1C
 * packet:   pkt_02178E1C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gWihWork  0x021797A8  data  a4
 */

typedef unsigned int u32;

void WIH_SetGgid(u32 v)
{
    *(u32 *)(*(u32 *)0x021797A8 + 8) = v;
}
