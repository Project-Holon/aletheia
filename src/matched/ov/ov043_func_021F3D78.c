/*
 * function: GIMMICK43_ElevatorEventMain
 * address:  0x021F3D78
 * packet:   pkt_ov043_021F3D78
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Once filed EXACT* because the extent ran into the unlabelled leaf GIMMICK43_IsLiftArrived
 * (filed as ov043_func_021F3ECC.c) and the unlabelled follower
 * 0x021F3EEC. Twin of ov044_func_021F37F0.c.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   GIMMICK43_IsLiftArrived  0x021F3ECC  thumb  ov043
 *   GIMMICK43_StartCameraShake  0x021F41B8  thumb  ov043
 *   GIMMICK43_UpdateCameraShake  0x021F4210  thumb  ov043
 *   GIMMICK43_ShowElevatorIdleAnime  0x021F4174  thumb  ov043
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Big;
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *FIELDMAP_GetCamera(void *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern u32 FIELD_CAMERA_GetTraceTarget(u8 *p);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_CAMERA_SetTraceTarget(u32 a, int v);
extern void func_020061E4(u32 a);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern int GIMMICK43_IsLiftArrived(int *p);
extern void GIMMICK43_StartCameraShake(int a0, int a1, int a2, int a3, u8 *s);
extern int GIMMICK43_UpdateCameraShake(u8 *s);
extern void GIMMICK43_ShowElevatorIdleAnime(void *p);

int GIMMICK43_ElevatorEventMain(void *a, int *b)
{
    void *s;
    void *r;
    int *w;
    u32 h;
    void *c;
    int v[3];

    s = GAMESYSTEM_GetFieldMap(func_020124E4(a));
    r = (void *)FIELDMAP_GetExpObj(s);
    w = FIELDMAP_GetCommonWork(s, 1);
    h = (u32)FIELDMAP_GetCamera(s);
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(s))), 7);
    switch (*b) {
    case 0:
        if (w[5] != 0) {
            w[4] = FIELD_CAMERA_GetTraceTarget((u8 *)h);
            FIELD_CAMERA_StopTargetTrace((u8 *)h);
        }
        func_020061E4(w[5] == 0 ? 0x6da : 0x6ca);
        (*b)++;
        break;
    case 1:
        w[1] += w[3];
        if (GIMMICK43_IsLiftArrived(w)) {
            w[1] = w[2];
            if (w[5] == 0) {
                GIMMICK43_StartCameraShake(0xff, w[3], 0, h, (u8 *)(w + 8));
                func_020061E4(0x6cb);
            }
            (*b)++;
        }
        ((int *)FLD_EXP_OBJ_GetModelStatus(r, 0, 7))[1] = w[1];
        c = FIELDMAP_GetFieldPlayer((void *)s);
        FIELD_PLAYER_GetPos(c, (struct VecFx32 *)v);
        v[1] = w[1];
        FIELD_PLAYER_SetPos(c, v);
        break;
    case 2:
        if (w[5] != 0) {
            return 1;
        }
        if (GIMMICK43_UpdateCameraShake((u8 *)(w + 8))) {
            if (w[4] != 0) {
                FIELD_CAMERA_SetTraceTarget(h, w[4]);
            }
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(r, 0, 7, 1), 0);
            (*b)++;
        }
        break;
    case 3:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(r, 0, 7, 1))) {
            GIMMICK43_ShowElevatorIdleAnime(r);
            return 1;
        }
        break;
    }
    return 0;
}
