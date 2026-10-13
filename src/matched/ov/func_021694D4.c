/*
 * function: FIELD_G3D_MAP_Unload
 * address:  0x021694D4
 * packet:   pkt_021694D4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_G3D_MAP_ClearRenderObjModel  0x02169998  thumb  ov010
 *   FIELD_G3D_MAP_ClearModelRes  0x02169550  thumb  ov010
 *   FIELD_G3D_MAP_ClearTextureRes  0x02169568  thumb  ov010
 *   FIELD_G3D_MAP_ResetLoadState  0x0216959C  thumb  ov010
 *   FIELD_G3D_MAP_Reset  0x0216990C  thumb  ov010
 */
#include "../include/Obj00306.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FIELD_G3D_MAP_ClearRenderObjModel(int a0, int a1);
extern int FIELD_G3D_MAP_ClearModelRes();
extern int FIELD_G3D_MAP_ClearTextureRes();
extern int FIELD_G3D_MAP_ResetLoadState();
extern int FIELD_G3D_MAP_Reset();

void FIELD_G3D_MAP_Unload(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00306 *)t4)->f2C;
    a0 = FIELD_G3D_MAP_ClearRenderObjModel(a0, a1);
loc_021694DE:
a0 = t4 + 0;
    a0 = FIELD_G3D_MAP_ClearModelRes(a0);
loc_021694E4:
a0 = t4 + 0;
    a0 = FIELD_G3D_MAP_ClearTextureRes(a0);
loc_021694EA:
a0 = t4 + 0;
    a0 = FIELD_G3D_MAP_ResetLoadState(a0);
loc_021694F0:
a0 = t4 + 0;
    a0 = FIELD_G3D_MAP_Reset(a0);
loc_021694F6:
    return;}
