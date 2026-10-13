/*
 * function: EFFECT_ENCOUNT_SetEffectFlag
 * address:  0x021AAB1C
 * packet:   pkt_ov021_021AAB1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetFieldGimmick  0x02012A38  thumb
 *   FLDEFF_ENCOUNT_SetDrawHidden  0x021ADB5C  thumb
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

typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetFieldGimmick(const struct BigObj *p);

extern void FLDEFF_ENCOUNT_SetDrawHidden(int a, int b);

void EFFECT_ENCOUNT_SetEffectFlag(S *s, int b)
{
    T *t = (T *)GAME_DATA_GetFieldGimmick((const struct BigObj *)s->f8);
    D *d = s->f10;
    if (t->lo && d->f5b4 != 0) {
        FLDEFF_ENCOUNT_SetDrawHidden(d->f5b4, b);
    }
}
