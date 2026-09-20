/*
 * function: func_020113F0
 * address:  0x020113F0
 * packet:   pkt_020113F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O1
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern const u8 lbl_0209DF24[];

u8 func_020113F0(int a, const u8 *b)
{
    int offset = a * 0x18;
    return b[(u32)lbl_0209DF24 + offset];
}
