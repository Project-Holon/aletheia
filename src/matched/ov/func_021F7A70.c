/*
 * function: func_021F7A70
 * address:  0x021F7A70
 * packet:   pkt_021F7A70
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9968  0x021F9968  thumb  ov135

 *
 * Hand the buffer at +0xde4 to the writer and stamp state 6.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*Fn)(void);
extern void func_021F9968(u8 *p, int mode);

int func_021F7A70(u8 *p)
{
    func_021F9968((u8 *)(*(u32 *)(p + 0xde4)), 0);
    *(u32 *)(p + 0x28) = 6;
    return 2;
}
