/*
 * function: DENDOU_VIEW_ExitActors
 * address:  0x021DE014
 * packet:   pkt_021DE014
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DENDOU_VIEW_ExitPageCounterOam  0x021DE884  thumb  ov171
 *   DENDOU_VIEW_DeleteActors  0x021DE368  thumb  ov171
 *   DENDOU_VIEW_ReleaseResources  0x021DE258  thumb  ov171
 *   CLACT_ExitSystem  0x0204A5AC  arm
 */

extern void DENDOU_VIEW_ExitPageCounterOam(int *);
extern void DENDOU_VIEW_DeleteActors(char *p);
extern void DENDOU_VIEW_ReleaseResources(char *p);
extern void CLACT_ExitSystem(void);

void DENDOU_VIEW_ExitActors(int *p)
{
    DENDOU_VIEW_ExitPageCounterOam(p);
    DENDOU_VIEW_DeleteActors((char *)p);
    DENDOU_VIEW_ReleaseResources((char *)p);
    CLACT_ExitSystem();
}
