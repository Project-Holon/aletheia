/*
 * function: func_021FF0BC
 * address:  0x021FF0BC
 * packet:   pkt_021FF0BC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02202840  0x02202840  thumb  ov135

 * When the build query answers 0 and either probe is set, roll the state word over.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 func_02202840(u8 *p);
extern u32 func_020362DC(void);
extern u32 func_02035C60(void);

int func_021FF0BC(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (func_020362DC() != 0 || func_02035C60() != 0) {
            *(u32 *)(p + 0x28) = *(u32 *)(p + 0x2c);
        }
    }
    return 2;
}
