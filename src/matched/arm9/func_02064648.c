/*
 * function: NNS_G2dGetMCBankNumCellAnimRequired
 * address:  0x02064648
 * packet:   pkt_02064364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020629E8  0x020629E8  arm
 *
 * Returns the largest per-multi-cell "cell animation slot count" (the u16 at
 * +0x02 of the 8-byte multi-cell descriptor) across a whole multi-cell bank.
 * The caller sizes its array of 0x5C-byte cell-animation states with this, and
 * each node's byte at +0x07 is the index into that array -- which is why that
 * byte runs 0, 1, 2, ... across a multi-cell's nodes rather than naming a cell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dGetMCBankNumCellAnimRequired.c  *       --func NNS_G2dGetMCBankNumCellAnimRequired --addr 0x02064648 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct MultiCellData {
    u16 numNodes;
    u16 numCellAnims;
};

struct MultiCellBank {
    u16 numMultiCell;
};

extern struct MultiCellData *func_020629E8(struct MultiCellBank *bank, u32 idx);

u16 NNS_G2dGetMCBankNumCellAnimRequired(struct MultiCellBank *bank)
{
    u16 max = 0;
    u16 i = 0;

    for (i = 0; i < bank->numMultiCell; i++) {
        u16 n = func_020629E8(bank, i)->numCellAnims;

        if (n > max) {
            max = n;
        }
    }

    return max;
}
