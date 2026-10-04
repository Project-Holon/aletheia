/*
 * function: func_021B8740
 * address: 0x021B8740
 * packet: pkt_ov172_021B8740
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_021B8740(int a, int b, u8 c, u32 d)
{
    struct { u32 w; u8 b; } buf;
    u32 entry;
    entry = (u32)func_020399A8();
    buf.b = c;
    buf.w = d;
    return func_0203D3F8(entry, 255, 0x2000, 8, (u32)&buf, 1, 0, 0);
}
