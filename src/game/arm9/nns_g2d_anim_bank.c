/*
 * file:     nns_g2d_anim_bank.c
 * unit:     yes
 * function: func_02062634, func_02062670, func_0206267C, func_02062688, func_020627D8, func_020627F0, func_02062810, func_02062820, func_0206285C, func_02062884, func_02062920, func_0206295C, func_0206296C, func_020629E8, func_02062A00, func_02062A3C, func_02062A4C, func_02062A88, func_02062A98, func_02062AD4, func_02062B10, func_02062B20
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
 *   func_02062BAC 0x02062BAC arm
 */
#include "../../matched/include/Obj02023.h"
#include "../../matched/include/Obj02615.h"
#include "../../matched/include/Obj11515.h"
#include "../../matched/include/Obj11517.h"
#include "../../matched/include/Obj11520.h"
#include "../../matched/include/Obj11521.h"

struct AnimBank_02062634;
struct NitroFileHeader;
struct Tbl;
struct CellDataBank;
struct MultiCellBank_020627D8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct AnimFrame {              /* stride 8 */
    void *data;
    u32 duration;               /* +0x04                                    */
};

struct AnimSequence_02062634 {           /* stride 0x10 */
    u16 numFrames;              /* +0x00 */
    u16 loopStart;              /* +0x02 */
    u32 animType;               /* +0x04 */
    u32 playMode;               /* +0x08 */
    struct AnimFrame *frames;   /* +0x0c */
};

struct MultiCellNode {          /* stride 0x0c */
    u16 numCells;               /* +0x00 */
    u16 unk02;                  /* +0x02 */
    u8 *unk04;                  /* +0x04 */
    u32 *cells;                 /* +0x08 */
};

struct MultiCellBank_02062634 {
    u16 numNodes;               /* +0x00 (bank + 8) */
    u16 unk02;
    struct MultiCellNode *nodes;/* +0x04 */
};

struct BankPair {
    u32 seq;
    u32 frames;
};

struct AnimBank_02062634 {
    u16 numSequences;           /* +0x00 */
    u16 numTotalFrames;         /* +0x02 */
    struct AnimSequence_02062634 *seq;   /* +0x04 */
    struct AnimFrame *frames;   /* +0x08 */
    u8 *pool;                   /* +0x0c */
    u32 unk10;                  /* +0x10 */
    u8 *sub;                    /* +0x14 */
};

typedef signed int     s32;

typedef signed short   s16;

struct AnimSequence_020627D8 {
    u16 numFrames;
    u16 loopStartFrameIdx;
    u32 animType;
    u32 playMode;
    void *frames;
};

struct AnimBank_020627D8 {
    u16 numSequences;
    u16 numTotalFrames;
    struct AnimSequence_020627D8 *array;
};

struct CellDataBank {
    u16 numCells;
    u16 bankAttr;
    void *cells;
};

struct CellData {
    u16 numOam;
    u16 cellAttr;
    void *oam;
};

struct CellDataEx {
    u16 numOam;
    u16 cellAttr;
    void *oam;
    s16 t, l, b, r;
};

struct MultiCellData {
    u16 numNodes;
    u16 unk02;
    u32 nodes;
};

struct MultiCellBank_020627D8 {
    u16 numMultiCell;
    u16 unk02;
    struct MultiCellData *array;
    u32 nodeBase;
    u32 unk0C;
    u8 *animBank;
};

extern void *NNS_G2dFindBinaryBlock(struct NitroFileHeader *file, u32 signature);
extern void func_02062BAC(struct Tbl *t);
int func_02062634(u32 a, u32 *out);
void func_02062670(u32 a, u32 *out);
void func_0206267C(u32 a, u32 *out);
void func_02062688(volatile struct AnimBank_02062634 *bank);
struct AnimSequence_020627D8 *func_020627D8(struct AnimBank_020627D8 *bank, u32 idx);
void *func_020627F0(struct CellDataBank *bank);
void func_02062810(void *p);
int func_02062820(int a, int *out);
void *func_0206285C(struct CellDataBank *bank, u32 idx);
void func_02062884(int *p);
int func_02062920(u32 a, u32 *out);
void func_0206295C(void *animBank);
void func_0206296C(volatile struct MultiCellBank_020627D8 *bank);
struct MultiCellData *func_020629E8(struct MultiCellBank_020627D8 *bank, u32 idx);
s32 func_02062A00(struct NitroFileHeader *file, void **out);
void func_02062A3C(u8 *block);
s32 func_02062A4C(struct NitroFileHeader *file, void **out);
void func_02062A88(u8 *block);
s32 func_02062A98(struct NitroFileHeader *file, void **out);
s32 func_02062AD4(struct NitroFileHeader *file, void **out);
void func_02062B10(u8 *block);
void func_02062B20(u8 *block);




/*
 * Blocking class: label.  Every concrete byte is right; the only unresolved site
 * is the tail `bl func_02062688` at 0x02062648, and 0x02062688 -- the packet's own
 * 336-byte function -- has no witness outside this file's range, because this is
 * its only caller.  The `bl NNS_G2dFindBinaryBlock` site resolves (`label x40`), so the
 * file closes on its own as soon as 0x02062688 is matched, which makes the site
 * `matched` instead of `label`.
 */
int func_02062634(u32 a, u32 *out)
{
    u32 r = (u32)NNS_G2dFindBinaryBlock((struct NitroFileHeader *)a, 0x41424E4B);

    if (r == 0) {
        *out = 0;
        return 0;
    }
    func_02062688((volatile struct AnimBank_02062634 *)(r + 8));
    *out = r + 8;
    return 1;
}




void func_02062670(u32 a, u32 *out){ func_02062634(a, out); }




void func_0206267C(u32 a, u32 *out){ func_02062634(a, out); }



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
 *   python3 tools/match.py one --src src/matched/func_02062688.c \
 *       --func func_02062688 --addr 0x02062688 --arm --cc ../2.0/sp2
 *   EXACT, 336 bytes, no relocations (sp2p2 EXACT; dsi/1.1p1 332 DIFF).
 */
void func_02062688(volatile struct AnimBank_02062634 *bank)
{
    u16 i, j;
    u16 n;
    struct AnimSequence_02062634 *seq;
    struct AnimFrame *frames;
    u8 *pool;
    u8 *sub;

    bank->seq    = (struct AnimSequence_02062634 *)((u32)bank->seq + (u32)bank);
    bank->frames = (struct AnimFrame *)((u32)bank->frames + (u32)bank);
    pool         = (u8 *)bank->pool + (u32)bank;
    bank->pool   = pool;

    i = 0;
    n = bank->numSequences;
    {
        struct BankPair *pp = (struct BankPair *)((u8 *)bank + 4);
        seq = (struct AnimSequence_02062634 *)pp->seq;
        frames = (struct AnimFrame *)pp->frames;
    }

    while (i < n) {
        seq[i].frames = (struct AnimFrame *)((u32)seq[i].frames + (u32)frames);
        for (j = 0; j < seq[i].numFrames; j++) {
            seq[i].frames[j].data = (void *)((u32)seq[i].frames[j].data + (u32)pool);
        }
        n = bank->numSequences;
        i++;
    }

    sub = bank->sub;
    if (sub != 0) {
        u32 k, m, coff;
        struct MultiCellBank_02062634 *mc;
        sub = sub + (u32)bank;
        bank->sub = sub;
        mc = (struct MultiCellBank_02062634 *)(sub + 8);
        mc->nodes = (struct MultiCellNode *)((u32)mc->nodes + (u32)mc);
        for (k = 0; k < mc->numNodes; k++) {
            struct MultiCellNode *n = &mc->nodes[k];
            n->unk04 = n->unk04 + (u32)mc;
            n->cells = (u32 *)((u8 *)n->cells + (u32)mc);
            m = 0;
            if (m < n->numCells) {
                coff = 0;
                do {
                    *(u32 *)((u8 *)n->cells + coff) = *(u32 *)((u8 *)n->cells + coff) + (u32)mc;
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
 * This is the lookup a multi-cell node's own u16 index feeds: func_020643CC
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
 *                                  record shape, see func_0206419C)
 *             +0x08  u32 playMode
 *             +0x0C  offset -> this sequence's own run of frame entries,
 *                              relative to the bank's +0x08 array
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020627D8.c  *       --func func_020627D8 --addr 0x020627D8 --cc 1.1p1
 */
struct AnimSequence_020627D8 *func_020627D8(struct AnimBank_020627D8 *bank, u32 idx)
{
    if (bank->numSequences > idx) {
        return &bank->array[idx];
    }

    return 0;
}


void *func_020627F0(struct CellDataBank *bank)
{
    if (bank->bankAttr & 1) {
        return (struct CellDataEx *)bank->cells + bank->numCells;
    } else {
        return (struct CellData *)bank->cells + bank->numCells;
    }
}




void func_02062810(void *p)
{
    func_02062BAC((struct Tbl *)((u8 *)p + 8));
}




int func_02062820(int a, int *out)
{
    char *o = (char *)NNS_G2dFindBinaryBlock((struct NitroFileHeader *)a, 0x4345424b);
    if (o == 0) {
        *out = 0;
        return 0;
    }
    func_02062884((int *)(o + 8));
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
 * func_02062884 fixes the block up and is what pins the OAM array's own base:
 * it walks the cells adding the address *past* the end of the cell array
 * (func_020627F0) to each cell's own offset field, so a cell's OAM offset is
 * relative to the byte after the last cell record, not to the block.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206285C.c  *       --func func_0206285C --addr 0x0206285C --cc 1.1p1
 */
void *func_0206285C(struct CellDataBank *bank, u32 idx)
{
    if (idx >= bank->numCells) {
        return 0;
    }

    if (bank->bankAttr & 1) {
        return (u8 *)bank->cells + idx * 16;
    }

    return (u8 *)bank->cells + idx * 8;
}


/*
 * parks lane 2 confirms the blocker and narrows it: 0x02062810 is a linker
 * stub with an argument adjustment, not a function,
 *   ldr ip,[pc,#4]; add r0,r0,#8; bx ip; .word 0x02062BAC
 * and `veneer_at()` in tools/match.py only recognises E59FC000 immediately
 * followed by E12FFF1C, or E51FF004 + one word.  The `add` between the load
 * and the branch makes the veneer class refuse, `label` refuses because this
 * call is the only branch to the stub in the image, and naming the real
 * callee (func_02062BAC, arm) resolves the site but reproduces 3 concrete
 * bytes (the original `bl` displacement points at the stub).  So this stays
 * MATCH and src/pending/func_02062820.c cannot be promoted.
 */
void func_02062884(int *p)
{
    u16 i;
    int base;
    p[1] = (int)((char *)p[1] + (int)p);
    base = (int)func_020627F0((struct CellDataBank *)p);
    for (i = 0; i < ((struct Obj02023 *)p)->f0; i++) {
        int *e = func_0206285C((struct CellDataBank *)p, i);
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
    func_02062810((void *)p[5]);
}



/*
 * Blocking class: label.  Same shape as src/pending/func_02062634.c one tag over:
 * every concrete byte is right, the only unresolved site is the tail
 * `bl func_0206296C` at 0x02062934, and this call is the only branch to
 * 0x0206296C in the image.  The `bl NNS_G2dFindBinaryBlock` site resolves (`label x40`).
 */
int func_02062920(u32 a, u32 *out)
{
    u32 r = (u32)NNS_G2dFindBinaryBlock((struct NitroFileHeader *)a, 0x4D43424B);

    if (r == 0) {
        *out = 0;
        return 0;
    }
    func_0206296C((volatile struct MultiCellBank_020627D8 *)(r + 8));
    *out = r + 8;
    return 1;
}


void func_0206295C(void *animBank)
{
    func_02062BAC((struct Tbl *)((u8 *)animBank + 8));
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
 * HOW THE 2026-09-21 WALL WAS CLOSED.  docs/notes/func_0206296C.c.txt records
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
 *   python3 tools/match.py one --src src/matched/func_0206296C.c \
 *       --func func_0206296C --addr 0x0206296C --cc 1.1p1 --arm
 */
void func_0206296C(volatile struct MultiCellBank_020627D8 *bank)
{
    u16 i;
    u16 n;
    struct MultiCellData *array;
    u8 *anim;
    u32 tmp;

    bank->array = (struct MultiCellData *)((u32)bank->array + (u32)bank);
    bank->nodeBase = bank->nodeBase + (u32)bank;

    i = 0;
    n = bank->numMultiCell;
    array = (struct MultiCellData *)*(volatile u32 *)&((struct Obj02615 *)bank)->f4;

    while (i < n) {
        tmp = array[i].nodes + bank->nodeBase;
        array[i].nodes = tmp;
        n = bank->numMultiCell;
        i++;
    }

    anim = bank->animBank;
    if (anim != 0) {
        anim = anim + (u32)bank;
        bank->animBank = anim;
        func_0206295C(anim);
    }
}




/*
 * *
 * Returns the idx'th multi-cell descriptor of an NNS G2D multi-cell bank
 * (the NMCR file's 'KBCM' block body), or NULL when idx is out of range.
 * The `lsl #3` pins the descriptor stride at 8 bytes, and the sibling fixup
 * routine at 0x0206296C (see docs/notes/func_0206296C.c.txt) pins the rest
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
 *   python tools/match.py one --src src/matched/func_020629E8.c  *       --func func_020629E8 --addr 0x020629E8 --cc 1.1p1
 */
struct MultiCellData *func_020629E8(struct MultiCellBank_020627D8 *bank, u32 idx)
{
    if (idx < bank->numMultiCell) {
        return &bank->array[idx];
    }

    return 0;
}



/*
 * Finds the 'RAHC' (NCGR character data) block in a loaded NITRO file, runs its
 * offset-to-pointer fixup and hands back the block body (block header + 8).
 * Returns 1 on success, 0 (and a NULL out-pointer) when the block is absent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062A00.c  *       --func func_02062A00 --addr 0x02062A00 --cc 1.1p1
 */
s32 func_02062A00(struct NitroFileHeader *file, void **out)
{
    void *block = NNS_G2dFindBinaryBlock(file, 0x43484152);

    if (block == 0) {
        *out = 0;
        return 0;
    }

    func_02062A3C((u8 *)block + 8);
    *out = (u8 *)block + 8;
    return 1;
}




/*
 * *
 * One-field offset-to-pointer fixup for the character-data bank ('RAHC' / NCGR body): the u32 at +0x14 is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062A3C.c  *       --func func_02062A3C --addr 0x02062A3C --cc 1.1p1
 */
void func_02062A3C(u8 *block)
{
    ((struct Obj11515 *)block)->f14 = ((struct Obj11515 *)block)->f14 + (u32)block;
}



/*
 * Finds the 'RAHC' (NCGR character data), second entry point block in a loaded NITRO file, runs its
 * offset-to-pointer fixup and hands back the block body (block header + 8).
 * Returns 1 on success, 0 (and a NULL out-pointer) when the block is absent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062A4C.c  *       --func func_02062A4C --addr 0x02062A4C --cc 1.1p1
 */
s32 func_02062A4C(struct NitroFileHeader *file, void **out)
{
    void *block = NNS_G2dFindBinaryBlock(file, 0x43484152);

    if (block == 0) {
        *out = 0;
        return 0;
    }

    func_02062A88((u8 *)block + 8);
    *out = (u8 *)block + 8;
    return 1;
}




/*
 * *
 * One-field offset-to-pointer fixup for the second 'RAHC' consumer, same fixup: the u32 at +0x14 is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062A88.c  *       --func func_02062A88 --addr 0x02062A88 --cc 1.1p1
 */
void func_02062A88(u8 *block)
{
    ((struct Obj11517 *)block)->f14 = ((struct Obj11517 *)block)->f14 + (u32)block;
}



/*
 * Finds the 'TTLP' (NCLR palette data) block in a loaded NITRO file, runs its
 * offset-to-pointer fixup and hands back the block body (block header + 8).
 * Returns 1 on success, 0 (and a NULL out-pointer) when the block is absent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062A98.c  *       --func func_02062A98 --addr 0x02062A98 --cc 1.1p1
 */
s32 func_02062A98(struct NitroFileHeader *file, void **out)
{
    void *block = NNS_G2dFindBinaryBlock(file, 0x504C5454);

    if (block == 0) {
        *out = 0;
        return 0;
    }

    func_02062B20((u8 *)block + 8);
    *out = (u8 *)block + 8;
    return 1;
}



/*
 * Finds the 'PMCP' (palette compression map) block in a loaded NITRO file, runs its
 * offset-to-pointer fixup and hands back the block body (block header + 8).
 * Returns 1 on success, 0 (and a NULL out-pointer) when the block is absent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062AD4.c  *       --func func_02062AD4 --addr 0x02062AD4 --cc 1.1p1
 */
s32 func_02062AD4(struct NitroFileHeader *file, void **out)
{
    void *block = NNS_G2dFindBinaryBlock(file, 0x50434D50);

    if (block == 0) {
        *out = 0;
        return 0;
    }

    func_02062B10((u8 *)block + 8);
    *out = (u8 *)block + 8;
    return 1;
}




/*
 * *
 * One-field offset-to-pointer fixup for the palette-compress-proxy bank ('PMCP' body): the u32 at +0x4 is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062B10.c  *       --func func_02062B10 --addr 0x02062B10 --cc 1.1p1
 */
void func_02062B10(u8 *block)
{
    ((struct Obj11520 *)block)->f4 = ((struct Obj11520 *)block)->f4 + (u32)block;
}




/*
 * *
 * One-field offset-to-pointer fixup for the palette bank ('TTLP' / NCLR body): the u32 at +0xc is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062B20.c  *       --func func_02062B20 --addr 0x02062B20 --cc 1.1p1
 */
void func_02062B20(u8 *block)
{
    ((struct Obj11521 *)block)->fC = ((struct Obj11521 *)block)->fC + (u32)block;
}
