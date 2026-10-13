/*
 * function: FIELD_PLAYER_CORE_ChangeToObjCode
 * address:  0x021A3D08
 * packet:   pkt_ov021_021A3D08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FIELD_PLAYER_CORE_CheckPlainModel  0x021A3B78  thumb  ov021
 *   FIELD_PLAYER_CORE_ChangeModel  0x021A3AD8  thumb  ov021
 *   FIELD_PLAYER_CORE_GetSex  0x021A398C  thumb  ov021
 *   FIELD_PLAYER_GetFormObjCode  0x021A3190  thumb  ov021
 */
#include "../include/Obj09562.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
extern u16 FLDMMDL_GetObjCode(void *p);
extern int FIELD_PLAYER_CORE_CheckPlainModel(u8 *);
extern void FIELD_PLAYER_CORE_ChangeModel(u8 *p, int a);
extern u32 FIELD_PLAYER_CORE_GetSex(u8 *);
extern u16 FIELD_PLAYER_GetFormObjCode(int, int);

int FIELD_PLAYER_CORE_ChangeToObjCode(u8 *p, u32 v)
{
    if (v == FLDMMDL_GetObjCode(FIELD_PLAYER_CORE_GetMmdl(p))) {
        ((struct Obj09562 *)p)->f32 = 1;
        return 1;
    }
    if (FIELD_PLAYER_CORE_CheckPlainModel(p) == 1) {
        FIELD_PLAYER_CORE_ChangeModel(p, v);
        ((struct Obj09562 *)p)->f32 = 1;
        return 1;
    }
    FIELD_PLAYER_CORE_ChangeModel(p, FIELD_PLAYER_GetFormObjCode(FIELD_PLAYER_CORE_GetSex(p), 0));
    return 0;
}
