/*
 * function: SCRCMD_WORK_CmdSetBoxFlags
 * address: 0x0215B084
 * packet: pkt_ov010_0215B084
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SCRCMD_WORK_GetGameData 0x0215A5E4 thumb ov010
 *   GAME_DATA_GetBoxManager 0x0201293C thumb
 *   func_02007A68 0x02007A68 thumb
 */
typedef unsigned short u16;
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
extern void func_02007A68(void *save, u32 bits);
int SCRCMD_WORK_CmdSetBoxFlags(int a,int b)
{
    int k = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int p = GAME_DATA_GetBoxManager(SCRCMD_WORK_GetGameData((void *)b));
    if ((u16)(k + 0xFFFF) <= 1) func_02007A68((void *)p,k);
    return 0;
}
