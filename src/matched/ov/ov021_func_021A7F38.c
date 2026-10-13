/*
 * function: func_021A7F38
 * address:  0x021A7F38
 * packet:   pkt_ov021_021A7F38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback installed by func_021A7E3C: steps through the Work step
 * table like func_021A7CE8, returning 0x21 to run again in the same frame
 * when w->f38 is set, 1 when the last step finishes, 0 otherwise.
 *
 * symbols:
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   ENTRANCE_CAMERA_Setup  0x021BDCC8  thumb  ov021
 *   ENTRANCE_CAMERA_Start  0x021BDD20  thumb  ov021
 *   func_021A8278  0x021A8278  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   ENTRANCE_CAMERA_IsActive  0x021BDD40  thumb  ov021
 *   ENTRANCE_CAMERA_IsInstant  0x021BDD48  thumb  ov021
 *   func_021A8244  0x021A8244  thumb  ov021
 *   func_021A7B10  0x021A7B10  thumb  ov021
 *   EVENT_FIELD_PROCLINK_StartObjAnim  0x021618E0  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_SOUND_SYSTEM_PostZoneBgmReplace  0x02029D44  thumb
 *   func_021A834C  0x021A834C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021A8324  0x021A8324  thumb  ov021
 *   ENTRANCE_CAMERA_Restore  0x021BDD34  thumb  ov021
 *   ENTRANCE_CAMERA_Delete  0x021BDCB8  thumb  ov021
 *   func_021A8234  0x021A8234  thumb  ov021
 *   func_021A81EC  0x021A81EC  thumb  ov021
 *   func_021A8200  0x021A8200  thumb  ov021
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
extern void func_021A8278(Work *w);
extern int FIELD_TASK_MANAGER_IsEmpty(void *p);
extern int ENTRANCE_CAMERA_IsActive(void *p);
typedef unsigned int   u32;
struct Evt;
struct Obj;
extern int ENTRANCE_CAMERA_IsInstant(struct Obj *o);
extern int func_021A8244(u32 a);
extern int func_021A7B10(void *a);
extern void *EVENT_FIELD_PROCLINK_StartObjAnim(void *a, void *o);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void FIELD_SOUND_SYSTEM_PostZoneBgmReplace(u32 a, u32 b, u16 c, u8 d);
extern int func_021A834C(Work *w);
extern void func_020061E4(u32 a);
extern void func_021A8324(void *task, Work *w);
extern void ENTRANCE_CAMERA_Restore(u8 *p);
extern void ENTRANCE_CAMERA_Delete(u8 *p);
extern void func_021A8234(Work *w);
extern u8 func_021A81EC(Work *w);
extern void func_021A8200(Work *w);

int func_021A7F38(void *task, int *state, Work *w)
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
        *state = func_021A81EC(w);
        func_021A8200(w);
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 1:
        ENTRANCE_CAMERA_Start(w->f08);
        *state = func_021A81EC(w);
        func_021A8200(w);
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 3:
        func_021A8278(w);
        *state = func_021A81EC(w);
        func_021A8200(w);
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
            *state = func_021A81EC(w);
            func_021A8200(w);
        }
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 4:
        if (func_021A8244((u32)w) == 1) {
            *state = func_021A81EC(w);
            func_021A8200(w);
            if (w->f38 != 0) {
                return 0x21;
            }
        }
        break;
    case 9:
        if (w->f18++ > 15) {
            *state = func_021A81EC(w);
            func_021A8200(w);
            if (w->f38 != 0) {
                return 0x21;
            }
        }
        break;
    case 5:
        func_021A7B10(obj);
        GAME_EVENT_CallEvent(task, EVENT_FIELD_PROCLINK_StartObjAnim(a04, obj));
        *state = func_021A81EC(w);
        func_021A8200(w);
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 6:
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace((u32)w04, (u32)a08, a->f20, a->f45);
        a->f48 = 1;
        *state = func_021A81EC(w);
        func_021A8200(w);
        break;
    case 7:
        if (func_021A834C(w) != 0) {
            func_020061E4(0x559);
        }
        func_021A8324(task, w);
        *state = func_021A81EC(w);
        func_021A8200(w);
        break;
    case 8:
        ENTRANCE_CAMERA_Restore(w->f08);
        ENTRANCE_CAMERA_Delete(w->f08);
        func_021A8234(w);
        return 1;
    }
    return 0;
}
