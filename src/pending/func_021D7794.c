/*
 * function: func_021D7794
 * address:  0x021D7794
 * packet:   pkt_021D7794
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   func_021D7794 0x021D7794 arm
 *   g_021D77A8    0x021D77A8 data
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void *g_021D77A8;

void func_021D7794(u32 index, u8 val)
{
    u8 *ptr = (u8 *)g_021D77A8;
    ptr += index << 6;
    ptr[0x38] = val;
}
