/*
 * file:     field_ground_anime_p05.c
 * unit:     yes
 * function: func_021A79E4, func_021A7A28, func_021A7A34
 * address:  0x021A79E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02047250  0x02047250  arm
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
    u8 pad00[0x14];
    u32 f14;
    u8 pad18[0x3C - 0x18];
    Dict dict;
} Res;

typedef signed short   s16;

typedef signed char    s8;

extern Res *func_02047250(void *p);
u8 *func_021A79E4(void *a, u32 idx);
int func_021A7A28(u32 a, u32 b);
int func_021A7A34(u32 a, u32 b);


static inline void *DictGetByIdx(const Dict *d, u32 idx)
{
    if (d && idx < d->numEntry) {
        const DictEntryHdr *h = (const DictEntryHdr *)((const u8 *)d + d->ofsEntry);
        return (void *)((const u8 *)h->data + h->sizeUnit * idx);
    }
    return 0;
}


u8 *func_021A79E4(void *a, u32 idx)
{
    Res *r;
    u32 *e;

    r = func_02047250(a);
    e = r ? DictGetByIdx(&r->dict, idx) : 0;
    return (u8 *)r + r->f14 + ((*e & 0xFFFF) << 3);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A7A28(u32 a, u32 b)
{
return (a + *(u32 *)((u8 *)((a + (b << 3))) + 4));
}


int func_021A7A34(u32 a, u32 b)
{
return (a + *(u32 *)((u8 *)((a + (b << 3))) + 8));
}
