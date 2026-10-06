/*
 * function: func_021EF894
 * address:  0x021EF894
 * packet:   pkt_ov093_021EF894
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF9B0  0x021EF9B0  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 */

extern char d_021F63F4;
typedef unsigned int   u32;
extern int func_021EF9B0(u32 *p);

int func_021EF894(void)
{
    return func_021EF9B0((u32 *)(&d_021F63F4));
}
