/*
 * function: NNSi_G3dBindMdlTexInternal
 * address:  0x0206A19C
 * packet:   pkt_0206A17C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FX_Div  0x0207C768  arm
 *
 * NitroSystem G3D bindMdlTex_Internal_ (static helper of NNS_G3dBindMdlTex,
 * NNS_G3dBindMdlTex): for every material index in a tex-to-material bind record,
 * ORs the texture's TEXIMAGE_PARAM (plus the VRAM key address >> 3) into the
 * material and sets magW/magH to width/origWidth and height/origHeight as
 * fx32 (FX32_ONE fast path, else FX_Div = FX_Div).  The key comes from
 * texInfo.vramKey (+8) or, for a 4x4-compressed texture (texfmt field
 * 0x1c000000 == 5 << 26), tex4x4Info.vramKey (+0x18).
 *
 * WHAT CLOSED IT (open since wave 9, "prologue spill choice"): writing the
 * body in terms of the real NitroSystem types and inlines instead of raw
 * offsets -- NNS_G3dGetMatDataByIdx(mat, idx) as a static inline with an
 * `if (mat)` guard around NNS_G3dGetResDataByIdx(&mat->dict, idx), and
 * NNS_GfdGetTexKeyAddr(key) = (key & 0xffff) << 3 followed by `>> 3` (the
 * pair is what 2.0 folds to the bic #0xe0000000).  EXACT on the first compile.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dBindMdlTexInternal.c
 *       --func NNSi_G3dBindMdlTexInternal --addr 0x0206A19C --arm --cc ../2.0/sp2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int s32;
typedef s32 fx32;

typedef struct { u8 revision; u8 numEntry; u16 sizeDictBlk; u16 dummy_; u16 ofsEntry; } ResDict;
typedef struct { u16 sizeUnit; u16 sizeTotal; u8 data[4]; } ResDictEntryHeader;
typedef struct { u16 ofsDictTexToMatList; u16 ofsDictPlttToMatList; ResDict dict; } ResMat;
typedef struct { u32 sig; u32 size; u32 texVramKey; u8 pad0c[0x0c]; u32 tex4x4VramKey; } ResTex;
typedef struct { u16 offset; u8 numIdx; u8 flag; } TexToMatIdx;
typedef struct { u32 texImageParam; u32 extraParam; } TexData;
typedef struct {
    u16 itemTag; u16 size; u32 diffAmb; u32 specEmi; u32 polyAttr; u32 polyAttrMask;
    u32 texImageParam; u32 texImageParamMask; u16 texPlttBase; u16 flag;
    u16 origWidth; u16 origHeight; fx32 magW; fx32 magH;
} MatData;

extern u32 FX_Div(u32 a, u32 b);

static inline void *GetResDataByIdx(const ResDict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const ResDictEntryHeader *hdr = (const ResDictEntryHeader *)((const u8 *)dict + dict->ofsEntry);
        return (void *)((const u8 *)hdr + 4 + hdr->sizeUnit * idx);
    }
    return 0;
}

static inline MatData *GetMatDataByIdx(ResMat *mat, u32 idx)
{
    if (mat) {
        u32 *data = (u32 *)GetResDataByIdx(&mat->dict, idx);
        if (data)
            return (MatData *)((u8 *)mat + *data);
    }
    return 0;
}

static inline u32 GetTexKeyAddr(u32 key)
{
    return (u32)((key & 0xffff) << 3);
}

void NNSi_G3dBindMdlTexInternal(ResMat *pMat, TexToMatIdx *pBindData, const ResTex *pTex, const TexData *pTexData)
{
    u8 *base;
    u32 vramOffset;
    u32 j;

    base = (u8 *)pMat + pBindData->offset;

    if ((pTexData->texImageParam & 0x1c000000) != 0x14000000)
        vramOffset = GetTexKeyAddr(pTex->texVramKey) >> 3;
    else
        vramOffset = GetTexKeyAddr(pTex->tex4x4VramKey) >> 3;

    for (j = 0; j < pBindData->numIdx; ++j) {
        MatData *matData = GetMatDataByIdx(pMat, base[j]);
        u32 w, h;

        matData->texImageParam |= pTexData->texImageParam + vramOffset;
        w = pTexData->extraParam & 0x7ff;
        h = (pTexData->extraParam & (0x7ff << 11)) >> 11;
        matData->magW = (w == matData->origWidth) ? 0x1000 : FX_Div((fx32)(w << 12), (fx32)(matData->origWidth << 12));
        matData->magH = (h == matData->origHeight) ? 0x1000 : FX_Div((fx32)(h << 12), (fx32)(matData->origHeight << 12));
    }
    pBindData->flag |= 1;
}
