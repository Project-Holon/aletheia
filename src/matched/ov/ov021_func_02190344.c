/*
 * function: func_02190344
 * address:  0x02190344
 * packet:   pkt_ov021_02190344
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02194798  0x02194798  thumb
 */
#include "../include/Obj04205.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02194798(unsigned char *a);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);

void func_02190344(u8 *a)
{
    if (((struct Obj04205 *)a)->f15C != 0) {
        func_02194798(((struct Obj04205 *)a)->f15C);
        ((struct Obj04205 *)a)->f15C = 0;
    }
    if (((struct Obj04205 *)a)->f2 != 0xff) {
        func_02040DA8(((struct Obj04205 *)a)->f2, 1, 0);
        func_020403F4((u8)(((struct Obj04205 *)a)->f2));
        ((struct Obj04205 *)a)->f2 = 0xff;
    }
}
