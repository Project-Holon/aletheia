/*
 * function: func_021C27C0
 * address:  0x021C27C0
 * packet:   pkt_021C27C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02043658  0x02043658  arm
 */

typedef unsigned int u32;

u32 func_02043658(char *p);

void func_021C27C0(char *p)
{
    *(u32 *)(p + 0x68) = func_02043658(p);
}
