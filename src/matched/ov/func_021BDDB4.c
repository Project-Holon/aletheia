/*
 * function: func_021BDDB4
 * address:  0x021BDDB4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BDD60  0x021BDD60  thumb  ov099
 *
 * True when the arm9 predicate accepts b and the selector is 4.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_021BDD60(int x);

BOOL func_021BDDB4(int a, void *b)
{
    if (func_021BDD60((int)b) != 0 && a == 4) {
        return 1;
    }

    return 0;
}
