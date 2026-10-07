/*
 * file:     camera_system_p17.c
 * unit:     yes
 * function: func_021B69BC, func_021B69D0
 * address:  0x021B69BC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj08254.h"
#include "../../matched/include/Obj24063.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

void func_021B69BC(void *p, u32 v);
void func_021B69D0(void *p);


void func_021B69BC(void *p, u32 v)
{
    if (((struct Obj08254 *)p)->f2C == v) {
        return;
    }
    if (((struct Obj08254 *)p)->f20 != 0) {
        return;
    }
    ((struct Obj08254 *)p)->f2C = v;
    ((struct Obj08254 *)p)->f20 = 1;
}


void func_021B69D0(void *p)
{
    ((struct Obj24063 *)p)->f44 = 1;
}
