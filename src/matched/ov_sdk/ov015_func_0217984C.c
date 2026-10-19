/*
 * function: IRCNET_CbIsLinkedReceiver
 * address:  0x0217984C
 * packet:   pkt_0217984C
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Guard/forward wrapper: returns the follower's result only when the predicate
 * holds, otherwise zero.
 *
 * symbols:
 *   IRCNET_IsLinkAlive  0x02179D3C  thumb  ov015
 *   IRCNET_IsReceiver  0x02179B24  thumb  ov015
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int IRCNET_IsLinkAlive(void);
int IRCNET_IsReceiver(void);

int IRCNET_CbIsLinkedReceiver(void)
{
    if (IRCNET_IsLinkAlive())
        return IRCNET_IsReceiver();
    return 0;
}
