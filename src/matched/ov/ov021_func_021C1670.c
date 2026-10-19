/*
 * function: FIELD_PLAYER_GRID_EVENT_JumpUpWaitEffect
 * address:  0x021C1670
 * packet:   pkt_ov021_021C1670
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Finishes the pending effect at +0x48 once it reports done.
 *
 * symbols:
 *   FLDEFF_NAMIPOKE_SPLASH_IsFinished  0x021AD5CC  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FIELD_EFFECT_FreeResource  0x021ABE64  thumb  ov021
 *   FIELD_PLAYER_SetGridHopLanded  0x021A35A0  thumb  ov021
 */
#include "../include/Obj04271.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDEFF_NAMIPOKE_SPLASH_IsFinished(u32 a);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern void FIELD_EFFECT_DeleteObject(u32 a);
extern void FIELD_EFFECT_FreeResource(u32 a, int b);
extern void FIELD_PLAYER_SetGridHopLanded(u32 *p, int a);

int FIELD_PLAYER_GRID_EVENT_JumpUpWaitEffect(u8 *p)
{
    u32 o;

    if (((struct Obj04271 *)p)->f48 != 0 && FLDEFF_NAMIPOKE_SPLASH_IsFinished(((struct Obj04271 *)p)->f48) == 1) {
        o = FIELDMAP_GetEffect((u8 *)(((struct Obj04271 *)p)->f40));
        FIELD_EFFECT_DeleteObject(((struct Obj04271 *)p)->f48);
        FIELD_EFFECT_FreeResource(o, 9);
        FIELD_PLAYER_SetGridHopLanded((u32 *)(((struct Obj04271 *)p)->f3C), 1);
        ((struct Obj04271 *)p)->f48 = 0;
        ((struct Obj04271 *)p)->f6 = 1;
    }
    return 0;
}
