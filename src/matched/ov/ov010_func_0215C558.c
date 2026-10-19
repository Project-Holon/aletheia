/*
 * function: SCRCMD_PROC_AddMiscPoints
 * address: 0x0215C558
 * packet: pkt_ov010_0215C558
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   SCRCMD_WORK_GetGameData 0x0215A5E4 thumb ov010
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   BEACON_AddMoney 0x0200C278 thumb
 */
typedef unsigned short u16;
extern void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned int   u32;
struct Blk34;
struct SaveBlock;
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 BEACON_AddMoney(struct Blk34 *p, u32 v);
int SCRCMD_PROC_AddMiscPoints(int a,int b)
{
    void *p = SCRCMD_WORK_GetGameData((void *)b);
    int k;
    GAME_DATA_GetMyPlayerWork(p);
    k = SCRIPT_WORK_ReadWorkValue((void *)a,(void *)b);
    BEACON_AddMoney(GAME_DATA_GetMiscSave(p),k);
    return 0;
}
