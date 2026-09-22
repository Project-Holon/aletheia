/*
 * function: func_0206A4AC
 * address:  0x0206A4AC
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
 *   func_0206A3CC  0x0206A3CC  arm
 *
 * NitroSystem G3D NNS_G3dBindMdlPltt(mdl, tex): the palette twin of
 * func_0206A2CC.  Walks the pltt-to-material dictionary, looks each name up in
 * the texture's palette dictionary (tex + plttInfo.ofsDict at +0x34, only when
 * that offset is non-zero), binds through func_0206A3CC.  Same closing lever
 * as func_0206A2CC (GetMat as an if/return inline).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206A4AC.c
 *       --func func_0206A4AC --addr 0x0206A4AC --arm --cc ../2.0/sp2
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
typedef struct { u8 pad[0x34]; u16 ofsPlttDict; } ResTex;
typedef struct { u16 offset; u8 numIdx; u8 flag; } PlttToMatIdx;

extern void *func_0206E62C(const ResDict *dict, const ResName *name);
extern void func_0206A3CC(ResMat *mat, PlttToMatIdx *data, const ResTex *tex, void *plttData);

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

static inline void *GetPlttDataByName(const ResTex *tex, const ResName *name)
{
    if (tex && tex->ofsPlttDict != 0)
        return func_0206E62C((const ResDict *)((const u8 *)tex + tex->ofsPlttDict), name);
    return 0;
}

BOOL func_0206A4AC(ResMdl *pMdl, const ResTex *pTex)
{
    ResMat *mat;
    ResDict *dict;
    u32 i;
    BOOL result = 1;

    mat = GetMat(pMdl);
    dict = (ResDict *)((u8 *)mat + mat->ofsDictPlttToMatList);

    for (i = 0; i < dict->numEntry; ++i) {
        const ResName *name = GetResNameByIdx(dict, i);
        void *plttData = GetPlttDataByName(pTex, name);
        if (plttData) {
            PlttToMatIdx *data = (PlttToMatIdx *)GetResDataByIdx(dict, i);
            if (!(data->flag & 1))
                func_0206A3CC(mat, data, pTex, plttData);
        } else {
            result = 0;
        }
    }
    return result;
}
