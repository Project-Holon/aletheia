/*
 * function: func_021BD014
 * address:  0x021BD014
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *
 * Asks the arm9 predicate at 0x020362DC about the block; on a non-zero answer
 * stamps 0x6E in the byte at +0x1353 and selector 0x8A.  Returns the second
 * argument.  The predicate takes only the block.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u32 func_020362DC(void);

int func_021BD014(char *p, int v)
{
    if (func_020362DC() != 0) {
        *(u8 *)(p + 0x1353) = 0x6E;
        *(u32 *)(p + 0x1CC) = 0x8A;
    }
    return v;
}
