/*
 * function: FIELD_GIMMICK_LIFT_LiftEventMain
 * address:  0x021F37F0
 * packet:   pkt_ov044_021F37F0
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Once filed EXACT* because the extent ran into the unlabelled leaf FIELD_GIMMICK_LIFT_IsLiftArrived
 * (filed as ov044_func_021F390C.c).
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FIELD_GIMMICK_LIFT_IsLiftArrived  0x021F390C  thumb  ov044
 *   FIELD_GIMMICK_LIFT_ShowIdleAnime  0x021F392C  thumb  ov044
 */

typedef unsigned int u32;

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
typedef unsigned char  u8;
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELD_CAMERA_GetTraceTarget(u8 *p);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_CAMERA_SetTraceTarget(u32 a, int v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern int FIELD_GIMMICK_LIFT_IsLiftArrived(int *p);
extern void FIELD_GIMMICK_LIFT_ShowIdleAnime(void *p);

int FIELD_GIMMICK_LIFT_LiftEventMain(void *a, int *b)
{
    void *s;
    void *r;
    int *w;
    u32 h;
    void *c;
    int v[3];

    s = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(a));
    r = (void *)FIELDMAP_GetExpObj(s);
    w = FIELDMAP_GetCommonWork(s, 1);
    h = (u32)FIELDMAP_GetCamera(s);
    switch (*b) {
    case 0:
        if (w[4] != 0) {
            w[3] = FIELD_CAMERA_GetTraceTarget((u8 *)h);
            FIELD_CAMERA_StopTargetTrace((u8 *)h);
        }
        GFL_USE_PlaySeDefaultVolume(w[4] == 0 ? 0x6da : 0x6ca);
        (*b)++;
        break;
    case 1:
        w[0] += w[2];
        if (FIELD_GIMMICK_LIFT_IsLiftArrived(w)) {
            w[0] = w[1];
            if (w[4] == 0) {
                GFL_USE_PlaySeDefaultVolume(0x6cb);
            }
            (*b)++;
        }
        ((int *)FLD_EXP_OBJ_GetModelStatus(r, 0, 0))[1] = w[0];
        c = FIELDMAP_GetFieldPlayer((void *)s);
        FIELD_PLAYER_GetPos(c, (struct VecFx32 *)v);
        v[1] = w[0];
        FIELD_PLAYER_SetPos(c, v);
        break;
    case 2:
        if (w[4] != 0) {
            return 1;
        }
        if (w[3] != 0) {
            FIELD_CAMERA_SetTraceTarget(h, w[3]);
        }
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(r, 0, 0, 0), 0);
        (*b)++;
        break;
    case 3:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(r, 0, 0, 0))) {
            FIELD_GIMMICK_LIFT_ShowIdleAnime(r);
            return 1;
        }
        break;
    }
    return 0;
}
