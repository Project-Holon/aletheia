/*
 * function: EVENT_DISAPPEAR_RunSpinZoom
 * address:  0x021C00C8
 * packet:   pkt_ov021_021C00C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   EVENT_DISAPPEAR_StartSpin  0x021C0140  thumb  ov021
 *   EVENT_DISAPPEAR_StartZoomIn  0x021C017C  thumb  ov021
 *   EVENT_DISAPPEAR_CreateFadeOut  0x021C01F8  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   EVENT_DISAPPEAR_EndZoomIn  0x021C01E4  thumb  ov021
 *
 * Same family as EVENT_APPEAR_RunSpinZoom: FIELD_TASK_MANAGER_IsEmpty takes FIELDMAP_GetTaskManager's result,
 * which keeps r0 live across the switch and puts the dispatch index in r1.
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern void EVENT_DISAPPEAR_StartSpin(u32 *p);
extern void EVENT_DISAPPEAR_StartZoomIn(u8 *p);
extern int EVENT_DISAPPEAR_CreateFadeOut(u32 *p);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_TASK_MANAGER_IsEmpty(void *p);
extern void func_020061E4(unsigned int a);
extern int EVENT_DISAPPEAR_EndZoomIn(void **a);

int EVENT_DISAPPEAR_RunSpinZoom(void *task, int *state, void **q)
{
    void *d;
    int t;

    d = (void *)FIELDMAP_GetTaskManager(q[1]);

    switch (*state) {
    case 0:
        EVENT_DISAPPEAR_StartSpin((u32 *)q);
        EVENT_DISAPPEAR_StartZoomIn((u8 *)q);
        (*state)++;
        break;
    case 1:
        t = (int)q[29];
        q[29] = (void *)(t + 1);
        if (t > 35) {
            GAME_EVENT_CallEvent(task, (struct Evt **)EVENT_DISAPPEAR_CreateFadeOut((u32 *)q));
            (*state)++;
            break;
        }
    case 2:
        if (FIELD_TASK_MANAGER_IsEmpty(d) != 0) {
            func_020061E4(0x559);
            (*state)++;
        }
        break;
    case 3:
        EVENT_DISAPPEAR_EndZoomIn(q);
        return 1;
    }
    return 0;
}
