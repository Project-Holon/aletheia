/*
 * function: func_021E1374
 * address:  0x021E1374
 * packet:   pkt_021E1374
 * region:   ov183
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

void func_021E1374(char *p, int v)
{
    *(int *)(p + 0x22C) = v;
    *(int *)(p + 0x230) = 0;
    *(int *)(p + 0x234) = 0;
    *(int *)(p + 0x238) = 0;
}
