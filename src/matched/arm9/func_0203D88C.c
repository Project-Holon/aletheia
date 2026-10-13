/*
 * function: GFL_NET_RestartWithTimeout
 * address:  0x0203D88C
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Truncates both arguments to 16 bits, then runs the pair through
 * GFL_NET_WM_ICON_SetDefaultPos and GFL_NET_RestartByNetType.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_RestartWithTimeout.c \
 *       --func GFL_NET_RestartWithTimeout --addr 0x0203D88C --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_RestartByNetType  0x0203D2CC  arm
 *   GFL_NET_WM_ICON_SetDefaultPos  0x020371AC  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_NET_WM_ICON_SetDefaultPos(unsigned short a, unsigned int b);
extern void GFL_NET_RestartByNetType(void);

void GFL_NET_RestartWithTimeout(u32 a, u32 b)
{
    GFL_NET_WM_ICON_SetDefaultPos((u16)a, (u16)b);
    GFL_NET_RestartByNetType();
}
