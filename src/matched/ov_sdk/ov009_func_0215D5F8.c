/*
 * function: SOCLi_ExecBindCommand
 * address:  0x0215d5f8
 * packet:   pkt_ov009_0215D5F8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_ExecBindCommand (socl_bind.o)
 *
 * symbols:
 *   SOCLi_CreateCommandPacket           0x0215ce3c arm
 *   SOCLi_ExecCommandPacketInRecvPipe   0x0215cf88 arm
 *   SOCLi_BindCallBack                  0x0215d650 arm
 */

struct SOCLSocket {
    unsigned char pad[0xac];
    short field_ac;
    signed char field_ae;
    signed char field_af;
    unsigned short field_b0;
    unsigned short field_b2;
    unsigned long field_b4;
};

struct SOCLiCommandPacket {
    int (*handler)(void *);
    struct SOCLSocket *socket;
    long field8;
    signed char fieldC;
    signed char fieldD;
    unsigned char padE[2];
    unsigned short field10;
    unsigned short field12;
    unsigned long field14;
};

extern struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *),
                                                            struct SOCLSocket *socket,
                                                            long flag);
extern int SOCLi_ExecCommandPacketInRecvPipe(struct SOCLSocket *socket,
                                             struct SOCLiCommandPacket *command);
extern int SOCLi_BindCallBack(void *arg);

static int SOCLi_ExecBindCommand(struct SOCLSocket *socket)
{
    struct SOCLiCommandPacket *command
        = SOCLi_CreateCommandPacket(SOCLi_BindCallBack, socket, socket->field_ae);

    if (command == 0)
        return -0x21;
    command->field10 = socket->field_b0;
    command->field12 = socket->field_b2;
    command->field14 = socket->field_b4;
    socket->field_ac |= 2;
    return SOCLi_ExecCommandPacketInRecvPipe(socket, command);
}
