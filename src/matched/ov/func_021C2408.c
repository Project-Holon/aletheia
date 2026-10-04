/*
 * function: func_021C2408
 * address:  0x021C2408
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021B98F8  0x021B98F8  thumb  ov099
 *
 * When the state word at +0x9B4 is 1, clears it and tears down the two sub-objects.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021BA8EC(char *p);
extern void func_021B98F8(char *p, int b);

void func_021C2408(char *p)
{
    if (((struct Obj00008 *)p)->f9B4 != 1) {
        return;
    }

    ((struct Obj00008 *)p)->f9B4 = 0;
    func_021BA8EC(p);
    func_021B98F8(p + 0x274, 0);
    ((struct Obj00008 *)p)->f135C = 0;
}
