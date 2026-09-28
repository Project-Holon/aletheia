/*
 * function: func_021BF580
 * address:  0x021BF580
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed getter + passthrough, tail call to ARM func_02025774.
 *
 * symbols:
 *   func_02025774  0x02025774  thumb  

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02025774(u32, u32);
void func_021BF580(u8 *p, u32 i, u32 j)
{
    func_02025774(*(u32 *)(p + i * 4 + 0x3a8), j);
}

