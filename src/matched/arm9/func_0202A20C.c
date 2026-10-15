/*
 * function: TPOKE_DATA_GetEntryIndex
 * address:  0x0202A20C
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Returns TPOKE_DATA_FindEntryIndex's result, clamped to zero when negative.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TPOKE_DATA_GetEntryIndex.c \
 *       --func TPOKE_DATA_GetEntryIndex --addr 0x0202A20C --thumb --cc 1.1p1
 *
 * Closed by the `matched` class: 0x0202A1CC was filed as an EXACT entry this
 * wave (pkt_0202A19C) with the struct-container spelling of the bounded scan.
 *
 * symbols:
 *   TPOKE_DATA_FindEntryIndex  0x0202A1CC  thumb
 */

typedef unsigned char u8;
typedef signed int    s32;
typedef unsigned int  u32;

struct Container;
extern u32 TPOKE_DATA_FindEntryIndex(const struct Container *c, u32 key, u32 v2, u32 v3);

u32 TPOKE_DATA_GetEntryIndex(u8 *p, u32 key, u32 v2, u32 v3)
{
    s32 r = TPOKE_DATA_FindEntryIndex((const struct Container *)p, key, v2, v3);

    return r < 0 ? 0u : (u32)r;
}
