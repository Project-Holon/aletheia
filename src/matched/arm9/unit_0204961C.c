/*
 * unit:     yes
 * address:  0x0204961C
 * packet:   pkt_0204961C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_0204968C  0x0204968C  arm
 */
#include "../include/Obj17354.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;

u16 func_0204961C(void *obj)
{
    return ((struct Obj17354 *)obj)->f4E;
}

extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern u32 func_0204968C(void *buf, u32 a1, u32 a2, u32 a3, u32 unused);

u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6)
{
    u32 ret = func_0204A1BC((int)a0, (int)a1, a5, a6);
    return func_0204968C((void *)ret, (u32)a2, (u32)a3, a4, a5);
}
