/*
 * function: DWC_RAP_OnUpdateServers
 * address:  0x02155C0C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Stores slot 6 when the argument is zero and slot 0xe otherwise.
 *
 * symbols:
 *   DWC_RAP_SetState  0x02155374  thumb  ov009
 */

extern void DWC_RAP_SetState(int v);

void DWC_RAP_OnUpdateServers(int a)
{
    if (a == 0) {
        DWC_RAP_SetState(6);
        return;
    }

    DWC_RAP_SetState(0xe);
}

