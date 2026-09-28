/*
 * function: func_021C1A44
 * address:  0x021C1A44
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * True when the word 0x8C8 bytes into the block is set.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

BOOL func_021C1A44(char *p)
{
    if (*(u32 *)(p + 0x8C8) != 0) {
        return 1;
    }

    return 0;
}
