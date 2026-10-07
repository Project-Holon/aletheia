/*
 * file:     palette_anime_p20.c
 * unit:     yes
 * function: func_021C2D68, func_021C2D88
 * address:  0x021C2D68
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
 *   func_02021F64  0x02021F64  thumb
 *   func_02082D44  0x02082D44  arm
 */
#include "../../matched/include/Obj00115.h"
#include "../../matched/include/Obj10968.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

extern void func_02021F64(u32 a, u32 b, u32 c, u32 d, u32 e);
extern int func_02082D44(int, int, int);
void func_021C2D68(void *p);
int func_021C2D88(char *p);


void func_021C2D68(void *p)
{
    func_02021F64(*(u32 *)&((struct Obj00115 *)p)->fC, *(u32 *)&((struct Obj00115 *)p)->f8, ((struct Obj00115 *)p)->f10, 7, ((struct Obj00115 *)p)->f12);
    (((struct Obj00115 *)p)->f1C)++;
}


int func_021C2D88(char *p)
{
    return func_02082D44(((struct Obj10968 *)p)->fC, ((struct Obj10968 *)p)->f8,
                         ((struct Obj10968 *)p)->f10 << 1);
}
