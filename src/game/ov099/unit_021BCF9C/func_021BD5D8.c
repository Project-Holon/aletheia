/*
 * function: func_021BD5D8
 * address:  0x021BD5D8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *
 * Early-returns the selector when the guard is false, else runs the setup and stamps 0x70.
 */
#include "../../../matched/include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_021BA928(void *p, int v);
extern void func_021BA828(char *p);

int func_021BD5D8(char *p, int v)
{
    if (func_021BA928(p, v) == 0) {
        return v;
    }

    func_021BA828(p);
    *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x70;
    return v;
}
