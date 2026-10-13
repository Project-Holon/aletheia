/*
 * function: SCRCMD_NETWORK_WifiProcEventMain
 * address:  0x0215FA54
 * packet:   pkt_ov010_0215FA54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Proc main of an ov010 sub-sequence: 11 states that push the child
 * tasks, load ov122 and ov172, and pick the closing screen from w->f28.
 * Byte-correct (first draft plus one lever: in state 9 the `f28 == 2`
 * test and the call share an else block ending in the one `*state = 10`
 * store, so that store is the copy the other arms cross-jump to).
 * Former blocker (MATCH): the pooled 0xAC is ov172_id passed in r1 to
 * GAME_EVENT_CallProc, which is not in match.py's OVERLAY_ID_CONSUMERS
 * (GAME_EVENT_CallProc stores r1 in a task descriptor, src/matched/GAME_EVENT_CallProc.c),
 * so the ABS32 at +0x190 has no witness.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   GAME_DATA_SetSubscreenType  0x020129B8  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_IsTransition  0x02026460  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   INTRUDE_SUBDISP_CreateTownWarpEvent  0x0217CE08  thumb
 *   INTRUDE_SUBDISP_CreateGuideScriptEvent  0x0217CDBC  thumb
 *   EVENT_COMM_COMMON_CreateReturnPalaceEvent  0x0217FA24  thumb
 *   ov122_id       0x0000007A  data
 *   ov172_id       0x000000AC  data
 *   d_021D5764     0x021D5764  data  ov122
 *   d_021C7240     0x021C7240  data
 
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    void *sys;          /* 0x00 */
    u8 pad04[0x0C - 0x04];
    u8 f0c[0x1C - 0x0C];/* 0x0C */
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
    u32 f24;            /* 0x24 */
    u32 f28;            /* 0x28 */
} Work;

struct Comm;
struct Ctx;
struct Evt;
struct IcaAnime;
struct Obj;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern void GAME_EVENT_CallProc(struct Obj *obj, u32 a1, u32 a2, u32 a3);
struct BigObj;
extern void GAME_DATA_SetSubscreenType(struct BigObj *p, u32 v);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *sys);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 h, u32 v);
extern void GFL_USE_FadeInBgmFull(u32 v);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern u32 GAME_COMM_GetKind(void *obj);
extern u32 GAME_COMM_IsTransition(void *obj);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *sys, void *proc, u32 a, u32 b);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void *INTRUDE_SUBDISP_CreateTownWarpEvent(void *sys, void *proc, u32 a, u32 b);
extern void *INTRUDE_SUBDISP_CreateGuideScriptEvent(void *sys);
extern void *EVENT_COMM_COMMON_CreateReturnPalaceEvent(void *sys);
extern u8 ov122_id[];
extern u8 ov172_id[];
extern u8 d_021D5764[];
extern u8 d_021C7240[];

int SCRCMD_NETWORK_WifiProcEventMain(void *evt, u32 *state, Work *w)
{
    void *sys = w->sys;
    void *save = (void *)GAMESYSTEM_GetGameComm(sys);
    void *ctx = GAMESYSTEM_GetGameData(sys);
    void *proc = GAMESYSTEM_GetFieldMap(sys);

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(evt, EVENT_FIELDMAP_CONTROL_StartFadeOut(sys, proc, 0, 0));
        (*state)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(evt, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)sys, (int)proc));
        *state = 2;
        break;
    case 2:
        (*state)++;
    case 3:
        GAMESYSTEM_CallProc(sys, (u32)ov122_id, d_021D5764, w);
        (*state)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(sys) != 0)
            break;
        switch (w->f20) {
        case 0:
            if (INTRUDE_COMM_GetWorkIfRunning((int)save) && w->f28 == 2)
                GAME_DATA_SetSubscreenType(ctx, 3);
            *state = 6;
            break;
        case 1:
            w->f24 = GFL_USE_GetBgmNo();
            GAME_EVENT_CallProc(evt, (u32)ov172_id, (u32)d_021C7240, (u32)w->f0c);
            *state = 5;
            break;
        default:
            *state = 6;
            break;
        }
        break;
    case 5:
        if (GAMESYSTEM_GetProcStatus(sys) != 0)
            break;
        GFL_USE_CancelChangeAndPlayBgm(w->f24, 0xFFFF);
        GFL_USE_FadeInBgmFull(60);
        *state = 6;
        break;
    case 6:
        w->f1c = 0;
        (*state)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(evt, FIELD_STATUS_CreateFieldOpenEvent(sys));
        (*state)++;
        break;
    case 8:
        GAME_EVENT_CallEvent(evt, EVENT_FIELDMAP_CONTROL_StartFadeIn(sys, proc, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 9:
        if (w->f20 == 0) {
            if (w->f28 == 0) {
                if (GAME_COMM_IsTransition(save))
                    break;
                if (GAME_COMM_GetKind(save)) {
                    GAME_COMM_RequestExitNoCallback(save);
                    break;
                }
                GAME_EVENT_CallEvent(evt, INTRUDE_SUBDISP_CreateTownWarpEvent(sys, proc, 0x117, 0));
                *state = 10;
            } else if (w->f28 == 3) {
                GAME_EVENT_CallEvent(evt, EVENT_COMM_COMMON_CreateReturnPalaceEvent(sys));
                *state = 10;
            } else {
                if (w->f28 != 2)
                    GAME_EVENT_CallEvent(evt, INTRUDE_SUBDISP_CreateGuideScriptEvent(sys));
                *state = 10;
            }
        } else {
            *state = 10;
        }
        break;
    case 10:
        return 1;
    }
    return 0;
}
