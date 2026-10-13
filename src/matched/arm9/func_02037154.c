/*
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * `bl` to 0x02036CA8, which has no outside witness.  0x02036CA8 carries no
 * `func_` label in the listing, so the `label` class cannot reach it, and the
 * only branch to it anywhere in the image is the one inside this function, so
 * there is no second caller to attest it either.  It closes the day
 * 0x02036CA8 is matched itself (its manifest entry would then be the witness)
 * or a second caller turns up.
 *
 * function: GFL_NET_WM_ICON_EasyMain
 * address:  0x02037154
 * packet:   pkt_02037154
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_WM_ICON_Draw  0x02036CA8  arm
 *   g_021469C8     0x021469C8  data
 *
 * Flush hook: does nothing while the handler in the second word of the global
 * at 0x021469C8 is unarmed, otherwise hands it to GFL_NET_WM_ICON_Draw.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_NET_WM_ICON_EasyMain.c \
 *       --func GFL_NET_WM_ICON_EasyMain --addr 0x02037154 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Icon;
extern void GFL_NET_WM_ICON_Draw(struct Icon *c);
extern u32  g_021469C8[];

void GFL_NET_WM_ICON_EasyMain(void)
{
    if (g_021469C8[1] == 0)
        return;
    GFL_NET_WM_ICON_Draw((struct Icon *)g_021469C8[1]);
}
