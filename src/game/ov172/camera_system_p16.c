/*
 * file:     camera_system_p16.c
 * unit:     yes
 * function: func_021B6938, func_021B6944
 * address:  0x021B6938
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj01264.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

u16 func_021B6938(void *p);
u16 func_021B6944(void *p);


u16 func_021B6938(void *p)
{
    return (u16)(((struct Obj01264 *)p)->f36 - ((struct Obj01264 *)p)->f34);
}


/*
 * Width of the u16 pair at +0x38/+0x3a, zero extended.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021B6944(void *p)
{
    return (u16)(((struct Obj01264 *)p)->f3A - ((struct Obj01264 *)p)->f38);
}
