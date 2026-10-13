/*
 * function: GF_FONT_GetProportionalWidth
 * address:  0x0201DC88
 * packet:   pkt_0201DC88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * gf_font.c streamed-glyph lookup: classify glyph `id` through a
 * 2-bit-per-glyph table, fall back to a 9-bit hash, then walk a run of
 * variable-length records for a matching 2-byte code.  See
 * docs/notes/GF_FONT_GetProportionalWidth.c.txt for the full structural derivation.
 *
 * No relocations: every table is reached through offsets stored in the
 * resource header at obj+0x84.
 *
 * EXACT*, not EXACT: GF_FONT_GetFixedWidth immediately after this one is an
 * unlabelled leaf, so the inferred extent runs long (240 vs 208).  Report
 * the unlabelled follower at 0x0201DD58 rather than editing
 * layout/function_starts.txt.
 *
 * The closing lever (2026-09-21): the record header must be read with a
 * fused post-increment, `cnt = *p++;`.  Spelling it as the two statements
 * `cnt = *p; p++;` swaps the cursor and the scan counter between r2 and r3
 * for the whole tail, which is the 17-byte residue the note records.
 */
#include "../include/Obj11722.h"
typedef unsigned char  u8;
typedef signed   char  s8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Hdr0201DC88 {
    u8  dflt[3];
    u8  pad3;
    u32 bits;       /* +4 */
    u32 hash;       /* +8 */
    u32 chain;      /* +0xc */
};

u8 GF_FONT_GetProportionalWidth(u8 *obj, u32 id)
{
    struct Hdr0201DC88 *h = *(struct Hdr0201DC88 * *)&((struct Obj11722 *)obj)->f84;
    u32 i = id * 2;
    u8  b = ((u8 *)h + h->bits)[i >> 3];
    u8  k = (u8)((b >> (6 - (i & 7))) & 3);
    u16 slot;
    s8  e;
    u16 n;
    u8 *p;
    u8  cnt;
    u8  idx;

    if (k < 3)
        return ((u8 *)h)[k];

    slot = (u16)(((id & 0x1ff) ^ (u16)(((((id >> 12) ^ (id >> 11)) ^ (id >> 10)) ^ (id >> 9)) & 1) << 3) & 0x1ff);

    e = ((s8 *)((u8 *)h + h->hash))[slot];
    if (e >= 0)
        return (u8)e;

    n = (u16)((u16)(-e) - 1);
    p = (u8 *)h + h->chain;
    while (n != 0) {
        u8 m = *p;
        u16 d = (u16)(n - 1);
        p += m + m * 2 + 1;
        n = d;
    }

    cnt = *p++;
    idx = 0;
    while (idx < cnt) {
        u16 key = (u16)((p[0] << 8) | p[1]);
        if (id == key)
            return p[2];
        idx = (u8)(idx + 1);
        p += 3;
    }
    return obj[0x5e];
}
