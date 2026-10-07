/*
 * file:     research_top_p18.c
 * unit:     yes
 * function: func_021BE4A4, func_021BE4CC, func_021BE4DC
 * address:  0x021BE4A4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C0E54  0x021C0E54  thumb  ov217
 *   func_021C0E64  0x021C0E64  thumb  ov217
 */
#include "../../matched/include/Obj00021.h"
#include "../../matched/include/Obj25905.h"

struct Ring;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern u32 func_021C0E54(struct Ring *r);
extern u32 func_021C0E64();
void func_021BE4A4(u32 a0);
void func_021BE4CC(void *p, u32 v);
u32 func_021BE4DC(void *p);

void func_021BE4A4(u32 a0)
{
    if (((struct Obj00021 *)(((u8*)a0)))->f3DC != 0) {
    if (func_021C0E64(((struct Obj00021 *)(((u8*)a0)))->f1C) == 0) {
    func_021BE4CC((void *)a0, func_021C0E54((struct Ring *)(((struct Obj00021 *)(((u8*)a0)))->f1C)));
    }
    }
}


/*
 * Set +0x20, clear +0x24, +0x28 and +0x3dc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE4CC(void *p, u32 v)
{
    ((struct Obj00021 *)p)->f20 = v;
    ((struct Obj00021 *)p)->f24 = 0;
    ((struct Obj00021 *)p)->f28 = 0;
    ((struct Obj00021 *)p)->f3DC = 0;
}


u32 func_021BE4DC(void *p)
{
    return ((struct Obj25905 *)p)->f24;
}
