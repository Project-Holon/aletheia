/*
 * function: FLDEFF_SPLASH_InitModelObj
 * address:  0x021C4C0C
 * packet:   pkt_ov021_021C4C0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FLDMMDL_GetCheckInfo  0x0216E1A4  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 */
#include "../include/Obj07561.h"

typedef unsigned short u16;

typedef struct { int a; int b; } S;

typedef unsigned int   u32;
extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern int FLDMMDL_GetCheckInfo(int a0, int a1);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void FIELD_EFFECT_SetObjectPos(int a, int *v);

void FLDEFF_SPLASH_InitModelObj(int a, int *b)
{
    int v[3];
    int *p = (int *)FIELD_EFFECT_GetObjectParam(a);

    *(S *)b = *(S *)p;
    FLDMMDL_GetCheckInfo(b[1], (int)(b + 2));
    FLDMMDL_GetPos((const struct Actor *)b[1], (struct VecFx32 *)v);
    v[2] += 0x8000;
    FIELD_EFFECT_SetObjectPos(a, v);
    ((struct Obj07561 *)b)->f10 = *(u16 *)(b[0] + 6);
}
