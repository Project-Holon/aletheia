/*
 * function: SOCL_CreateSocket
 * address:  0x0215d070
 * packet:   pkt_ov009_0215D070
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The flag select was the whole residue: `flag = (socket->field_ac & 1) != 0`
 * made 1.1p1 emit `moveq r5, r1 / mov r1, r5` (184 B), while the image has the
 * single predicated `movne r1, r5` reusing the constant 1 already in r5.  The
 * vendor object is .comment 4.0.0.1024 -> dsi/1.1p1, so this is source-level:
 * an explicit inner `if (..) flag = 1; else flag = 0;` keeps flag's zero-init
 * as its own `mov r1, #0` and lets each arm move a constant, so the select
 * collapses to the one predicated move and the function is exactly 180 B.
 *
 * sdk:      SOCL_CreateSocket (socl_create.o)
 *
 * symbols:
 *   SOCLi_StartupSocket                0x0215d198 arm
 *   SOCLi_CreateCommandPacket          0x0215ce3c arm
 *   SOCLi_ExecCommandPacketInCtrlPipe  0x0215cfa8 arm
 *   SOCLiConfigPtr                     0x021a1cd8 data
 *   SOCLi_CreateSocketCallBack         0x0215d124 arm
 *   SOCLi_Resource                     0x021aa4ac data
 */

struct SOCLSocketParam;

struct SOCLSocket {
    unsigned char pad[0xac];
    short field_ac;
    signed char field_ae;
    signed char field_af;
};

struct SOCLiCommandPacket;

struct SOCLiResource {
    unsigned long count0;
    unsigned long count4;
};

extern void *SOCLiConfigPtr;
extern struct SOCLiResource SOCLi_Resource;
extern struct SOCLSocket *SOCLi_StartupSocket(struct SOCLSocketParam *param);
extern struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *),
                                                            struct SOCLSocket *socket,
                                                            long flag);
extern int SOCLi_ExecCommandPacketInCtrlPipe(struct SOCLSocket *socket,
                                             struct SOCLiCommandPacket *command);
extern int SOCLi_CreateSocketCallBack(void *arg);

int SOCL_CreateSocket(struct SOCLSocketParam *param)
{
    struct SOCLSocket *socket;
    struct SOCLiCommandPacket *command;

    if (SOCLiConfigPtr == 0)
        return -0x27;
    socket = SOCLi_StartupSocket(param);
    if (socket == 0)
        return -0x31;
    command = SOCLi_CreateCommandPacket(SOCLi_CreateSocketCallBack, socket, 1);
    SOCLi_ExecCommandPacketInCtrlPipe(socket, command);
    {
        int flag = 0;

        if (socket != 0) {
            if (socket->field_ac & 1)
                flag = 1;
            else
                flag = 0;
        }
        if (flag != 0) {
            int b = (socket->field_af == 0 || socket->field_af == 4);

            if (b)
                SOCLi_Resource.count0++;
            else
                SOCLi_Resource.count4++;
        }
    }
    return (int)socket;
}
