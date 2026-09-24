/*
 * function: func_021C207C
 * address:  0x021C207C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets the word at +0x8F4 and the byte at +0x8F1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

void func_021C207C(char *p)
{
    *(u32 *)(p + 0x8F4) = 1;
    *(u8 *)(p + 0x8F1) = 1;
}
