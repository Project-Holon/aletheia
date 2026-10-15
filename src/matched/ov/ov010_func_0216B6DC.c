/*
 * function: SCRCMD_RESEARCH_CmdClearMission
 * address:  0x0216B6DC
 * packet:   pkt_ov010_0216B6DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   SYMBOL_SAVE_GetBitBlock  0x0200E394  thumb
 *   func_0200C334  0x0200C334  thumb
 *   func_0200C344  0x0200C344  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern void *SYMBOL_SAVE_GetBitBlock(void *a0);
struct Blk34;
extern void func_0200C334(struct Blk34 *p, u8 v);
extern void func_0200C344(struct Blk34 *p, u8 i, u8 v);

int SCRCMD_RESEARCH_CmdClearMission(int a0, int a1)
{
    void *w;
    void *h;
    int i;

    SCRCMD_WORK_GetScriptWork((void *)a1);
    w = GAME_DATA_GetSaveControl((struct Big *)SCRCMD_WORK_GetGameData((void *)a1));
    h = func_0200C0F0(w);
    SYMBOL_SAVE_GetBitBlock(w);
    func_0200C334(h, 0);
    for (i = 0; i < 3; i++)
        func_0200C344(h, (u8)i, 0xFF);
    return 0;
}
