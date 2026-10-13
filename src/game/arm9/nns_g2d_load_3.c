/*
 * file:     nns_g2d_load_3.c
 * unit:     yes
 * function: func_02062BAC, func_02062BF4, func_02062D08, func_02062D40, func_02062D4C, func_02062F00, sub_02062F1C, func_02062F38, func_02062F78
 * address:  0x02062BAC
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02062F90  0x02062F90  arm
 *   func_02091588  0x02091588  arm
 */
#include "../../matched/include/Obj07015.h"
#include "../../matched/include/Obj11525.h"
#include "../../matched/include/Obj16406.h"

struct NNSG2dAnimController;
struct Slider;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Tbl {
    u16   count;                /* 0x00  number of offsets, read with ldrh   */
    u16   pad02;
    u8  **offsets;              /* 0x04  itself an offset until fixed up     */
};

struct Sub {
    u16 h0;       /* 0x00 */
    u16 h2;       /* 0x02 */
    u32 pad04;    /* 0x04 */
    u32 field_08; /* 0x08 */
    u32 ptr_0C;   /* 0x0C */
};

typedef void (*Callback)(u32, u32);

struct Slider {
    u32 pos;         /* 0x00 */
    u32 pad04;       /* 0x04 */
    u32 field_08;    /* 0x08 */
    u32 field_0C;    /* 0x0C */
    u32 field_10;    /* 0x10 */
    u32 pad14;       /* 0x14 */
    u32 field_18;    /* 0x18 */
    struct Sub *sub; /* 0x1C */
    u32 field_20;    /* 0x20 */
    u32 field_24;    /* 0x24 */
    Callback cb_28;  /* 0x28 */
};

typedef signed int     s32;

struct CellAnim {
    u32 unk00;
    void **sequence;
};

typedef long long s64;

typedef int BOOL;

typedef struct {
    void *pContent;
    u16 frames;
    u16 pad;
} Frame;

typedef struct {
    u16 numFrames;
    u16 loopStartFrameIdx;
    u32 animType;
    u32 playMode;
    Frame *pFrameArray;
} Seq;

typedef struct {
    u32 type;
    u32 param;
    void (*pFunc)(u32 param, u32 idx);
    u16 frameIdx;
} Functor;

typedef struct {
    Frame *pCurrent;
    Frame *pActiveCurrent;
    BOOL bReverse;
    BOOL bActive;
    s32 currentTime;
    s32 speed;
    u32 overriddenPlayMode;
    Seq *pAnimSequence;
    Functor callback;
} Ctrl;

struct AnimState {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u16 unk0C;
};

struct AnimObj {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    struct AnimState anim;
};

struct Owner {
    u8  pad_00[0xc];
    u32 base;
};

struct Node {
    u32           cursor;
    u8            pad_04[0x18];
    struct Owner *owner;
};

extern void func_02062F90(struct NNSG2dAnimController *pAnimCtrl);
extern s32 func_02091588(s32 x);
void func_02062BAC(struct Tbl *t);
void func_02062BF4(struct Slider *s);
int func_02062D08(void *p, u32 i);
void *func_02062D40(struct CellAnim *anim);
BOOL func_02062D4C(Ctrl *p, s32 frames);
int func_02062F00(void *s, u32 i);
u16 sub_02062F1C(const struct Node *n);
int func_02062F38(int a0);
void func_02062F78(struct AnimState *state);





/*
 * The NNS G2D offset-fixup pass for one loaded block.  A block that has just
 * been read off the card stores its interior pointers as offsets from the
 * block's own start; this walks a (count, offset array) header and turns every
 * one of them into an absolute address, the array pointer itself first.  It is
 * a leaf with no relocation sites at all -- the only address it ever adds is
 * its own argument.
 *
 * Neighbour of src/matched/NNS_G2dFindBinaryBlock.c, which is the block-chain lookup
 * for the same NITRO file format; this is what the caller runs over the block
 * that lookup returns.
 *
 * FOUR THINGS THE BYTES FORCED, in the order they cost time:
 *
 *   1. THE ARRAY ELEMENT IS A POINTER, NOT A `u32`.  This is the whole
 *      residue at the end and it is worth stating plainly: the image adds the
 *      base with `add r2, r0, r2` -- the object pointer in the LEFT slot --
 *      and every spelling whose left operand is an integer gives
 *      `add r2, r2, r0` instead.  `x += (u32)t`, `x = (u32)t + x`, and the
 *      same two through a hoisted `u32 *e = &t->offsets[i]` are all identical
 *      and all wrong, because with a `u32` element the front end treats the
 *      cast object address as the addend and the loaded word as the
 *      accumulator.  Declaring the array as `u8 **` and writing
 *      `t->offsets[i] = (u8 *)t + (u32)t->offsets[i]` makes the object the
 *      POINTER operand of pointer-plus-integer, which this front end always
 *      issues left-first, and the byte falls out.  This is the pointer-typed
 *      companion to
 *      docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md
 *      and to docs/idioms/commutative-operand-order-names-the-temporary.md:
 *      operand order here names the TYPE, not the temporary.
 *
 *   2. The loop is a plain `while (t->count > i)`, not `if (n) do ... while`.
 *      The image re-reads the count with `ldrh r2, [r0]` at the BOTTOM of
 *      every iteration as well as testing it once at the top, which is what a
 *      `while` on a field (rather than on a local copy) costs; hoisting the
 *      count into a `u16 n` local loses the reload.
 *
 *   3. The top guard is `>` on the unsigned count, which is why the early exit
 *      is `cmp r1, #0 / bxls lr` and not `bxeq lr`.  Spelling it `if (n != 0)`
 *      gives the `eq` form -- one byte, and the first thing to check on this
 *      shape.
 *
 *   4. `i` is a `u16`: the `lsl r1, r1, #0x10` / `lsr ip, r1, #0x10` pair
 *      around the increment is the truncation, and the loop bound is compared
 *      against the pre-truncation value with `cmp r2, r1, lsr #16`.
 *
 * THE `../2.0/sp2` PIN.  dsi/1.1p1 with the final body is 14 concrete bytes
 * out and with the `u32` body 16; the permuter cannot close either
 * (`--explain` shows a three-way r0/r1/r2 reshuffle, `--mode hill --budget
 * 800 --types` exhausts 82 singles with no improvement, `--mode anneal
 * --budget 2000 --jobs 8 --types` never leaves the baseline).  ../1.2/sp2 is
 * 4 bytes out.  ../2.0/sp2 reproduces the image byte for byte.  The residue
 * 1.1p1 leaves is the prologue schedule -- it hoists the `ldrh` of the count
 * above the `add`/`str` of the array pointer and pushes the `mov ip, #0` down
 * past the compare -- which is the same scheduling family as the cluster's
 * other 2.0 rows.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062BAC.c \
 *       --func func_02062BAC --addr 0x02062BAC --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 72 = original 72, 0 relocation sites
 */
void func_02062BAC(struct Tbl *t)
{
    u16 i;

    t->offsets = (u8 **)((u8 *)t->offsets + (u32)t);
    i = 0;
    while (t->count > i) {
        t->offsets[i] = (u8 *)t + (u32)t->offsets[i];
        i = i + 1;
    }
}





static inline u32 getMode(struct Slider *s) {
    u32 m = s->field_18;
    if (m == 0) {
        m = s->sub->field_08;
    }
    return m;
}




/*
 * One step of the NNS G2D cell/animation player: advance the playback cursor,
 * fire the user callback if one is armed, hand off to func_02062F90 when the
 * playback mode says to, and finally clamp the cursor into the frame table's
 * bounds.
 *
 * The body is the one docs/notes/pkt_02062BF4.c.txt recorded as a codegen wall
 * (26 concrete bytes out under dsi/1.1p1, with 208 of the 276 bytes already
 * instruction-for-instruction).  It is filed here essentially unchanged.  TWO
 * things closed it, and neither was a new reading of the function:
 *
 *   1. THE `../2.0/sp2` PIN closes the note's second residue outright.  The
 *      note's item 2 was the scheduler moving the independent
 *      `ldr r1, [r4, #0x1c]` up into the load-delay slot of `ldr r0, [r4, #8]`,
 *      splitting the image's `ldr / eor / str / ldr` into `ldr / ldr / eor /
 *      str`.  That is a 1.1p1 scheduling habit; ../2.0/sp2 issues the four in
 *      the image's order with the SAME C.  Measured on the note's body
 *      unchanged: 1.1p1 nine mismatched instructions, ../1.2/sp2 forty-seven,
 *      ../2.0/sp2 three.  This is the same front end the cluster neighbour
 *      src/matched/func_02062BAC.c is pinned to.
 *
 *   2. THE RANGE FOLD, which is the note's item 1 and was the whole remaining
 *      residue (5 concrete bytes, three instructions).  mwccarm folds a
 *      disjunction over two CONSECUTIVE integers into a range test:
 *      `mode == 3 || mode == 4` becomes `sub r0, r0, #3 / cmp r0, #1 / bhi`,
 *      where the image has the unfolded `cmp r0, #3 / cmpne r0, #4 / bne`.
 *      The fold is not a spelling of the disjunction -- swapping the operand
 *      order, `(mode ^ 3) == 0 || (mode ^ 4) == 0`, and both nestings of the
 *      equivalent ternary all give either the same fold or a larger function.
 *      What blocks it is forcing the disjunction to be materialised as a VALUE
 *      before it is branched on:
 *
 *          if (mode == 3 || mode == 4 ? 1 : 0) { ... }
 *
 *      The `? 1 : 0` makes the condition an ordinary int expression, so the
 *      front end evaluates the two equality tests and if-converts them into
 *      `cmp` / `cmpne`, and only then branches -- which is exactly the image.
 *      This is the counterpart of
 *      docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md:
 *      there the disjunction has to be ONE expression to tail-merge, here it
 *      has to be one VALUE to escape the range fold.  Note that the function's
 *      other two disjunctions, `mode == 2 || mode == 4`, need no such
 *      treatment and are written plainly: 2 and 4 are not consecutive, so
 *      there is nothing to fold and the front end emits `cmp` / `cmpne` of its
 *      own accord.  The tell is precise -- consecutive constants fold, others
 *      do not.
 *
 * The permuter confirms the residue was never allocation: `--explain` on the
 * ../2.0/sp2 baseline reports NO register substitution at all.  It is worth
 * recording what it did do, because it is the shape of a near miss rather than
 * a close: `--mode hill --budget 800 --jobs 8 --types` walked the 5-byte
 * baseline down to 2 concrete bytes (instruction score 225 -> 10) and then
 * exhausted 275 single mutations with no further improvement.  It could reach
 * the right instruction COUNT and ordering but never the `cmp`/`cmpne` pair
 * itself, because no value-preserving mutation in its set can undo a fold the
 * front end performs on constants.  A residue the permuter cannot move is in
 * the declarations or in the reading of the image; here it was in neither --
 * it was in the shape of one condition, and `? 1 : 0` is the whole edit.
 *
 * WHY THE TWO ARMS DUPLICATE.  0x02062C44..0x02062C8C and
 * 0x02062C90..0x02062CD4 are byte-identical bodies reached from the two sides
 * of the mode test, and they are written out twice in the source for exactly
 * the reason docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md
 * gives: factoring them behind a label moves the branch target and reallocates
 * every register.  `getMode` is `static inline` and is called twice for the
 * same reason -- the image re-reads +0x18 and +0x1c after the callback,
 * because the callback may have written them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062BF4.c \
 *       --func func_02062BF4 --addr 0x02062BF4 --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 276 = original 276, 2 of 2 sites resolved
 */
void func_02062BF4(struct Slider *s)
{
    u32 mode = getMode(s);
    if (mode == 3 || mode == 4 ? 1 : 0) {
        struct Sub *sub;
        u32 pos;
        s->field_08 ^= 1;
        sub = s->sub;
        pos = s->pos;
        if (pos <= (sub->ptr_0C + (sub->h2 << 3) - 8)) {
            if (s->field_20 == 1) {
                s->cb_28(s->field_24, s->field_10);
            }
            mode = getMode(s);
            if (mode == 2 || mode == 4) {
                func_02062F90((struct NNSG2dAnimController *)s);
            } else {
                s->field_0C = 0;
            }
        }
    } else {
        if (s->field_20 == 1) {
            s->cb_28(s->field_24, s->field_10);
        }
        mode = getMode(s);
        if (mode == 2 || mode == 4) {
            func_02062F90((struct NNSG2dAnimController *)s);
        } else {
            s->field_0C = 0;
        }
    }

    {
        struct Sub *sub = s->sub;
        u32 pos = s->pos;
        u32 bound = sub->ptr_0C + (sub->h0 << 3) - 8;
        if (pos > bound) {
            s->pos = bound;
            return;
        }
        if (pos < sub->ptr_0C) {
            s->pos = sub->ptr_0C;
        }
    }
}





int func_02062D08(void *p, u32 i)
{
    u8 *s = (u8 *)p;
    u8 *t = *(u8 * *)&((struct Obj07015 *)s)->f1C;
    u8 *e;

    if (i < ((struct Obj11525 *)t)->f0) {
        e = *(u8 * *)&((struct Obj11525 *)t)->fC + i * 8;
        *(u8 * *)&((struct Obj07015 *)s)->f0 = e;
        if (((struct Obj16406 *)e)->f4 != 0) {
            *(u8 * *)&((struct Obj07015 *)s)->f4 = e;
        }
        return 1;
    }
    return 0;
}





/*
 * *
 * Returns the cell-animation's current animation-sequence record: the sequence
 * pointer array member at +0x04 of the animation state, dereferenced once. The
 * value it yields is the 16-byte NANR sequence record the multi-cell node's
 * own sequence index selected.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062D40.c  *       --func func_02062D40 --addr 0x02062D40 --cc 1.1p1
 */
void *func_02062D40(struct CellAnim *anim)
{
    return *anim->sequence;
}



static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((s64)a * b + 0x800) >> 12);
}



static inline BOOL IsForward_(const Ctrl *p)
{
    return (BOOL)((p->speed > 0) ^ p->bReverse);
}



static inline BOOL IsReachEndEdge_(const Frame *cur, const Frame *arr, u16 n)
{
    return (BOOL)(cur >= arr + n);
}



static inline BOOL IsReachStartEdge_(const Frame *cur, const Frame *arr, u16 idx)
{
    return (BOOL)(cur <= arr + idx - 1);
}



static inline BOOL IsReachedEdge_(const Ctrl *p)
{
    const Frame *cur = p->pCurrent;
    if (IsForward_(p))
        return IsReachEndEdge_(cur, p->pAnimSequence->pFrameArray, p->pAnimSequence->numFrames);
    else
        return IsReachStartEdge_(cur, p->pAnimSequence->pFrameArray, p->pAnimSequence->loopStartFrameIdx);
}



static inline u16 GetCurrentFrameIdx_(const Ctrl *p)
{
    return (u16)(((u32)p->pCurrent - (u32)p->pAnimSequence->pFrameArray) >> 3);
}



static inline BOOL ShouldAdvance_(const Ctrl *p)
{
    if (p->bActive && p->currentTime >= (s32)(p->pCurrent->frames << 12))
        return 1;
    return 0;
}



static inline void CallbackFuncHandling_(const Functor *f, u16 idx)
{
    switch (f->type) {
    case 2:
        if (idx == f->frameIdx)
            f->pFunc(f->param, idx);
        break;
    case 3:
        f->pFunc(f->param, idx);
        break;
    }
}



/*
 * The cell-animation controller tick (NitroSystem g2d NNS_G2dTickAnimCtrl
 * shape): if active, advance currentTime by |FX_Mul(speed, frames)| (the
 * callee at 0x02091588 is abs), then while the controller is active and the
 * time has passed the current frame's length, step the frame pointer in the
 * play direction, hand the edge case to func_02062BF4, latch the last frame
 * with a non-zero length, and fire the +0x20 callback functor (type 2: on one
 * frame index, type 3: every frame).  Returns whether a frame changed.
 *
 * Struct layout agrees with src/matched/func_02062BF4.c (the edge handler),
 * func_02062D08.c and sub_02062F1C.c (the u16 frame index).
 *
 * Levers, each measured:
 *   - ../2.0/sp2: every per-inline 0/1 constant hoisted to its own callee-
 *     saved register (r8/r7, r6/r5, r4/fp) and the ten-register push.
 *     dsi/1.1p1 is 408 bytes and pushes six.
 *   - the loop test is `if (active && time >= len) return 1; return 0;`
 *     (value materialised with movge #1 / bge / mov #0).
 *   - the edge test binds only `cur = p->pCurrent` before the direction
 *     test; the sequence and frame array are read inside each arm (the
 *     compiler hoists them after the teq).  A local for the array too moves
 *     the sequence load ahead of the direction test (16 bytes out).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02062D4C.c \
 *       --func func_02062D4C --addr 0x02062D4C --arm --cc ../2.0/sp2
 *   EXACT, 436 bytes, 2 of 2 relocation sites resolved (sp2p2 also EXACT).
 */
BOOL func_02062D4C(Ctrl *p, s32 frames)
{
    BOOL bChanged = 0;

    if (p->bActive != 1)
        return 0;
    p->currentTime += func_02091588(FX_Mul(p->speed, frames));
    while (ShouldAdvance_(p)) {
        bChanged = 1;
        p->currentTime -= p->pCurrent->frames << 12;
        if (IsForward_(p))
            p->pCurrent++;
        else
            p->pCurrent--;
        if (IsReachedEdge_(p))
            func_02062BF4((struct Slider *)p);
        if (p->pCurrent->frames != 0)
            p->pActiveCurrent = p->pCurrent;
        if (p->callback.type != 0)
            CallbackFuncHandling_(&p->callback, GetCurrentFrameIdx_(p));
    }
    return bChanged;
}




int func_02062F00(void *s, u32 i)
{
    u32 r = func_02062D08(s, i);

    if (r != 0) {
        ((struct Obj07015 *)s)->f10 = 0;
    }
    return r;
}




/*
 * Index-of: how far the cursor at +0 of this record sits past the array
 * base its owner (+0x1c) keeps at +0xc, in units of eight bytes.  A leaf
 * with no prologue at all, which is why disasm.py never labelled it.
 *
 * The `lsl #13; lsr #16` pair is the folded form of "shift right by three,
 * then truncate to u16"
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md);
 * the shifts being logical is the evidence that the subtraction is done in
 * u32, not as a signed ptrdiff.
 *
 * This is the missing witness for src/pending/CLACT_GetActorAnimSeqCount.c, the only
 * other reference to this address in the image.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02062F1C.c \
 *       --func sub_02062F1C --addr 0x02062F1C --cc 1.1p1 --arm
 */
u16 sub_02062F1C(const struct Node *n)
{
    return (u16)((n->cursor - n->owner->base) >> 3);
}


int func_02062F38(int a0)
{
    func_02062F78((struct AnimState *)(a0 + 0x20));
    ((struct AnimObj *)a0)->f0 = 0;
    ((struct AnimObj *)a0)->f4 = 0;
    ((struct AnimObj *)a0)->f8 = 0;
    ((struct AnimObj *)a0)->fC = 1;
    ((struct AnimObj *)a0)->f10 = 0;
    ((struct AnimObj *)a0)->f14 = 0x1000;
    ((struct AnimObj *)a0)->f18 = 0;
    ((struct AnimObj *)a0)->f1C = 0;
    return 0x1000;
}


/*
 * Zeroes a 14-byte animation-playback sub-state: three u32 words and a
 * trailing halfword. Written as four stores rather than a memset.
 */
void func_02062F78(struct AnimState *state)
{
    state->unk00 = 0;
    state->unk04 = 0;
    state->unk08 = 0;
    state->unk0C = 0;
}
