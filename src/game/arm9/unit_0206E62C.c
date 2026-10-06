/*
 * file:     unit_0206E62C.c
 * unit:     yes
 * function: func_0206E62C, func_0206E7EC
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
typedef signed int s32;

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { u32 val[4]; } ResName;

typedef struct { u8 refBit; u8 idxLeft; u8 idxRight; u8 idxEntry; } TreeNode;

typedef struct { u16 sizeUnit; u16 ofsName; u8 data[4]; } EntryHdr;

typedef struct {
    u8  revision;
    u8  numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
    TreeNode node[1];
} ResDict;

void *func_0206E62C(const ResDict *dict, const ResName *name);
s32 func_0206E7EC(const ResDict *dict, const ResName *name);


static inline const ResName *GetResNameByIdx(const ResDict *dict, u32 idx)
{
    if (dict != 0 && idx < dict->numEntry) {
        const EntryHdr *hdr = (const EntryHdr *)((const u8 *)dict + dict->ofsEntry);
        return (const ResName *)((const u8 *)hdr + hdr->ofsName) + idx;
    } else {
        return 0;
    }
}


static inline void *GetResDataByIdx(const ResDict *dict, u32 idx)
{
    if (dict != 0 && idx < dict->numEntry) {
        const EntryHdr *hdr = (const EntryHdr *)((const u8 *)dict + dict->ofsEntry);
        return (void *)((const u8 *)&hdr->data[0] + hdr->sizeUnit * idx);
    } else {
        return 0;
    }
}


/*
 * NitroSystem g3d resource-dictionary lookup by 16-byte name, returning the
 * entry's DATA POINTER (0 when absent); shape of NNS_G3dGetResDataByName.
 * The same body as src/matched/func_0206E7EC.c (the index variant) with the
 * two hits returning through the inlined data accessor
 * (&hdr->data[0] + sizeUnit * idx, the `mla`).  Pinned to ../2.0/sp2 for the
 * same reason: only 2.0 strength-reduces the scan's name pointer.  Derived
 * from the 7EC source and EXACT on the first compile.
 */
void *func_0206E62C(const ResDict *dict, const ResName *name)
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
            const ResName *p = GetResNameByIdx(dict, i);
            if (p->val[0] == val0 && p->val[1] == val1 && p->val[2] == val2 && p->val[3] == val3)
                return GetResDataByIdx(dict, i);
        }
    } else {
        const TreeNode *base = &dict->node[0];
        u32 n = base->idxLeft;
        if (n != 0) {
            const ResName *p;
            const TreeNode *x = &base[n];
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
            p = GetResNameByIdx(dict, x->idxEntry);
            if (p->val[0] == name->val[0] && p->val[1] == name->val[1] &&
                p->val[2] == name->val[2] && p->val[3] == name->val[3])
                return GetResDataByIdx(dict, idx);
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
 * refBit compare is unsigned.  The trie body is permuter output
 * (decl-order(idx<->x); expand(idx x1); expand(n x1)), value-preserving:
 * the child index is re-spelled in the `bit` update rather than read back
 * from `n`, which is what gives the child the r4 colour.
 */
s32 func_0206E7EC(const ResDict *dict, const ResName *name)
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
            const ResName *p = GetResNameByIdx(dict, i);
            if (p->val[0] == val0 && p->val[1] == val1 && p->val[2] == val2 && p->val[3] == val3)
                return (s32)i;
        }
    } else {
        const TreeNode *base = &dict->node[0];
        u32 n = base->idxLeft;
        if (n != 0) {
            const ResName *p;
            const TreeNode *x = &base[n];
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
            p = GetResNameByIdx(dict, x->idxEntry);
            if (p->val[0] == name->val[0] && p->val[1] == name->val[1] &&
                p->val[2] == name->val[2] && p->val[3] == name->val[3])
                return (s32)idx;
        }
    }
    return -1;
}
