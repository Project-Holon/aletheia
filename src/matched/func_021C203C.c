/*
 * function: func_021C203C
 * address:  0x021C203C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the byte at index i of the 0x8CB table, then sets the byte at +0x8F1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

void func_021C203C(char *p, int i)
{
    *(u8 *)(p + i + 0x8CB) = 0;
    *(u8 *)(p + 0x8F1) = 1;
}
