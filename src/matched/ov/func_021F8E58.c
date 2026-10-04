/*
 * function: func_021F8E58
 * address:  0x021F8E58
 * packet:   pkt_021F8E58
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4EC0  0x021F4EC0  thumb  ov135

 * While the +0x12f4 word is clear, publish +0x10dc, reset the mode pair and latch state 1.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_020307B0(void *p);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);

int func_021F8E58(u8 *p)
{
    if (*(u32 *)(p + 0x12f4) == 0) {
        func_020307B0((void *)(*(u32 *)(p + 0x10dc)));
        func_021F4EC0(p, 0, 0);
        *(u32 *)(p + 0x28) = 1;
    }
    return 2;
}
