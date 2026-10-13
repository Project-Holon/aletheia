/*
 * function: EVENT_APPEAR_RunSpinZoomAlt
 * address:  0x021BF8EC
 * packet:   pkt_ov021_021BF8EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   EVENT_APPEAR_StartPlayerSpinAlt  0x021BF9F4  thumb  ov021
 *   EVENT_APPEAR_StartZoomOutAlt  0x021BF978  thumb  ov021
 *   EVENT_APPEAR_CreateFadeInAlt  0x021BFA18  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   EVENT_APPEAR_EndZoomOutAlt  0x021BF9E0  thumb  ov021
 *
 * Twin of EVENT_APPEAR_RunSpinZoom. FIELD_TASK_MANAGER_IsEmpty takes FIELDMAP_GetTaskManager's result (no
 * argument setup before its bl in case 4); that value, live across the
 * switch, is what puts the dispatch index in r1.
 */

extern void *FIELDMAP_GetCamera(void *o);
extern unsigned int FIELDMAP_GetTaskManager(unsigned char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Evt;
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
extern int EVENT_APPEAR_StartPlayerSpinAlt(void **a);
extern void EVENT_APPEAR_StartZoomOutAlt(void **q);
extern void *EVENT_APPEAR_CreateFadeInAlt(int *q);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_TASK_MANAGER_IsEmpty(void *p);
extern int EVENT_APPEAR_EndZoomOutAlt(void **a);

int EVENT_APPEAR_RunSpinZoomAlt(void *task, int *state, void **q)
{
    void *obj;
    void *h;
    void *d;

    obj = q[1];
    h = FIELDMAP_GetCamera(obj);
    d = (void *)FIELDMAP_GetTaskManager(obj);

    switch (*state) {
    case 0:
        FIELD_CAMERA_EndDelay(h);
        (*state)++;
        break;
    case 1:
        if (FIELD_CAMERA_IsDelayEnabled(h) == 0)
            (*state)++;
        break;
    case 2:
        if (q[23] == 0) {
            EVENT_APPEAR_StartPlayerSpinAlt(q);
            EVENT_APPEAR_StartZoomOutAlt(q);
        }
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(task, EVENT_APPEAR_CreateFadeInAlt((int *)q));
        (*state)++;
        break;
    case 4:
        if (FIELD_TASK_MANAGER_IsEmpty(d) != 0)
            (*state)++;
        break;
    case 5:
        EVENT_APPEAR_EndZoomOutAlt(q);
        return 1;
    }
    return 0;
}
