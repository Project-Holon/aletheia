/*
 * function: DUP_FITTING_UpdateIdle
 * address: 0x021B75E0
 * packet: pkt_ov133_021B75E0
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_UpdateSubMode 0x021B8A30 thumb ov133
 *   DUP_FITTING_UpdateCursor 0x021B7A70 thumb ov133
 *   DUP_FITTING_UpdateRotation 0x021B8AC8 thumb ov133
 *   DUP_FITTING_UpdateHeldVisible 0x021B8FA8 thumb ov133
 *   DUP_FITTING_SetModelTransform 0x021B765C thumb ov133
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void DUP_FITTING_UpdateSubMode(u8 *);
extern void DUP_FITTING_UpdateCursor(u8 *);
extern void DUP_FITTING_UpdateRotation(u8 *);
extern void DUP_FITTING_UpdateHeldVisible(u8 *);
typedef signed short   s16;
extern void *DUP_FITTING_SetModelTransform(u8 *p, u16 base, s16 speed, u16 rx, u16 ry);
void DUP_FITTING_UpdateIdle(u8 *p)
{
    if (((struct Obj00004 *)p)->f98 == 1) DUP_FITTING_UpdateSubMode(p);
    else { DUP_FITTING_UpdateCursor(p); DUP_FITTING_UpdateRotation(p); }
    DUP_FITTING_UpdateHeldVisible(p);
    ++((struct Obj00004 *)p)->f94;
    if (((struct Obj00004 *)p)->f94 >= 90) {
        ((struct Obj00004 *)p)->f94 = 0;
        DUP_FITTING_SetModelTransform(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
    }
    if (((struct Obj00004 *)p)->f94 == 45)
        DUP_FITTING_SetModelTransform(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
}
