/*
 * file:     tcbl_p01.c
 * unit:     yes
 * function: func_020306F0, func_02030734, func_020307B0, func_020307C8, func_020307E0, func_02030830, func_0203084C, func_02030880, func_020308B8, func_02030958, func_02030984, func_020309B8, func_02030A00, func_02030A2C, func_02030A5C, func_02030A7C, func_02030B50, func_02030BA4, func_02030BBC, func_02030BC8, sub_02030BD4
 * address:  0x020306F0
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
 *   sub_0202FF98   0x0202FF98  arm
 *   sub_02030524   0x02030524  arm
 *   OS_Terminate   0x02088234  arm
 *   sub_02030098    0x02030098  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   sub_02030164  0x02030164  arm
 *   func_02030238 0x02030238 arm
 *   func_02088234 0x02088234 arm
 *   sub_020302A4    0x020302A4  arm
 *   sub_02030344    0x02030344  arm
 *   sub_020304CC    0x020304CC  arm
 *   sub_020304C0    0x020304C0  arm
 *   sub_02030428    0x02030428  arm
 *   sub_02030B50    0x02030B50  arm
 *   sub_02060E6C    0x02060E6C  arm
 *   sub_02060E94    0x02060E94  arm
 *   sub_0203046C    0x0203046C  arm
 *   sub_020304B8    0x020304B8  arm
 *   sub_02060F90    0x02060F90  arm
 *   g_020A7820      0x020A7820  data
 *   g_02146970      0x02146970  data
 *   g_0214697C      0x0214697C  data
 *   str_system_name 0x020A7824  data
 *   func_020304C0   0x020304C0  arm
 *   func_02060F90   0x02060F90  arm
 *   func_020308B8   0x020308B8  arm
 *   func_0203F004   0x0203F004  arm
 *   MI_CpuCopy8     0x02082D44  arm
 *   func_020303D8   0x020303D8  arm
 *   func_02030344   0x02030344  arm
 *   func_0203038C   0x0203038C  arm
 *   func_0203046C   0x0203046C  arm
 *   func_02030428   0x02030428  arm
 *   func_0209128C   0x0209128C  arm
 *   func_02060F50   0x02060F50  arm
 *   func_02030534 0x02030534 arm
 *   func_020305C4  0x020305C4  arm
 *   sub_020305E4  0x020305E4  arm
 */
#include "../../matched/include/Obj15863.h"

struct Heap;
struct Ctx;
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

struct HeapBlockSite {
    char name[0x12];
    u16  tag;
};

typedef unsigned char u8;

struct AllocInfo {
    u16 unk_00;
    u16 pad_02;
    void *unk_04;
    void *unk_08;
    char name[0x13];
};

struct Node {
    struct Ctx  *owner;   /* +0x00 */
    struct Node *prev;    /* +0x04 */
    struct Node *next;    /* +0x08 */
    u32          key;     /* +0x0c */
    u32          arg;     /* +0x10 */
    void       (*fn)(u32);/* +0x14 */
    u32          fired;   /* +0x18 */
};

struct Ctx {
    u32           capacity;   /* +0x00 */
    u32           top;        /* +0x04 */
    struct Node   head;       /* +0x08 */
    struct Node **freeList;   /* +0x24 */
    struct Node  *pool;       /* +0x28 */
    u32           busy;       /* +0x2c */
    struct Node  *cursor;     /* +0x30 */
    struct Node  *walk;       /* +0x34 */
    struct Node  *slots[1];   /* +0x38 */
};

extern u32  sub_0202FF98(u32 heap);
extern u16 sub_02030524(void);
extern void OS_Terminate(void);
extern void *sub_02030098(u32 heapId, u32 size);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern u32 sub_02030164(void *p);
extern u32 func_02030238(void *p, u32 heapId, s32 size);
extern void func_02088234(void);
extern u32 sub_020302A4(void *p, u32 size);
extern void *sub_02030344(u32 heapId);
extern u32 sub_020304CC(u32 heapId);
extern void *sub_020304C0(void *p);
extern void *sub_02030428(u32 heapId);
extern void sub_02030B50(void *p);
extern int sub_02060E6C(int *p);
extern s32 sub_02060E94(struct Heap *heap, s32 x);
extern u16 sub_020304B8(void *p);
extern u16 sub_0203046C(u32 heapId);
extern int sub_02060F90(char *p);
extern void *func_020304C0(void *p);
extern int func_02060F90(char *p);
extern int func_020308B8(u8 *dst, const char *src);
extern u32 func_0203F004(const u8 *s);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern u32 func_020303D8(u32 heapId);
extern void *func_02030344(u32 heapId);
extern void *func_0203038C(u32 heapId);
extern u16 func_0203046C(u32 heapId);
extern void *func_02030428(u32 heapId);
extern void func_0209128C(int x);
extern void func_02060F50(int *p, void (*fn)(void *, void *, int), int ctx);
extern signed int func_02030534(u32 size);
extern void *func_020305C4(u32 size);
extern int sub_020305E4(u32 idx);
void func_020306F0(u32 heap);
void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 sub_020307B0(void *p);
asm void func_020307C8(void);
void sub_020307E0(void *p, u32 size);
void *sub_02030830(u32 heapId);
void *sub_0203084C(u32 heapId);
void sub_02030880(void *p, const char *site, u16 tag);
int sub_020308B8(u8 *dst, const char *src);
void sub_02030958(u32 heapId, u32 size, const char *site, int tag);
void sub_02030984(void *p, u32 size);
void sub_020309B8(void *p);
void sub_02030A00(u32 heapId, void *p, u32 size);
void sub_02030A2C(void *p);
void sub_02030A5C(u32 heapId);
void func_02030A7C(void *heap);
void func_02030B50(void *p);
asm void func_02030BA4(void);
void *sub_02030BBC(u32 a0);
int sub_02030BC8(u32 idx);
extern s32 g_020A7820;
extern struct AllocInfo g_02146970;
extern char g_0214697C[0x13];
extern const char str_system_name[];





/*
 * Heap teardown: run the pre-destroy hook, then destroy.  On failure ask
 * sub_02030524 for the current error policy and terminate under policies 1
 * and 2, the same policy read the rest of the heap layer does (see
 * src/matched/sub_0203084C.c, which spells the complementary
 * `!= 1 && != 2 && == 3` shape).
 *
 * The two arms each carry their own `bl OS_Terminate` and their own
 * epilogue rather than sharing one: that is what an `else if` chain of two
 * equality tests gives here, and it is also the evidence that the compiler
 * was not told OS_Terminate is noreturn, since a `pop` follows each call.
 *
 * The two arms must be a `switch`, not an `else if` chain.  Written as two
 * equality `if`s the compiler inlines the first arm on the fall-through
 * path (`bne` over a `bl`/`pop` pair) and the function comes out 64 bytes
 * instead of 68; the switch is what pushes both arms past the shared
 * `pop {r4, pc}` and leaves two forward `beq`s.
 *
 * The PC24 at +0x10 (sub_0202FF98) has no `label` witness: func_020306F0
 * is 0x0202FF98's only caller image-wide, and the two are not contiguous,
 * so no unit can make the site `local` either.  It resolves on class
 * `matched` against src/matched/sub_0202FF98.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020306F0.c \
 *       --func func_020306F0 --addr 0x020306F0 --cc 1.1p1 --arm
 */
void func_020306F0(u32 heap)
{
    sub_02030A5C(heap);

    if (sub_0202FF98(heap) == 0) {
        u32 state = sub_02030524();

        switch (state) {
        case 1:
            OS_Terminate();
            break;
        case 2:
            OS_Terminate();
            break;
        }
    }
}





/*
 * The allocation entry point of the game's heap layer, and the highest-
 * radiation function in the image: 1163 branch references from arm9 and
 * the overlays. Every object constructor in the game that wants memory
 * goes through this wrapper rather than calling the raw allocator at
 * 0x02030098 directly.
 *
 *   void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
 *                      u16 tag)
 *
 * Previously capped at MATCH: all 124 concrete bytes were correct but four
 * of the seven relocation sites had no witness, each target's only branch
 * reference in the image being the call inside this function. All four are
 * now EXACT and attest this file by the `matched` class:
 *
 *   0x02030098  the raw allocator            src/matched/sub_02030098.c
 *   0x02030880  provenance stamp             src/matched/sub_02030880.c
 *   0x02030958  out-of-memory reporter       src/matched/sub_02030958.c
 *   0x02030A00  watched-allocation hook      src/matched/sub_02030A00.c
 *
 * The fifth argument is a u16 delivered on the stack; with six registers
 * pushed it lands at [sp, #0x18], and the callee reads it back with a
 * halfword load rather than a word load, which is what pins its type.
 * It is carried, together with the fourth argument, into the success-side
 * bookkeeping call sub_02030880, which stamps the pair into the 0x1c-byte
 * block header the raw allocator reserved: the string goes into the
 * 0x12-byte name field at header+4 and the tag into the halfword at
 * header+0x16. It is *not* the classic __FILE__/__LINE__ pair: the sites
 * that call this pass addresses above the arm9 static image end
 * (0x020A6800 per layout/layout.json), i.e. BSS globals, not string
 * constants. See src/matched/sub_020457B0.c for a worked caller.
 *
 * Shape notes:
 *
 *  - The raw allocator sub_02030098 reads only r0 and r1, so this call
 *    forwards only heapId and size; r2 and r3 arriving unchanged from
 *    this function's own prologue are leftovers, the shape of
 *    docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md.
 *    The same is true of the failure reporter: sub_02030958 reads only
 *    r0, so the site and tag registers set up for it are leftovers too,
 *    and the four-parameter declaration below is kept only because it is
 *    what the original call site's register setup looks like.
 *  - The failure arm is the fall-through, so it is written first
 *    (docs/idioms/the-fall-through-arm-is-the-source-order.md). It calls
 *    sub_02030524 with no arguments, reports, then OS_Terminate; the
 *    branch to the shared `return p` tail after OS_Terminate shows the
 *    compiler was not told OS_Terminate is noreturn.
 *  - The clear flag guards MIi_CpuClear32(0, p, size), which is why a
 *    caller that wants zeroed memory passes a non-zero third argument
 *    rather than clearing at the call site.
 *
 * layout/symbols_sdk.json offers the names GX_GetBankForBGExtPltt for
 * 0x02030524 and ENV_SetResourceSet for 0x020307B0. Both are
 * signature-matcher guesses with large sibling sets (37 and 8
 * respectively) and neither fits the role played here, so the canonical
 * sub_ names are used. MIi_CpuClear32 and OS_Terminate have no such
 * ambiguity and keep their SDK names.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030734.c \
 *       --func sub_02030734 --addr 0x02030734 --cc 1.1p1 --arm
 */
void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag)
{
    void *p;

    p = sub_02030098(heapId, size);
    if (p == 0) {
        sub_02030524();
        sub_02030958(heapId, size, site, tag);
        OS_Terminate();
    } else {
        sub_02030880(p, site, tag);
        sub_02030A00(heapId, p, size);
        if (clear != 0) {
            MIi_CpuClear32(0, p, size);
        }
    }
    return p;
}





/*
 * The release counterpart of sub_02030734, and the second-highest-radiation
 * function of the heap layer: 904 branch references image-wide.  It runs the
 * watched-allocation bookkeeping first (sub_02030A2C, which reads the block
 * header the raw allocator stamped) and then hands the pointer to the raw
 * free at 0x02030164, which walks back over the 0x1c-byte header.
 *
 * The pointer has to survive the first call, which is the whole reason for
 * the `push {r4, lr}` and the `mov r0, r4` before the second: with the calls
 * the other way round the parameter would still be in r0 and the function
 * would be a pair of tail calls.
 *
 * layout/symbols_sdk.json offers the name ENV_SetResourceSet for this
 * address.  It is a signature-matcher guess with eight siblings, and the role
 * here is plainly the heap free, so the canonical sub_ name is used; see the
 * same note in src/matched/sub_02030734.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020307B0.c \
 *       --func sub_020307B0 --addr 0x020307B0 --cc 1.1p1 --arm
 */
u32 sub_020307B0(void *p)
{
    sub_02030A2C(p);
    return sub_02030164(p);
}





asm void func_020307C8(void)
{
    stmfd sp!, {r3, lr}
    bl func_02030238
    cmp	r0, #0
    ldmnefd sp!, {r3, pc}
    bl func_02088234
    ldmfd sp!, {r3, pc}
}





/*
 * BLOCKED on one relocation site: all 80 concrete bytes are correct, but
 * the call to sub_020302A4 at +0004 has no witness, that call being
 * 0x020302A4's only branch reference in the image. 0x020302A4 is written
 * and byte-correct in src/pending/sub_020302A4.c but is itself capped at
 * MATCH on sub_02060CD0, so the chain is
 * 0x02060CD0 -> 0x020302A4 -> this function: one EXACT entry for
 * 0x02060CD0 promotes all three.
 *
 * A heap-state assertion, guarded on the result of sub_020302A4 and then
 * dispatched on the heap-layer state word returned by sub_02030524.
 *
 *   void sub_020307E0(void *p, u32 size)
 *
 * Neither call takes an argument. The dispatch is the ARM form of the
 * dense switch: `cmp r0, #5` then `addls pc, pc, r0, lsl #2`, so the table
 * runs from case 0 to case 5 inclusive and the fall-through past the
 * `addls` is the default. Every case body here is one instruction, so the
 * bodies live directly in the table slots rather than being branched to:
 * cases 0, 4 and 5 are the bare `pop`, cases 1, 2 and 3 are branches to
 * three separate `bl OS_Terminate; pop` blocks further down.
 *
 * Those three blocks are byte-identical and are *not* cross-jumped, which
 * is the interesting part: writing the three arms as one shared arm
 * (`case 1: case 2: case 3:`) collapses them into a single block and loses
 * sixteen bytes. Each arm must be spelled out separately. The likely
 * original is three distinct assertion messages that the release build
 * stripped down to the same call.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020307E0.c \
 *       --func sub_020307E0 --addr 0x020307E0 --cc 1.1p1 --arm
 */
void sub_020307E0(void *p, u32 size)
{
    if (sub_020302A4(p, size) != 0) {
        return;
    }
    switch (sub_02030524()) {
    case 0:
        break;
    case 1:
        OS_Terminate();
        break;
    case 2:
        OS_Terminate();
        break;
    case 3:
        OS_Terminate();
        break;
    case 4:
        break;
    case 5:
        break;
    }
}





/*
 * Asserting wrapper around sub_02030344: forwards its single argument,
 * terminates if the result is NULL, and hands the result back either way.
 *
 *   void *sub_02030830(u32 heapId)
 *
 * The `movs r4, r0` that both saves and tests the result is the tell that
 * the value is bound to a local before being compared, not compared as a
 * call expression; the value has to survive the OS_Terminate call, which
 * is what spends r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030830.c \
 *       --func sub_02030830 --addr 0x02030830 --cc 1.1p1 --arm
 */
void *sub_02030830(u32 heapId)
{
    void *p;

    p = sub_02030344(heapId);
    if (p == 0) {
        OS_Terminate();
    }
    return p;
}





/*
 * Promoted from MATCH with no change to the C. The call to sub_020304CC at
 * +0004 was the one unresolved site: 0x020304CC's only branch reference in
 * the image is this call, so no `label` witness exists. It closed when
 * src/matched/sub_020304CC.c landed EXACT, which makes the site `matched`.
 *
 * Asserting wrapper around sub_020304CC, the same shape as sub_02030830
 * but with the assertion itself gated on the heap-layer state word.
 *
 *   void *sub_0203084C(u32 heapId)
 *
 * The guard is one three-term conjunction, and the way it splits across
 * the instructions is what pins that reading: `cmp r0, #1` / `cmpne r0,
 * #2` is the conditional-compare fold of the first two terms into a single
 * `beq`, and the third term gets its own `cmp r0, #3` / `bne`. The third
 * term subsumes the first two, so as written the test is just `state ==
 * 3`; the compiler does not simplify it, and writing only `state == 3`
 * loses the first two comparisons and eight bytes. The redundancy is
 * evidence that the original spelled three named state constants.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203084C.c \
 *       --func sub_0203084C --addr 0x0203084C --cc 1.1p1 --arm
 */
void *sub_0203084C(u32 heapId)
{
    void *p;
    u32 state;

    p = (void *)sub_020304CC(heapId);
    if (p == 0) {
        state = sub_02030524();
        if (state != 1 && state != 2 && state == 3) {
            OS_Terminate();
        }
    }
    return p;
}





/*
 * Success-side bookkeeping for the allocation entry point sub_02030734:
 * stamps the allocation-site provenance pair (name string, u16 tag) into
 * the block header of a freshly allocated payload.
 *
 *   void sub_02030880(void *p, const char *site, u16 tag)
 *
 * sub_020304C0 (already EXACT) converts the payload pointer into
 * `&((char *)p - 0x1c)[4]`, so the provenance record lives at header+4 and
 * is 0x14 bytes wide: an 0x12-byte name field followed by the u16 tag at
 * +0x12. The copy is a bounded strncpy-shaped loop that stops on the NUL
 * but, like strncpy with a full-length source, does not NUL-terminate: the
 * terminator is only written because it is copied.
 *
 * The single `ldrsb` per iteration (not two loads) is the tell that the
 * source byte is bound to a local before being both stored and tested;
 * writing `dst[i] = site[i]; if (site[i] == 0)` would reload, since a
 * `const char *` source may alias the `char *` destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030880.c \
 *       --func sub_02030880 --addr 0x02030880 --cc 1.1p1 --arm
 */
void sub_02030880(void *p, const char *site, u16 tag)
{
    struct HeapBlockSite *rec;
    int i;

    rec = (struct HeapBlockSite *)sub_020304C0(p);
    for (i = 0; i < 0x12; i++) {
        char c = site[i];
        rec->name[i] = c;
        if (c == 0) {
            break;
        }
    }
    rec->tag = tag;
}





/*
 * Copies a block's allocation-site name out of its header into a caller
 * buffer and answers whether the name is plausible. A leaf: no prologue,
 * no relocations.
 *
 *   int sub_020308B8(u8 *dst, const char *src)
 *
 * Three passes, in this order:
 *
 *  1. Copy up to 0x12 bytes, stopping on the NUL, then NUL-terminate at
 *     the copied length. This is the read-back of what sub_02030880
 *     stamped, and it is the mirror image of that function's loop: there
 *     the terminator is stored and the length test comes after the store,
 *     here the test comes first and the terminator is written separately,
 *     which is why the buffer must be 0x13 bytes and not 0x12.
 *  2. Every byte must be printable ASCII, 0x20..0x7e. The `ldrb` here
 *     against the `ldrsb` of the copy loop is the whole signedness story:
 *     the source is `char` (signed by -char signed) and the destination is
 *     read back as `u8`, which is what makes `< 0x20` an unsigned `blo`.
 *  3. A name shorter than the full 0x12 bytes must contain a '.', i.e. it
 *     must look like a file name. A name that fills the field is accepted
 *     without the dot, since the dot may simply have been truncated away.
 *
 * An empty name is rejected before pass 2, and the zero it returns is the
 * same register the NUL-terminator store just materialised, which also
 * seeds the pass-2 index: one `mov r2, #0` doing three jobs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020308B8.c \
 *       --func sub_020308B8 --addr 0x020308B8 --cc 1.1p1 --arm
 */
int sub_020308B8(u8 *dst, const char *src)
{
    int len;
    int i;

    for (len = 0; len < 0x12; len++) {
        char c = src[len];
        if (c == 0) {
            break;
        }
        dst[len] = c;
    }
    dst[len] = 0;
    if (len == 0) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        u8 c = dst[i];
        if (c < 0x20 || c > 0x7e) {
            return 0;
        }
    }
    if (len < 0x12) {
        for (i = 0; i < len; i++) {
            if (dst[i] == '.') {
                break;
            }
        }
        if (i == len) {
            return 0;
        }
    }
    return 1;
}





/*
 * The out-of-memory failure reporter reached from the allocation entry
 * point sub_02030734 just before OS_Terminate.
 *
 *   void sub_02030958(u32 heapId)
 *
 * Only r0 is read. sub_02030734 sets up four argument registers at this
 * call (heapId, size, site, tag) but the last three arrive unchanged from
 * its own prologue and are leftovers, the shape of
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md;
 * the declaration in src/pending/sub_02030734.c spelling four parameters
 * is therefore wider than the real callee and should be narrowed to one
 * when that file is revisited.
 *
 * Body: sub_02030428 maps the public heap id to the heap's arena handle
 * (it masks the id, range-checks it against the count at +8 of the heap
 * table, records an error code at +0xe on failure and otherwise tail-calls
 * sub_0202FBAC), that handle is then walked by sub_02060E6C and dumped by
 * sub_02060E94 with a mode of 4, and sub_02030B50 is passed the original
 * public id. The handle value is live across two calls, so it costs r4,
 * and the id costs r5.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030958.c \
 *       --func sub_02030958 --addr 0x02030958 --cc 1.1p1 --arm
 */
void sub_02030958(u32 heapId, u32 size, const char *site, int tag)
{
    void *arena;

    arena = sub_02030428(heapId);
    sub_02060E6C(arena);
    sub_02060E94(arena, 4);
    sub_02030B50((void *)heapId);
}





/*
 * The watched-allocation audit, reached only from sub_02030A00 when the
 * global watch id g_020A7820 names this allocation's heap.
 *
 *   void sub_02030984(void *p)
 *
 * Only r0 is read; sub_02030A00 also sets r1 to the size, a leftover
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * Three things happen, and two of them discard their results, which is
 * what a stripped diagnostic looks like: the calls survive for their side
 * effects (sub_0203046C records an error code in the heap table at +0xe)
 * and for the bounds checking they perform, while the value each computes
 * is dropped.
 *
 *  - sub_020304C0(p) is the provenance record stamped by sub_02030880,
 *    i.e. header+4. It is live across two calls and so costs r4.
 *  - sub_020304B8(p) is a plain `ldrh [p, #-0x1c]`: the heap id stored in
 *    the first halfword of the block header. It feeds sub_0203046C, the
 *    id-to-arena mapper, whose result is dropped.
 *  - sub_020308B8 copies the provenance name into a 0x13-byte stack
 *    buffer and validates it (all bytes printable 0x20..0x7e, and a '.'
 *    present unless the name fills all 0x12 bytes); its verdict is also
 *    dropped. The buffer is declared before the pointer locals, which is
 *    what puts it at sp+0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030984.c \
 *       --func sub_02030984 --addr 0x02030984 --cc 1.1p1 --arm
 */
void sub_02030984(void *p, u32 size)
{
    u8 buf[0x13];
    void *rec;

    rec = sub_020304C0(p);
    sub_0203046C(sub_020304B8(p));
    sub_020308B8(buf, (const char *)rec);
}





/*
 * The free-side audit, the counterpart of sub_02030984: same three opening
 * calls, then the actual release of the block and a dump of the heap it
 * came from.
 *
 *   void sub_020309B8(void *p)
 *
 * The difference from sub_02030984 is that the block's heap id is needed
 * twice here, so it is bound to a local and costs r4, while in
 * sub_02030984 it flows straight from sub_020304B8 into sub_0203046C and
 * costs nothing. sub_02060F90 is handed the header address (p - 0x1c), the
 * same address sub_02030098 got back from the expanded-heap allocator, and
 * sub_02030344 then dumps the heap the id names.
 *
 * The 0x13-byte scratch buffer is declared first, which is what puts it at
 * sp + 0; the stack frame is rounded to 0x14.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020309B8.c \
 *       --func sub_020309B8 --addr 0x020309B8 --cc 1.1p1 --arm
 */
void sub_020309B8(void *p)
{
    u8 buf[0x13];
    void *rec;
    u32 heapId;

    rec = sub_020304C0(p);
    heapId = sub_020304B8(p);
    sub_0203046C(heapId);
    sub_020308B8(buf, (const char *)rec);
    sub_02060F90((char *)p - 0x1c);
    sub_02030344(heapId);
}





/*
 * Success-side bookkeeping for the allocation entry point sub_02030734,
 * and a debug filter: the whole body is gated on a global watch id.
 *
 *   void sub_02030A00(u32 heapId, void *p, u32 size)
 *
 * g_020A7820 is a signed watch id, -1 (or any negative value) meaning
 * "watch nothing". Only when it is non-negative and equal to the heap id
 * of this allocation does the block get handed to sub_02030984, which
 * validates the provenance name stamped by sub_02030880.
 *
 * The `cmp r3, #0` / `cmpge r0, r3` pair is the conditional-compare fold
 * of a single `&&`: the first comparison is the first-written conjunct,
 * and the guard must be one expression, not two sequential `if`s, for the
 * `popne` to serve both.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030A00.c \
 *       --func sub_02030A00 --addr 0x02030A00 --cc 1.1p1 --arm
 */
void sub_02030A00(u32 heapId, void *p, u32 size)
{
    if (g_020A7820 >= 0 && heapId == (u32)g_020A7820) {
        sub_02030984(p, size);
    }
}





/*
 * The free-side watch filter, exactly the shape of sub_02030A00 on the
 * allocation side: the audit runs only when the global watch id names this
 * block's heap.
 *
 *   void sub_02030A2C(void *p)
 *
 * The heap id is not a parameter here, it is read back out of the block's
 * own header by sub_020304B8, which is why the call is scheduled before
 * the global is even loaded: its result has to be in r0, and only then can
 * the conditional-compare pair `cmp r1, #0` / `cmpge r0, r1` fold the two
 * conjuncts. The source order of the conjuncts is still watch-id-first,
 * the order the comparisons appear in.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030A2C.c \
 *       --func sub_02030A2C --addr 0x02030A2C --cc 1.1p1 --arm
 */
void sub_02030A2C(void *p)
{
    u32 heapId;

    heapId = sub_020304B8(p);
    if (g_020A7820 >= 0 && heapId == (u32)g_020A7820) {
        sub_020309B8(p);
    }
}





/*
 * Dumps a heap, but only if the heap actually has live allocations.
 *
 *   void sub_02030A5C(u32 heapId)
 *
 * sub_0203046C returns the heap's +0xc record halfword, which
 * sub_02030098 increments on every successful allocation, so a zero answer
 * means an empty heap and there is nothing to report. Note that the
 * out-of-range answer from sub_0203046C is 0xffff, not zero, so a bad id
 * still reaches sub_02030B50; the range check is left to that call.
 *
 * The id has to survive the first call, which is what spends r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030A5C.c \
 *       --func sub_02030A5C --addr 0x02030A5C --cc 1.1p1 --arm
 */
void sub_02030A5C(u32 heapId)
{
    if (sub_0203046C(heapId) != 0) {
        sub_02030B50((void *)heapId);
    }
}





/*
 *           8 of 10 relocation sites resolved.  Down from 3 unresolved sites to 2.
 *           sole-ref x1 -- the class was widened 2026-09-21 to accept an address that
 *           lands on something the layout recognises, and 0x020A7824 is the start of a
 *           NUL-terminated printable run (sole-ref/string).  The note below about
 *           attest_string() refusing it is still accurate for the OLD `string` class
 *           and is kept for the record, but it no longer blocks this file.
 * Fills in the allocator's bookkeeping object at 0x02146970 (u16 tag, two
 * pointers, then an 18-character name buffer at 0x0214697C) and names the
 * block it was handed.  The block's own id is read out of the block header
 * (+0x12, a u16 halfword) when func_020308B8 finds a name for the scratch
 * buffer, and the buffer is otherwise loaded with the 13-byte default
 * "SYSTEM ALLOC" at 0x020A7824 and tagged 0.  That name is then copied into
 * the object's name buffer (length + 1) and space-padded out to 18 columns
 * with the terminator at the padding boundary, which is why the loop is
 * written as a guarded `do` with the index left over for the final store.
 *
 * Every byte of the 212-byte extent matches, relocation fields aside: this
 * file compiles to 212 bytes of which 200 are code, exactly the original's
 * shape, and match.py's only complaint is the three wildcarded pool words
 * below.  All three are data:
 *
 *  - 0x02146970 and 0x0214697C are bss addresses (bss runs from 0x020A9E80
 *    to 0x021542C0 and is not part of this image), so nothing disassembles
 *    there and the only evidence class that can ever name them is `literal`.
 *  - 0x020A7824 is the "SYSTEM ALLOC" string.  The `string` class refuses
 *    it: the four bytes immediately before it are FF FF FF FF (a word
 *    alignment filler between it and the preceding "time_icon.c"), and
 *    attest_string() requires NUL padding directly before the run, not
 *    another string's terminator four bytes away.  `data_table` refuses it
 *    as well -- 0x54535953 is not a pointer into a loaded region.
 *
 * So the function's own literal pool is the only thing in the image that
 * holds these three values: each has exactly one pool word image-wide
 * (0x02030B44, 0x02030B48, 0x02030B4C) and all three sit inside the
 * function's own extent, where the honesty rule refuses them as witnesses.
 * `--suggest-split` returns 0 pieces and leaves the single function out:
 * there is no cut that frees a site, because this function is the whole
 * range.  The three addresses are unwitnessable at any spelling of the C --
 * the pass is only reachable when some *other* matched function happens to
 * pool one of them, and nothing else in the image references them.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02030A7C.c \
 *       --func func_02030A7C --addr 0x02030A7C --cc 1.1p1 --arm
 */
void func_02030A7C(void *heap)
{
    u8 buf[0x14];
    u8 *p = (u8 *)heap + 0x1c;
    void *h = func_020304C0(p);
    u16 v;
    s32 n;
    s32 k;
    s32 i;

    g_02146970.unk_08 = (void *)func_02060F90(heap);
    g_02146970.unk_04 = p;
    if (func_020308B8(buf, h) != 0) {
        v = ((struct Obj15863 *)h)->f12;
    } else {
        MI_CpuCopy8(str_system_name, buf, 0xd);
        v = 0;
    }
    n = func_0203F004(buf);
    MI_CpuCopy8(buf, g_0214697C, n + 1);
    g_02146970.unk_00 = v;
    k = 0x12 - func_0203F004(buf);
    i = 0;
    if (k > 0) {
        do {
            buf[i] = ' ';
            i++;
        } while (i < k);
    }
    buf[i] = 0;
}





/*
 * Tears the object down and then runs func_02030A7C over every block in the
 * allocator list: the five per-object teardown calls, the global
 * "shutting down" flag set through func_0209128C(1), then func_02060F50 with
 * the callback and the context the teardown returned, and the flag cleared
 * again with func_0209128C(0).  The callback is passed a zero context, which
 * is why the constant is materialised once in r4 and copied to r2 rather
 * than emitted twice.
 *
 * All 84 bytes of the extent match, relocation fields aside: 80 bytes of
 * code plus the function's own pool word, exactly the original's shape.  The
 * blocker is not the C -- it is that this function is the only evidence for
 * two of the addresses it names:
 *
 *  - 0x0209128C (the "shutting down" flag setter at the head of packet
 *    pkt_020911D8) is branched to from exactly two sites in the whole image,
 *    and both of them are this function's own two `bl`s.  The `label` class
 *    needs a branch from *outside* the compared range, so the range being
 *    this function makes the only witnesses in the image inadmissible.
 *  - 0x02030A7C (the callback, and this packet's other function) is named by
 *    a single pool word image-wide, at 0x02030BA0, and that word is inside
 *    this function's own extent; nothing anywhere `b`/`bl`s to it, so the
 *    `label` class has no site to offer either.  It is also why the two
 *    functions cannot attest each other: func_02030A7C is this file's
 *    sibling in pkt_02030A7C, but it is itself MATCH-capped on three data
 *    sites (see src/pending/func_02030A7C.c), so no `matched` entry exists
 *    to witness this call.
 *
 * `--suggest-split` returns 0 pieces and leaves the single function out:
 * both blockers are inside the range and no cut can free them.  Every
 * unresolved site here clears the moment the function it names is matched
 * by somebody else -- 0x0209128C is an entry point of pkt_020911D8, and
 * 0x02030A7C is blocked on bss evidence rather than on anything this file
 * could do differently.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02030B50.c \
 *       --func func_02030B50 --addr 0x02030B50 --cc 1.1p1 --arm
 */
void func_02030B50(void *p)
{
    func_020303D8((u32)p);
    func_02030344((u32)p);
    func_0203038C((u32)p);
    func_0203046C((u32)p);
    func_0209128C(1);
    func_02060F50(func_02030428((u32)p), (void (*)(void *, void *, int))func_02030A7C, 0);
    func_0209128C(0);
}




asm void func_02030BA4(void)
{
    stmfd sp!, {r3, lr}
    bl func_02030534
    cmp	r0, #0
    ldmnefd sp!, {r3, pc}
    bl func_02088234
    ldmfd sp!, {r3, pc}
}




/*
 * A four-instruction tail call: `ldr ip, [pc]; bx ip; .word target`. The
 * target, 0x020305C4, is not itself a labelled function: it is the second
 * half of the 176-byte function at 0x02030534 (pkt_02030534, outside this
 * packet), reached only through this pool word and never by a branch, so
 * `disasm.py`'s prologue sweep never fires on it. See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md for the shape;
 * this is the same phenomenon one level up, a whole secondary entry point
 * rather than one accessor.
 *
 * Promoted from MATCH with no change to the C. The one relocation had no
 * witness under the honesty rule: the only reference to 0x020305C4
 * anywhere is this call, inside the range under test, and the address
 * carried no func_ label. It closed when 0x020305C4 was seeded into
 * layout/function_starts.txt and written as src/matched/func_020305C4.c,
 * which makes the site `matched`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030BBC.c \
 *       --func sub_02030BBC --addr 0x02030BBC --cc 1.1p1 --arm
 */
void *sub_02030BBC(u32 a0)
{
    return func_020305C4(a0);
}




/*
 * A four-instruction tail call to sub_020305E4 (src/matched/sub_020305E4.c,
 * pkt_02030534), attested by the `matched` class: sub_020305E4's own EXACT
 * entry pins its address, and this call is the only branch to it found in
 * the ROM.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030BC8.c \
 *       --func sub_02030BC8 --addr 0x02030BC8 --cc 1.1p1
 */
int sub_02030BC8(u32 idx)
{
    return sub_020305E4(idx);
}


/*
 * Refill the free stack: every node in the pool is blanked, pointed back at
 * its owner and at the sentinel, and pushed onto the stack in index order, so
 * afterwards the stack holds all `capacity` nodes and the top index is zero.
 * The allocator in src/matched/unit_02030C44.c reads that stack from the top.
 *
 * The node stride is 0x1c, so the pool index is a real `mul` against a hoisted
 * 0x1c, not a shift.  `&c->pool[i]` is recomputed from the field for the
 * free-stack store, and the loop bound re-reads c->capacity, because the
 * writes through the cursor may alias either pointer.
 *
 * This function is kept in its own file rather than folded into
 * unit_02030C44.c beside it: a unit spanning both records its manifest entry
 * at the unit's own start address, and 0x02030C44 then stops being an
 * attestable address, which costs unit_02030DA8.c its only witness.  See
 * docs/idioms/a-unit-attests-only-its-own-start-address.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030BD4.c  *       --func sub_02030BD4 --addr 0x02030BD4 --cc 1.1p1 --arm
 */
void sub_02030BD4(struct Ctx *c)
{
    struct Node *n;
    u32 i;

    for (i = 0; i < c->capacity; i++) {
        n = &c->pool[i];
        n->owner = c;
        n->next = &c->head;
        n->prev = &c->head;
        n->key = 0;
        n->arg = 0;
        n->fn = 0;
        c->freeList[i] = &c->pool[i];
    }
    c->top = 0;
}
