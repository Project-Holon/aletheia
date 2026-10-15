/*
 * function: BSUBWAY_SCR_WaitCommSend
 * address:  0x021CB6DC
 * packet:   pkt_ov021_021CB6DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task step: resolves the field's current map object and reports whether its fade has finished.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetCurrentEvent  0x02012ED8  thumb
 *   BSUBWAY_COMM_SendData  0x02167CB4  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetGameSystem(void *p);
struct Big;
struct Ctx;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetCurrentEvent(struct Big *p);
extern int BSUBWAY_COMM_SendData(struct Obj *o);

int BSUBWAY_SCR_WaitCommSend(void *task, void *p)
{
    if (BSUBWAY_COMM_SendData(GAME_DATA_GetCurrentEvent(GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(p))))) == 1)
        return 1;
    return 0;
}
