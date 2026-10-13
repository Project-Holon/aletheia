/*
 * function: FIELD_GIMMICK_TIME_EFFECT_Init
 * address:  0x021F36C0
 * packet:   pkt_ov065_021F36C0
 * region:   ov065
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     s is declared last (first or third put it in r4 and a0 in r5);
 *           the range test is `x - 3 <= 1` on the u32 result (a switch
 *           with cases 3 and 4 compiles two compares).
 *
 * symbols:
 *   sGimmick65UnitDescNight     0x021F3918  data  a4
 *   sGimmick65UnitDescDay     0x021F38F8  data  a4
 *   sGimmick65EffectPosition     0x021F3970  data  a4
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   TIMEZONE_GetNowTimeZone  0x020113D8  thumb
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 */

#include "../include/G__anon_V.h"

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct _anon_V V;

extern char sGimmick65UnitDescNight[];
extern char sGimmick65UnitDescDay[];
extern struct _anon_V sGimmick65EffectPosition;

struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Big;
extern unsigned char *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern int FIELDMAP_GetExpObj(int *p);
typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
struct BigObj;
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u32   TIMEZONE_GetNowTimeZone(u32 a);
extern void  FLD_EXP_OBJ_AddUnitFromArchive(void *p, void *a, int b);
extern V    *FLD_EXP_OBJ_GetModelStatus(void *p, int i, u16 j);
extern void FLD_EXP_OBJ_SetModelCullDraw(char *p, int i, int j, int v);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void  FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, u16 j, u16 k, int flag);

void FIELD_GIMMICK_TIME_EFFECT_Init(void *a0)
{
    u32 sv;
    int *q;
    int *o;
    int i;
    void *b;
    void *s;

    sv = (u32)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a0));
    q = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave((struct Big *)sv), 0x36);
    s = (void *)FIELDMAP_GetExpObj(a0);
    FIELDMAP_AllocCommonWork(a0, 1, FIELDMAP_GetHeapId(a0), 8);
    o = FIELDMAP_GetCommonWork(a0, 1);
    o[0] = 0;
    if (TIMEZONE_GetNowTimeZone((u32)GAME_DATA_GetSeason((const struct BigObj *)sv)) - 3 <= 1) {
        FLD_EXP_OBJ_AddUnitFromArchive(s, sGimmick65UnitDescNight, 0);
        o[1] = 1;
    } else {
        FLD_EXP_OBJ_AddUnitFromArchive(s, sGimmick65UnitDescDay, 0);
        o[1] = 0;
    }
    *FLD_EXP_OBJ_GetModelStatus(s, 0, 0) = sGimmick65EffectPosition;
    FLD_EXP_OBJ_SetModelCullDraw(s, 0, 0, 1);
    FLD_EXP_OBJ_SetModelHidden(s, 0, 0, *q == 0);
    for (i = 0; i < 2; i++) {
        b = FLD_EXP_OBJ_GetAnime(s, 0, (u16)0, (u16)i);
        FLD_EXP_OBJ_SetAnimeLoop(b, 0);
        FLD_EXP_OBJ_SetAnimePaused(b, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, 0, i, *q != 0);
    }
}
