/*
 * unit:     yes
 * address:  0x0201C314
 * packet:   pkt_0201BD28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WAZA_TOOL_IsDamaging
 *
 * A boolean wrapper around WAZA_TOOL_GetParam (see src/matched/unit_0201C1C8.c),
 * id 3 again, this time reduced to 0/1 rather than truncated to a halfword.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C314.c \
 *       --addr 0x0201C314 --thumb
 *
 * symbols:
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 */

typedef unsigned int u32;

extern u32 WAZA_TOOL_GetParam(void *p, u32 id);

u32 WAZA_TOOL_IsDamaging(void *p)
{
    if (WAZA_TOOL_GetParam(p, 3) == 0) {
        return 0;
    }
    return 1;
}
