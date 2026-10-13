/*
 * function: EVENT_FIELD_PROCLINK_CreateEvolutionParam
 * address:  0x02161554
 * packet:   pkt_ov010_02161554
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   SHINKA_CHECK_CheckEvolution  0x0201B2B0  thumb
 *   func_02030734  0x02030734  arm
 *   d_02172978     0x02172978  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ctx {
    u8 pad00[0x18];
    u32 **f18;          /* 0x18 */
    u8 pad1c[0x68 - 0x1C];
    u32 f68;            /* 0x68 */
} Ctx;

typedef struct Src {
    u8 pad00[0x3C];
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 f44;            /* 0x44 */
} Src;

typedef struct Rec {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u16 f08;            /* 0x08 */
    u8 f0a;             /* 0x0A */
    u8 f0b;             /* 0x0B */
    u32 f0c;            /* 0x0C */
    u32 f10;            /* 0x10 */
} Rec;

extern const char d_02172978[];

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *func_0201AB28(void *a, u32 b);
extern u16 *GAME_DATA_GetMyPlayerWork(void *sv);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

Rec *EVENT_FIELD_PROCLINK_CreateEvolutionParam(Ctx *c, int a1, int mode, const Src *src)
{
    Rec *r;
    void *sv;
    void *t;
    void *k;
    u32 out;
    u32 res;
    u8 x;

    sv = GAMESYSTEM_GetGameData((const struct Ctx *)(*c->f18));
    r = 0;
    if (mode == 0) {
        t = GAME_DATA_GetMyParty(sv);
        if (src->f40 == 8) {
            c->f68 = 3;
            k = func_0201AB28(t, src->f3c);
            x = GAME_DATA_GetSeason(sv);
            res = SHINKA_CHECK_CheckEvolution(t, k, 3, src->f44, x, &out, 4);
        } else {
            c->f68 = 4;
            k = func_0201AB28(t, src->f3c);
            res = SHINKA_CHECK_CheckEvolution(t, k, 0, *GAME_DATA_GetMyPlayerWork(sv), GAME_DATA_GetSeason(sv), &out, 4);
        }
        r = func_02030734(4, 0x14, 0, d_02172978, 0x868);
        r->f00 = sv;
        r->f04 = t;
        r->f08 = res;
        r->f0a = src->f3c;
        r->f0b = out;
        r->f0c = 1;
        r->f10 = 1;
    }
    return r;
}
