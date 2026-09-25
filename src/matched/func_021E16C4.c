/*
 * function: func_021E16C4
 * address:  0x021E16C4
 * packet:   pkt_021E16C4
 * region:   ov137
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

int func_021E16C4(char *p, int mask)
{
    return (*(u16 *)(*(char **)(p + 0xDC) + 0x40) & mask) != 0;
}
