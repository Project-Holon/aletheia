/*
 * function: func_021D90E8
 * address: 0x021D90E8
 * packet: pkt_ov119_021D90E8
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
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
void func_021D90E8(u32 a, u32 b, u32 c, u8 *base, void *e)
{
    if (e == func_020399A8()) {
        if (c == func_0203D1A4((struct Link *)func_020399A8()))
            *(u32 *)(base + b * 4 + 0xff0) = a;
        else
            *(u32 *)(base + b * 4 + 0xffc) = a;
    }
}
