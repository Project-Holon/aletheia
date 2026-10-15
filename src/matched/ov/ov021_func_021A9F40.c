/*
 * function: FIELD_ENCOUNT_CheckWildEncount
 * address:  0x021A9F40
 * packet:   pkt_ov021_021A9F40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   GAME_DATA_GetFieldGimmick  0x02012A38  thumb
 *   FIELD_ENCOUNT_UpdateStepWork  0x021AA728  thumb  ov021
 *   FIELD_ENCOUNT_GetEncountType  0x021AA35C  thumb  ov021
 *   FIELD_ENCOUNT_GetEncountRate  0x021AA3E0  thumb  ov021
 *   FIELDMAP_GetWeather  0x02188C6C  thumb  ov021
 *   WEATHER_GetWeatherId  0x021A1BF4  thumb  ov021
 *   FIELD_ENCOUNT_SetupParam  0x021A9350  thumb  ov021
 *   FIELD_ENCOUNT_CalcEncountRate  0x021A94B0  thumb  ov021
 *   FIELD_ENCOUNT_CheckEncountRoll  0x021AA3FC  thumb  ov021
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_ENCOUNT_PickRoamer  0x021A957C  thumb  ov021
 *   BTL_SETUP_Create  0x02013090  thumb
 *   FIELD_ENCOUNT_SetupRoamerBattle  0x021AA548  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_ENCOUNT_CreateZoneWildMons  0x021A954C  thumb  ov021
 *   FIELD_ENCOUNT_SetupWildBattle  0x021AA490  thumb  ov021
 *   FIELD_ENCOUNT_ResetStepWork  0x021AA6F8  thumb  ov021
 *   EVENT_BATTLE_CreateScriptedBattle  0x0216E7C8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Mon {
    u8 pad00[7];
    u8 lo : 7;
    u8 b7 : 1;
};

struct Ctx {
    void *f00;
    int f04;
    void *f08;
    struct Mon *f0C;
};

struct Slot14 {
    u8 raw[0x14];
};

struct Sel {
    u8 pad00[0x15];
    u8 f15;
    u8 pad16[0x12];
    u32 b0 : 5;
    u32 b5 : 1;
};

struct Pos;
struct Sub02008C20Obj;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct BigObj;
struct Obj;
struct Unit;
extern u32 GAME_DATA_GetFieldGimmick(const struct BigObj *p);
extern void FIELD_ENCOUNT_UpdateStepWork(struct Pos *p, void *q);
struct Tab;
extern int FIELD_ENCOUNT_GetEncountType(void **ctx, int mode, u8 *out);
extern int FIELD_ENCOUNT_GetEncountRate(struct Tab *t, int i, int add);
extern u32 FIELDMAP_GetWeather(u8 *p);
extern u16 WEATHER_GetWeatherId(u8 *p);
extern void FIELD_ENCOUNT_SetupParam(struct Sel *s, void *a, int b, int c, u16 d);
extern u32 FIELD_ENCOUNT_CalcEncountRate(struct Obj *o, u32 unused, u32 n);
extern int FIELD_ENCOUNT_CheckEncountRoll(void *a0, void *p, u32 rate);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void *FIELD_ENCOUNT_PickRoamer(void *a0, struct Unit *u, u32 want);
extern void *BTL_SETUP_Create(u32 heap);
extern void FIELD_ENCOUNT_SetupRoamerBattle(struct Ctx *ctx, void *a1, void *a2, u16 heap, void *src);
extern void MI_CpuFill8(void *p, int v, int n);
extern int FIELD_ENCOUNT_CreateZoneWildMons(void *a0, void *u, u16 id, void *slots);
extern void FIELD_ENCOUNT_SetupWildBattle(struct Ctx *ctx, struct Unit *u, void *a2, u16 heap, struct Slot14 *slots);
extern void FIELD_ENCOUNT_ResetStepWork(struct Pos *p, void *q);
extern int EVENT_BATTLE_CreateScriptedBattle(int a0, int a1, int a2, int a3, int a4);

int FIELD_ENCOUNT_CheckWildEncount(struct Ctx *ctx, int mode)
{
    struct Slot14 slots[2];
    struct Sel sel;
    u8 loc;
    int n;
    int m;
    void *p;
    void *q;
    int skip;
    void *src;
    void *h;
    int cnt;

    skip = 0;
    src = 0;
    q = FIELDMAP_GetFieldPlayer(ctx->f00);
    p = (void *)GAME_DATA_GetFieldGimmick(ctx->f08);
    if (mode == 1 || mode == 2)
        skip = 1;
    else
        FIELD_ENCOUNT_UpdateStepWork(p, q);
    if (ctx->f0C == 0 || !ctx->f0C->b7)
        return 0;
    loc = 0;
    m = FIELD_ENCOUNT_GetEncountType((void **)ctx, mode, &loc);
    n = FIELD_ENCOUNT_GetEncountRate((struct Tab *)ctx, m, loc);
    if (m == 0xFF || n == 0)
        return 0;
    FIELD_ENCOUNT_SetupParam(&sel, ctx->f08, m, mode, WEATHER_GetWeatherId((u8 *)FIELDMAP_GetWeather(ctx->f00)));
    if (!skip) {
        if (!FIELD_ENCOUNT_CheckEncountRoll(ctx, p, FIELD_ENCOUNT_CalcEncountRate((struct Obj *)(&sel), (u32)ctx->f08, n)))
            return 0;
    }
    if (mode == 1)
        func_02008DF0((void *)GAME_DATA_GetTrainerRecord(ctx->f08), 0x70);
    else
        src = FIELD_ENCOUNT_PickRoamer(ctx->f0C, (struct Unit *)(&sel), FIELDMAP_GetZoneId(ctx->f00));
    if (src) {
        h = BTL_SETUP_Create(4);
        FIELD_ENCOUNT_SetupRoamerBattle(ctx, &sel, h, 4, src);
    } else {
        src = 0;
        MI_CpuFill8(slots, 0, 0x28);
        cnt = FIELD_ENCOUNT_CreateZoneWildMons(ctx->f0C, &sel, FIELDMAP_GetZoneId(ctx->f00), slots);
        if (cnt == 0)
            return (int)src;
        if (sel.b5 && cnt == 1) {
            sel.b5 = 0;
            sel.f15 = cnt;
        }
        h = BTL_SETUP_Create(4);
        FIELD_ENCOUNT_SetupWildBattle(ctx, (struct Unit *)(&sel), h, 4, slots);
    }
    FIELD_ENCOUNT_ResetStepWork(p, q);
    return EVENT_BATTLE_CreateScriptedBattle(ctx->f04, (int)ctx->f00, (int)h, 0, mode);
}
