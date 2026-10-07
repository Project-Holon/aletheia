/*
 * file:     research_top_p03.c
 * unit:     yes
 * function: func_021BA144, func_021BA150
 * address:  0x021BA144
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
 *   func_021C0E4C  0x021C0E4C  thumb  ov217
 */
#include "../../matched/include/Obj25808.h"
#include "../../matched/include/Obj25809.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_021C0E4C(u32, u32);
void func_021BA144(u8 *a0, u32 a1);
void func_021BA150(void *p);


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 20)) to func_021C0E4C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA144(u8 *a0, u32 a1)
{
    func_021C0E4C((u32)(((struct Obj25808 *)a0)->f14), a1);
}


void func_021BA150(void *p)
{
    ((struct Obj25809 *)p)->f80 = 1;
}
