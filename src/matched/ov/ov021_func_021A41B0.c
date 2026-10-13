/*
 * function: FIELD_PLAYER_GRID_Move
 * address:  0x021A41B0
 * packet:   pkt_ov021_021A41B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_ChooseMoveDirFromKeys  0x021A3AB8  thumb  ov021
 *   FIELD_PLAYER_GRID_CanStartMove  0x021A4254  thumb  ov021
 *   FIELD_PLAYER_CORE_StepFormChange  0x021A3CC0  thumb  ov021
 *   FIELD_PLAYER_GRID_RunForcedMove  0x021A55A8  thumb  ov021
 *   FIELD_PLAYER_GRID_GetMoveResult  0x021A4444  thumb  ov021
 *   FIELD_PLAYER_GRID_BeginMove  0x021A4224  thumb  ov021
 *   FIELD_PLAYER_GRID_ApplyMoveResult  0x021A4CA8  thumb  ov021
 *   FIELD_PLAYER_GRID_PlayStepSound  0x021A43D8  thumb  ov021
 */
#include "../include/Obj00656.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 w0;
    u32 w4;
    u16 h8;
    u32 wC;
    u32 w10;
} Req;

extern u16 FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(u32 a, u32 v);
extern int FIELD_PLAYER_GRID_CanStartMove(u32 *p, u32 a);
extern void FIELD_PLAYER_CORE_StepFormChange(u32);
extern int FIELD_PLAYER_GRID_RunForcedMove(u32 *p, u32 a, int b);
extern int FIELD_PLAYER_GRID_GetMoveResult(u8 *p, u32 s);
extern void FIELD_PLAYER_GRID_BeginMove(u8 *, int, Req *);
extern void FIELD_PLAYER_GRID_ApplyMoveResult(u32 a, u32 b, u32 c);
extern void FIELD_PLAYER_GRID_PlayStepSound(u8 *p, int k, int dir);

void FIELD_PLAYER_GRID_Move(u8 *p, u32 a, u32 b, u32 c)
{
    Req s;
    u32 d;
    int e;

    d = FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(*(u32 *)&((struct Obj00656 *)p)->fC, b);
    if (FIELD_PLAYER_GRID_CanStartMove((u32 *)p, d) == 1) {
        FIELD_PLAYER_CORE_StepFormChange(*(u32 *)&((struct Obj00656 *)p)->fC);
        if (FIELD_PLAYER_GRID_RunForcedMove((u32 *)p, d, 0) == 0) {
            s.w0 = a;
            s.w4 = b;
            s.h8 = d;
            s.wC = c;
            s.w10 = 0;
            e = FIELD_PLAYER_GRID_GetMoveResult(p, (u32)(&s));
            FIELD_PLAYER_GRID_BeginMove(p, e, &s);
            FIELD_PLAYER_GRID_ApplyMoveResult((u32)p, e, (u32)(&s));
            FIELD_PLAYER_GRID_PlayStepSound(p, e, d);
        }
    }
}
