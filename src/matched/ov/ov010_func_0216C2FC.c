/*
 * function: NAMEIN_SETUP_RunLandEvent
 * address:  0x0216C2FC
 * packet:   pkt_ov010_0216C2FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Seven-state proc of a field event in ov010: animate the actor until it
 * lands on the grid, push the result screen with a fixed Param, then
 * settle the ov050 gimmick and drop the object back to the ground height.
 * First draft; the 0x021F37xx callees are declared ov050, the only
 * overlay that labels all six.
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   ICA_ANIME_CreateFull  0x020114D0  thumb
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   NAMEIN_SETUP_StepLandAnim  0x0216C270  thumb  ov010
 *   NAMEIN_SETUP_SyncObjHeightToAnim  0x0216C280  thumb  ov010
 *   NAMEIN_SETUP_SnapObjToGrid  0x0216C2A4  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   GIMMICK49_InitModels  0x021F3714  thumb  ov050
 *   GIMMICK50_ShowModel1  0x021F37B8  thumb  ov050
 *   GIMMICK50_IsModel0AnimeDone  0x021F3758  thumb  ov050
 *   GIMMICK50_IsModel1AnimeDone  0x021F3808  thumb  ov050
 *   GIMMICK50_StopModel0Anime  0x021F3744  thumb  ov050
 *   GIMMICK50_HideModel1  0x021F3788  thumb  ov050
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   FIELD_CAMERA_CreateShakeTask  0x021D2D50  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_020061E4  0x020061E4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Param {
    u16 f00;            /* 0x00 */
    u16 f02;            /* 0x02 */
    u16 f04;            /* 0x04 */
    u16 f06;            /* 0x06 */
    u16 f08;            /* 0x08 */
    u16 f0a;            /* 0x0A */
    u16 f0c;            /* 0x0C */
    u8 f0e;             /* 0x0E */
    u8 f0f;             /* 0x0F */
    u32 f10;            /* 0x10 */
    u32 f14;            /* 0x14 */
} Param;

typedef struct Work {
    u16 f00;            /* 0x00 */
    void *sys;          /* 0x04 */
    void *field;        /* 0x08 */
    void *f0c;          /* 0x0C */
    void *anim;         /* 0x10 */
} Work;

struct Evt;
struct IcaAnime;
extern int FIELDMAP_GetExpObj(int *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *ICA_ANIME_CreateFull(u32 heap, u32 a1, u32 a2);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern int NAMEIN_SETUP_StepLandAnim(Work *w);
extern void *NAMEIN_SETUP_SyncObjHeightToAnim(void *p);
extern void NAMEIN_SETUP_SnapObjToGrid(Work *w);
extern void FLDMMDL_MOVE_GetMapHeight(void *a, VecFx32 *v, fx32 *y);
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
extern void GIMMICK49_InitModels(int *p);
extern void GIMMICK50_ShowModel1(int a);
extern int GIMMICK50_IsModel0AnimeDone(int *p);
extern int GIMMICK50_IsModel1AnimeDone(int *p);
extern void GIMMICK50_StopModel0Anime(int *p);
extern void GIMMICK50_HideModel1(int *p);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void *FIELD_CAMERA_CreateShakeTask(void *sys, Param *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern int GFL_USE_GetSeSlot(u32 a0);
extern void func_020061F8(int i);
extern void func_020061E4(u32 se);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int NAMEIN_SETUP_RunLandEvent(void *evt, u32 *state, Work *w)
{
    Param p;
    VecFx32 v;
    fx32 y;
    int done;
    void *q;
    void *a;

    FIELDMAP_GetExpObj(w->field);
    switch (*state) {
    case 0:
        w->anim = ICA_ANIME_CreateFull(w->f00, 0x9D, 0x19);
        NAMEIN_SETUP_SyncObjHeightToAnim(w);
        NAMEIN_SETUP_SnapObjToGrid(w);
        FIELD_CAMERA_EndDelay(w->f0c);
        (*state)++;
        break;
    case 1:
        if (FIELD_CAMERA_IsDelayEnabled(w->f0c) == 0)
            (*state)++;
        break;
    case 2:
        GIMMICK49_InitModels(w->field);
        GIMMICK50_ShowModel1((int)w->field);
        GAME_EVENT_CallEvent(evt, EVENT_FIELDMAP_CONTROL_StartFadeIn(w->sys, w->field, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 3:
        done = NAMEIN_SETUP_StepLandAnim(w);
        if (done == 0) {
            NAMEIN_SETUP_SyncObjHeightToAnim(w);
            NAMEIN_SETUP_SnapObjToGrid(w);
        }
        if (done != 0) {
            ICA_ANIME_Delete(w->anim);
            func_020061F8(GFL_USE_GetSeSlot(1953));
            func_020061E4(1775);
            p.f00 = 2;
            p.f02 = 0;
            p.f10 = 3;
            p.f0f = 2;
            p.f0e = 2;
            p.f14 = 0;
            p.f04 = 0;
            p.f06 = 1;
            p.f08 = 0;
            p.f0a = 0;
            p.f0c = 2;
            GAME_EVENT_CallEvent(evt, FIELD_CAMERA_CreateShakeTask(w->sys, &p));
            (*state)++;
        }
        break;
    case 4:
        if (GIMMICK50_IsModel0AnimeDone(w->field) && GIMMICK50_IsModel1AnimeDone(w->field)) {
            GIMMICK50_StopModel0Anime(w->field);
            GIMMICK50_HideModel1(w->field);
            (*state)++;
        }
        break;
    case 5:
        q = FIELDMAP_GetFieldPlayer(w->field);
        a = FIELD_PLAYER_GetMmdl(q);
        FIELD_PLAYER_GetPos(q, &v);
        FLDMMDL_MOVE_GetMapHeight(a, &v, &y);
        v.y = y;
        FIELD_PLAYER_SetPos(q, &v);
        (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}
