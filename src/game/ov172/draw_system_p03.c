/*
 * file:     draw_system_p03.c
 * unit:     yes
 * function: func_021B6E88, func_021B6EA8
 * address:  0x021B6E88
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B6EC4  0x021B6EC4  thumb  ov172
 *   func_021B6ECC  0x021B6ECC  thumb  ov172
 *   func_02082D44  0x02082D44  arm
 */
#include "../../matched/include/Obj04549.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern u8 *func_021B6EC4(void *p, int i);
extern void func_021B6ECC(void *o, u16 *c);
extern void  func_02082D44(void *a, void *b, int c);
void func_021B6E88(char *p, void *q);
void func_021B6EA8(void *p, u16 v);


/*
 * Copies one 8-byte entry in and steps the +4 cursor.
 *
 * Addresses are Black-image addresses.
 */
void func_021B6E88(char *p, void *q)
{
    func_02082D44(q, func_021B6EC4(p, ((struct Obj04549 *)p)->f4), 8);
    func_021B6ECC(p, (u16 *)(p + 4));
}

void func_021B6EA8(void *p, u16 v)
{
    u16 *h = (u16 *)p;
    h[2] = v;
    h[3] = v + 5;
    if (h[3] >= h[1])
        h[3] -= h[1];
}
