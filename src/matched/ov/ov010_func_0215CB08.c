/*
 * function: SCRCMD_PROC_CallModeScreen
 * address:  0x0215CB08
 * packet:   pkt_ov010_0215CB08
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: reads a mode (0-2) and a word; unless the mode is 2
 * calls GAME_BEACON_SEARCH_SetScriptEvent, then boxes the system object (and the word) in a
 * hand-off record and opens overlay 0xDD, 0xDE or 0xE0 over it through
 * SCRCMD_PROC_StartOverlayProc.
 *
 * MATCH, bytes exact. Blockers: the three overlay ids (ABS32 0xDD, 0xDE,
 * 0xE0) have no witness: `overlay_id` would carry them, but SCRCMD_PROC_StartOverlayProc
 * (which forwards its r2 to GAMESYSTEM_CallProc's r1) is not in match.py's
 * OVERLAY_ID_CONSUMERS. d_021BA250 (ov222) and d_021B9BF8 (ov224) are
 * contested hints that resolve once the function loads those overlays
 * through an overlay_id site. d_021BA1A4 (ov221) already resolves.
 *
 * 2026-10-05 (wave D9): re-tried overlay tokens on the contested hints; they stay contested because the id sites do not attest. Residue is the three id words (ov221_id, ov222_id, ov224_id) reaching SCRCMD_PROC_StartOverlayProc, which is not in OVERLAY_ID_CONSUMERS; add that consumer (r2 -> GAMESYSTEM_CallProc r1) and the hints resolve. Not fixable in C.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_BEACON_SEARCH_SetScriptEvent  0x02165344  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   SCRCMD_PROC_StartOverlayProc  0x0215C63C  thumb  ov010
 *   sAllocSiteScrcmdProc     0x021728F0  data  a1
 *   ov221_id       0x000000DD  data
 *   ov222_id       0x000000DE  data
 *   ov224_id       0x000000E0  data
 *   d_021BA1A4     0x021BA1A4  data  ov221  a4
 *   d_021BA250     0x021BA250  data  ov222  a4
 *   d_021B9BF8     0x021B9BF8  data  ov224  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Box8 {
    void *sys;          /* 0x00 */
    u32 v;              /* 0x04 */
} Box8;

extern void *SCRCMD_WORK_GetGameSystem(void *vm);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u32 SCRIPT_WORK_ReadWorkValue(void *c, void *vm);
extern void GAME_BEACON_SEARCH_SetScriptEvent(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void SCRCMD_PROC_StartOverlayProc(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
extern const char sAllocSiteScrcmdProc[];
extern const u8 d_021BA1A4[];
extern const u8 d_021BA250[];
extern const u8 d_021B9BF8[];
extern u8 ov221_id[];
extern u8 ov222_id[];
extern u8 ov224_id[];

int SCRCMD_PROC_CallModeScreen(void *c, void *vm)
{
    void *sys;
    void *sub;
    u32 mode;
    u32 v;
    Box8 *b;
    void **w;

    sys = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(vm));
    sub = GAME_DATA_GetMyStatus(sys);
    mode = SCRIPT_WORK_ReadWorkValue(c, vm);
    v = SCRIPT_WORK_ReadWorkValue(c, vm);
    if (mode != 2) {
        GAME_BEACON_SEARCH_SetScriptEvent();
    }
    switch (mode) {
    case 0:
        b = func_02030734(4, 8, 1, sAllocSiteScrcmdProc, 0x22B);
        b->sys = sys;
        b->v = v;
        SCRCMD_PROC_StartOverlayProc(c, vm, (u32)ov221_id, d_021BA1A4, b, 0, 0);
        break;
    case 1:
        b = func_02030734(4, 8, 1, sAllocSiteScrcmdProc, 0x233);
        b->sys = sys;
        b->v = v;
        SCRCMD_PROC_StartOverlayProc(c, vm, (u32)ov222_id, d_021BA250, b, 0, 0);
        break;
    case 2:
        w = func_02030734(4, 4, 1, sAllocSiteScrcmdProc, 0x23C);
        *w = sub;
        SCRCMD_PROC_StartOverlayProc(c, vm, (u32)ov224_id, d_021B9BF8, w, 0, 0);
        break;
    }
    return 1;
}
