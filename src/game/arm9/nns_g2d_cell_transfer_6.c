/*
 * file:     nns_g2d_cell_transfer_6.c
 * unit:     no
 * function: func_02066AE0
 * address:  0x02066AE0
 * packet:   pkt_02066AE0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sCellTransferStateManager  0x02148B20  data
 *
 * Claim the first cell of the bank at 0x02148B20 whose +0x1c occupancy word
 * is not 1: set it to 1 and return the index, or return -1 when every cell
 * of the `count` is taken (and when the count is zero).
 *
 * FRONT END: this is a `../2.0/sp2` PIN row, the "kept branches" tell.  The
 * claim block is five instructions (mov #0x30 / mla / mov #1 / str / bx lr)
 * and dsi/1.1p1 -O4,p IF-CONVERTS all five into movne / mlane / movne /
 * strne / bxne, which is 84 bytes against the image's 88.  2.0/sp2 keeps
 * the `beq` over the block and is byte-exact with the same source.  Under
 * 1.1p1 the residue is 4 bytes and 48 concrete out; a full permuter hill
 * (155 singles) and a 2000-compile anneal both fail to move it, and no loop
 * shape reaches it either (goto both polarities, for, while, a volatile
 * store target, a re-derived base pointer, an extra statement in the arm).
 * Only `u8 i` reaches 88 bytes under 1.1p1, and it pays an `and r0, #0xff`
 * the image does not have.  See docs/notes/pkt_02066AE0.c.txt.
 *
 * TWO SOURCE LEVERS, both needed and both cheap to get wrong:
 *   - the entry test is `count > i` against the ZERO counter, not
 *     `count != 0`.  The image's `bls` at 0x02066AF0 is the loop's own
 *     unsigned pre-test hoisted; `!= 0` gives `beq` and is one byte wrong.
 *     This is the same lever src/matched/func_02067998.c needed.
 *   - the claim STORE is through the index, `sCellTransferStateManager.cells[i].used = 1`,
 *     while the SCAN is through the cursor `c`.  That is what makes the
 *     image spend `mov r1, #0x30` / `mla r1, r0, r1, ip` on a cell address
 *     it already has in r2: the accessor NNSi_G2dGetCellTransferState (0x02066878, the
 *     same `base + i * 0x30` shape) is inlined at the store and not at the
 *     load.  Storing through `c` drops both instructions.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02066AE0.c \
 *       --func func_02066AE0 --addr 0x02066AE0 --cc ../2.0/sp2 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Cell02066AE0 {
    u8  pad_00[0x1c];
    u32 used;            /* +0x1c */
    u8  pad_20[0x10];
};

struct Bank02066AE0 {
    u32 pad_00;
    u32 count;                    /* +0x04 */
    struct Cell02066AE0 *cells;   /* +0x08 */
};

extern struct Bank02066AE0 sCellTransferStateManager;

int func_02066AE0(void)
{
    u32 i = 0;

    if (sCellTransferStateManager.count > i) {
        struct Cell02066AE0 *c = sCellTransferStateManager.cells;

        do {
            if (c->used != 1) {
                sCellTransferStateManager.cells[i].used = 1;
                return i;
            }
            i++;
            c++;
        } while (i < sCellTransferStateManager.count);
    }
    return -1;
}
