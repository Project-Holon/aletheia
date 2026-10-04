/*
 * function: func_021B3CFC
 * address:  0x021B3CFC
 * packet:   pkt_ov021_021B3CFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02020E60 0x02020E60 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 */
#include "../include/Obj00037.h"

extern unsigned func_02020E60(unsigned a, unsigned b);
typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned int   u32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);

void func_021B3CFC(char *w)
{
    ((struct Obj00037 *)w)->f1EC = (void *)func_0204AC18(((struct Obj00037 *)w)->f1F8, func_02020E60(1, 2), 0, 0x20, 0, 1, ((struct Obj00037 *)w)->f4);
    ((struct Obj00037 *)w)->f1F0 = (void *)func_0204A6C8(((struct Obj00037 *)w)->f1F8, func_02020E60(1, 1), 0, 0, ((struct Obj00037 *)w)->f4);
    ((struct Obj00037 *)w)->f1F4 = (void *)func_0204AF28(((struct Obj00037 *)w)->f1F8, 1, 0, ((struct Obj00037 *)w)->f4);
}
