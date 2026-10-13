/*
 * function: FLDEFF_BTRAIN_Draw
 * address:  0x021D034C
 * packet:   pkt_ov021_021D034C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sBtrainDrawStatus  0x021DB8F0  data  ov021  a4
 *   func_0207ADC4  0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12997.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct V {
    u32 w[15];
} V;

extern const V sBtrainDrawStatus;
extern void func_0207ADC4(void *a);
extern void FIELD_EFFECT_GetObjectPos(u32 a, V *v);
struct Arg;
extern int G3D_SYSTEM_DrawObjectCulling(void *a0, struct Arg *a1);

void FLDEFF_BTRAIN_Draw(u32 a, u8 *b)
{
    V v;

    if (b[1] == 0) {
        v = sBtrainDrawStatus;
        func_0207ADC4(&v.w[6]);
        FIELD_EFFECT_GetObjectPos(a, &v);
        G3D_SYSTEM_DrawObjectCulling((void *)(((struct Obj12997 *)b)->fC), (struct Arg *)(&v));
    }
}
