/*
 * function: FIELD_BUILDMODEL_CollectEntriesInRect
 * address:  0x0218C584
 * packet:   pkt_ov021_0218C584
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Collects the active 16-byte entries whose position lies inside a rect.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELD_G3D_MAP_GetPos  0x02169510  thumb
 *   VEC_Add  0x0207C9D0  arm
 *   FIELD_BUILDMODEL_GetEntryAnimKind  0x0218C674  thumb  ov021
 *   gBuildModelFileName     0x021DD9CC  data   a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19535.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int a;
    int b;
    int c;
    int d;
} Rect;

typedef struct {
    int obj;
    int pad[2];
    u8 *ref;
} Ent;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FIELD_G3D_MAP_GetPos(int o, Vec *v);
extern void VEC_Add(Vec *a, Vec *b, Vec *c);
extern int FIELD_BUILDMODEL_GetEntryAnimKind(unsigned char *p, int b);
extern char gBuildModelFileName[];

static inline int InRect(Rect *r, int x, int z)
{
    if (r->c <= x && r->d >= x && r->a <= z && r->b >= z)
        return 1;
    return 0;
}

Ent **FIELD_BUILDMODEL_CollectEntriesInRect(u8 *s, Rect *r, int kind, int *count)
{
    Ent **list;
    Ent *e;
    Vec v;
    int n = 0;
    u32 i;

    list = func_02030734(((struct Obj19535 *)s)->f0, 0x80, 1, gBuildModelFileName, 0x749);
    for (i = 0; i < 0x120; i++) {
        e = (Ent *)(s + 0x1F8) + i;
        if (e->obj == 0)
            continue;
        if (kind != 0 && kind != FIELD_BUILDMODEL_GetEntryAnimKind(s, (int)e))
            continue;
        FIELD_G3D_MAP_GetPos(e->obj, &v);
        VEC_Add((Vec *)(e->ref + 4), &v, &v);
        if (InRect(r, v.x, v.z) == 1) {
            list[n] = e;
            n++;
        }
    }
    *count = n;
    return list;
}
