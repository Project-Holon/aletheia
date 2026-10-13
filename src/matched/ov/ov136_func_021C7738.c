/*
 * function: func_021C7738
 * address:  0x021C7738
 * packet:   pkt_021C7738
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 */

typedef unsigned int u32;

extern u32 KEY_GetTrg(void);

int func_021C7738(void)
{
    return (KEY_GetTrg() & 0x400) ? 1 : 0;
}
