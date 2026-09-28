/*
 * function: func_020648B4
 * address:  0x020648B4
 * packet:   pkt_0206469C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02064648    0x02064648  arm
 *   func_020648E0    0x020648E0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02064648(u32 a);
extern u32 func_020648E0(u32 a);

int func_020648B4(u32 a, u32 b)
{
    u32 v;

    if (b == 1) {
        v = func_02064648(a) * 0x5c;
    } else {
        v = func_020648E0(a) << 7;
    }
    return v;
}
