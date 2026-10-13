/*
 * function: EVENT_MAPCHANGE_CreateWarpEventWithTargetPos
 * address:  0x02184E40
 * packet:   pkt_ov020_02184E40
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   ZONEDATA_SetDirectLocation  0x02014184  thumb
 *   EVENT_MAPCHANGE_TargetPositionEvent  0x02184730  thumb  ov020
 *   EVENT_MAPCHANGE_InitWork  0x02184CEC  thumb  ov020
 */
#include "../include/Obj00248.h"
typedef short s16;
typedef struct { int x, y, z; } Vec;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void ZONEDATA_SetDirectLocation(void *d, int a, s16 b, unsigned int c, unsigned int e, unsigned int f);
int EVENT_MAPCHANGE_TargetPositionEvent(int ctx, int *state, u8 *p);
void EVENT_MAPCHANGE_InitWork(void **o, void *p);
static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x; d->y = y; d->z = z;
}
void *EVENT_MAPCHANGE_CreateWarpEventWithTargetPos(void *p, int u, const Vec *v, s16 b, const int *s)
{
    void *r0v = func_020122C0(p, 0, EVENT_MAPCHANGE_TargetPositionEvent, 0x9c);
    char *r4 = func_020124E8(r0v);
    EVENT_MAPCHANGE_InitWork((void **)r4, p);
    ZONEDATA_SetDirectLocation(r4 + 0x10, b, 1, s[0], s[1], s[2]);
    vset((Vec *)(r4 + 0x34), v->x, v->y, v->z);
    ((struct Obj00248 *)r4)->f2C = 0;
    return r0v;
}
