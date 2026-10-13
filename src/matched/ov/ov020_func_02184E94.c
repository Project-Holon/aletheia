/*
 * function: EVENT_MAPCHANGE_CreateDigEscapeEvent
 * address:  0x02184E94
 * packet:   pkt_ov020_02184E94
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAME_DATA_GetEscapeLocation  0x020128B8  thumb
 *   EVENT_MAPCHANGE_SeasonEffectAEvent  0x021847CC  thumb  ov020
 *   EVENT_MAPCHANGE_InitWork  0x02184CEC  thumb  ov020
 *   EVENT_MAPCHANGE_CopySpecialLocation  0x02185F18  thumb  ov020
 */
#include "../include/Obj00248.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct BigObj;
struct Rec1C;
struct Rec1C *GAME_DATA_GetEscapeLocation(const struct BigObj *p);
int EVENT_MAPCHANGE_SeasonEffectAEvent(int ctx, int *state, u8 *p);
void EVENT_MAPCHANGE_InitWork(void **o, void *p);
void EVENT_MAPCHANGE_CopySpecialLocation(void *a, void *b);

void *EVENT_MAPCHANGE_CreateDigEscapeEvent(int u, void *p)
{
    void *r0v = func_020122C0(p, 0, EVENT_MAPCHANGE_SeasonEffectAEvent, 0x9c);
    char *r4 = func_020124E8(r0v);
    S7 *src;

    EVENT_MAPCHANGE_InitWork((void **)r4, p);
    src = (S7 *)GAME_DATA_GetEscapeLocation(((struct Obj00248 *)r4)->f4);
    *(S7 *)(r4 + 0x10) = *src;
    EVENT_MAPCHANGE_CopySpecialLocation(((struct Obj00248 *)r4)->f4, r4 + 0x10);
    ((struct Obj00248 *)r4)->f10 = 1;
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = 1;
    return r0v;
}
