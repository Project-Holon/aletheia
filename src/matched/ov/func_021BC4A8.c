/*
 * function: func_021BC4A8
 * address:  0x021BC4A8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9B64  0x021B9B64  thumb  ov099
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *
 * Re-arms, then runs the setup and stamps 0xA7 when the guard answers true.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021B9B64(char *p);
extern int func_021BA928(void *p);
extern void func_021BA828(char *p);

int func_021BC4A8(char *p, int v)
{
    func_021B9B64(p + 0x274);

    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        *(u32 *)&((struct Obj00008 *)p)->f1CC = 0xA7;
    }

    return v;
}
