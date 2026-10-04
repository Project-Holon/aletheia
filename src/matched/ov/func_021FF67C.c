/*
 * function: func_021FF67C
 * address:  0x021FF67C
 * packet:   pkt_021FF67C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F5074  0x021F5074  thumb  ov135
 *   func_021F4EC8  0x021F4EC8  thumb  ov135

 * Publish the +0xf byte of the +0x10dc object as the u16 at +0xc6, then tear down.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void func_020307B0(void *p);
extern void func_021F5074(u8 *p);
extern void func_021F4EC8(u8 *p);

u32 func_021FF67C(u8 *p)
{
    u32 q = *(u32 *)(p + 0x10dc);

    *(u16 *)(p + 0xc6) = *(u8 *)(q + 0xf);
    func_020307B0((void *)q);
    func_021F5074(p);
    func_021F4EC8(p);
    return 0;
}
