/*
 * function: SCRCMD_NETWORK_CommBattleEventMain
 * address:  0x0215F734
 * packet:   pkt_ov010_0215F734
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Step machine of an ov010 sub-sequence: the step comes from w->seq[*i]
 * through SCRCMD_NETWORK_AdvanceStep, loading ov180/ov181 as procs and ov205/ov182 as
 * tasks. Byte-correct first draft.
 * Former blocker (MATCH): ov205_id and ov182_id reach r1 of GAME_EVENT_CallProc, which
 * is not in match.py's OVERLAY_ID_CONSUMERS; d_021B9BA0 then fails its
 * ov182 hint for want of that overlay_id site. Same blocker as
 * SCRCMD_NETWORK_WifiProcEventMain.
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   GAMESYSTEM_SetAlwaysNetFlag  0x02012158  thumb
 *   FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent  0x02014554  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   func_02026454  0x02026454  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   SCRCMD_NETWORK_GetCommExitKind  0x0215F9C4  thumb  ov010
 *   SCRCMD_NETWORK_AdvanceStep  0x0215F9DC  thumb  ov010
 *   SCRCMD_NETWORK_SetupMiscSave  0x0215F9EC  thumb  ov010
 *   SCRIPT_SYS_RunRecoverScript  0x02158A20  thumb  ov010
 *   EVENT_FIELD_PROCLINK_CreateCommExitEvent  0x02161B90  thumb  ov010
 *   ov180_id       0x000000B4  data
 *   ov181_id       0x000000B5  data
 *   ov205_id       0x000000CD  data
 *   ov182_id       0x000000B6  data
 *   d_021B800C     0x021B800C  data  ov180
 *   d_021BAB24     0x021BAB24  data  ov181
 *   d_021B9E54     0x021B9E54  data  ov205
 *   d_021B9BA0     0x021B9BA0  data  ov182
 
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    void *sys;          /* 0x00 */
    void *f04;          /* 0x04 */
    u32 f08;            /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u8 f14[8];          /* 0x14 */
    u8 f1c[0x28 - 0x1C];/* 0x1C */
    u8 f28[8];          /* 0x28 */
    u8 f30[4];          /* 0x30 */
    u32 step;           /* 0x34 */
    u32 seq[16];        /* 0x38 */
    int timer;          /* 0x78 */
} Work;

struct Big;
struct Comm;
struct Ctx;
struct Evt;
struct IcaAnime;
struct Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern void GAME_EVENT_CallProc(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern void GAMESYSTEM_SetAlwaysNetFlag(char *p, unsigned int v);
extern int FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent(int a0, int a1);
extern void GFL_USE_FadeOutBgm(u32 v);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern u32 func_02026454(void *obj);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *sys, void *proc, u32 a, u32 b);
extern int SCRCMD_NETWORK_GetCommExitKind(void);
extern void SCRCMD_NETWORK_AdvanceStep(Work *w, u32 *i);
extern int SCRCMD_NETWORK_SetupMiscSave(int a0);
extern void SCRIPT_SYS_RunRecoverScript(int a, int v);
extern void *EVENT_FIELD_PROCLINK_CreateCommExitEvent(void *p, void *a1, int kind, int sub, int flag);
extern u8 ov180_id[];
extern u8 ov181_id[];
extern u8 ov205_id[];
extern u8 ov182_id[];
extern u8 d_021B800C[];
extern u8 d_021BAB24[];
extern u8 d_021B9E54[];
extern u8 d_021B9BA0[];

int SCRCMD_NETWORK_CommBattleEventMain(void *evt, u32 *i, Work *w)
{
    void *sys = w->sys;
    void *save;
    void *proc;

    GAME_DATA_GetSaveControl(w->f04);
    proc = GAMESYSTEM_GetFieldMap(w->sys);
    save = (void *)GAMESYSTEM_GetGameComm(w->sys);
    switch (w->step) {
    case 0:
        if (w->f08 == 1)
            SCRCMD_NETWORK_SetupMiscSave((int)w);
        GFL_USE_FadeOutBgm(30);
        SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 1:
        GAME_EVENT_CallEvent(evt, EVENT_FIELDMAP_CONTROL_StartFadeOut(sys, proc, 0, 0));
        SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 2:
        if (func_02026454(save))
            GAME_COMM_RequestExitNoCallback(save);
        SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 3:
        if (func_02026454(save) == 0)
            SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 4:
        GAME_EVENT_CallEvent(evt, (void *)FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent((int)sys, (int)proc));
        SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 5:
        GAMESYSTEM_CallProc(sys, (u32)ov180_id, d_021B800C, w->f1c);
        SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 6:
        if (GAMESYSTEM_GetProcStatus(sys) == 0)
            SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 7:
        GAMESYSTEM_CallProc(sys, (u32)ov181_id, d_021BAB24, w->f28);
        SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 8:
        if (GAMESYSTEM_GetProcStatus(sys) == 0)
            SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 9:
        GAME_EVENT_CallEvent(evt, EVENT_FIELD_PROCLINK_CreateCommExitEvent(sys, evt, SCRCMD_NETWORK_GetCommExitKind(), 0, 0));
        SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 10:
        SCRIPT_SYS_RunRecoverScript((int)sys, 4);
        SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 11:
        GAME_EVENT_CallProc(evt, (u32)ov205_id, (u32)d_021B9E54, (u32)w->f14);
        SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 12:
        if (w->timer > 60) {
            w->timer = 0;
            SCRCMD_NETWORK_AdvanceStep(w, i);
        }
        w->timer++;
        break;
    case 13:
        GAME_EVENT_CallProc(evt, (u32)ov182_id, (u32)d_021B9BA0, (u32)w->f30);
        GAMESYSTEM_SetAlwaysNetFlag(sys, 0);
        SCRCMD_NETWORK_AdvanceStep(w, i);
        break;
    case 14:
        return 1;
    case 15:
        return 0;
    }
    return 0;
}
