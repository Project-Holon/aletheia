/*
 * function: func_0215739C
 * address:  0x0215739C
 * packet:   pkt_ov010_0215739C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback of func_02157450: a 10-state sequence that pushes the
 * field-effect child tasks (the ov008 effect runner gets the effect
 * object, its direction record and a zero word) and returns 1 when done.
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   BTL_SETUP_FreeSlots  0x020130DC  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   EVENT_BATTLE_REC_SAVE_Start  0x021550A0  thumb  ov008
 *   ov008_id       0x00000008  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u8 pad00[0x18];
    u16 f18;            /* 0x18 */
} Obj;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    Obj f08;            /* 0x08 */
    u8 pad[0xF8 - 0x08 - sizeof(Obj)];
    void *fF8;          /* 0xF8 */
} Work;

typedef struct Args {
    Obj *obj;
    void *sub;
    u32 zero;
} Args;

extern u8 ov008_id[];

struct Evt;
extern void *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(void *a, u32 b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
struct Desc;
extern struct Desc *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void BTL_SETUP_FreeSlots(Obj *o);
extern void *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(void *h);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *h);
extern void *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(void *h);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *EVENT_BATTLE_REC_SAVE_Start(void *a, const int *p);

int func_0215739C(void *evt, u32 *state, Work *w)
{
    void *h = w->f00;

    switch (*state) {
    case 0:
        *state = 3;
        break;
    case 1:
    case 2:
        break;
    case 3:
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(h, w->f08.f18));
        (*state)++;
        break;
    case 4: {
        Args a;

        a.obj = &w->f08;
        a.sub = w->fF8;
        a.zero = 0;
        GAME_EVENT_CallEvent(evt, (struct Evt **)GAME_EVENT_CreateOverlayEvent(h, (u32)ov008_id, (u32 (*)(void *, u32))EVENT_BATTLE_REC_SAVE_Start, (u32)(&a)));
        (*state)++;
        break;
    }
    case 5:
        BTL_SETUP_FreeSlots(&w->f08);
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(h));
        (*state)++;
        break;
    case 6:
        GAME_EVENT_CallEvent(evt, FIELD_STATUS_CreateFieldOpenEvent(h));
        (*state)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(evt, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn(h, (int)w->f04, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 8:
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(h));
        (*state)++;
        break;
    case 9:
        return 1;
    }
    return 0;
}
