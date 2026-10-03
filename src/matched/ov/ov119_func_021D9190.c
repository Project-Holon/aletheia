/*
 * function: func_021D9190
 * address: 0x021D9190
 * packet: pkt_ov119_021D9190
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
extern u32 func_0203D1A4(void *);
void func_021D9190(u32 a, u32 b, u32 c, u8 *base, void *e)
{
    if (e == func_020399A8()) {
        if (a != func_0203D1A4(func_020399A8()))
            base[0x11fb] = base[0x11fb] & ~0xf;
    }
}
