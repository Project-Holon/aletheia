/*
 * function: SCRCMD_PROC_CallBagScreen
 * address:  0x0215C72C
 * packet:   pkt_ov010_0215C72C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: reads a selector and two words, maps the selector
 * (0 -> 4, 1 -> 5, else 0), then opens overlay 0x46 over a work built
 * from BAG_PARAM_Create with an 8-byte hand-off record.
 *
 * 2026-10-05 (wave D9): EXACT. The ov070 token on the d_021BB96C data line
 * (the proc table lives in ov070, the overlay this function opens) gave the
 * witness; ov070_id then resolved through the overlay_id walk (SCRCMD_PROC_StartOverlayProc
 * is a registered consumer). Source unchanged.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   BAG_PARAM_Create  0x0202E474  thumb
 *   func_02030734  0x02030734  arm
 *   SCRCMD_PROC_StartOverlayProc  0x0215C63C  thumb  ov010
 *   SCRCMD_PROC_OnBagClosed  0x0215C700  thumb  ov010
 *   sAllocSiteScrcmdProc     0x021728F0  data  a1
 *   ov070_id       0x00000046  data
 *   d_021BB96C     0x021BB96C  data  ov070 a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *vm);
extern void *SCRCMD_WORK_GetScriptWork(void *vm);
extern u32 SCRIPT_WORK_ReadWorkValue(void *c, void *vm);
struct Pair;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *vm);
struct BigObj;
extern void *BAG_PARAM_Create(const struct BigObj *a0, int a1, int a2, int a3);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void SCRCMD_PROC_StartOverlayProc(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
extern void SCRCMD_PROC_OnBagClosed(struct Pair *p);
extern const char sAllocSiteScrcmdProc[];
extern const u8 d_021BB96C[];
extern u8 ov070_id[];

int SCRCMD_PROC_CallBagScreen(void *c, void *vm)
{
    u32 sel;
    u32 a;
    u32 b;
    u32 k;
    void *work;
    u32 *h;

    SCRCMD_WORK_GetGameSystem(vm);
    SCRCMD_WORK_GetScriptWork(vm);
    sel = SCRIPT_WORK_ReadWorkValue(c, vm);
    a = (u32)SCRIPT_WORK_ReadWorkPointer(c, vm);
    b = (u32)SCRIPT_WORK_ReadWorkPointer(c, vm);
    if (sel == 0)
        k = 4;
    else if (sel == 1)
        k = 5;
    else
        k = 0;
    work = BAG_PARAM_Create((const struct BigObj *)SCRCMD_WORK_GetGameData(vm), 0, k, 4);
    h = func_02030734(4, 8, 1, sAllocSiteScrcmdProc, 0x118);
    h[0] = a;
    h[1] = b;
    SCRCMD_PROC_StartOverlayProc(c, vm, (u32)ov070_id, d_021BB96C, work, (u32)SCRCMD_PROC_OnBagClosed, (u32)h);
    return 1;
}
