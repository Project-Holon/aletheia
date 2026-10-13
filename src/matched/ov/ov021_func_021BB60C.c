/*
 * function: FLDEFF_GYOE_UpdateHeldTask
 * address:  0x021BB60C
 * packet:   pkt_ov021_021BB60C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDEFF_GYOE_StepAnimation  0x021BB808  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V3;
typedef struct { u32 f0, f4, f8, fC; u16 f10[10]; u32 f24; } X;
extern int FLDMMDL_CheckCheckInfo(int a0, int a1);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *v);
struct Vec;
extern void FLDEFF_GYOE_StepAnimation(int *o, struct Vec *out);
extern void FIELD_EFFECT_SetObjectPos(u32 a, V3 *v);
void FLDEFF_GYOE_UpdateHeldTask(u32 a, X *x)
{
    V3 v;
    if (FLDMMDL_CheckCheckInfo(x->fC, (int)x->f10) == 0) {
        x->f24 = 1;
        return;
    }
    FLDMMDL_GetPos((const struct Actor *)x->fC, (struct VecFx32 *)&v);
    FLDEFF_GYOE_StepAnimation((int *)x, (struct Vec *)(&v));
    FIELD_EFFECT_SetObjectPos(a, &v);
}
