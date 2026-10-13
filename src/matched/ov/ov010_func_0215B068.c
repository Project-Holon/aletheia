/*
 * function: SCRCMD_WORK_CmdSetFixedEventFlag
 * address: 0x0215B068
 * packet: pkt_ov010_0215B068
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   SCRCMD_WORK_GetGameData 0x0215A5E4 thumb ov010
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_SetEventFlag 0x02014314 thumb
 */
typedef unsigned short u16;
extern void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void ZONEDATA_SetEventFlag(char *,int);
int SCRCMD_WORK_CmdSetFixedEventFlag(int a,int b)
{
    ZONEDATA_SetEventFlag((char *)GAME_DATA_GetEventWork(SCRCMD_WORK_GetGameData((void *)b)), 0x963);
    return 0;
}
