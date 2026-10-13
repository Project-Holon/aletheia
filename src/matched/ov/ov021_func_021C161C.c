/*
 * function: FIELD_PLAYER_GRID_EVENT_JumpUpLand
 * address:  0x021C161C
 * packet:   pkt_ov021_021C161C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_InitPosition  0x0216E014  thumb  ov010
 *   FIELD_PLAYER_GetRideEffect  0x021A2F98  thumb  ov021
 *   FLDEFF_NAMIPOKE_SetFollowMode  0x021ACBB8  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_NAMIPOKE_SPLASH_StartOnEffect  0x021AD564  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04270.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int FLDMMDL_SetStatusBitHeightGetOff(void *a0, int a1);
extern void FLDMMDL_InitPosition(void *a, int *p, int b);
extern u32 FIELD_PLAYER_GetRideEffect(u8 *p);
extern void FLDEFF_NAMIPOKE_SetFollowMode(u32 a, u8 v);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern u32 FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(u32 a, u32 b, void *c);
extern void func_020061E4(u32 se);

int FIELD_PLAYER_GRID_EVENT_JumpUpLand(u8 *p)
{
    void *r5;

    r5 = FIELD_PLAYER_GetMmdl(((struct Obj04270 *)p)->f3C);
    FLDMMDL_SetStatusBitHeightGetOff(r5, 0);
    FLDMMDL_InitPosition(r5, (int *)(p + 0x24), ((struct Obj04270 *)p)->f4);
    r5 = (void *)FIELD_PLAYER_GetRideEffect((u8 *)(*(u32 *)&((struct Obj04270 *)p)->f3C));
    FLDEFF_NAMIPOKE_SetFollowMode((u32)r5, 1);
    ((struct Obj04270 *)p)->f48 = FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(FIELDMAP_GetEffect((u8 *)(((struct Obj04270 *)p)->f40)), 0, r5);
    func_020061E4(0x6e2);
    ((struct Obj04270 *)p)->f2 = ((struct Obj04270 *)p)->f2 + 1;
    return 0;
}
