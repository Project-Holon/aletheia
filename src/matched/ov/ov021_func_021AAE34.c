/*
 * function: EFFECT_ENCOUNT_PickSpot
 * address:  0x021AAE34
 * packet:   pkt_ov021_021AAE34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005728  0x02005728  thumb
 *   GAME_DATA_GetFieldGimmick  0x02012A38  thumb
 *   EFFECT_ENCOUNT_IsTileOccupied  0x021AAEC0  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb
 *   EFFECT_ENCOUNT_ResetStepCount  0x021AABEC  thumb
 *   EFFECT_ENCOUNT_CreateEffectObj  0x021AAFC0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 b0;
    u8 pad1;
    u16 h2;
    u16 h4;
    u16 h6;
    int f8;
} E;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    E e[1];
} R;

typedef struct {
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    int f8;
    u8 bc;
    u8 lo : 4;
    u8 mid : 2;
    u8 hi : 2;
    u8 pad[2];
} Sub;

typedef struct {
    u8 pad[0x10];
    Sub sub;
} T;

typedef struct {
    int f0;
    int f4;
    int f8;
} S;

extern u32 func_02005728(u32 n);
struct BigObj;
extern u32 GAME_DATA_GetFieldGimmick(const struct BigObj *p);
extern int EFFECT_ENCOUNT_IsTileOccupied(S *s, s16 x, s16 y, s16 z, int w);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void EFFECT_ENCOUNT_ResetStepCount(u8 *p);
extern void EFFECT_ENCOUNT_CreateEffectObj(S *s, R *r, Sub *b);

void EFFECT_ENCOUNT_PickSpot(S *s, R *r)
{
    u16 k = func_02005728(r->h4);
    E *e = &r->e[k];
    T *t = (T *)GAME_DATA_GetFieldGimmick((const struct BigObj *)s->f8);
    Sub *b = &t->sub;
    e->h4 = (e->f8 >> 4) / 0x1000;
    if (EFFECT_ENCOUNT_IsTileOccupied(s, e->h2, e->h4, e->h6, 0) == 0) {
        b->h2 = e->h2;
        b->h4 = e->h4;
        b->h6 = e->h6;
        b->f8 = e->f8;
        b->bc = e->b0;
        b->h0 = FIELDMAP_GetZoneId((u8 *)s->f0);
        b->lo = 1;
        EFFECT_ENCOUNT_ResetStepCount((u8 *)t);
        EFFECT_ENCOUNT_CreateEffectObj(s, r, b);
    }
}
