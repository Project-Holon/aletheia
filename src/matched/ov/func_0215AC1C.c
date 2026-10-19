/*
 * function: SCRCMD_WORK_CmdGetPlayerSex
 * address:  0x0215AC1C
 * packet:   pkt_0215AC1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The arm9 chain result is biased by the record's own 0x20 before the
 * halfword store.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer   0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData   0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork   0x020127A4  thumb
 *   func_02008550   0x02008550  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern int GAME_DATA_GetMyPlayerWork(void *);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);

int SCRCMD_WORK_CmdGetPlayerSex(void *a0, void *a1)
{
    u16 *p = SCRIPT_WORK_ReadWorkPointer(a0, a1);

    *p = (u16)func_02008550((const struct Sub0200852CObj *)(GAME_DATA_GetMyPlayerWork(SCRCMD_WORK_GetGameData(a1)) + 0x20));

    return 0;
}

