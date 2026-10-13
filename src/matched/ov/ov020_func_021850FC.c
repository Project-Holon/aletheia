/*
 * function: EVENT_MAPCHANGE_CreateSpecialLocationEvent
 * address:  0x021850FC
 * packet:   pkt_021850FC
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, then a seven-word record copied from a global-ish
 * accessor into offset 0x10.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSpecialLocation  0x02012894  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_MAPCHANGE_SwapCommOverlayEvent  0x02184BF8  thumb  ov020
 *   EVENT_MAPCHANGE_InitWork  0x02184CEC  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct BigObj;
struct Ctx;
struct Rec1C;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Rec1C *GAME_DATA_GetSpecialLocation(const struct BigObj *p);
int EVENT_MAPCHANGE_SwapCommOverlayEvent(void *ctx, int *st, int *p);
void EVENT_MAPCHANGE_InitWork(void **o, void *p);

void *EVENT_MAPCHANGE_CreateSpecialLocationEvent(void *p, u8 *pos)
{
    S7 *r5 = (S7 *)GAME_DATA_GetSpecialLocation(GAMESYSTEM_GetGameData(p));
    void *r0v = func_020122C0(p, 0, EVENT_MAPCHANGE_SwapCommOverlayEvent, 0x9C);
    char *r4 = func_020124E8(r0v);

    EVENT_MAPCHANGE_InitWork((void **)r4, p);
    *(S7 *)(r4 + 0x10) = *r5;
    return r0v;
}
