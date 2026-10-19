/*
 * file:     nns_g3d_res.c
 * unit:     yes
 * function: NNS_G3dGetResDataByName, NNS_G3dGetResDictIdxByName, NNS_G3dGetMdlSet, NNS_G3dGetTex, NNS_G3dGetAnmByIdx
 * address:  0x0206E62C
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#define BTX0_SIGNATURE 0x30585442u
#include "../types.h"

#include "nns_g3d_anm_calc_types.h"

/* NNSG3dResFileHeader: the part these functions read. */
typedef struct {
    u32 signature;
    u8  unused04[8];
    u16 headerSize;
    u16 numDataBlocks;
} NNSG3dResFileHeader;

/* Offsets of the data blocks, right after the file header. */
typedef struct {
    u32 ofsBlock0;
    u32 ofsBlock1;
} NNSG3dResBlockOffsets;

/* Block header (signature, size) followed by a resource dictionary. */
typedef struct {
    u8  unused00[9];
    u8  numEntry;
    u8  unused0a[4];
    u16 ofsEntry;
} NNSG3dResDictBlock;

/* Prefix of a dictionary data record: the offset of the resource. */
typedef struct {
    u32 ofsRes;
} NNSG3dResDictData;

void *NNS_G3dGetResDataByName(const NNSG3dResDict *dict, const NNSG3dResName *name);
s32 NNS_G3dGetResDictIdxByName(const NNSG3dResDict *dict, const NNSG3dResName *name);
int NNS_G3dGetMdlSet(int pFile);
unsigned char *NNS_G3dGetTex(unsigned char *pFile);
u8 *NNS_G3dGetAnmByIdx(u8 *pFile, u32 resIdx);

static inline const NNSG3dResName *NNSi_G3dGetResNameByIdx(const NNSG3dResDict *dict, u32 idx)
{
    if (dict != 0 && idx < dict->numEntry) {
        const NNSG3dResDictEntryHdr *hdr = (const NNSG3dResDictEntryHdr *)((const u8 *)dict + dict->ofsEntry);
        return (const NNSG3dResName *)((const u8 *)hdr + hdr->ofsName) + idx;
    } else {
        return 0;
    }
}

static inline void *NNSi_G3dGetResDataByIdx(const NNSG3dResDict *dict, u32 idx)
{
    if (dict != 0 && idx < dict->numEntry) {
        const NNSG3dResDictEntryHdr *hdr = (const NNSG3dResDictEntryHdr *)((const u8 *)dict + dict->ofsEntry);
        return (void *)((const u8 *)(hdr + 1) + hdr->sizeUnit * idx);
    } else {
        return 0;
    }
}

/*
 * NitroSystem g3d resource-dictionary lookup by 16-byte name, returning the
 * entry's DATA POINTER (0 when absent); shape of NNS_G3dGetResDataByName.
 * The same body as src/matched/NNS_G3dGetResDictIdxByName.c (the index variant) with the
 * two hits returning through the inlined data accessor
 * (&hdr->data[0] + sizeUnit * idx, the `mla`).  Pinned to ../2.0/sp2 for the
 * same reason: only 2.0 strength-reduces the scan's name pointer.  Derived
 * from the 7EC source and EXACT on the first compile.
 */
void *NNS_G3dGetResDataByName(const NNSG3dResDict *dict, const NNSG3dResName *name)
{
    if (name == 0)
        return 0;
    if (dict->numEntry < 16) {
        u32 i;
        u32 val0 = name->val[0];
        u32 val1 = name->val[1];
        u32 val2 = name->val[2];
        u32 val3 = name->val[3];
        for (i = 0; i < dict->numEntry; ++i) {
            const NNSG3dResName *p = NNSi_G3dGetResNameByIdx(dict, i);
            if (p->val[0] == val0 && p->val[1] == val1 && p->val[2] == val2 && p->val[3] == val3)
                return NNSi_G3dGetResDataByIdx(dict, i);
        }
    } else {
        const NNSG3dResDictTreeNode *base = (const NNSG3dResDictTreeNode *)(dict + 1);
        u32 n = base->idxLeft;
        if (n != 0) {
            const NNSG3dResName *p;
            const NNSG3dResDictTreeNode *x = &base[n];
            u32 bitPrev = base->refBit;
            s32 bit = base[n].refBit;
            u32 idx;
            while (bitPrev > bit) {
                n = (&x->idxLeft)[(name->val[bit >> 5] >> (bit & 31)) & 1];
                bitPrev = x->refBit;
                bit = base[(&x->idxLeft)[(name->val[bit >> 5] >> (bit & 31)) & 1]].refBit;
                x = &base[n];
            }
            idx = x->idxEntry;
            p = NNSi_G3dGetResNameByIdx(dict, x->idxEntry);
            if (p->val[0] == name->val[0] && p->val[1] == name->val[1] &&
                p->val[2] == name->val[2] && p->val[3] == name->val[3])
                return NNSi_G3dGetResDataByIdx(dict, idx);
        }
    }
    return 0;
}

/*
 * NitroSystem g3d resource-dictionary lookup by 16-byte name, returning the
 * entry INDEX (-1 when absent): linear scan below 16 entries, Patricia-trie
 * descent otherwise.  Shape of NNS_G3dGetResDictIdxByName.
 *
 * Compiler pin: ../2.0/sp2.  dsi/1.1p1 never strength-reduces the scan's
 * `name + i` into the separate +0x10 induction register the image keeps in
 * r4 (it emits `add rN, base, i, lsl #4` and is 356 bytes); 2.0 does.
 * Levers: `u32 i` declared BEFORE the four key words (otherwise the four-word
 * ldm splits into ldm + ldr); guard polarity `dict != 0 && idx < count`
 * (compute arm falls through); the bit index is SIGNED (asr #5) while the
 * refBit compare is unsigned.  The trie body keeps the child
 * index spelled out twice (declaration order idx/x, expanded idx and n),
 * value-preserving: the child index is re-spelled in the `bit` update rather than read back
 * from `n`, which is what gives the child the r4 colour.
 */
s32 NNS_G3dGetResDictIdxByName(const NNSG3dResDict *dict, const NNSG3dResName *name)
{
    if (name == 0)
        return -1;
    if (dict->numEntry < 16) {
        u32 i;
        u32 val0 = name->val[0];
        u32 val1 = name->val[1];
        u32 val2 = name->val[2];
        u32 val3 = name->val[3];
        for (i = 0; i < dict->numEntry; ++i) {
            const NNSG3dResName *p = NNSi_G3dGetResNameByIdx(dict, i);
            if (p->val[0] == val0 && p->val[1] == val1 && p->val[2] == val2 && p->val[3] == val3)
                return (s32)i;
        }
    } else {
        const NNSG3dResDictTreeNode *base = (const NNSG3dResDictTreeNode *)(dict + 1);
        u32 n = base->idxLeft;
        if (n != 0) {
            const NNSG3dResName *p;
            const NNSG3dResDictTreeNode *x = &base[n];
            u32 bitPrev = base->refBit;
            s32 bit = base[n].refBit;
            u32 idx;
            while (bitPrev > bit) {
                n = (&x->idxLeft)[(name->val[bit >> 5] >> (bit & 31)) & 1];
                bitPrev = x->refBit;
                bit = base[(&x->idxLeft)[(name->val[bit >> 5] >> (bit & 31)) & 1]].refBit;
                x = &base[n];
            }
            idx = x->idxEntry;
            p = NNSi_G3dGetResNameByIdx(dict, x->idxEntry);
            if (p->val[0] == name->val[0] && p->val[1] == name->val[1] &&
                p->val[2] == name->val[2] && p->val[3] == name->val[3])
                return (s32)idx;
        }
    }
    return -1;
}

/* NNS_G3dGetMdlSet: the file header plus the offset of its first block. */
int NNS_G3dGetMdlSet(int pFile){ return (pFile + *(int *)((pFile + (((NNSG3dResFileHeader *)pFile)->headerSize << 0)))); }

/*
 * NNS_G3dGetTex: the texture block of a model file (BMD0) or texture file
 * (BTX0). The halfword at +12 is the offset of the block offset table and
 * the halfword at +14 is the block count (1 = a file that holds one block:
 * the BTX0 form, when the magic matches).
 */
unsigned char *NNS_G3dGetTex(unsigned char *pFile)
{
    unsigned char *pBlockOffsets = pFile + ((NNSG3dResFileHeader *)pFile)->headerSize;

    if (((NNSG3dResFileHeader *)pFile)->numDataBlocks == 1) {
        if (((NNSG3dResFileHeader *)pFile)->signature == BTX0_SIGNATURE)
            return pFile + ((NNSG3dResBlockOffsets *)pBlockOffsets)->ofsBlock0;
        return 0;
    }
    return pFile + ((NNSG3dResBlockOffsets *)pBlockOffsets)->ofsBlock1;
}

/*
 * NNS_G3dGetAnmByIdx: look up the resource number resIdx of the first block
 * of an animation file through its dictionary; resIdx is reused for the
 * dictionary record address (the register allocation depends on it).
 */
u8 *NNS_G3dGetAnmByIdx(u8 *pFile, u32 resIdx)
{
    u8 *pBlock;
    u8 *pDict;
    u32 ofsEntry;

    if (pFile == 0)
        goto ret0;
    pBlock = pFile + *(u32 *)(pFile + ((NNSG3dResFileHeader *)pFile)->headerSize);
    pDict = pBlock + 8;
    if (pDict == 0)
        goto fail;
    if (resIdx >= ((NNSG3dResDictBlock *)pBlock)->numEntry)
        goto fail;
    ofsEntry = ((NNSG3dResDictBlock *)pBlock)->ofsEntry;
    resIdx = *(u16 *)(pDict + ofsEntry) * resIdx + ((u32)pDict + ofsEntry + 4);
    goto end;
fail:
    resIdx = 0;
end:
    if (resIdx != 0)
        return pBlock + ((NNSG3dResDictData *)resIdx)->ofsRes;
ret0:
    return 0;
}
