/*
 * function: SCRCMD_WORK_CmdCheckLastBattleResultA
 * address: 0x0215B3DC
 * packet: pkt_ov010_0215B3DC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRCMD_WORK_GetGameData 0x0215A5E4 thumb ov010
 *   GAME_DATA_GetLastBattleResult 0x02012A44 thumb
 *   EVENT_BATTLE_IsResultSilent 0x0216EFA8 thumb ov010
 */
typedef unsigned short u16;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetLastBattleResult(const struct BigObj *p);
extern int EVENT_BATTLE_IsResultSilent(int,int);
int SCRCMD_WORK_CmdCheckLastBattleResultA(int a,int b)
{
    u16 *out = SCRIPT_WORK_ReadWorkPointer((void *)a,(void *)b);
    int z = 1;
    if (EVENT_BATTLE_IsResultSilent(GAME_DATA_GetLastBattleResult(SCRCMD_WORK_GetGameData((void *)b)),1) == 1) *out = 0; else *out = z;
    return 0;
}
