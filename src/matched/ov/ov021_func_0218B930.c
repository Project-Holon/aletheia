/*
 * function: FIELD_BUILDMODEL_GetPlacementPosition
 * address:  0x0218B930
 * packet:   pkt_ov021_0218B930
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetPlacementByTableId  0x0218B910  thumb  ov021
 *   FIELD_BUILDMODEL_GetModelIndex  0x0218BBD0  thumb  ov021
 */

typedef struct {
    int f0;
    unsigned short id;
    short x;
    short y;
    short z;
} Ent;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef unsigned int   u32;
int FIELD_BUILDMODEL_GetPlacementByTableId(u32 a, u32 b);
int FIELD_BUILDMODEL_GetModelIndex(void *p, unsigned int i);

static inline void Vec_Set(Vec *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

int FIELD_BUILDMODEL_GetPlacementPosition(void *p, int a, Vec *pos, int *k)
{
    Ent *e = (Ent *)FIELD_BUILDMODEL_GetPlacementByTableId((u32)p, a);
    if (e->id == 0xFFFF)
        return 0;
    *k = FIELD_BUILDMODEL_GetModelIndex(p, e->id);
    Vec_Set(pos, e->x << 12, e->y << 12, e->z << 12);
    return 1;
}
