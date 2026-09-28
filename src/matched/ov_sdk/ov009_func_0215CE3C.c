/*
 * function: SOCLi_CreateCommandPacket
 * address:  0x0215ce3c
 * packet:   pkt_ov009_0215CE3C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_CreateCommandPacket (socl_command.o)
 *
 * symbols:
 *   SOCLi_AllocCommandPacket   0x0215ce14 arm
 */

struct SOCLSocket;

struct SOCLiCommandPacket {
    int (*handler)(void *);
    struct SOCLSocket *socket;
    long field8;
    signed char fieldC;
    signed char fieldD;
};

extern struct SOCLiCommandPacket *SOCLi_AllocCommandPacket(long flag);

struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *),
                                                     struct SOCLSocket *socket,
                                                     long flag)
{
    struct SOCLiCommandPacket *cp = SOCLi_AllocCommandPacket(flag);

    if (cp != 0) {
        cp->handler = handler;
        cp->socket = socket;
        cp->field8 = 0;
        cp->fieldC = *(signed char *)((char *)socket + 0xaf);
        cp->fieldD = (signed char)flag;
    }
    return cp;
}
