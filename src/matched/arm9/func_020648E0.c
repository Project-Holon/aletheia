/*
 * function: NNS_G2dGetMCBankNumNodesRequired
 * address:  0x020648E0
 * packet:   pkt_020648E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dGetMultiCellDataByIdx   0x020629E8  arm
 *
 * Returns the largest node count among the multi-cell descriptors of the bank,
 * 0 for an empty bank.  The counter is a u16 (the `lsl #16` / `lsr #16` pair
 * per iteration) and the count is re-read from the bank every iteration, which
 * is why the guard at the top is a rotated `cmp count, #0`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dGetMCBankNumNodesRequired.c \
 *       --func NNS_G2dGetMCBankNumNodesRequired --addr 0x020648E0 --arm --cc 1.1p1
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct MultiCellData {
    u16 numNodes;
    u16 unk_02;
    u32 nodes;
};

struct MultiCellBank {
    u16 numMultiCell;
    u16 unk_02;
    struct MultiCellData *array;
};

extern struct MultiCellData *NNS_G2dGetMultiCellDataByIdx(struct MultiCellBank *bank, u32 idx);

u16 NNS_G2dGetMCBankNumNodesRequired(struct MultiCellBank *bank)
{
    u16 max = 0;
    u16 i;

    for (i = 0; i < bank->numMultiCell; i++) {
        u16 n = NNS_G2dGetMultiCellDataByIdx(bank, i)->numNodes;

        if (n > max) {
            max = n;
        }
    }

    return max;
}
