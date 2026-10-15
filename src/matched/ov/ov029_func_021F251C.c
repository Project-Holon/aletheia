/*
 * function: C_GEAR_Init
 * address:  0x021F251C
 * packet:   pkt_ov029_021F251C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (wave D5 lane 02): arm9 UI_SetSleepHookGlobal/UI_SetWakeHookGlobal and their setters UI_SetSleepHook/UI_SetWakeHook are now filed in src/matched/arm9/; the wrappers show MATCH only until the labels exist. Re-run after the integrator labels them.
 * 2026-10-04 (wD2 lane 09): bytes are identical; 3 of 41 relocations open.
 * Filed leaf C_GEAR_OnCommEvent as matched ov029_func_021F24FC.c (EXACT).
 * Open: ABS32 +01C0 to 021F24FC (witness index not yet regenerated),
 * and THM_CALL +0128/+0130 to unlabelled arm9 02035010 and 02035040 (arm9 wrappers:
 * r2=*(0x021469BC), tail call to 02035004/02035034 style stubs, no source or label yet).
 *
 * Byte-correct.  Blocked by two unlabelled ARM9 leaves (the integrator's), so the
 * overlay leaf 0x021F24FC is not filed either:
 *   +0128 UI_SetSleepHookGlobal (arm): verified MATCH with `one --arm`, capped
 *     only by its own unlabelled tail-call target 0x02035004
 *     (str r1,[r0,#0x14]; str r2,[r0,#0x28]; bx lr):
 *       extern void *d_021469BC;
 *       void UI_SetSleepHookGlobal(void *cb, void *arg)
 *       { UI_SetSleepHook(d_021469BC, cb, arg); }
 *   +0130 UI_SetWakeHookGlobal (arm): the same wrapper over 0x02035034
 *     (str r1,[r0,#0x10]; str r2,[r0,#0x28]; bx lr), MATCH likewise:
 *       void UI_SetWakeHookGlobal(void *cb, void *arg)
 *       { UI_SetWakeHook(d_021469BC, cb, arg); }
 *   +01C0 ABS32 C_GEAR_OnCommEvent (ov029): unlabelled leaf
 *     `void C_GEAR_OnCommEvent(u8 *p) { p[0x451] = 2; }` (ldr r1,=0x451;
 *     movs r2,#2; strb r2,[r0,r1]; bx lr).
 * Levers: r = 0 at the top shares the zero register with the 0x214/0x218
 * stores; t = 1 assigned after the PALANM_Create store keeps t in a stack
 * slot and 0x1C0 in r7; p is u8 * (ldrb of 0x45A); C_GEAR_SetPowerState's second
 * argument is int here (no narrowing before the call).
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Open: unlabelled arm9 02035010 and 02035040 (no source change possible here).
 *
 * symbols:
 *   GAMESYSTEM_GetAlwaysNetFlag  0x0201214C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CBC  0x02030CBC  arm
 *   C_GEAR_ChangeStep  0x021EFEF8  thumb  ov029
 *   C_GEAR_StepOpen  0x021F21F8  thumb  ov029
 *   C_GEAR_StepIdle  0x021F2180  thumb  ov029
 *   C_GEAR_InitTabTimersPowerOn  0x021F0298  thumb  ov029
 *   C_GEAR_SetupBackgrounds  0x021F1624  thumb  ov029
 *   C_GEAR_LoadGraphics  0x021F1DE8  thumb  ov029
 *   func_02009100  0x02009100  thumb
 *   C_GEAR_LoadCustomBackground  0x021F23CC  thumb  ov029
 *   C_GEAR_LoadFrameGraphics  0x021F15FC  thumb  ov029
 *   C_GEAR_InitTiles  0x021F0A0C  thumb  ov029
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb
 *   C_GEAR_TintPalettes  0x021F0DB4  thumb  ov029
 *   PALANM_TransferPalettes  0x02021D50  thumb
 *   func_020056A0  0x020056A0  thumb
 *   C_GEAR_TransferPalettesTask  0x021F2508  thumb  ov029
 *   UI_SetSleepHookGlobal  0x02035010  arm
 *   C_GEAR_OnCommDisconnect  0x021F24C0  thumb  ov029
 *   UI_SetWakeHookGlobal  0x02035040  arm
 *   C_GEAR_OnCommEvent  0x021F24FC  thumb  ov029
 *   C_GEAR_CreateFadeFx  0x021F2E10  thumb  ov029
 *   C_GEAR_UpdateBeaconColors  0x021F1CD8  thumb  ov029
 *   C_GEAR_UpdateClock  0x021F1F80  thumb  ov029
 *   GAMESYSTEM_IsEventActive  0x020120D8  thumb
 *   C_GEAR_SetPowerState  0x021F3144  thumb  ov029
 *   C_GEAR_ApplyIndicators  0x021F2D84  thumb  ov029
 *   TCB_Main  0x02030D28  arm
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetVisitProgress  0x021585E0  thumb  ov010
 *   INTRUDE_COMM_SetCompleted  0x02158614  thumb  ov010
 *   d_021F3554     0x021F3554  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int d_021F3554;

struct Ctx;
struct Obj02021EE4;
struct PalAnmSlot;
struct S02021D50;
struct Sub020090B0Obj;
extern u32 GAMESYSTEM_GetAlwaysNetFlag(const struct Ctx *p);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02030CB0(u32 n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void C_GEAR_ChangeStep(char *p, void (*f)(void), int line);
extern void C_GEAR_StepOpen(char *p);
extern void C_GEAR_StepIdle(char *p);
extern void C_GEAR_InitTabTimersPowerOn(u8 *p);
extern void C_GEAR_SetupBackgrounds(void *p);
extern void C_GEAR_LoadGraphics(char *p, int flag);
extern u8 func_02009100(const struct Sub020090B0Obj *obj);
extern int C_GEAR_LoadCustomBackground(u8 *p, int a);
extern void C_GEAR_LoadFrameGraphics(char *p, int flag);
extern void C_GEAR_InitTiles(u8 *p);
extern void *PALANM_Create(u32 heap);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void C_GEAR_TintPalettes(char *p, int mode);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern int func_020056A0(void *callback, void *ctx, int a2);
extern void C_GEAR_TransferPalettesTask(void *task, char *p);
extern void UI_SetSleepHookGlobal(u32 a, u32 b);
extern void C_GEAR_OnCommDisconnect(char *p);
extern void UI_SetWakeHookGlobal(u32 a, u32 b);
extern void C_GEAR_OnCommEvent(unsigned char *p);
extern void C_GEAR_CreateFadeFx(char *p, int *q);
extern void C_GEAR_UpdateBeaconColors(char *p);
extern void C_GEAR_UpdateClock(char *p);
extern int GAMESYSTEM_IsEventActive(char *p);
extern void C_GEAR_SetPowerState(u8 *p, int v);
extern void C_GEAR_ApplyIndicators(u8 *p);
extern void TCB_Main(struct Ctx *c);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetVisitProgress(int a);
extern void INTRUDE_COMM_SetCompleted(void *p);

void C_GEAR_Init(u8 *p, int a1, int a2, int a3, int e)
{
    int r = 0;
    int t;
    int h;

    *(u16 *)(p + 0xc) = 0x70;
    *(int *)(p + 0x20) = a1;
    *(int *)(p + 0x18) = a2;
    *(int *)(p + 0x1c) = a3;
    p[0x454] = 1;
    p[0x45A] = GAMESYSTEM_GetAlwaysNetFlag((const struct Ctx *)a3);
    p[0x45B] = 1;
    *(int *)(p + 0x214) = 0;
    *(int *)(p + 0x218) = 0;
    *(int *)(p + 0x24) = (int)func_020490F4(0x1e, 0x70);
    *(void **)(p + 0x20C) = func_02030734(0x70, func_02030CB0(4), 1, (const char *)(&d_021F3554), 4280);
    *(int *)(p + 0x204) = (int)func_02030CBC(4, *(void **)(p + 0x20C));
    if (e != 0) {
        C_GEAR_ChangeStep((char *)p, (void (*)(void))C_GEAR_StepOpen, 4284);
    } else {
        C_GEAR_InitTabTimersPowerOn(p);
        C_GEAR_ChangeStep((char *)p, (void (*)(void))C_GEAR_StepIdle, 4287);
    }
    C_GEAR_SetupBackgrounds(p);
    C_GEAR_LoadGraphics((char *)p, e);
    if (func_02009100((const struct Sub020090B0Obj *)(*(int *)(p + 0x20))) != 0)
        r = C_GEAR_LoadCustomBackground(p, a3);
    C_GEAR_LoadFrameGraphics((char *)p, r);
    C_GEAR_InitTiles(p);
    *(int *)(p + 0x210) = (int)PALANM_Create(0x70);
    t = 1;
    PALANM_SetAutoTransfer((struct Obj02021EE4 *)(*(int *)(p + 0x210)), 1);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)(*(int *)(p + 0x210)), 3, 0x1C0, 0x70);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)(*(int *)(p + 0x210)), 1, 0x1C0, 0x70);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)(*(int *)(p + 0x210)), 3, 0, 0x1C0);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)(*(int *)(p + 0x210)), 1, 0, 0x1C0);
    C_GEAR_TintPalettes((char *)p, p[0x45A]);
    PALANM_TransferPalettes((struct S02021D50 *)(*(int *)(p + 0x210)));
    *(int *)(p + 0x208) = func_020056A0((void *)C_GEAR_TransferPalettesTask, p, 1);
    UI_SetSleepHookGlobal((u32)((void *)C_GEAR_OnCommDisconnect), (u32)p);
    UI_SetWakeHookGlobal((u32)((void *)C_GEAR_OnCommEvent), (u32)p);
    C_GEAR_CreateFadeFx((char *)p, (int *)(p + 0x21C));
    C_GEAR_UpdateBeaconColors((char *)p);
    C_GEAR_UpdateClock((char *)p);
    if (e == 0) {
        if (GAMESYSTEM_IsEventActive((char *)a3) != 0)
            t = 0;
        C_GEAR_SetPowerState(p, t);
        C_GEAR_ApplyIndicators(p);
    } else {
        C_GEAR_StepOpen((char *)p);
    }
    if (*(int *)(p + 0x204) != 0)
        TCB_Main((struct Ctx *)(*(int *)(p + 0x204)));
    h = GAMESYSTEM_GetGameComm((const struct Ctx *)a3);
    if (h != 0 && INTRUDE_COMM_GetVisitProgress(h) == 2)
        INTRUDE_COMM_SetCompleted((void *)h);
}
