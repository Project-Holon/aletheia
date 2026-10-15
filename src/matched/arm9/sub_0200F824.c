/*
 * function: GFL_NET_ERR_UpdateNetwork
 * address:  0x0200F824
 * packet:   pkt_0200F168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_ERR_UpdateNetwork.c \
 *       --func GFL_NET_ERR_UpdateNetwork --addr 0x0200F824 --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_Main  0x0203CF5C  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   OS_WaitIrq  0x0208459C  arm
 */

typedef unsigned int u32;

extern int GFL_NET_GetRunState(void);
extern u32 GFL_NET_Main(void);
extern void OS_WaitIrq(int clear, u32 irqFlags);

void GFL_NET_ERR_UpdateNetwork(void)
{
    if (GFL_NET_GetRunState() == 1) {
        GFL_NET_Main();
        OS_WaitIrq(1, 1);
    }
}
