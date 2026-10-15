/*
 * file:     nns_g2d_anim_bank.c
 * unit:     yes
 * function: NNS_G2dGetUnpackedAnimBank, NNS_G2dGetUnpackedAnimBankEx, NNSi_G2dGetUnpackedAnimBank, NNSi_G2dUnpackAnimBank, NNS_G2dGetAnimSequenceByIdx, NNSi_G2dGetCellDataBankOamBase, NNSi_G2dFixupCellAnimBankTbl, NNS_G2dGetUnpackedCellBank, NNS_G2dGetCellDataByIdx, NNSi_G2dUnpackCellBank, NNS_G2dGetUnpackedMultiCellBank, NNSi_G2dFixupMultiCellAnimBankTbl, NNSi_G2dUnpackMultiCellBank, NNS_G2dGetMultiCellDataByIdx, NNS_G2dGetUnpackedCharacterData, NNSi_G2dFixupCharacterData, NNS_G2dGetUnpackedCharacterDataEx, NNSi_G2dFixupCharacterDataEx, NNS_G2dGetUnpackedPaletteData, NNS_G2dGetUnpackedPaletteCompressInfo, NNSi_G2dFixupPaletteCompressInfo, NNSi_G2dFixupPaletteData
 * address:  0x02062634
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
 *   NNS_G2dFindBinaryBlock    0x02062B64  arm
 *   NNSi_G2dFixupOffsets 0x02062BAC arm
 */
struct AnimBank;
struct NitroFileHeader;
struct Tbl;
struct CellDataBank;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct AnimFrameData {              /* stride 8 */
    void *pContent;             /* +0x00  offset into the frame-data pool   */
    u16 frames;                 /* +0x04                                    */
    u16 pad;
} AnimFrameData;

typedef struct AnimSequenceData {           /* stride 0x10 */
    u16 numFrames;              /* +0x00 */
    u16 loopStartFrameIdx;      /* +0x02 */
    u32 animType;               /* +0x04 */
    u32 playMode;               /* +0x08 */
    AnimFrameData *pAnmFrameArray; /* +0x0c */
} AnimSequenceData;

struct MultiCellNode {          /* stride 0x0c */
    u16 numCells;               /* +0x00 */
    u16 pad02;                  /* +0x02 */
    u8 *pOffsetArray;           /* +0x04  offset, relocated to a pointer */
    u32 *pCellOffsets;          /* +0x08 */
};

struct MultiCellNodeBank {
    u16 numNodes;               /* +0x00 (bank + 8) */
    u16 pad02;
    struct MultiCellNode *pNodes; /* +0x04 */
};

struct AnimBankPair {
    u32 seqOffset;
    u32 framesOffset;
};

struct AnimBank {
    u16 numSequences;              /* +0x00 */
    u16 numTotalFrames;            /* +0x02 */
    AnimSequenceData *pSequences;  /* +0x04 */
    AnimFrameData *pFrames;        /* +0x08 */
    u8 *pPool;                     /* +0x0c */
    u32 unk10;                     /* +0x10 */
    u8 *pSubBank;                  /* +0x14 */
};

typedef signed int     s32;

typedef signed short   s16;

struct CellDataBank {
    u16 numCells;
    u16 bankAttr;
    void *pCells;
};

struct CellData {
    u16 numOam;
    u16 cellAttr;
    void *pOam;
};

struct CellDataEx {
    u16 numOam;
    u16 cellAttr;
    void *pOam;
    s16 t, l, b, r;
};

/* The 'RAHC' (NCGR) character-data body: only the +0x14 self-relative offset
 * is touched by the fixup; the rest of the header is not read here. */
struct NNSG2dCharacterData {
    u8  pad_00[0x14];
    u32 pCharData;      /* +0x14  offset, becomes a pointer */
};

/* The 'TTLP' (NCLR) palette-data body: only the +0x0c self-relative offset
 * is touched by the fixup. */
struct NNSG2dPaletteData {
    u8  pad_00[0x0c];
    u32 pPlttData;      /* +0x0c  offset, becomes a pointer */
};

/* The 'PMCP' palette-compress-map body: only the +0x04 self-relative offset
 * is touched by the fixup. */
struct NNSG2dPaletteCompressInfo {
    u8  pad_00[0x04];
    u32 pVramTransfer;  /* +0x04  offset, becomes a pointer */
};

struct MultiCellData {
    u16 numNodes;
    u16 pad02;
    u32 nodeOffset;
};

struct MultiCellBank {
    u16 numMultiCell;
    u16 pad02;
    struct MultiCellData *pArray;
    u32 nodeBase;
    u32 unk0C;
    u8 *pAnimBank;
};

extern void *NNS_G2dFindBinaryBlock(struct NitroFileHeader *file, u32 signature);
extern void NNSi_G2dFixupOffsets(struct Tbl *t);
int NNS_G2dGetUnpackedAnimBank(u32 a, u32 *out);
void NNS_G2dGetUnpackedAnimBankEx(u32 a, u32 *out);
void NNSi_G2dGetUnpackedAnimBank(u32 a, u32 *out);
void NNSi_G2dUnpackAnimBank(volatile struct AnimBank *bank);
AnimSequenceData *NNS_G2dGetAnimSequenceByIdx(struct AnimBank *bank, u32 idx);
void *NNSi_G2dGetCellDataBankOamBase(struct CellDataBank *bank);
void NNSi_G2dFixupCellAnimBankTbl(void *p);
int NNS_G2dGetUnpackedCellBank(int a, int *out);
void *NNS_G2dGetCellDataByIdx(struct CellDataBank *bank, u32 idx);
void NNSi_G2dUnpackCellBank(int *p);
int NNS_G2dGetUnpackedMultiCellBank(u32 a, u32 *out);
void NNSi_G2dFixupMultiCellAnimBankTbl(void *animBank);
void NNSi_G2dUnpackMultiCellBank(volatile struct MultiCellBank *bank);
struct MultiCellData *NNS_G2dGetMultiCellDataByIdx(struct MultiCellBank *bank, u32 idx);
s32 NNS_G2dGetUnpackedCharacterData(struct NitroFileHeader *file, void **out);
void NNSi_G2dFixupCharacterData(u8 *block);
s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);
void NNSi_G2dFixupCharacterDataEx(u8 *block);
s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);
s32 NNS_G2dGetUnpackedPaletteCompressInfo(struct NitroFileHeader *file, void **out);
void NNSi_G2dFixupPaletteCompressInfo(u8 *block);
void NNSi_G2dFixupPaletteData(u8 *block);




/*
 * Blocking class: label.  Every concrete byte is right; the only unresolved site
 * is the tail `bl NNSi_G2dUnpackAnimBank` at 0x02062648, and 0x02062688 -- the packet's own
 * 336-byte function -- has no witness outside this file's range, because this is
 * its only caller.  The `bl NNS_G2dFindBinaryBlock` site resolves (`label x40`), so the
 * file closes on its own as soon as 0x02062688 is matched, which makes the site
 * `matched` instead of `label`.
 */
int NNS_G2dGetUnpackedAnimBank(u32 a, u32 *out)
{
    u32 r = (u32)NNS_G2dFindBinaryBlock((struct NitroFileHeader *)a, 0x41424E4B);

    if (r == 0) {
        *out = 0;
        return 0;
    }
    NNSi_G2dUnpackAnimBank((volatile struct AnimBank *)(r + 8));
    *out = r + 8;
    return 1;
}




void NNS_G2dGetUnpackedAnimBankEx(u32 a, u32 *out){ NNS_G2dGetUnpackedAnimBank(a, out); }




void NNSi_G2dGetUnpackedAnimBank(u32 a, u32 *out){ NNS_G2dGetUnpackedAnimBank(a, out); }



/*
 * NANR bank fixup ('KNBA' body, NitroSystem NNSi_G2dUnpackNAN shape): turn
 * the bank's sequence / frame / pool offsets into pointers, relocate every
 * sequence's frame array and every frame's data pointer, then, when the bank
 * carries an extended sub-block at +0x14, relocate it and its per-node arrays
 * (docs/families/cluster_02062688.h).
 *
 * Closed wave 12 from the a9 source of docs/notes/pkt_02062688.c.txt:
 *   - COMPILER ../2.0/sp2.  The whole "re-load plus ldmib merge" wall of that
 *     note is a 1.1p1 artefact: under 2.0/sp2 the a9 spelling (volatile bank,
 *     pair read through a non-volatile BankPair view) emits the single
 *     `ldmib r0, {r4, r5}` directly.  The cluster's "no pin" statement no
 *     longer holds for this row.
 *   - the frame data field is a POINTER (`void *`) relocated as
 *     `(void *)((u32)data + (u32)pool)`; as a u32 field the add comes out
 *     `add r8, r8, r6` instead of `add r8, r6, r8`.
 *   - the sub-bank walk indexes nodes naturally (`&mc->nodes[k]`, u32 k: the
 *     compiler strength-reduces to the image's `add r3, r3, #0xc`), and the
 *     inner walk is a guarded do-while with its own byte cursor initialised
 *     INSIDE the guard (image `mov r8, r7` after the `bls`).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G2dUnpackAnimBank.c \
 *       --func NNSi_G2dUnpackAnimBank --addr 0x02062688 --arm --cc ../2.0/sp2
 *   EXACT, 336 bytes, no relocations (sp2p2 EXACT; dsi/1.1p1 332 DIFF).
 */
void NNSi_G2dUnpackAnimBank(volatile struct AnimBank *bank)
{
    u16 i, j;
    u16 n;
    AnimSequenceData *seq;
    AnimFrameData *frames;
    u8 *pool;
    u8 *sub;

    bank->pSequences = (AnimSequenceData *)((u32)bank->pSequences + (u32)bank);
    bank->pFrames = (AnimFrameData *)((u32)bank->pFrames + (u32)bank);
    pool         = (u8 *)bank->pPool + (u32)bank;
    bank->pPool   = pool;

    i = 0;
    n = bank->numSequences;
    {
        struct AnimBankPair *pp = (struct AnimBankPair *)((u8 *)bank + 4);
        seq = (AnimSequenceData *)pp->seqOffset;
        frames = (AnimFrameData *)pp->framesOffset;
    }

    while (i < n) {
        seq[i].pAnmFrameArray = (AnimFrameData *)((u32)seq[i].pAnmFrameArray + (u32)frames);
        for (j = 0; j < seq[i].numFrames; j++) {
            seq[i].pAnmFrameArray[j].pContent = (void *)((u32)seq[i].pAnmFrameArray[j].pContent + (u32)pool);
        }
        n = bank->numSequences;
        i++;
    }

    sub = bank->pSubBank;
    if (sub != 0) {
        u32 k, m, coff;
        struct MultiCellNodeBank *mc;
        sub = sub + (u32)bank;
        bank->pSubBank = sub;
        mc = (struct MultiCellNodeBank *)(sub + 8);
        mc->pNodes = (struct MultiCellNode *)((u32)mc->pNodes + (u32)mc);
        for (k = 0; k < mc->numNodes; k++) {
            struct MultiCellNode *n = &mc->pNodes[k];
            n->pOffsetArray = n->pOffsetArray + (u32)mc;
            n->pCellOffsets = (u32 *)((u8 *)n->pCellOffsets + (u32)mc);
            m = 0;
            if (m < n->numCells) {
                coff = 0;
                do {
                    *(u32 *)((u8 *)n->pCellOffsets + coff) = *(u32 *)((u8 *)n->pCellOffsets + coff) + (u32)mc;
                    m++;
                    coff += 4;
                } while (m < n->numCells);
            }
        }
    }
}





/*
 * *
 * Returns the idx'th animation sequence of an NNS G2D cell-animation bank
 * (the NANR file's 'KNBA' block body), or NULL when idx is out of range.
 * The `lsl #4` pins the sequence stride at 16 bytes.
 *
 * This is the lookup a multi-cell node's own u16 index feeds: NNSi_G2dSetMCDataToMCInstanceImpl
 * passes the node's +0x00 field straight in, so a node names a sequence, and
 * the sequence's current frame is what names the cell to draw.
 *
 * The sibling fixup routine at 0x02062688 pins the rest of the block:
 *
 *   bank  +0x00  u16 numSequences
 *         +0x02  u16 numTotalFrames
 *         +0x04  offset -> sequence array, 16 bytes per entry
 *         +0x08  offset -> frame-entry array, 8 bytes per entry
 *         +0x0C  offset -> frame-data pool
 *
 *   sequence  +0x00  u16 numFrames
 *             +0x02  u16 loopStartFrameIdx
 *             +0x04  u32 animType (low byte 0/1/2 selects the frame-data
 *                                  record shape, see NNSi_G2dRefreshCellAnimation)
 *             +0x08  u32 playMode
 *             +0x0C  offset -> this sequence's own run of frame entries,
 *                              relative to the bank's +0x08 array
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dGetAnimSequenceByIdx.c  *       --func NNS_G2dGetAnimSequenceByIdx --addr 0x020627D8 --cc 1.1p1
 */
AnimSequenceData *NNS_G2dGetAnimSequenceByIdx(struct AnimBank *bank, u32 idx)
{
    if (bank->numSequences > idx) {
        return &bank->pSequences[idx];
    }

    return 0;
}


void *NNSi_G2dGetCellDataBankOamBase(struct CellDataBank *bank)
{
    if (bank->bankAttr & 1) {
        return (struct CellDataEx *)bank->pCells + bank->numCells;
    } else {
        return (struct CellData *)bank->pCells + bank->numCells;
    }
}




void NNSi_G2dFixupCellAnimBankTbl(void *p)
{
    NNSi_G2dFixupOffsets((struct Tbl *)((u8 *)p + 8));
}




int NNS_G2dGetUnpackedCellBank(int a, int *out)
{
    char *o = (char *)NNS_G2dFindBinaryBlock((struct NitroFileHeader *)a, 0x4345424b);
    if (o == 0) {
        *out = 0;
        return 0;
    }
    NNSi_G2dUnpackCellBank((int *)(o + 8));
    *out = (int)(o + 8);
    return 1;
}







/*
 * *
 * Returns the idx'th cell of an NNS G2D cell data bank (the NCER file's
 * 'KBEC' block body), or NULL when idx is out of range.
 *
 *   bank  +0x00  u16 numCells
 *         +0x02  u16 bankAttr    bit0: cells carry a bounding box
 *         +0x04  offset -> cell array
 *         +0x08  u32 mappingType
 *         +0x0C  offset -> VRAM transfer data, or 0
 *         +0x14  offset -> embedded cell-animation bank, or 0
 *
 * The `tst #1` plus the two shifts pin the cell stride: 8 bytes for a plain
 * cell ({u16 numOam; u16 cellAttr; offset oam;}) and 16 for one that carries
 * the extra bounding-box rectangle. Every cell in the a/0/0/4 rig archive is
 * the plain 8-byte kind.
 *
 * NNSi_G2dUnpackCellBank fixes the block up and is what pins the OAM array's own base:
 * it walks the cells adding the address *past* the end of the cell array
 * (NNSi_G2dGetCellDataBankOamBase) to each cell's own offset field, so a cell's OAM offset is
 * relative to the byte after the last cell record, not to the block.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dGetCellDataByIdx.c  *       --func NNS_G2dGetCellDataByIdx --addr 0x0206285C --cc 1.1p1
 */
void *NNS_G2dGetCellDataByIdx(struct CellDataBank *bank, u32 idx)
{
    if (idx >= bank->numCells) {
        return 0;
    }

    if (bank->bankAttr & 1) {
        return (u8 *)bank->pCells + idx * 16;
    }

    return (u8 *)bank->pCells + idx * 8;
}


/*
 * parks lane 2 confirms the blocker and narrows it: 0x02062810 is a linker
 * stub with an argument adjustment, not a function,
 *   ldr ip,[pc,#4]; add r0,r0,#8; bx ip; .word 0x02062BAC
 * and `veneer_at()` in tools/match.py only recognises E59FC000 immediately
 * followed by E12FFF1C, or E51FF004 + one word.  The `add` between the load
 * and the branch makes the veneer class refuse, `label` refuses because this
 * call is the only branch to the stub in the image, and naming the real
 * callee (NNSi_G2dFixupOffsets, arm) resolves the site but reproduces 3 concrete
 * bytes (the original `bl` displacement points at the stub).  So this stays
 * MATCH and src/pending/NNS_G2dGetUnpackedCellBank.c cannot be promoted.
 */
void NNSi_G2dUnpackCellBank(int *p)
{
    u16 i;
    int base;
    p[1] = (int)((char *)p[1] + (int)p);
    base = (int)NNSi_G2dGetCellDataBankOamBase((struct CellDataBank *)p);
    for (i = 0; i < ((struct CellDataBank *)p)->numCells; i++) {
        int *e = NNS_G2dGetCellDataByIdx((struct CellDataBank *)p, i);
        e[1] = (int)((char *)e[1] + base);
    }
    if (p[3] != 0) {
        int *q;
        p[3] = (int)((char *)p[3] + (int)p);
        q = (int *)p[3];
        q[1] = (int)((char *)q[1] + (int)q);
        p[3] = (int)q;
    }
    if (p[5] == 0)
        return;
    p[5] = (int)((char *)p[5] + (int)p);
    NNSi_G2dFixupCellAnimBankTbl((void *)p[5]);
}



/*
 * Blocking class: label.  Same shape as src/pending/NNS_G2dGetUnpackedAnimBank.c one tag over:
 * every concrete byte is right, the only unresolved site is the tail
 * `bl NNSi_G2dUnpackMultiCellBank` at 0x02062934, and this call is the only branch to
 * 0x0206296C in the image.  The `bl NNS_G2dFindBinaryBlock` site resolves (`label x40`).
 */
int NNS_G2dGetUnpackedMultiCellBank(u32 a, u32 *out)
{
    u32 r = (u32)NNS_G2dFindBinaryBlock((struct NitroFileHeader *)a, 0x4D43424B);

    if (r == 0) {
        *out = 0;
        return 0;
    }
    NNSi_G2dUnpackMultiCellBank((volatile struct MultiCellBank *)(r + 8));
    *out = r + 8;
    return 1;
}


void NNSi_G2dFixupMultiCellAnimBankTbl(void *animBank)
{
    NNSi_G2dFixupOffsets((struct Tbl *)((u8 *)animBank + 8));
}




/*
 * NNS G2D multi-cell bank (NMCR 'KBCM' block) offset-to-pointer fixup, run
 * once when the bank is unpacked.  It names the on-disk layout exactly:
 *
 *   +0x00  u16 numMultiCell
 *   +0x02  u16 (padding)
 *   +0x04  offset -> the multi-cell descriptor array, 8 bytes per entry
 *   +0x08  offset -> the base the per-descriptor node arrays are relative to
 *   +0x10  offset -> the embedded cell-animation bank ('KNBA'/NANR body), or 0
 *
 * and each 8-byte multi-cell descriptor as
 *
 *   +0x00  u16 numNodes
 *   +0x02  u16
 *   +0x04  offset -> that multi-cell's node array, relative to the +0x08 base
 *
 * The 8-byte descriptor stride is what the loop's `lsl #3` proves; a 10- or
 * 12-byte descriptor is not what this game reads.
 *
 * HOW THE 2026-09-21 WALL WAS CLOSED.  docs/notes/NNSi_G2dUnpackMultiCellBank.c.txt records
 * this function as a 120-of-124-byte near miss: the image re-loads the +0x04
 * field it has just stored (`ldr r4,[r0,#4]` at +0x24), and every plain
 * spelling lets -O4,p forward the stored value instead, four bytes short.
 * Three things together reproduce it, and all three are load-order evidence,
 * not decoration:
 *   1. the bank pointer is `volatile`, which is what stops the two +0x04/+0x08
 *      fixups being scheduled in parallel into two scratch registers;
 *   2. the re-load is written as an explicit `*(volatile u32 *)(bank + 4)`
 *      read into a local, which is the only spelling the optimiser does not
 *      forward through -- a plain `array = bank->array` still folds;
 *   3. the loop bound is re-read at the BOTTOM of the body (`n =
 *      bank->numMultiCell;` after the store), which is what puts the count's
 *      `ldrh r1,[r0]` ahead of the array re-load instead of behind it.
 * The last two steps (statement order inside the body, and binding the sum to
 * a named temporary so the `add` lands before the `str`) were found by
 * tools/permuter.py --mode hill: `reorder(+1) ; temp(tmp=array[i].nodes +
 * bank->nodeBase)`, EXACT at compile 429 of 800.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G2dUnpackMultiCellBank.c \
 *       --func NNSi_G2dUnpackMultiCellBank --addr 0x0206296C --cc 1.1p1 --arm
 */
void NNSi_G2dUnpackMultiCellBank(volatile struct MultiCellBank *bank)
{
    u16 i;
    u16 n;
    struct MultiCellData *array;
    u8 *anim;
    u32 tmp;

    bank->pArray = (struct MultiCellData *)((u32)bank->pArray + (u32)bank);
    bank->nodeBase = bank->nodeBase + (u32)bank;

    i = 0;
    n = bank->numMultiCell;
    array = (struct MultiCellData *)*(volatile u32 *)&bank->pArray;

    while (i < n) {
        tmp = array[i].nodeOffset + bank->nodeBase;
        array[i].nodeOffset = tmp;
        n = bank->numMultiCell;
        i++;
    }

    anim = bank->pAnimBank;
    if (anim != 0) {
        anim = anim + (u32)bank;
        bank->pAnimBank = anim;
        NNSi_G2dFixupMultiCellAnimBankTbl(anim);
    }
}




/*
 * *
 * Returns the idx'th multi-cell descriptor of an NNS G2D multi-cell bank
 * (the NMCR file's 'KBCM' block body), or NULL when idx is out of range.
 * The `lsl #3` pins the descriptor stride at 8 bytes, and the sibling fixup
 * routine at 0x0206296C (see docs/notes/NNSi_G2dUnpackMultiCellBank.c.txt) pins the rest
 * of the block layout:
 *
 *   bank  +0x00  u16 numMultiCell
 *         +0x02  u16 (padding)
 *         +0x04  offset -> descriptor array, 8 bytes per entry
 *         +0x08  offset -> base that per-descriptor node arrays are relative to
 *         +0x10  offset -> embedded cell-animation bank ('KNBA'/NANR body), or 0
 *
 *   descriptor  +0x00  u16 numNodes
 *               +0x02  u16
 *               +0x04  offset -> this multi-cell's node array
 *
 * A 10- or 12-byte descriptor stride is not what this game reads.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dGetMultiCellDataByIdx.c  *       --func NNS_G2dGetMultiCellDataByIdx --addr 0x020629E8 --cc 1.1p1
 */
struct MultiCellData *NNS_G2dGetMultiCellDataByIdx(struct MultiCellBank *bank, u32 idx)
{
    if (idx < bank->numMultiCell) {
        return &bank->pArray[idx];
    }

    return 0;
}



/*
 * Finds the 'RAHC' (NCGR character data) block in a loaded NITRO file, runs its
 * offset-to-pointer fixup and hands back the block body (block header + 8).
 * Returns 1 on success, 0 (and a NULL out-pointer) when the block is absent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dGetUnpackedCharacterData.c  *       --func NNS_G2dGetUnpackedCharacterData --addr 0x02062A00 --cc 1.1p1
 */
s32 NNS_G2dGetUnpackedCharacterData(struct NitroFileHeader *file, void **out)
{
    void *block = NNS_G2dFindBinaryBlock(file, 0x43484152);

    if (block == 0) {
        *out = 0;
        return 0;
    }

    NNSi_G2dFixupCharacterData((u8 *)block + 8);
    *out = (u8 *)block + 8;
    return 1;
}




/*
 * *
 * One-field offset-to-pointer fixup for the character-data bank ('RAHC' / NCGR body): the u32 at +0x14 is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dFixupCharacterData.c  *       --func NNSi_G2dFixupCharacterData --addr 0x02062A3C --cc 1.1p1
 */
void NNSi_G2dFixupCharacterData(u8 *block)
{
    ((struct NNSG2dCharacterData *)block)->pCharData = ((struct NNSG2dCharacterData *)block)->pCharData + (u32)block;
}



/*
 * Finds the 'RAHC' (NCGR character data), second entry point block in a loaded NITRO file, runs its
 * offset-to-pointer fixup and hands back the block body (block header + 8).
 * Returns 1 on success, 0 (and a NULL out-pointer) when the block is absent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dGetUnpackedCharacterDataEx.c  *       --func NNS_G2dGetUnpackedCharacterDataEx --addr 0x02062A4C --cc 1.1p1
 */
s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out)
{
    void *block = NNS_G2dFindBinaryBlock(file, 0x43484152);

    if (block == 0) {
        *out = 0;
        return 0;
    }

    NNSi_G2dFixupCharacterDataEx((u8 *)block + 8);
    *out = (u8 *)block + 8;
    return 1;
}




/*
 * *
 * One-field offset-to-pointer fixup for the second 'RAHC' consumer, same fixup: the u32 at +0x14 is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dFixupCharacterDataEx.c  *       --func NNSi_G2dFixupCharacterDataEx --addr 0x02062A88 --cc 1.1p1
 */
void NNSi_G2dFixupCharacterDataEx(u8 *block)
{
    ((struct NNSG2dCharacterData *)block)->pCharData = ((struct NNSG2dCharacterData *)block)->pCharData + (u32)block;
}



/*
 * Finds the 'TTLP' (NCLR palette data) block in a loaded NITRO file, runs its
 * offset-to-pointer fixup and hands back the block body (block header + 8).
 * Returns 1 on success, 0 (and a NULL out-pointer) when the block is absent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dGetUnpackedPaletteData.c  *       --func NNS_G2dGetUnpackedPaletteData --addr 0x02062A98 --cc 1.1p1
 */
s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out)
{
    void *block = NNS_G2dFindBinaryBlock(file, 0x504C5454);

    if (block == 0) {
        *out = 0;
        return 0;
    }

    NNSi_G2dFixupPaletteData((u8 *)block + 8);
    *out = (u8 *)block + 8;
    return 1;
}



/*
 * Finds the 'PMCP' (palette compression map) block in a loaded NITRO file, runs its
 * offset-to-pointer fixup and hands back the block body (block header + 8).
 * Returns 1 on success, 0 (and a NULL out-pointer) when the block is absent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dGetUnpackedPaletteCompressInfo.c  *       --func NNS_G2dGetUnpackedPaletteCompressInfo --addr 0x02062AD4 --cc 1.1p1
 */
s32 NNS_G2dGetUnpackedPaletteCompressInfo(struct NitroFileHeader *file, void **out)
{
    void *block = NNS_G2dFindBinaryBlock(file, 0x50434D50);

    if (block == 0) {
        *out = 0;
        return 0;
    }

    NNSi_G2dFixupPaletteCompressInfo((u8 *)block + 8);
    *out = (u8 *)block + 8;
    return 1;
}




/*
 * *
 * One-field offset-to-pointer fixup for the palette-compress-proxy bank ('PMCP' body): the u32 at +0x4 is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dFixupPaletteCompressInfo.c  *       --func NNSi_G2dFixupPaletteCompressInfo --addr 0x02062B10 --cc 1.1p1
 */
void NNSi_G2dFixupPaletteCompressInfo(u8 *block)
{
    ((struct NNSG2dPaletteCompressInfo *)block)->pVramTransfer = ((struct NNSG2dPaletteCompressInfo *)block)->pVramTransfer + (u32)block;
}




/*
 * *
 * One-field offset-to-pointer fixup for the palette bank ('TTLP' / NCLR body): the u32 at +0xc is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dFixupPaletteData.c  *       --func NNSi_G2dFixupPaletteData --addr 0x02062B20 --cc 1.1p1
 */
void NNSi_G2dFixupPaletteData(u8 *block)
{
    ((struct NNSG2dPaletteData *)block)->pPlttData = ((struct NNSG2dPaletteData *)block)->pPlttData + (u32)block;
}
