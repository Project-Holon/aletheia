/*
 * function: FIELD_PLAYER_GRID_ApplyMoveResultOnCycle
 * address:  0x021A4FA8
 * packet:   pkt_ov021_021A4FA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_GRID_ApplyNoneOnCycle  0x021A5010  thumb  ov021
 *   FIELD_PLAYER_GRID_StartStandOnCycle  0x021A5014  thumb  ov021
 *   FIELD_PLAYER_GRID_StartWalkOnCycle  0x021A5044  thumb  ov021
 *   FIELD_PLAYER_GRID_StartTurnOnCycle  0x021A50BC  thumb  ov021
 *   FIELD_PLAYER_GRID_StartBlockedOnCycle  0x021A50E0  thumb  ov021
 *   FIELD_PLAYER_GRID_StartLedgeJumpOnCycle  0x021A511C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00262.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern void FIELD_PLAYER_GRID_ApplyNoneOnCycle(u32 a, u32 b, u32 c);
extern void FIELD_PLAYER_GRID_StartStandOnCycle(u32 *p, int b, u8 *c);
extern void FIELD_PLAYER_GRID_StartWalkOnCycle(u32 *a, u32 b, u32 *c);
extern void FIELD_PLAYER_GRID_StartTurnOnCycle(u32 *p, int b, u8 *c);
extern void FIELD_PLAYER_GRID_StartBlockedOnCycle(u32 *p, int b, u8 *c);
extern void FIELD_PLAYER_GRID_StartLedgeJumpOnCycle(u32 *p, int b, u8 *c);

void FIELD_PLAYER_GRID_ApplyMoveResultOnCycle(u32 a, u32 b, u32 c)
{
    void *x = FIELD_PLAYER_CORE_GetMmdl(((struct Obj00262 *)a)->fC);
    switch (b) {
    case 0: FIELD_PLAYER_GRID_ApplyNoneOnCycle(a, (u32)x, c); return;
    case 1: FIELD_PLAYER_GRID_StartStandOnCycle((u32 *)a, (int)x, (u8 *)c); return;
    case 2: FIELD_PLAYER_GRID_StartWalkOnCycle((u32 *)a, (u32)x, (u32 *)c); return;
    case 3: FIELD_PLAYER_GRID_StartTurnOnCycle((u32 *)a, (int)x, (u8 *)c); return;
    case 4: FIELD_PLAYER_GRID_StartBlockedOnCycle((u32 *)a, (int)x, (u8 *)c); return;
    case 5: FIELD_PLAYER_GRID_StartLedgeJumpOnCycle((u32 *)a, (int)x, (u8 *)c); break;
    }
}
