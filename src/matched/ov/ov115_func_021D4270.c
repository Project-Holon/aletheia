/*
 * function: func_021D4270
 * address:  0x021D4270
 * packet:   pkt_ov115_021D4270
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note: extent is 30 bytes (label gap said 56; the rest is data and two tiny leaves).
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern u32 func_020399A8(void);
extern u16 func_02039338(void);

void func_021D4270(u32 a, u32 b, u32 c, u8 *p, u32 id)
{
    if (id == func_020399A8() && a != func_02039338()) {
        *(u32 *)(p + 0x1c) = 1;
    }
}
