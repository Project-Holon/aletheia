/*
 * function: FLDEFF_ENCOUNT_DrawSlotObject
 * address:  0x021ADC6C
 * packet:   pkt_ov021_021ADC6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207ADC4  0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   sEncounterDrawSlotStatus     0x021D9254  data  a4
 */
#include "../include/Obj09607.h"

typedef unsigned char u8;

typedef struct T { int w[15]; } T;

extern T sEncounterDrawSlotStatus;

extern void func_0207ADC4(int *m);
extern void FIELD_EFFECT_GetObjectPos(int a, T *t);
struct Arg;
extern int G3D_SYSTEM_DrawObjectCulling(void *a0, struct Arg *a1);

void FLDEFF_ENCOUNT_DrawSlotObject(int a, u8 *b)
{
    T t = sEncounterDrawSlotStatus;
    int c = ((struct Obj09607 *)b)->f8;

    if (b[3] == 0) {
        func_0207ADC4(&t.w[6]);
        FIELD_EFFECT_GetObjectPos(a, &t);
        G3D_SYSTEM_DrawObjectCulling((void *)(*(int *)(c + b[0x1c] * 0x18 + 0x28)), (struct Arg *)(&t));
    }
}
