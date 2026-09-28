/*
 * function: func_021B8CB0
 * address:  0x021B8CB0
 * packet:   pkt_ov093_021B8CB0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021B8CB0 { u32 f0; u32 mode; };

u8 func_021B8CB0(struct Unk021B8CB0 **p, u8 x)
{
    switch ((*p)->mode) {
    case 0:
        return x;
    case 3:
        return x;
    case 1:
        return (x + 2) & 3;
    case 2:
        return x;
    }
    return x;
}
