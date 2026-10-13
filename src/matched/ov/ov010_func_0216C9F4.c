/*
 * function: NAMEIN_SETUP_RunSceneEvent
 * address:  0x0216C9F4
 * packet:   pkt_ov010_0216C9F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_CreateAnimEvent  0x02161824  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_ConsumeSpot  0x021AAABC  thumb  ov021
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_Start  0x021CF498  thumb  ov021
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   NAMEIN_SETUP_StartProcCallEvent  0x0216C9CC  thumb  ov010
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Ctx;
struct Evt;
extern void *EVENT_FIELD_PROCLINK_CreateAnimEvent(void *a, void *b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(void *a, u32 b);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern void EFFECT_ENCOUNT_ConsumeSpot(int);
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern void ENCEFF_Start(struct Ctx *c, u32 x, int idx);
extern int FIELD_STATUS_CreateFieldCloseEvent(int, int);
extern void *NAMEIN_SETUP_StartProcCallEvent(void *a, void *b, void *c);
extern void *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(void *a);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern void *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(void *a);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);

int NAMEIN_SETUP_RunSceneEvent(int a, int *st, int *o)
{
    int x = o[0];
    int y = o[1];
    switch (*st) {
    case 0:
        GAME_EVENT_CallEvent((struct Evt *)a, EVENT_FIELD_PROCLINK_CreateAnimEvent((void *)x, (void *)y));
        (*st)++;
        break;
    case 1:
        GAME_EVENT_CallEvent((struct Evt *)a, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask((void *)x, *(unsigned short *)(o[2] + 0x18)));
        (*st)++;
        break;
    case 2:
        EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount((u8 *)y));
        ENCEFF_Start((struct Ctx *)FIELDMAP_GetEncEff((unsigned char *)o[1]), a, 9);
        (*st)++;
        break;
    case 3:
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(x, y));
        (*st)++;
        break;
    case 4:
        GAME_EVENT_CallEvent((struct Evt *)a, NAMEIN_SETUP_StartProcCallEvent((void *)x, (void *)o[2], (void *)o[3]));
        (*st)++;
        break;
    case 5:
        GAME_EVENT_CallEvent((struct Evt *)a, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask((void *)x));
        (*st)++;
        break;
    case 6:
        GAME_EVENT_CallEvent((struct Evt *)a, FIELD_STATUS_CreateFieldOpenEvent((void *)x));
        (*st)++;
        break;
    case 7:
        GAME_EVENT_CallEvent((struct Evt *)a, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask((void *)x));
        (*st)++;
        break;
    case 8:
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)x, y, 0, 0, 1, 0, 0));
        (*st)++;
        break;
    case 9:
        return 1;
    default:
        return 1;
    }
    return 0;
}
