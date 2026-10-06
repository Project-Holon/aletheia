/*
 * file:     unit_02061B2C_p01.c
 * unit:     yes
 * function: func_02061B5C, func_02061B74
 * address:  0x02061B5C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj07006.h"
#include "../../matched/include/Obj04778.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern int func_02061860(u8 *p);
extern u32 func_02061840(u8 *p, u32 v);
void func_02061B5C(u8 *p);
int func_02061B74(char *p);


/*
 * Clears the cursor fields.  No relocations; pure.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061B5C.c \
 *       --func func_02061B5C --addr 0x02061B5C --arm --cc 1.1p1
 */
void func_02061B5C(u8 *p)
{
    ((struct Obj07006 *)p)->fA = 0;
    ((struct Obj07006 *)p)->f8 = 0;
    ((struct Obj07006 *)p)->fC = 0;
    ((struct Obj07006 *)p)->f10 = 0;
}

int func_02061B74(char *p)
{
    int v;
    if (func_02061860((u8 *)p))
        return 0;
    v = func_02061840((u8 *)p, ((struct Obj04778 *)p)->fA);
    *(volatile u16 *)&((struct Obj04778 *)p)->fA = (u16)v;
    *(volatile u16 *)&((struct Obj04778 *)p)->fC = (u16)(*(volatile u16 *)&((struct Obj04778 *)p)->fC + 1);
    return 1;
}
