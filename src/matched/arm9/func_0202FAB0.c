/*
 * function: APP_POWER_IsReady
 * address:  0x0202FAB0
 * packet:   pkt_0202F9F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * time_icon.c.  The unlabelled four-byte leaf after OVERLAY_LAUNCH_Driver's literal
 * pool (`movs r0, #1; bx lr`), which the listing extent of OVERLAY_LAUNCH_Driver
 * swallows.  It saves nothing, so disasm.py never labels it
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); seed
 * 0x0202FAB0 in layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/APP_POWER_IsReady.c \
 *       --func APP_POWER_IsReady --addr 0x0202FAB0 --cc 1.1p1 --thumb
 */

int APP_POWER_IsReady(void)
{
    return 1;
}
