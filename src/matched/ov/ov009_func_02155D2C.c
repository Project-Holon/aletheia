/*
 * function: DWC_RAP_EnterConnected
 * address:  0x02155D2C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Enables slot 9 then calls the wakeup.
 *
 * symbols:
 *   DWC_RAP_SetState  0x02155374  thumb  ov009
 *   DWC_RAP_SetupRecvTimeouts  0x02155C8C  thumb  ov009
 */

extern void DWC_RAP_SetState(int v);
extern void DWC_RAP_SetupRecvTimeouts(void);

void DWC_RAP_EnterConnected(int e)
{
    DWC_RAP_SetState(9);
    DWC_RAP_SetupRecvTimeouts();
}

