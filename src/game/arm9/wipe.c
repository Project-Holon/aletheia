/*
 * file:     wipe.c
 * unit:     yes
 * function: func_0202208C, WIPE_SYS_Main, func_020221A4, WIPE_SYS_ExeEnd, WIPE_ResetWndMask, WIPE_ResetBrightness, func_0202223C, WIPE_SetMstBrightColor, WIPE_SetBackColor, WIPE_SetBrightness, WIPE_SYS_Finish, WIPE_SYS_MainPanels, WIPE_SYS_MainPanel, WIPE_SYS_CallPattern, WIPE_SYS_SetDivision, WIPE_SYS_SetDivisionFlags, WIPE_SYS_InitPanel, WIPE_InitHBlankSlots, WIPE_HBlankSlotsTask, WIPE_SetHBlankSlot, WIPE_ClearHBlankSlot, WIPE_RequestSetHBlankSlot, WIPE_RequestClearHBlankSlot, WIPE_SetHBlankSlotTask, WIPE_ClearHBlankSlotTask, WIPE_DummyHBlank
 * address:  0x0202208C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EAC   0x02030EAC  arm
 *   func_0207E3D0   0x0207E3D0  arm
 *   func_0207E468   0x0207E468  arm
 *   g_wipeSys                0x021467A4  data
 *   CARD_GetBackupSectorSize  0x0204E6E0  arm
 *   func_0207D534  0x0207D534  arm
 *   g_wipePatternHandlers  0x0209F538  data
 *   func_02005624  0x02005624  thumb
 *   func_02030734  0x02030734  arm
 *   func_020056A0  0x020056A0  thumb
 *   g_wipeSourceFile     0x020A73C8  data
 *   func_020307B0  0x020307B0  arm
 *   WIPE_SUB_ResolveColor  0x020225F4  thumb
 *   WIPE_SUB_GetEndColor  0x02022608  thumb
 *   WIPE_SUB_RequestBrightnessReset  0x02022640  thumb
 *   WIPE_SUB_ApplyEndBrightness  0x02022670  thumb
 *   WIPE_SUB_ClearSys  0x020226A0  thumb
 *   WIPE_SUB_SetWindowVisible  0x02023B48  thumb
 */
struct Node;
#include "wipe_types.h"

struct Node;

typedef struct {
    u16 paletteBits;
    u16 wait     : 6;
    u16 current    : 5;
    u16 end    : 5;
    u16 color : 15;
    u16 direction   : 1;
    u16 speed   : 5;
    u16 waitCount   : 6;
    u16 pad    : 5;
} PaletteFadeParam;

typedef struct {
    u16 *defaultWork;
    u16 *transWork;
    u32 size;
    PaletteFadeParam param;
} PaletteFadeWork;

typedef struct {
    PaletteFadeWork work[14];
    u16 requestFlag : 2;
    u16 requestBits  : 14;
    u16 transBits : 14;
    u16 taskActive  : 1;
    u16 autoTrans : 1;
    u8  forceStop;
} PaletteFade;

typedef u32 (*FuncPtr)(void *);
extern void func_02030DA8(void *ctx, void (*fn)(void *, PaletteFade *), PaletteFade *p, s32 pri);
extern u32 func_02030EAC(struct Node *n);
extern void func_0207E3D0(void *a, u32 b, u32 c);
extern void func_0207E468(void *a, u32 b, u32 c);
extern u32   CARD_GetBackupSectorSize(void);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void *fn, void *arg, u32 prio);
extern u32 func_020307B0(void *p);
void func_0202208C(void *p1, u32 p2, u32 p3, u16 p4, u32 p5, u32 p6, u32 p7);
void WIPE_SYS_Main(void);
u32 func_020221A4(void);
void WIPE_SYS_ExeEnd(void);
void WIPE_ResetWndMask(void *win);
void WIPE_ResetBrightness(u32 which);
void func_0202223C(u32 a, u32 color);
void WIPE_SetMstBrightColor(u32 color);
void WIPE_SetBackColor(u32 a);
void WIPE_SetBrightness(u32 which, int brightness);
void WIPE_SYS_Finish(struct WipeSys *p);
u32 WIPE_SYS_MainPanels(struct WipeSys *p, void *top, void *bottom);
void WIPE_SYS_MainPanel(u32 *obj, void *arg);
u32 WIPE_SYS_CallPattern(void *p);
void WIPE_SYS_SetDivision(u32 mode, struct WipeSys *p);
void WIPE_SYS_InitPanel(struct WipePanel *s, u32 a, u32 b, s32 c, u32 d, u32 e, u32 f, void *g, void *h, u32 i, u16 j);
void WIPE_InitHBlankSlots(struct WipeHBlankSlots *p);
void WIPE_HBlankSlotsTask(void *task, struct WipeHBlankSlots *p);
void WIPE_SetHBlankSlot(struct WipeHBlankSlots *p, void *ctx, Handler fn, u32 idx);
void WIPE_ClearHBlankSlot(struct WipeHBlankSlots *p, u32 idx);
void WIPE_RequestSetHBlankSlot(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
void WIPE_RequestClearHBlankSlot(u32 a0, u32 a1, u32 a2);
void WIPE_SetHBlankSlotTask(void *a0, u32 *a1);
void WIPE_ClearHBlankSlotTask(struct Node *a0, u32 *a1);
void WIPE_DummyHBlank(void *ctx);
u16 WIPE_SUB_ResolveColor(struct WipeSys *obj, u16 value);
u16 WIPE_SUB_GetEndColor(struct WipeSys *p);
void WIPE_SUB_RequestBrightnessReset(struct WipePanel *s);
void WIPE_SUB_ApplyEndBrightness(struct WipePanel *s);
void WIPE_SUB_ClearSys(struct WipeSys *p);
void WIPE_SUB_SetWindowVisible(u32 val, u32 engine);

extern struct WipeSys g_wipeSys;
extern FuncPtr g_wipePatternHandlers[];
extern char  g_wipeSourceFile[];

/*
 * The setup entry point of the dual-screen window/text cluster whose object
 * lives at 0x021467A4, the same fixed object WIPE_SUB_ClearSys zero-fills in five
 * sub-ranges (0x00/0x14, 0x14/0x30, 0x44/0x30, 0x74/0x18, 0x8C/0xC0) and the
 * one func_0202223C/WIPE_SetMstBrightColor read the sentinel colour out of at +0x150.
 * It divides its sixth argument by CARD_GetBackupSectorSize(), clears the
 * object, runs two configuration calls, then builds the two screens with the
 * same eleven-argument builder WIPE_SYS_InitPanel: sub-object +0x14 with the
 * second argument and mode 0, sub-object +0x44 with the third argument and
 * mode 1, both sharing the buffers at +0x8C and +0x74 and the object the
 * fifth call returned.  It then publishes the two sub-objects through the
 * slots at +0x04 and +0x08, and for each of the two delegate pointers at
 * +0x0C and +0x10 that is non-null it runs WIPE_SUB_RequestBrightnessReset on the matching
 * sub-object and sets the byte flag at +0x14E / +0x14F.
 *
 * Graduated in wave 20B.  It was parked at MATCH only because five of its
 * callees had no branch reference anywhere in the image except the ones in
 * this function, so the `label` class had no witness outside the compared
 * range.  All five are now EXACT manifest entries in pkt_02022174
 * (WIPE_SYS_SetDivision, WIPE_InitHBlankSlots, WIPE_SUB_ResolveColor, WIPE_SYS_InitPanel,
 * WIPE_SUB_RequestBrightnessReset), and every one of those sites resolves on the `matched`
 * class.  g_wipeSys resolves on `literal`, CARD_GetBackupSectorSize,
 * _s32_div_f, WIPE_SUB_ClearSys and WIPE_SYS_MainPanel on `label`.
 *
 * Near miss worth keeping: the division had to be written as a self-recompute,
 *   n = (s32)p6;  n = n / (s32)CARD_GetBackupSectorSize();
 * The single-expression form `(s32)p6 / (s32)CARD_GetBackupSectorSize()`
 * compiles the call first and then rematerialises p6 out of its incoming
 * stack slot into r0, two bytes shorter and a whole-function shift; the
 * original loads p6 into a callee-saved register in the prologue shuffle and
 * only then calls.  See
 * docs/idioms/a-self-recompute-pins-an-operand-before-the-other-side-calls.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202208C.c  *       --func func_0202208C --addr 0x0202208C --cc 1.1p1 --thumb
 */
void func_0202208C(void *p1, u32 p2, u32 p3, u16 p4, u32 p5, u32 p6, u32 p7)
{
    s32    n;
    struct WipeSys *g;
    u16    obj;

    n = (s32)p6;
    n = n / (s32)CARD_GetBackupSectorSize();
    g = &g_wipeSys;
    WIPE_SUB_ClearSys(g);
    WIPE_SYS_SetDivision((u32)p1, g);
    WIPE_InitHBlankSlots(&g->hblank);
    obj = WIPE_SUB_ResolveColor(g, p4);
    WIPE_SYS_InitPanel(&g->mainPanel, p2, p5, n, 0, 0, 0,
                  &g->windowRequests, &g->hblank, p7, obj);
    WIPE_SYS_InitPanel(&g->subPanel, p3, p5, n, 0, 0, 1,
                  &g->windowRequests, &g->hblank, p7, obj);
    g->active = 1;
    WIPE_SYS_MainPanel(&g->mainActive, &g->mainPanel);
    WIPE_SYS_MainPanel(&g->subActive, &g->subPanel);
    if (g->mainUsed != 0) {
        WIPE_SUB_RequestBrightnessReset(&g->mainPanel);
        g->mainResetPending = 1;
    }
    if (g->subUsed != 0) {
        WIPE_SUB_RequestBrightnessReset(&g->subPanel);
        g->subResetPending = 1;
    }
}

/*
 * Per-frame poll for the dual-screen text cluster at 0x021467A4: while the
 * cluster is live (the u16 at +0x14C non-zero) it steps both sub-objects and,
 * when the stepper reports 1, runs the completion handler on the cluster.
 *
 * The +0x14C read costs its own pool word because 0x14C is far past the
 * ldrh immediate reach; it is g_wipeSys + 0x140 with a +0xC displacement,
 * one symbol and not a second object, see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * The follower at 0x020221A4 is a separate leaf function with fan-in 111 and
 * is deliberately NOT folded into a unit here; it keeps its own entry, see
 * docs/idioms/a-unit-attests-only-its-own-start-address.md.  EXACT* is the
 * inferred extent running into that follower, not a byte difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SYS_Main.c \
 *       --func WIPE_SYS_Main --addr 0x02022174 --cc 1.1p1 --thumb
 */
void WIPE_SYS_Main(void)
{
    struct WipeSys *g;

    g = &g_wipeSys;
    if (g_wipeSys.active != 0) {
        if (WIPE_SYS_MainPanels(g, &g->mainPanel, &g->subPanel) == 1)
            WIPE_SYS_Finish(g);
    }
}

/*
 * "Is the dual-screen text cluster idle?", the image's most-called predicate
 * on this object (fan-in 111, mostly from overlay script code): it reports 1
 * when the live counter at +0x14C is zero.  It is a leaf that saves no lr, so
 * disasm.py never labels it and it prints as an anonymous run between two
 * literal pools; see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * It deliberately does not share a file with WIPE_SYS_Main above it: a unit
 * records only its start address, and this address has 111 call sites that
 * need a manifest entry here.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020221A4.c \
 *       --func func_020221A4 --addr 0x020221A4 --cc 1.1p1 --thumb
 */
u32 func_020221A4(void)
{
    if (g_wipeSys.active == 0)
        return 1;
    return 0;
}

/*
 * Shutdown of the dual-screen text cluster, the counterpart of func_0202208C.
 * It drops both entries of the callback block at +0x74, forces each live screen
 * into state 2, unpublishes both sub-objects through the same WIPE_SYS_MainPanel
 * slot writer the setup used, clears the live counter and the two delegate
 * flags at +0x14C/+0x14E/+0x14F, and releases the object.
 *
 * Every pool word here is g_wipeSys with a different displacement (+0x74,
 * +0x00, +0x04, +0x14, +0x08, +0x44, +0x140), one symbol and not seven
 * objects; see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SYS_ExeEnd.c \
 *       --func WIPE_SYS_ExeEnd --addr 0x020221B8 --cc 1.1p1 --thumb
 */
void WIPE_SYS_ExeEnd(void)
{
    WIPE_ClearHBlankSlot(&g_wipeSys.hblank, 0);
    WIPE_ClearHBlankSlot(&g_wipeSys.hblank, 1);
    if (g_wipeSys.mainActive != 0)
        g_wipeSys.mainPanel.phase = 2;
    if (g_wipeSys.subActive != 0)
        g_wipeSys.subPanel.phase = 2;
    WIPE_SYS_MainPanel(&g_wipeSys.mainActive, &g_wipeSys.mainPanel);
    WIPE_SYS_MainPanel(&g_wipeSys.subActive, &g_wipeSys.subPanel);
    g_wipeSys.active = 0;
    g_wipeSys.mainResetPending = 0;
    g_wipeSys.subResetPending = 0;
    WIPE_SUB_ClearSys(&g_wipeSys);
}

/*
 * A two-instruction forwarder (fan-in 22) that pins the first argument of
 * WIPE_SUB_SetWindowVisible to zero and passes the caller's window pointer through as the
 * second.  Tail calls in this compiler are always a pool word and a `bx`,
 * never a displacement branch, because every function gets its own section;
 * see docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * EXACT* is the extent walk running into the second forwarder at 0x02022230,
 * which is an unlabelled leaf with its own callers and keeps its own file.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_ResetWndMask.c \
 *       --func WIPE_ResetWndMask --addr 0x02022224 --cc 1.1p1 --thumb
 */
void WIPE_ResetWndMask(void *win)
{
    WIPE_SUB_SetWindowVisible(0, (u32)win);
}

/*
 * The companion forwarder to WIPE_ResetWndMask: it passes the caller's engine
 * selector straight through to WIPE_SetBrightness and supplies the unused second
 * argument as zero.  Same pool-word-and-`bx` tail call shape.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_ResetBrightness.c \
 *       --func WIPE_ResetBrightness --addr 0x02022230 --cc 1.1p1 --thumb
 */
void WIPE_ResetBrightness(u32 which)
{
    WIPE_SetBrightness(which, 0);
}

/*
 * Maps two sentinel colour values (0xFFFF, "read back the last value
 * written"; 0x7FFF, "white") to two hardware-register-friendly constants
 * and forwards to WIPE_SetBrightness, which selects one of two hardware
 * addresses from its first argument and ignores the colour entirely
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-
 * leftovers.md; WIPE_SetBrightness's own file spells this out).
 *
 * The sentinel readback is `g_wipeSys.color`, a halfword sixteen bytes into
 * a fixed object.  Writing it as `*(u16 *)(0x021468E4 + 0x10)` folds the
 * base and the offset into a single pool word (a plain integer constant
 * has no reason not to), which does not reproduce the original's separate
 * `ldr r1, [pc]; ldrh r1, [r1, #0x10]`.  Declaring the object as an extern
 * struct and taking a real relocation on its base keeps the offset in the
 * instruction encoding instead, matching
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-
 * the-load-reach.md.  The base address is attested by ten other literal
 * pools in the image.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202223C.c \
 *       --func func_0202223C --addr 0x0202223C --cc 1.1p1 --thumb
 */
void func_0202223C(u32 a, u32 color)
{
    if (color == 0xFFFF) {
        color = g_wipeSys.color;
    }
    if (color == 0x7FFF) {
        color = 0x10;
    } else {
        color = ~(u32)0xF;
    }
    WIPE_SetBrightness(a, color);
}

/*
 * Same sentinel-mapping shape as func_0202223C.c, but read-modify-write:
 * it substitutes the sentinel readback the same way, maps the result to
 * one of the same two hardware constants, forwards it to both of
 * WIPE_SetBrightness's hardware selections (0 and 1), and then stores the
 * *pre-mapping* colour back into the same halfword field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SetMstBrightColor.c \
 *       --func WIPE_SetMstBrightColor --addr 0x02022268 --cc 1.1p1 --thumb
 */
void WIPE_SetMstBrightColor(u32 color)
{
    u32 mapped;

    if (color == 0xFFFF) {
        color = g_wipeSys.color;
    }
    if (color == 0x7FFF) {
        mapped = 0x10;
    } else {
        mapped = ~(u32)0xF;
    }
    WIPE_SetBrightness(0, mapped);
    WIPE_SetBrightness(1, mapped);
    g_wipeSys.color = color;
}

void WIPE_SetBackColor(u32 a)
{
    u32 *p = &a;

    func_0207E3D0(p, 0, 2);
    func_0207E468(p, 0, 2);
}

/*
 * Selects one of two hardware register addresses (0x0400006C, 0x0400106C:
 * the master brightness registers of the two DS display engines) from its
 * first argument and passes it to func_0207D534 together with the second
 * argument, the brightness level, which stays in r1 untouched (an argument
 * passed through a register must be named in the C).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SetBrightness.c \
 *       --func WIPE_SetBrightness --addr 0x020222CC --cc 1.1p1 --thumb
 */
void WIPE_SetBrightness(u32 which, int brightness)
{
    if (which == 0) {
        func_0207D534((volatile u16 *)0x0400006C, brightness);
    } else {
        func_0207D534((volatile u16 *)0x0400106C, brightness);
    }
}

/*
 * Teardown for the dual-screen text cluster, run by WIPE_SYS_Main once both
 * screen slots have gone null.  It clears the live flag at +0x14C, latches the
 * value WIPE_SUB_GetEndColor returns into the sentinel colour slot at +0x150, and for
 * each of the two delegates at +0x0C and +0x10 runs the per-screen finaliser
 * WIPE_SUB_ApplyEndBrightness on the matching sub-object.
 *
 * Two notes on the original's shape.  Both delegate arms retest the *same*
 * field, +0x3C, which is the top sub-object's task handle at 0x14 + 0x28; the
 * bottom arm does not use its own +0x6C.  That is the image's behaviour, not a
 * transcription slip, and it is reproduced literally.  Both flag writes also go
 * through the global rather than the incoming pointer, which the encoding
 * distinguishes: the pointer form would reuse r5, the global form spends a
 * pool word at 0x0202233C.
 *
 * 0x14C and 0x150 are both past the strh immediate reach, so the first is
 * materialised as 0x53 << 2 into a register offset and the second derived from
 * it with a single `adds r1, r4, #4`; see
 * docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md for the
 * same derivation on line-number arguments.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SYS_Finish.c \
 *       --func WIPE_SYS_Finish --addr 0x020222EC --cc 1.1p1 --thumb
 */
void WIPE_SYS_Finish(struct WipeSys *p)
{
    p->active = 0;
    p->color = WIPE_SUB_GetEndColor(p);
    if (p->mainUsed != 0) {
        WIPE_SUB_ApplyEndBrightness(&p->mainPanel);
        if (p->mainPanel.fadeOut == 0)
            g_wipeSys.mainResetPending = 0;
    }
    if (p->subUsed != 0) {
        WIPE_SUB_ApplyEndBrightness(&p->subPanel);
        if (p->mainPanel.fadeOut == 0)
            g_wipeSys.subResetPending = 0;
    }
    WIPE_SUB_ClearSys(p);
}

/*
 * One poll step of the dual-screen cluster.  The mode word at +0x00 (the one
 * WIPE_SYS_SetDivision wrote) selects which of the two screen slots gets pumped:
 * mode 0 pumps both, mode 1 prefers the top slot and falls back to the bottom
 * one, mode 2 the mirror of that.  It reports 1 only once both slots have gone
 * null, which is what WIPE_SYS_Main tests before running the teardown.
 *
 * Three cases starting at zero still compile to a cmp chain, not a halfword
 * table: the table form only wins from four cases up.  The two pump calls are
 * written once per arm and cross-jumped by the compiler into the two shared
 * blocks at 0x0202235C and 0x02022376; factoring them behind a label instead
 * moves the branch targets.  See
 * docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md.
 *
 * The tail has to be written as the positive `if (both null) return 1; return
 * 0;`.  The equivalent `if (top || bottom) return 0; return 1;` inverts the
 * second branch and swaps the two constant returns, four bytes wrong.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SYS_MainPanels.c \
 *       --func WIPE_SYS_MainPanels --addr 0x02022340 --cc 1.1p1 --thumb
 */
u32 WIPE_SYS_MainPanels(struct WipeSys *p, void *top, void *bottom)
{
    switch (p->division) {
    case 0:
        WIPE_SYS_MainPanel(&p->mainActive, top);
        WIPE_SYS_MainPanel(&p->subActive, bottom);
        break;
    case 1:
        if (p->mainActive != 0)
            WIPE_SYS_MainPanel(&p->mainActive, top);
        else
            WIPE_SYS_MainPanel(&p->subActive, bottom);
        break;
    case 2:
        if (p->subActive != 0)
            WIPE_SYS_MainPanel(&p->subActive, bottom);
        else
            WIPE_SYS_MainPanel(&p->mainActive, top);
        break;
    }
    if (p->mainActive == 0 && p->subActive == 0)
        return 1;
    return 0;
}

void WIPE_SYS_MainPanel(u32 *obj, void *arg)
{
    if (*obj != 0) {
        if (WIPE_SYS_CallPattern(arg) == 1) {
            *obj = 0;
        }
    }
}

u32 WIPE_SYS_CallPattern(void *p)
{
    u32 idx = ((struct WipePanel *)p)->pattern;
    return g_wipePatternHandlers[idx](p);
}

static void WIPE_SYS_SetDivisionFlags(struct WipeSys *p, u32 kind, u32 a, u32 b);

/*
 * Mode decoder for the dual-screen text cluster: a five-case dense switch on
 * the mode index that fills the five leading words of the object with one of
 * five fixed (kind, flagA, flagB) triples.  The writer at 0x02022424 is an
 * unlabelled leaf static in the same translation unit (no lr save, so
 * disasm.py never labels it); it stores the triple twice, once at +0x00/+0x04/
 * +0x08 and once more at +0x0C/+0x10, which is what makes the two later
 * readers see the same pair of values from either half.  It carries its
 * address as its name, and is listed in `function:` above, so the manifest
 * records the address it covers: coverage is counted per address named by an
 * entry, and a range covered only by a unit names nothing on its own.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020223C0.c \
 *       --addr 0x020223C0 --thumb
 */
void WIPE_SYS_SetDivision(u32 mode, struct WipeSys *p)
{
    switch (mode) {
    case 0:
        WIPE_SYS_SetDivisionFlags(p, 0, 1, 1);
        break;
    case 1:
        WIPE_SYS_SetDivisionFlags(p, 1, 1, 1);
        break;
    case 2:
        WIPE_SYS_SetDivisionFlags(p, 2, 1, 1);
        break;
    case 3:
        WIPE_SYS_SetDivisionFlags(p, 1, 1, 0);
        break;
    case 4:
        WIPE_SYS_SetDivisionFlags(p, 2, 0, 1);
        break;
    }
}

static void WIPE_SYS_SetDivisionFlags(struct WipeSys *p, u32 kind, u32 a, u32 b)
{
    p->division = kind;
    p->mainActive = a;
    p->subActive = b;
    p->mainUsed = a;
    p->subUsed = b;
}

/*
 * The eleven-argument screen descriptor builder func_0202208C runs twice, once
 * per screen: a pure field-by-field copy of the argument list into the 0x26
 * byte sub-object, with no validation at all.  The four register arguments
 * land at +0x00..+0x0C and the seven stacked ones at +0x10..+0x24.
 *
 * Two shape facts the encoding pins down.  The sixth and seventh arguments are
 * stored the other way round from the argument order, +0x14 before +0x10, so
 * the struct's own field order is not the parameter order; writing them in
 * parameter order and letting the scheduler interleave is what reproduces the
 * ldr/str pairing.  The last argument is a u16, not a pointer: it is read back
 * with `add r1, sp, #0` + `ldrh r1, [r1, #0x18]` because Thumb has no
 * halfword load with an sp base, and stored with `strh`.  That is the value
 * WIPE_SUB_ResolveColor resolved, so the sentinel slot at +0x150 is a u16 end to end.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SYS_InitPanel.c \
 *       --func WIPE_SYS_InitPanel --addr 0x02022430 --cc 1.1p1 --thumb
 */
void WIPE_SYS_InitPanel(struct WipePanel *s, u32 a, u32 b, s32 c, u32 d, u32 e,
                   u32 f, void *g, void *h, u32 i, u16 j)
{
    s->pattern = a;
    s->frames = b;
    s->wait = c;
    s->phase = d;
    s->work = (void *)e;
    s->screen = f;
    s->windowRequests = (struct WindowRequests *)g;
    s->hblank = (u32)h;
    s->heapId = i;
    s->color = j;
}

/*
 * Resets the 24-byte two-entry callback block at +0x74 of the dual-screen
 * text object (the buffer func_0202208C hands to both screen builders):
 * three parallel two-element arrays, the context pointers at +0x00, the
 * handlers at +0x08 and the user words at +0x10.  Both handler slots are
 * armed with the do-nothing WIPE_DummyHBlank rather than a null, so the
 * dispatcher never has to test them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_InitHBlankSlots.c \
 *       --func WIPE_InitHBlankSlots --addr 0x02022458 --cc 1.1p1 --thumb
 */
void WIPE_InitHBlankSlots(struct WipeHBlankSlots *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        p->work[i] = 0;
        p->func[i] = WIPE_DummyHBlank;
        p->active[i] = 0;
    }
}

void WIPE_HBlankSlotsTask(void *task, struct WipeHBlankSlots *p)
{
    int i;
    for (i = 0; i < 2; i++)
        p->func[i](p->work[i]);
}

/*
 * Arms one entry of the two-slot callback block at +0x74 of the dual-screen
 * text cluster: the exact inverse of WIPE_ClearHBlankSlot.  It publishes the
 * context pointer at ctx[idx], the handler at fn[idx] (falling back to the
 * do-nothing WIPE_DummyHBlank when the caller passes none, the same convention
 * WIPE_InitHBlankSlots uses), and marks the slot live with arg[idx] = 1.  Before
 * any of that, if BOTH user words are still zero the block was idle, so it
 * registers the dispatcher WIPE_HBlankSlotsTask as a task through func_02005624 and
 * parks the handle at g_wipeSys.hblankTask -- the same handle WIPE_ClearHBlankSlot
 * releases once both words go back to zero.
 *
 * Data flow checked against both neighbours: WIPE_ClearHBlankSlot clears arg[idx]
 * first and only then tests both words, this function tests both words first
 * and only then writes, so the handle is created exactly once per
 * idle-to-live transition and released exactly once per live-to-idle one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SetHBlankSlot.c \
 *       --func WIPE_SetHBlankSlot --addr 0x02022490 --cc 1.1p1 --thumb --lang c99
 */
void WIPE_SetHBlankSlot(struct WipeHBlankSlots *p, void *ctx, Handler fn, u32 idx)
{
    if (p->active[0] == 0 && p->active[1] == 0)
        g_wipeSys.hblankTask = func_02005624((u32)WIPE_HBlankSlotsTask, (u32)p, 0);

    p->work[idx] = ctx;
    if (fn != 0)
        p->func[idx] = fn;
    else
        p->func[idx] = WIPE_DummyHBlank;
    p->active[idx] = 1;
}

/*
 * Drops one entry of the two-slot callback block WIPE_InitHBlankSlots arms (the
 * 0x18-byte object at +0x74 of the dual-screen cluster): three parallel
 * two-element arrays, ctx[] at +0x00, fn[] at +0x08 and arg[] at +0x10.
 * WIPE_SYS_ExeEnd calls it once per slot during shutdown.
 *
 * It clears this slot's user word FIRST, and only then checks whether both
 * user words have gone to zero; when they have and the vblank/task handle at
 * g_wipeSys.hblankTask is still live, it releases that handle through
 * func_02030EAC and nulls it.  The slot's handler is then re-armed with the
 * do-nothing WIPE_DummyHBlank rather than a null, the same convention
 * WIPE_InitHBlankSlots uses, and the context pointer cleared last.
 *
 * Shape notes.  The zero written to arg[idx] and the zero written back to
 * +0x54 are one value kept in r6 across the call, which is what makes them
 * one named local rather than two literal zeroes; the final ctx[idx] = 0
 * uses a fresh `movs r0, #0` after the call instead, so it must be written
 * as a plain constant.  The two `adds r0, r5, r4` recomputations of
 * &slot[idx] on either side of the guard are the compiler's own
 * rematerialisation of the scaled index, not two separate cursors; keeping
 * the address in a named local costs a callee-saved register, see
 * docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_ClearHBlankSlot.c \
 *       --func WIPE_ClearHBlankSlot --addr 0x020224DC --cc 1.1p1 --thumb
 */
void WIPE_ClearHBlankSlot(struct WipeHBlankSlots *p, u32 idx)
{
    u32 zero = 0;

    p->active[idx] = zero;
    if (p->active[0] == 0 && p->active[1] == 0 && g_wipeSys.hblankTask != 0) {
        func_02030EAC(g_wipeSys.hblankTask);
        g_wipeSys.hblankTask = (void *)zero;
    }
    p->func[idx] = WIPE_DummyHBlank;
    p->work[idx] = 0;
}

/*
 *           The only branch reaching 0x020225B4 image-wide is this pool word; 0x020225B4
 *           itself is src/pending/WIPE_SetHBlankSlotTask.c, MATCH-capped on 0x02022490, so the
 *           'matched' class has nothing to offer. Every concrete byte is identical
 *           (0 concrete diffs, 4/4 relocations correct, 3 resolved).
 */
void WIPE_RequestSetHBlankSlot(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 *p;

    p = (u32 *)func_02030734((u16)(((u16)a4 & 0x7FFF) | 0x8000), 0x10, 0,
                             g_wipeSourceFile, 0x3E8);
    p[0] = a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    func_020056A0((void *)WIPE_SetHBlankSlotTask, p, 0x400);
}

void WIPE_RequestClearHBlankSlot(u32 a0, u32 a1, u32 a2)
{
    u32 *p = func_02030734((u16)(((u16)a2 & 0x7fff) | 0x8000), 8, 0, g_wipeSourceFile, 0x401);

    p[0] = a0;
    p[1] = a1;
    func_020056A0((void *)WIPE_ClearHBlankSlotTask, p, 8 << 7);
}

/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 */
void WIPE_SetHBlankSlotTask(void *a0, u32 *a1)
{
    WIPE_SetHBlankSlot((struct WipeHBlankSlots *)a1[0], (void *)a1[1], (Handler)a1[2], a1[3]);
    func_02030EAC(a0);
    func_020307B0(a1);
}

void WIPE_ClearHBlankSlotTask(struct Node *a0, u32 *a1)
{
    WIPE_ClearHBlankSlot((struct WipeHBlankSlots *)a1[0], a1[1]);
    func_02030EAC(a0);
    func_020307B0(a1);
}

/*
 * The do-nothing default handler the two-entry callback table in
 * WIPE_InitHBlankSlots is initialised with: a single `bx lr` plus two bytes of
 * section padding.  It has no branch reference anywhere in the image, only
 * the ABS32 pool word at 0x02022474 that takes its address, so an EXACT
 * entry here is what lets WIPE_InitHBlankSlots resolve that pool word on the
 * `matched` class.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/WIPE_DummyHBlank.c \
 *       --addr 0x020225F0 --thumb
 */
void WIPE_DummyHBlank(void *ctx)
{
}
