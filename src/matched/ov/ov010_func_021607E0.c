/*
 * function: EVENT_SHORTCUT_MENU_ProcEventMain
 * address:  0x021607E0
 * packet:   pkt_ov010_021607E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The fourteen-state task EVENT_SHORTCUT_MENU_CreateProcEvent creates. The procedure table at
 * 0x021712CC has 24-byte records; each pool word is the table plus the
 * field offset.
 *
 * symbols:
 *   d_021712CC     0x021712CC  data
 *   EVENT_SHORTCUT_MENU_CallSuspendHook  0x02160A64  thumb  ov010
 *   EVENT_SHORTCUT_MENU_CallResumeHook  0x02160A4C  thumb  ov010
 *   EVENT_SHORTCUT_MENU_CallExitHook  0x02160A7C  thumb  ov010
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_SetBgMode  0x02188DA0  thumb  ov021
 *   FIELDMAP_ResetBgAffineShowMsg  0x02188DB0  thumb  ov021
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Owner {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 pad08[8];
    void *f10;          /* 0x10 */
    u8 pad14[0x10];
    u32 result;         /* 0x24 */
} Owner;

typedef struct Callbacks {
    void *fn[3];
    u32 arg;
    void *ctx;
} Callbacks;

typedef struct Task {
    u16 id;             /* 0x00 */
    u8 pad02[2];
    u32 proc;           /* 0x04 */
    u32 prev;           /* 0x08 */
    u32 next;           /* 0x0C */
    u32 state;          /* 0x10 */
    void *handle;       /* 0x14 */
    Owner *owner;       /* 0x18 */
    void *work;         /* 0x1C */
    Callbacks cb;       /* 0x20 */
} Task;

typedef struct Proc {
    void *f00;                                      /* 0x00 */
    void *f04;                                      /* 0x04 */
    void *(*init)(Task *t, void *arg, u32 prev, void *work); /* 0x08 */
    u32 (*finish)(Task *t, void *work);             /* 0x0C */
    void (*start)(Task *t, void *arg);              /* 0x10 */
    void (*exit)(void *work);                       /* 0x14 */
} Proc;

extern Proc d_021712CC[];

extern int EVENT_SHORTCUT_MENU_CallSuspendHook(Callbacks *c);
extern int EVENT_SHORTCUT_MENU_CallResumeHook(Callbacks *c);
extern int EVENT_SHORTCUT_MENU_CallExitHook(Callbacks *c);
struct IcaAnime;
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
struct Ctx;
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void FIELDMAP_SetBgMode(void);
extern void FIELDMAP_ResetBgAffineShowMsg(u8 *a);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern u32 func_020307B0(void *p);

int EVENT_SHORTCUT_MENU_ProcEventMain(void *evt, u32 *state, Task *t)
{
    u32 v;
    void *work;

    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        v = t->state;
        if (v <= 1) {
            *state = 2;
        } else if (v == 4) {
            if (d_021712CC[t->proc].start == 0)
                *state = 6;
            else
                *state = 3;
        } else if (v == 3) {
            t->owner->result = 3;
            *state = 2;
        } else if (v == 2) {
            t->owner->result = 2;
            *state = 2;
        }
        break;
    case 2:
        v = t->state;
        if (v == 0)
            t->owner->result = 0;
        else if (v == 1)
            t->owner->result = 1;
        return 1;
    case 3:
        if (EVENT_SHORTCUT_MENU_CallSuspendHook(&t->cb) == 0)
            break;
        d_021712CC[t->proc].start(t, t->owner->f10);
        *state = 4;
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        if (t->state == 0) {
            if (EVENT_SHORTCUT_MENU_CallResumeHook(&t->cb) == 0)
                break;
            *state = 1;
        } else {
            *state = 1;
        }
        break;
    case 6:
        GAME_EVENT_CallEvent(evt, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut(t->owner->f00, (int)t->owner->f04, 0, 0));
        *state = 7;
        break;
    case 7:
        if (EVENT_SHORTCUT_MENU_CallSuspendHook(&t->cb) == 0)
            break;
        GAME_EVENT_CallEvent(evt, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)t->owner->f00, (int)t->owner->f04));
        *state = 11;
        break;
    case 8:
        EVENT_SHORTCUT_MENU_CallExitHook(&t->cb);
        GAME_EVENT_CallEvent(evt, FIELD_STATUS_CreateFieldOpenEvent(t->owner->f00));
        *state = 9;
        break;
    case 9:
        work = GAMESYSTEM_GetFieldMap(t->owner->f00);
        t->owner->f04 = work;
        FIELDMAP_SetBgMode();
        FIELDMAP_ResetBgAffineShowMsg(t->owner->f04);
        *state = 10;
        break;
    case 10:
        if (EVENT_SHORTCUT_MENU_CallResumeHook(&t->cb) == 0)
            break;
        GAME_EVENT_CallEvent(evt, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn(t->owner->f00, (int)t->owner->f04, 0, 0, 0, 0, 0));
        *state = 1;
        break;
    case 11:
        work = d_021712CC[t->proc].init(t, t->owner->f10, t->prev, t->work);
        if (t->work != 0) {
            d_021712CC[t->prev].exit(t->work);
            t->work = 0;
        }
        t->work = work;
        if (d_021712CC[t->proc].f04 == 0)
            break;
        GAMESYSTEM_CallProc(t->owner->f00, (u32)d_021712CC[t->proc].f00, d_021712CC[t->proc].f04, work);
        *state = 12;
        break;
    case 12:
        if (GAMESYSTEM_GetProcStatus(t->owner->f00) != 0)
            break;
        *state = 13;
        break;
    case 13:
        t->state = d_021712CC[t->proc].finish(t, t->work);
        v = t->state;
        if (v == 0)
            t->owner->result = 0;
        else if (v == 1)
            t->owner->result = 1;
        else if (v == 3)
            t->owner->result = 3;
        else if (v == 2)
            t->owner->result = 2;
        if (t->state == 4) {
            t->prev = t->proc;
            t->proc = t->next;
            *state = 11;
        } else {
            if (t->work != 0) {
                func_020307B0(t->work);
                t->work = 0;
            }
            *state = 8;
        }
        break;
    }
    return 0;
}
