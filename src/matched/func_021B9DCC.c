/*
 * function: func_021B9DCC
 * address:  0x021B9DCC
 * packet:   pkt_021B9DCC
 * region:   ov181
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

void func_021B9DCC(char *p, u32 v)
{
    *(u8 *)(p + 0x2CC) |= (u8)v;
}
