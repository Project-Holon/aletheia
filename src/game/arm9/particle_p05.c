/*
 * file:     particle_p05.c
 * unit:     yes
 * function: func_020506B8, func_02050738, func_02050790, func_020507A0, func_020507D0, func_020507F0, func_02050804, func_0205082C, func_02050848, func_0205085C, func_02050880, func_02050894, func_020508C4, func_020508D8, func_020508EC, func_02050920, func_02050944, func_02050984, func_020509E0, func_020509E8, func_02050A00, func_02050A58, func_02050A70, func_02050B14, func_02050B80, func_02050BE8
 * address:  0x020506B8
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
 *   func_020473D8  0x020473D8  arm
 *   func_0204F2B4  0x0204F2B4  arm
 *   func_0204F344  0x0204F344  arm
 *   func_020473EC   0x020473EC  arm
 *   func_0204F2CC   0x0204F2CC  arm
 *   DWCi_LSTlErase 0x0204F7DC arm
 *   g_02146A84     0x02146A84  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_02030734   0x02030734  arm
 *   g_02146A88      0x02146A88  data
 *   pkt_02050A70_File 0x020A7FC0  data
 */
#include "../../matched/include/Obj06992.h"
#include "../../matched/include/Obj11453.h"
#include "../../matched/include/Obj11454.h"
#include "../../matched/include/Obj16154.h"
#include "../../matched/include/Obj16155.h"
#include "../../matched/include/Obj02611.h"
#include "../../matched/include/Obj16156.h"
#include "../../matched/include/Obj16157.h"
#include "../../matched/include/Obj11455.h"
#include "../../matched/include/Obj16158.h"
#include "../../matched/include/Obj11456.h"
#include "../../matched/include/Obj16160.h"
#include "../../matched/include/Obj16161.h"
#include "../../matched/include/Obj16163.h"
#include "../../matched/include/Obj16164.h"

struct Cmd;
struct Ent;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct Owner {
    u32 f00;
    u32 f04;
    void (*f08)(u32 a0, u32 a1, u32 a2, u32 a3);
} Owner;

typedef struct Entry {
    u16 f00;
    u16 f02;
    u32 f04;
} Entry;

typedef unsigned char  u8;

typedef struct tagLISTCB {
    void *head;
    void *tail;
} LISTCB;

typedef struct { int f0; char pad[0x24]; } E28_020507D0;

typedef struct { int pad0; int f4; char pad[0x10]; E28_020507D0 *f18; } Mgr_020507D0;

struct S8 {
    u16 h;
    u16 pad;
    u32 w;
};

struct S40 {
    u32 f0;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 f12;
    u32 f16;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f32;
    u32 f36;
};

typedef struct { int f0; char pad[0x24]; } E28_020508C4;

typedef struct { char pad[0x18]; E28_020508C4 *f18; } Mgr_020508C4;

struct S14 {
    u16 f : 14;
};

typedef void (*Fn)(void);

struct Ent_02050A00 {
    u16 pad00[8];
    u16 f10;
    u16 f12;
    u16 f14;
};

struct Cmd {
    u16 f00;
    u16 f02;
};

struct Ent_02050A58 {
    u16 pad00[8];
    u16 f10;
    u16 f12;
};

typedef struct Slot_02050A70 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 active : 1;             /* bit 0 of +0x0C */
    u32 torn   : 1;             /* bit 1 of +0x0C */
    u32 kill   : 1;             /* bit 2 of +0x0C */
    u32        : 29;
} Slot_02050A70;

typedef struct Slot_02050B14 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
} Slot_02050B14;

struct Ctx {
    u32  words[16];     /* 0x00 */
    u32  f40;           /* 0x40 */
    u32  f44;           /* 0x44 */
};

extern int func_020473D8(int a0);
extern void func_0204F2B4(int p0, int p1, int p2);
extern void func_0204F344(void *a0, u32 a1, int a2, int *out, int *in, u8 flag);
extern int func_020473EC(int a0);
extern u32 func_0204F2CC(u32 a, u16 b, u32 *out);
extern void DWCi_LSTlErase(void *ob);
extern int func_0204F720(u32 a, u32 b, void *buf);
extern u32 func_0204F704(u8 *a0, int i);
extern void func_020500A0(int p0);
extern u32  OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 s);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02051504(void);
extern int func_02051534(void);
extern int func_02051574(void);
void func_020506B8(Owner *o, Entry *e, u32 a2);
u32 func_02050738(void *p, void *q);
void func_02050790(LISTCB *list, int b, int c);
int func_020507A0(void *p, int idx, u32 x);
int func_020507D0(Mgr_020507D0 *p, int i);
void func_020507F0(void *p, int idx, u32 v);
void func_02050804(void *p, int idx, u32 v, u16 h);
void func_0205082C(void *p, int idx, u32 h);
u16 func_02050848(u8 *p, int i);
void func_0205085C(void *p, int idx, u32 v);
u16 func_02050880(u8 *p, int i);
int func_02050894(void *p, int idx, int j);
int func_020508C4(Mgr_020508C4 *p, int i);
u32 func_020508D8(u8 *o, u32 i);
u32 func_020508EC(u8 *p, int i, u16 *out);
int func_02050920(struct S14 *p);
int func_02050944(void *p, struct S14 *q);
Fn func_02050984(u32 id);
int func_020509E0(void);
int func_020509E8(void *p, void *q);
int func_02050A00(struct Ent_02050A00 *e, struct Cmd *c);
int func_02050A58(struct Ent_02050A58 *e, struct Cmd *c);
void func_02050A70(void);
void func_02050B14(u32 idx);
void func_02050B80(u32 heap);
void func_02050BE8(void);
extern Slot_02050A70 *g_02146A84;
extern struct Ctx *g_02146A88;
extern const char pkt_02050A70_File[];




void func_020506B8(Owner *o, Entry *e, u32 a2)
{
    u32 s4;
    u32 s3;
    u32 s2;
    u32 base;
    u32 zero;

    base = func_020473D8(e->f04);
    func_0204F2B4(o->f04, e->f00, (int)(&s4));
    zero = 0;
    func_0204F344((void *)o->f04, e->f00, a2, (int *)(&s3), (int *)(&s2), zero);
    if (o->f08 != 0) {
        o->f08(zero, s4, base + s3, s2);
    }
}




/*
 * An 88-byte ARM function in the 0x02050000 block.  It reads a record index
 * out of the object at +4, resolves it through func_020473EC, then calls
 * func_0204F2CC with the object's word at +4, the halfword at q[0] and a
 * stack scratch slot; when the hook pointer at p+8 is non-null it calls the
 * hook with the scratch value and the resolved record.  The null case returns
 * the func_0204F2CC result, which is why the `cmp ip, #0` sits after the
 * second call with r0 still live.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050738.c \
 *       --func func_02050738 --addr 0x02050738 --cc 1.1p1 --arm
 */
u32 func_02050738(void *p, void *q)
{
    u32 v = func_020473EC(((struct Obj06992 *)q)->f4);
    u32 t;
    u32 r = func_0204F2CC(((struct Obj11453 *)p)->f4, ((struct Obj06992 *)q)->f0, &t);
    u32 (*hook)(u32, u32, u32, u32) = *(u32 (**)(u32, u32, u32, u32))((char *)p + 8);

    if (hook == 0)
        return r;
    return hook(1, t, v, 0x20);
}




/*
 * sdk:      DWCi_LSTlPopFront (libdwcutil.TWL.HYB.a list.o)
 */
void func_02050790(LISTCB *list, int b, int c)
{
    DWCi_LSTlErase(list->tail);
}




/*
 * The listing labels this function at 0x020507A4, not 0x020507A0: disasm.py
 * only auto-labels a prologue that saves lr, so the four bytes at 0x020507A0
 * that home the four argument registers (`push {r0,r1,r2,r3}`, the tell for
 * an address-taken register parameter,
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md) are
 * printed as a stray `.word` and the label lands on the `push {r3, lr}` four
 * bytes later.  The real entry is 0x020507A0 and the function is 48 bytes,
 * not the worklist's 44; verified from 0x020507A0, where the extent runs to
 * the next label at 0x020507D0.
 *
 * The third parameter is not a pointer but a scalar whose address is taken
 * (`&x`, compiled as the home slot).  Written as `u8 *buf` it compiles to 32
 * bytes; as `u8 buf[16]`, 32; only `&x` on a scalar reproduces the home push.
 *
 * Reads element `idx` of a 40-byte record array hanging off p+24 and hands it,
 * together with p's own word at +4 and the caller's buffer address, to
 * func_0204F720.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020507A0.c \
 *       --func func_020507A0 --addr 0x020507A0 --cc 1.1p1 --arm
 */
int func_020507A0(void *p, int idx, u32 x)
{
    return func_0204F720(((struct Obj11454 *)p)->f4,
                         *(u32 *)(((struct Obj11454 *)p)->f18 + idx * 40),
                         &x);
}




/*
 * Leaf witness for ov021 0x021BBF10 / 0x021BC138 (lane wA1-12).
 */
int func_020507D0(Mgr_020507D0 *p, int i)
{
    return func_0204F704((u8 *)p->f4, p->f18[i].f0);
}




void func_020507F0(void *p, int idx, u32 v)
{
    char *e = (char *)(((struct Obj16154 *)p)->f18 + idx * 40);
    ((struct Obj16155 *)e)->f18 = v;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050804.c \
 *       --func func_02050804 --addr 0x02050804 --cc 1.1p1 --arm
 */
void func_02050804(void *p, int idx, u32 v, u16 h)
{
    char *e = (char *)(((struct Obj16156 *)p)->f18 + idx * 40);

    ((struct Obj02611 *)e)->f8 = v;
    ((struct Obj02611 *)e)->fC = h;
    ((struct Obj02611 *)e)->fE = 0;
    func_020500A0((int)e);
}




void func_0205082C(void *p, int idx, u32 h)
{
    char *e = (char *)(((struct Obj16157 *)p)->f18 + idx * 40);
    ((struct Obj02611 *)e)->fE = h;
    func_020500A0((int)e);
}




/*
 * Leaf witness for ov021 0x0219F058 and siblings (lane wA1-06).
 */
u16 func_02050848(u8 *p, int i)
{
    return *(u16 *)(*(u8 * *)&((struct Obj11455 *)p)->f18 + i * 40 + 0xe);
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0205085C.c \
 *       --func func_0205085C --addr 0x0205085C --cc 1.1p1 --arm
 */
void func_0205085C(void *p, int idx, u32 v)
{
    char *e = (char *)(((struct Obj16158 *)p)->f18 + idx * 40);

    func_020500A0((int)e);
    ((struct Obj02611 *)e)->f10 = v;
}




u16 func_02050880(u8 *p, int i)
{
    return *(u16 *)(*(u8 * *)&((struct Obj11455 *)p)->f18 + i * 40 + 0x10);
}




/*
 * PROMOTED from src/pending/func_02050894.c: it was parked at MATCH because
 * the only branch in the image to 0x02050738 is the one inside this function.
 * 0x02050738 (88 bytes, pkt_02050340) is now matched, so the site resolves by
 * the `matched` class with no change to the C.  The file's packet id is
 * corrected from pkt_02050340 to pkt_02050894, which is the packet the
 * worklist gives 0x02050894.
 *
 * Moves one word between two parallel record arrays of the object: the index
 * is read out of the 40-byte record table at p+24, the value out of the
 * 8-byte-pair array at p+12, the value is stored back into the record the
 * index names, and the record is handed to func_02050738.
 *
 * The listing's extent runs 140 bytes because the follower at 0x020508C4 is an
 * unlabelled leaf accessor (no prologue that saves lr).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050894.c \
 *       --func func_02050894 --addr 0x02050894 --cc 1.1p1 --arm
 */
int func_02050894(void *p, int idx, int j)
{
    struct S8  *arr = *(struct S8 * *)&((struct Obj11456 *)p)->fC;
    struct S40 *rec = *(struct S40 * *)&((struct Obj11456 *)p)->f18;
    u16 e = rec[idx].f4;
    u32 v = arr[j].w;

    arr[e].w = v;
    return func_02050738(p, &arr[e]);
}




int func_020508C4(Mgr_020508C4 *p, int i)
{
    return p->f18[i].f0;
}




u32 func_020508D8(u8 *o, u32 i)
{
    return *(u16 *)(*(u8 * *)&((struct Obj16160 *)o)->f18 + i * 0x28 + 4);
}




u32 func_020508EC(u8 *p, int i, u16 *out)
{
    u16 v = *(u16 *)(*(u8 * *)&((struct Obj16161 *)p)->f18 + i * 40 + 0x1c);
    *out = v;
    return (u16)(v + 4 + 0xC000) <= 3;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050920.c \
 *       --func func_02050920 --addr 0x02050920 --cc 1.1p1 --arm
 */
int func_02050920(struct S14 *p)
{
    return func_02050984(p->f) != 0;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050944.c \
 *       --func func_02050944 --addr 0x02050944 --cc 1.1p1 --arm
 */
int func_02050944(void *p, struct S14 *q)
{
    int (*fn)(void *, struct S14 *);

    fn = (int (*)(void *, struct S14 *))func_02050984(q->f);
    ((struct Obj16163 *)p)->f1C = q->f;
    return fn(p, q);
}




/*
 * PROMOTED from src/pending/func_02050984.c 2026-09-21 (wave 4, billboard_act).
 * The C is UNCHANGED: it was parked at MATCH* because three of its four ABS32
 * pool words -- 0x020509E0, 0x02050A00 and 0x02050A58 -- each had exactly one
 * mention image wide, the pool word inside this very function, so neither
 * `label` nor `literal` reached them.  All three handlers are now filed EXACT
 * (src/matched/func_020509E0.c, func_02050A00.c, func_02050A58.c, shard
 * arm9/pkt_02050984.json), so every site resolves by the `matched` class and
 * this file verifies EXACT* with no edit to the body.
 *
 * EXACT*, not EXACT: the listing's extent runs 100 bytes because the follower
 * at 0x020509E0 is reached only through this function's own pool word and has
 * no prologue that saves lr, so disasm.py does not label it.  Report
 * 0x020509E0 as a seed for layout/function_starts.txt; it is never a byte
 * difference.
 *
 * The switch normalises the id with two subtracts and no `mov` of the base,
 * which is the whole reason the case labels read 0x3FFC..0x3FFF: the image
 * subtracts 0x3FC and then 0x3C00, i.e. 0x3FFC, and spelling the cases
 * 0x43FC..0x43FF makes the second subtract `#0x4000` and the four case arms
 * come out in the wrong order.  Writing the cases in DESCENDING source order
 * is what reproduces the image's arm order (case 0x3FFF's arm nearest the
 * table); ascending order puts case 0x3FFC's arm there and differs in four
 * branch instructions.
 *
 * `return <function address>;` is the shape: each arm is `ldr r0, [pc, #n];
 * bx lr` and the fall-through is `mov r0, #0; bx lr`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050984.c \
 *       --func func_02050984 --addr 0x02050984 --cc 1.1p1 --arm
 */
Fn func_02050984(u32 id)
{
    switch (id) {
    case 0x3FFF: return (Fn)func_020509E0;
    case 0x3FFE: return (Fn)func_020509E8;
    case 0x3FFD: return (Fn)func_02050A00;
    case 0x3FFC: return (Fn)func_02050A58;
    }
    return 0;
}



/*
 * The second arm of the four-entry handler table func_02050984 dispatches
 * through (its pool word at 0x020509D0).  Eight bytes, a leaf that returns the
 * nonzero constant the dispatch caller tests, and one of the pool words that
 * keeps src/pending/func_02050984.c wildcarded until it has an EXACT entry.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020509E0.c \
 *       --func func_020509E0 --addr 0x020509E0 --cc 1.1p1 --arm
 */
int func_020509E0(void)
{
    return 1;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020509E8.c \
 *       --func func_020509E8 --addr 0x020509E8 --cc 1.1p1 --arm
 */
int func_020509E8(void *p, void *q)
{
    ((struct Obj02611 *)p)->fE = ((struct Obj16164 *)q)->f2;
    func_020500A0((int)p);
    return 0;
}




/*
 * The third arm of the handler table func_02050984 dispatches through (see
 * src/pending/func_02050984.c).  88 bytes, a leaf: the command halfword at
 * c->f02 packs two bytes, a repeat count in the high half and a value in the
 * low half.  While the entry's repeat counter at +0x14 is below the count,
 * store the value at +0x10 and bump the counter; once it reaches the count,
 * reset the counter and advance +0x10 by one instead.  +0x12 is zeroed on
 * both paths.  Returns 0 (the "command consumed, keep going" verdict the
 * dispatcher in func_02050944 tests).
 *
 * The comparison is SIGNED (`bge`), so both sides are promoted `int`s and the
 * counter is compared as an int, not as an unsigned halfword.
 *
 * Two shapes are load-bearing, both worth 8 bytes each:
 *
 *   - The high byte must land in a `u8` LOCAL, not be written inline in the
 *     comparison.  `if (n < ((v & 0xff00) >> 8 & 0xff))` lets mwcc fold the
 *     shift into the compare's shifter operand (`cmp r2, r1, asr #8`) and drop
 *     the redundant `and #0xff` entirely, losing the original's separate
 *     `asr r1,r1,#8` / `and r1,r1,#0xff` pair (80 bytes, 56 out).
 *   - The LOW byte must be extracted into its own local BEFORE the `if`, not
 *     spelled `v & 0xff` at its single use inside the taken arm.  The original
 *     issues `and r3, r3, #0xff` above the `bge`; written at the use it lands
 *     after it, which is the last 8 bytes (88 bytes, 8 out).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050A00.c \
 *       --func func_02050A00 --addr 0x02050A00 --cc 1.1p1 --arm
 */
int func_02050A00(struct Ent_02050A00 *e, struct Cmd *c)
{
    int v = c->f02;
    int n = e->f14;
    unsigned char hi = (unsigned char)((v & 0xff00) >> 8);
    unsigned char lo = (unsigned char)v;

    if (n < hi) {
        e->f10 = lo;
        e->f12 = 0;
        e->f14 = (u16)(n + 1);
    } else {
        int cur = e->f10;
        e->f14 = 0;
        e->f12 = 0;
        e->f10 = (u16)(cur + 1);
    }
    return 0;
}



/*
 * The fourth arm of the handler table func_02050984 dispatches through (its
 * pool word at 0x02050980-ish; see src/pending/func_02050984.c).  Twenty
 * bytes, a leaf: it loads the command's second halfword (`c->f02`), zeroes the
 * entry's +0x12 counter, stores the halfword at +0x10 and returns 0.
 *
 * The zero is materialised once and reused for both the +0x12 store and the
 * return (`mov r1,#0 ... mov r0,r1`), which is what a single `0` constant
 * shared between the store and the `return 0;` produces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050A58.c \
 *       --func func_02050A58 --addr 0x02050A58 --cc 1.1p1 --arm
 */
int func_02050A58(struct Ent_02050A58 *e, struct Cmd *c)
{
    u16 v = c->f02;

    e->f12 = 0;
    e->f10 = v;
    return 0;
}



/*
 *           02050A70..02050B14 - BOTH unresolved sites are the `bl` to it,
 *           and this function holds the only two branches to 0x02050B14 in
 *           the whole image, so `label` has nothing to point at and no cut
 *           frees it.  It closes only when 0x02050B14 itself has a shard
 *           entry, and that body is the one-register allocator residue
 *           written up in docs/notes/pkt_02050A70.c.txt (44 differing bytes,
 *           no source reaches it).  Chain row.
 *
 *           All 164 concrete bytes reproduce, including the third site
 *           (g_02146A84, literal x5).  The counter is `int`, not `u32`: the
 *           loop's back edge is `blt`.
 *
 * Sweep the four 16-byte slots of the global bank at 0x02146A84 and retire
 * the ones whose state bits say so: a slot whose bit 0 of +0x0C is set has it
 * cleared, and if it is still busy (bits 11.. of +0x08) its teardown routine
 * runs and the "torn down" bit (bit 1) is set; a slot whose bit 2 is set has
 * it cleared and the teardown routine runs.  The bank pointer is re-read
 * after every store (`ldr r0, [r5]`), which is what the repeated reads say:
 * the store can alias the global itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02050A70.c \
 *       --func func_02050A70 --addr 0x02050A70 --cc 1.1p1 --arm
 */
void func_02050A70(void)
{
    int i;

    if (g_02146A84 == 0)
        return;

    for (i = 0; i < 4; i++) {
        if (g_02146A84[i].active) {
            g_02146A84[i].active = 0;
            if (g_02146A84[i].unk08 >> 11) {
                func_02050B14(i);
                g_02146A84[i].torn = 1;
            }
        }
        if (g_02146A84[i].kill) {
            g_02146A84[i].kill = 0;
            func_02050B14(i);
        }
    }
}



/*
 * CLOSES the two-wave wall written up at the top of docs/notes/pkt_02050A70.c.txt
 * (44 differing bytes, diagnosed there as a one-register allocator shift with
 * "no source shape that reaches it").  The diagnosis was wrong: the residue was
 * a WRONG RECORD STRIDE, not an allocation tie.  The note's reconstruction read
 * the field as `g_02146A84[idx].unk_08` over 16-byte records but spelled the
 * index arithmetic so that the compiler emitted a multiply; the image emits
 * `add r1, r3, r4, lsl #4` -- a shift, because 16 is a power of two -- and
 * `mul r2, r4, r1` ONLY for the SECOND, independent 12-byte stride of the I/O
 * register address (0x040000B8 + idx * 12).  Declaring the record struct as
 * four plain u32 words (16 bytes) and subscripting it normally gives the shift,
 * and every register then falls out identical: the whole 44-byte residue was
 * downstream of that one address computation.
 *
 * Read the 3D engine's per-engine configuration word out of the slot bank and
 * repack it into the display register at 0x040000B8 + idx*12: dest bit 30 from
 * source bit 1, dest bit 26 from source bit 5, dest 23:24 from source 7:8,
 * dest 21:22 from source 9:10 and dest 0:20 from source 11:31, under an
 * interrupt-disabled critical section.
 *
 * The OR-chain ORDER is load-bearing and is the note's one surviving finding:
 * the bit-30 term is written FIRST and the bit-26 term SECOND, because the
 * compiler fully materialises the second operand of a commutative chain
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md)
 * and the image materialises the bit-26 term (`lsl #0x1a; lsr #0x1f; lsl #0x1a`)
 * while folding the other three placements into the ORs' shifter operands.
 * Written in descending destination order the four extracts come out mirrored.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050B14.c \
 *       --func func_02050B14 --addr 0x02050B14 --cc 1.1p1 --arm
 *   EXACT, 108 bytes, 3 relocation sites, all resolved.
 */
void func_02050B14(u32 idx)
{
    u32 s = OS_DisableInterrupts();
    u32 v = g_02146A84[idx].unk08;

    *(volatile u32 *)(0x040000B8 + idx * 12) =
        ((v << 30) >> 31) << 30 |
        ((v << 26) >> 31) << 26 |
        ((v << 23) >> 30) << 23 |
        ((v << 21) >> 30) << 21 |
        (v >> 11);

    OS_RestoreInterrupts(s);
}




/*
 * Allocate the 0x48-byte singleton on the caller's heap and publish it at
 * 0x02146A88, zero its first sixteen words, then clear the two trailing word
 * fields at +0x40 and +0x44.
 *
 * The heap id is the incoming r0, untouched: the allocator's first argument is
 * the parameter, and its third (the clear flag, 0) is CSE'd off the loop
 * counter's own zero, which is why no `mov r0` appears and r4 is zeroed before
 * the call.
 *
 * The global is a pointer VARIABLE, and both the zero loop and the two field
 * stores re-dereference it: a store through the pointer could overwrite the
 * pointer itself, so only `g[i] = 0` inside the loop and `g->f40`/`g->f44`
 * afterwards reproduce the four separate loads of the global.
 */
void func_02050B80(u32 heap)
{
    int i = 0;

    g_02146A88 = func_02030734(heap, 0x48, i, pkt_02050A70_File, 190);

    for (i = 0; i < 16; i++) {
        ((u32 *)g_02146A88)[i] = 0;
    }

    g_02146A88->f40 = 0;
    g_02146A88->f44 = 0;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050BE8.c \
 *       --func func_02050BE8 --addr 0x02050BE8 --cc 1.1p1 --arm
 */
void func_02050BE8(void)
{
    if (func_02051504() == 0)
        return;
    func_02051534();
    func_02051574();
}
