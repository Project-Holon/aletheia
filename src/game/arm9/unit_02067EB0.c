/*
 * file:     unit_02067EB0.c
 * unit:     yes
 * function: NNSi_G2dFontGetGlyphIndexFromCMap, NNS_G2dFontInitUTF16, NNS_G2dFontGetGlyphIndex
 * address:  0x02067EB0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020698F8    0x020698F8  arm
 *   NNSi_G2dReadCharUTF16    0x02069C00  arm
 *   NNSi_G2dFontGetGlyphIndexFromCMap  0x02067EB0  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct FontCMapEntry {
    u16 charCode;
    u16 glyphIndex;
};

struct FontCMap {
    u16 firstCode;          /* 0x0 */
    u16 pad_02;
    u16 type;               /* 0x4 */
    u16 pad_06;
    u8 pad_08[4];
    union {
        u16 offset;         /* 0xc */
        u16 glyphIndices[1]; /* 0xc */
        u16 count;          /* 0xc */
    };
    u16 pad_0e;
    struct FontCMapEntry entries[]; /* 0xe */
};

struct FontCMapRange {
    u16  firstCode;    /* 0x00 */
    u16  lastCode;    /* 0x02 */
    u8   pad_04[4];
    struct FontCMapRange *next;   /* 0x08 */
};

struct FontGlyphMap {
    u8          pad_00[0x10];
    struct FontCMapRange *chain;  /* 0x10 */
};

extern void func_020698F8(u32 pResource, void *pFont);
extern u32 NNSi_G2dFontGetGlyphIndexFromCMap(struct FontCMap *tbl, u32 charCode);
void NNS_G2dFontInitUTF16(void *pFont, u32 pResource);
extern u8 NNSi_G2dReadCharUTF16[];


u32 NNSi_G2dFontGetGlyphIndexFromCMap(struct FontCMap *tbl, u32 charCode)
{
    u32 ret = 0xFFFF;
    u16 type = tbl->type;

    switch (type) {
    case 0:
        {
            u32 diff = charCode - tbl->firstCode;
            ret = (u16)(tbl->offset + diff);
        }
        break;
    case 1:
        ret = *(u16 *)((u8 *)tbl + 0xc + (charCode - tbl->firstCode) * 2);
        break;
    case 2:
        {
            struct FontCMapEntry *low = (struct FontCMapEntry *)((u8 *)tbl + 0xe);
            struct FontCMapEntry *high = low + (tbl->count - 1);

            while (low <= high) {
                struct FontCMapEntry *mid = low + (high - low) / 2;

                if (mid->charCode < charCode) {
                    low = mid + 1;
                } else if (charCode < mid->charCode) {
                    high = mid - 1;
                } else {
                    ret = mid->glyphIndex;
                    break;
                }
            }
        }
        break;
    }

    return ret;
}


/*
 * Blocking class: label.  Every concrete byte is right; both relocation sites are
 * unresolved and both for the same reason: the `bl func_020698F8` at 0x02067F88 is
 * the only branch to 0x020698F8 in the image, and the pool word that stores
 * 0x02069C00 as a value (+0x20) is the only reference to that address anywhere, so
 * neither `label` nor `literal` has a witness outside this file's 32 bytes.
 */
void NNS_G2dFontInitUTF16(void *pFont, u32 pResource)
{
    func_020698F8(pResource, pFont);
    ((u32 *)pFont)[1] = (u32)NNSi_G2dReadCharUTF16;
}


/*
 * Range lookup over a singly linked list of key records: walk the chain hung
 * off (*a0)->f10 and hand the first record whose [lo, hi] halfword pair
 * contains `key` to NNSi_G2dFontGetGlyphIndexFromCMap, which returns the mapped word.  No record
 * holds the key: return the pooled 0xFFFF sentinel.  The record's link is at
 * +0x04 (used by the twin at 0x02067FE4) while the chain head here is the
 * +0x10 field of the object the caller's pointer points at.
 *
 * The half-open test is ONE conjunction (`key >= lo && key <= hi`): the
 * original's `ldrhls`/`cmpls` pair is the second comparison issued
 * conditionally on the first, which is a `&&`, not two nested guards.
 */
u32 NNS_G2dFontGetGlyphIndex(struct FontGlyphMap **ppMap, u32 charCode)
{
    struct FontCMapRange *range = (*ppMap)->chain;

    while (range != 0) {
        if (range->firstCode <= charCode && charCode <= range->lastCode) {
            return NNSi_G2dFontGetGlyphIndexFromCMap((struct FontCMap *)range, charCode);
        }
        range = range->next;
    }

    return 0xffff;
}
