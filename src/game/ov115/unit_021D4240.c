/*
 * file:     unit_021D4240.c
 * unit:     yes
 * function: func_021D4240, func_021D426C, func_021D4270
 * address:  0x021D4240
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 */
#include "../../matched/include/Obj22580.h"
#include "../../matched/include/Obj22581.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern u32 func_020399A8(void);
extern u16 func_02039338(void);
int func_021D4240(u8 *p);
void func_021D426C(u8 *p, u32 v);
void func_021D4270(u32 a, u32 b, u32 c, u8 *p, u32 id);

int func_021D4240(u8 *p) { if(func_020362DC()&3) return 1; if(*(int *)(((struct Obj22580 *)p)->f40+4) && func_02035C60()) return 1; return 0; }


void func_021D426C(u8 *p, u32 v) { ((struct Obj22581 *)p)->f0 = v; }


void func_021D4270(u32 a, u32 b, u32 c, u8 *p, u32 id)
{
    if (id == func_020399A8() && a != func_02039338()) {
        *(u32 *)(p + 0x1c) = 1;
    }
}
