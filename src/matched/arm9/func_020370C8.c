/*
 * unit:     no
 * function: GFL_NET_WM_ICON_EasyEnd
 * address:  0x020370C8
 * packet:   pkt_020370C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469C8      0x021469C8  data
 *   GFL_NET_WM_ICON_Delete  0x02036E80  arm
 *   GFL_NET_WM_ICON_ClearOam  0x02036FD8  arm
 *
 * Two-stage shutdown guarded on a global word: always run GFL_NET_WM_ICON_ClearOam,
 * then, only when g_021469C8[1] is set, run GFL_NET_WM_ICON_Delete and clear the flag.
 * GFL_NET_WM_ICON_Delete was the sole blocker for this file; it was matched in the
 * same wave, so its PC24 site now attests on the `matched` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_WM_ICON_EasyEnd.c \
 *       --func GFL_NET_WM_ICON_EasyEnd --addr 0x020370C8 --arm --cc 1.1p1
 */

extern int GFL_NET_WM_ICON_ClearOam(void);
extern void GFL_NET_WM_ICON_Delete(unsigned char *p);
extern int g_021469C8[];

void GFL_NET_WM_ICON_EasyEnd(void)
{
    GFL_NET_WM_ICON_ClearOam();
    if (g_021469C8[1] == 0)
        return;
    GFL_NET_WM_ICON_Delete((unsigned char *)g_021469C8[1]);
    g_021469C8[1] = 0;
}
