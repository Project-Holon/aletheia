/*
 * function: func_02155244
 * address:  0x02155244
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Feeds the inverted argument to func_02156690 and reports 1 when it accepts.
 *
 * symbols:
 *   func_02156690  0x02156690  thumb  ov009
 *   func_02156730  0x02156730  thumb  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_02155244(int x)
{
    int func_02156690(int);
    int func_02156730(void);
    int t;
    if (x == 0) t = 1;
    else t = 0;
    if (func_02156690(t)) {
        func_02156730();
        return 1;
    }
    return 0;
}
