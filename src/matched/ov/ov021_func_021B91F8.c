/*
 * function: func_021B91F8
 * address:  0x021B91F8
 * packet:   pkt_ov021_021B91F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021B8848  0x021B8848  thumb  ov021
 *   func_021B8894  0x021B8894  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00454.h"
#include "../include/Obj20083.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct { u32 a, b, c; } V3;
typedef void (*Fn)(void *, void *);

u32 *func_021B8848(void *a, u32 b);
Fn func_021B8894(void *a, u32 b);

void func_021B91F8(u8 *p, V3 *out)
{
    Fn f;

    if (((struct Obj00454 *)p)->f0 == 0) {
        *out = *(V3 *)(*(u8 * *)&((struct Obj00454 *)p)->f4 + 0x30);
        return;
    }
    if (((struct Obj00454 *)p)->f0 == 1) {
        u32 *r = func_021B8848(((struct Obj00454 *)p)->f24, ((struct Obj20083 *)(*(u8 * *)&((struct Obj00454 *)p)->f4))->fC);
        f = func_021B8894(((struct Obj00454 *)p)->f24, *r);
        if (f)
            f(p, out);
    }
}
