/*
 * function: func_021BA95C
 * address: 0x021BA95C
 * packet: pkt_ov213_021BA95C
 * region: ov213
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA9AC 0x021BA9AC thumb ov213
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   d_021BB0F8 0x021BB0F8 data a4
 * width: 477A4 index u16: original narrows at 021BA994-021BA998.
 */
#include "../include/Obj02551.h"
typedef unsigned short u16;
typedef struct Util Util;
typedef struct { void *resTbl; u16 resCount; void *objTbl; u16 objCount; } Setup;
struct G3dSys;
extern const Setup d_021BB0F8[];
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021BA9AC(char *p);
extern u16 G3D_UTIL_AddUnit(Util *util, const Setup *setup);
extern u32 func_02048A18(u8 *a0, int i);
extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
void func_021BA95C(unsigned char *p, int index)
{
    int *object;
    int i, count;
    if (p[15]) func_021BA9AC((char *)p);
    ((struct Obj02551 *)p)->fC=G3D_UTIL_AddUnit(*(Util * *)&((struct Obj02551 *)p)->f8, &d_021BB0F8[index]);
    p[15]=1;
    object=(int *)func_02048A18((u8 *)(*(Util * *)&((struct Obj02551 *)p)->f8), ((struct Obj02551 *)p)->fC);
    count=G3D_SYSTEM_GetObjectAnimeCount(object);
    for(i=0;i<count;i++) G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)object,(u16)i);
}
