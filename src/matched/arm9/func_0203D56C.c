/*
 * function: GFL_NET_ResetSendQueue
 * address:  0x0203D56C
 * packet:   pkt_0203D56C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_IsSendQueueEmpty  0x020394C0  arm
 */

extern int GFL_NET_SYSTEM_IsSendQueueEmpty(void);
void GFL_NET_ResetSendQueue(void)
{
    GFL_NET_SYSTEM_IsSendQueueEmpty();
}
