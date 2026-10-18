/*
 * file:     ui.c
 * unit:     yes
 * function: UI_Create, UI_Main, UI_Update, UI_SetKeepAwakeFlags, UI_SetKeepAwakeFlagsGlobal, UI_ClearKeepAwakeFlags, UI_ClearKeepAwakeFlagsGlobal, UI_TestKeepAwakeFlags, UI_TestKeepAwakeFlagsGlobal, UI_SetSleepHook, UI_SetSleepHookGlobal, UI_SetWakeHook, UI_SetWakeHookGlobal, UI_SetKeepAwakePred, UI_SetSuspendHook, UI_SetResumeAndSuspendHooks, UI_GetSuspendHook, UI_GetSuspendHookGlobal, UI_SetResumeHook, UI_SetWakePoweredHook, UI_SetWakePoweredHookGlobal, UI_SetFlags39, UI_SetFlags39Global, UI_ClearFlags39, UI_ClearFlags39Global, UI_TestFlags39, UI_TestFlags39Global, UI_SetIntrData, UI_SetIntrDataGlobal, UI_GetPointerValue, UI_GetContext, UI_RunSleepHook, UI_RunWakeHook, UI_RunSuspendHook, UI_RunResumeHook, UI_PollPower, DWCi_IsFold, UI_IsPowerConnected, UI_RunWakePoweredHook, UI_IsSleepInhibited, UI_SetBottomBackLight, UI_ServiceLidSleep, UI_SoftReset, UI_GetInputMode, UI_SetInputMode, UI_ClearPendingInputFlagOf, UI_SetFrameRateOf, UI_ChangeFrameRate, UI_GetPowerState, UI_ApplyInputBounds
 * address:  0x02034E24
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * ui_p02.c folded in here as one whole TU (0x020353B0..0x02035750).
 *
 * symbols:
 *   GFL_HEAP_Alloc    0x02030734  arm
 *   MI_CpuFill8      0x02082BCC  arm
 *   KEY_Create    0x02035EE8  arm
 *   TOUCHPANEL_Create    0x020357E0  arm
 *   PM_GetBackLight  0x0208BFD0  arm
 *   gUiState     0x021469BC  data
 *   s_UiFile         0x020A7984  data
 *   KEY_Main  0x020360A8  arm
 *   TOUCHPANEL_Main  0x02035A60  arm
 *   UI_ServiceLidSleep  0x0203545C  arm
 *   UI_ApplyInputBounds  0x020356A0  arm
 *   KEY_GetCont  0x0203630C  arm
 *   UI_SoftReset  0x02035544  arm
 *   g_02034F5C_Ptr  0x021469BC  data
 *   UI_Main   0x02034EF8  arm
 *   d_021469BC   0x021469BC  data  a4
 *   UI_SetSuspendHook 0x02035080  arm
 *   UI_SetResumeHook 0x02035120  arm
 *   UI_SetFlags39 0x0203515C arm
 *   UI_ClearFlags39 0x02035188  arm
 *   UI_TestFlags39 0x020351BC arm
 *   OS_Terminate  0x02088234  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   PM_GetBattery  0x0208BF6C  arm
 *   PM_GetACAdapter 0x0208BFAC  arm
 *   UI_IsPowerConnected  0x020353B0  arm
 *   PM_SetBackLight 0x0208BDD8  arm
 *   UI_GetContext   0x02035224  arm
 *   UI_IsSleepInhibited   0x020353F8  arm
 *   TOUCHPANEL_AutoSamplingStop   0x02035E08  arm
 *   UI_RunSleepHook   0x0203524C  arm
 *   PM_GoSleepMode  0x0208C154  arm
 *   UI_RunWakePoweredHook   0x020353C8  arm
 *   UI_RunResumeHook   0x020352AC  arm
 *   UI_RunWakeHook   0x02035268  arm
 *   TOUCHPANEL_AutoSamplingRestart   0x02035DC8  arm
 *   UI_SetBottomBackLight   0x02035428  arm
 *   UI_RunSuspendHook   0x02035284  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   OS_ResetSystem            0x02087BCC  arm
 *   OS_WaitIrq                0x0208459C  arm
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
#define SYS_TICK_COUNTER (*(volatile u32 *)0x02FFFC3C)
struct UiCtx;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef void (*UiCb)(void *);

typedef int  (*UiPred)(void *);

typedef void (*UiIntrFunc)(u32);

/* The UI context pointed at by gUiState.ctx (0x021469BC).  touchpanel.c and the
 * areaman tick UI_Main are all views of this one object; the fields
 * follow the names those files use (keyWork/tpWork/onWake..resumeArmed). */
struct UiCtx {
    void   *keyWork;          /* 0x00 KEY_Create result */
    void   *tpWork;           /* 0x04 TOUCHPANEL_Create result */
    UiIntrFunc intrData;      /* 0x08 per-frame interrupt callback */
    u32     intrArg;          /* 0x0C its argument */
    UiCb    onWake;           /* 0x10 */
    UiCb    onSleep;          /* 0x14 */
    UiCb    onResume;         /* 0x18 */
    UiCb    onSuspend;        /* 0x1C */
    UiCb    onWakePowered;    /* 0x20 */
    UiPred  keepAwakePred;    /* 0x24 */
    void   *sleepWakeArg;     /* 0x28 */
    void   *suspendResumeArg; /* 0x2C */
    void   *wakePoweredArg;   /* 0x30 */
    void   *keepAwakeArg;     /* 0x34 */
    u8      keepAwakeFlags;   /* 0x38 */
    u8      flags39;          /* 0x39 */
    u8      reserved3A;       /* 0x3A */
    u8      backlightState;   /* 0x3B */
    u8      inputMode;        /* 0x3C */
    u8      frameRate;        /* 0x3D */
    u8      frameCounter;     /* 0x3E */
    u8      powerState;       /* 0x3F */
    u8      mode;             /* 0x40 */
    u8      resumeArmed;      /* 0x41 */
    u8      reserved42;       /* 0x42 */
    u8      suspended;        /* 0x43 */
};

typedef unsigned short u16;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void *KEY_Create(u32 heap);
extern void *TOUCHPANEL_Create(u32 heap);
extern void  PM_GetBackLight(u32 *top, u32 *bottom);
extern void KEY_Main(void);
extern void TOUCHPANEL_Main(void);
extern void UI_ServiceLidSleep(void);
extern void UI_ApplyInputBounds(int a0);
extern unsigned int KEY_GetCont(void);
extern void UI_SoftReset(u32 x);
extern void UI_SetSuspendHook(struct UiCtx *p, UiCb fn, void *arg);
extern void UI_SetResumeHook(struct UiCtx *p, UiCb fn, void *arg);
extern void UI_SetFlags39(struct UiCtx *p, u8 mask);
extern int UI_ClearFlags39(struct UiCtx *p, u32 v);
extern u32 UI_TestFlags39(struct UiCtx *p, u32 mask);
extern void OS_Terminate(void);
extern int OS_IsRunOnTwl(void);
extern int PM_GetBattery(u32 *out);
extern int PM_GetACAdapter(u16 *out);
void UI_Create(u32 heap, u8 mode);
void UI_Main(struct UiCtx *p);
void UI_Update(void);
void UI_SetKeepAwakeFlags(struct UiCtx *p, u8 flags);
void UI_SetKeepAwakeFlagsGlobal(u8 flags);
void UI_ClearKeepAwakeFlags(struct UiCtx *p, unsigned char flags);
void UI_ClearKeepAwakeFlagsGlobal(u8 v);
u32 UI_TestKeepAwakeFlags(struct UiCtx *p, u8 flags);
u32 UI_TestKeepAwakeFlagsGlobal(u8 flags);
void UI_SetSleepHook(struct UiCtx *o, UiCb a, void *b);
void UI_SetSleepHookGlobal(UiCb a, void *b);
void UI_SetWakeHook(struct UiCtx *o, UiCb a, void *b);
void UI_SetWakeHookGlobal(UiCb a, void *b);
void UI_SetKeepAwakePred(UiPred fn, void *arg);
void UI_SetSuspendHook(struct UiCtx *p, UiCb fn, void *arg);
void UI_SetResumeAndSuspendHooks(UiCb a, UiCb b, void *c);
UiCb UI_GetSuspendHook(struct UiCtx *p);
UiCb UI_GetSuspendHookGlobal(void);
void UI_SetResumeHook(struct UiCtx *p, UiCb fn, void *arg);
void UI_SetWakePoweredHook(struct UiCtx *p, UiCb fn, void *arg);
void UI_SetWakePoweredHookGlobal(UiCb fn, void *arg);
void UI_SetFlags39(struct UiCtx *p, u8 mask);
void UI_SetFlags39Global(u8 mask);
void UI_ClearFlags39(struct UiCtx *p, u8 mask);
int UI_ClearFlags39Global(u32 v);
u32 UI_TestFlags39(struct UiCtx *p, u32 mask);
u32 UI_TestFlags39Global(u32 mask);
void UI_SetIntrData(struct UiCtx *p, u32 a, u32 b);
void UI_SetIntrDataGlobal(u32 a, u32 b);
u32 UI_GetPointerValue(u32 *p);
struct UiCtx *UI_GetContext(void);
void UI_RunSleepHook(struct UiCtx *p);
void UI_RunWakeHook(struct UiCtx *p);
void UI_RunSuspendHook(struct UiCtx *p);
void UI_RunResumeHook(struct UiCtx *p);
void UI_PollPower(void);
asm void DWCi_IsFold(void);
extern const char s_UiFile[];
/* The UI singleton.  ui.c reads the context pointer at +0x00; the input
 * bounds callback UI_ApplyInputBounds dispatches through lives at +0x04.  Both
 * are fields of the one object at 0x021469BC. */
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
    struct UiCtx *ctx;                                             /* 0x00 */
    int (*getInputBounds)(UiInputCorner *lower, UiInputCorner *upper); /* 0x04 */
} UiState;

extern UiState gUiState;






/*
 * BLOCKER (re-derived after 0x020357E0 was filed in pkt_020357E0): the
 * two capped sites this file used to name -- KEY_Create and
 * TOUCHPANEL_Create -- both resolve now (`matched`), and 9 of the 10
 * relocation sites are closed.  The single remaining one is
 *
 *   +00CC ABS32 s_UiFile  0x020A7984 (data, declared in symbols)
 *          -> no witness outside 02034E24..02034EF8
 *
 * 0x020A7984 is a string whose only pool word in the image is inside this
 * function's own extent, and attest_string() refuses it: the bytes before
 * it are not a NUL run that fixes its start.  No cut exists inside a
 * single function section, so --suggest-split offers nothing.  It
 * graduates the same way every own-pool string does: when some other
 * matched function happens to pool 0x020A7984, or when the string area's
 * neighbours are attested.
 *
 * The constructor for the 0x44-byte UI context src/pending/UI_Update.c
 * tail-calls through: allocate and zero it, fill the two sub-objects at +0
 * and +4 from the same heap, seed the fixed +0x3c / +0x3d / +0x3f bytes,
 * publish it at 0x021469BC, and stash the mode argument at +0x40.
 *
 * Note this is a different translation unit from the rest of pkt_02034978:
 * the debug file string here is "ui.c" at 0x020A7984, not the
 * "gf_overlay.c" at 0x020A7970 that GF_OVERLAY_Init and GF_OVERLAY_CheckRangeFree use.  The
 * boundary between the two units falls between 0x02034DC4 and 0x02034E24.
 *
 * The two mode tests are sequential `if`s, not an if/else chain: mode 0 only
 * caches the backlight state, mode 1 caches it and then runs the two extra
 * services.  Each PM_GetBackLight call gets its own stack slot, the later
 * declaration at the lower address.
 *
 * PARKED AT MATCH.  Every concrete byte is right.  Three relocation sites
 * have no witness:
 *
 *   0x02035EE8 and 0x020357E0 are each called from exactly this one place in
 *   the image, so `label` has nothing outside the range to offer.  Both are
 *   in this territory and both unstick as soon as they are themselves EXACT
 *   (class `matched`).
 *
 *   0x020A7984, the file string "ui.c", is the harder one.  It has exactly
 *   one pool word image-wide, this function's own, so `literal` discards its
 *   only witness; and `string` will not take it either, because the run
 *   before it is the one-byte "0" at 0x020A7980 whose NUL is followed by two
 *   bytes of alignment padding, so the terminator does not fix where this
 *   string starts.  Same shape as
 *   docs/idioms/a-string-after-a-data-table-has-no-witness.md.  Nothing in
 *   this packet can create that witness; it needs a second allocation site
 *   in ui.c, most plausibly in an overlay.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_Create.c \
 *       --func UI_Create --addr 0x02034E24 --cc 1.1p1 --arm
 */
void UI_Create(u32 heap, u8 mode)
{
    struct UiCtx *p;
    u32 a;
    u32 b;

    p = GFL_HEAP_Alloc(heap, sizeof(struct UiCtx), 0, s_UiFile, 58);
    MI_CpuFill8(p, 0, sizeof(struct UiCtx));

    p->keyWork = KEY_Create(heap);
    p->tpWork = TOUCHPANEL_Create(heap);

    p->inputMode = 0;
    p->frameRate = 0x3C;
    gUiState.ctx = p;
    p->mode = mode;
    p->powerState = 5;

    if (mode == 0) {
        PM_GetBackLight(0, &a);
        p->backlightState = a;
    }
    if (mode == 1) {
        PM_GetBackLight(0, &b);
        p->backlightState = b;
        UI_SetKeepAwakeFlagsGlobal(0x10);
        UI_SetFlags39Global(4);
    }
}






/*
 * One tick of the main loop the areaman singleton drives: bump the frame
 * counter at +0x3e, run the five per-frame services in order, then, only
 * when both pad bits 0x30c are held and the +0x39 inhibit byte is clear,
 * fire the registered callback at +8 with its argument at +0xc and hand 0
 * to UI_SoftReset.
 *
 * The callback null test and the UI_SoftReset call are one block: the `beq`
 * over the `blx` lands on the `mov r0, #0` that sets up the last call, so
 * UI_SoftReset runs whether or not a callback was installed.
 *
 * PARKED AT MATCH.  Every concrete byte is right.  All five per-frame
 * services it calls are reached from this one site only, so each needs to be
 * EXACT in the manifest before its `bl` resolves on `matched`:
 *
 *   0x020352DC, 0x020360A8, 0x02035A60, 0x0203545C, 0x020356A0
 *
 * Of those, 0x0203545C is the blocker that cannot be cleared from inside
 * this territory: src/pending/UI_ServiceLidSleep.c is byte-correct but capped on
 * PM_GoSleepMode (0x0208C154), which the whole image calls exactly once,
 * from that function.  0x02035A60 and 0x020360A8 are byte-correct too
 * (src/pending/) and capped on their own single-caller callees 0x020358A0
 * and 0x02035F38.  So this function stays MATCH until the 0x02035000 block
 * is finished bottom-up, and even then only if PM_GoSleepMode acquires a
 * second call site.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_Main.c \
 *       --func UI_Main --addr 0x02034EF8 --cc 1.1p1 --arm
 */
void UI_Main(struct UiCtx *p)
{
    p->frameCounter++;

    UI_PollPower();
    KEY_Main();
    TOUCHPANEL_Main();
    UI_ServiceLidSleep();
    UI_ApplyInputBounds((int)p);

    if ((KEY_GetCont() & 0x30C) == 0x30C && p->flags39 == 0) {
        if (p->intrData != 0) {
            p->intrData(p->intrArg);
        }
        UI_SoftReset((u32)(0));
    }
}





/*
 * A tail call, `ldr r3,[pc]`/`bx r3`, passing one argument through: the
 * value of a global pointer, dereferenced once.
 *
 * Every concrete byte matches; neither the global pointer nor the callee
 * (both single-use, so far, in this ROM) has a witness outside this one
 * function, so both ABS32 sites stay unresolved under the honesty rule.
 * The tool also reports the original's listing extent as 40 bytes against
 * this function's 24: the territory ends at 0x02034FA0 with no further
 * label, so `disasm.py`'s extent runs into an unlabelled follower the
 * same way docs/MATCHING.md's "two missing labels" section describes.
 * That follower is outside this file's scope.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_Update.c \
 *       --func UI_Update --addr 0x02034F5C --cc 1.1p1 --arm
 */
void UI_Update(void)
{
    UI_Main(gUiState.ctx);
}




void UI_SetKeepAwakeFlags(struct UiCtx *p, u8 flags)
{
    p->keepAwakeFlags |= flags;
}






void UI_SetKeepAwakeFlagsGlobal(u8 flags)
{
    UI_SetKeepAwakeFlags(gUiState.ctx, flags);
}





void UI_ClearKeepAwakeFlags(struct UiCtx *p, unsigned char flags)
{
    p->keepAwakeFlags &= (unsigned char)~flags;
}







void UI_ClearKeepAwakeFlagsGlobal(u8 v)
{
    UI_ClearKeepAwakeFlags(gUiState.ctx, v);
}






u32 UI_TestKeepAwakeFlags(struct UiCtx *p, u8 flags)
{
    return (p->keepAwakeFlags & flags) != 0;
}







u32 UI_TestKeepAwakeFlagsGlobal(u8 flags)
{
    return UI_TestKeepAwakeFlags(gUiState.ctx, flags);
}







/*
 * Setter: stores two values into an object at +0x14 and +0x28.
 */
void UI_SetSleepHook(struct UiCtx *o, UiCb a, void *b)
{
    o->onSleep = a;
    o->sleepWakeArg = b;
}







/*
 * Wrapper: calls UI_SetSleepHook with the object gUiState.ctx points at as the first argument.
 */
void UI_SetSleepHookGlobal(UiCb a, void *b)
{
    UI_SetSleepHook(gUiState.ctx, a, b);
}







/*
 * Setter: stores two values into an object at +0x10 and +0x28.
 */
void UI_SetWakeHook(struct UiCtx *o, UiCb a, void *b)
{
    o->onWake = a;
    o->sleepWakeArg = b;
}





/*
 * Wrapper: calls UI_SetWakeHook with the object gUiState.ctx points at as the first argument.
 */
void UI_SetWakeHookGlobal(UiCb a, void *b)
{
    UI_SetWakeHook(gUiState.ctx, a, b);
}




/*
 * Stores a callback and its argument into the object gUiState.ctx points at
 * (+0x24 and +0x34).  The pointer is reloaded for the second store because
 * the first store may alias it.  Called from GAMESYSTEM_RegisterSleepCheck and
 * GAMESYSTEM_ReleaseSleepCheck.
 */
void UI_SetKeepAwakePred(UiPred fn, void *arg)
{
    gUiState.ctx->keepAwakePred = fn;
    gUiState.ctx->keepAwakeArg = arg;
}







/*
 * A plain two-field setter in the ARM SDK-style block at
 * 0x02035000..0x02038000: "str r1,[r0,#0x1c]; str r2,[r0,#0x2c]; bx lr",
 * twelve bytes, no relocations at all.  The struct here only pins the two
 * offsets this function touches, not the real layout.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_SetSuspendHook.c \
 *       --func UI_SetSuspendHook --addr 0x02035080 --cc 1.1p1 --arm
 */
void UI_SetSuspendHook(struct UiCtx *p, UiCb fn, void *arg)
{
    p->onSuspend = fn;
    p->suspendResumeArg = arg;
}






void UI_SetResumeAndSuspendHooks(UiCb a, UiCb b, void *c)
{
    struct UiCtx *g = gUiState.ctx;

    if (g->resumeArmed != 0) {
        if (g->onResume != 0) {
            g->onResume(g->suspendResumeArg);
        }
        if (a != 0) {
            a(c);
        }
    }
    UI_SetSuspendHook(gUiState.ctx, a, c);
    UI_SetResumeHook(gUiState.ctx, b, c);
}






/*
 * An unlabelled leaf.  disasm.py only traces a prologue that saves lr, so this
 * eight-byte getter was printed as `.word 0xE590001C / .word 0xE12FFF1E` in
 * the word run that follows UI_SetResumeAndSuspendHooks's literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  It is the
 * only callee UI_GetSuspendHookGlobal has, and that neighbour stays capped at MATCH for
 * as long as this address has no manifest entry
 * (docs/idioms/a-veneer-attests-nothing-while-its-target-is-an-unlabelled-leaf.md
 * is the same shape, where the stub in between makes a `matched` entry useless
 * - here the pool word names the leaf directly, so the entry is the unblock).
 */
UiCb UI_GetSuspendHook(struct UiCtx *p)
{
    return p->onSuspend;
}







/*
 * closed:   the tail call's target 0x02035100 is now a manifest entry
 *           (matched class); the global resolves on `literal x100`.
 *
 * Promoted out of src/pending: it was parked at MATCH on 0x02035100, an
 * unlabelled eight-byte leaf that had no witness of any class - its only
 * naming pool word is this function's own.  Filing the leaf (see
 * src/matched/UI_GetSuspendHook.c) closes the site with no change here.
 */
UiCb UI_GetSuspendHookGlobal(void)
{
    return UI_GetSuspendHook(gUiState.ctx);
}







/*
 * Two more plain field setters right after UI_SetSuspendHook's pair, same shape:
 * "str r1,[r0,#0x18]; str r2,[r0,#0x2c]; bx lr" then
 * "str r1,[r0,#0x20]; str r2,[r0,#0x30]; bx lr", twelve bytes each, no
 * relocations.  A third function follows in the same block at 0x02035138
 * (not attempted here: it loads through two pool words and is not a plain
 * accessor).
 *
 * The struct here only pins the four offsets these two functions touch, not
 * the real layout.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035120.c \
 *       --addr 0x02035120 --arm
 */
void UI_SetResumeHook(struct UiCtx *p, UiCb fn, void *arg)
{
    p->onResume = fn;
    p->suspendResumeArg = arg;
}





void UI_SetWakePoweredHook(struct UiCtx *p, UiCb fn, void *arg)
{
    p->onWakePowered = fn;
    p->wakePoweredArg = arg;
}









/*
 * Tail call: UI_SetWakePoweredHook(*gUiState.ctx, fn, arg).  Called from GAMESYSTEM_RegisterSleepCallback
 * and GAMESYSTEM_ReleaseSleepCallback.
 */
void UI_SetWakePoweredHookGlobal(UiCb fn, void *arg)
{
    UI_SetWakePoweredHook(gUiState.ctx, fn, arg);
}









/*
 * The set half of a set/clear pair on the flag byte at +0x39, right after
 * the two tail-call veneers in the same block; no lr push, so disasm.py
 * never labels it. Twin of UI_ClearFlags39 (clear).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_SetFlags39.c \
 *       --func UI_SetFlags39 --addr 0x0203515C --cc 1.1p1 --arm
 */
void UI_SetFlags39(struct UiCtx *p, u8 mask)
{
    p->flags39 |= mask;
}








void UI_SetFlags39Global(u8 mask)
{
    UI_SetFlags39(gUiState.ctx, mask);
}








/*
 * The clear half of the set/clear pair on the flag byte at +0x39. No lr
 * push, so disasm.py never labels it. Twin of UI_SetFlags39 (set).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_ClearFlags39.c \
 *       --func UI_ClearFlags39 --addr 0x02035188 --cc 1.1p1 --arm
 */
void UI_ClearFlags39(struct UiCtx *p, u8 mask)
{
    p->flags39 &= ~mask;
}







int UI_ClearFlags39Global(u32 v)
{
    return UI_ClearFlags39(gUiState.ctx, v);
}







/*
 * The test half of the set/clear/test trio on the flag byte at +0x39.
 * No lr push, so disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_TestFlags39.c \
 *       --func UI_TestFlags39 --addr 0x020351BC --cc 1.1p1 --arm
 */
u32 UI_TestFlags39(struct UiCtx *p, u32 mask)
{
    return (p->flags39 & mask) != 0;
}







u32 UI_TestFlags39Global(u32 mask)
{
    return UI_TestFlags39(gUiState.ctx, mask);
}








/*
 * A plain two-field setter, same shape as UI_SetSuspendHook/UI_SetResumeHook: "str
 * r1,[r0,#8]; str r2,[r0,#0xc]; bx lr", twelve bytes, no relocations. No lr
 * push, so disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_SetIntrData.c \
 *       --func UI_SetIntrData --addr 0x020351EC --cc 1.1p1 --arm
 */
void UI_SetIntrData(struct UiCtx *p, u32 a, u32 b)
{
    p->intrData = (UiIntrFunc)a;
    p->intrArg = b;
}







/*
 * Forwards both arguments to the setter UI_SetIntrData on the object held in
 * gUiState.ctx (a tail call through ip).  No lr push, so disasm.py never
 * labels it; filed so its ov088/ov172 callers can resolve the BLX.
 */
void UI_SetIntrDataGlobal(u32 a, u32 b)
{
    UI_SetIntrData(gUiState.ctx, a, b);
}







/*
 * A trivial pointer-dereference getter: "ldr r0,[r0]; bx lr", eight bytes,
 * no relocations. No lr push, so disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_GetPointerValue.c \
 *       --func UI_GetPointerValue --addr 0x0203521C --cc 1.1p1 --arm
 */
u32 UI_GetPointerValue(u32 *p)
{
    return *p;
}







/*
 * The singleton accessor for the UI context UI_Create publishes: stop the
 * machine if it has not been constructed yet, otherwise hand it back.  The
 * pointer is loaded twice off the one pool word because OS_Terminate is an
 * ordinary extern as far as the compiler is concerned, so the global has to
 * be re-read after the call.
 *
 * This is the most-called function in the 0x02035000 block: a hundred-odd
 * branches reach it image-wide.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_GetContext.c \
 *       --func UI_GetContext --addr 0x02035224 --cc 1.1p1 --arm
 */
struct UiCtx *UI_GetContext(void)
{
    if (gUiState.ctx == 0) {
        OS_Terminate();
    }
    return gUiState.ctx;
}







/*
 * One of the five optional callback slots the UI context carries: run the
 * hook at +0x14 with its own argument at +0x28 if one is installed, and do
 * nothing otherwise.  The argument is loaded only on the taken path, after
 * the null test, so the null check cannot be folded into the call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_RunSleepHook.c \n *       --func UI_RunSleepHook --addr 0x0203524C --cc 1.1p1 --arm
 */
void UI_RunSleepHook(struct UiCtx *p)
{
    if (p->onSleep != 0) {
        p->onSleep(p->sleepWakeArg);
    }
}







/*
 * The +0x10 callback slot, same shape as UI_RunSleepHook and sharing its
 * argument word at +0x28.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_RunWakeHook.c \n *       --func UI_RunWakeHook --addr 0x02035268 --cc 1.1p1 --arm
 */
void UI_RunWakeHook(struct UiCtx *p)
{
    if (p->onWake != 0) {
        p->onWake(p->sleepWakeArg);
    }
}







/*
 * Arm the context: run the +0x1c hook with the +0x2c argument and set the
 * armed flag at +0x41.  UI_RunResumeHook is the disarming half.  The flag is set
 * only when a hook was actually installed, so it stays inside the guard.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_RunSuspendHook.c \n *       --func UI_RunSuspendHook --addr 0x02035284 --cc 1.1p1 --arm
 */
void UI_RunSuspendHook(struct UiCtx *p)
{
    if (p->onSuspend != 0) {
        p->onSuspend(p->suspendResumeArg);
        p->resumeArmed = 1;
    }
}







/*
 * The disarming half of UI_RunSuspendHook: run the +0x18 hook with the same
 * +0x2c argument and clear the armed flag, but only if the context was armed
 * in the first place.
 *
 * The two conditions are one `&&`, not a nested pair of `if`s: they share a
 * single `popeq` epilogue, which the chain-of-returns spelling would split
 * into two (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_RunResumeHook.c \n *       --func UI_RunResumeHook --addr 0x020352AC --cc 1.1p1 --arm
 */
void UI_RunResumeHook(struct UiCtx *p)
{
    if (p->onResume != 0 && p->resumeArmed != 0) {
        p->onResume(p->suspendResumeArg);
        p->resumeArmed = 0;
    }
}







/*
 * BLOCKED on two relocation sites: all 180 concrete bytes are correct,
 * 2 of 4 sites resolve, and the two that do not are
 *
 *   +0044 PC24 PM_GetACAdapter  0x0208BFAC  -> no witness outside range
 *   +0068 PC24 PM_GetBattery    0x0208BF6C  -> no witness outside range
 *
 * Each is called exactly once in the whole image and that call is here,
 * so the `label` class refuses them (every witness would be in-range),
 * and no cut exists inside a single function section, so
 * --suggest-split offers nothing.  Both are plain TwlSDK libspi
 * entry points (pm.o), so they graduate the moment any *other* caller
 * turns up, or when the libspi block around 0x0208BF00 is itself
 * matched.  Nothing about the C can change this.
 *
 * Ten-second power poll: the shared tick word at 0x02FFFC3C is read once
 * and the body only runs on the tick where `tick % 600` is 1, i.e. one
 * tick past each ten-second roll-over.  The modulus is the compiler's
 * own unsigned magic-multiply for the constant 600 (umull by 0x1B4E81B5,
 * high word >> 6, umull by 600, subtract), so the value must be an
 * unsigned 32-bit read -- declaring it signed drops the umull pair.
 *
 * On a DSi the AC adapter state wins and is written straight through;
 * on a DS the battery flag is read as a 32-bit word and is mapped to 5
 * (no charge) or 1 (charging).  Both arms of the second branch are short
 * enough that mwcc predicates them instead of branching, which is why
 * the global pointer is re-loaded in each arm rather than hoisted.
 */
void UI_PollPower(void)
{
    u16 ac;
    u32 bat;

    if (SYS_TICK_COUNTER % 600 != 1)
        return;

    if (OS_IsRunOnTwl() != 0) {
        if (PM_GetACAdapter(&ac) == 0)
            gUiState.ctx->powerState = ac;
        return;
    }

    if (PM_GetBattery(&bat) != 0)
        return;
    if (bat == 0)
        gUiState.ctx->powerState = 5;
    else
        gUiState.ctx->powerState = 1;
}

asm void DWCi_IsFold(void)
{
    ldr r0, =0x02FFFFA8
    ldrh r0, [r0]
    and r0, r0, #0x8000
    movs r0, r0, asr #15
    movne r0, #1
    moveq r0, #0
    bx lr
}

extern int PM_SetBackLight(u32 which, u32 status);
extern void TOUCHPANEL_AutoSamplingStop(void);
extern void PM_GoSleepMode(u32 trigger, u32 a, u32 b);
extern void TOUCHPANEL_AutoSamplingRestart(void);
extern void UI_RunSuspendHook(struct UiCtx *ui);
extern struct UiCtx *UI_GetContext(void);
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
 * The lid/sleep service, one of the five UI_Main runs per frame.  Bit
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
 * This is what caps src/pending/UI_Main.c as well.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_ServiceLidSleep.c \
 *       --func UI_ServiceLidSleep --addr 0x0203545C --cc 1.1p1 --arm
 */
void UI_ServiceLidSleep(void)
{
    struct UiCtx *ui;

    ui = UI_GetContext();

    if ((*(u16 *)0x02FFFFA8 & 0x8000) >> 15) {
        if (UI_IsSleepInhibited(ui) == 0) {
            TOUCHPANEL_AutoSamplingStop();
            UI_RunSleepHook(ui);
            PM_GoSleepMode(0xC, 0, 0);
            UI_RunWakePoweredHook(ui);
            UI_RunResumeHook(ui);
            UI_RunWakeHook(ui);
            TOUCHPANEL_AutoSamplingRestart();
            if (ui->suspended != 0) {
                ui->suspended = 0;
                UI_SetBottomBackLight(ui->backlightState);
            }
        } else {
            if (ui->suspended == 0) {
                ui->suspended = 1;
                UI_SetBottomBackLight(0);
                UI_RunSuspendHook(ui);
                UI_RunSleepHook(ui);
            }
        }
    } else {
        if (ui->suspended != 0) {
            ui->suspended = 0;
            UI_SetBottomBackLight(ui->backlightState);
            UI_RunWakeHook(ui);
            UI_RunResumeHook(ui);
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

    ui = UI_GetContext();
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
    ui->frameCounter = 0;
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
