/*
 * function: func_0206BEA0
 * address:  0x0206BEA0
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NNSi_G3dFuncSbc_MAT: the SBC MAT opcode (2 bytes). Gate on rs->flag (0x200 skip; bit 0 / bit 3 plus
 * rs->currentMat at +0xad decide whether the material is re-sent), look the
 * material up in rs->pResMat (+0xd8, dictionary at +4) and dispatch through
 * the material-type table on its item tag with (rs, opt, mat, idxMat).
 *
 * IDENTIFICATION: this cluster is the NitroSystem G3D SBC interpreter (sbc.c).
 * The two things that closed it after 29 bytes of register tie: (1) handlers
 * take (rs, opt) and the dispatched function takes FOUR arguments
 * (rs, opt, data, idx), which pins data in r2 and idx in r3 across the blx;
 * (2) the lookup is the two NNS inline accessors (NNS_G3dGetResDataByIdx and
 * the Get*DataByIdx wrapper that null-tests the resource itself), written as
 * static inline, which reproduces the doubled zero arm without gotos.
 * Byte-identical under dsi/1.1p1 as well; pinned ../2.0/sp2 with the cluster.
 *
 * symbols:
 *   tbl_020A82C8   0x020A82C8  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8  revision;
    u8  numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
} Dict;

typedef struct {
    u16 sizeUnit;
    u16 sizeHeader;
} DictEntryHeader;

typedef struct {
    u16 ofsDictTexToMatList;
    u16 ofsDictPlttToMatList;
    Dict dict;
} ResMat;

typedef struct {
    u16 tag;
    u16 size;
} ItemTag;

typedef struct Ctx {
    u8  *c;
    u32 p04;
    u32 flag;
    u8  p0c[0xad - 0x0c];
    u8  currentMat;
    u8  pad[0xd8 - 0xae];
    ResMat *pResMat;
} Ctx;

extern void (*tbl_020A82C8[])(Ctx *, u32, const ItemTag *, u32);

static inline void *GetResDataByIdx(const Dict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const DictEntryHeader *hdr = (const DictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (void *)((u32)hdr + sizeof(DictEntryHeader) + hdr->sizeUnit * idx);
    }
    return 0;
}

static inline const ItemTag *GetMatDataByIdx(const ResMat *mat, u32 idx)
{
    if (mat) {
        const u32 *data = (const u32 *)GetResDataByIdx(&mat->dict, idx);
        if (data)
            return (const ItemTag *)((u8 *)mat + *data);
    }
    return 0;
}

void func_0206BEA0(Ctx *rs, u32 opt)
{
    if (!(rs->flag & 0x200)) {
        u32 idxMat = *(rs->c + 1);
        if ((rs->flag & 1) || !(rs->flag & 8) || idxMat != rs->currentMat) {
            const ItemTag *mat = GetMatDataByIdx(rs->pResMat, idxMat);
            (*tbl_020A82C8[mat->tag])(rs, opt, mat, idxMat);
        }
    }
    rs->c += 2;
}
