/*
 * function: FIELD_GIMMICK_GAUGE_EFFECT_Update
 * address:  0x021F374C
 * packet:   pkt_ov060_021F374C
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   FIELD_GIMMICK_GAUGE_EFFECT_GetIntrudeCommSys  0x021F3938  thumb  ov060
 *   FIELD_GIMMICK_GAUGE_EFFECT_HideGaugeModels  0x021F3850  thumb  ov060
 *   FIELD_GIMMICK_GAUGE_EFFECT_ShowGauges  0x021F3880  thumb  ov060
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   FIELD_GIMMICK_GAUGE_EFFECT_UpdateEffect  0x021F39F4  thumb  ov060
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u16 lo : 3;
} Bf;

struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *a);
extern void *FIELD_GIMMICK_GAUGE_EFFECT_GetIntrudeCommSys(void *p);
extern void FIELD_GIMMICK_GAUGE_EFFECT_HideGaugeModels(char *p);
extern u8 FIELD_GIMMICK_GAUGE_EFFECT_ShowGauges(void *a, void *b, void *unused);
extern void FLD_EXP_OBJ_UpdateAnimes(void *p);
extern void FIELD_GIMMICK_GAUGE_EFFECT_UpdateEffect(u8 *a, void *b);

void FIELD_GIMMICK_GAUGE_EFFECT_Update(void *o)
{
    u32 c;
    u32 h;
    void *s;
    u8 *q;
    void *v;

    c = (u32)FIELDMAP_GetGameSystem(o);
    h = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)c);
    GAME_DATA_GetFieldSave((struct Big *)h);
    s = (void *)FIELDMAP_GetExpObj(o);
    q = (u8 *)FIELDMAP_GetCommonWork(o, 0);
    v = FIELD_GIMMICK_GAUGE_EFFECT_GetIntrudeCommSys((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)c));
    if (v != 0) {
        if (((Bf *)((u8 *)v + 0x86))->lo != *q) {
            FIELD_GIMMICK_GAUGE_EFFECT_HideGaugeModels((char *)s);
            *q = FIELD_GIMMICK_GAUGE_EFFECT_ShowGauges((void *)h, s, v);
        }
    }
    FLD_EXP_OBJ_UpdateAnimes(s);
    if (q[1] != 0) {
        FIELD_GIMMICK_GAUGE_EFFECT_UpdateEffect(q, s);
    }
}
