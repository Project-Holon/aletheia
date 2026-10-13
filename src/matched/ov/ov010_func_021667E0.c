/*
 * function: SYMBOL_MAP_ScrCmdStartRecordTask
 * address: 0x021667E0
 * packet: pkt_ov010_021667E0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The returned task remains live as SCRIPT_SYS_CallEvent's second argument.
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetEventState 0x02012ED0 thumb
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SYMBOL_MAP_CreateRecordTask 0x0216666C thumb ov010
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 */
extern void *SCRCMD_WORK_GetScriptWork(void *);
extern void *SCRCMD_WORK_GetGameSystem(void *);
typedef unsigned short u16;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned char  u8;
struct Big;
extern u8 *GAME_DATA_GetEventState(struct Big *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SYMBOL_MAP_CreateRecordTask(void *, void *, void *);
extern void SCRIPT_SYS_CallEvent(void *, void *);

int SYMBOL_MAP_ScrCmdStartRecordTask(void *a, void *b)
{
    void *x = SCRCMD_WORK_GetScriptWork(b);
    void *y = SCRCMD_WORK_GetGameSystem(b);
    void **p;
    void *r;
    p = (void **)GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(y));
    r = SYMBOL_MAP_CreateRecordTask(y, *p, SCRIPT_WORK_ReadWorkPointer(a, b));
    if (r == 0)
        return 1;
    SCRIPT_SYS_CallEvent(x, r);
    return 1;
}
