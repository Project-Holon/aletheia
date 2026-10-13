/*
 * function: FIELD_PLAYER_GRID_ApplyMoveResultOnFoot
 * address:  0x021A4CF4
 * packet:   pkt_ov021_021A4CF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_GRID_ApplyNoneOnFoot  0x021A4D8C  thumb  ov021
 *   FIELD_PLAYER_GRID_StartStandOnFoot  0x021A4D90  thumb  ov021
 *   FIELD_PLAYER_GRID_StartWalkOnFoot  0x021A4DC0  thumb  ov021
 *   FIELD_PLAYER_GRID_StartTurnOnFoot  0x021A4E78  thumb  ov021
 *   FIELD_PLAYER_GRID_StartBlockedOnFoot  0x021A4E9C  thumb  ov021
 *   FIELD_PLAYER_GRID_StartLedgeJumpOnFoot  0x021A4ED8  thumb  ov021
 *   FIELD_PLAYER_GRID_StartHoldOnFoot  0x021A4F04  thumb  ov021
 *   FIELD_PLAYER_GRID_StartHopOnFoot  0x021A4F0C  thumb  ov021
 *   FIELD_PLAYER_GRID_StartHopAirOnFoot  0x021A4F50  thumb  ov021
 *   FIELD_PLAYER_GRID_StartHopFallOnFoot  0x021A4F58  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00262.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern void FIELD_PLAYER_GRID_ApplyNoneOnFoot(u32 a, u32 b, u32 c);
extern void FIELD_PLAYER_GRID_StartStandOnFoot(u32 *p, int b, u8 *c);
extern void FIELD_PLAYER_GRID_StartWalkOnFoot(u32 *a, u32 b, u32 *c);
extern void FIELD_PLAYER_GRID_StartTurnOnFoot(u32 *p, int b, u8 *c);
extern void FIELD_PLAYER_GRID_StartBlockedOnFoot(u32 *p, int b, u8 *c);
extern void FIELD_PLAYER_GRID_StartLedgeJumpOnFoot(u32 *p, int b, u8 *c);
extern void FIELD_PLAYER_GRID_StartHoldOnFoot(u32 *a, void *a1, u32 a2);
extern void FIELD_PLAYER_GRID_StartHopOnFoot(u32 a, void *b, u32 c);
extern void FIELD_PLAYER_GRID_StartHopAirOnFoot(u32 *a, void *a1, u32 a2);
extern int FIELD_PLAYER_GRID_StartHopFallOnFoot(u32 *p, void *a1, u32 a2);

void FIELD_PLAYER_GRID_ApplyMoveResultOnFoot(u32 a, u32 b, u32 c)
{
    void *x = FIELD_PLAYER_CORE_GetMmdl(((struct Obj00262 *)a)->fC);
    switch (b) {
    case 0: FIELD_PLAYER_GRID_ApplyNoneOnFoot(a, (u32)x, c); return;
    case 1: FIELD_PLAYER_GRID_StartStandOnFoot((u32 *)a, (int)x, (u8 *)c); return;
    case 2: FIELD_PLAYER_GRID_StartWalkOnFoot((u32 *)a, (u32)x, (u32 *)c); return;
    case 3: FIELD_PLAYER_GRID_StartTurnOnFoot((u32 *)a, (int)x, (u8 *)c); return;
    case 4: FIELD_PLAYER_GRID_StartBlockedOnFoot((u32 *)a, (int)x, (u8 *)c); return;
    case 5: FIELD_PLAYER_GRID_StartLedgeJumpOnFoot((u32 *)a, (int)x, (u8 *)c); return;
    case 6: FIELD_PLAYER_GRID_StartHoldOnFoot((u32 *)a, x, c); return;
    case 7: FIELD_PLAYER_GRID_StartHopOnFoot(a, (void *)x, c); return;
    case 8: FIELD_PLAYER_GRID_StartHopAirOnFoot((u32 *)((u32)((u32)((u32)((u32)((u32)((u32)a)))))), x, c); return;
    case 9: FIELD_PLAYER_GRID_StartHopFallOnFoot((u32 *)((u32 *)a), x, c); break;
    }
}
