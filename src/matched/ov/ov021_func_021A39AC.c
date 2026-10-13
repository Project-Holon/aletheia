/*
 * function: FIELD_PLAYER_CORE_SetFormSlotModel
 * address:  0x021A39AC
 * packet:   pkt_ov021_021A39AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetSex  0x021A398C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_GetFormObjCode  0x021A3190  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FIELD_PLAYER_CORE_ChangeModel  0x021A3AD8  thumb  ov021
 */
#include "../include/Obj19778.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_PLAYER_CORE_GetSex(u8 *p);
void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
u16 FIELD_PLAYER_GetFormObjCode(int i, int j);
u16 FLDMMDL_GetObjCode(void *p);
void FIELD_PLAYER_CORE_ChangeModel(u8 *p, int v);

void FIELD_PLAYER_CORE_SetFormSlotModel(u8 *p, int a)
{
    u32 x = FIELD_PLAYER_CORE_GetSex(p);
    void *h = FIELD_PLAYER_CORE_GetMmdl(p);
    int v = FIELD_PLAYER_GetFormObjCode(x, a);

    if (v != FLDMMDL_GetObjCode(h))
        FIELD_PLAYER_CORE_ChangeModel(p, v);
    ((struct Obj19778 *)p)->f2C = 0;
}
