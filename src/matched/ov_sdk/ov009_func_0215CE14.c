/*
 * function: SOCLi_AllocCommandPacket
 * address:  0x0215ce14
 * packet:   pkt_ov009_0215CE14
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_AllocCommandPacket (socl_command.o)
 *
 * symbols:
 *   OS_ReceiveMessage           0x02085e50 arm
 *   SOCLiCommandPacketQueue    0x021aa484 data
 */

struct OSMessageQueue;

extern struct OSMessageQueue SOCLiCommandPacketQueue;
extern int OS_ReceiveMessage(struct OSMessageQueue *mq, void **msg, long flags);

union SOCLiCommandPacket;

union SOCLiCommandPacket *SOCLi_AllocCommandPacket(long flag)
{
    union SOCLiCommandPacket *cp;

    if (OS_ReceiveMessage(&SOCLiCommandPacketQueue, (void **)&cp, flag) != 0)
        return cp;
    return 0;
}
