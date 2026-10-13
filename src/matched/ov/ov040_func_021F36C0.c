/*
 * function: FIELD_GIMMICK_FLAG_ANIME_Init
 * address:  0x021F36C0
 * packet:   pkt_ov040_021F36C0
 * region:   ov040
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GIMMICK_FLAG_ANIME_Init  0x021F36C0  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_AddUnit  0x021BE310  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   gGimmick40ModelPos     0x021F38D4  data  a4
 *   gGimmick40UnitSetup     0x021F38EC  data  a4
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern V3 gGimmick40ModelPos;
extern char gGimmick40UnitSetup[];

typedef unsigned short u16;
struct Big;
struct Ctx;
extern int FIELDMAP_GetExpObj(int *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void FLD_EXP_OBJ_AddUnit(u32 a, void *b, int c);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern V3 *FLD_EXP_OBJ_GetModelStatus(u32 a, int b, int c);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeLoop(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(u32 a);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);

void FIELD_GIMMICK_FLAG_ANIME_Init(u32 a)
{
    u32 s;
    u8 *q;
    u8 *e;
    V3 v;

    s = FIELDMAP_GetExpObj((int *)a);
    FIELDMAP_AllocCommonWork((unsigned char *)a, 1, FIELDMAP_GetHeapId((u8 *)a), 4);
    FIELDMAP_GetCommonWork((char *)a, 1);
    FLD_EXP_OBJ_AddUnit(s, gGimmick40UnitSetup, 0);
    q = (u8 *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a))), 3);
    v.a = gGimmick40ModelPos.a;
    v.b = 0;
    v.c = gGimmick40ModelPos.b;
    *FLD_EXP_OBJ_GetModelStatus(s, 0, 0) = v;
    e = FLD_EXP_OBJ_GetAnime((char *)s, 0, 0, 0);
    FLD_EXP_OBJ_SetAnimePaused(e, 1);
    FLD_EXP_OBJ_SetAnimeLoop(e, 0);
    if (q[4] != 0) {
        FLD_EXP_OBJ_SetAnimeEnabled((void *)s, 0, 0, 0, 1);
        FLD_EXP_OBJ_SetAnimeFrame(s, 0, 0, 0, FLD_EXP_OBJ_GetAnimeLastFrame((u32)e));
    }
}
