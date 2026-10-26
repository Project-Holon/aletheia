/*
 * file:     nns_g2d_load.c
 * unit:     yes
 * function: NNS_G2dGetUnpackedScreenData, NNS_G2dFindBinaryBlock, NNSi_G2dFixupOffsets, NNSi_G2dCellAnimationEdgeHandler, NNSi_G2dSetCellAnimationFrame, NNSi_G2dGetCellAnimationCurrentSequence, NNS_G2dTickAnimCtrl, NNSi_G2dSetCellAnimationCurrentFrame, NNSi_G2dGetCellAnimFrameIdx, NNS_G2dInitAnimCtrl, NNSi_G2dResetCellAnimationState
 * address:  0x02062B30
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * The 'NRCS' (NSCR screen data) accessor of docs/families/cluster_02062688.h,
 * NitroSystem NNS_G2dGetUnpackedScreenData shape: find the block, hand back
 * its body (block + 8) through *out and return 1, else *out = 0 and 0.
 * Closed wave 12 (was src/pending/NNS_G2dGetUnpackedScreenData.c, DIFF 48/52 under every
 * front end on the NEGATIVE spelling).  The fix is the POSITIVE spelling
 * `if (b) { ...; return 1; } else { ...; return 0; }` under ../2.0/sp2 (also
 * ../2.0/base and sp1): 2.0 predicates only the zero arm (`popeq`) and keeps
 * the fall-through, exactly the image.  dsi/1.1p1 predicates both arms under
 * every spelling measured.
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_G2dGetUnpackedScreenData.c \
 *       --func NNS_G2dGetUnpackedScreenData --addr 0x02062B30 --arm --cc ../2.0/sp2
 *   EXACT, 52 bytes, 1 of 1 relocation site resolved.
 * *
 * NNS G2D binary-block lookup: walks the block chain of a loaded NITRO file
 * starting at the file header's headerSize (u16 at +0x0C) for numBlocks (u16
 * at +0x0E) blocks, returning the first whose 4-character signature matches,
 * else NULL. Each block header is {u32 signature; u32 size}, and size is the
 * whole block, so the walk is a plain byte advance. Every NCGR/NCLR/NCER/NANR
 * /NMCR getter in this module is this call plus a per-format offset fixup.
 *   python tools/match.py one --src src/matched/NNS_G2dFindBinaryBlock.c  *       --func NNS_G2dFindBinaryBlock --addr 0x02062B64 --cc 1.1p1
 *
 * symbols:
 *   NNS_G2dResetCellAnimation  0x02062F90  arm
 *   abs  0x02091588  arm
 */
#include "../types.h"

typedef struct {
    u32 sig;
    u32 size;
} Blk;

struct NNSG2dBinaryBlockHeader {
    u32 signature;
    u32 size;
};

struct NNSG2dBinaryFileHeader {
    u32 signature;
    u16 byteOrder;
    u16 version;
    u32 fileSize;
    u16 headerSize;
    u16 numBlocks;
};

struct Tbl {
    u16   count;                /* 0x00  number of offsets, read with ldrh   */
    u16   pad02;
    u8  **offsets;              /* 0x04  itself an offset until fixed up     */
};

#include "nns_g2d_anim_types.h"


struct NodeRec;
#include "nns_g2d_cell_animation.h"
#include "msl_crt.h"
BOOL NNS_G2dGetUnpackedScreenData(void *file, void **out);
void *NNS_G2dFindBinaryBlock(struct NNSG2dBinaryFileHeader *pHeader, u32 signature);
void NNSi_G2dFixupOffsets(struct Tbl *t);
void NNSi_G2dCellAnimationEdgeHandler(AnimCtrl *s);
int NNSi_G2dSetCellAnimationFrame(void *p, u32 i);
struct NodeRec *NNSi_G2dGetCellAnimationCurrentSequence(AnimCtrl *anim);
BOOL NNS_G2dTickAnimCtrl(AnimCtrl *p, fx32 frames);
int NNSi_G2dSetCellAnimationCurrentFrame(void *s, u32 i);
u16 NNSi_G2dGetCellAnimFrameIdx(const AnimCtrl *n);
int NNS_G2dInitAnimCtrl(AnimCtrl *pAnimCtrl);
void NNSi_G2dResetCellAnimationState(AnimCallBack *callBack);

BOOL NNS_G2dGetUnpackedScreenData(void *file, void **out)
{
    Blk *b = 0;

    b = NNS_G2dFindBinaryBlock(file, 0x5343524E);
    if (b) {
        *out = (void *)(b + 1);
        return 1;
    } else {
        *out = 0;
        return 0;
    }
}

void *NNS_G2dFindBinaryBlock(struct NNSG2dBinaryFileHeader *pHeader, u32 signature)
{
    struct NNSG2dBinaryBlockHeader *block =
        (struct NNSG2dBinaryBlockHeader *)((u8 *)pHeader + pHeader->headerSize);
    u16 numBlocks = pHeader->numBlocks;
    u16 i;

    for (i = 0; i < numBlocks; i++) {
        if (block->signature == signature) {
            return block;
        }
        block = (struct NNSG2dBinaryBlockHeader *)((u8 *)block + block->size);
    }

    return 0;
}

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
 *   python tools/match.py one --src src/matched/NNSi_G2dFixupOffsets.c \
 *       --func NNSi_G2dFixupOffsets --addr 0x02062BAC --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 72 = original 72, 0 relocation sites
 */
void NNSi_G2dFixupOffsets(struct Tbl *t)
{
    u16 i;

    t->offsets = (u8 **)((u8 *)t->offsets + (uptr)t);
    i = 0;
    while (t->count > i) {
        t->offsets[i] = (u8 *)t + (uptr)t->offsets[i];
        i = i + 1;
    }
}

static inline u32 getMode(AnimCtrl *s) {
    u32 m = s->overriddenPlayMode;
    if (m == 0) {
        m = s->pAnimSequence->playMode;
    }
    return m;
}

/*
 * One step of the NNS G2D cell/animation player: advance the playback cursor,
 * fire the user callback if one is armed, hand off to NNS_G2dResetCellAnimation when the
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
 *      src/matched/NNSi_G2dFixupOffsets.c is pinned to.
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
 *   python tools/match.py one --src src/matched/NNSi_G2dCellAnimationEdgeHandler.c \
 *       --func NNSi_G2dCellAnimationEdgeHandler --addr 0x02062BF4 --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 276 = original 276, 2 of 2 sites resolved
 */
void NNSi_G2dCellAnimationEdgeHandler(AnimCtrl *s)
{
    u32 mode = getMode(s);
    if (mode == 3 || mode == 4 ? 1 : 0) {
        const AnimSequenceData *seq;
        u32 pos;
        s->bReverse ^= 1;
        seq = s->pAnimSequence;
        pos = (uptr)s->pCurrent;
        if (pos <= ((uptr)seq->pAnmFrameArray + (seq->loopStartFrameIdx << 3) - 8)) {
            if (s->callBack.type == 1) {
                s->callBack.pFunc(s->callBack.param, s->currentTime);
            }
            mode = getMode(s);
            if (mode == 2 || mode == 4) {
                NNS_G2dResetCellAnimation((AnimCtrl *)s);
            } else {
                s->bActive = 0;
            }
        }
    } else {
        if (s->callBack.type == 1) {
            s->callBack.pFunc(s->callBack.param, s->currentTime);
        }
        mode = getMode(s);
        if (mode == 2 || mode == 4) {
            NNS_G2dResetCellAnimation((AnimCtrl *)s);
        } else {
            s->bActive = 0;
        }
    }

    {
        const AnimSequenceData *seq = s->pAnimSequence;
        uptr pos = (uptr)s->pCurrent;
        uptr bound = (uptr)seq->pAnmFrameArray + (seq->numFrames << 3) - 8;
        if (pos > bound) {
            s->pCurrent = (AnimFrameData *)bound;
            return;
        }
        if (pos < (uptr)seq->pAnmFrameArray) {
            s->pCurrent = seq->pAnmFrameArray;
        }
    }
}

int NNSi_G2dSetCellAnimationFrame(void *p, u32 i)
{
    AnimCtrl *s = (AnimCtrl *)p;
    const AnimSequenceData *seq = s->pAnimSequence;
    AnimFrameData *e;

    if (i < seq->numFrames) {
        e = seq->pAnmFrameArray + i;
        s->pCurrent = e;
        if (e->frames != 0) {
            s->pActiveCurrent = e;
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
 *   python tools/match.py one --src src/matched/NNSi_G2dGetCellAnimationCurrentSequence.c  *       --func NNSi_G2dGetCellAnimationCurrentSequence --addr 0x02062D40 --cc 1.1p1
 */
struct NodeRec *NNSi_G2dGetCellAnimationCurrentSequence(AnimCtrl *anim)
{
    return (struct NodeRec *)anim->pActiveCurrent->pContent;
}

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline BOOL IsForward_(const AnimCtrl *p)
{
    return (BOOL)((p->speed > 0) ^ p->bReverse);
}

static inline BOOL IsReachEndEdge_(const AnimFrameData *cur, const AnimFrameData *arr, u16 n)
{
    return (BOOL)(cur >= arr + n);
}

static inline BOOL IsReachStartEdge_(const AnimFrameData *cur, const AnimFrameData *arr, u16 idx)
{
    return (BOOL)(cur <= arr + idx - 1);
}

static inline BOOL IsReachedEdge_(const AnimCtrl *p)
{
    const AnimFrameData *cur = p->pCurrent;
    if (IsForward_(p))
        return IsReachEndEdge_(cur, p->pAnimSequence->pAnmFrameArray, p->pAnimSequence->numFrames);
    else
        return IsReachStartEdge_(cur, p->pAnimSequence->pAnmFrameArray, p->pAnimSequence->loopStartFrameIdx);
}

static inline u16 GetCurrentFrameIdx_(const AnimCtrl *p)
{
    return (u16)(((uptr)p->pCurrent - (uptr)p->pAnimSequence->pAnmFrameArray) >> 3);
}

static inline BOOL ShouldAdvance_(const AnimCtrl *p)
{
    if (p->bActive && p->currentTime >= (s32)(p->pCurrent->frames << 12))
        return 1;
    return 0;
}

static inline void CallbackFuncHandling_(const AnimCallBack *f, u16 idx)
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
 * play direction, hand the edge case to NNSi_G2dCellAnimationEdgeHandler, latch the last frame
 * with a non-zero length, and fire the +0x20 callback functor (type 2: on one
 * frame index, type 3: every frame).  Returns whether a frame changed.
 *
 * Struct layout agrees with src/matched/NNSi_G2dCellAnimationEdgeHandler.c (the edge handler),
 * NNSi_G2dSetCellAnimationFrame.c and NNSi_G2dGetCellAnimFrameIdx.c (the u16 frame index).
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
 *   python3 tools/match.py one --src src/matched/NNS_G2dTickAnimCtrl.c \
 *       --func NNS_G2dTickAnimCtrl --addr 0x02062D4C --arm --cc ../2.0/sp2
 *   EXACT, 436 bytes, 2 of 2 relocation sites resolved (sp2p2 also EXACT).
 */
BOOL NNS_G2dTickAnimCtrl(AnimCtrl *p, fx32 frames)
{
    BOOL bChanged = 0;

    if (p->bActive != 1)
        return 0;
    p->currentTime += abs(FX_Mul(p->speed, frames));
    while (ShouldAdvance_(p)) {
        bChanged = 1;
        p->currentTime -= p->pCurrent->frames << 12;
        if (IsForward_(p))
            p->pCurrent++;
        else
            p->pCurrent--;
        if (IsReachedEdge_(p))
            NNSi_G2dCellAnimationEdgeHandler(p);
        if (p->pCurrent->frames != 0)
            p->pActiveCurrent = p->pCurrent;
        if (p->callBack.type != 0)
            CallbackFuncHandling_(&p->callBack, GetCurrentFrameIdx_(p));
    }
    return bChanged;
}

int NNSi_G2dSetCellAnimationCurrentFrame(void *s, u32 i)
{
    u32 r = NNSi_G2dSetCellAnimationFrame(s, i);

    if (r != 0) {
        ((AnimCtrl *)s)->currentTime = 0;
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
 *   python tools/match.py one --src src/matched/NNSi_G2dGetCellAnimFrameIdx.c \
 *       --func NNSi_G2dGetCellAnimFrameIdx --addr 0x02062F1C --cc 1.1p1 --arm
 */
u16 NNSi_G2dGetCellAnimFrameIdx(const AnimCtrl *n)
{
    return (u16)(((uptr)n->pCurrent - (uptr)n->pAnimSequence->pAnmFrameArray) >> 3);
}

int NNS_G2dInitAnimCtrl(AnimCtrl *pAnimCtrl)
{
    AnimCtrl *c = (AnimCtrl *)pAnimCtrl;
    NNSi_G2dResetCellAnimationState(&c->callBack);
    c->pCurrent = 0;
    c->pActiveCurrent = 0;
    c->bReverse = 0;
    c->bActive = 1;
    c->currentTime = 0;
    c->speed = 0x1000;
    c->overriddenPlayMode = 0;
    c->pAnimSequence = 0;
    return 0x1000;
}

/*
 * Zeroes a 14-byte animation-playback sub-state: three u32 words and a
 * trailing halfword. Written as four stores rather than a memset.
 */
void NNSi_G2dResetCellAnimationState(AnimCallBack *callBack)
{
    callBack->type = 0;
    callBack->param = 0;
    callBack->pFunc = 0;
    callBack->frameIdx = 0;
}
