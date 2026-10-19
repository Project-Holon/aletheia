/*
 * function: GFL_USE_PostIrqUpdate
 * address:  0x02005230
 * packet:   pkt_0200520C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0200567C
 *
 * symbols:
 *   GFL_USE_DoVramTransfer  0x02005430  thumb
 *   GFL_USE_RunMainTasks  0x0200567C  thumb
 */

extern void GFL_USE_DoVramTransfer(void);
extern void GFL_USE_RunMainTasks(void);
void GFL_USE_PostIrqUpdate(void)
{
    GFL_USE_DoVramTransfer();
    GFL_USE_RunMainTasks();
}
