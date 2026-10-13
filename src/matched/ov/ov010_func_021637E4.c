/*
 * function: FLDMMDL_MOVE_AttrEffectLongGrassStart
 * address:  0x021637E4
 * packet:   pkt_ov010_021637E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckMoveBitReflect  0x0216DC34  thumb  ov010
 *   FLDMMDL_MOVE_GetDirMapAttr  0x02163F40  thumb  ov010
 *   FLDMMDL_SetMoveBitReflect  0x0216DC18  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   func_021AB440  0x021AB440  thumb  ov021
 *   MAP_ATTR_IsIce  0x021AB358  thumb  ov021
 *   FLDEFF_REFLECT_SetMMdl  0x021BBFB8  thumb  ov021
 */
#include "../include/Obj00110.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern int FLDMMDL_CheckMoveBitReflect(void *a0);
typedef unsigned int   u32;
extern int FLDMMDL_MOVE_GetDirMapAttr(int a, int dir);
extern int FLDMMDL_SetMoveBitReflect(void *a0, int a1);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int func_021AB440();
extern int MAP_ATTR_IsIce(int x);
extern void FLDEFF_REFLECT_SetMMdl(u32 a, u32 b, u32 c, u32 d);

void FLDMMDL_MOVE_AttrEffectLongGrassStart(void *a, int q)
{
    int r4, r7, s;
    u8 *t = *(u8 * *)&((struct Obj00110 *)q)->f10;

    if (t[6] == 0) {
        return;
    }
    if (FLDMMDL_CheckMoveBitReflect((void *)a) != 0) {
        return;
    }
    r4 = -1;
    if (((struct Obj00110 *)q)->fE & 0x40) {
        r4 = *(int *)(q + 4);
    } else {
        r7 = FLDMMDL_MOVE_GetDirMapAttr((int)a, 1);
        if (MAP_ATTR_GetFlags(r7) & 0x40) {
            r4 = r7;
        }
    }
    if (r4 == -1) {
        return;
    }
    r7 = 1;
    r4 = MAP_ATTR_GetTerrainId(r4);
    s = (int)FLDMMDL_GetMmdlSys((void *)a);
    if (func_021AB440(r4) == 1 || MAP_ATTR_IsIce(r4) == 1) {
        r7 = 2;
    }
    FLDEFF_REFLECT_SetMMdl(s, (u32)a, ((struct Obj00110 *)q)->f14, r7);
    FLDMMDL_SetMoveBitReflect(a, 1);
}
