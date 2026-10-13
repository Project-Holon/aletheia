/*
 * function: EVENT_MAPCHANGE_CreateWarpEvent
 * address:  0x02184D38
 * packet:   pkt_ov020_02184D38
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The ARM9 leaf 0x02014184 is resolved by its matched shard.
 *
 * What made it byte-correct: `const int *q` (see the EXACT twins
 * ov020_func_02184D90.c / ov020_func_02184DE8.c).
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020142A4  0x020142A4  thumb
 *   ZONEDATA_SetDirectLocation  0x02014184  thumb
 *   EVENT_MAPCHANGE_InitWork  0x02184CEC  thumb  ov020
 *   EVENT_MAPCHANGE_EntranceEvent  0x02184388  thumb  ov020
 */
#include "../include/Obj00248.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void EVENT_MAPCHANGE_InitWork(void **o, void *p);
u32 func_020142A4(u32 idx);
int EVENT_MAPCHANGE_EntranceEvent(int a, int *state, u8 *p);
void ZONEDATA_SetDirectLocation(void *o, int a, int s, int x, int y, int z);

void *EVENT_MAPCHANGE_CreateWarpEvent(void *p, int unused, int a, const int *q, u16 s, int t)
{
    void *r0v = func_020122C0(p, 0, EVENT_MAPCHANGE_EntranceEvent, 0x9c);
    char *r4 = func_020124E8(r0v);

    EVENT_MAPCHANGE_InitWork((void **)r4, p);
    s = func_020142A4(s);
    ZONEDATA_SetDirectLocation(r4 + 0x10, a, (s16)s, q[0], q[1], q[2]);
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = t;
    return r0v;
}
