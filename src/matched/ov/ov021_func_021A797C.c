/*
 * function: func_021A797C
 * address:  0x021A797C
 * packet:   pkt_ov021_021A797C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047250  0x02047250  arm
 *   func_0209C2B0  0x0209C2B0  arm
 *   d_021D8B08     0x021D8B08  data  a2
 *   d_021D8B00     0x021D8B00  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Dict {
    u8 rev;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy;
    u16 ofsEntry;
} Dict;

typedef struct DictEntryHdr {
    u16 sizeUnit;
    u16 ofsName;
    u8 data[4];
} DictEntryHdr;

typedef struct Res {
    u8 pad00[0x3C];
    Dict dict;
} Res;

extern Res *func_02047250(void *p);
extern u32 func_0209C2B0(u32 a, u32 b);
extern const u16 d_021D8B08[];
extern const u8 d_021D8B00[];

static inline void *DictGetByIdx(const Dict *d, u32 idx)
{
    if (d && idx < d->numEntry) {
        const DictEntryHdr *h = (const DictEntryHdr *)((const u8 *)d + d->ofsEntry);
        return (void *)((const u8 *)h->data + h->sizeUnit * idx);
    }
    return 0;
}

u32 func_021A797C(void *a, u32 idx)
{
    Res *r;
    u32 *e;
    u32 v;

    r = func_02047250(a);
    e = r ? DictGetByIdx(&r->dict, idx) : 0;
    v = *e;
    return func_0209C2B0(d_021D8B08[(v & 0x700000) >> 20] * d_021D8B08[(v & 0x3800000) >> 23], d_021D8B00[(v & 0x1C000000) >> 26]);
}
