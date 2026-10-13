/*
 * function: FIELD_PLAYER_GRID_GetMoveResultOnFoot
 * address:  0x021A44C8
 * packet:   pkt_ov021_021A44C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_GRID_IsOnHopStartTile  0x021A5610  thumb  ov021
 *   FIELD_PLAYER_GRID_IsHopFlagSet  0x021A53BC  thumb  ov021
 *   FIELD_PLAYER_GRID_GetMoveResultOnFootHop  0x021A46F0  thumb  ov021
 *   FIELD_PLAYER_GRID_GetStandResultOnFoot  0x021A4544  thumb  ov021
 *   FIELD_PLAYER_GRID_GetWalkResultOnFoot  0x021A4598  thumb  ov021
 *   FIELD_PLAYER_GRID_GetTurnResultOnFoot  0x021A4664  thumb  ov021
 *   FIELD_PLAYER_GRID_GetBlockedResultOnFoot  0x021A4698  thumb  ov021
 */
#include "../include/Obj09565.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern int FIELD_PLAYER_GRID_IsOnHopStartTile(u32 *p);
extern int FIELD_PLAYER_GRID_IsHopFlagSet(u32 a);
extern int FIELD_PLAYER_GRID_GetMoveResultOnFootHop(u8 *, u32);
extern int FIELD_PLAYER_GRID_GetStandResultOnFoot(u8 *p, u32 r, u8 *q);
extern int FIELD_PLAYER_GRID_GetWalkResultOnFoot(u8 *a, void *b, u8 *c);
extern int FIELD_PLAYER_GRID_GetTurnResultOnFoot(int a, int b, u8 *c);
extern int FIELD_PLAYER_GRID_GetBlockedResultOnFoot(u8 *, void *, u32);

int FIELD_PLAYER_GRID_GetMoveResultOnFoot(u8 *p, u32 s)
{
    void *a;
    int r;

    a = FIELD_PLAYER_CORE_GetMmdl(((struct Obj09565 *)p)->fC);
    r = 0;
    if (FIELD_PLAYER_GRID_IsOnHopStartTile((u32 *)p) == 1 || FIELD_PLAYER_GRID_IsHopFlagSet((u32)p) == 1) {
        return FIELD_PLAYER_GRID_GetMoveResultOnFootHop(p, s);
    }
    switch (((struct Obj09565 *)p)->f0) {
    case 0:
        r = FIELD_PLAYER_GRID_GetStandResultOnFoot(p, (u32)a, (u8 *)s);
        break;
    case 1:
        r = FIELD_PLAYER_GRID_GetWalkResultOnFoot(p, a, (u8 *)s);
        break;
    case 2:
        r = FIELD_PLAYER_GRID_GetTurnResultOnFoot((int)p, (int)a, (u8 *)s);
        break;
    case 3:
        r = FIELD_PLAYER_GRID_GetBlockedResultOnFoot(p, a, s);
        break;
    }
    return r;
}
