/*
 * function: FIELD_GROUND_ANIME_MainB
 * address:  0x021A7F38
 * packet:   pkt_ov021_021A7F38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback installed by FIELD_GROUND_ANIME_CreateB: steps through the Work step
 * table like FIELD_GROUND_ANIME_MainA, returning 0x21 to run again in the same frame
 * when w->f38 is set, 1 when the last step finishes, 0 otherwise.
 *
 * symbols:
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   ENTRANCE_CAMERA_Setup  0x021BDCC8  thumb  ov021
 *   ENTRANCE_CAMERA_Start  0x021BDD20  thumb  ov021
 *   FIELD_GROUND_ANIME_PlayBuildModelForward  0x021A8278  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   ENTRANCE_CAMERA_IsActive  0x021BDD40  thumb  ov021
 *   ENTRANCE_CAMERA_IsInstant  0x021BDD48  thumb  ov021
 *   FIELD_GROUND_ANIME_IsBuildModelDone  0x021A8244  thumb  ov021
 *   FIELD_GROUND_ANIME_FreePlayerAcmd  0x021A7B10  thumb  ov021
 *   EVENT_FIELD_PROCLINK_StartObjAnim  0x021618E0  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_SOUND_SYSTEM_PostZoneBgmReplace  0x02029D44  thumb
 *   FIELD_GROUND_ANIME_ShouldPlayDoorSe  0x021A834C  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_GROUND_ANIME_CallExitEvent  0x021A8324  thumb  ov021
 *   ENTRANCE_CAMERA_Restore  0x021BDD34  thumb  ov021
 *   ENTRANCE_CAMERA_Delete  0x021BDCB8  thumb  ov021
 *   FIELD_GROUND_ANIME_DeleteBuildModel  0x021A8234  thumb  ov021
 *   FIELD_GROUND_ANIME_GetNextStep  0x021A81EC  thumb  ov021
 *   FIELD_GROUND_ANIME_AdvanceStep  0x021A8200  thumb  ov021
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
    u8 pad18[0x20 - 0x18];
    u16 f20;
    u8 pad22[0x45 - 0x22];
    u8 f45;
    u8 pad46[0x48 - 0x46];
    int f48;
} Args;

typedef struct Work {
    Args *f00;
    void *f04;
    void *f08;
    u8 f0C[0x18 - 0x0C];
    u16 f18;
    u8 pad1A[0x38 - 0x1A];
    int f38;
} Work;

extern unsigned int FIELDMAP_GetTaskManager(u8 *p);
extern void ENTRANCE_CAMERA_Setup(char *a, int *b);
extern void ENTRANCE_CAMERA_Start(void *p);
extern void FIELD_GROUND_ANIME_PlayBuildModelForward(Work *w);
extern int FIELD_TASK_MANAGER_IsEmpty(void *p);
extern int ENTRANCE_CAMERA_IsActive(void *p);
typedef unsigned int   u32;
struct Evt;
struct Obj;
extern int ENTRANCE_CAMERA_IsInstant(struct Obj *o);
extern int FIELD_GROUND_ANIME_IsBuildModelDone(u32 a);
extern int FIELD_GROUND_ANIME_FreePlayerAcmd(void *a);
extern void *EVENT_FIELD_PROCLINK_StartObjAnim(void *a, void *o);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void FIELD_SOUND_SYSTEM_PostZoneBgmReplace(u32 a, u32 b, u16 c, u8 d);
extern int FIELD_GROUND_ANIME_ShouldPlayDoorSe(Work *w);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void FIELD_GROUND_ANIME_CallExitEvent(void *task, Work *w);
extern void ENTRANCE_CAMERA_Restore(u8 *p);
extern void ENTRANCE_CAMERA_Delete(u8 *p);
extern void FIELD_GROUND_ANIME_DeleteBuildModel(Work *w);
extern u8 FIELD_GROUND_ANIME_GetNextStep(Work *w);
extern void FIELD_GROUND_ANIME_AdvanceStep(Work *w);

int FIELD_GROUND_ANIME_MainB(void *task, int *state, Work *w)
{
    Args *a;
    void *a04;
    void *a08;
    void *obj;
    void *w04;
    void *d;

    a = w->f00;
    a04 = a->f04;
    a08 = a->f08;
    obj = a->f0C;
    w04 = w->f04;
    d = (void *)FIELDMAP_GetTaskManager(obj);

    switch (*state) {
    case 0:
        ENTRANCE_CAMERA_Setup(w->f08, (int *)w->f0C);
        *state = FIELD_GROUND_ANIME_GetNextStep(w);
        FIELD_GROUND_ANIME_AdvanceStep(w);
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 1:
        ENTRANCE_CAMERA_Start(w->f08);
        *state = FIELD_GROUND_ANIME_GetNextStep(w);
        FIELD_GROUND_ANIME_AdvanceStep(w);
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 3:
        FIELD_GROUND_ANIME_PlayBuildModelForward(w);
        *state = FIELD_GROUND_ANIME_GetNextStep(w);
        FIELD_GROUND_ANIME_AdvanceStep(w);
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 2:
        if (FIELD_TASK_MANAGER_IsEmpty(d) == 0) {
            break;
        }
        if (ENTRANCE_CAMERA_IsActive(w->f08) != 0 && ENTRANCE_CAMERA_IsInstant(w->f08) != 0) {
            *state = 9;
        } else {
            *state = FIELD_GROUND_ANIME_GetNextStep(w);
            FIELD_GROUND_ANIME_AdvanceStep(w);
        }
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 4:
        if (FIELD_GROUND_ANIME_IsBuildModelDone((u32)w) == 1) {
            *state = FIELD_GROUND_ANIME_GetNextStep(w);
            FIELD_GROUND_ANIME_AdvanceStep(w);
            if (w->f38 != 0) {
                return 0x21;
            }
        }
        break;
    case 9:
        if (w->f18++ > 15) {
            *state = FIELD_GROUND_ANIME_GetNextStep(w);
            FIELD_GROUND_ANIME_AdvanceStep(w);
            if (w->f38 != 0) {
                return 0x21;
            }
        }
        break;
    case 5:
        FIELD_GROUND_ANIME_FreePlayerAcmd(obj);
        GAME_EVENT_CallEvent(task, EVENT_FIELD_PROCLINK_StartObjAnim(a04, obj));
        *state = FIELD_GROUND_ANIME_GetNextStep(w);
        FIELD_GROUND_ANIME_AdvanceStep(w);
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 6:
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace((u32)w04, (u32)a08, a->f20, a->f45);
        a->f48 = 1;
        *state = FIELD_GROUND_ANIME_GetNextStep(w);
        FIELD_GROUND_ANIME_AdvanceStep(w);
        break;
    case 7:
        if (FIELD_GROUND_ANIME_ShouldPlayDoorSe(w) != 0) {
            GFL_USE_PlaySeDefaultVolume(0x559);
        }
        FIELD_GROUND_ANIME_CallExitEvent(task, w);
        *state = FIELD_GROUND_ANIME_GetNextStep(w);
        FIELD_GROUND_ANIME_AdvanceStep(w);
        break;
    case 8:
        ENTRANCE_CAMERA_Restore(w->f08);
        ENTRANCE_CAMERA_Delete(w->f08);
        FIELD_GROUND_ANIME_DeleteBuildModel(w);
        return 1;
    }
    return 0;
}
