/*
 * function: UNION_SCENE_StepPokemonTrade
 * address:  0x021742BC
 * packet:   pkt_ov012_021742BC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *state (8 states). Pooled small words 0x77/0xC3 are
 * linker overlay ids (ov119/ov195) handed to GAMESYSTEM_CallProc with a table in
 * that overlay's window, as in ov001 func_021542C0.
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   ov119_id       0x00000077  data   a1
 *   ov195_id       0x000000C3  data   a1
 *   gPokemonTradeProcData     0x021E7608  data   ov119  a4
 *   d_02208C40     0x02208C40  data   ov195  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Req {
    u32 f0;
    u32 f4;
    u16 f8;
    u8  fA;
    u8  fB;
    u32 fC;
    u32 f10;
} Req;

typedef struct Ctx {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    Req *f20;
} Ctx;

struct IcaAnime;
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern u32 func_0200FB24(void);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);

extern char ov119_id[];
extern char ov195_id[];
extern u8 gPokemonTradeProcData[];
extern u8 d_02208C40[];

int UNION_SCENE_StepPokemonTrade(u32 a0, u32 a1, u32 a2, Ctx *ctx, u32 a4, void **out, u8 *state)
{
    Req *r;

    switch (*state) {
    case 0:
        *out = (void *)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)a0, a2, 0, 0);
        (*state)++;
        break;
    case 1:
        *out = (void *)FIELD_STATUS_CreateFieldCloseEvent(a0, a2);
        (*state)++;
        break;
    case 2:
        GAMESYSTEM_CallProc((struct IcaAnime *)a0, (u32)ov119_id, gPokemonTradeProcData, ctx);
        (*state)++;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)a0) != 0)
            break;
        if (ctx->f8 == 1)
            *state = 4;
        else
            *state = 6;
        break;
    case 4:
        r = ctx->f20;
        r->f0 = ctx->f14;
        r->f4 = ctx->f1C;
        r->f8 = ctx->fC;
        r->fA = 0;
        r->fB = ctx->f10;
        r->fC = 1;
        r->f10 = 0;
        ctx->f20 = r;
        GAMESYSTEM_CallProc((struct IcaAnime *)a0, (u32)ov195_id, d_02208C40, r);
        (*state)++;
        break;
    case 5:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)a0) != 0)
            break;
        if (func_0200FB24() != 0) {
            *state = 6;
        } else {
            ctx->f8 = 1;
            *state = 2;
        }
        break;
    case 6:
        *out = FIELD_STATUS_CreateFieldOpenEvent((void *)a0);
        *state = 7;
        break;
    case 7:
        *out = (void *)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)a0, a2, 0, 0, 1, 0, 0);
        *state = 8;
        break;
    default:
        return 1;
    }
    return 0;
}
