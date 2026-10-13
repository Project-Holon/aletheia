/*
 * function: EVENT_MAPCHANGE_CreateWarpEventToLocation
 * address:  0x021854CC
 * packet:   pkt_ov020_021854CC
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_SetPlayerObjectCode  0x02012B2C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_MAPCHANGE_DetachedTailEvent  0x02184504  thumb  ov020
 *   EVENT_MAPCHANGE_InitWork  0x02184CEC  thumb  ov020
 *   EVENT_MAPCHANGE_UpdateEscapeLocation  0x02185EB0  thumb  ov020
 */
#include "../include/Obj00248.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

struct Ctx;
struct Desc;
struct Obj;
struct Rec44;
struct SaveBlock;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
void GAME_DATA_SetPlayerObjectCode(struct Rec44 *p, u32 v);
int EVENT_MAPCHANGE_DetachedTailEvent(int a, int *state, u8 *p);
void EVENT_MAPCHANGE_InitWork(void **o, void *p);
void EVENT_MAPCHANGE_UpdateEscapeLocation(int a, u16 *p);

void *EVENT_MAPCHANGE_CreateWarpEventToLocation(void *p, int u, int u2, const S7 *src, u16 h)
{
    void *r7 = GAMESYSTEM_GetGameData(p);
    void *r0v;
    char *r4;

    GAME_DATA_SetPlayerObjectCode(GAME_DATA_GetMyPlayerWork(r7), 0);
    r0v = func_020122C0(p, 0, EVENT_MAPCHANGE_DetachedTailEvent, 0x9c);
    r4 = func_020124E8(r0v);
    EVENT_MAPCHANGE_InitWork((void **)r4, p);
    *(S7 *)(r4 + 0x10) = *src;
    ((struct Obj00248 *)r4)->f18 = h;
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f30 = 1;
    EVENT_MAPCHANGE_UpdateEscapeLocation((int)r7, (u16 *)(r4 + 0x10));
    return r0v;
}
