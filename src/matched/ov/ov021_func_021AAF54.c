/*
 * function: EFFECT_ENCOUNT_ClearSpotIfOccupied
 * address:  0x021AAF54
 * packet:   pkt_ov021_021AAF54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetFieldGimmick  0x02012A38  thumb
 *   EFFECT_ENCOUNT_IsTileOccupied  0x021AAEC0  thumb
 *   EFFECT_ENCOUNT_ClearSpot  0x021AAFA0  thumb
 */

typedef struct Ent {
    unsigned short id;
    short x;
    short y;
    short z;
    unsigned long w;
    unsigned char b;
    unsigned char flags : 4;
} Ent;

typedef struct Self {
    void *ctx;
    char pad04[4];
    void *obj;
    char pad0c[4];
    void *f10;
} Self;

typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetFieldGimmick(const struct BigObj *p);
extern int EFFECT_ENCOUNT_IsTileOccupied(Self *self, int x, short y, int z, int skip);
extern void EFFECT_ENCOUNT_ClearSpot(Self *self, void *p);

int EFFECT_ENCOUNT_ClearSpotIfOccupied(Self *self)
{
    Ent *e = (Ent *)(GAME_DATA_GetFieldGimmick(self->obj) + 0x10);

    if (e->flags == 0)
        return 0;
    if (EFFECT_ENCOUNT_IsTileOccupied(self, e->x, e->y, e->z, 1)) {
        EFFECT_ENCOUNT_ClearSpot(self, self->f10);
        return 1;
    }
    return 0;
}
