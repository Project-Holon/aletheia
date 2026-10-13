/*
 * file:     ui.c
 * unit:     yes
 * function: func_02034E24, func_02034EF8, func_02034F5C, func_02034F74, func_02034F84, func_02034FA0, func_02034FB8, func_02034FD4, func_02034FE8, func_02035004, func_02035010, func_02035034, func_02035040, func_02035064, func_02035080, func_0203508C, func_02035100, func_02035108, func_02035120, func_0203512C, func_02035138, func_0203515C, func_0203516C, func_02035188, func_020351A0, func_020351BC, func_020351D0, func_020351EC, func_020351F8, func_0203521C, func_02035224, func_0203524C, func_02035268, func_02035284, func_020352AC, func_020352DC
 * address:  0x02034E24
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734    0x02030734  arm
 *   MI_CpuFill8      0x02082BCC  arm
 *   KEY_Create    0x02035EE8  arm
 *   TOUCHPANEL_Create    0x020357E0  arm
 *   PM_GetBackLight  0x0208BFD0  arm
 *   gUiState     0x021469BC  data
 *   s_UiFile         0x020A7984  data
 *   KEY_Main  0x020360A8  arm
 *   TOUCHPANEL_Main  0x02035A60  arm
 *   UI_ServiceLidSleep  0x0203545C  arm
 *   sub_020356A0  0x020356A0  arm
 *   KEY_GetCont  0x0203630C  arm
 *   sub_02035544  0x02035544  arm
 *   g_02034F5C_Ptr  0x021469BC  data
 *   func_02034EF8   0x02034EF8  arm
 *   d_021469BC   0x021469BC  data  a4
 *   func_02035080 0x02035080  arm
 *   func_02035120 0x02035120  arm
 *   func_0203515C 0x0203515C arm
 *   func_02035188 0x02035188  arm
 *   func_020351BC 0x020351BC arm
 *   OS_Terminate  0x02088234  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   PM_GetBattery  0x0208BF6C  arm
 *   PM_GetACAdapter 0x0208BFAC  arm
 */
#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)
struct AreaCtx;
struct UiCtx;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef void (*UiCb)(void *);

typedef int  (*UiPred)(void *);

struct UiCtx {
    void   *unk00;
    void   *unk04;
    u32     unk08;
    u32     unk0C;
    UiCb    on_10;
    UiCb    on_14;
    UiCb    on_18;
    UiCb    on_1c;
    UiCb    on_20;
    UiPred  on_24;
    void   *arg_28;
    void   *arg_2c;
    void   *arg_30;
    void   *arg_34;
    u8      always;
    u8      flags39;
    u8      pad3A;
    u8      backlight;
    u8      unk3C;
    u8      unk3D;
    u8      pad3E;
    u8      unk3F;
    u8      mode;
    u8      armed;
    u8      pad42[2];
};

typedef unsigned short u16;

struct AreaCtx {
    u32 unk00;
    u32 unk04;
    void (*fn)(u32);
    u32  arg;
    u8   unk10[0x29];
    u8   inhibit;
    u8   unk3A[4];
    u8   frames;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void *KEY_Create(u32 heap);
extern void *TOUCHPANEL_Create(u32 heap);
extern void  PM_GetBackLight(u32 *top, u32 *bottom);
extern void KEY_Main(void);
extern void TOUCHPANEL_Main(void);
extern void UI_ServiceLidSleep(void);
extern void sub_020356A0(int a0);
extern unsigned int KEY_GetCont(void);
extern void sub_02035544(u32 x);
extern void func_02034EF8(struct AreaCtx *p);
extern void func_02035080(struct UiCtx *p, UiCb fn, void *arg);
extern void func_02035120(struct UiCtx *p, UiCb fn, void *arg);
extern void func_0203515C(struct UiCtx *p, u8 mask);
extern int func_02035188(struct UiCtx *p, u32 v);
extern u32 func_020351BC(struct UiCtx *p, u32 mask);
extern void OS_Terminate(void);
extern int OS_IsRunOnTwl(void);
extern int PM_GetBattery(u32 *out);
extern int PM_GetACAdapter(u16 *out);
void sub_02034E24(u32 heap, u8 mode);
void sub_02034EF8(struct AreaCtx *p);
void sub_02034F5C(void);
void func_02034F74(struct UiCtx *p, u8 flags);
void func_02034F84(u8 flags);
void func_02034FA0(struct UiCtx *p, unsigned char flags);
void func_02034FB8(u8 v);
u32 func_02034FD4(struct UiCtx *p, u8 flags);
u32 func_02034FE8(u8 flags);
void func_02035004(struct UiCtx *o, UiCb a, void *b);
void func_02035010(UiCb a, void *b);
void func_02035034(struct UiCtx *o, UiCb a, void *b);
void func_02035040(UiCb a, void *b);
void func_02035064(UiPred fn, void *arg);
void sub_02035080(struct UiCtx *p, UiCb fn, void *arg);
void func_0203508C(UiCb a, UiCb b, void *c);
UiCb func_02035100(struct UiCtx *p);
UiCb func_02035108(void);
void sub_02035120(struct UiCtx *p, UiCb fn, void *arg);
void func_0203512C(struct UiCtx *p, UiCb fn, void *arg);
void func_02035138(UiCb fn, void *arg);
void sub_0203515C(struct UiCtx *p, u8 mask);
void func_0203516C(u8 mask);
void sub_02035188(struct UiCtx *p, u8 mask);
int func_020351A0(u32 v);
u32 sub_020351BC(struct UiCtx *p, u32 mask);
u32 func_020351D0(u32 mask);
void sub_020351EC(struct UiCtx *p, u32 a, u32 b);
void sub_020351F8(u32 a, u32 b);
u32 sub_0203521C(u32 *p);
struct UiCtx *sub_02035224(void);
void sub_0203524C(struct UiCtx *p);
void sub_02035268(struct UiCtx *p);
void sub_02035284(struct UiCtx *p);
void sub_020352AC(struct UiCtx *p);
void sub_020352DC(void);
extern const char s_UiFile[];
extern void *g_02034F5C_Ptr;
extern struct UiCtx *gUiState;





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
 * The constructor for the 0x44-byte UI context src/pending/sub_02034F5C.c
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
 *   python tools/match.py one --src src/pending/sub_02034E24.c \
 *       --func sub_02034E24 --addr 0x02034E24 --cc 1.1p1 --arm
 */
void sub_02034E24(u32 heap, u8 mode)
{
    struct UiCtx *p;
    u32 a;
    u32 b;

    p = func_02030734(heap, sizeof(struct UiCtx), 0, s_UiFile, 58);
    MI_CpuFill8(p, 0, sizeof(struct UiCtx));

    p->unk00 = KEY_Create(heap);
    p->unk04 = TOUCHPANEL_Create(heap);

    p->unk3C = 0;
    p->unk3D = 0x3C;
    gUiState = p;
    p->mode = mode;
    p->unk3F = 5;

    if (mode == 0) {
        PM_GetBackLight(0, &a);
        p->backlight = a;
    }
    if (mode == 1) {
        PM_GetBackLight(0, &b);
        p->backlight = b;
        func_02034F84(0x10);
        func_0203516C(4);
    }
}





/*
 * One tick of the main loop the areaman singleton drives: bump the frame
 * counter at +0x3e, run the five per-frame services in order, then, only
 * when both pad bits 0x30c are held and the +0x39 inhibit byte is clear,
 * fire the registered callback at +8 with its argument at +0xc and hand 0
 * to sub_02035544.
 *
 * The callback null test and the sub_02035544 call are one block: the `beq`
 * over the `blx` lands on the `mov r0, #0` that sets up the last call, so
 * sub_02035544 runs whether or not a callback was installed.
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
 *   python tools/match.py one --src src/pending/sub_02034EF8.c \
 *       --func sub_02034EF8 --addr 0x02034EF8 --cc 1.1p1 --arm
 */
void sub_02034EF8(struct AreaCtx *p)
{
    p->frames++;

    sub_020352DC();
    KEY_Main();
    TOUCHPANEL_Main();
    UI_ServiceLidSleep();
    sub_020356A0((int)p);

    if ((KEY_GetCont() & 0x30C) == 0x30C && p->inhibit == 0) {
        if (p->fn != 0) {
            p->fn(p->arg);
        }
        sub_02035544(0);
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
 *   python tools/match.py one --src src/pending/sub_02034F5C.c \
 *       --func sub_02034F5C --addr 0x02034F5C --cc 1.1p1 --arm
 */
void sub_02034F5C(void)
{
    func_02034EF8(g_02034F5C_Ptr);
}



void func_02034F74(struct UiCtx *p, u8 flags)
{
    p->always |= flags;
}





void func_02034F84(u8 flags)
{
    func_02034F74(gUiState, flags);
}




void func_02034FA0(struct UiCtx *p, unsigned char flags)
{
    p->always &= (unsigned char)~flags;
}






void func_02034FB8(u8 v)
{
    func_02034FA0(gUiState, v);
}





u32 func_02034FD4(struct UiCtx *p, u8 flags)
{
    return (p->always & flags) != 0;
}






u32 func_02034FE8(u8 flags)
{
    return func_02034FD4(gUiState, flags);
}






/*
 * Setter: stores two values into an object at +0x14 and +0x28.
 */
void func_02035004(struct UiCtx *o, UiCb a, void *b)
{
    o->on_14 = a;
    o->arg_28 = b;
}






/*
 * Wrapper: calls func_02035004 with the object gUiState points at as the first argument.
 */
void func_02035010(UiCb a, void *b)
{
    func_02035004(gUiState, a, b);
}






/*
 * Setter: stores two values into an object at +0x10 and +0x28.
 */
void func_02035034(struct UiCtx *o, UiCb a, void *b)
{
    o->on_10 = a;
    o->arg_28 = b;
}




/*
 * Wrapper: calls func_02035034 with the object gUiState points at as the first argument.
 */
void func_02035040(UiCb a, void *b)
{
    func_02035034(gUiState, a, b);
}



/*
 * Stores a callback and its argument into the object gUiState points at
 * (+0x24 and +0x34).  The pointer is reloaded for the second store because
 * the first store may alias it.  Called from GAMESYSTEM_RegisterSleepCheck and
 * GAMESYSTEM_ReleaseSleepCheck.
 */
void func_02035064(UiPred fn, void *arg)
{
    gUiState->on_24 = fn;
    gUiState->arg_34 = arg;
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
 *   python tools/match.py one --src src/matched/sub_02035080.c \
 *       --func sub_02035080 --addr 0x02035080 --cc 1.1p1 --arm
 */
void sub_02035080(struct UiCtx *p, UiCb fn, void *arg)
{
    p->on_1c = fn;
    p->arg_2c = arg;
}





void func_0203508C(UiCb a, UiCb b, void *c)
{
    struct UiCtx *g = gUiState;

    if (g->armed != 0) {
        if (g->on_18 != 0) {
            g->on_18(g->arg_2c);
        }
        if (a != 0) {
            a(c);
        }
    }
    func_02035080(gUiState, a, c);
    func_02035120(gUiState, b, c);
}





/*
 * An unlabelled leaf.  disasm.py only traces a prologue that saves lr, so this
 * eight-byte getter was printed as `.word 0xE590001C / .word 0xE12FFF1E` in
 * the word run that follows func_0203508C's literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  It is the
 * only callee func_02035108 has, and that neighbour stays capped at MATCH for
 * as long as this address has no manifest entry
 * (docs/idioms/a-veneer-attests-nothing-while-its-target-is-an-unlabelled-leaf.md
 * is the same shape, where the stub in between makes a `matched` entry useless
 * - here the pool word names the leaf directly, so the entry is the unblock).
 */
UiCb func_02035100(struct UiCtx *p)
{
    return p->on_1c;
}






/*
 * closed:   the tail call's target 0x02035100 is now a manifest entry
 *           (matched class); the global resolves on `literal x100`.
 *
 * Promoted out of src/pending: it was parked at MATCH on 0x02035100, an
 * unlabelled eight-byte leaf that had no witness of any class - its only
 * naming pool word is this function's own.  Filing the leaf (see
 * src/matched/func_02035100.c) closes the site with no change here.
 */
UiCb func_02035108(void)
{
    return func_02035100(gUiState);
}






/*
 * Two more plain field setters right after sub_02035080's pair, same shape:
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
void sub_02035120(struct UiCtx *p, UiCb fn, void *arg)
{
    p->on_18 = fn;
    p->arg_2c = arg;
}




void func_0203512C(struct UiCtx *p, UiCb fn, void *arg)
{
    p->on_20 = fn;
    p->arg_30 = arg;
}








/*
 * Tail call: func_0203512C(*gUiState, fn, arg).  Called from GAMESYSTEM_RegisterSleepCallback
 * and GAMESYSTEM_ReleaseSleepCallback.
 */
void func_02035138(UiCb fn, void *arg)
{
    func_0203512C(gUiState, fn, arg);
}








/*
 * The set half of a set/clear pair on the flag byte at +0x39, right after
 * the two tail-call veneers in the same block; no lr push, so disasm.py
 * never labels it. Twin of sub_02035188 (clear).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0203515C.c \
 *       --func sub_0203515C --addr 0x0203515C --cc 1.1p1 --arm
 */
void sub_0203515C(struct UiCtx *p, u8 mask)
{
    p->flags39 |= mask;
}







void func_0203516C(u8 mask)
{
    func_0203515C(gUiState, mask);
}







/*
 * The clear half of the set/clear pair on the flag byte at +0x39. No lr
 * push, so disasm.py never labels it. Twin of sub_0203515C (set).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02035188.c \
 *       --func sub_02035188 --addr 0x02035188 --cc 1.1p1 --arm
 */
void sub_02035188(struct UiCtx *p, u8 mask)
{
    p->flags39 &= ~mask;
}






int func_020351A0(u32 v)
{
    return func_02035188(gUiState, v);
}






/*
 * The test half of the set/clear/test trio on the flag byte at +0x39.
 * No lr push, so disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020351BC.c \
 *       --func sub_020351BC --addr 0x020351BC --cc 1.1p1 --arm
 */
u32 sub_020351BC(struct UiCtx *p, u32 mask)
{
    return (p->flags39 & mask) != 0;
}






u32 func_020351D0(u32 mask)
{
    return func_020351BC(gUiState, mask);
}







/*
 * A plain two-field setter, same shape as sub_02035080/sub_02035120: "str
 * r1,[r0,#8]; str r2,[r0,#0xc]; bx lr", twelve bytes, no relocations. No lr
 * push, so disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020351EC.c \
 *       --func sub_020351EC --addr 0x020351EC --cc 1.1p1 --arm
 */
void sub_020351EC(struct UiCtx *p, u32 a, u32 b)
{
    p->unk08 = a;
    p->unk0C = b;
}






/*
 * Forwards both arguments to the setter sub_020351EC on the object held in
 * gUiState (a tail call through ip).  No lr push, so disasm.py never
 * labels it; filed so its ov088/ov172 callers can resolve the BLX.
 */
void sub_020351F8(u32 a, u32 b)
{
    sub_020351EC(gUiState, a, b);
}






/*
 * A trivial pointer-dereference getter: "ldr r0,[r0]; bx lr", eight bytes,
 * no relocations. No lr push, so disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0203521C.c \
 *       --func sub_0203521C --addr 0x0203521C --cc 1.1p1 --arm
 */
u32 sub_0203521C(u32 *p)
{
    return *p;
}






/*
 * The singleton accessor for the UI context sub_02034E24 publishes: stop the
 * machine if it has not been constructed yet, otherwise hand it back.  The
 * pointer is loaded twice off the one pool word because OS_Terminate is an
 * ordinary extern as far as the compiler is concerned, so the global has to
 * be re-read after the call.
 *
 * This is the most-called function in the 0x02035000 block: a hundred-odd
 * branches reach it image-wide.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035224.c \
 *       --func sub_02035224 --addr 0x02035224 --cc 1.1p1 --arm
 */
struct UiCtx *sub_02035224(void)
{
    if (gUiState == 0) {
        OS_Terminate();
    }
    return gUiState;
}






/*
 * One of the five optional callback slots the UI context carries: run the
 * hook at +0x14 with its own argument at +0x28 if one is installed, and do
 * nothing otherwise.  The argument is loaded only on the taken path, after
 * the null test, so the null check cannot be folded into the call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203524C.c \n *       --func sub_0203524C --addr 0x0203524C --cc 1.1p1 --arm
 */
void sub_0203524C(struct UiCtx *p)
{
    if (p->on_14 != 0) {
        p->on_14(p->arg_28);
    }
}






/*
 * The +0x10 callback slot, same shape as sub_0203524C and sharing its
 * argument word at +0x28.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035268.c \n *       --func sub_02035268 --addr 0x02035268 --cc 1.1p1 --arm
 */
void sub_02035268(struct UiCtx *p)
{
    if (p->on_10 != 0) {
        p->on_10(p->arg_28);
    }
}






/*
 * Arm the context: run the +0x1c hook with the +0x2c argument and set the
 * armed flag at +0x41.  sub_020352AC is the disarming half.  The flag is set
 * only when a hook was actually installed, so it stays inside the guard.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035284.c \n *       --func sub_02035284 --addr 0x02035284 --cc 1.1p1 --arm
 */
void sub_02035284(struct UiCtx *p)
{
    if (p->on_1c != 0) {
        p->on_1c(p->arg_2c);
        p->armed = 1;
    }
}






/*
 * The disarming half of sub_02035284: run the +0x18 hook with the same
 * +0x2c argument and clear the armed flag, but only if the context was armed
 * in the first place.
 *
 * The two conditions are one `&&`, not a nested pair of `if`s: they share a
 * single `popeq` epilogue, which the chain-of-returns spelling would split
 * into two (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020352AC.c \n *       --func sub_020352AC --addr 0x020352AC --cc 1.1p1 --arm
 */
void sub_020352AC(struct UiCtx *p)
{
    if (p->on_18 != 0 && p->armed != 0) {
        p->on_18(p->arg_2c);
        p->armed = 0;
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
void sub_020352DC(void)
{
    u16 ac;
    u32 bat;

    if (unk_02FFFC3C % 600 != 1)
        return;

    if (OS_IsRunOnTwl() != 0) {
        if (PM_GetACAdapter(&ac) == 0)
            gUiState->unk3F = ac;
        return;
    }

    if (PM_GetBattery(&bat) != 0)
        return;
    if (bat == 0)
        gUiState->unk3F = 5;
    else
        gUiState->unk3F = 1;
}
