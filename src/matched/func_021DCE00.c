/*
 * function: func_021DCE00
 * address:  0x021DCE00
 * packet:   pkt_021DCE00
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

int func_021DCE00(char *p, int i)
{
    return *(int *)(p + 0x50) + i * 0x594;
}
