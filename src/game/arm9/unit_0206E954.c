/*
 * file:     unit_0206E954.c
 * unit:     yes
 * function: func_0206E954, func_0206E964, func_0206E9A4
 * address:  0x0206E954
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

/* NNSG3dResFileHeader: the part these functions read. */
typedef struct {
    u32 signature;
    u8  unused04[8];
    u16 headerSize;
    u16 numDataBlocks;
} ResFileHeader;

/* Offsets of the data blocks, right after the file header. */
typedef struct {
    u32 ofsBlock0;
    u32 ofsBlock1;
} ResBlockOffsets;

/* Block header (signature, size) followed by a resource dictionary. */
typedef struct {
    u8  unused00[9];
    u8  numEntry;
    u8  unused0a[4];
    u16 ofsEntry;
} ResDictBlock;

/* Prefix of a dictionary data record: the offset of the resource. */
typedef struct {
    u32 ofsRes;
} ResDictData;

#define BTX0_SIGNATURE 0x30585442u

int func_0206E954(int pFile);
unsigned char *func_0206E964(unsigned char *pFile);
u8 *func_0206E9A4(u8 *pFile, u32 resIdx);


/* NNS_G3dGetMdlSet: the file header plus the offset of its first block. */
int func_0206E954(int pFile){ return (pFile + *(int *)((pFile + (((ResFileHeader *)pFile)->headerSize << 0)))); }


/*
 * NNS_G3dGetTex: the texture block of a model file (BMD0) or texture file
 * (BTX0). The halfword at +12 is the offset of the block offset table and
 * the halfword at +14 is the block count (1 = a file that holds one block:
 * the BTX0 form, when the magic matches).
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206E964.c  *       --func func_0206E964 --addr 0x0206E964 --cc 1.1p1 --arm
 */
unsigned char *func_0206E964(unsigned char *pFile)
{
    unsigned char *pBlockOffsets = pFile + ((ResFileHeader *)pFile)->headerSize;

    if (((ResFileHeader *)pFile)->numDataBlocks == 1) {
        if (((ResFileHeader *)pFile)->signature == BTX0_SIGNATURE)
            return pFile + ((ResBlockOffsets *)pBlockOffsets)->ofsBlock0;
        return 0;
    }
    return pFile + ((ResBlockOffsets *)pBlockOffsets)->ofsBlock1;
}


/*
 * NNS_G3dGetAnmByIdx: look up the resource number resIdx of the first block
 * of an animation file through its dictionary; resIdx is reused for the
 * dictionary record address (the register allocation depends on it).
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206E9A4.c  *       --func func_0206E9A4 --addr 0x0206E9A4 --cc 1.1p1 --arm
 */
u8 *func_0206E9A4(u8 *pFile, u32 resIdx)
{
    u8 *pBlock;
    u8 *pDict;
    u32 ofsEntry;

    if (pFile == 0)
        goto ret0;
    pBlock = pFile + *(u32 *)(pFile + ((ResFileHeader *)pFile)->headerSize);
    pDict = pBlock + 8;
    if (pDict == 0)
        goto fail;
    if (resIdx >= ((ResDictBlock *)pBlock)->numEntry)
        goto fail;
    ofsEntry = ((ResDictBlock *)pBlock)->ofsEntry;
    resIdx = *(u16 *)(pDict + ofsEntry) * resIdx + ((u32)pDict + ofsEntry + 4);
    goto end;
fail:
    resIdx = 0;
end:
    if (resIdx != 0)
        return pBlock + ((ResDictData *)resIdx)->ofsRes;
ret0:
    return 0;
}
