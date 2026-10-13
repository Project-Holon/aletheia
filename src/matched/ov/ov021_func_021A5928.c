/*
 * function: FIELD_PLAYER_NOGRID_AttachMmdl
 * address:  0x021A5928
 * packet:   pkt_ov021_021A5928
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_ChangeHeader  0x0216E0AC  thumb  ov010
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FLDMMDL_RAIL_SetLocation  0x0219E2C0  thumb  ov021
 *   gFieldPlayerNogridMmdlHeader     0x021DDEE0  data  a4
 *   d_021DDEE0b    0x021DDEE0  data  a4
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05027.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern u16  gFieldPlayerNogridMmdlHeader[2];
extern u16  d_021DDEE0b[2];

extern u16 FLDMMDL_GetMoveCode(void *p);
extern u16 FLDMMDL_GetObjCode(void *p);
extern void FLDMMDL_ChangeHeader(void *a0, void *a1);
extern void *FLDMMDL_RAIL_GetRailWork(void *a);
extern void FLDMMDL_RAIL_SetLocation(void *a, void *r);

void FIELD_PLAYER_NOGRID_AttachMmdl(u8 *p, int v)
{
    if (FLDMMDL_GetMoveCode((void *)(((struct Obj05027 *)p)->f1C)) != 0x45) {
        gFieldPlayerNogridMmdlHeader[1] = FLDMMDL_GetObjCode((void *)(((struct Obj05027 *)p)->f1C));
        FLDMMDL_ChangeHeader((void *)(((struct Obj05027 *)p)->f1C), d_021DDEE0b);
    }
    ((struct Obj05027 *)p)->f20 = (int)FLDMMDL_RAIL_GetRailWork((void *)(((struct Obj05027 *)p)->f1C));
    FLDMMDL_RAIL_SetLocation((void *)(((struct Obj05027 *)p)->f1C), (void *)v);
}
