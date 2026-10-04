/*
 * function: func_021551DC
 * address:  0x021551DC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Null-pointer guard through func_02156690, then either func_02156730 or func_0215592C.
 *
 * symbols:
 *   func_02156690  0x02156690  thumb  ov009
 *   func_02156730  0x02156730  thumb  ov009
 *   func_0215592C  0x0215592C  thumb  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021551DC(void *p)
{
    int func_02156690(int);
    int func_02156730(void);
    int func_0215592C(int a);
    int t;
    if (p == 0) t = 1;
    else t = 0;
    if (func_02156690(t)) {
        func_02156730();
        return 1;
    }
    func_0215592C((int)p);
    return 1;
}
