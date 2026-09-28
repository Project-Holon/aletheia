/*
 * function: func_0206A3CC
 * address:  0x0206A3CC
 * packet:   pkt_0206A17C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem G3D bindMdlPltt_Internal_ (static helper of
 * NNS_G3dBindMdlPltt, func_0206A4AC): for every material index in a
 * pltt-to-material bind record, stores plttBase + (plttInfo.vramKey address)
 * into the material's texPlttBase, both halved when the palette is not a
 * 4-colour one (flag bit 0 clear); marks the record bound.
 *
 * WHAT CLOSED IT: the 2-byte lsr/ldrh r4/r5 swap (2315 permuter compiles and
 * 28 hand spellings flat) was in the DECLARATIONS: plttBase and vramOffset
 * as u16 locals, vramOffset = (u16)(NNS_GfdGetPlttKeyAddr(key) >> 3) with the
 * key-address helper as an inline ((key & 0xffff) << 3), and the material
 * lookup as the NNS_G3dGetMatDataByIdx inline with an `if (mat)` guard.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206A3CC.c
 *       --func func_0206A3CC --addr 0x0206A3CC --arm --cc ../2.0/sp2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u8 revision; u8 numEntry; u16 sizeDictBlk; u16 dummy_; u16 ofsEntry; } ResDict;
typedef struct { u16 sizeUnit; u16 sizeTotal; u8 data[4]; } ResDictEntryHeader;
typedef struct { u16 ofsTex; u16 ofsPltt; ResDict dict; } ResMat;
typedef struct { u8 pad[0x2c]; u32 vramKey; } ResTex;
typedef struct { u16 offset; u8 numIdx; u8 flag; } PlttToMatIdx;
typedef struct { u16 offset; u16 flag; } PlttData;
typedef struct { u8 pad[0x1c]; u16 texPlttBase; } MatData;

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

static inline u32 GetPlttKeyAddr(u32 key)
{
    return (u32)((key & 0xffff) << 3);
}

void func_0206A3CC(ResMat *pMat, PlttToMatIdx *pBindData, const ResTex *pTex, const PlttData *pPlttData)
{
    u8 *base;
    u16 plttBase;
    u16 vramOffset;
    u32 j;

    base = (u8 *)pMat + pBindData->offset;
    plttBase = pPlttData->offset;
    vramOffset = (u16)(GetPlttKeyAddr(pTex->vramKey) >> 3);

    if (!(pPlttData->flag & 1)) {
        plttBase >>= 1;
        vramOffset >>= 1;
    }
    for (j = 0; j < pBindData->numIdx; ++j) {
        MatData *matData = GetMatDataByIdx(pMat, base[j]);
        matData->texPlttBase = (u16)(plttBase + vramOffset);
    }
    pBindData->flag |= 1;
}
