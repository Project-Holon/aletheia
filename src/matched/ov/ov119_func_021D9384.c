/*
 * function: func_021D9384
 * address: 0x021D9384
 * packet: pkt_ov119_021D9384
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020399A8(void);
extern u16 func_02039338(void);
void func_021D9384(u32 a, u32 b, short *src, u8 *base, void *e)
{
    if (e == func_020399A8()) {
        if (a != func_02039338())
            *(short *)(base + 0x107e) = *src;
    }
}
