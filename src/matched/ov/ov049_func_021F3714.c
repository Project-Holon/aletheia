/*
 * function: func_021F3714
 * address:  0x021F3714
 * packet:   pkt_ov049_021F3714
 * region:   ov049
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the 12-byte table is copied field by field from a const table: a
 *           V3 struct assignment gives ldm/stm, and a non-const table keeps
 *           the third load below the second store.
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   gGimmick49Setup     0x021F3894  data  ov049  a4
 *   d_021F38A4     0x021F38A4  data  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern const V3 d_021F38A4[];
extern char gGimmick49Setup[];

struct BigObj;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
typedef signed int     s32;
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_AddUnitFromArchive(u32 a, void *b, int c);
extern V3 *FLD_EXP_OBJ_GetModelStatus(u32 a, int b, u16 c);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);

void func_021F3714(u32 a0, u32 a)
{
    int f0;
    int f1;
    int f2;
    int f3;
    void *sv;
    u32 s;
    int i;
    V3 *p;

    sv = (void *)GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a)));
    f0 = ZONEDATA_CheckEventFlag(sv, 0x96B);
    f1 = ZONEDATA_CheckEventFlag(sv, 0x96A);
    f2 = ZONEDATA_CheckEventFlag(sv, 0x969);
    f3 = ZONEDATA_CheckEventFlag(sv, 0x96C);
    s = FIELDMAP_GetExpObj((int *)a);
    FLD_EXP_OBJ_AddUnitFromArchive(s, gGimmick49Setup, 0);
    for (i = 0; i < 6; i++) {
        p = FLD_EXP_OBJ_GetModelStatus(s, 0, i);
        p->a = d_021F38A4[i].a;
        p->b = d_021F38A4[i].b;
        p->c = d_021F38A4[i].c;
    }
    if (f0 && f1 && f2 && f3) {
        FLD_EXP_OBJ_SetAnimeEnabled((void *)s, 0, 0, 0, 1);
        FLD_EXP_OBJ_SetAnimeEnabled((void *)s, 0, 1, 0, 1);
    }
    if (f0)
        FLD_EXP_OBJ_SetAnimeEnabled((void *)s, 0, 2, 1, 1);
    else
        FLD_EXP_OBJ_SetAnimeEnabled((void *)s, 0, 2, 0, 1);
    if (f1)
        FLD_EXP_OBJ_SetAnimeEnabled((void *)s, 0, 3, 1, 1);
    else
        FLD_EXP_OBJ_SetAnimeEnabled((void *)s, 0, 3, 0, 1);
    if (f2)
        FLD_EXP_OBJ_SetAnimeEnabled((void *)s, 0, 4, 1, 1);
    else
        FLD_EXP_OBJ_SetAnimeEnabled((void *)s, 0, 4, 0, 1);
    if (f3)
        FLD_EXP_OBJ_SetAnimeEnabled((void *)s, 0, 5, 1, 1);
    else
        FLD_EXP_OBJ_SetAnimeEnabled((void *)s, 0, 5, 0, 1);
}
