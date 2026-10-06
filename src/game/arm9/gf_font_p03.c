/*
 * file:     gf_font_p03.c
 * unit:     yes
 * function: func_0201DB20, func_0201DBBC
 * address:  0x0201DB20
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0201DC44  0x0201DC44  thumb
 */
#include "../../matched/include/Obj07086.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct CMap {
    u16 ccodeBegin;
    u16 ccodeEnd;
    u16 mappingMethod;
    u16 reserved;
    struct CMap *pNext;
    u16 mapInfo[1];
};

struct Font_0201DB20 {
    u8  pad00[0x68];
    u8 *unk68;
    u32 pad6C;
    u16 unk70;
    u8  pad72[0x16];
    u8 *unk88;
};

struct Font_0201DBBC {
    u32   format;
    u32   measure;
    u32   decode;
    u8   *body;
    u8    pad10[0x40];
    void *handle;
    u8    pad54[0x22];
    u16   mapSize;
    u8    pad78[4];
    u16   lastCols;
    u8    tilesW;
    u8    tilesH;
    void *resHdr;
    void *bodyBuf;
    void *charMap;
    void *glyphDir;
    void *scratch;
};

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_0201DC44(struct Font_0201DBBC *f, const u8 *g, u32 w, void *d, u8 *out);


/*
 * gf_font.c's character-to-glyph-index lookup: NitroSystem's character-map
 * search (NNSG2dFontCodeMap: ccodeBegin, ccodeEnd, mappingMethod, reserved,
 * pNext, mapInfo[]) walked Game Freak style.  The chain pointer is stored as
 * an address in the resource file and is rebased from the load address
 * (+0x68) onto the copy (+0x88); +0x70 is the font's default glyph.  Method
 * 0 is a direct run, 1 a table, 2 a binary search over (code, index) pairs.
 *
 * Two details closed it (docs/notes/sub_0201DB20.c.txt has every
 * measurement):
 *
 *   - the rebase re-reads +0x88 as `*(u8 **)((u8 *)f + 0x88)`, so it is not
 *     CSE'd with the first read (wave 15, 139 -> 15 bytes out);
 *   - the chain step goes through a second pointer local `n` and ends in the
 *     copy `m = n;`.  When m's loop-carried definition is an arithmetic
 *     result (`m = rebase(m)`, even `m = m + 4`), mwcc colours m after every
 *     other local whatever the declaration order, and m takes r6.  With the
 *     copy, m, lo and hi colour in declaration order, which is the image's
 *     m r4, lo r5, hi r6 (wave 21 lane F2, 15 -> 0).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DB20.c \
 *       --func func_0201DB20 --addr 0x0201DB20 --cc 1.1p1 --thumb
 */
u32 func_0201DB20(struct Font_0201DB20 *f, u16 c)
{
    struct CMap *m;
    s32 lo;
    s32 hi;
    struct CMap *n;

    m = (struct CMap *)f->unk88;
    for (;;) {
        if (m->ccodeBegin <= c && m->ccodeEnd >= c) {
            switch (m->mappingMethod) {
            case 0:
                return m->mapInfo[0] + (c - m->ccodeBegin);
            case 1:
                return m->mapInfo[(u16)(c - m->ccodeBegin)];
            case 2: {
                lo = 0;
                hi = m->mapInfo[0] - 1;
                while (lo <= hi) {
                    s32 mid = lo + (hi - lo) / 2;
                    s32 j = 2 * mid + 1;
                    if (m->mapInfo[j] < c)
                        lo = mid + 1;
                    else if (c < m->mapInfo[j])
                        hi = mid - 1;
                    else
                        return m->mapInfo[j + 1];
                }
                break;
            }
            }
            return f->unk70;
        }
        n = m->pNext;
        if (n != 0)
            n = (struct CMap *)(*(u8 * *)&((struct Obj07086 *)f)->f88 + ((u8 *)n - f->unk68));
        else
            return 0;
        m = n;
    }
}


/*
 * gf_font.c's glyph fetch for a preloaded font: copy glyph record i
 * (mapSize bytes) out of the resident body into the scratch buffer, then
 * hand it to func_0201DC44 with the last-tile column count.
 *
 * The lever (wave 16) is `const` on the font parameter, which is only read
 * here.  With a plain pointer the outgoing stack argument `out` was stored
 * third in the final call's setup; with `const struct Font *` it is stored
 * last, as in the image (12 bytes out before, every spelling and 3000
 * permuter compiles flat: docs/notes/sub_0201DBBC.c.txt).  Field names
 * follow docs/families/gf_font.h.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DBBC.c \
 *       --func func_0201DBBC --addr 0x0201DBBC --cc 1.1p1 --thumb
 */
void func_0201DBBC(const struct Font_0201DBBC *f, u32 i, void *d, u8 *out)
{
    MI_CpuCopy8(f->body + i * f->mapSize, f->scratch, f->mapSize);
    func_0201DC44((struct Font_0201DBBC *)f, f->scratch, f->lastCols, d, out);
}
