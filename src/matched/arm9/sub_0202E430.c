/*
 * unit:     no
 * function: PMS_DRAW_GetFrameSurface
 * address:  0x0202E430
 * packet:   pkt_0202DBC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twelve bytes, no prologue: is the id at or above 4. The unsigned
 * compare says the parameter is unsigned, and the arm that falls through
 * the `blo` is the one the source wrote first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md), so the
 * source tests `>= 4` and returns 1, rather than testing `< 4` and
 * returning 0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMS_DRAW_GetFrameSurface.c \
 *       --func PMS_DRAW_GetFrameSurface --addr 0x0202E430 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

u32 PMS_DRAW_GetFrameSurface(u32 id)
{
    if (id >= 4) {
        return 1;
    }
    return 0;
}
