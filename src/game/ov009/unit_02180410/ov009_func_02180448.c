/*
 * function: gsUdpRemotePeerCompare
 * address:  0x02180448
 * packet:   pkt_ov009_02180448
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpRemotePeerCompare (gsudpengine.o)
 *
 * symbols:
 */

struct GSUdpRemotePeer {
    unsigned int   ip;    /* +0x00 */
    unsigned short port;  /* +0x04 */
};

int gsUdpRemotePeerCompare(void *theFirstPeer, void *theSecondPeer)
{
    struct GSUdpRemotePeer *aPeer1 = (struct GSUdpRemotePeer *)theFirstPeer;
    struct GSUdpRemotePeer *aPeer2 = (struct GSUdpRemotePeer *)theSecondPeer;

    if (aPeer1->ip != aPeer2->ip)
        return 1;
    if (aPeer1->port != aPeer2->port)
        return 1;
    return 0;
}
