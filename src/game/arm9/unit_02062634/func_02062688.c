/*
 * function: func_02062688
 * address:  0x02062688
 * packet:   pkt_02062688
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
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
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct AnimFrame {              /* stride 8 */
    void *data;
    u32 duration;               /* +0x04                                    */
};

struct AnimSequence {           /* stride 0x10 */
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

struct MultiCellBank {
    u16 numNodes;               /* +0x00 (bank + 8) */
    u16 unk02;
    struct MultiCellNode *nodes;/* +0x04 */
};

struct BankPair {
    u32 seq;
    u32 frames;
};

struct AnimBank {
    u16 numSequences;           /* +0x00 */
    u16 numTotalFrames;         /* +0x02 */
    struct AnimSequence *seq;   /* +0x04 */
    struct AnimFrame *frames;   /* +0x08 */
    u8 *pool;                   /* +0x0c */
    u32 unk10;                  /* +0x10 */
    u8 *sub;                    /* +0x14 */
};

void func_02062688(volatile struct AnimBank *bank)
{
    u16 i, j;
    u16 n;
    struct AnimSequence *seq;
    struct AnimFrame *frames;
    u8 *pool;
    u8 *sub;

    bank->seq    = (struct AnimSequence *)((u32)bank->seq + (u32)bank);
    bank->frames = (struct AnimFrame *)((u32)bank->frames + (u32)bank);
    pool         = (u8 *)bank->pool + (u32)bank;
    bank->pool   = pool;

    i = 0;
    n = bank->numSequences;
    {
        struct BankPair *pp = (struct BankPair *)((u8 *)bank + 4);
        seq = (struct AnimSequence *)pp->seq;
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
        struct MultiCellBank *mc;
        sub = sub + (u32)bank;
        bank->sub = sub;
        mc = (struct MultiCellBank *)(sub + 8);
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

