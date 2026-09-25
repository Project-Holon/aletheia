/*
 * function: func_021C5E14
 * address:  0x021C5E14
 * packet:   pkt_021C5E14
 * region:   ov127
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int func_021C5E14(unsigned int a, unsigned int b)
{
    int r;

    if (a <= 0x20) {
        r = 0;
        if (b > 0x20)
            r = 2;
    } else {
        r = 1;
        if (b > 0x20)
            r = 3;
    }
    return r;
}
