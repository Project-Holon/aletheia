/*
 * function: FLDEFF_SPLASH_UpdateModelObj
 * address:  0x021C4C54
 * packet:   pkt_ov021_021C4C54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FLDMMDL_CheckMoveBitSplash  0x0216DBE8  thumb  ov010
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_G3DOBJ_GetObjectTrans  0x021C6658  thumb  ov021
 *   FIELD_G3DOBJ_GetObjectRedrawFlag  0x021C6844  thumb  ov021
 *   FIELD_G3DOBJ_LoopAnimeFrame  0x021C66EC  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectRedrawFlag  0x021C6828  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 */
#include "../include/Obj06076.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern int FLDMMDL_CheckCheckInfo(int a0, int a1);
extern void FIELD_EFFECT_DeleteObject(int a);
extern int FLDMMDL_CheckMoveBitSplash(void *a0);
typedef unsigned char  u8;
extern u32 FIELD_EFFECT_GetFieldMapData(u8 *p);
extern int FIELD_G3DOBJ_GetObjectTrans(u32 a, u32 b);
extern int FIELD_G3DOBJ_GetObjectRedrawFlag(int a, int b);
extern int FIELD_G3DOBJ_LoopAnimeFrame(u32 *a, int idx, int v);
extern void FIELD_G3DOBJ_SetObjectRedrawFlag(int a, int b, int c);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void FIELD_EFFECT_SetObjectPos(int a, int *v);

void FLDEFF_SPLASH_UpdateModelObj(int a, int *b)
{
    int v[3];
    int h;
    int r;

    if (FLDMMDL_CheckCheckInfo(b[1], (int)(b + 2)) == 0) {
        FIELD_EFFECT_DeleteObject(a);
        return;
    }
    if (FLDMMDL_CheckMoveBitSplash((void *)b[1]) == 0) {
        FIELD_EFFECT_DeleteObject(a);
        return;
    }
    h = ((struct Obj06076 *)b)->f10;
    r = FIELD_EFFECT_GetFieldMapData((u8 *)(*(int *)b[0]));
    FIELD_G3DOBJ_GetObjectTrans(r, h);
    if (FIELD_G3DOBJ_GetObjectRedrawFlag(r, h) == 0) {
        FIELD_G3DOBJ_LoopAnimeFrame((u32 *)r, h, 0x1000);
        FIELD_G3DOBJ_SetObjectRedrawFlag(r, h, 1);
    }
    FLDMMDL_GetPos((const struct Actor *)b[1], (struct VecFx32 *)v);
    v[2] += 0x8000;
    FIELD_EFFECT_SetObjectPos(a, v);
}
