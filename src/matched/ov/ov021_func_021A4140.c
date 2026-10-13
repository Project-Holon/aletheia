/*
 * function: FIELD_PLAYER_GRID_Create
 * address:  0x021A4140
 * packet:   pkt_ov021_021A4140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   sFieldPlayerGridFile     0x021DDECC  data  ov021  a4
 *   FIELD_PLAYER_CORE_GetFieldMap  0x021A395C  thumb  ov021
 *   FIELD_PLAYER_GRID_SetNoForcedMoveFlag  0x021A5354  thumb  ov021
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_CORE_StartFormChange  0x021A3CB0  thumb  ov021
 *   FIELD_PLAYER_CORE_FinishFormChange  0x021A3CE8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03586.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 sFieldPlayerGridFile[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 FIELD_PLAYER_CORE_GetFieldMap(u8 *p);
extern void FIELD_PLAYER_GRID_SetNoForcedMoveFlag(u32 a);
extern u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);
extern int FIELD_PLAYER_CORE_StartFormChange(u32, u32);
extern void FIELD_PLAYER_CORE_FinishFormChange(u32);

u32 *FIELD_PLAYER_GRID_Create(u32 a, u32 b)
{
    u32 *o;
    int k;

    o = func_02030734(b, 0x20, 1, (const char *)sFieldPlayerGridFile, 0x17D);
    o[3] = a;
    o[4] = FIELD_PLAYER_CORE_GetFieldMap((u8 *)a);
    ((struct Obj03586 *)o)->f18 = 0x546;
    FIELD_PLAYER_GRID_SetNoForcedMoveFlag((u32)o);
    k = FIELD_PLAYER_CORE_GetFormCode((u8 *)o[3]);
    switch (k) {
    case 2:
        FIELD_PLAYER_CORE_StartFormChange(o[3], 4);
        FIELD_PLAYER_CORE_FinishFormChange(o[3]);
        break;
    case 3:
        FIELD_PLAYER_CORE_StartFormChange(o[3], 0x100);
        FIELD_PLAYER_CORE_FinishFormChange(o[3]);
        break;
    }
    return o;
}
