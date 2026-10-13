/*
 * function: GFL_NET_RestartNoTimeout
 * address:  0x0203D8AC
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Runs GFL_NET_WM_ICON_SetDefaultPos(0, 0) and GFL_NET_RestartByNetType.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_RestartNoTimeout.c \
 *       --func GFL_NET_RestartNoTimeout --addr 0x0203D8AC --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_RestartByNetType  0x0203D2CC  arm
 *   GFL_NET_WM_ICON_SetDefaultPos  0x020371AC  arm
 */

extern void GFL_NET_WM_ICON_SetDefaultPos(unsigned short a, unsigned int b);
extern void GFL_NET_RestartByNetType(void);

void GFL_NET_RestartNoTimeout(void)
{
    GFL_NET_WM_ICON_SetDefaultPos(0, 0);
    GFL_NET_RestartByNetType();
}
