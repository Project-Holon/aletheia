/*
 * function: NNS_G2dFindBinaryBlock
 * address:  0x02062B64
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * *
 * NNS G2D binary-block lookup: walks the block chain of a loaded NITRO file
 * starting at the file header's headerSize (u16 at +0x0C) for numBlocks (u16
 * at +0x0E) blocks, returning the first whose 4-character signature matches,
 * else NULL. Each block header is {u32 signature; u32 size}, and size is the
 * whole block, so the walk is a plain byte advance. Every NCGR/NCLR/NCER/NANR
 * /NMCR getter in this module is this call plus a per-format offset fixup.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dFindBinaryBlock.c  *       --func NNS_G2dFindBinaryBlock --addr 0x02062B64 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct NitroBlock {
    u32 signature;
    u32 size;
};

struct NitroFileHeader {
    u32 magic;
    u32 unk04;
    u32 fileSize;
    u16 headerSize;
    u16 numBlocks;
};

void *NNS_G2dFindBinaryBlock(struct NitroFileHeader *file, u32 signature)
{
    struct NitroBlock *block = (struct NitroBlock *)((u8 *)file + file->headerSize);
    u16 numBlocks = file->numBlocks;
    u16 i;

    for (i = 0; i < numBlocks; i++) {
        if (block->signature == signature) {
            return block;
        }
        block = (struct NitroBlock *)((u8 *)block + block->size);
    }

    return 0;
}
