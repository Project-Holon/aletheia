/*
 * file:     net_state_p04.c
 * unit:     yes
 * function: func_0203CDBC, func_0203CDD4, func_0203CEAC, func_0203CF04, func_0203CF10, func_0203CF3C, func_0203CF5C, func_0203CFA0, func_0203CFF0, func_0203D000, func_0203D010, func_0203D01C, func_0203D060
 * address:  0x0203CDBC
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
 *   func_0203D788   0x0203D788  arm
 *   func_020398B4  0x020398B4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02034714  0x02034714  arm
 *   func_02034FB8  0x02034FB8  arm
 *   func_0200F234  0x0200F234  thumb
 *   g_021469E0     0x021469E0  data
 *   str_020A7CA0   0x020A7CA0  data
 *   str_020A7CE8   0x020A7CE8  data
 *   func_0203DA20  0x0203DA20  arm
 *   func_0203C774  0x0203C774  arm
 *   func_0203BF9C  0x0203BF9C  arm
 *   func_020370C8  0x020370C8  arm
 *   func_0203BFF0  0x0203BFF0  arm
 *   func_0203EA9C 0x0203EA9C  arm
 *   func_0203DC70 0x0203DC70  arm
 *   func_0203B1D8 0x0203B1D8  arm
 *   func_02037154 0x02037154  arm
 *   func_02039D94 0x02039D94  arm
 *   func_02037C10 0x02037C10  arm
 *   func_02039594 0x02039594  arm
 *   g_021469DC     0x021469DC  data
 *   func_0203B0C4  0x0203B0C4  arm
 *   func_0203B1B0  0x0203B1B0  arm
 *   func_0203C3B4  0x0203C3B4  arm
 *   func_0203B2D0  0x0203B2D0  arm
 */
#include "../../matched/include/Obj15974.h"
#include "../../matched/include/Obj15975.h"
#include "../../matched/include/Obj15976.h"
#include "../../matched/include/Obj11372.h"
#include "../../matched/include/Obj15978.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct NetCtx;

struct Entry {
    void *obj;
    u8    pad_04[4];
    void *slot[8];
    u8    pad_28[0x16];
    u16   key3e;
    u16   key40;
    u8    pad_42[2];
    u16   key44;
    u16   key46;
    u8    pad_48;
    u8    f49;
    u8    f4a;
    u8    pad_4b[5];
};

struct NetVtbl {
    void (*f00)(u32 a, u32 b);
    void (*f04)(u16 key, struct NetCtx *ctx, u32 zero, u32 arg);
    void (*f08)(u32 a);
    int  (*f0C)(u32 a);
    u32  (*f10)(u32 a, u32 b);
    u32  (*f14)(u32 a);
    u8   pad18[0x28 - 0x18];
    u32  (*f28)(u32 a);
    void *(*f2C)(u32 a);
    u8   pad30[0x38 - 0x30];
    u32  (*f38)(u32 a);
    void (*f3C)(void *cb);
    u32  (*f40)(u32 a, u32 b);
    u32  (*f44)(u32 a, u32 b);
    u32  (*f48)(u32 a, u32 b, u32 c, u32 d, u32 e);
    u8   pad4C[4];
    u32  (*f50)(int a, u32 b, u32 c);
    u32  (*f54)(u32 a, u32 b);
    u32  (*f58)(void);
    u32  (*f5C)(u32 a);
    u32  (*f60)(u32 a);
    u32  (*f64)(u32 a, u32 b, u32 c, void *d);
    void (*f68)(void *cb);
    u32  (*f6C)(void);
    int  (*f70)(void);
    u32  (*f74)(void);
    u32  (*f78)(void);
    u32  (*f7C)(void);
    int  (*f80)(void);
    u32  (*f84)(void);
    int  (*f88)(void);
    void (*f8C)(u32 a);
    u32  (*f90)(u32 a);
    u8   pad94[0x9C - 0x94];
    void (*f9C)(void);
    u32  (*fA0)(void);
    u32  (*fA4)(void);
    u32  (*fA8)(void);
    u32  (*fAC)(void);
    int  (*fB0)(void);
    void (*fB4)(void);
    void (*fB8)(void *arg);
    int  (*fBC)(void);
    void (*fC0)(int a);
    void (*fC4)(u32 a);
    void (*fC8)(u32 a);
};

struct NetCtx {
    u8   pad00[0x08];
    void (*f08)(u32 a, u32 b);
    void (*f0C)(int a, u32 b);
    u32  (*f10)(u32 a);
    u32  (*f14)(u32 a);
    u8   pad18[0x1C - 0x18];
    void (*f1C)(void);
    u8   pad20[0x24 - 0x20];
    void (*f24)(u32 a, u32 b, u32 c);
    void (*f28)(u32 a, u32 b, u32 c);
    void (*f2C)(u32 a);
    void (*f30)(u32 a);
    u8   pad34[0x40 - 0x34];
    u32  (*f40)(u32 a);
    u32  (*f44)(u32 a);
    u8   pad48[0x56 - 0x48];
    u16  f56;
    u16  f58;
    u16  f5A;
    u16  f5C;
    u16  f5E;
    u8   f60;
    u8   f61;
    u8   pad62[2];
    u8   f64;
    u8   f65;
    u8   f66;
    u8   f67;
    u8   pad68[4];
    u16  f6C;
    u16  f6E;
    struct Entry table[9];
    struct NetVtbl *vt;
    u32  f344;
    void (*f348)(u32 a);
    u32  f34C;
    u8   pad350[2];
    u8   f352;
};

struct NetCtx;

struct NetCtx;

struct NetCtx;

typedef u32 (*Fn_0203CF10)(u32);

typedef void *(*Fn_0203CF3C)(u32);

typedef signed char   s8;

extern struct NetCtx *func_0203D788(void);
void func_020398B4(struct NetCtx *unused);
extern u32 func_020307B0(void *p);
extern void func_020306F0(u32 a);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02034FB8(u32 a);
extern void func_0200F234(u32 a);
extern void func_0203DA20(void);
extern void func_0203C774(u32 v);
extern void func_0203BF9C(u32 v);
extern void func_020370C8(void);
extern void func_0203BFF0(void);
extern void func_0203EA9C(void);
extern void func_0203DC70(void);
extern u32 func_0203B1D8(void);
extern void func_02037154(void);
extern void func_02039D94(void);
extern int func_02037C10(void);
extern int func_02039594(void);
extern struct NetCtx *func_0203D798(void);
extern void func_0203B0C4(int a0, int a1);
extern void func_0203B1B0(void);
extern void func_0203C3B4(void);
extern void func_0203B2D0(u32 a);
extern int func_0203DA4C(void);
extern void *func_0203DA7C(void *a0, void *a1, void *a2);
extern void func_0203BA98(u16 a0, u32 a1, u8 a2);
int func_0203CDBC(void);
void func_0203CDD4(void);
int func_0203CEAC(void (*a0)(u32));
void func_0203CF04(void);
u32 func_0203CF10(u32 a);
void *func_0203CF3C(u32 a);
u32 func_0203CF5C(void);
void func_0203CFA0(void);
void func_0203CFF0(void *p);
void func_0203D000(void *p);
void func_0203D010(void);
void func_0203D01C(void);
void func_0203D060(u32 a, u32 b, u32 c);
extern u32 g_021469E0[];
extern char str_020A7CA0[];
extern char str_020A7CE8[];



int func_0203CDBC(void)
{
    return func_0203D788() == 0;
}



/*
 * Net teardown/mode dispatch.  Fetches the state record, snapshots four
 * fields, fires two optional callbacks through function-pointer fields,
 * runs the shared shutdown calls, clears a word of the global block and
 * then dispatches on the mode byte.
 *
 * THE DISPATCH BASE IS THE WHOLE PUZZLE, and it is worth stating plainly
 * because an off-by-one here costs a whole pass.  The image has:
 *
 *   0203CE3C  cmp   r8, #6
 *   0203CE40  addls pc, pc, r8, lsl #2
 *   0203CE44  b     #0x203ce78          <- NOT table[0]
 *   0203CE48  b     #0x203ce8c          <- table[0]
 *
 * `addls pc, pc, ...` reads pc as the instruction address PLUS 8, so the
 * base is 0x0203CE40 + 8 = 0x0203CE48 and entry k sits at 0x0203CE48 + 4k.
 * The word at 0x0203CE44, which LOOKS like the first table slot in a plain
 * byte diff, is the out-of-range fallthrough branch to the default arm.
 * Reading it as table[0] shifts every case by one and yields a residue that
 * no source-level edit can fix: the blocks all land at the right addresses
 * and only the dispatch words differ.  The true mapping is
 *
 *   0 -> break      1 -> f(b)    2 -> f(b)    3 -> f(c)
 *   4 -> f(c)       5 -> break   6 -> f(b)    default -> assert, return
 *
 * The assert arm must be spelled `default:`, not `case 0:`; with an
 * explicit case 0 the fallthrough word at 0x0203CE44 is wrong.
 *
 * PERMUTER RESULT (negative, and recorded because it is the evidence that
 * the residue was structural rather than an allocation tie):
 *   hill,   budget 800,  --types: 181 single mutations, none improved.
 *   anneal, budget 3000, --types: 3000 compiles in 128s, completely flat at
 *   asm=30 bytes-out=8 size=216/216, never once below the baseline.
 * Six different source orderings of the five arms were also measured by
 * hand and every one gave byte-identical output.  A residue that flat is
 * not a spelling problem, which is what sent the work back to the dispatch
 * arithmetic.
 *
 * func_0200F234 is THUMB and reached by `blx`; declaring it arm makes
 * match.py refuse the site outright (it checks the .thumb_func marker).
 * The g_021469E0 store is written g_021469E0[2] rather than
 * *(u32 *)(0x021469E0 + 8): the constant-plus-offset form folds the +8
 * into the pool word and compiles to `str r1, [r0]`.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0203CDD4.c \
 *       --func func_0203CDD4 --addr 0x0203CDD4 --cc 1.1p1 --arm
 */
void func_0203CDD4(void)
{
    struct NetCtx *s = func_0203D788();
    void (*f)(u32);
    u16 a;
    u16 b;
    u16 c;
    u8 m;

    f = s->f348;
    a = s->f56;
    b = s->f58;
    c = s->f5A;
    m = s->f65;

    if (f != 0)
        f(s->f34C);

    f = s->f2C;
    if (f != 0)
        f(s->f34C);

    func_020398B4(s);
    func_0200F234(m);
    func_020307B0(s);

    g_021469E0[2] = 0;

    switch (m) {
    case 1:
    case 2:
    case 6:
        func_020306F0(b);
        break;
    case 3:
    case 4:
        func_020306F0(c);
        break;
    case 0:
    case 5:
        break;
    default:
        func_02034714(str_020A7CA0, 0xEE, str_020A7CE8);
        return;
    }

    func_020306F0(a);
    func_02034FB8(4);
}



/*
 * Net bring-up: fetch the state object, run its per-frame tick, and if the
 * object exists stamp the caller's handle into it, then install one of two
 * handlers according to the object's mode byte and finish with the shared
 * tail.  Both handler installs take the same address (0x0203CDD4) and the
 * image loads it from one pool word at 0x0203CF00, so the source names the
 * function at both call sites rather than hoisting it into a local.
 *
 * FILED EXACT 2026-09-22.  This file sat in src/pending as MATCH on two
 * blockers that were both bookkeeping errors, not evidence gaps:
 *
 *   * the `bl` at +0040 was declared `func_0203D70C8` / `0x0203D70C8`, an
 *     address with NINE hex digits.  The instruction is `bl #0x20370c8`, so
 *     the target is 0x020370C8 -- a stray `D`.  The real address is an EXACT
 *     manifest entry (src/matched/func_020370C8.c) and also carries 15
 *     outside branches, so it attests as `label` immediately.
 *   * the ABS32 at +0054 was declared `g_0203CDD4 ... data`.  0x0203CDD4 is
 *     a traced ARM function start (it pushes lr), i.e. this is a FUNCTION
 *     POINTER argument, not a data address.  Declared `data` it was routed
 *     to sole-ref/data, which correctly refuses a code target; declared
 *     `arm` it resolves through sole-ref/code.
 *
 * The C itself was already byte-correct and is unchanged apart from the two
 * declarations and the argument type (void * rather than u8 *).
 *
 * Two spellings still matter, from the original lane's work:
 *   * `if (p != 0) { ... return 1; } return 0;` -- the `if (p == 0) return 0;`
 *     guard form compiles to `moveq r0, #0` + `popeq {r3, r4, r5, pc}` and
 *     shifts every following byte; the image branches to a separate
 *     out-of-line `mov r0, #0; pop {...}` block at 0x0203CEF8.
 *   * the mode byte is read into a named local *before* the caller's handle
 *     is stored into the object, which is the image's order (`ldrb r0,
 *     [r4, #0x65]` at +001C, `str r5, [r4, #0x348]` at +0020).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0203CEAC.c \
 *       --func func_0203CEAC --addr 0x0203CEAC --cc 1.1p1 --arm
 */
int func_0203CEAC(void (*a0)(u32))
{
    struct NetCtx *p;

    p = func_0203D788();
    func_0203DA20();
    if (p != 0) {
        u8 t = p->f65;

        p->f348 = a0;
        if (t == 1) {
            func_0203C774((u32)func_0203CDD4);
        } else {
            func_0203BF9C((u32)func_0203CDD4);
        }
        func_020370C8();
        return 1;
    }
    return 0;
}



void func_0203CF04(void)
{
    func_0203BFF0();
}



/*
 * Dispatches through the vtable at +0x340 of the state object: the entry at
 * +0x28 takes the single argument and its result is returned.  A missing state
 * object is the `moveq`/`popeq` pair that answers 0.  The vtable pointer
 * itself is not checked - src/matched/func_0203D17C.c is the neighbouring
 * hook that does check it.
 *
 * The indirect call is a register `blx` with an ordinary `pop {r4, pc}`
 * epilogue: not the ARMv4T-style return that would name a 1.2-built function,
 * so it is compiled C like any other.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CF10.c \
 *       --func func_0203CF10 --addr 0x0203CF10 --cc 1.1p1 --arm
 */
u32 func_0203CF10(u32 a)
{
    struct NetCtx *p;

    p = func_0203D788();
    if (p == 0)
        return 0;
    return p->vt->f28(a);
}



/*
 * The same vtable dispatch as src/matched/func_0203CF10.c, one slot further
 * on (+0x2C) and without the null test: the state object is assumed live and
 * the hook's pointer result is returned to the caller.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CF3C.c \
 *       --func func_0203CF3C --addr 0x0203CF3C --cc 1.1p1 --arm
 */
void *func_0203CF3C(u32 a)
{
    struct NetCtx *p;

    p = func_0203D788();
    return p->vt->f2C(a);
}



/*
 *           --suggest-split offers nothing (single function, all four
 *           unresolved sites' only witnesses are inside this range).
 *           all four) -- each has no witness outside 0203CF5C..0203CFA0; every
 *           branch to them in the image is this function's own call. Four of
 *           the eight sites resolve. Every concrete byte of the body
 *           reproduces. Note the chain is two levels deep: func_0203B1D8,
 *           also called here, is itself a documented DIFF
 *           (docs/notes/pkt_0203B1D8.c.txt) and func_02037154 is a pending
 *           MATCH park.
 */
u32 func_0203CF5C(void)
{
    struct NetCtx *p = func_0203D788();

    func_0203EA9C();
    func_0203DC70();
    if (func_0203B1D8() != 0) {
        return 1;
    }
    if (p == 0) {
        return 1;
    }
    func_02037154();
    func_02039D94();
    func_02037C10();
    return func_02039594();
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CFA0.c \
 *       --func func_0203CFA0 --addr 0x0203CFA0 --cc 1.1p1 --arm
 */
void func_0203CFA0(void)
{
    struct NetCtx *s = func_0203D788();
    struct NetCtx *p;

    if (func_0203B1D8() != 0)
        return;
    if (s == 0 || s->vt == 0)
        return;

    p = func_0203D798();
    switch (p->f65) {
    case 1:
    case 2:
        return;
    }

    s->vt->f0C(0);
}



/*
 * Tail-call wrapper: func_0203B0C4(p, 1).  Called by state 10 of
 * func_0203DC70 with ctx + 0x94.  NOTE: layout/symbols_sdk.txt lists this
 * address as DWC_IsSendableReliable (thumb), a false signature match: the
 * bytes are ARM (`ldr ip, [pc, #4]; mov r1, #1; bx ip`) and the caller
 * reaches it with an ARM `bl`.
 */
void func_0203CFF0(void *p)
{
    func_0203B0C4((int)p, 1);
}



/*
 * Tail-call wrapper: func_0203B0C4(p, 0), the twin of func_0203CFF0.
 * NOTE: layout/symbols_sdk.txt lists this address as FATFS_FormatDrive
 * (thumb), a false signature match: the bytes are ARM.
 */
void func_0203D000(void *p)
{
    func_0203B0C4((int)p, 0);
}



/*
 * Tail-call wrapper (`ldr ip, [pc]; bx ip`, docs/idioms tail-call-is-a-
 * pool-word-and-bx), called by state 10 of func_0203DC70.  An unlabelled
 * ARM leaf inside func_0203CFA0's EXACT* extent; filed as a witness.
 */
void func_0203D010(void)
{
    func_0203B1B0();
}



void func_0203D01C(void)
{
    struct NetCtx *s = func_0203D788();

    switch (s->f65) {
    case 1:
    case 2:
        func_0203C3B4();
        return;
    case 0:
    case 5:
        func_0203B2D0(s->f56);
        return;
    default:
        return;
    }
}


/*
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * `bl` to 0x0203DA7C, whose only caller in the image is this function, and
 * 0x0203DA7C lies past this packet (another lane's), so it cannot be matched
 * from here.
 *
 * The trailing `*` is the usual unlabelled-follower case and not a byte
 * difference: the inferred extent runs on to 0x0203D0D0 because the three
 * eight-byte ARM long-branch veneers at 0x0203D0AC, 0x0203D0B8 and 0x0203D0C4
 * save no `lr` and so carry no label.  They want seeding into
 * layout/function_starts.txt, which is the integrator's file.
 *            caller, address outside this packet)
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D060.c \
 *       --func func_0203D060 --addr 0x0203D060 --cc 1.1p1 --arm
 */
void func_0203D060(u32 a, u32 b, u32 c)
{
    struct NetCtx *s = func_0203D788();
    u32 v = a;

    if (func_0203DA4C() == 1)
        v = (u32)func_0203DA7C((void *)a, (void *)b, (void *)c);

    func_0203BA98(s->f56, v, 1);
}
