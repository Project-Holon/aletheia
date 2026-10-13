/*
 * function: ZONEDATA_IsSameMatrixGroup
 * address:  0x02013E90
 * packet:   pkt_02013E90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_GetMatrixId  0x02013B44  thumb
 *
 * "Do these two zones share a region?": both ids are reduced through
 * ZONEDATA_GetMatrixId, the accessor for record +0x04, and the two results compared.
 * The +0x04 lane is therefore a grouping key rather than a per-zone index,
 * which agrees with the data: 238 distinct values over 427 records.
 *
 * On top of plain equality, 0 and 0xaf are treated as the same group in either
 * order.  That is a hard-coded pair of content constants, not a computed one,
 * and is exactly the kind of value that may differ in White; nothing here
 * reads a version identifier.
 *
 * The equality test is one `if` with its own return, and the special case is a
 * single disjunction afterwards: writing the special case as two separate
 * `if`s gives each its own epilogue instead of the shared one the original
 * has (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ZONEDATA_IsSameMatrixGroup.c \
 *       --func ZONEDATA_IsSameMatrixGroup --addr 0x02013E90 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 ZONEDATA_GetMatrixId(u32 id);

u32 ZONEDATA_IsSameMatrixGroup(u32 a, u32 b)
{
    u32 ga = ZONEDATA_GetMatrixId(a);
    u32 gb = ZONEDATA_GetMatrixId(b);

    if (ga == gb)
        return 1;
    if ((ga == 0 && gb == 0xaf) || (ga == 0xaf && gb == 0))
        return 1;
    return 0;
}
