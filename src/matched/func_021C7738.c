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
 *   func_020362DC  0x020362DC  arm
 */

extern int func_020362DC(void);

int func_021C7738(void)
{
    return (func_020362DC() & 0x400) ? 1 : 0;
}
