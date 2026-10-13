/*
 * function: GFL_NET_ERR_HaltIfActive
 * address:  0x0200FA84
 * packet:   pkt_0200F83C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02010054  0x02010054  thumb
 *   GFL_NET_ERR_DrawAndHang  0x0200FA94  thumb
 *
 * Guard: if func_02010054() reports nonzero, calls the abort path
 * GFL_NET_ERR_DrawAndHang.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_ERR_HaltIfActive.c \
 *       --func GFL_NET_ERR_HaltIfActive --addr 0x0200FA84 --cc 1.1p1
 */

typedef unsigned int u32;

extern u32  func_02010054(void);
extern void GFL_NET_ERR_DrawAndHang(void);

void GFL_NET_ERR_HaltIfActive(void)
{
    if (func_02010054() != 0) {
        GFL_NET_ERR_DrawAndHang();
    }
}
