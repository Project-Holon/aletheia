/*
 * function: func_021D6C2C
 * address:  0x021D6C2C
 * packet:   pkt_ov093_021D6C2C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D6C2C {
    u32 f0;
    u32 f4;
    u8 pad8[0x13];
    u8 lo : 6;
    u8 b6 : 1;
    u8 b7 : 1;
};

void func_021D6C2C(struct Unk021D6C2C *p)
{
    p->b6 = 0;
    p->f4 = 0;
}
