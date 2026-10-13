/*
 * function: EFFECT_ENCOUNT_SetEffectPaused
 * address:  0x021AAAF0
 * packet:   pkt_ov021_021AAAF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetFieldGimmick  0x02012A38  thumb
 *   FLDEFF_ENCOUNT_SetPaused  0x021ADB4C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad[0x1d];
    u8 lo : 4;
    u8 mid : 2;
    u8 hi : 2;
} T;

typedef struct {
    char pad[0x5b4];
    int f5b4;
} D;

typedef struct {
    int pad[2];
    int f8;
    int fc;
    D *f10;
} S;

struct BigObj;
extern unsigned int GAME_DATA_GetFieldGimmick(const struct BigObj *p);

typedef unsigned int   u32;
extern void FLDEFF_ENCOUNT_SetPaused(u32 a, int v);

void EFFECT_ENCOUNT_SetEffectPaused(S *s, int b)
{
    T *t = (T *)GAME_DATA_GetFieldGimmick((const struct BigObj *)s->f8);
    D *d = s->f10;
    if (t->lo && d->f5b4 != 0) {
        FLDEFF_ENCOUNT_SetPaused(d->f5b4, b);
    }
}
