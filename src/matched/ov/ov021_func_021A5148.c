/*
 * function: FIELD_PLAYER_GRID_ApplyMoveResultOnSurf
 * address:  0x021A5148
 * packet:   pkt_ov021_021A5148
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_GRID_ApplyNoneOnSurf  0x021A51A4  thumb  ov021
 *   FIELD_PLAYER_GRID_StartStandOnSurf  0x021A51A8  thumb  ov021
 *   FIELD_PLAYER_GRID_StartWalkOnSurf  0x021A51D8  thumb  ov021
 *   FIELD_PLAYER_GRID_StartTurnOnSurf  0x021A5204  thumb  ov021
 *   FIELD_PLAYER_GRID_StartBlockedOnSurf  0x021A5228  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00262.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern void FIELD_PLAYER_GRID_ApplyNoneOnSurf(u32 a, u32 b, u32 c);
extern void FIELD_PLAYER_GRID_StartStandOnSurf(u32 *p, int b, u8 *c);
extern void FIELD_PLAYER_GRID_StartWalkOnSurf(u32 *p, int b, u8 *c);
extern void FIELD_PLAYER_GRID_StartTurnOnSurf(u32 *p, int b, u8 *c);
extern void FIELD_PLAYER_GRID_StartBlockedOnSurf(u32 *p, int b, u8 *c);

void FIELD_PLAYER_GRID_ApplyMoveResultOnSurf(u32 a, u32 b, u32 c)
{
    void *x = FIELD_PLAYER_CORE_GetMmdl(((struct Obj00262 *)a)->fC);
    switch (b) {
    case 0: FIELD_PLAYER_GRID_ApplyNoneOnSurf(a, (u32)x, c); return;
    case 1: FIELD_PLAYER_GRID_StartStandOnSurf((u32 *)a, (int)x, (u8 *)c); return;
    case 2: FIELD_PLAYER_GRID_StartWalkOnSurf((u32 *)a, (int)x, (u8 *)c); return;
    case 3: FIELD_PLAYER_GRID_StartTurnOnSurf((u32 *)a, (int)x, (u8 *)c); return;
    case 4: FIELD_PLAYER_GRID_StartBlockedOnSurf((u32 *)a, (int)x, (u8 *)c); break;
    }
}
