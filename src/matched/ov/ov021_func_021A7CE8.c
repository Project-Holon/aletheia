/*
 * function: FIELD_GROUND_ANIME_MainA
 * address:  0x021A7CE8
 * packet:   pkt_ov021_021A7CE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Step machine over the Work step table: each state either stays or loads
 * the next step (FIELD_GROUND_ANIME_GetNextStep) and advances the index (FIELD_GROUND_ANIME_AdvanceStep).
 * Returns 1 once the current step is 8 and the handle reports done.
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   EVENT_MAPCHANGE_SetPlayerVanish  0x02185B88  thumb  ov020
 *   FIELD_CAMERA_HasDelay  0x0218F0F8  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   ENTRANCE_CAMERA_Setup  0x021BDCC8  thumb  ov021
 *   FIELD_SOUND_SYSTEM_PostFadeIn  0x02029D7C  thumb
 *   FIELD_GROUND_ANIME_CallEnterEvent  0x021A82D8  thumb  ov021
 *   FIELD_GROUND_ANIME_PlayBuildModelForward  0x021A8278  thumb  ov021
 *   FIELD_GROUND_ANIME_IsBuildModelDone  0x021A8244  thumb  ov021
 *   EVENT_FIELD_PROCLINK_StartObjAnim  0x021618E0  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   ENTRANCE_CAMERA_IsActive  0x021BDD40  thumb  ov021
 *   ENTRANCE_CAMERA_IsInstant  0x021BDD48  thumb  ov021
 *   FIELD_GROUND_ANIME_PlayBuildModelReverse  0x021A82A8  thumb  ov021
 *   ENTRANCE_CAMERA_Start  0x021BDD20  thumb  ov021
 *   FIELD_GROUND_ANIME_GetNextStep  0x021A81EC  thumb  ov021
 *   FIELD_GROUND_ANIME_AdvanceStep  0x021A8200  thumb  ov021
 *   FIELD_GROUND_ANIME_GetCurrentStep  0x021A81DC  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   ENTRANCE_CAMERA_Restore  0x021BDD34  thumb  ov021
 *   FIELD_CAMERA_ReloadSetting  0x0218E160  thumb  ov021
 *   ENTRANCE_CAMERA_Delete  0x021BDCB8  thumb  ov021
 *   FIELD_GROUND_ANIME_DeleteBuildModel  0x021A8234  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Args {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
} Args;

typedef struct Work {
    Args *f00;
    void *f04;
    void *f08;
    u8 f0C[0x18 - 0x0C];
    u16 f18;
} Work;

extern void *FIELDMAP_GetCamera(void *o);
extern unsigned int FIELDMAP_GetTaskManager(u8 *p);
typedef unsigned int   u32;
struct Evt;
struct Obj;
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void EVENT_MAPCHANGE_SetPlayerVanish(void *p, unsigned int v);
extern int FIELD_CAMERA_HasDelay(u8 *a);
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
struct Src;
extern void ENTRANCE_CAMERA_Setup(char *a, int *b);
extern void FIELD_SOUND_SYSTEM_PostFadeIn(void *a, void *b);
extern void FIELD_GROUND_ANIME_CallEnterEvent(void *a, struct Src **pp);
extern void FIELD_GROUND_ANIME_PlayBuildModelForward(Work *w);
extern int FIELD_GROUND_ANIME_IsBuildModelDone(u32 a);
extern void *EVENT_FIELD_PROCLINK_StartObjAnim(void *a, void *o);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int ENTRANCE_CAMERA_IsActive(void *p);
extern int ENTRANCE_CAMERA_IsInstant(struct Obj *o);
extern void FIELD_GROUND_ANIME_PlayBuildModelReverse(Work *w);
extern void ENTRANCE_CAMERA_Start(void *p);
extern u8 FIELD_GROUND_ANIME_GetNextStep(Work *w);
extern void FIELD_GROUND_ANIME_AdvanceStep(Work *w);
extern u8 FIELD_GROUND_ANIME_GetCurrentStep(u32 a);
extern int FIELD_TASK_MANAGER_IsEmpty(void *p);
extern void ENTRANCE_CAMERA_Restore(u8 *p);
extern int FIELD_CAMERA_ReloadSetting(u32 a);
extern void ENTRANCE_CAMERA_Delete(u8 *p);
extern void FIELD_GROUND_ANIME_DeleteBuildModel(Work *w);

int FIELD_GROUND_ANIME_MainA(void *task, int *state, Work *w)
{
    Args *a;
    void *a04;
    void *obj;
    void *a08;
    void *w04;
    void *h;
    void *d;

    a = w->f00;
    a04 = a->f04;
    obj = a->f0C;
    a08 = a->f08;
    w04 = w->f04;
    h = FIELDMAP_GetCamera(obj);
    d = (void *)FIELDMAP_GetTaskManager(obj);
    FIELDMAP_GetZoneId(obj);

    switch (*state) {
    case 0:
        EVENT_MAPCHANGE_SetPlayerVanish(obj, 1);
        if (FIELD_CAMERA_HasDelay(h) == 0) {
            *state = FIELD_GROUND_ANIME_GetNextStep(w);
            FIELD_GROUND_ANIME_AdvanceStep(w);
        } else {
            FIELD_CAMERA_EndDelay(h);
            *state = 9;
        }
        break;
    case 9:
        if (FIELD_CAMERA_IsDelayEnabled(h) == 0) {
            *state = FIELD_GROUND_ANIME_GetNextStep(w);
            FIELD_GROUND_ANIME_AdvanceStep(w);
        }
        break;
    case 1:
        ENTRANCE_CAMERA_Setup(w->f08, (int *)w->f0C);
        FIELD_SOUND_SYSTEM_PostFadeIn(w04, a08);
        FIELD_GROUND_ANIME_CallEnterEvent(task, (struct Src **)w);
        *state = FIELD_GROUND_ANIME_GetNextStep(w);
        FIELD_GROUND_ANIME_AdvanceStep(w);
        break;
    case 2:
        FIELD_GROUND_ANIME_PlayBuildModelForward(w);
        *state = FIELD_GROUND_ANIME_GetNextStep(w);
        FIELD_GROUND_ANIME_AdvanceStep(w);
        break;
    case 3:
        if (FIELD_GROUND_ANIME_IsBuildModelDone((u32)w) == 1) {
            *state = FIELD_GROUND_ANIME_GetNextStep(w);
            FIELD_GROUND_ANIME_AdvanceStep(w);
        }
        break;
    case 4:
        EVENT_MAPCHANGE_SetPlayerVanish(obj, 0);
        GAME_EVENT_CallEvent(task, EVENT_FIELD_PROCLINK_StartObjAnim(a04, obj));
        if (ENTRANCE_CAMERA_IsActive(w->f08) != 0 && ENTRANCE_CAMERA_IsInstant(w->f08) != 0) {
            *state = 10;
        } else {
            *state = FIELD_GROUND_ANIME_GetNextStep(w);
            FIELD_GROUND_ANIME_AdvanceStep(w);
        }
        break;
    case 6:
        FIELD_GROUND_ANIME_PlayBuildModelReverse(w);
        *state = FIELD_GROUND_ANIME_GetNextStep(w);
        FIELD_GROUND_ANIME_AdvanceStep(w);
        break;
    case 10:
        if (w->f18++ > 15) {
            *state = FIELD_GROUND_ANIME_GetNextStep(w);
            FIELD_GROUND_ANIME_AdvanceStep(w);
        }
        break;
    case 5:
        ENTRANCE_CAMERA_Start(w->f08);
        *state = FIELD_GROUND_ANIME_GetNextStep(w);
        FIELD_GROUND_ANIME_AdvanceStep(w);
        break;
    case 7:
        if (FIELD_GROUND_ANIME_IsBuildModelDone((u32)w) == 1) {
            *state = FIELD_GROUND_ANIME_GetNextStep(w);
            FIELD_GROUND_ANIME_AdvanceStep(w);
        }
        break;
    case 8:
        break;
    }

    if (FIELD_GROUND_ANIME_GetCurrentStep((u32)w) == 8 && FIELD_TASK_MANAGER_IsEmpty(d) != 0) {
        ENTRANCE_CAMERA_Restore(w->f08);
        FIELD_CAMERA_ReloadSetting((u32)h);
        ENTRANCE_CAMERA_Delete(w->f08);
        FIELD_GROUND_ANIME_DeleteBuildModel(w);
        return 1;
    }
    return 0;
}
