/*
 * file:     ctvt_comm_p05.c
 * unit:     yes
 * function: func_021B80DC, func_021B80E4
 * address:  0x021B80DC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj24076.h"
#include "../../matched/include/Obj24077.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

void func_021B80DC(int unused, char *p, u32 v);
u32 func_021B80E4(int unused, char *p);

void func_021B80DC(int unused, char *p, u32 v)
{
    ((struct Obj24076 *)p)->f178 = v;
}


u32 func_021B80E4(int unused, char *p)
{
    return ((struct Obj24077 *)p)->f174;
}
