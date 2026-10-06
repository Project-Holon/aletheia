/*
 * unit:     no
 * function: func_02061B74
 * address:  0x02061B74
 * packet:   pkt_02061B2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj04778.h"

typedef unsigned short u16;
typedef unsigned char  u8;
extern int func_02061860(u8 *p);
typedef unsigned int   u32;
extern u32 func_02061840(u8 *p, u32 v);
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

