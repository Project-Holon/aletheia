/*
 * function: func_021D4808
 * address: 0x021D4808
 * packet: pkt_ov093_021D4808
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_02008468 0x02008468 thumb
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned int u32;
extern u32 *d_021F3B88;
extern int func_02008468(void);
extern u32 func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
int func_021D4808(u32 a)
{
    u32 r = func_02008468();
    return func_0203D3F8(*d_021F3B88, 255, 0x105, r, a, 0, 1, 1);
}
