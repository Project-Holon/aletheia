/*
 * file:     nns_gfd_vram_manager.c
 * unit:     yes
 * function: NNS_FndAllocFromAllocator, NNS_FndFreeToAllocator, NNS_FndInitAllocatorForExpHeap, NNS_G2dStubReturnZeroA, NNS_G2dStubReturnMinusOneA, NNS_G2dStubReturnZeroB, NNS_G2dStubReturnMinusOneB, NNSi_GfdSetTexVramSlotOrder, NNS_GfdInitVramManager, NNSi_GfdUpdateVramManager, NNSi_GfdDefaultAllocTexVram, NNSi_GfdDefaultFreeTexVram, NNS_GfdSaveVramManager, NNS_GfdLoadVramManager
 * address:  0x02061330
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from nns_fnd_unitheap.c by tools/splitfile.py.
 *
 * symbols:
 *   g_020A1708     0x020A1708  data
 *   g_020A8150     0x020A8150  data
 *   g_020A816C     0x020A816C  data
 *   g_02146B70      0x02146B70  data
 *   NNS_GfdDefaultFuncAllocTexVram      0x020A8140  data
 *   NNS_GfdDefaultFuncFreeTexVram      0x020A8144  data
 *   g_020A8158  0x020A8158  data
 */
#include "nns_fnd_unitheap_shared_types.h"

typedef unsigned short u16;

typedef void (*NNSiFndMethod)(void *self, u32 value);

typedef struct NNSiFndVTable {
    NNSiFndMethod method0;
    NNSiFndMethod method1;
} NNSiFndVTable;

typedef struct NNSiFndObject {
    NNSiFndVTable *vtable;
} NNSiFndObject;

typedef struct NNSG2dCellBank {
    void *table;
    u32 start;
    u32 count;
    u32 flags;
} NNSG2dCellBank;

typedef struct NNSGfdTexVramSlot {
    u32 cur;       /* 0x00 */
    u32 end;       /* 0x04 */
    u32 enable;    /* 0x08 */
    u32 modeFlag;  /* 0x0c */
    u16 kind;      /* 0x10 */
    u16 pad_12;
    u32 base;      /* 0x14 */
} NNSGfdTexVramSlot;

void NNS_FndAllocFromAllocator(NNSiFndObject *pObject, u32 value);

void NNS_FndFreeToAllocator(NNSiFndObject *pObject, u32 value);

void NNS_FndInitAllocatorForExpHeap(NNSG2dCellBank *pCellBank, u32 start, u32 count);

int NNS_G2dStubReturnZeroA(void);

int NNS_G2dStubReturnMinusOneA(void);

int NNS_G2dStubReturnZeroB(void);

int NNS_G2dStubReturnMinusOneB(void);

void NNSi_GfdSetTexVramSlotOrder(u32 a, u32 b, u32 c, u32 d, u32 e);

void NNS_GfdInitVramManager(u32 mode, u32 flag);

void NNSi_GfdUpdateVramManager(void);

u32 NNSi_GfdDefaultAllocTexVram(u32 size, u32 which);

u32 NNSi_GfdDefaultFreeTexVram(void);

void NNS_GfdSaveVramManager(u32 *dst);

void NNS_GfdLoadVramManager(u32 *src);

extern u8 g_020A1708[];

extern NNSGfdTexVramSlot g_020A816C[5];

extern NNSGfdTexVramSlot *g_020A8150[7];

extern u16 g_02146B70;

extern u32 NNS_GfdDefaultFuncAllocTexVram;

extern u32 NNS_GfdDefaultFuncFreeTexVram;

extern NNSGfdTexVramSlot *g_020A8158[5];

/*
 * functions:
 *   NNS_FndAllocFromAllocator  0x02061330  arm
 *   NNS_FndFreeToAllocator  0x02061344  arm
 *
 * Two two-argument vtable forwarders, 20 bytes each, no relocations at all.
 * The object at r0 holds a pointer to a table of function pointers at r0[0];
 * the call dispatches through slot 0 (0x02061330) and slot 1 (0x02061344).
 *
 * The tell that the callee takes *two* arguments is the register the loaded
 * pointer lands in.  Written as a one-argument call (`o->vt->f0(o)`) mwcc
 * keeps the function pointer in r1, which is free; the original puts it in
 * r2, which is only necessary when r0 and r1 are both argument registers, so
 * the wrapper forwards its own second parameter.  Same bytes either way for
 * the load pair, four differing bytes for the register choice.
 *
 * The wrapper's own arity is not visible in its body (the caller's r1 is
 * simply passed on), so the two-parameter reading is the one that reproduces
 * the register numbering; the functions are only reachable through a pointer
 * table, so no call site can be consulted.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061330.c \
 *       --addr 0x02061330 --arm
 *   EXACT, 40 bytes, 2 functions, 0 relocation sites.
 */
void NNS_FndAllocFromAllocator(NNSiFndObject *o, u32 x)
{
    o->vtable->method0(o, x);
}

void NNS_FndFreeToAllocator(NNSiFndObject *o, u32 x)
{
    o->vtable->method1(o, x);
}

/*
 *           NNS_G2dStubReturnMinusOneB
 *
 * functions:
 *   NNS_FndInitAllocatorForExpHeap  0x02061358  arm
 *   NNS_G2dStubReturnZeroA  0x02061370  arm
 *   NNS_G2dStubReturnMinusOneA  0x02061378  arm
 *   NNS_G2dStubReturnZeroB  0x02061380  arm
 *   NNS_G2dStubReturnMinusOneB  0x02061388  arm
 *
 * The four eight-byte functions after the first are the `0` / `-1` stub
 * pair the object's own dispatch table points at (the word stored at
 * 0x020A1708 is 0x0206128C, and the stubs sit right behind the table pointer
 * this function installs).  `disasm.py` never labels them, because a leaf
 * that saves no register has no prologue to sweep, so they print as a run of
 * `.word`s between two literal pools -- see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  They are read
 * out of the bytes here, and folding them into this unit is also what makes
 * the unit EXACT rather than EXACT*: on its own, NNS_FndInitAllocatorForExpHeap's inferred
 * extent runs 56 bytes to the next label at 0x02061390.
 *
 * The store order in the first function is the whole of its codegen: the zero
 * word has to be written *second* in the source (after the table pointer,
 * before the two arguments) for mwcc to fold the a/b/0 stores into a single
 * `stmib r0, {r1, r2, r3}`.  With `unkC = 0` written last the compiler emits
 * a two-register `stmib` plus a separate `str` and the literal pool moves
 * four bytes along.
 *
 * The one relocation site is the pool word for the data object at 0x020A1708;
 * it resolves as `data_table` (40 witnesses elsewhere in the image), which is
 * why this file is EXACT rather than the MATCH the single-function,
 * own-pool-witness reading would suggest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061358.c \
 *       --addr 0x02061358 --arm
 *   EXACT, 56 bytes, 5 functions, 1 relocation site, resolved.
 */
void NNS_FndInitAllocatorForExpHeap(NNSG2dCellBank *s, u32 a, u32 b)
{
    s->table = (void *)g_020A1708;
    s->flags = 0;
    s->start = a;
    s->count = b;
}

int NNS_G2dStubReturnZeroA(void)  { return 0; }

int NNS_G2dStubReturnMinusOneA(void)  { return -1; }

int NNS_G2dStubReturnZeroB(void)  { return 0; }

int NNS_G2dStubReturnMinusOneB(void)  { return -1; }

/*
 * The two pool words at 0x020613D0 / 0x020613D4 resolve through `literal`
 * witnesses in other functions (0x020614D0 for the table, 0x0206163C for the
 * global), so the file is EXACT; its section is 72 bytes, the 64 code bytes
 * the worklist records plus its own pool.
 *
 * The function indexes a table of 0x18-byte records (mla r6, r0, ip, r5 with
 * ip = 0x18) five times, once per parameter, and stores the five computed
 * addresses into consecutive words at +8..+0x18 of a global at 0x020A8150.
 * The fifth parameter arrives on the stack, at [sp, #0x10] before the push.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NNSi_GfdSetTexVramSlotOrder.c \
 *       --func NNSi_GfdSetTexVramSlotOrder --addr 0x02061390 --arm --cc 1.1p1
 *   EXACT, 72 bytes, 2 relocation sites, all 2 resolved.
 */
void NNSi_GfdSetTexVramSlotOrder(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    g_020A8150[2] = &g_020A816C[a];
    g_020A8150[3] = &g_020A816C[b];
    g_020A8150[4] = &g_020A816C[c];
    g_020A8150[5] = &g_020A816C[d];
    g_020A8150[6] = &g_020A816C[e];
}

/*
 * The mode selector of the NNS G2D multi-cell renderer.  It builds one of two
 * five-slot tables through NNSi_GfdSetTexVramSlotOrder depending on the mode, publishes the
 * mode word at 0x02146B70, re-runs NNSi_GfdUpdateVramManager (the table walker that lives
 * just past this function), and installs the two callbacks at 0x020A8140 /
 * 0x020A8144 when the second argument is non-zero.
 *
 * The mode test is written `mode <= 2`: the original's fall-through arm is the
 * (2, 0) table pair and its branch is the positive `bhi` to the (0, 2) pair,
 * which is what mwccarm emits for the negated form.
 *
 * THE COMPILER PIN.  The C below is, character for character, the body
 * docs/notes/pkt_020613D8.c.txt parked as DIFF.  The residue that note records
 * -- "this compiler cross-jumps the two calls' identical two-instruction tails
 * (`str ip, [sp]; bl NNSi_GfdSetTexVramSlotOrder`) into one shared block, the original keeps
 * both copies", 128 compiled against 136 -- is a FRONT-END artefact, not a
 * source-shape question.  Under `../2.0/sp2` the same source keeps both copies
 * and is byte-exact at 136.  The note's sweep (separate `if`s, `else if`, an
 * explicit `goto`, a `switch`, and four `#pragma`s) was correct in concluding
 * that no spelling moves it under 1.1p1.
 *
 * The pin is shared with src/matched/NNS_GfdAllocVram.c in this same cluster and
 * its evidence row is in docs/FRONTEND-PINS.md; a whole-function tail
 * duplication that 1.1p1 merges and 2.0/sp2 keeps is a second instance of the
 * same "2.0 spends bytes where 1.1p1 shares them" family as the kept-constants
 * tell.
 *
 * The pool word for NNSi_GfdDefaultFreeTexVram at +0x80 resolves only because
 * src/matched/NNSi_GfdDefaultFreeTexVram.c is an EXACT manifest entry: this store is the
 * only reference to that eight-byte stub anywhere in the image.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_GfdInitVramManager.c \
 *       --func NNS_GfdInitVramManager --addr 0x020613D8 --arm --cc ../2.0/sp2
 *   EXACT, 136 bytes, 8 relocation sites, all 8 resolved.
 */
void NNS_GfdInitVramManager(u32 mode, u32 flag)
{
    if (mode <= 2) {
        NNSi_GfdSetTexVramSlotOrder(4, 3, 2, 0, 1);
    } else {
        NNSi_GfdSetTexVramSlotOrder(4, 3, 0, 2, 1);
    }

    g_02146B70 = (u16)mode;
    NNSi_GfdUpdateVramManager();

    if (flag == 0) {
        return;
    }

    NNS_GfdDefaultFuncAllocTexVram = (u32)NNSi_GfdDefaultAllocTexVram;
    NNS_GfdDefaultFuncFreeTexVram = (u32)NNSi_GfdDefaultFreeTexVram;
}

/*
 * Re-derive every descriptor's enable and limit words from the renderer
 * mode (docs/families/cluster_020611D4.h): records below n = mode (plus
 * one when mode > 1) are enabled, and each record's {lo, hi} limit pair
 * is reset to {0, 0x10000} or {0, 0x20000} by its +0x0c kind word.
 *
 * THE LEVER, after two earlier lanes left this at 6 bytes (docs/notes/
 * pkt_020611D4.c.txt, docs/notes/pkt_020613D8.c.txt): the three stored
 * zeros are ONE named zero, `lo`, and the loop counter is INITIALISED
 * FROM IT (`for (i = lo; ...)`).  The image's `mov r5, #0` is the
 * counter's start and `mov lr, r5` / `mov r1, r5` / `mov r3, r5` are the
 * hoisted copies of the same value; with a literal 0 at each store (and
 * `i = 0`) the compiler materialises a separate zero into lr first and
 * gives the counter its own `mov r5, #0` -- the whole 6-byte residue.
 * `u32 z = i` spellings (tried before) do not reach it: the counter must
 * be derived from the zero, not the zero from the counter.  The permuter
 * is flat on the literal-zero body (hill, 161 singles), because no
 * value-preserving mutation it has introduces a shared zero variable.
 *
 * Front end: NOT pinned; EXACT under both dsi/1.1p1 and ../2.0/sp2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdUpdateVramManager.c \
 *       --func NNSi_GfdUpdateVramManager --addr 0x02061460 --arm
 */
void NNSi_GfdUpdateVramManager(void)
{
    int i;
    u32 lo = 0;
    NNSGfdTexVramSlot *t = g_020A816C;
    int n = g_02146B70;

    if (n > 1u) n++;

    for (i = lo; i < 5; i++, t++) {
        if (i < n) t->enable = 1;
        else       t->enable = lo;
        if (t->modeFlag != 0) {
            t->cur = lo;
            t->end = 0x10000;
        } else {
            t->cur = lo;
            t->end = 0x20000;
        }
    }
}

/* free extent of a slot, read through a signed word view */
#define ROOM(s) ((u32)((int *)(s))[1] - (u32)((int *)(s))[0])

/*
 * The descriptor-bank allocator of the NNS G2D multi-cell VRAM manager
 * (docs/families/cluster_020611D4.h, subsystem B), installed into the
 * 0x020A8140 callback slot by NNS_GfdInitVramManager.  Round the request to 16
 * (0 -> 16), refuse >= 0x7FFF0, then
 *   which != 0: walk the TWO slots at 0x020A8150; a live slot with room
 *     picks a companion by its halfword kind -- kind 0 -> &g_020A816C[1]
 *     (0x020A8184), kind 3 -> &g_020A816C[2] (0x020A819C), else null --
 *     which must have room for HALF the request; bump both cursors and
 *     answer the main slot's base + old cursor;
 *   which == 0: walk the FIVE slots at 0x020A8158 and allocate downward
 *     from the slot's end.
 * The answer packs ((n >> 4) << 16) | ((addr << 13) >> 16) | (which << 31),
 * size-high first as in NNS_GfdAllocTexVram.
 *
 * CORRECTIONS to docs/notes/pkt_020611D4.c.txt's reading: the TWO-slot
 * walk is 0x020A8150 and the FIVE-slot walk 0x020A8158 (the note had
 * them swapped), and the companions are not pointer variables but the
 * ADDRESSES 0x020A8184 / 0x020A819C, i.e. records 1 and 2 of the bank,
 * which is why they resolve through g_020A816C's own witnesses.
 *
 * What closed it, in order:
 *   1. the dispatch as a `switch` (0 / 3 / default).  Under ../2.0/sp2 it
 *      compiles to the image's chain of real branches to three
 *      one-instruction blocks; the default's null is derived from the loop
 *      counter's zero (`mov r7, r4`) with no help.
 *   2. the room checks must NOT be CSE'd into the bodies: the image reads
 *      cur/end with an `ldm` for the check and re-loads the one it needs
 *      in the body (`ldr r4, [lr]`, `ldr r2, [ip, #4]`).  Spelled through
 *      the fields, both front ends keep the check's load live and come out
 *      4 bytes short with a different allocation.  Reading the pair
 *      through a signed word view -- the ROOM() macro below -- makes the
 *      check's loads a different expression from the body's u32 field
 *      reads.  A `u32 *` view is NOT enough for the end-relative check of
 *      the downward walk (still CSE'd); the `int *` view is.
 *   3. declaration order addr, ok, n, b, a, i (a sweep of 24 orders; the
 *      field order closes only this one) puts n in r3 and addr in r2.
 *
 * Pin evidence (2.0): the same C under dsi/1.1p1 is 356 code+pool bytes
 * against 368, 145 out.  The image's push list {r3-r9, lr} and the
 * derived-zero default both come out under 2.0 only, the same pin its
 * sibling allocator NNS_GfdAllocVram carries.
 *
 * EXACT* (not a byte difference): the listing extent (376) runs over the
 * unlabelled 8-byte stub NNSi_GfdDefaultFreeTexVram at 0x02061644, already its own
 * EXACT entry; the function is 348 code bytes plus a 20-byte pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdDefaultAllocTexVram.c \
 *       --func NNSi_GfdDefaultAllocTexVram --addr 0x020614D4 --arm --cc ../2.0/sp2
 */
u32 NNSi_GfdDefaultAllocTexVram(u32 size, u32 which)
{
    u32 addr;
    u32 ok;
    u32 n;
    NNSGfdTexVramSlot *b;
    NNSGfdTexVramSlot *a;
    int i;

    if (size == 0)
        n = 0x10;
    else
        n = (size + 0xf) & ~0xfu;
    if (n >= 0x7fff0u)
        return 0;

    if (which != 0) {
        for (i = 0; i < 2; i++) {
            a = g_020A8150[i];
            if (a->enable == 0)
                continue;
            if (ROOM(a) < n)
                continue;
            switch (a->kind) {
            case 0:  b = &g_020A816C[1]; break;
            case 3:  b = &g_020A816C[2]; break;
            default: b = 0; break;
            }
            if (b->enable == 0)
                continue;
            if (ROOM(b) < (n >> 1))
                continue;
            ok = 1;
            addr = a->cur;
            a->cur = addr + n;
            b->cur += n >> 1;
            addr += a->base;
            goto done;
        }
        ok = 0;
    } else {
        for (i = 0; i < 5; i++) {
            NNSGfdTexVramSlot *c = g_020A8158[i];
            if (c->enable == 0)
                continue;
            if (ROOM(c) < n)
                continue;
            ok = 1;
            c->end -= n;
            addr = c->end + c->base;
            goto done;
        }
        ok = 0;
    }
done:
    if (ok == 0)
        return 0;
    return ((n >> 4) << 16) | ((addr << 13) >> 16) | (which << 31);
}

/*
 * An eight-byte unlabelled leaf: `mov r0, #0; bx lr`.  disasm.py only labels
 * a function whose prologue saves lr, so this stub is invisible in the
 * listing and sits between the tail of NNSi_GfdDefaultAllocTexVram's literal pool (which
 * ends at 0x02061640) and the next labelled function at 0x0206164C.
 *
 * It is the default callback NNS_GfdInitVramManager installs at 0x020A8144 as a
 * function pointer, so the pool word naming it is the only reference in the
 * image; filing this entry is what lets that pool word resolve.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdDefaultFreeTexVram.c \
 *       --func NNSi_GfdDefaultFreeTexVram --addr 0x02061644 --arm --cc 1.1p1
 */
u32 NNSi_GfdDefaultFreeTexVram(void)
{
    return 0;
}

/*
 * SAVE half of the save/restore pair the NNS G2D multi-cell renderer uses
 * around a mode switch: it copies the first two words of each of the five
 * 0x18-byte records at 0x020A816C out into the caller's flat buffer, two
 * words per record.  NNS_GfdLoadVramManager at 0x0206168C is the exact mirror and
 * restores them.
 *
 * The residue docs/notes/pkt_0206164C.c.txt recorded (10 concrete bytes, "which
 * of the three loop quantities gets which register") is resolved here, and the
 * lever is not declaration order, which that note swept exhaustively: it is
 * WHERE THE FIRST ZERO IS MATERIALISED.  The image does
 *
 *     mov r3, #0          <- i
 *     ...
 *     mov lr, r3          <- j = i, derived from the same zero
 *
 * so `i` must be the value that owns the literal and `j` must be spelled as a
 * COPY OF IT, not as its own `0`.  `int i = 0; ... int j = i;` with the `for`
 * carrying an empty init clause is byte-exact; `int j = 0` in any of the six
 * declaration orders leaves the two `mov`s swapped, which is the whole of the
 * previously recorded 10-byte residue.  This is the same shape the sibling
 * NNSi_GfdUpdateVramManager note describes (the original derives the second zero from the
 * first, the compiler materialises a second one), and the same fix applies.
 *
 * `t` sits between the two so the pointer, not `j`, takes ip; that ordering is
 * the permuter's decl-order(j<->t) result and is load-bearing for the
 * `add ip, ip, #0x18` / `add lr, lr, #2` pair.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_GfdSaveVramManager.c \
 *       --func NNS_GfdSaveVramManager --addr 0x0206164C --arm --cc 1.1p1
 *   EXACT, 64 bytes, 1 relocation site, resolved.
 */
void NNS_GfdSaveVramManager(u32 *dst)
{
    int i = 0;
    NNSGfdTexVramSlot *t = g_020A816C;
    int j = i;

    for (; i < 5; i++) {
        dst[j] = t->cur;
        dst[j + 1] = t->end;
        t++;
        j += 2;
    }
}

/*
 * RESTORE half of the pair whose save half is src/matched/NNS_GfdSaveVramManager.c:
 * it copies two words per record back from the caller's flat buffer into the
 * first two words of each of the five 0x18-byte records at 0x020A816C.
 *
 * Same lever as the save half (see that file's header): the image derives the
 * second loop zero from the first with `mov ip, r3`, so `j` has to be spelled
 * as a copy of `i` and not as its own literal `0`.
 *
 * The one DIFFERENCE from the save half is declaration order, and it is not
 * cosmetic.  In the save half `t` is declared BETWEEN `i` and `j`, which puts
 * the table pointer in ip and the destination index in lr; here the same order
 * is 10 bytes out because the registers are the other way round -- the image
 * puts the table pointer in lr and the index in ip.  Declaring `j` before `t`
 * reproduces it exactly.  The two mirrors therefore disagree on declaration
 * order despite being written from the same template, which is the
 * declaration-order-is-register-order idiom applied in both directions.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_GfdLoadVramManager.c \
 *       --func NNS_GfdLoadVramManager --addr 0x0206168C --arm --cc 1.1p1
 *   EXACT, 64 bytes, 1 relocation site, resolved.
 */
void NNS_GfdLoadVramManager(u32 *src)
{
    int i = 0;
    int j = i;
    NNSGfdTexVramSlot *t = g_020A816C;

    for (; i < 5; i++) {
        t->cur = src[j];
        t->end = src[j + 1];
        j += 2;
        t++;
    }
}
