/*
 * function: func_0201DB20
 * address:  0x0201DB20
 * packet:   pkt_0201DB20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
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
#include "../include/Obj07086.h"

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

struct Font {
    u8  pad00[0x68];
    u8 *unk68;
    u32 pad6C;
    u16 unk70;
    u8  pad72[0x16];
    u8 *unk88;
};

u32 func_0201DB20(struct Font *f, u16 c)
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
