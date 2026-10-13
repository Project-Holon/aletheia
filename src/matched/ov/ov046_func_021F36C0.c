/*
 * function: GIMMICK45_Init
 * address:  0x021F36C0
 * packet:   pkt_ov046_021F36C0
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The [sp,#0xc] word the loop passes is mwcc's hoisted constant 1, spilled,
 * and f = (GIMMICK46_IsPosInside(vec) != 0 ? 1 : 0) coalesces with it; a named
 * f = 1 before the loop is propagated as a literal instead (41 bytes off).
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   GIMMICK46_InitModel  0x021F3838  thumb  ov046
 *   GIMMICK46_InitUnitPose  0x021F38D4  thumb  ov046
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   GIMMICK46_IsPosInside  0x021F40D8  thumb  ov046
 *   GIMMICK46_SetExteriorHidden  0x021F3FA8  thumb  ov046
 *   GIMMICK46_ApplyPoseLines  0x021F4078  thumb  ov046
 *   sGimmick46ExpUnitDesc     0x021F4120  data  a4
 *   sGimmick46UnitAngles     0x021F4108  data  a2
 *   sGimmick46BodyPos     0x021F4194  data  a4
 *   sGimmick46LeverPos     0x021F4170  data  a4
 *   sGimmick46ButtonPos     0x021F4204  data  a4
 *   sGimmick46ExtraModelPos     0x021F41B8  data  a4
 */
#include "../include/Obj20520.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern int FIELDMAP_GetExpObj(int *p);
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern void FLD_EXP_OBJ_AddUnitFromArchive(u32 p, void *a, int b);
extern void GIMMICK46_InitModel(u32 a0, int a1, V *a2, u16 *a3, int a4, int a5);
extern void GIMMICK46_InitUnitPose(u8 *base, u32 t, int idx);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern int GIMMICK46_IsPosInside(int *p);
extern void GIMMICK46_SetExteriorHidden(char *a, u32 b, u32 c);
extern void GIMMICK46_ApplyPoseLines(u32 a, int b, int c);

extern int sGimmick46ExpUnitDesc;
extern u16 sGimmick46UnitAngles[];
extern V sGimmick46BodyPos[];
extern V sGimmick46LeverPos[];
extern V sGimmick46ButtonPos[];
extern V sGimmick46ExtraModelPos;

void GIMMICK45_Init(void *a0)
{
    V tmp;
    int vec[3];
    u16 v;
    int i;
    u32 t;
    u8 *w;
    u8 *x;
    int n;
    int f;

    t = FIELDMAP_GetExpObj(a0);
    w = (u8 *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a0))), 10);
    x = FIELDMAP_AllocCommonWork(a0, 1, FIELDMAP_GetHeapId(a0), 0x28);
    FLD_EXP_OBJ_AddUnitFromArchive(t, &sGimmick46ExpUnitDesc, 0);
    for (i = 0; i < 3; i++) {
        v = 0;
        v = sGimmick46UnitAngles[i];
        n = i * 5;
        GIMMICK46_InitModel(t, n, &sGimmick46BodyPos[i], &v, 8, 0);
        GIMMICK46_InitModel(t, n + 1, &sGimmick46LeverPos[i], &v, 2, 0);
        GIMMICK46_InitModel(t, n + 2, &sGimmick46LeverPos[i], &v, 2, 0);
        GIMMICK46_InitModel(t, n + 3, &sGimmick46ButtonPos[i * 2], 0, 1, 1);
        GIMMICK46_InitModel(t, n + 4, &sGimmick46ButtonPos[i * 2 + 1], 0, 1, 1);
        GIMMICK46_InitUnitPose(w, t, i);
    }
    tmp = sGimmick46ExtraModelPos;
    GIMMICK46_InitModel(t, 0xf, &tmp, 0, 0, 0);
    FLD_EXP_OBJ_SetAnimeEnabled((void *)t, 0, 0xf, 0, 1);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((void *)a0), (struct VecFx32 *)vec);
    f = GIMMICK46_IsPosInside(vec) != 0 ? 1 : 0;
    GIMMICK46_SetExteriorHidden((char *)t, (u32)a0, f);
    ((struct Obj20520 *)x)->f24 = f;
    for (i = 0; i < 3; i++)
        GIMMICK46_ApplyPoseLines((u32)a0, i, *(int *)(w + i * 12));
}
