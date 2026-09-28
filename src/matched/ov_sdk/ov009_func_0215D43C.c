/*
 * function: SOCL_Bind
 * address:  0x0215d43c
 * packet:   pkt_ov009_0215D43C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_Bind (socl_bind.o)
 *
 * symbols:
 *   SOCL_SocketIsInvalid     0x0215f3d0 arm
 *   SOCLi_ExecBindCommand    0x0215d5f8 arm
 */

struct SOCLSocket {
    unsigned char pad[0xac];
    short field_ac;
    signed char field_ae;
    signed char field_af;
    unsigned short field_b0;
};

extern int SOCL_SocketIsInvalid(struct SOCLSocket *socket);
extern int SOCLi_ExecBindCommand(struct SOCLSocket *socket);

int SOCL_Bind(int s, unsigned short local_port)
{
    struct SOCLSocket *socket = (struct SOCLSocket *)s;

    if (SOCL_SocketIsInvalid(socket))
        return -0x1c;
    {
        int flag = 0;

        if (socket != 0)
            flag = (socket->field_ac & 1) != 0;
        if (flag == 0)
            return -0x27;
    }
    if (socket->field_ac & 2)
        return -7;
    socket->field_b0 = local_port;
    if (socket->field_af != 1)
        return 0;
    return SOCLi_ExecBindCommand(socket);
}
