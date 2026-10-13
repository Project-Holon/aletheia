/*
 * function: FIELD_PLAYER_GRID_BeginMove
 * address:  0x021A4224
 * packet:   pkt_ov021_021A4224
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_RememberKeyDirs  0x021A3AC4  thumb  ov021
 *   FIELD_PLAYER_GRID_ClearStepPendingFlag  0x021A536C  thumb  ov021
 *   FIELD_PLAYER_GRID_ClearFlag  0x021A530C  thumb  ov021
 *   FIELD_PLAYER_GRID_ClearNoForcedMoveFlag  0x021A5360  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 pad0;
    int mode;
    u32 pad8;
    u32 h;
    u8 pad10[0xC];
    u32 x1c;
} Obj021A4224;

typedef struct {
    u32 pad0;
    u32 v;
} Arg021A4224;

void FIELD_PLAYER_CORE_RememberKeyDirs(u32 a, u32 b);
void FIELD_PLAYER_GRID_ClearStepPendingFlag(u32 a);
int FIELD_PLAYER_GRID_ClearFlag(u32 a, u32 b);
void FIELD_PLAYER_GRID_ClearNoForcedMoveFlag(u32 a);

void FIELD_PLAYER_GRID_BeginMove(Obj021A4224 *p, int mode, const Arg021A4224 *q)
{
    p->mode = mode;
    FIELD_PLAYER_CORE_RememberKeyDirs(p->h, q->v);
    FIELD_PLAYER_GRID_ClearStepPendingFlag((u32)p);
    FIELD_PLAYER_GRID_ClearFlag((u32)p, 0x20);
    if (mode == 2)
        FIELD_PLAYER_GRID_ClearNoForcedMoveFlag((u32)p);
    p->x1c = 0;
}
