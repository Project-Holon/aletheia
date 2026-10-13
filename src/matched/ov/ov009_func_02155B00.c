/*
 * function: DWC_RAP_SendAck
 * address:  0x02155B00
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Flag test on the three-argument call.
 *
 * symbols:
 *   DWC_RAP_SendPacket  0x02155A80  thumb  ov009
 */

extern int DWC_RAP_SendPacket(void *src, int len, int c);

int DWC_RAP_SendAck(int a, int b)
{
    if (DWC_RAP_SendPacket((void *)a, b, 3) != 0) {
        return 1;
    }

    return 0;
}

