/*
 * function: INTRUDE_LINK_EventMain
 * address:  0x021766F0
 * packet:   pkt_ov011_021766F0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Lever: case 1 forwards GAMESYSTEM_GetFieldMap's live r0 result into
 * FIELDMAP_GetEncEff(unsigned char *); the matched body reads p + 0x13C.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_Start  0x021CF498  thumb  ov021
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   sIntrudeLinkProcTable     0x02176FCC  data  ov011  a4
 */

typedef unsigned int u32;

extern char sIntrudeLinkProcTable[];
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
typedef unsigned char  u8;
struct Evt;
struct Obj;
extern void *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(void *a, u32 b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int  FIELDMAP_GetEncEff(unsigned char *p);
extern void ENCEFF_Start(struct Ctx *c, u32 x, int idx);
extern int  FIELD_STATUS_CreateFieldCloseEvent(int a, int b);
extern void GAME_EVENT_CallProc(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern void *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(void *a);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern void *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(void *a);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);

int INTRUDE_LINK_EventMain(void *a, u32 *p, int *q)
{
    int sv;

    sv = (int)GAMESYSTEM_GetFieldMap((const struct Ctx *)q[0]);
    switch (*p) {
    case 0:
        GAME_EVENT_CallEvent(a, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask((void *)q[0], 0x490));
        (*p)++;
        break;
    case 1:
        ENCEFF_Start((struct Ctx *)FIELDMAP_GetEncEff((unsigned char *)sv), (u32)a, 5);
        (*p)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(a, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(q[0], sv));
        (*p)++;
        break;
    case 3:
        GAME_EVENT_CallProc(a, -1, (u32)sIntrudeLinkProcTable, q[1]);
        (*p)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(a, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask((void *)q[0]));
        (*p)++;
        break;
    case 5:
        GAME_EVENT_CallEvent(a, FIELD_STATUS_CreateFieldOpenEvent((void *)q[0]));
        (*p)++;
        break;
    case 6:
        GAME_EVENT_CallEvent(a, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask((void *)q[0]));
        (*p)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(a, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)q[0], sv, 0, 0, 1, 0, 0));
        (*p)++;
        break;
    default:
        return 1;
    }
    return 0;
}
