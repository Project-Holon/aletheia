/*
 * function: SCRCMD_WORK_CmdCheckMiscFlag
 * address: 0x0215AC3C
 * packet: pkt_ov010_0215AC3C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SCRCMD_WORK_GetGameData 0x0215A5E4 thumb ov010
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   BEACON_GetFlag 0x0200C234 thumb
 */
typedef unsigned short u16;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *,void *);
extern void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned int   u32;
struct Blk34;
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 BEACON_GetFlag(struct Blk34 *p, u32 bit);
int SCRCMD_WORK_CmdCheckMiscFlag(int a,int b)
{
    u16 *out = SCRIPT_WORK_ReadWorkPointer((void *)a,(void *)b);
    int k = SCRIPT_WORK_ReadWorkValue((void *)a,(void *)b);
    *out = BEACON_GetFlag(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData((void *)b)),k);
    return 0;
}
