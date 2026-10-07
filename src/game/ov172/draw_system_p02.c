/*
 * file:     draw_system_p02.c
 * unit:     yes
 * function: func_021B6C34, func_021B6C48
 * address:  0x021B6C34
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
 *   func_0203D7FC  0x0203D7FC  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj24067.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_0203D7FC(void *p);
extern u32 func_020307B0(void *p);
void func_021B6C34(char *p);
void func_021B6C48(u32 a);


void func_021B6C34(char *p)
{
    func_0203D7FC(((struct Obj24067 *)p)->f10);
    func_020307B0(p);
}


void func_021B6C48(u32 a)
{
}
