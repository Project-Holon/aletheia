/*
 * function: FIELD_ENCOUNT_CheckFishingEncount
 * address:  0x021AA180
 * packet:   pkt_ov021_021AA180
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   FIELD_ENCOUNT_GetEncountRate  0x021AA3E0  thumb  ov021
 *   FIELDMAP_GetWeather  0x02188C6C  thumb  ov021
 *   WEATHER_GetWeatherId  0x021A1BF4  thumb  ov021
 *   FIELD_ENCOUNT_SetupParam  0x021A9350  thumb  ov021
 *   FIELD_ENCOUNT_CalcEncountRate  0x021A94B0  thumb  ov021
 *   FIELD_ENCOUNT_RandRatePercent  0x021AA6E0  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_ENCOUNT_CreateZoneWildMons  0x021A954C  thumb  ov021
 *   BTL_SETUP_Create  0x02013090  thumb
 *   FIELD_ENCOUNT_SetupWildBattle  0x021AA490  thumb  ov021
 *   BTL_SETUP_SetStatusFlag  0x02013144  thumb
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
    u8 pad16[0x16];
};

struct Obj {
    u8 pad00[0xC];
    int f0C;
};

struct Tab;
extern int FIELD_ENCOUNT_GetEncountRate(struct Tab *t, int i, int add);
extern u32 FIELDMAP_GetWeather(u8 *p);
struct Unit;
extern u16 WEATHER_GetWeatherId(u8 *p);
extern void FIELD_ENCOUNT_SetupParam(struct Sel *s, void *a, int b, int c, u16 d);
extern u32 FIELD_ENCOUNT_CalcEncountRate(struct Obj *o, u32 unused, u32 n);
extern u32 FIELD_ENCOUNT_RandRatePercent(void);
extern void func_02082BCC(void *p, int v, int n);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern int FIELD_ENCOUNT_CreateZoneWildMons(void *a0, void *u, u16 id, void *slots);
extern void *BTL_SETUP_Create(u32 heap);
extern void FIELD_ENCOUNT_SetupWildBattle(struct Ctx *ctx, struct Unit *u, void *a2, u16 heap, struct Slot14 *slots);
extern void BTL_SETUP_SetStatusFlag(char *p, int v);

struct Obj *FIELD_ENCOUNT_CheckFishingEncount(struct Ctx *ctx, int mode)
{
    struct Slot14 slots[2];
    struct Sel sel;
    int k;
    int m;
    u32 rate;
    struct Obj *h;

    if (ctx->f0C == 0 || !ctx->f0C->b7)
        return 0;
    k = 6;
    if (mode != 1)
        k = 5;
    m = FIELD_ENCOUNT_GetEncountRate((struct Tab *)ctx, k, 0);
    if (m == 0)
        return 0;
    FIELD_ENCOUNT_SetupParam(&sel, ctx->f08, k, mode, WEATHER_GetWeatherId((u8 *)FIELDMAP_GetWeather(ctx->f00)));
    if (mode != 1) {
        rate = FIELD_ENCOUNT_CalcEncountRate((struct Obj *)(&sel), (u32)ctx->f08, m);
        if (FIELD_ENCOUNT_RandRatePercent() > rate)
            return 0;
    }
    h = 0;
    func_02082BCC(slots, 0, 0x28);
    if ((u32)FIELD_ENCOUNT_CreateZoneWildMons(ctx->f0C, &sel, FIELDMAP_GetZoneId(ctx->f00), slots) < sel.f15)
        return h;
    h = BTL_SETUP_Create(4);
    FIELD_ENCOUNT_SetupWildBattle(ctx, (struct Unit *)(&sel), h, 4, slots);
    BTL_SETUP_SetStatusFlag((char *)h, 1);
    h->f0C = 6;
    return h;
}
