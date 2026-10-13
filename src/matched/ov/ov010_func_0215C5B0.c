/*
 * function: SCRCMD_PROC_CheckMiscValueReached
 * address: 0x0215C5B0
 * packet: pkt_ov010_0215C5B0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SCRCMD_WORK_GetGameData 0x0215A5E4 thumb ov010
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   func_0200C274 0x0200C274 thumb
 */
typedef unsigned short u16;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
typedef unsigned int   u32;
struct Blk34;
struct SaveBlock;
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 func_0200C274(struct Blk34 *p);

int SCRCMD_PROC_CheckMiscValueReached(void *a, void *b)
{
    u16 *p = SCRIPT_WORK_ReadWorkPointer(a, b);
    unsigned int v = SCRIPT_WORK_ReadWorkValue(a, b);
    void *q = SCRCMD_WORK_GetGameData(b);
    GAME_DATA_GetMyPlayerWork(q);
    *p = v <= func_0200C274(GAME_DATA_GetMiscSave(q)) ? 1 : 0;
    return 0;
}
