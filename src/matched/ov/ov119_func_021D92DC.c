/*
 * function: func_021D92DC
 * address: 0x021D92DC
 * packet: pkt_ov119_021D92DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
void func_021D92DC(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == func_020399A8())
        (base + a)[0x11e0] = *src;
}
