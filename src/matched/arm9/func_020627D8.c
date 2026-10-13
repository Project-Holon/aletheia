/*
 * function: func_020627D8
 * address:  0x020627D8
 * packet:   pkt_02061EB8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct AnimSequence {
    u16 numFrames;
    u16 loopStartFrameIdx;
    u32 animType;
    u32 playMode;
    void *frames;
};

struct AnimBank {
    u16 numSequences;
    u16 numTotalFrames;
    struct AnimSequence *array;
};

struct AnimSequence *func_020627D8(struct AnimBank *bank, u32 idx)
{
    if (bank->numSequences > idx) {
        return &bank->array[idx];
    }

    return 0;
}
