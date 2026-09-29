/*
 * function: func_02195B44
 * address:  0x02195B44
 * packet:   pkt_ov009_02195B44
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gt2Connect (libdwcgsgt2.TWL.HYB.a(gt2main.o))
 *
 * symbols:
 *   gt2StringToAddress          0x021986C4  arm  ov009
 *   gti2NewOutgoingConnection   0x02195590  arm  ov009
 *   gti2StartConnectionAttempt  0x021955F0  arm  ov009
 *   gti2FreeSocketConnection    0x02198264  arm  ov009
 *   gt2Think                    0x02195AF0  arm  ov009
 *   msleep                      0x0217F2BC  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct GTI2Connection
{
    int pad0[3];
    int state;
    int pad1[2];
    int result;
    int pad2;
    int timeout;
    int freezeCount;
} GTI2Connection;

extern int gt2StringToAddress();
extern int gti2NewOutgoingConnection();
extern int gti2StartConnectionAttempt();
extern void gti2FreeSocketConnection();
extern void gt2Think();
extern void msleep();

int func_02195B44(void *socket, GTI2Connection **connection, char *remoteAddress, u8 *message, int len, int timeout, void *callbacks, int blocking)
{
    GTI2Connection *connectionTemp;
    int result;
    int done;
    u32 ip;
    u16 port;

    if (!gt2StringToAddress(remoteAddress, &ip, &port) || !ip || !port)
        return 4;
    if (((((ip >> 24) & 0xFF) | ((ip >> 8) & 0xFF00) | ((ip << 8) & 0xFF0000) | ((ip << 24) & 0xFF000000)) & 0xE0000000) == 0xE0000000)
        return 4;
    result = gti2NewOutgoingConnection(socket, &connectionTemp, ip, port);
    if (result)
        return result;
    connectionTemp->timeout = timeout;
    result = gti2StartConnectionAttempt(connectionTemp, message, len, callbacks);
    if (result)
    {
        gti2FreeSocketConnection(connectionTemp);
        return result;
    }
    if (!blocking)
    {
        if (connection)
            *connection = connectionTemp;
        return 0;
    }
    connectionTemp->freezeCount++;
    do
    {
        gt2Think(socket);
        done = connectionTemp->state >= 5;
        if (!done)
            msleep(1);
    } while (!done);
    connectionTemp->freezeCount--;
    if (connectionTemp->state == 5)
        *connection = connectionTemp;
    return connectionTemp->result;
}
