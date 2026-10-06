/*
 * function: func_02174BB8
 * address: 0x02174BB8
 * packet: pkt_ov012_02174BB8
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
u32 func_02174BB8(u32 a, u32 b)
{
    u32 v = 0;
    if (b != 1) v = 255;
    return func_0203D3F8((u32)func_020399A8(),(u8)v,0x1501,44,a,1,0,1);
}
