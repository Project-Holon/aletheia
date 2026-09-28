/*
 * function: func_021F8A18
 * address:  0x021F8A18
 * packet:   pkt_021F8A18
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F8A40  0x021F8A40  thumb  ov135
 *   func_021F5074  0x021F5074  thumb  ov135
 *   func_021F4EC8  0x021F4EC8  thumb  ov135

 * Run the three teardown steps, then report 4 while the +0x10 handle is gone.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void func_021F8A40(u8 *p);
extern void func_021F5074(u8 *p);
extern void func_021F4EC8(u8 *p);

u32 func_021F8A18(u8 *p)
{
    func_021F8A40(p);
    func_021F5074(p);
    func_021F4EC8(p);
    if (*(u32 *)(p + 0x10) == 0) {
        return 4;
    }
    return 0;
}
