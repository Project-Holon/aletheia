/*
 * file:     ui_p02.c
 * unit:     yes
 * function: UI_IsPowerConnected, UI_RunWakePoweredHook, UI_IsSleepInhibited, UI_SetBottomBackLight, UI_ServiceLidSleep, UI_SoftReset, UI_GetInputMode, UI_SetInputMode, UI_ClearPendingInputFlagOf, UI_SetFrameRateOf, UI_ChangeFrameRate, UI_GetPowerState, UI_ApplyInputBounds
 * address:  0x020353B0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from net_state.c at 0x02035750 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   UI_IsPowerConnected  0x020353B0  arm
 *   PM_SetBackLight 0x0208BDD8  arm
 *   sub_02035224   0x02035224  arm
 *   UI_IsSleepInhibited   0x020353F8  arm
 *   TOUCHPANEL_AutoSamplingStop   0x02035E08  arm
 *   func_0203524C   0x0203524C  arm
 *   PM_GoSleepMode  0x0208C154  arm
 *   UI_RunWakePoweredHook   0x020353C8  arm
 *   func_020352AC   0x020352AC  arm
 *   func_02035268   0x02035268  arm
 *   TOUCHPANEL_AutoSamplingRestart   0x02035DC8  arm
 *   UI_SetBottomBackLight   0x02035428  arm
 *   func_02035284   0x02035284  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   OS_ResetSystem            0x02087BCC  arm
 *   OS_WaitIrq                0x0208459C  arm
 *   gUiState     0x021469BC  data
 *   TOUCHPANEL_ClearFrameRateWork 0x02035E54 arm
 *   TOUCHPANEL_SetPoint 0x02035E84 arm
 *   TOUCHPANEL_SetTrg 0x02035EB0 arm
 *   TOUCHPANEL_SetCont 0x02035ECC arm
 *   KEY_ClearFrameRateWork 0x02036390 arm
 *   KEY_SetTrg 0x020363B8 arm
 *   KEY_SetCont 0x020363D4 arm
 *   KEY_SetRepeat 0x020363F0 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_Main 0x0203CF5C arm
 *   GFL_NET_IsIdle 0x0203D210 arm
 *   FADE_Update  0x0204E638  arm
 *   CARD_TryWaitBackupAsync  0x02076B8C  arm
 */
struct UiCtx;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef void (*UiCb)(void *);

typedef int  (*UiPred)(void *);

struct UiCtx {
    u8      reserved00[0x10];
    UiCb    onWake;
    UiCb    onSleep;
    UiCb    onResume;
    UiCb    onSuspend;
    UiCb    onWakePowered;
    UiPred  keepAwakePred;
    void   *sleepWakeArg;
    void   *suspendResumeArg;
    void   *wakePoweredArg;
    void   *keepAwakeArg;
    u8      keepAwakeFlags;
    u8      flags39[2];
    u8      backlightState;
    u8      inputMode;
    u8      frameRate;
    u8      pendingInputFlag;
    u8      powerState;
    u8      mode[3];
    u8      suspended;
};

typedef unsigned short u16;

/* One corner of the input area: three key-side parameters, the touch point
 * and two touch flags.  The two corners are pushed into key.c and
 * touchpanel.c by UI_ApplyInputBounds. */
typedef struct {
    u16 keyParam0;
    u16 keyParam1;
    u16 keyParam2;
    u16 touchX;
    u16 touchY;
    u8  touchFlagA;
    u8  touchFlagB;
} UiInputCorner;

typedef struct {
    struct UiCtx *ctx;
    int (*getInputBounds)(UiInputCorner *lower, UiInputCorner *upper);
} UiState;

extern int PM_SetBackLight(u32 which, u32 status);
extern void TOUCHPANEL_AutoSamplingStop(void);
extern void func_0203524C(struct UiCtx *ui);
extern void PM_GoSleepMode(u32 trigger, u32 a, u32 b);
extern void func_020352AC(struct UiCtx *ui);
extern void func_02035268(struct UiCtx *ui);
extern void TOUCHPANEL_AutoSamplingRestart(void);
extern void func_02035284(struct UiCtx *ui);
extern struct UiCtx *sub_02035224(void);
extern void GXx_SetMasterBrightness_(u32 reg, int brightness);
extern u32 CARD_TryWaitBackupAsync(void);
extern void OS_ResetSystem(u32 param);
extern void OS_WaitIrq(u32 clear, u32 irqFlags);
extern void FADE_Update(void);
int UI_IsPowerConnected(void);
void UI_RunWakePoweredHook(struct UiCtx *ui);
int UI_IsSleepInhibited(struct UiCtx *ui);
void UI_SetBottomBackLight(u32 backlightState);
void UI_ServiceLidSleep(void);
void UI_SoftReset(u32 resetParam);
u8 UI_GetInputMode(void);
void UI_SetInputMode(u8 value);
void UI_ClearPendingInputFlagOf(struct UiCtx *ui);
void UI_SetFrameRateOf(struct UiCtx *unused, u8 value);
u8 UI_GetFrameRateOf(struct UiCtx *ui);
void UI_SetFrameRate(u8 value);
u8 UI_GetFrameRate(void);
void UI_ClearPendingInputFlag(void);
void UI_ChangeFrameRate(u8 value);
int UI_GetPowerState(void);
void UI_ApplyInputBounds(int inputObj);
void TOUCHPANEL_ClearFrameRateWork(struct UiCtx *ui);
void TOUCHPANEL_SetPoint(void *touchObj, u16 lowerX, u16 lowerY, u16 upperX, u16 upperY);
int TOUCHPANEL_SetTrg(int inputObj, int a1, int a2);
int TOUCHPANEL_SetCont(int inputObj, int a1, int a2);
void KEY_ClearFrameRateWork(struct UiCtx *ui);
int KEY_SetTrg(int inputObj, int a1, int a2);
int KEY_SetCont(int inputObj, int a1, int a2);
int KEY_SetRepeat(int inputObj, int a1, int a2);
int GFL_NET_Exit(void (*hook)(u32));
u32 GFL_NET_Main(void);
u32 GFL_NET_IsIdle(void);
extern UiState gUiState;




























/*
 * The "is the lid state low enough to keep running" predicate: normalise
 * UI_GetPowerState's level to a boolean at the threshold 2.  Written as a
 * signed compare, so the two constant arms come out as movle/movgt off one
 * `cmp r0, #2` instead of a branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_IsPowerConnected.c \n *       --func UI_IsPowerConnected --addr 0x020353B0 --cc 1.1p1 --arm
 */
int UI_IsPowerConnected(void)
{
    return UI_GetPowerState() <= 2;
}




























/*
 * Run the +0x20 hook, but only when one is installed and UI_IsPowerConnected says
 * the state allows it.  The two guards each carry their own `popeq`: a call
 * sits between them, so they cannot share an exit block and are two `if`s
 * rather than one `&&`.
 *
 * The hook pointer is re-read after the UI_IsPowerConnected call, and the argument
 * at +0x30 is loaded before it, because nothing proves the call left the
 * context alone.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_RunWakePoweredHook.c \n *       --func UI_RunWakePoweredHook --addr 0x020353C8 --cc 1.1p1 --arm
 */
void UI_RunWakePoweredHook(struct UiCtx *ui)
{
    if (ui->onWakePowered == 0) {
        return;
    }
    if (UI_IsPowerConnected() == 0) {
        return;
    }
    ui->onWakePowered(ui->wakePoweredArg);
}



























/*
 * The context's veto predicate: the byte at +0x38 forces a yes, otherwise a
 * hook at +0x24 decides, and with no hook the answer is no.  The hook
 * pointer stays in r1 from its own null test through the `blx`, which is why
 * the argument at +0x34 is fetched into r0 second.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_IsSleepInhibited.c \n *       --func UI_IsSleepInhibited --addr 0x020353F8 --cc 1.1p1 --arm
 */
int UI_IsSleepInhibited(struct UiCtx *ui)
{
    if (ui->keepAwakeFlags != 0) {
        return 1;
    }
    if (ui->keepAwakePred == 0) {
        return 0;
    }
    return ui->keepAwakePred(ui->keepAwakeArg);
}


























/*
 * Retry PM_SetBackLight on the bottom screen until it reports success or a
 * thousand attempts have gone by.  The loop counter is assigned before the
 * hoisted screen selector, which is what puts `mov r5, #0` ahead of
 * `mov r4, #2`
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_SetBottomBackLight.c \n *       --func UI_SetBottomBackLight --addr 0x02035428 --cc 1.1p1 --arm
 */
void UI_SetBottomBackLight(u32 backlightState)
{
    int attempt;

    for (attempt = 0; attempt < 1000; attempt++) {
        if (PM_SetBackLight(2, backlightState) == 0) {
            return;
        }
    }
}

























/*
 * The lid/sleep service, one of the five sub_02034EF8 runs per frame.  Bit
 * 15 of the halfword at 0x02FFFFA8 is the lid-closed flag; when it is set
 * and the veto predicate UI_IsSleepInhibited says no, the machine goes to sleep
 * with the whole shutdown/wake sequence around it, and when the predicate
 * says yes the context is instead marked as suspended (+0x43) with the
 * backlight forced off.  An open lid undoes the suspension.
 *
 * The flag is read as a signed `int`, hence `asrs r1, r1, #0xf` rather than
 * a logical shift: the halfword zero-extends into an `int`, the mask keeps
 * it positive, and the shift inherits the signed type.
 *
 * The literal 0 sits in r5 for the whole function because PM_GoSleepMode's
 * second and third arguments and the +0x43 store all want it.
 *
 * PARKED AT MATCH.  Every concrete byte is right, and fifteen of the sixteen
 * relocation sites resolve.  The sixteenth, PM_GoSleepMode at 0x0208C154, is
 * reached from exactly one place in the whole image: the `bl` at 0x020354A4
 * inside this function.  `label` therefore has no outside branch, and
 * `matched` would need an EXACT manifest entry for TwlSDK libspi code.  No
 * split can help, because the site is inside the only function that needs
 * it.
 *
 * This is what caps src/pending/sub_02034EF8.c as well.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_ServiceLidSleep.c \
 *       --func UI_ServiceLidSleep --addr 0x0203545C --cc 1.1p1 --arm
 */
void UI_ServiceLidSleep(void)
{
    struct UiCtx *ui;

    ui = sub_02035224();

    if ((*(u16 *)0x02FFFFA8 & 0x8000) >> 15) {
        if (UI_IsSleepInhibited(ui) == 0) {
            TOUCHPANEL_AutoSamplingStop();
            func_0203524C(ui);
            PM_GoSleepMode(0xC, 0, 0);
            UI_RunWakePoweredHook(ui);
            func_020352AC(ui);
            func_02035268(ui);
            TOUCHPANEL_AutoSamplingRestart();
            if (ui->suspended != 0) {
                ui->suspended = 0;
                UI_SetBottomBackLight(ui->backlightState);
            }
        } else {
            if (ui->suspended == 0) {
                ui->suspended = 1;
                UI_SetBottomBackLight(0);
                func_02035284(ui);
                func_0203524C(ui);
            }
        }
    } else {
        if (ui->suspended != 0) {
            ui->suspended = 0;
            UI_SetBottomBackLight(ui->backlightState);
            func_02035268(ui);
            func_020352AC(ui);
        }
    }
}
























/*
 * The soft-reset trap: fade both screens to white, tear the UI down, then spin
 * forever pumping the main loop's per-frame work.  The loop never exits (the
 * image's tail is an unconditional `b` back to the GFL_NET_IsIdle test), and
 * the reset path inside it returns through OS_ResetSystem.
 *
 * Both master-brightness registers come off one pool word: 0x0400006C is the
 * main engine's MASTER_BRIGHT and the sub engine's sits +0x1000 away, which is
 * why the image loads the base once into r5 and spells the second as
 * `add r0, r5, #0x1000`.  The brightness value 0x10 and the OS_WaitIrq mask
 * are both kept in r4 across the calls, and the `mov r4, #1` that retargets it
 * sits before the loop head.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_SoftReset.c \
 *       --func UI_SoftReset --addr 0x02035544 --cc 1.1p1 --arm
 */
void UI_SoftReset(u32 resetParam)
{
    struct UiCtx *ui;

    ui = sub_02035224();
    GXx_SetMasterBrightness_(0x0400006C, 0x10);
    GXx_SetMasterBrightness_(0x0400006C + 0x1000, 0x10);
    GFL_NET_Exit(0);

    while (1) {
        if (GFL_NET_IsIdle() != 0 && CARD_TryWaitBackupAsync() != 0) {
            UI_SetBottomBackLight(ui->backlightState);
            OS_ResetSystem(resetParam);
        }
        OS_WaitIrq(1, 1);
        GFL_NET_Main();
        FADE_Update();
    }
}























/*
 * A whole translation unit, matched as one byte range.
 *
 *           UI_GetFrameRateOf, UI_SetFrameRate, UI_GetFrameRate, UI_ClearPendingInputFlag
 *
 * The accessor block of the singleton reached through the pointer at
 * 0x021469BC.  None of these eight functions saves lr, so disasm.py
 * labels none of them; they are visible only by sweeping addresses
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The block is written as instance accessors plus global wrappers that
 * fetch the singleton and forward:
 *
 *   UI_GetInputMode  read the u8 at +0x3c of the singleton.
 *   UI_SetInputMode  write it.
 *   UI_ClearPendingInputFlagOf  clear the u8 at +0x3e of a caller-supplied instance.
 *   UI_SetFrameRateOf  write the u8 at +0x3d.  Takes an instance pointer for
 *                 symmetry with UI_GetFrameRateOf but ignores it and goes
 *                 through the singleton anyway; the reload of the global
 *                 over r0 is the whole tell.
 *   UI_GetFrameRateOf  read the u8 at +0x3d of a caller-supplied instance.
 *   UI_SetFrameRate  global wrapper over UI_SetFrameRateOf.
 *   UI_GetFrameRate  global wrapper over UI_GetFrameRateOf.
 *   UI_ClearPendingInputFlag  global wrapper over UI_ClearPendingInputFlagOf.
 *
 * The range deliberately stops before UI_ChangeFrameRate, the one labelled
 * function of this file: its calls to 0x02036390 and 0x02035E54 have no
 * witness outside the file, so including it caps the whole unit at MATCH.
 * It is parked in src/pending/UI_ChangeFrameRate.c.
 *
 * Every wrapper is a pool word and a `bx ip`, never a displacement
 * branch, because each function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020355C4.c \
 *       --addr 0x020355C4 --arm
 */
u8 UI_GetInputMode(void)
{
    return gUiState.ctx->inputMode;
}























void UI_SetInputMode(u8 value)
{
    gUiState.ctx->inputMode = value;
}























void UI_ClearPendingInputFlagOf(struct UiCtx *ui)
{
    ui->pendingInputFlag = 0;
}























void UI_SetFrameRateOf(struct UiCtx *unused, u8 value)
{
    gUiState.ctx->frameRate = value;
}























u8 UI_GetFrameRateOf(struct UiCtx *ui)
{
    return ui->frameRate;
}























void UI_SetFrameRate(u8 value)
{
    UI_SetFrameRateOf(gUiState.ctx, value);
}























u8 UI_GetFrameRate(void)
{
    return UI_GetFrameRateOf(gUiState.ctx);
}























void UI_ClearPendingInputFlag(void)
{
    UI_ClearPendingInputFlagOf(gUiState.ctx);
}






















void UI_ChangeFrameRate(u8 value)
{
    UI_SetFrameRateOf(gUiState.ctx, value);
    KEY_ClearFrameRateWork(gUiState.ctx);
    TOUCHPANEL_ClearFrameRateWork(gUiState.ctx);
}






















int UI_GetPowerState(void)
{
    return gUiState.ctx->powerState;
}























/*
 * A descriptor fan-out: the global at 0x021469BC carries a callback at +4
 * which fills two twelve-byte records on the stack, and the seven
 * accessors below push each pair into the object in inputObj.
 */
void UI_ApplyInputBounds(int inputObj)
{
    UiInputCorner lower;
    UiInputCorner upper;

    if (gUiState.getInputBounds == 0) {
        return;
    }
    if (gUiState.getInputBounds(&lower, &upper) == 0) {
        return;
    }
    KEY_SetTrg(inputObj, lower.keyParam0, upper.keyParam0);
    KEY_SetCont(inputObj, lower.keyParam1, upper.keyParam1);
    KEY_SetRepeat(inputObj, lower.keyParam2, upper.keyParam2);
    TOUCHPANEL_SetPoint((void *)inputObj, lower.touchX, lower.touchY, upper.touchX, upper.touchY);
    TOUCHPANEL_SetTrg(inputObj, lower.touchFlagA, upper.touchFlagA);
    TOUCHPANEL_SetCont(inputObj, lower.touchFlagB, upper.touchFlagB);
}
