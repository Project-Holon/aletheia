/*
 * function: BSUBWAY_SCR_CmdDeleteWork
 * address:  0x021CA598
 * packet:   pkt_ov021_021CA598
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetCurrentEvent  0x02012ED8  thumb
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   BSUBWAY_SCR_DeleteWork  0x021C9B24  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Big;
struct Ctx;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *SCRIPT_WORK_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetCurrentEvent(struct Big *p);
extern void BSUBWAY_SCR_DeleteWork(u32 a, u8 *p);
int BSUBWAY_SCR_CmdDeleteWork(u32 a, u32 b)
{
    void *h = SCRCMD_WORK_GetScriptWork((void *)b);
    u32 x;
    SCRIPT_WORK_ResetFieldParam((int)h);
    x = (u32)SCRIPT_WORK_GetGameSystem(h);
    BSUBWAY_SCR_DeleteWork(x, GAME_DATA_GetCurrentEvent(GAMESYSTEM_GetGameData((const struct Ctx *)x)));
    return 0;
}
