/*
 * function: func_021E1974
 * address:  0x021E1974
 * packet:   pkt_021E1974
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

int func_021E1974(char *p)
{
    return *(u16 *)(*(char **)(p + 0xDC) + 0x48) != 0;
}
