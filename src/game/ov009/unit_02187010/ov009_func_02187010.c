/*
 * function: gpiSendAuthBuddyRequest
 * address:  0x02187010
 * packet:   pkt_ov009_02187010
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSendAuthBuddyRequest (gpibuddy.o)
 *
 * symbols:
 *   gpiAppendStringToBuffer  0x0218946C  arm
 *   gpiAppendIntToBuffer     0x0218949C  arm
 *   g_021A4240               0x021A4240  data
 *   g_021A424C               0x021A424C  data
 *   g_021A4258               0x021A4258  data
 *   g_021A4268               0x021A4268  data
 *   g_021A4270               0x021A4270  data
 */

typedef struct GPIConnection GPIConnection;
typedef struct GPIProfile GPIProfile;
typedef struct GPIBuffer GPIBuffer;

struct GPIBuffer {
    char pad[4];
};

struct GPIConnection {
    char pad[0x210];
    GPIBuffer outputBuffer;
};

extern char g_021A4240[];
extern char g_021A424C[];
extern char g_021A4258[];
extern char g_021A4268[];
extern char g_021A4270[];
extern int gpiAppendStringToBuffer(void **connection, GPIBuffer *outputBuffer, char *buffer);
extern int gpiAppendIntToBuffer(void **connection, GPIBuffer *outputBuffer, int num);

int gpiSendAuthBuddyRequest(void **connection, GPIProfile *profile)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;

    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4240);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A424C);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, *(int *)((char *)iconnection + 0x198));
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4258);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, *(int *)profile);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4268);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, *(char **)((char *)profile + 0x14));
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4270);
    return 0;
}
