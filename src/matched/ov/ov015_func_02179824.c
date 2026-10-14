/*
 * function: IRCNET_SendAndNotify
 * address: 0x02179824
 * packet: pkt_ov015_02179824
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0217983E.
 * symbols:
 *   IRCNET_QueueSend 0x02179A4C thumb ov015
 */
typedef unsigned char u8;
extern void IRCNET_QueueSend(void *, u8, u8);
int IRCNET_SendAndNotify(void *dst, int a, int unused, void (*cb)(int))
{
    IRCNET_QueueSend(dst, (u8)a, 0);
    if (cb != 0) cb(1);
    return 1;
}
