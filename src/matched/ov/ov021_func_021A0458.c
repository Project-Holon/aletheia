/*
 * function: FIELD_LIGHT_Main
 * address:  0x021A0458
 * packet:   pkt_ov021_021A0458
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_LIGHT_GetKeyframeSeconds  0x021A07F8  thumb  ov021
 *   FIELD_LIGHT_BeginBlendDefault  0x021A0974  thumb  ov021
 *   FIELD_LIGHT_StepBlend  0x021A0B14  thumb  ov021
 *   FIELD_LIGHT_IsBlending  0x021A0B34  thumb  ov021
 *   FIELD_LIGHT_EvalBlend  0x021A0B4C  thumb  ov021
 *   FIELD_LIGHT_FADE_Update  0x021A0C74  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01497.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern s32 FIELD_LIGHT_GetKeyframeSeconds(u16 a, void *b);
extern void FIELD_LIGHT_BeginBlendDefault(u32 a1, u32 a2, u32 a3);
extern void FIELD_LIGHT_StepBlend(void *a);
extern int FIELD_LIGHT_IsBlending(u32 a);
extern void FIELD_LIGHT_EvalBlend(const u8 *a, u8 *b);
extern s32 FIELD_LIGHT_FADE_Update(u16 *a, void *b, void *c, void *d);

void FIELD_LIGHT_Main(u8 *a, s32 b)
{
    s32 prev;
    s32 cur;
    s32 t;
    s32 wrapped;
    s32 i;
    u32 m;

    if (((struct Obj01497 *)a)->fC == 0)
        return;
    switch (((struct Obj01497 *)a)->f0) {
    case 0:
        cur = FIELD_LIGHT_GetKeyframeSeconds(((struct Obj01497 *)a)->f2, a + 0x10 + ((struct Obj01497 *)a)->f350 * 0x34);
        wrapped = 0;
        i = ((struct Obj01497 *)a)->f350 - 1;
        if (i < 0) {
            prev = 0;
            t = FIELD_LIGHT_GetKeyframeSeconds(((struct Obj01497 *)a)->f2, a + 0x10 + (*(s32 *)&((struct Obj01497 *)a)->fC - 1) * 0x34);
            if (t <= b) {
                prev = t;
                wrapped = 1;
                cur += 86400;
            }
        } else {
            prev = FIELD_LIGHT_GetKeyframeSeconds(((struct Obj01497 *)a)->f2, a + 0x10 + i * 0x34);
        }
        if ((prev > b || cur <= b) && wrapped == 0) {
            m = (*(u32 *)&((struct Obj01497 *)a)->f350 + 1) % ((struct Obj01497 *)a)->fC;
            *(u32 *)&((struct Obj01497 *)a)->f350 = m;
            FIELD_LIGHT_BeginBlendDefault((u32)(a + 0x390), (u32)(a + 0x356), (u32)(a + 0x10 + m * 0x34));
        }
        break;
    case 1:
        if (FIELD_LIGHT_FADE_Update((u16 *)(a + 0x484), a + 0x390, a + 0x356, a + 0x10 + ((struct Obj01497 *)a)->f350 * 0x34))
            ((struct Obj01497 *)a)->f0 = 0;
        break;
    }
    if (FIELD_LIGHT_IsBlending((u32)(a + 0x390))) {
        FIELD_LIGHT_StepBlend(a + 0x390);
        FIELD_LIGHT_EvalBlend(a + 0x390, a + 0x356);
        ((struct Obj01497 *)a)->f38C = 1;
    }
    ((struct Obj01497 *)a)->f48C = b;
}
