/*
 * function: func_021D916C
 * address: 0x021D916C
 * packet: pkt_ov119_021D916C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
void func_021D916C(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == func_020399A8())
        *(u32 *)(base + a * 4 + 0x5e4) = *src;
}
