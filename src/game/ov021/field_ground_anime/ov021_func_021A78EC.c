/*
 * function: func_021A78EC
 * address:  0x021A78EC
 * packet:   pkt_ov021_021A78EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047250  0x02047250  arm
 *   func_0206E7EC  0x0206E7EC  arm
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
    u8 pad00[8];
    u32 f08;
    u8 pad0C[0x3C - 0x0C];
    Dict dict;
} Res;

extern Res *func_02047250(void *p);
extern int func_0206E7EC(const Dict *d, const void *name);

static inline void *DictGetByIdx(const Dict *d, u32 idx)
{
    if (d && idx < d->numEntry) {
        const DictEntryHdr *h = (const DictEntryHdr *)((const u8 *)d + d->ofsEntry);
        return (void *)((const u8 *)h->data + h->sizeUnit * idx);
    }
    return 0;
}

static inline void *DictGetNameByIdx(const Dict *d, u32 idx)
{
    if (d && idx < d->numEntry) {
        const DictEntryHdr *h = (const DictEntryHdr *)((const u8 *)d + d->ofsEntry);
        return (void *)((const u8 *)h + h->ofsName + idx * 16);
    }
    return 0;
}

int func_021A78EC(void *a, void *b, u32 idx)
{
    Res *ra;
    Res *rb;
    void *name;
    int k;
    u32 *e;

    ra = func_02047250(a);
    rb = func_02047250(b);
    name = rb ? DictGetNameByIdx(&rb->dict, idx) : 0;
    if (ra) {
        k = func_0206E7EC(&ra->dict, name);
    } else {
        k = -1;
    }
    if (k < 0) {
        return -1;
    }
    e = ra ? DictGetByIdx(&ra->dict, k) : 0;
    return ((*e << 16) >> 13) + ((ra->f08 << 16) >> 13);
}
