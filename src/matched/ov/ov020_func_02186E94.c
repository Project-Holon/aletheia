/*
 * function: FIELD_WFBC_DATA_LOCAL_ScrCmdAddPoints
 * address: 0x02186E94
 * packet: pkt_ov020_02186E94
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero alignment bytes.
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRIPT_WORK_ResetFieldParam 0x02158F58 thumb ov010
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMusicalShotExtraData 0x020127F0 thumb
 *   FIELD_WFBC_DATA_LOCAL_AddValuePoints 0x021869BC thumb ov020
 * interface: 020127F0's body loads only r0, forwarding r0 through 0200A864/0200A898.
 */
struct Ctx;
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_GetMusicalShotExtraData(int a0);
typedef unsigned short u16;
extern void FIELD_WFBC_DATA_LOCAL_AddValuePoints(u16 *p);
int FIELD_WFBC_DATA_LOCAL_ScrCmdAddPoints(void *unused, void *p)
{
    FIELD_WFBC_DATA_LOCAL_AddValuePoints((void *)GAME_DATA_GetMusicalShotExtraData((int)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(*(void **)(SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork(p)) + 4)))));
    return 0;
}
