/*
 * function: func_021EF884
 * address:  0x021EF884
 * packet:   pkt_ov093_021EF884
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF9A8  0x021EF9A8  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 */

extern char d_021F63F4;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 func_021EF9A8(u32 *p);

int func_021EF884(void)
{
    return func_021EF9A8((u32 *)(&d_021F63F4));
}
