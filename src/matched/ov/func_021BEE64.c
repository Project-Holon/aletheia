/*
 * function: func_021BEE64
 * address:  0x021BEE64
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C23B8  0x021C23B8  thumb  ov099
 *   func_021C27D0  0x021C27D0  thumb  ov099
 *   func_021C27D8  0x021C27D8  thumb  ov099
 *
 * True when the two objects - the one at +0x08 of b and the one func_021C23B8
 * returns - agree under func_021C27D8 after both have been released through
 * func_021C27D0.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void *func_021C23B8(void *a, void *b);
extern int func_021C27D0(void *p);
extern int func_021C27D8(void *p);

BOOL func_021BEE64(void *a, char *b)
{
    void *x = *(void **)(b + 8);
    void *y = func_021C23B8(a, b);

    func_021C27D0(x);
    func_021C27D0(y);

    if (func_021C27D8(x) == func_021C27D8(y)) {
        return 1;
    }

    return 0;
}
