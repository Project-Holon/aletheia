/*
 * file:     ui_p02.c
 * unit:     yes
 * function: sub_020353B0, sub_020353C8, sub_020353F8, sub_02035428, sub_0203545C, func_02035544, sub_020355C4, sub_020355D8, sub_020355EC, sub_020355F8, sub_02035660, func_0203568C, func_020356A0
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
 *   sub_020353B0  0x020353B0  arm
 *   PM_SetBackLight 0x0208BDD8  arm
 *   sub_02035224   0x02035224  arm
 *   sub_020353F8   0x020353F8  arm
 *   func_02035E08   0x02035E08  arm
 *   func_0203524C   0x0203524C  arm
 *   PM_GoSleepMode  0x0208C154  arm
 *   sub_020353C8   0x020353C8  arm
 *   func_020352AC   0x020352AC  arm
 *   func_02035268   0x02035268  arm
 *   func_02035DC8   0x02035DC8  arm
 *   sub_02035428   0x02035428  arm
 *   func_02035284   0x02035284  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   OS_ResetSystem            0x02087BCC  arm
 *   OS_WaitIrq                0x0208459C  arm
 *   g_021469BC     0x021469BC  data
 *   sub_02035E54 0x02035E54 arm
 *   func_02035E84 0x02035E84 arm
 *   func_02035EB0 0x02035EB0 arm
 *   func_02035ECC 0x02035ECC arm
 *   sub_02036390 0x02036390 arm
 *   func_020363B8 0x020363B8 arm
 *   func_020363D4 0x020363D4 arm
 *   func_020363F0 0x020363F0 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203CF5C 0x0203CF5C arm
 *   func_0203D210 0x0203D210 arm
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
extern void func_02035E08(void);
extern void func_0203524C(struct UiCtx *ui);
extern void PM_GoSleepMode(u32 trigger, u32 a, u32 b);
extern void func_020352AC(struct UiCtx *ui);
extern void func_02035268(struct UiCtx *ui);
extern void func_02035DC8(void);
extern void func_02035284(struct UiCtx *ui);
extern struct UiCtx *sub_02035224(void);
extern void GXx_SetMasterBrightness_(u32 reg, int brightness);
extern u32 func_02076B8C(void);
extern void OS_ResetSystem(u32 param);
extern void OS_WaitIrq(u32 clear, u32 irqFlags);
extern void func_0204E638(void);
int sub_020353B0(void);
void sub_020353C8(struct UiCtx *ui);
int sub_020353F8(struct UiCtx *ui);
void sub_02035428(u32 backlightState);
void sub_0203545C(void);
void func_02035544(u32 resetParam);
u8 sub_020355C4(void);
void sub_020355D8(u8 value);
void sub_020355EC(struct UiCtx *ui);
void sub_020355F8(struct UiCtx *unused, u8 value);
u8 sub_0203560C(struct UiCtx *ui);
void sub_02035614(u8 value);
u8 sub_02035630(void);
void sub_02035648(void);
void sub_02035660(u8 value);
int func_0203568C(void);
void func_020356A0(int inputObj);
void sub_02035E54(struct UiCtx *ui);
void func_02035E84(void *touchObj, u16 lowerX, u16 lowerY, u16 upperX, u16 upperY);
int func_02035EB0(int inputObj, int a1, int a2);
int func_02035ECC(int inputObj, int a1, int a2);
void sub_02036390(struct UiCtx *ui);
int func_020363B8(int inputObj, int a1, int a2);
int func_020363D4(int inputObj, int a1, int a2);
int func_020363F0(int inputObj, int a1, int a2);
int func_0203CEAC(void (*hook)(u32));
u32 func_0203CF5C(void);
u32 func_0203D210(void);
extern UiState g_021469BC;




























/*
 * The "is the lid state low enough to keep running" predicate: normalise
 * func_0203568C's level to a boolean at the threshold 2.  Written as a
 * signed compare, so the two constant arms come out as movle/movgt off one
 * `cmp r0, #2` instead of a branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020353B0.c \n *       --func sub_020353B0 --addr 0x020353B0 --cc 1.1p1 --arm
 */
int sub_020353B0(void)
{
    return func_0203568C() <= 2;
}




























/*
 * Run the +0x20 hook, but only when one is installed and sub_020353B0 says
 * the state allows it.  The two guards each carry their own `popeq`: a call
 * sits between them, so they cannot share an exit block and are two `if`s
 * rather than one `&&`.
 *
 * The hook pointer is re-read after the sub_020353B0 call, and the argument
 * at +0x30 is loaded before it, because nothing proves the call left the
 * context alone.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020353C8.c \n *       --func sub_020353C8 --addr 0x020353C8 --cc 1.1p1 --arm
 */
void sub_020353C8(struct UiCtx *ui)
{
    if (ui->onWakePowered == 0) {
        return;
    }
    if (sub_020353B0() == 0) {
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
 *   python tools/match.py one --src src/matched/sub_020353F8.c \n *       --func sub_020353F8 --addr 0x020353F8 --cc 1.1p1 --arm
 */
int sub_020353F8(struct UiCtx *ui)
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
 *   python tools/match.py one --src src/matched/sub_02035428.c \n *       --func sub_02035428 --addr 0x02035428 --cc 1.1p1 --arm
 */
void sub_02035428(u32 backlightState)
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
 * and the veto predicate sub_020353F8 says no, the machine goes to sleep
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
 *   python tools/match.py one --src src/pending/sub_0203545C.c \
 *       --func sub_0203545C --addr 0x0203545C --cc 1.1p1 --arm
 */
void sub_0203545C(void)
{
    struct UiCtx *ui;

    ui = sub_02035224();

    if ((*(u16 *)0x02FFFFA8 & 0x8000) >> 15) {
        if (sub_020353F8(ui) == 0) {
            func_02035E08();
            func_0203524C(ui);
            PM_GoSleepMode(0xC, 0, 0);
            sub_020353C8(ui);
            func_020352AC(ui);
            func_02035268(ui);
            func_02035DC8();
            if (ui->suspended != 0) {
                ui->suspended = 0;
                sub_02035428(ui->backlightState);
            }
        } else {
            if (ui->suspended == 0) {
                ui->suspended = 1;
                sub_02035428(0);
                func_02035284(ui);
                func_0203524C(ui);
            }
        }
    } else {
        if (ui->suspended != 0) {
            ui->suspended = 0;
            sub_02035428(ui->backlightState);
            func_02035268(ui);
            func_020352AC(ui);
        }
    }
}
























/*
 * The soft-reset trap: fade both screens to white, tear the UI down, then spin
 * forever pumping the main loop's per-frame work.  The loop never exits (the
 * image's tail is an unconditional `b` back to the func_0203D210 test), and
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
 *   python tools/match.py one --src src/matched/func_02035544.c \
 *       --func func_02035544 --addr 0x02035544 --cc 1.1p1 --arm
 */
void func_02035544(u32 resetParam)
{
    struct UiCtx *ui;

    ui = sub_02035224();
    GXx_SetMasterBrightness_(0x0400006C, 0x10);
    GXx_SetMasterBrightness_(0x0400006C + 0x1000, 0x10);
    func_0203CEAC(0);

    while (1) {
        if (func_0203D210() != 0 && func_02076B8C() != 0) {
            sub_02035428(ui->backlightState);
            OS_ResetSystem(resetParam);
        }
        OS_WaitIrq(1, 1);
        func_0203CF5C();
        func_0204E638();
    }
}























/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0203560C, sub_02035614, sub_02035630, sub_02035648
 *
 * The accessor block of the singleton reached through the pointer at
 * 0x021469BC.  None of these eight functions saves lr, so disasm.py
 * labels none of them; they are visible only by sweeping addresses
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The block is written as instance accessors plus global wrappers that
 * fetch the singleton and forward:
 *
 *   sub_020355C4  read the u8 at +0x3c of the singleton.
 *   sub_020355D8  write it.
 *   sub_020355EC  clear the u8 at +0x3e of a caller-supplied instance.
 *   sub_020355F8  write the u8 at +0x3d.  Takes an instance pointer for
 *                 symmetry with sub_0203560C but ignores it and goes
 *                 through the singleton anyway; the reload of the global
 *                 over r0 is the whole tell.
 *   sub_0203560C  read the u8 at +0x3d of a caller-supplied instance.
 *   sub_02035614  global wrapper over sub_020355F8.
 *   sub_02035630  global wrapper over sub_0203560C.
 *   sub_02035648  global wrapper over sub_020355EC.
 *
 * The range deliberately stops before sub_02035660, the one labelled
 * function of this file: its calls to 0x02036390 and 0x02035E54 have no
 * witness outside the file, so including it caps the whole unit at MATCH.
 * It is parked in src/pending/sub_02035660.c.
 *
 * Every wrapper is a pool word and a `bx ip`, never a displacement
 * branch, because each function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020355C4.c \
 *       --addr 0x020355C4 --arm
 */
u8 sub_020355C4(void)
{
    return g_021469BC.ctx->inputMode;
}























void sub_020355D8(u8 value)
{
    g_021469BC.ctx->inputMode = value;
}























void sub_020355EC(struct UiCtx *ui)
{
    ui->pendingInputFlag = 0;
}























void sub_020355F8(struct UiCtx *unused, u8 value)
{
    g_021469BC.ctx->frameRate = value;
}























u8 sub_0203560C(struct UiCtx *ui)
{
    return ui->frameRate;
}























void sub_02035614(u8 value)
{
    sub_020355F8(g_021469BC.ctx, value);
}























u8 sub_02035630(void)
{
    return sub_0203560C(g_021469BC.ctx);
}























void sub_02035648(void)
{
    sub_020355EC(g_021469BC.ctx);
}






















void sub_02035660(u8 value)
{
    sub_020355F8(g_021469BC.ctx, value);
    sub_02036390(g_021469BC.ctx);
    sub_02035E54(g_021469BC.ctx);
}






















int func_0203568C(void)
{
    return g_021469BC.ctx->powerState;
}























/*
 * A descriptor fan-out: the global at 0x021469BC carries a callback at +4
 * which fills two twelve-byte records on the stack, and the seven
 * accessors below push each pair into the object in inputObj.
 */
void func_020356A0(int inputObj)
{
    UiInputCorner lower;
    UiInputCorner upper;

    if (g_021469BC.getInputBounds == 0) {
        return;
    }
    if (g_021469BC.getInputBounds(&lower, &upper) == 0) {
        return;
    }
    func_020363B8(inputObj, lower.keyParam0, upper.keyParam0);
    func_020363D4(inputObj, lower.keyParam1, upper.keyParam1);
    func_020363F0(inputObj, lower.keyParam2, upper.keyParam2);
    func_02035E84((void *)inputObj, lower.touchX, lower.touchY, upper.touchX, upper.touchY);
    func_02035EB0(inputObj, lower.touchFlagA, upper.touchFlagA);
    func_02035ECC(inputObj, lower.touchFlagB, upper.touchFlagB);
}
