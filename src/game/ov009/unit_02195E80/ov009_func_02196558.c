/*
 * function: func_02196558
 * address:  0x02196558
 * packet:   pkt_ov009_02196558
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2DeliverReliableMessage (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   gti2HandleAppReliable       0x02196118  arm  ov009
 *   gti2HandleClientChallenge   0x021961C8  arm  ov009
 *   gti2HandleServerChallenge   0x02196268  arm  ov009
 *   gti2HandleClientResponse    0x02196348  arm  ov009
 *   gti2HandleAccept            0x02196458  arm  ov009
 *   gti2HandleReject            0x021964A8  arm  ov009
 *   gti2HandleClose             0x02196514  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct GTI2Connection
{
    char pad0[0x66];
    u16 serverChallengeCount;
} GTI2Connection;

extern int gti2HandleAppReliable();
extern int gti2HandleClientChallenge();
extern int gti2HandleServerChallenge();
extern int gti2HandleClientResponse();
extern int gti2HandleAccept();
extern int gti2HandleReject();
extern int gti2HandleClose();

int func_02196558(GTI2Connection *connection, int type, u8 *message, int len)
{
    connection->serverChallengeCount++;
    if (type == 0)
    {
        if (!gti2HandleAppReliable(connection, message, len))
            return 0;
    }
    else if (type == 1)
    {
        if (!gti2HandleClientChallenge(connection, message, len))
            return 0;
    }
    else if (type == 2)
    {
        if (!gti2HandleServerChallenge(connection, message, len))
            return 0;
    }
    else if (type == 3)
    {
        if (!gti2HandleClientResponse(connection, message, len))
            return 0;
    }
    else if (type == 4)
    {
        if (!gti2HandleAccept(connection))
            return 0;
    }
    else if (type == 5)
    {
        if (!gti2HandleReject(connection, message, len))
            return 0;
    }
    else if (type == 6)
    {
        if (!gti2HandleClose(connection))
            return 0;
    }
    return 1;
}
