/*
 * function: func_021BDD60
 * address:  0x021BDD60
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fifteen-entry dispatch on a small selector: 0 through 6 answer 0, 7 through 14 answer 1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

int func_021BDD60(int x)
{
    switch (x) {
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        return 1;

    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    default:
        return 0;
    }
}
