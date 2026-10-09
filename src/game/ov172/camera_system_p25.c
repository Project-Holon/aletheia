/*
 * file:     camera_system_p25.c
 * unit:     yes
 * function: func_021B6938, func_021B6944, func_021B6950
 * address:  0x021B6938
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
 *   func_02085D3C 0x02085D3C arm
 *   func_021B6974 0x021B6974 arm ov172
 *   func_021B68A0 0x021B68A0 thumb ov172
 */
#include "../../matched/include/Obj01264.h"
#include "../../matched/include/Obj01264.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern int func_02085D3C(void);
extern void func_021B6974(int, int, int);
extern void func_021B68A0(char *);
u16 func_021B6938(void *p);
u16 func_021B6944(void *p);
void func_021B6950(char *p, int v);



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


void func_021B6950(char *p, int v)
{
    if (func_02085D3C() == 1) func_021B6974(3, 3, v);
    ((struct Obj01264 *)p)->f30 = v;
    func_021B68A0(p);
}
