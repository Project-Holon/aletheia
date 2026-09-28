/*
 * function: func_021C82C0
 * address:  0x021C82C0
 * packet:   pkt_ov111_021C82C0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02048A0C  0x02048A0C  arm
 *   func_02047250  0x02047250  arm
 *   func_02061CA4  0x02061CA4  arm
 *   d_021C8874  0x021C8874  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

typedef struct {
    u8 rev;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy;
    u16 ofsEntry;
} Dict;

typedef struct {
    u16 sizeUnit;
    u16 ofsName;
    u8 data[4];
} DictEntryHdr;

typedef struct {
    u8 pad0[0x2C];
    u8 *plttData;
    u8 pad30[4];
    u16 ofsDict;
} Tex;

extern void *func_02048A0C(void *p, int i);
extern Tex *func_02047250(void *p);
extern void func_02061CA4(int a, const void *src, void *dst, int size);
extern const int d_021C8874[];

static inline void *DictGetByIdx(const Dict *d, u32 idx)
{
    if (d && idx < d->numEntry) {
        const DictEntryHdr *h = (const DictEntryHdr *)((const u8 *)d + d->ofsEntry);
        return (void *)((const u8 *)h->data + h->sizeUnit * idx);
    }
    return 0;
}

static inline const u16 *TexGetPltt(const Tex *t, u32 idx)
{
    if (t && t->ofsDict) {
        return DictGetByIdx((const Dict *)((const u8 *)t + t->ofsDict), idx);
    }
    return 0;
}

void func_021C82C0(Work *p, int idx, int k)
{
    u8 *dst;
    Tex *tex;
    const u16 *e;

    if (k > 2) {
        k = 2;
    }
    dst = p->f170[k]->fC;
    tex = func_02047250(func_02048A0C(p->fF8, 0));
    e = TexGetPltt(tex, idx);
    func_02061CA4(1, tex->plttData + *e * 8, dst + d_021C8874[idx] * 32, 0x20);
}
