/*
 * function: SCRCMD_PROC_CallValueScreen
 * address:  0x0215CAB4
 * packet:   pkt_ov010_0215CAB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: reads one halfword and the system, boxes them in an
 * 8-byte record and opens overlay 0xAE over it.
 *
 * Bytes exact.
 *
 * 2026-10-05 (wave D9): EXACT. The ov174 token on the gLocalTvtSysProcData data line (the
 * proc table lives in ov174, which this function loads) gave the witness; the
 * ov174_id word then resolved through the overlay_id walk. Source unchanged.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_PROC_StartOverlayProc  0x0215C63C  thumb  ov010
 *   sAllocSiteScrcmdProc     0x021728F0  data  a1
 *   ov174_id       0x000000AE  data
 *   gLocalTvtSysProcData     0x021B74A0  data  a1 ov174
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Box8 {
    u16 v;              /* 0x00 */
    u16 pad02;
    void *sys;          /* 0x04 */
} Box8;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *SCRCMD_WORK_GetGameData(void *vm);
extern void SCRCMD_PROC_StartOverlayProc(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
extern const char sAllocSiteScrcmdProc[];
extern const u8 gLocalTvtSysProcData[];
extern u8 ov174_id[];

int SCRCMD_PROC_CallValueScreen(void *c, void *vm)
{
    u16 v;
    Box8 *b;

    v = SCRIPT_WORK_ReadWorkValue(c, vm);
    b = func_02030734(4, 8, 1, sAllocSiteScrcmdProc, 0x205);
    b->v = v;
    b->sys = SCRCMD_WORK_GetGameData(vm);
    SCRCMD_PROC_StartOverlayProc(c, vm, (u32)ov174_id, gLocalTvtSysProcData, b, 0, 0);
    return 1;
}
