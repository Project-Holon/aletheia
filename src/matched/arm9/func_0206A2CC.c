/*
 * function: func_0206A2CC
 * address:  0x0206A2CC
 * packet:   pkt_0206A17C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206E62C  0x0206E62C  arm
 *   func_0206A19C  0x0206A19C  arm
 *
 * NitroSystem G3D NNS_G3dBindMdlTex(mdl, tex): for every entry of the
 * material block's tex-to-material dictionary, looks the entry's name up in
 * the texture's dictionary (func_0206E62C = NNS_G3dGetResDataByName, dict at
 * tex + 0x3c) and, when found and not already bound (flag bit 0), binds it
 * through func_0206A19C; returns FALSE if any name was missing.
 *
 * WHAT CLOSED IT: the 9-byte r8/sb swap (base vs name-stride accumulator)
 * that 2285 permuter compiles could not move was the SPELLING OF
 * NNS_G3dGetMat: a static inline written as an if/return with a trailing
 * `return 0;` -- the same guard as a ternary gives the swap.  Everything else
 * is the real NitroSystem shape: GetResNameByIdx / GetResDataByIdx inlines
 * over the ResDict, BOOL result initialised at declaration.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206A2CC.c
 *       --func func_0206A2CC --addr 0x0206A2CC --arm --cc ../2.0/sp2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

typedef struct { u8 revision; u8 numEntry; u16 sizeDictBlk; u16 dummy_; u16 ofsEntry; } ResDict;
typedef struct { u16 sizeUnit; u16 sizeTotal; u8 data[4]; } ResDictEntryHeader;
typedef struct { u8 name[16]; } ResName;
typedef struct { u16 ofsDictTexToMatList; u16 ofsDictPlttToMatList; ResDict dict; } ResMat;
typedef struct { u32 sig; u32 size; u32 ofsMat; } ResMdl;
typedef struct { u8 pad[0x3c]; ResDict dict; } ResTex;
typedef struct { u16 offset; u8 numIdx; u8 flag; } TexToMatIdx;

extern void *func_0206E62C(const ResDict *dict, const ResName *name);
extern void func_0206A19C(ResMat *mat, TexToMatIdx *data, const ResTex *tex, void *texData);

static inline ResMat *GetMat(ResMdl *mdl)
{
    if (mdl != 0 && mdl->ofsMat != 0) return (ResMat *)((u8 *)mdl + mdl->ofsMat);
    return 0;
}

static inline void *GetResDataByIdx(const ResDict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const ResDictEntryHeader *hdr = (const ResDictEntryHeader *)((const u8 *)dict + dict->ofsEntry);
        return (void *)((const u8 *)hdr + 4 + hdr->sizeUnit * idx);
    }
    return 0;
}

static inline const ResName *GetResNameByIdx(const ResDict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const ResDictEntryHeader *hdr = (const ResDictEntryHeader *)((const u8 *)dict + dict->ofsEntry);
        return (const ResName *)((const u8 *)hdr + hdr->sizeTotal) + idx;
    }
    return 0;
}

static inline void *GetTexDataByName(const ResTex *tex, const ResName *name)
{
    if (tex)
        return func_0206E62C(&tex->dict, name);
    return 0;
}

BOOL func_0206A2CC(ResMdl *pMdl, const ResTex *pTex)
{
    ResMat *mat;
    ResDict *dict;
    u32 i;
    BOOL result = 1;

    mat = GetMat(pMdl);
    dict = (ResDict *)((u8 *)mat + mat->ofsDictTexToMatList);

    for (i = 0; i < dict->numEntry; ++i) {
        const ResName *name = GetResNameByIdx(dict, i);
        void *texData = GetTexDataByName(pTex, name);
        if (texData) {
            TexToMatIdx *data = (TexToMatIdx *)GetResDataByIdx(dict, i);
            if (!(data->flag & 1))
                func_0206A19C(mat, data, pTex, texData);
        } else {
            result = 0;
        }
    }
    return result;
}
