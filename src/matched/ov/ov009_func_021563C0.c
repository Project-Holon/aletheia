/*
 * function: DWC_RAP_StartVchatDefaultHeap
 * address:  0x021563C0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Halfword at +0x56 of the block GFL_NET_GetInitParam returns, passed on.
 *
 * symbols:
 *   DWC_RAP_StartVchat  0x02156344  thumb  ov009
 *   GFL_NET_GetInitParam  0x0203D798  arm  arm9
 */

extern char *GFL_NET_GetInitParam(int a);
extern void DWC_RAP_StartVchat(void *a);

void DWC_RAP_StartVchatDefaultHeap(int a)
{
    DWC_RAP_StartVchat((void *)(*(unsigned short *)(GFL_NET_GetInitParam(a) + 0x56)));
}

