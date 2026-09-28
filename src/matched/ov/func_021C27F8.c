/*
 * function: func_021C27F8
 * address:  0x021C27F8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203EFC8  0x0203EFC8  arm
 *
 * True when the arm9 comparison of the two blocks, 0x0E and 8 bytes in, answers 0.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_0203EFC8(void *a, void *b, int c);

BOOL func_021C27F8(char *p, char *q)
{
    if (func_0203EFC8(p + 0xE, q + 8, 6) == 0) {
        return 1;
    }

    return 0;
}
