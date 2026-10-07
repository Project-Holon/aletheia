/*
 * file:     field_wfbc_p17.c
 * unit:     yes
 * function: func_0219499C, func_02194A00
 * address:  0x0219499C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02194A94  0x02194A94  thumb  ov021
 *   func_02195E54  0x02195E54  thumb  ov021
 */
#include "../../matched/include/Obj02376.h"
#include "../../matched/include/Obj09486.h"

struct Rec3;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 func_02194A94(u32 a, u32 b, u32 c, u32 d, u8 e);
extern void func_02195E54(u32 a, u32 b, u8 c, u32 d);
void func_0219499C(u8 *p, int i, u32 b, u32 c);
u32 func_02194A00(u32 a, u8 b, u8 c, u8 d, u8 e, u32 f);


/*
 * Addresses are Black-image addresses.
 */
void func_0219499C(u8 *p, int i, u32 b, u32 c)
{
    u8 *e;

    e = p + 0x18 + i * 100;
    if (((struct Obj02376 *)e)->f8 != 0) {
        func_0201CE48((struct Rec3 *)(((struct Obj02376 *)e)->f8));
        ((struct Obj02376 *)e)->f8 = 0;
    }
    if (b != 0) {
        ((struct Obj02376 *)e)->f60 = c;
        ((struct Obj02376 *)e)->f14 = b;
        ((struct Obj02376 *)e)->f8 = func_0201CCE4(((struct Obj02376 *)e)->fC, e[0x5C], e[0x5D], ((struct Obj02376 *)e)->f14,
                                        ((struct Obj09486 *)p)->f8, c, ((struct Obj09486 *)p)->fC98, 0, ((struct Obj09486 *)p)->f0, 15);
        ((struct Obj02376 *)e)->f0 = 4;
    }
}


u32 func_02194A00(u32 a, u8 b, u8 c, u8 d, u8 e, u32 f)
{
    u32 r;

    r = func_02194A94(a, b, c, d, e);
    func_02195E54(a, r, f, 0);
    return r;
}
