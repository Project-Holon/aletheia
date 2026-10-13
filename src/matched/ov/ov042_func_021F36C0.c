/*
 * function: FIELD_GIMMICK_BUTTON_STATES_Init
 * address:  0x021F36C0
 * packet:   pkt_ov042_021F36C0
 * region:   ov042
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The counters are 32-bit with a u8 wraparound increment: each use passed
 * to a u16 parameter keeps its own (u8) truncation pair, which a u8 counter
 * drops.
 *
 * symbols:
 *   gGimmick42UnitSetup     0x021F3A58  data  a4
 *   gGimmick42StatePos     0x021F3AD4  data  a4
 *   gGimmick42OneShotPos     0x021F3A68  data  a4
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    V v[9];
} T;

extern int gGimmick42UnitSetup;
extern T gGimmick42StatePos;
extern T gGimmick42OneShotPos;

struct Big;
struct Ctx;
extern int FIELDMAP_GetExpObj(int *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void  FLD_EXP_OBJ_AddUnitFromArchive(void *p, void *a, int b);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void FLD_EXP_OBJ_SetModelCullDraw(char *p, int i, int j, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *p, int v);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(u32 a);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);

void FIELD_GIMMICK_BUTTON_STATES_Init(void *a0)
{
    void *s;
    u8 *q;
    char *e;
    void *b;
    u32 i;
    u8 x;
    T ta;
    T tb;

    s = (void *)FIELDMAP_GetExpObj(a0);
    q = (u8 *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a0))), 4);
    FIELDMAP_AllocCommonWork(a0, 1, FIELDMAP_GetHeapId(a0), 4);
    FLD_EXP_OBJ_AddUnitFromArchive(s, &gGimmick42UnitSetup, 0);
    ta = gGimmick42StatePos;
    for (i = 0; i < 9; i = (u8)(i + 1)) {
        e = (char *)FLD_EXP_OBJ_GetModelStatus(s, 0, (u8)i);
        *(V *)e = ta.v[i];
        FLD_EXP_OBJ_SetModelCullDraw(s, 0, (u8)i, 1);
    }
    tb = gGimmick42OneShotPos;
    for (i = 0; i < 3; i = (u8)(i + 1)) {
        e = (char *)FLD_EXP_OBJ_GetModelStatus(s, 0, (u8)(i + 9));
        *(V *)e = tb.v[i];
        FLD_EXP_OBJ_SetModelCullDraw(s, 0, (u8)(i + 9), 1);
    }
    for (i = 0; i < 3; i = (u8)(i + 1)) {
        if (q[i]) {
            x = i + 9;
            FLD_EXP_OBJ_SetAnimeEnabled(s, 0, x, 0, 1);
            b = FLD_EXP_OBJ_GetAnime(s, 0, x, 0);
            FLD_EXP_OBJ_SetAnimePaused(b, 0);
            FLD_EXP_OBJ_SetAnimeLoop(b, 0);
            FLD_EXP_OBJ_SetAnimeFrame((int)s, 0, x, 0, FLD_EXP_OBJ_GetAnimeLastFrame((u32)b));
        }
    }
}
