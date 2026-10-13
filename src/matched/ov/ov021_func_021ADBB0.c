/*
 * function: FLDEFF_ENCOUNT_Update
 * address:  0x021ADBB0
 * packet:   pkt_ov021_021ADBB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FLDEFF_ENCOUNT_PlaySound  0x021ADC04  thumb  ov021
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 */
#include "../include/Obj05043.h"
#include "../include/Obj12797.h"
typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 FIELD_EFFECT_GetFieldMap(u8 *p);
extern int FIELDMAP_IsReady(void *a);
extern void FLDEFF_ENCOUNT_PlaySound(u8 *w, u8 *o);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);

void FLDEFF_ENCOUNT_Update(int a, u8 *w)
{
    int i;
    u8 *o = *(u8 * *)&((struct Obj05043 *)w)->f8;

    if (FIELDMAP_IsReady((void *)FIELD_EFFECT_GetFieldMap((u8 *)(((struct Obj12797 *)o)->f0))) != 0 && w[2] == 0) {
        FLDEFF_ENCOUNT_PlaySound(w, o);
        for (i = 0; i < o[0x88]; i++) {
            G3D_SYSTEM_LoopObjectAnimeFrame((void *)(*(int *)(o + 0x28 + w[0x1c] * 0x18)), (u16)i, 0x1000);
        }
    }
}
