/*
 * function: FIELD_ENCOUNT_CheckWfbcEncount
 * address:  0x021AA248
 * packet:   pkt_ov021_021AA248
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   func_02012A38  0x02012A38  thumb
 *   FIELD_ENCOUNT_UpdateStepWork  0x021AA728  thumb  ov021
 *   FIELD_WFBC_IsBackPeople  0x02193920  thumb  ov021
 *   FIELD_ENCOUNT_CheckWfbcRoll  0x021AA42C  thumb  ov021
 *   FIELD_ENCOUNT_GetEncountType  0x021AA35C  thumb  ov021
 *   FIELDMAP_GetWeather  0x02188C6C  thumb  ov021
 *   WEATHER_GetWeatherId  0x021A1BF4  thumb  ov021
 *   FIELD_ENCOUNT_SetupParam  0x021A9350  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_ENCOUNT_PickWfbcMon  0x021A9604  thumb  ov021
 *   BTL_SETUP_Create  0x02013090  thumb
 *   FIELD_ENCOUNT_SetupWildBattle  0x021AA490  thumb  ov021
 *   FIELD_ENCOUNT_ResetStepWork  0x021AA6F8  thumb  ov021
 *   EVENT_BATTLE_CreateScriptedBattle  0x0216E7C8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    void *f00;
    int f04;
    void *f08;
};

struct Slot14 {
    u16 f00;
    u16 f02;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
    u8 pad08[0xC];
};

struct Sel {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x20];
};

struct Pos;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct BigObj;
struct Out;
struct Unit;
extern u32 func_02012A38(const struct BigObj *p);
extern void FIELD_ENCOUNT_UpdateStepWork(struct Pos *p, void *q);
extern u8 FIELD_WFBC_IsBackPeople(u8 *p);
extern int FIELD_ENCOUNT_CheckWfbcRoll(void *a, void *b);
extern int FIELD_ENCOUNT_GetEncountType(void **ctx, int mode, u8 *out);
extern u32 FIELDMAP_GetWeather(u8 *p);
extern u16 WEATHER_GetWeatherId(u8 *p);
extern void FIELD_ENCOUNT_SetupParam(struct Sel *s, void *a, int b, int c, u16 d);
extern void MI_CpuFill8(void *p, int v, int n);
extern u32 FIELD_ENCOUNT_PickWfbcMon(int obj, struct Sel *sel, struct Out *out);
extern void *BTL_SETUP_Create(u32 heap);
extern void FIELD_ENCOUNT_SetupWildBattle(struct Ctx *ctx, struct Unit *u, void *a2, u16 heap, struct Slot14 *slots);
extern void FIELD_ENCOUNT_ResetStepWork(struct Pos *p, void *q);
extern int EVENT_BATTLE_CreateScriptedBattle(int a0, int a1, int a2, int a3, int a4);

int FIELD_ENCOUNT_CheckWfbcEncount(struct Ctx *ctx, void *b)
{
    struct Slot14 slots[2];
    struct Sel sel;
    u8 loc;
    void *q;
    void *p;
    int m;
    void *h;

    q = FIELDMAP_GetFieldPlayer(ctx->f00);
    p = (void *)func_02012A38(ctx->f08);
    FIELD_ENCOUNT_UpdateStepWork(p, q);
    if (FIELD_WFBC_IsBackPeople(b) == 1) {
        return 0;
    }
    if (!FIELD_ENCOUNT_CheckWfbcRoll(p, b)) {
        return 0;
    }
    loc = 0;
    m = FIELD_ENCOUNT_GetEncountType((void **)ctx, 3, &loc);
    FIELD_ENCOUNT_SetupParam(&sel, ctx->f08, m, 3, WEATHER_GetWeatherId((u8 *)FIELDMAP_GetWeather(ctx->f00)));
    MI_CpuFill8(slots, 0, 0x28);
    if (!FIELD_ENCOUNT_PickWfbcMon((int)b, &sel, (struct Out *)slots)) {
        return 0;
    }
    h = BTL_SETUP_Create(4);
    FIELD_ENCOUNT_SetupWildBattle(ctx, (struct Unit *)(&sel), h, 4, slots);
    FIELD_ENCOUNT_ResetStepWork(p, q);
    return EVENT_BATTLE_CreateScriptedBattle(ctx->f04, (int)ctx->f00, (int)h, 0, 3);
}
