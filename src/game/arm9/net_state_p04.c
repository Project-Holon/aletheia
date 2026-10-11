/*
 * file:     net_state_p04.c
 * unit:     yes
 * function: func_0203CDBC, func_0203CDD4, func_0203CEAC, func_0203CF04, func_0203CF10, func_0203CF3C, func_0203CF5C, func_0203CFA0, func_0203CFF0, func_0203D000, func_0203D010, func_0203D01C, func_0203D060, func_0203D0AC, func_0203D0B8, func_0203D0C4, func_0203D0D0, func_0203D0DC, func_0203D0FC, func_0203D10C, func_0203D12C, func_0203D14C, func_0203D158, func_0203D164, func_0203D170, func_0203D17C, func_0203D1A4, func_0203D1B4, func_0203D1C0, func_0203D1E8, func_0203D210, func_0203D24C, func_0203D26C, func_0203D29C, func_0203D2CC, func_0203D34C, func_0203D378, func_0203D394, func_0203D3A8, func_0203D3F8, func_0203D4D0, func_0203D56C, func_0203D578, func_0203D594, func_0203D5A0, func_0203D5AC, func_0203D5D4, func_0203D5EC, func_0203D610
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
 *   func_0203E5AC  0x0203E5AC  arm
 *   func_0203DBB0  0x0203DBB0  arm
 *   func_0203DA68  0x0203DA68  arm
 *   func_0203C010  0x0203C010  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_02037A44  0x02037A44  arm
 *   func_0203BD30  0x0203BD30  arm
 *   func_0203E4E8  0x0203E4E8  arm
 *   func_0203E538  0x0203E538  arm
 *   func_0203E590  0x0203E590  arm
 *   func_020395EC  0x020395EC  arm
 *   func_020399EC  0x020399EC  arm
 *   func_0203996C  0x0203996C  arm
 *   func_020399B8  0x020399B8  arm
 *   func_0203D798  0x0203D798  arm
 *   g_020A7CA0     0x020A7CA0  data
 *   g_020A7CE8     0x020A7CE8  data
 *   func_020338F8  0x020338F8  arm
 *   func_02037010  0x02037010  arm
 *   func_02037118  0x02037118  arm
 *   func_02039338  0x02039338  arm
 *   func_02038C18  0x02038C18  arm
 *   g_020A7CEC     0x020A7CEC  data
 *   func_02039468  0x02039468  arm
 *   func_020394C0  0x020394C0  arm
 *   func_02039C3C  0x02039C3C  arm
 *   func_02039CA0  0x02039CA0  arm
 */
#include "../../matched/include/Obj15974.h"
#include "../../matched/include/Obj15975.h"
#include "../../matched/include/Obj15976.h"
#include "../../matched/include/Obj11372.h"
#include "../../matched/include/Obj15978.h"
#include "../../matched/include/Obj15979.h"
#include "../../matched/include/Obj15980.h"

struct NetCtx;
struct Entry;
struct Link;
struct NetEntry;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

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

typedef u32 (*Fn_0203CF10)(u32);

typedef void *(*Fn_0203CF3C)(u32);

typedef signed char   s8;

struct Singleton {
    u8    pad_00[8];
    void *unk_08;
};

typedef void (*Fn)(u32);

typedef signed int     s32;

typedef unsigned char u32_pad;

typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

struct NetEntry {
    u8 pad_00[0x4a];
    u8 state;
};

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
extern void func_0203E5AC(int a0);
extern void func_0203DBB0(void);
extern void func_0203DA68(unsigned int value);
extern void func_0203D9EC(void);
extern void func_0203C010(void);
extern int func_0203CD98(void);
extern void func_02037A44(int a);
extern void func_0203BD30(u32 a0, u32 a1, u8 *a2);
extern u32 func_0203E4E8(void);
extern void func_0203E538(int a0);
extern int func_0203E590(void);
extern int func_020395EC(struct Entry *a);
extern int func_020399EC(void);
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_020399B8(u8 *p);
extern u32  func_020338F8(void);
extern void func_02037010(u32 a, u32 b, u32 c, u32 d);
extern void func_02037118(u32 a, u32 b);
extern u16 func_02039338(void);
extern int   func_02038C18(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u32   func_02039468(u32 a, u32 b);
extern int func_020394C0(void);
extern void func_02039C3C(void *p, u16 tag);
extern void func_02039CA0(void);
extern void func_0203A458(u8 *a0, u32 a1);
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
void func_0203D0AC(int a0);
void func_0203D0B8(void);
void func_0203D0C4(unsigned int value);
void func_0203D0D0(void);
void func_0203D0DC(u32 a0);
void func_0203D0FC(int a);
void func_0203D10C(u32 a0);
void func_0203D12C(int a);
void func_0203D14C(u32 a0, u32 a1, u8 *a2);
u32 func_0203D158(void);
void func_0203D164(int a0);
int func_0203D170(void);
void func_0203D17C(u32 a);
u32 func_0203D1A4(struct Link *p);
int func_0203D1B4(void);
u32 func_0203D1C0(u32 index);
void func_0203D1E8(u32 unused, void *arg);
u32 func_0203D210(void);
void func_0203D24C(u16 a, u16 b);
u32 func_0203D26C(void);
u32 func_0203D29C(void);
void func_0203D2CC(void);
void func_0203D34C(u32 a, u32 b);
u32 func_0203D378(void);
u32 func_0203D394(struct NetEntry *e);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_0203D56C(void);
void func_0203D578(int a, u32 b);
void func_0203D594(void *p, u16 tag);
void func_0203D5A0(void);
void func_0203D5AC(int a, int b);
u32 func_0203D5D4(void);
u32 func_0203D5EC(void);
u32 func_0203D610(void);
extern struct Singleton g_021469E0;
extern char str_020A7CA0[];
extern char str_020A7CE8[];
extern char g_020A7CA0[];
extern char g_020A7CE8[];
extern char g_020A7CEC[];







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

    g_021469E0.unk_08 = 0;

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





void func_0203D0AC(int a0)
{
    func_0203E5AC(a0);
}





void func_0203D0B8(void)
{
    func_0203DBB0();
}





void func_0203D0C4(unsigned int value)
{
    func_0203DA68(value);
}





void func_0203D0D0(void){ func_0203D9EC(); }






void func_0203D0DC(u32 a0)
{
    func_0203BA98(func_0203D788()->f56, a0, 1);
}




void func_0203D0FC(int a)
{
    func_0203D788();
    func_0203C010();
}


void func_0203D10C(u32 a0)
{
    func_0203BA98(func_0203D788()->f56, a0, 0);
}




/*
 * EXACT*, not EXACT: the inferred extent runs on to 0x0203D17C because the
 * four eight-byte ARM long-branch veneers at 0x0203D14C, 0x0203D158,
 * 0x0203D164 and 0x0203D170 save no `lr` and so carry no label.  It is not a
 * byte difference.  They want seeding into layout/function_starts.txt, which
 * is the integrator's file.
 *
 * Guarded forwarding call: the hook at 0x0203CD98 answers whether the
 * connection is up, and only then is the argument handed to 0x02037A44.  The
 * `bl` at the top passes r0 through untouched, so the callee is declared
 * `void` while this one takes the value it later forwards.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D12C.c \
 *       --func func_0203D12C --addr 0x0203D12C --cc 1.1p1 --arm
 */
void func_0203D12C(int a)
{
    if (func_0203CD98() == 0)
        return;

    func_02037A44(a);
}



void func_0203D14C(u32 a0, u32 a1, u8 *a2)
{
    func_0203BD30(a0, a1, a2);
}



u32 func_0203D158(void)
{
    return func_0203E4E8();
}



void func_0203D164(int a0)
{
    func_0203E538(a0);
}



int func_0203D170(void)
{
    return func_0203E590();
}







/*
 * Vtable dispatch with the *vtable pointer* null-checked (the state object
 * itself is not): the entry at +0xC4 takes the argument, and the hook's value
 * is dropped.  Two loads separate the two tests, which is what makes this
 * shape distinct from src/matched/func_0203CF10.c and
 * src/matched/func_0203CF3C.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D17C.c \
 *       --func func_0203D17C --addr 0x0203D17C --cc 1.1p1 --arm
 */
void func_0203D17C(u32 a)
{
    struct NetCtx *p;
    struct NetVtbl *vt;

    p = func_0203D788();
    vt = p->vt;
    if (vt == 0)
        return;
    vt->fC4(a);
}







/*
 * Forward to func_020395EC and mask the result to a byte.  func_020395EC is
 * called from func_0203D578 (outside this range), which is what attests the
 * `bl` here as a real function rather than a wildcarded relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D1A4.c \
 *       --func func_0203D1A4 --addr 0x0203D1A4 --cc 1.1p1 --arm
 */
u32 func_0203D1A4(struct Link *p)
{
    return func_020395EC((struct Entry *)p) & 0xff;
}






int func_0203D1B4(void)
{
    return func_020399EC();
}






/*
 * TU: net.c (named by the assert site at 0x0203D2EC, which passes the
 * string at 0x020A7CA0, "net.c").
 *
 * Guard on the network singleton, then a two-step query: look the entry
 * `index` up with func_0203996C and ask func_020399B8 about the result.
 * The `moveq r0, #0` is a no-op on the value it guards; it only exists
 * because the source spells the null return out.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D1C0.c \
 *       --func func_0203D1C0 --addr 0x0203D1C0 --cc 1.1p1 --arm
 */
u32 func_0203D1C0(u32 index)
{
    if (func_0203D788() == 0) {
        return 0;
    }
    return func_020399B8((u8 *)func_0203996C(index));
}





void func_0203D1E8(u32 unused, void *arg)
{
    void (*fn)(void *) = func_0203D788()->vt->fB8;

    if (fn == 0) {
        return;
    }
    fn(arg);
}





/*
 * TU: net.c.
 *
 * "Nothing running, or the +0x6c hook says idle".  The first test reads
 * g_021469E0.unk_08 straight out of the singleton (the same two
 * instructions func_0203D788 is made of), while the second goes through the
 * real call; that asymmetry is what says the first read is a file-local
 * access and not an inlined copy of the extern.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D210.c \
 *       --func func_0203D210 --addr 0x0203D210 --cc 1.1p1 --arm
 */
u32 func_0203D210(void)
{
    if (g_021469E0.unk_08 == 0) {
        return 1;
    }
    return func_0203D788()->vt->f6C() == 0;
}







/*
 * TU: net.c.
 *
 * Store a halfword pair into +0x5c/+0x5e of the network state block, if it
 * exists.  Both stores are predicated off the one null test, which is why
 * the two parameters have to survive the accessor call in r5/r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D24C.c \
 *       --func func_0203D24C --addr 0x0203D24C --cc 1.1p1 --arm
 */
void func_0203D24C(u16 a, u16 b)
{
    struct NetCtx *s = func_0203D798();

    if (s != 0) {
        s->f5C = a;
        s->f5E = b;
    }
}







/*
 * TU: net.c.
 *
 * "State is 3 or 4" predicate on the +0x65 mode byte of the network
 * singleton.  The range test is written as one unsigned compare on the
 * biased byte, so the original spells `- 3` as `add r0, r0, #0xfd` with the
 * `and r0, r0, #0xff` that the u8 cast forces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D26C.c \
 *       --func func_0203D26C --addr 0x0203D26C --cc 1.1p1 --arm
 */
u32 func_0203D26C(void)
{
    struct NetCtx *s = func_0203D788();

    if (s != 0) {
        if ((u8)(s->f65 + 0xfd) <= 1) {
            return 1;
        }
    }
    return 0;
}







/*
 * TU: net.c.
 *
 * Sibling of func_0203D26C one range lower: "state is 1 or 2" on the +0x65
 * mode byte.  Same shape, `add r0, r0, #0xff` for the bias instead of
 * `#0xfd`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D29C.c \
 *       --func func_0203D29C --addr 0x0203D29C --cc 1.1p1 --arm
 */
u32 func_0203D29C(void)
{
    struct NetCtx *s = func_0203D788();

    if (s != 0) {
        if ((u8)(s->f65 + 0xff) <= 1) {
            return 1;
        }
    }
    return 0;
}







/*
 * TU: net.c.  This is the function that names it: the assert call at
 * 0x0203D2EC passes the string at 0x020A7CA0, which reads "net.c", with
 * line 0x364 (868) and the message string "0" at 0x020A7CE8.
 *
 * Refresh of the on-screen connection indicator.  Both accessors are
 * called even though they return the same singleton field (func_0203D798
 * null-checks it, func_0203D788 does not); the original keeps both results
 * live in r4 and r5 and uses r4 only for the mode test, so the two calls
 * are in the source, not an artefact.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D2CC.c \
 *       --func func_0203D2CC --addr 0x0203D2CC --cc 1.1p1 --arm
 */
void func_0203D2CC(void)
{
    struct NetCtx *a = func_0203D798();
    struct NetCtx *b = func_0203D788();

    if (func_020338F8() == 1) {
        func_02034714(g_020A7CA0, 868, g_020A7CE8);
        return;
    }
    if (b != 0 && a->f65 != 3) {
        u32 flag = 0;

        if ((u8)(b->f65 + 0xff) <= 1) {
            flag = 1;
        }
        func_02037010(b->f5C, b->f5E, flag, b->f56);
    } else {
        func_020370C8();
    }
}







/*
 * TU: net.c.
 *
 * Three-call sequence: stamp the (0xf0, 0) pair into the state block, run
 * the transfer at 0x02037118 with this function's own two arguments, then
 * kick the state machine at 0x0203D2CC.  Both arguments have to outlive the
 * first call, which is what spends r5/r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D34C.c \
 *       --func func_0203D34C --addr 0x0203D34C --cc 1.1p1 --arm
 */
void func_0203D34C(u32 a, u32 b)
{
    func_0203D24C(0xf0, 0);
    func_02037118(a, b);
    func_0203D2CC();
}







/*
 * TU: net.c.
 *
 * Inverted forward: 1 when func_02039338 reports zero.  The result local is
 * initialised before the call, so the zero lands in r4 ahead of the `bl`
 * and the true case is a single `moveq`; writing `return f() == 0;`
 * instead puts the materialisation after the call and loses the shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D378.c \
 *       --func func_0203D378 --addr 0x0203D378 --cc 1.1p1 --arm
 */
u32 func_0203D378(void)
{
    u32 res = 0;

    if (func_02039338() == 0) {
        res = 1;
    }
    return res;
}







/*
 * TU: net.c.
 *
 * Leaf predicate on the +0x4a byte of an entry: "is this entry in state 5".
 * No relocation and no frame; the same three-instruction body appears
 * inlined inside func_020399B8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D394.c \
 *       --func func_0203D394 --addr 0x0203D394 --cc 1.1p1 --arm
 */
u32 func_0203D394(struct NetEntry *e)
{
    return e->state == 5;
}






/*
 * TU: net.c.
 *
 * Seven-argument send wrapper.  The leading func_0203D798 call is made for
 * effect only, its result is dead in the original, and the four incoming
 * arguments all have to survive it, which is what spends r4-r7.  Arguments
 * five to seven go on the stack, hence the `sub sp, sp, #0xc`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D3A8.c \
 *       --func func_0203D3A8 --addr 0x0203D3A8 --cc 1.1p1 --arm
 */
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d)
{
    func_0203D798();
    return func_02038C18(b, d, c, 0, func_020395EC(a), 0xff, 0);
}






/*
 *           the image and it is the call inside this function, so `label` has
 *           no outside witness for either and no manifest entry covers them
 *           yet.  File those two addresses first and this graduates with no
 *           change to its C (every other site resolves).
 */
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h)
{
    u8 mask;

    func_0203D798();
    mask = 0xff;
    if (func_0203D394((struct NetEntry *)entry) == 0 && c >= 0x11) {
        return 0;
    }
    if (g != 0 && func_02039468(c, func_020395EC((void *)entry)) != 0) {
        return 0;
    }
    if (sendID != 0xff) {
        if (sendID >= 7) {
            func_02034714(g_020A7CA0, 1019, g_020A7CEC);
        }
        mask = 1 << sendID;
    }
    return func_02038C18(c, e, d, f, func_020395EC((void *)entry), mask, h);
}






/*
 * TU: net.c.
 *
 * The explicit-mask sibling of func_0203D3F8: identical guards, but the
 * destination bitmask arrives as the second parameter instead of being
 * derived from a send id, so there is no assert and no `lsl`, and the mask
 * stays in r6 across the whole body.  The two stack arguments that live
 * next to each other go out as one `stmib`.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x0203D578 because the
 * follower at 0x0203D56C has no label.  It is not a byte difference; the
 * follower is a twelve-byte ARM long-branch veneer (ldr ip, [pc]; bx ip;
 * .word 0x020394C0) that saves no lr and so is invisible to disasm.py.  It
 * wants seeding into layout/function_starts.txt, which is the integrator's
 * file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D4D0.c \
 *       --func func_0203D4D0 --addr 0x0203D4D0 --cc 1.1p1 --arm
 */
u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g,
                  u32 h)
{
    func_0203D798();
    if (func_0203D394((struct NetEntry *)entry) == 0 && c >= 0x11) {
        return 0;
    }
    if (g != 0 && func_02039468(c, func_020395EC((void *)entry)) != 0) {
        return 0;
    }
    return func_02038C18(c, e, d, f, func_020395EC((void *)entry), mask, h);
}





void func_0203D56C(void)
{
    func_020394C0();
}






/*
 * Forwards the first argument through func_020395EC and passes the result
 * with the second argument to func_02039468.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D578.c \
 *       --func func_0203D578 --addr 0x0203D578 --arm --cc 1.1p1
 */
void func_0203D578(int a, u32 b)
{
    u32 r = func_020395EC((void *)a);

    func_02039468(b, r);
}



void func_0203D594(void *p, u16 tag)
{
    func_02039C3C(p, tag);
}



void func_0203D5A0(void)
{
    func_02039CA0();
}




/*
 * PROMOTED from src/pending/.  The `bl` to 0x0203A458 was this file's last
 * open site; it now resolves as `matched` against that function's own EXACT
 * shard entry, so the cap is gone.
 *
 * Sets the net context's +0x67 byte to the argument (after forcing the
 * context through func_0203D788), then updates the channel with
 * func_0203996C(0xff) and func_0203A458.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D5AC.c \
 *       --func func_0203D5AC --addr 0x0203D5AC --arm --cc 1.1p1
 */
void func_0203D5AC(int a, int b)
{
    struct NetCtx *p;

    func_0203D788();
    p = func_0203D798();
    p->f67 = (u8)a;
    func_0203A458((u8 *)func_0203996C(0xff), a);
}





/*
 * Returns the byte at +0x67 of the net context, or 0 when there is none.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D5D4.c \
 *       --func func_0203D5D4 --addr 0x0203D5D4 --arm --cc 1.1p1
 */
u32 func_0203D5D4(void)
{
    struct NetCtx *p = func_0203D798();

    return p != 0 ? p->f67 : 0;
}





/*
 * Calls the net context's +0x44 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D5EC.c \
 *       --func func_0203D5EC --addr 0x0203D5EC --arm --cc 1.1p1
 */
u32 func_0203D5EC(void)
{
    struct NetCtx *p = func_0203D788();

    if (p->f44 == 0) {
        return 0;
    }
    return ((u32 (*)(u32)) p->f44)(p->f34C);
}





/*
 * Calls the net context's +0x40 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D610.c \
 *       --func func_0203D610 --addr 0x0203D610 --arm --cc 1.1p1
 */
u32 func_0203D610(void)
{
    struct NetCtx *p = func_0203D788();

    if (p->f40 == 0) {
        return 0;
    }
    return ((u32 (*)(u32)) p->f40)(p->f34C);
}
