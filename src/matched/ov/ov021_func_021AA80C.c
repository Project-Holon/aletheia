/*
 * function: EFFECT_ENCOUNT_OnPlayerStep
 * address:  0x021AA80C
 * packet:   pkt_ov021_021AA80C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetFieldGimmick  0x02012A38  thumb
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   MAP_MATRIX_IsInRangeByPos  0x02159C48  thumb  ov010
 *   MAP_MATRIX_GetZoneIdByPos  0x02159BD4  thumb  ov010
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   BEACON_GetFlag  0x0200C234  thumb
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   EFFECT_ENCOUNT_CountStep  0x021AABC4  thumb  ov021
 *   func_02005728  0x02005728  thumb
 *   EFFECT_ENCOUNT_ResetStepCount  0x021AABEC  thumb  ov021
 *   EFFECT_ENCOUNT_CollectCandidates  0x021AACD4  thumb  ov021
 *   EFFECT_ENCOUNT_PickSpot  0x021AAE34  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Mon {
    u8 pad00[7];
    u8 lo : 7;
    u8 b7 : 1;
};

struct Entry {
    u8 pad00[0x1D];
    u8 flags : 4;
};

struct Enc {
    u8 pad00[4];
    u16 f04;
    u8 pad06[0x5B4];
    u16 f5BA;
};

struct Ctx {
    void *f00;
    int f04;
    void *f08;
    struct Mon *f0C;
    struct Enc *f10;
};

struct BigObj;
extern u32 GAME_DATA_GetFieldGimmick(const struct BigObj *p);
extern u32 GAME_DATA_GetFieldWork(const struct BigObj *p);
struct Blk34;
extern u16 FIELDMAP_GetZoneId(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern int MAP_MATRIX_IsInRangeByPos(int a0, int a1, int a2);
extern int MAP_MATRIX_GetZoneIdByPos(int a0, int a1, int a2);
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 BEACON_GetFlag(struct Blk34 *p, u32 bit);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int EFFECT_ENCOUNT_CountStep(struct Entry *p, struct Enc *e);
extern u32 func_02005728(u32 v);
extern void EFFECT_ENCOUNT_ResetStepCount(u8 *p);
extern void EFFECT_ENCOUNT_CollectCandidates(void **ctx, struct Enc *e);
extern void EFFECT_ENCOUNT_PickSpot(struct Ctx *ctx, struct Enc *e);

void EFFECT_ENCOUNT_OnPlayerStep(struct Ctx *ctx)
{
    struct Enc *e = ctx->f10;
    struct Entry *p = (struct Entry *)GAME_DATA_GetFieldGimmick(ctx->f08);
    void *m;
    u16 id;
    s32 pos[3];
    int r;

    if (ctx == 0 || ctx->f0C == 0 || !ctx->f0C->b7)
        return;
    m = (void *)GAME_DATA_GetFieldWork(ctx->f08);
    if (ctx->f00 == 0 || m == 0)
        return;
    id = FIELDMAP_GetZoneId(ctx->f00);
    FLDMMDL_GetPos(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(ctx->f00)), (struct VecFx32 *)pos);
    if (MAP_MATRIX_IsInRangeByPos((int)m, pos[0], pos[2]) == 0)
        return;
    r = MAP_MATRIX_GetZoneIdByPos((int)m, pos[0], pos[2]);
    if (id == 0xFFFF || r == 0xFFFF || id != r)
        return;
    if (BEACON_GetFlag(GAME_DATA_GetMiscSave(ctx->f08), 0) == 0)
        return;
    if (FIELDMAP_GetMoveKind(ctx->f00) != 0)
        return;
    if (p->flags != 0)
        return;
    if (EFFECT_ENCOUNT_CountStep(p, e) == 0)
        return;
    if (func_02005728(1000) >= e->f5BA * 10) {
        EFFECT_ENCOUNT_ResetStepCount((u8 *)p);
        return;
    }
    EFFECT_ENCOUNT_CollectCandidates((void **)ctx, e);
    if (e->f04 != 0)
        EFFECT_ENCOUNT_PickSpot(ctx, e);
}
