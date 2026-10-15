/*
 * function: NNS_G2dGetMultiCellDataByIdx
 * address:  0x020629E8
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct MultiCellData {
    u16 numNodes;
    u16 unk02;
    u32 nodes;
};

struct MultiCellBank {
    u16 numMultiCell;
    u16 unk02;
    struct MultiCellData *array;
};

struct MultiCellData *NNS_G2dGetMultiCellDataByIdx(struct MultiCellBank *bank, u32 idx)
{
    if (idx < bank->numMultiCell) {
        return &bank->array[idx];
    }

    return 0;
}
