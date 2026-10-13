/*
 * file:     unit_020643CC.c
 * unit:     yes
 * function: func_020643CC, func_02064648, func_0206469C, func_02064754, func_020648B4, func_020648E0, func_02064934, func_020649D4, func_02064AB4, func_02064B68
 * address:  0x020643CC
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
 *   _u32_div_f          0x0209C2B0  arm
 *   func_020627D8       0x020627D8  arm
 *   func_0206434C       0x0206434C  arm
 *   func_02064364       0x02064364  arm
 *   func_02063030       0x02063030  arm
 *   func_020640DC       0x020640DC  arm
 *   func_020629E8  0x020629E8  arm
 *   func_02062D40   0x02062D40  arm
 *   func_02062FF0   0x02062FF0  arm
 *   func_02064100   0x02064100  arm
 *   func_02064120   0x02064120  arm
 *   NNSi_G2dSrtcInitControl   0x02064140  arm
 *   func_0206428C  0x0206428C  arm
 *   func_02064178  0x02064178  arm
 *   func_02062F38  0x02062F38  arm
 *   func_02062D4C  0x02062D4C  arm
 *   func_02062F00  0x02062F00  arm
 *   sub_020643C4  0x020643C4  arm
 */
struct AnimBank;
struct AnimSequence;
struct CellAnim;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

typedef int            BOOL;

typedef s32            fx32;

typedef struct AnimFrameData { void *pContent; u16 frames; u16 pad; } AnimFrameData;

typedef struct AnimSequenceData {
    u16 numFrames; u16 loopStartFrameIdx; u32 animType; u32 playMode;
    AnimFrameData *pAnmFrameArray;
} AnimSequenceData;

typedef struct AnimCtrl { u8 pad00[0xC]; BOOL bActive; u8 pad10[0x2C]; } AnimCtrl;

typedef struct CellAnimation { AnimCtrl animCtrl; u8 pad3c[0x1C]; } CellAnimation; /* 0x58 */

typedef struct MCCellAnimation { CellAnimation cellAnim; BOOL bInited; } MCCellAnimation;

typedef struct SRTControl { u32 type; u32 srt[4]; } SRTControl;

typedef struct Node { void *pContent; u32 type; BOOL bVisible; SRTControl srtCtrl; u8 pad20[8]; } Node;

typedef struct HierData { u16 animSequenceIdx; s16 posX; s16 posY; u16 nodeAttr; } HierData;

typedef struct MultiCellData { u16 numNodes; u16 numCellAnim; HierData *pHierDataArray; } MultiCellData;

typedef struct MultiCellBank { u16 numMultiCell; } MultiCellBank;

typedef struct MCInstance {
    const MultiCellData *pCurrentMultiCell;
    const void *pAnimDataBank;
    u32 mcType;
    void *pCellAnimInstasnces;
} MCInstance;

typedef struct CountHdr { u8 pad00[4]; u16 count; } CountHdr;

typedef struct FrameHdr { u8 pad00[4]; u32 kind; } FrameHdr;

typedef struct NodeRec {
    u16 idx;            /* +0x00 */
    u16 rot;            /* +0x02 */
    union {
        u32 xy;         /* +0x04, read as one word */
        struct { s16 x; s16 y; };
    };
    u32 f08;
    s16 fC;
    s16 fE;
} NodeRec;

typedef struct MultiCellAnim {
    CountHdr *f0;           /* +0x00 */
    CountHdr *f4;           /* +0x04 */
    u8 pad08[0xC];
    void *f14;              /* +0x14 */
    u8 pad18[4];
    FrameHdr *f1c;          /* +0x1C */
    u8 pad20[0x10];
    u16 totalFrames;        /* +0x30 */
    u8 pad32[2];
    MCInstance mc;          /* +0x34 */
    MultiCellBank *bank;    /* +0x44 */
    SRTControl srt;         /* +0x48 */
} MultiCellAnim;            /* 0x5C */

extern struct AnimSequence *func_020627D8(struct AnimBank *bank, u32 idx);
extern void func_0206434C(CellAnimation *p, const AnimSequenceData *seq);
extern s32 func_02063030(struct CellAnim *anim);
extern void func_02064364(struct CellAnim *anim, s32 frames);
extern void func_020640DC(SRTControl *s, s16 x, s16 y);
extern void func_02064120(SRTControl *s, u32 sx, u32 sy);
extern void func_02064100(SRTControl *s, u16 val);
extern void NNSi_G2dSrtcInitControl(SRTControl *s, u32 a);
extern MultiCellData *func_020629E8(MultiCellBank *bank, u32 idx);
extern void func_02062FF0(struct CellAnim *anim, void *bank);
extern NodeRec *func_02062D40(struct CellAnim *anim);
extern int func_02062D4C(struct CellAnim *anim, int a1);
extern int func_02062F00(struct CellAnim *anim, u32 i);
extern int func_02062F38(struct CellAnim *anim);
extern void func_0206428C(CellAnimation *self, struct AnimSequence *seq, void *c);
extern void func_02064178(Node *n, u32 a);
extern void sub_020643C4(struct CellAnim *anim, u32 value);
void func_020643CC(MCInstance *pMCInst, const MultiCellData *pMcData, u16 mcTotalFrame);
u16 func_02064648(MultiCellBank *bank);
void func_0206469C(MultiCellAnim *o, void *bank);
void func_02064754(MultiCellAnim *o, void *buf, void *set, int a3, MultiCellBank *bank, int kind);
int func_020648B4(u32 a, u32 b);
u16 func_020648E0(MultiCellBank *bank);
void func_02064934(MCInstance *p, int arg);
void func_020649D4(MultiCellAnim *self, int a1);
void func_02064AB4(MultiCellAnim *self, unsigned int i);
void sub_02064B68(MultiCellAnim *o, void *arg);



static inline u32 CalcTotal(const AnimSequenceData *pAnimSeq)
{
    u32 i;
    u32 total = 0;

    for (i = 0; i < pAnimSeq->numFrames; i++) {
        total += pAnimSeq->pAnmFrameArray[i].frames;
    }
    return total;
}



static inline u32 GetPlayMode(const HierData *pNode)
{
    const u32 mode = (u32)((pNode->nodeAttr >> 0) & 0xF);
    return mode;
}



static inline u16 GetCellAnimIdx(const HierData *pNodeData)
{
    return (u16)((0xFF00 & pNodeData->nodeAttr) >> 8);
}



static inline void SetNodeDataToCellAnim_(CellAnimation *pCellAnim, const HierData *pNodeData,
                                          const void *pAnimBank, u16 mcTotalFrame)
{
    const AnimSequenceData *pAnimSeq = 0;

    pAnimSeq = (const AnimSequenceData *)func_020627D8((struct AnimBank *)pAnimBank, pNodeData->animSequenceIdx);

    func_0206434C(pCellAnim, pAnimSeq);
    pCellAnim->animCtrl.bActive = 1;

    if (GetPlayMode(pNodeData) == 1) {
        const u32 animSeqLength = CalcTotal(pAnimSeq);

        if (func_02063030((struct CellAnim *)(&pCellAnim->animCtrl))) {
            const u32 frameToMove = (mcTotalFrame % animSeqLength);
            func_02064364((struct CellAnim *)pCellAnim, (fx32)(frameToMove << 12));
        } else {
            const u32 frameToMove = (mcTotalFrame >= animSeqLength) ? animSeqLength : mcTotalFrame;
            func_02064364((struct CellAnim *)pCellAnim, (fx32)(frameToMove << 12));
        }
    }
}



/*
 * NitroSystem g2d SetMCDataToMCInstanceImpl_ (g2d_MultiCellAnimation.c):
 * bind a multi-cell data record to an instance and (re)start every node's
 * cell animation, seeking CONTINUE-mode nodes to the multi-cell's total
 * frame (modulo the sequence length when the animation loops, clamped
 * otherwise).  mcType 1 = cell animations shared through a 0x5c-byte
 * { NNSG2dCellAnimation, bInited } array; otherwise a 0x28-byte node array
 * whose pContent is the cell animation.  Callees: func_020627D8
 * GetAnimSequenceByIdx, func_0206434C SetCellAnimationSequence,
 * func_02063030 IsAnimCtrlLoopAnim, func_02064364 TickCellAnimation,
 * func_020640DC SrtcSetTrans.
 *
 * Closed in wave 12 by writing the library's own shape: ONE u16 counter at
 * function scope shared by all three loops, the per-node work as the
 * SetNodeDataToCellAnim_ inline, the frame sum as the
 * CalcAnimSequenceTotalVideoFrames inline, and bInited re-indexed through
 * the array (not a held pointer).  The wave-11 hand-scoped source stuck at
 * 7 bytes out (cells/counter swap) is in docs/notes/pkt_020643CC.c.txt.
 * Front end: ../2.0/sp2 and ../2.0/sp2p2 give identical bytes; 1.1p1 is
 * 620 bytes.
 */
void func_020643CC(MCInstance *pMCInst, const MultiCellData *pMcData, u16 mcTotalFrame)
{
    u16 i;

    pMCInst->pCurrentMultiCell = pMcData;

    if (pMCInst->mcType == 1) {
        MCCellAnimation *pCellAnimArray = (MCCellAnimation *)pMCInst->pCellAnimInstasnces;

        for (i = 0; i < pMcData->numCellAnim; i++) {
            pCellAnimArray[i].bInited = 0;
        }

        for (i = 0; i < pMcData->numNodes; i++) {
            const HierData *pNodeData = &pMcData->pHierDataArray[i];
            const u16 cellAnimIdx = GetCellAnimIdx(pNodeData);

            if (!pCellAnimArray[cellAnimIdx].bInited) {
                CellAnimation *pCellAnim = &pCellAnimArray[cellAnimIdx].cellAnim;

                SetNodeDataToCellAnim_(pCellAnim, pNodeData, pMCInst->pAnimDataBank, mcTotalFrame);

                pCellAnimArray[cellAnimIdx].bInited = 1;
            }
        }
    } else {
        Node *pNodeArray = (Node *)(pMCInst->pCellAnimInstasnces);

        for (i = 0; i < pMcData->numNodes; i++) {
            const HierData *pNodeData = &pMcData->pHierDataArray[i];
            CellAnimation *pCellAnim = (CellAnimation *)pNodeArray[i].pContent;

            SetNodeDataToCellAnim_(pCellAnim, pNodeData, pMCInst->pAnimDataBank, mcTotalFrame);

            pNodeArray[i].bVisible = 1;
            func_020640DC(&pNodeArray[i].srtCtrl, pNodeData->posX, pNodeData->posY);
        }
    }
}




/*
 * Returns the largest per-multi-cell "cell animation slot count" (the u16 at
 * +0x02 of the 8-byte multi-cell descriptor) across a whole multi-cell bank.
 * The caller sizes its array of 0x5C-byte cell-animation states with this, and
 * each node's byte at +0x07 is the index into that array -- which is why that
 * byte runs 0, 1, 2, ... across a multi-cell's nodes rather than naming a cell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064648.c  *       --func func_02064648 --addr 0x02064648 --cc 1.1p1
 */
u16 func_02064648(MultiCellBank *bank)
{
    u16 max = 0;
    u16 i = 0;

    for (i = 0; i < bank->numMultiCell; i++) {
        u16 n = func_020629E8(bank, i)->numCellAnim;

        if (n > max) {
            max = n;
        }
    }

    return max;
}





/*
 * Rebuilds one multi-cell node's SRT block from its current NANR frame record.
 * The node record comes through func_02062D40 and its descriptor through
 * func_020629E8; the frame's kind byte (a word masked with 0xff, not a ldrb)
 * selects the arm: 0 does nothing, 2 is translation-only, anything else is the
 * full SRT form (scale, rotation, translation).  The walk finishes by handing
 * the descriptor and the node's own u16 counter at +0x30 to func_020643CC.
 *
 * PIN ../2.0/sp2: the "kept branches" tell in its CROSS-JUMP form, the same
 * one src/matched/func_02064AB4.c and src/matched/func_0206419C.c carry.  The
 * image writes the kind==2 arm's `add r0, r4, #0x48` / `bl func_020640DC` tail
 * out in its own arm although the other arm's LAST call is a byte-identical
 * pair; 1.1p1 -O4,p cross-jumps the two and lands at 176 bytes against the
 * original's 184, 73 concrete bytes out (docs/notes/pkt_0206469C.c.txt, which
 * measured the goto/if-else/switch spellings and found them all folding).
 * Under the pin this SAME C is 184 bytes, 0 mismatches, all 9 sites by label.
 */
void func_0206469C(MultiCellAnim *o, void *bank)
{
    NodeRec *p;
    u32 k;
    u32 r;

    func_02062FF0((struct CellAnim *)o, bank);
    o->totalFrames = 0;

    if (o->f4->count == 0) {
        return;
    }

    p = func_02062D40((struct CellAnim *)o);
    r = (u32)func_020629E8(o->bank, p->idx);
    k = o->f1c->kind & 0xff;

    NNSi_G2dSrtcInitControl(&o->srt, 1);

    if (k == 0) {
        goto done;
    }

    if (k == 2) {
        func_020640DC(&o->srt, p->x, p->y);
    } else {
        func_02064120(&o->srt, p->xy, p->f08);
        func_02064100(&o->srt, p->rot);
        func_020640DC(&o->srt, p->fC, p->fE);
    }

done:
    func_020643CC(&o->mc, (const MultiCellData *)r, o->totalFrames);
}




/*
 * Build a multi-cell animation's cell array (docs/families/cluster_020640DC.h,
 * section 3): kind == 1 is the flat 0x5c-stride array sized by
 * func_02064648(bank), anything else the two-level shape of
 * func_020648E0(bank) 0x28-byte group headers followed by 0x58-stride cells.
 *
 * Three things closed it after docs/notes/pkt_02064754.c.txt stalled at 70
 * out:
 *   - DATA FLOW.  The NMCR bank handed to both sizing calls is the FIFTH
 *     argument (loaded from [sp,#0x28] into r0 before the kind test and
 *     respilled to its own slot), and the second argument is the cell
 *     buffer stored at +0x40 and used as the group-header base.  The note's
 *     body passed the second argument to func_020648E0; with the flow
 *     corrected no `volatile` is needed for the respill.
 *   - Arm 2 runs the four-call tail TWICE (it falls into the shared copy),
 *     so the tail is written in the arm and again after the if.
 *   - The count and index are declared PER ARM (u16 n, i inside each
 *     block); function-scope n / i are 18 out (a register swap in both
 *     loops), a separate j for arm 2 is 4 bytes short.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064754.c \
 *       --func func_02064754 --addr 0x02064754 --arm --cc ../2.0/sp2
 */
void func_02064754(MultiCellAnim *o, void *buf, void *set, int a3, MultiCellBank *bank, int kind)
{
  if (kind == 1)
  {
    MCCellAnimation *cells;
    u16 n;
    u16 i;
    o->mc.mcType = 1;
    o->mc.pAnimDataBank = set;
    o->mc.pCellAnimInstasnces = buf;
    n = func_02064648(bank);
    cells = (MCCellAnimation *)o->mc.pCellAnimInstasnces;
    for (i = 0; i < n; i++)
    {
      MCCellAnimation *cell = &cells[i];
      func_0206428C(&cell->cellAnim, func_020627D8(set, 0), (void *)a3);
      cell->bInited = 1;
    }
  }
  else
  {
    char *base;
    u16 n;
    u16 i;
    n = func_020648E0(bank);
    base = (char *)buf + n * 0x28;
    o->mc.mcType = 0;
    o->mc.pCurrentMultiCell = 0;
    o->mc.pAnimDataBank = set;
    o->mc.pCellAnimInstasnces = buf;
    for (i = 0; i < n; i++)
    {
      Node *hdr = (Node *)buf + i;
      CellAnimation *cell;
      func_02064178(hdr, 1);
      cell = (CellAnimation *)(base + i * 0x58);
      hdr->pContent = cell;
      func_0206428C(cell, func_020627D8(set, 0), (void *)a3);
    }
    func_02062F38((struct CellAnim *)o);
    o->bank = bank;
    NNSi_G2dSrtcInitControl(&o->srt, 1);
    o->totalFrames = 0;
  }
  func_02062F38((struct CellAnim *)o);
  o->bank = bank;
  NNSi_G2dSrtcInitControl(&o->srt, 1);
  o->totalFrames = 0;
}




int func_020648B4(u32 a, u32 b)
{
    u32 v;

    if (b == 1) {
        v = func_02064648((MultiCellBank *)a) * 0x5c;
    } else {
        v = func_020648E0((MultiCellBank *)a) << 7;
    }
    return v;
}





/*
 * Returns the largest node count among the multi-cell descriptors of the bank,
 * 0 for an empty bank.  The counter is a u16 (the `lsl #16` / `lsr #16` pair
 * per iteration) and the count is re-read from the bank every iteration, which
 * is why the guard at the top is a rotated `cmp count, #0`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020648E0.c \
 *       --func func_020648E0 --addr 0x020648E0 --arm --cc 1.1p1
 */
u16 func_020648E0(MultiCellBank *bank)
{
    u16 max = 0;
    u16 i;

    for (i = 0; i < bank->numMultiCell; i++) {
        u16 n = func_020629E8(bank, i)->numNodes;

        if (n > max) {
            max = n;
        }
    }

    return max;
}



/*
 * Step every node of the multi-cell walk block (struct Root of
 * docs/families/cluster_020640DC.h) by `arg` ticks: kind == 1 walks the
 * flat 0x5c-stride array for data->numCellAnims, anything else the
 * 0x28-stride group headers' first word for data->numNodes.
 *
 * The lever that closed the note's last 4 bytes (two head loads swapped,
 * docs/notes/func_02064934.c.txt): declare the index and the array base
 * INSIDE EACH ARM.  A function-scope `u16 i = 0; char *base = p->f0c;`
 * issues the base load before the data-pointer load; per-arm locals let
 * the front end hoist the arms' common data-pointer load first, which is
 * the image.  No dead local needed.  Identical bytes under dsi/1.1p1 and
 * ../2.0/sp2 (not a pin).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064934.c \
 *       --func func_02064934 --addr 0x02064934 --arm --cc 1.1p1
 */
void func_02064934(MCInstance *p, int arg)
{
    if (p->mcType == 1) {
        u16 i;
        MCCellAnimation *cells = (MCCellAnimation *)p->pCellAnimInstasnces;
        for (i = 0; i < p->pCurrentMultiCell->numCellAnim; i++) func_02064364((struct CellAnim *)&cells[i], arg);
    } else {
        u16 i;
        Node *nodes = (Node *)p->pCellAnimInstasnces;
        for (i = 0; i < p->pCurrentMultiCell->numNodes; i++) func_02064364((struct CellAnim *)nodes[i].pContent, arg);
    }
}




/*
 * The tick-driven form of func_02064AB4: steps the multi-cell animation by a
 * fx32 tick through func_02062D4C and, when that reports no advance, hands the
 * whole walk block at +0x34 to func_02064934 instead.  From the header test
 * down the body is func_02064AB4's verbatim.
 *
 * PIN ../2.0/sp2, inherited from the sibling src/matched/func_02064AB4.c: the
 * same case-2 cross-jump.  1.1p1 -O4,p shares case 2's
 * `add r0, r4, #0x48` / `bl func_020640DC` tail with the default arm's
 * identical pair at 0x02064A88/0x02064A8C and lands at 220 bytes against the
 * original's 224 (docs/notes/pkt_02064934.func_020649D4.c.txt).
 *
 * THREE C LEVERS, all needed and all found in this pass:
 *  1. func_02062D4C IS ARITY TWO, not three.  The note's body declared a third
 *     parameter and passed the latched halfword `t`; that costs a `mov r2, r5`
 *     at 0x020649E8 and the compile is 228 bytes.  The image sets only r0/r1.
 *  2. THE MISS ARM MUST BE A `goto` TO THE FUNCTION'S TAIL.  Written inline as
 *     `{ func_02064934(...); return; }` the compiler emits it in place under a
 *     `bne` where the image emits `beq #0x2064aa4` over the whole body to an
 *     arm placed AFTER the main epilogue.  Size-exact either way; the inline
 *     form is 140 concrete bytes out because everything after +0x1C is shifted
 *     by one instruction.
 *  3. `int kind;` MUST BE DECLARED BEFORE `int r7;`.  Declaration order is
 *     stack/colour order here: the reverse puts the masked kind in r7 and the
 *     descriptor in r6, where the image has kind in r6 and the descriptor in
 *     r7 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *
 * The +0x2C PC24 to func_02064934 resolves by `sole-ref/code`: 0x02064934 is a
 * traced function start and this `bl` is its only branch image-wide, which is
 * exactly the single-caller shape `label` cannot reach.
 */
void func_020649D4(MultiCellAnim *self, int a1)
{
    unsigned short t = self->f0->count;
    NodeRec *p;
    int kind;
    int r7;

    if (func_02062D4C((struct CellAnim *)self, a1) == 0) {
        goto miss;
    }
    self->totalFrames += t;
    if (self->f4->count == 0)
        return;
    p = func_02062D40((struct CellAnim *)self);
    r7 = (int)func_020629E8(self->bank, p->idx);
    kind = self->f1c->kind & 0xff;
    NNSi_G2dSrtcInitControl(&self->srt, 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        func_020640DC(&self->srt, p->x, p->y);
        break;
    default:
        func_02064120(&self->srt, p->xy, p->f08);
        func_02064100(&self->srt, p->rot);
        func_020640DC(&self->srt, p->fC, p->fE);
        break;
    }
    func_020643CC(&self->mc, (const MultiCellData *)r7, self->totalFrames);
    return;
miss:
    func_02064934(&self->mc, a1);
}




/*
 * PIN ../2.0/sp2: the "kept branches" tell.  The image writes the case-2
 * call tail out in its own arm -- `add r0, r4, #0x48` (0x02064B20) /
 * `bl func_020640DC` (0x02064B24) / `b 0x02064B54` (0x02064B28) -- although
 * the default arm ends in a byte-identical `add r0, r4, #0x48` /
 * `bl func_020640DC` pair at 0x02064B4C/0x02064B50.  1.1p1 -O4,p cross-jumps
 * the two, branching case 2 into the default arm's pair and giving 172 bytes
 * against the original's 180, 64 concrete bytes out.  Two independent lanes
 * measured a dozen spellings (switch arm order, if-chain, goto tail, named
 * s16 locals, nested switch) and all cross-jump.  Under the pin the same C
 * is 180 bytes, 0 mismatches.
 *
 * Same body as func_020649D4 from the header test down, but with a guard
 * that returns early instead of the missed-lookup arm, and no call to
 * func_02064934.  The early-out is ONE expression: the two tests are
 * predicated onto a single `popeq` (`ldrne`/`cmpne`/`popeq`), which is what
 * makes it a `||` inside a single `if` rather than two `if`s (two separate
 * guards would each need their own `pop`).
 */
void func_02064AB4(MultiCellAnim *self, unsigned int i)
{
    NodeRec *p;
    int kind;
    int item;

    if (func_02062F00((struct CellAnim *)self, i) == 0 || self->f4->count == 0)
        return;
    p = func_02062D40((struct CellAnim *)self);
    item = (int)func_020629E8(self->bank, p->idx);
    kind = self->f1c->kind & 0xff;
    NNSi_G2dSrtcInitControl(&self->srt, 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        func_020640DC(&self->srt, p->x, p->y);
        break;
    default:
        func_02064120(&self->srt, p->xy, p->f08);
        func_02064100(&self->srt, p->rot);
        func_020640DC(&self->srt, p->fC, p->fE);
        break;
    }
    func_020643CC(&self->mc, (const MultiCellData *)item, self->totalFrames);
}



/*
 * PART 1 bank walker of docs/families/cluster_02064B68.h: publish `arg` at
 * +0x14, then step every record of the walk block at +0x34 (the same
 * struct Root func_02064934 takes) through sub_020643C4 -- kind 1 the flat
 * 0x5c-stride array for numCellAnims, else the 0x28-stride headers' first
 * word for numNodes.
 *
 * Two levers closed docs/notes/sub_02064B68.c.txt's last 11 bytes:
 *   - the index and base are PER-ARM locals (as in func_02064934);
 *   - the +0x14 store is written IN EACH ARM.  The front end hoists the
 *     common store above the branch but schedules it below the `cmp` and
 *     the index zero, which is the image; a single store before the `if`
 *     issues it above the `cmp` (11 out), and with it the volatile hdr
 *     the note needed is no longer necessary (the per-arm store is what
 *     keeps each arm's +0x34 load in its arm).
 * 1.1p1 gives 168 bytes / 24 out on the same C: pinned ../2.0/sp2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02064B68.c \
 *       --func sub_02064B68 --addr 0x02064B68 --arm --cc ../2.0/sp2
 */
void sub_02064B68(MultiCellAnim *o, void *arg)
{
    if (o->mc.mcType == 1) {
        u16 i;
        MCCellAnimation *cells = (MCCellAnimation *)o->mc.pCellAnimInstasnces;
        o->f14 = arg;
        for (i = 0; i < o->mc.pCurrentMultiCell->numCellAnim; i++) sub_020643C4((struct CellAnim *)&cells[i], (u32)arg);
    } else {
        u16 i;
        Node *nodes = (Node *)o->mc.pCellAnimInstasnces;
        o->f14 = arg;
        for (i = 0; i < o->mc.pCurrentMultiCell->numNodes; i++) sub_020643C4((struct CellAnim *)nodes[i].pContent, (u32)arg);
    }
}
