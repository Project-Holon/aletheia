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
 *   gGpiBuddyKeyAuthAdd               0x021A4240  data
 *   gGpiBuddyKeySessKey               0x021A424C  data
 *   gGpiBuddyKeyFromProfileId               0x021A4258  data
 *   gGpiBuddyKeySig               0x021A4268  data
 *   gGpiBuddyKeyFinal               0x021A4270  data
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

extern char gGpiBuddyKeyAuthAdd[];
extern char gGpiBuddyKeySessKey[];
extern char gGpiBuddyKeyFromProfileId[];
extern char gGpiBuddyKeySig[];
extern char gGpiBuddyKeyFinal[];
extern int gpiAppendStringToBuffer(void **connection, GPIBuffer *outputBuffer, char *buffer);
extern int gpiAppendIntToBuffer(void **connection, GPIBuffer *outputBuffer, int num);

int gpiSendAuthBuddyRequest(void **connection, GPIProfile *profile)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;

    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, gGpiBuddyKeyAuthAdd);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, gGpiBuddyKeySessKey);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, *(int *)((char *)iconnection + 0x198));
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, gGpiBuddyKeyFromProfileId);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, *(int *)profile);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, gGpiBuddyKeySig);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, *(char **)((char *)profile + 0x14));
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, gGpiBuddyKeyFinal);
    return 0;
}
