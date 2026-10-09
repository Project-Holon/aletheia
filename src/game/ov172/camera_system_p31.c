/*
 * file:     camera_system_p31.c
 * unit:     yes
 * function: func_021B69BC, func_021B69D0, func_021B69D8, func_021B69E0, func_021B69F0
 * address:  0x021B69BC
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
 *   d_021C88E4 0x021C88E4 data a4 ov172
 *   g_021C88E4  0x021C88E4  data  ov172
 */
#include "../../matched/include/Obj08254.h"
#include "../../matched/include/Obj24063.h"
#include "../../matched/include/Obj24064.h"
#include "../../matched/include/Obj14294.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct D021C88E4 {
    u8 pad0[4];
    u16 h4;
    u8 b6;
};

void func_021B69BC(void *p, u32 v);
void func_021B69D0(void *p);
void func_021B69D8(void *p);
void func_021B69E0(void);
void func_021B69F0(void);
extern struct D021C88E4 d_021C88E4;



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



void func_021B69D8(void *p)
{
    ((struct Obj24064 *)p)->f44 = 4;
}



/*
 * Clear the halfword at +4 and the byte at +6 of the ov172 state block. Filed
 * as the call witness for ov172 func_021B97AC.
 */
void func_021B69E0(void)
{
    d_021C88E4.h4 = 0;
    d_021C88E4.b6 = 0;
}



/*
 * Clear the 3-byte counter at g_021C88E4.
 *
 * Addresses are Black-image addresses.
 */
void func_021B69F0(void)
{
    u8 *p = (u8 *)0x021C88E4;
    ((struct Obj14294 *)p)->f0 = 0;
    ((struct Obj14294 *)p)->f2 = 0;
}
