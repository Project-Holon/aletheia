/*
 * function: FIELD_GIMMICK_LIFT_ELEVATOR_UpdateBigLift
 * address:  0x021F3FE8
 * packet:   pkt_ov043_021F3FE8
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * FIELDMAP_GetFog's result is bound to t before the A01FC call: passed inline,
 * the ternary fourth argument is evaluated before the call.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   FIELD_GIMMICK_LIFT_ELEVATOR_StartCameraShake  0x021F41B8  thumb  ov043
 *   FIELD_GIMMICK_LIFT_ELEVATOR_UpdateCameraShake  0x021F4210  thumb  ov043
 *   FIELDMAP_GetZoneFog  0x02188C68  thumb  ov021
 *   FIELD_ZONEFOG_GetFogOffset  0x021A03A4  thumb  ov021
 *   FIELD_ZONEFOG_GetFogSlope  0x021A03B8  thumb  ov021
 *   FIELDMAP_GetFog  0x02188C64  thumb  ov021
 *   FIELD_FOG_FADE_Init  0x021A01FC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
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
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GFL_USE_GetSeSlot(u32 a0);
extern void GFL_USE_StopSeSlot(int i);
extern void FIELD_GIMMICK_LIFT_ELEVATOR_StartCameraShake(int a0, int a1, int a2, int a3, u8 *s);
extern int FIELD_GIMMICK_LIFT_ELEVATOR_UpdateCameraShake(u8 *s);
extern u32 FIELDMAP_GetZoneFog(u8 *p);
extern int FIELD_ZONEFOG_GetFogOffset(int *p);
extern int FIELD_ZONEFOG_GetFogSlope(int *p);
extern u32 FIELDMAP_GetFog(u8 *p);
extern void FIELD_FOG_FADE_Init(u8 *p, u32 a, u32 b, u32 c);

void FIELD_GIMMICK_LIFT_ELEVATOR_UpdateBigLift(void *a)
{
    void *s;
    void *r;
    int *w;
    u32 h;
    int *q;
    int flag;
    u32 t;
    int x;
    int y;

    s = GAMESYSTEM_GetFieldMap((void *)a);
    r = (void *)FIELDMAP_GetExpObj(s);
    w = FIELDMAP_GetCommonWork(s, 1);
    h = (u32)FIELDMAP_GetCamera(s);
    q = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(s))), 7);
    if (w[0] != 5) {
        return;
    }
    if (q[6] == 0 && w[1] <= -0x230000) {
        q[6] = 1;
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(r, 0, 6, 0), 0);
        GFL_USE_PlaySeDefaultVolume(0x6cd);
        w[1] = -0x230000;
        w[6] = 1;
        ((u16 *)w)[14] = 0;
        ((u16 *)w)[15] = 0;
        w[16] = 1;
    }
    if (w[6] != 0) {
        switch (((u16 *)w)[15]) {
        case 0:
            FIELD_GIMMICK_LIFT_ELEVATOR_StartCameraShake((u8)w[0], w[3], 0, (u32)h, (u8 *)(w + 8));
            GFL_USE_PlaySeDefaultVolume(0x6cb);
            ((u16 *)w)[15]++;
            break;
        case 1:
            if (FIELD_GIMMICK_LIFT_ELEVATOR_UpdateCameraShake((u8 *)(w + 8))) {
                ((u16 *)w)[14]++;
                if (((u16 *)w)[14] >= 100) {
                    w[3] = -0x2000;
                    w[6] = 0;
                    GFL_USE_PlaySeDefaultVolume(0x6ca);
                }
            }
            break;
        }
    }
    if (w[15] != 0) {
        flag = 0;
        if (w[3] >= 0) {
            if (w[1] >= -0x2a0000) {
                t = FIELDMAP_GetZoneFog(s);
                flag = 1;
                x = FIELD_ZONEFOG_GetFogOffset((int *)t);
                y = FIELD_ZONEFOG_GetFogSlope((int *)t);
            }
        } else {
            if (w[1] <= -0x310000) {
                flag = 1;
                x = 0x7fdf;
                y = 9;
            }
        }
        if (flag) {
            t = FIELDMAP_GetFog(s);
            FIELD_FOG_FADE_Init((u8 *)t, x, y, w[3] == -0x2000 ? 0x20 : 0x10);
            w[15] = 0;
        }
    }
    if (w[16] != 0) {
        if (w[16] == 1) {
            w[16] = 2;
            return;
        }
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(r, 0, 6, 0))) {
            GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(0x6cd));
            w[16] = 0;
        }
    }
}
