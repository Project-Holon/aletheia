/*
 * function: func_021D8AF4
 * address:  0x021D8AF4
 * packet:   pkt_021D8AF4
 * region:   ov129
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

void func_021D8AF4(char *p, int v)
{
    *(int *)(p + 0x22C) = v;
    *(int *)(p + 0x230) = 0;
    *(int *)(p + 0x234) = 0;
    *(int *)(p + 0x238) = 0;
}
