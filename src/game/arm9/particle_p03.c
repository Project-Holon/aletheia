/*
 * file:     particle_p03.c
 * unit:     yes
 * function: func_02050304, func_02050330
 * address:  0x02050304
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj08868.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

int func_02050304(int a0, int a1);
u16 func_02050330(u8 *p, int i);


int func_02050304(int a0, int a1){ int t0 = func_02050088((int)(*(int *)&((struct Obj08868 *)((char *)(a0)))->fC + (a1 << 3))); int t1 = func_0203422C((int)((struct Obj08868 *)((char *)(a0)))->f14, (int)a1, (int)1); return t1; }


u16 func_02050330(u8 *p, int i)
{
    return *(u16 *)(*(u8 * *)&((struct Obj08868 *)p)->fC + i * 8);
}
