/*
 * function: FIELD_RAIL_ProbeStep
 * address:  0x021B9368
 * packet:   pkt_ov021_021B9368
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_RAIL_WORK_SetLocation  0x021B7EE4  thumb  ov021
 *   FIELD_RAIL_WORK_StartStep  0x021B80E0  thumb  ov021
 *   FIELD_RAIL_WORK_UpdateStep  0x021B810C  thumb  ov021
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb  ov021
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   FIELD_RAIL_WORK_IsLocationValid  0x021B7DE0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03136.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_RAIL_WORK_SetLocation(u32 a, u32 b, u32 c, u32 d);
void FIELD_RAIL_WORK_StartStep(u32 a, u32 b, u32 c);
struct Sub;
void FIELD_RAIL_WORK_UpdateStep(struct Sub *o);
void FIELD_RAIL_WORK_GetPos(u32 a, u32 b);
typedef signed int     s32;
s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);
int FIELD_RAIL_WORK_IsLocationValid(u32 a, u32 b);

int FIELD_RAIL_ProbeStep(u8 *p, u32 a1, u32 a2, int a3, u32 a5)
{
    int i;

    FIELD_RAIL_WORK_SetLocation(((struct Obj03136 *)p)->f1C, a1, a2, a3);
    FIELD_RAIL_WORK_StartStep(((struct Obj03136 *)p)->f1C, 4, a2);
    FIELD_RAIL_WORK_UpdateStep((struct Sub *)(((struct Obj03136 *)p)->f1C));
    FIELD_RAIL_WORK_StartStep(((struct Obj03136 *)p)->f1C, 0, a2);
    for (i = 0; i < 16; i++) {
        if (a3 == i)
            FIELD_RAIL_WORK_GetPos(((struct Obj03136 *)p)->f1C, a5);
        FIELD_RAIL_WORK_UpdateStep((struct Sub *)(((struct Obj03136 *)p)->f1C));
    }
    if (GF_STANDARD_CompareBytes((void *)a1, (void *)(((struct Obj03136 *)p)->f1C + 0x5c), 8) == 0)
        return 0;
    return FIELD_RAIL_WORK_IsLocationValid(((struct Obj03136 *)p)->f1C, ((struct Obj03136 *)p)->f1C + 0x5c);
}
