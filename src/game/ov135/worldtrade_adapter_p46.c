/*
 * file:     worldtrade_adapter_p46.c
 * unit:     yes
 * function: func_02202840, func_02202858
 * address:  0x02202840
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022028C8 0x022028C8 thumb ov135
 */
#include "../../matched/include/Obj18615.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

extern u32 func_0201CE30(void *p);
extern u32 func_022028C8(void *,u8,void *,u32,u32,u32,u16,void *);
u32 func_02202840(u8 *p);
u32 func_02202858(void *p,u8 b,void *s,u32 x,u32 y,void *out);


/*
 * Non-zero unless the +0x10 handle is absent or the query answers 2.
 */
u32 func_02202840(u8 *p)
{
    u32 r;
    u32 x;

    r = 0;
    x = ((struct Obj18615 *)p)->f10;
    if (x != 0 && func_0201CE30((void *)x) != 2) {
        r = 1;
    }
    return r;
}

u32 func_02202858(void *p,u8 b,void *s,u32 x,u32 y,void *out) { return func_022028C8(p,b,s,x,y,0,0x44f,out); }
