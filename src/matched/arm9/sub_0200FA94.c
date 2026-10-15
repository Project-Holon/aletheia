/*
 * function: GFL_NET_ERR_DrawAndHang
 * address:  0x0200FA94
 * packet:   pkt_0200F83C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200FD38  0x0200FD38  thumb
 *   UI_ClearFlags39Global  0x020351A0  arm
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 *
 * An abort path: reports a fixed status, tears down with UI_ClearFlags39Global(2),
 * then spins forever calling GFL_USE_PollPowerExit(). The infinite loop is why
 * nothing after this in the same block is ever reached.
 *
 * EXACT* because the 22 compiled bytes fall two short of the disasm.py
 * extent: a "movs r0, r0" alignment filler before the next label, the
 * ordinary inter-function padding, not a byte difference.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_ERR_DrawAndHang.c \
 *       --func GFL_NET_ERR_DrawAndHang --addr 0x0200FA94 --cc 1.1p1
 */

typedef unsigned int u32;

extern void func_0200FD38(u32 a, u32 b);
extern int UI_ClearFlags39Global(u32 v);
extern void GFL_USE_PollPowerExit(void);

void GFL_NET_ERR_DrawAndHang(void)
{
    func_0200FD38(1, 0);
    UI_ClearFlags39Global(2);
    for (;;) {
        GFL_USE_PollPowerExit();
    }
}
