/*
 * function: func_021BC6DC
 * address:  0x021BC6DC
 * packet:   pkt_ov110_021BC6DC
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * ov110 copy of the getter (`40 6c 70 47` = ldr r0,[r0,#0x44]; bx lr).
 * Note the ov217 entry at the same address is a different function
 * (u8 at +0x30), so a region-qualified entry is required here.
 */

unsigned int func_021BC6DC(void *p)
{
    return *(unsigned int *)((char *)p + 0x44);
}
