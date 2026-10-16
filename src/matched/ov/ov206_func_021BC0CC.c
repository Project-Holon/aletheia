/*
 * function: ZUKAN_INFO_GetCellAnimMode
 * address:  0x021BC0CC
 * packet:   pkt_021BC0CC
 * region:   ov206
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int ZUKAN_INFO_GetCellAnimMode(int v)
{
    if (v <= 0x1ED)
        return 1;
    else
        return 3;
}
