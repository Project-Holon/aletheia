/*
 * function: func_0206285C
 * address:  0x0206285C
 * packet:   pkt_02062820
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct CellDataBank {
    u16 numCells;
    u16 bankAttr;
    void *cells;
};

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
