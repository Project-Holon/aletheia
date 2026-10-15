/*
 * function: gpiSendGetInfo
 * address:  0x0218D40C
 * packet:   pkt_ov009_0218D40C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSendGetInfo (gpiinfo.o)
 *
 * symbols:
 *   gpiAppendStringToBuffer  0x0218946C  arm
 *   gpiAppendIntToBuffer     0x0218949C  arm
 *   gGpiInfoKeyGetProfileSessKey               0x021A4D60  data
 *   gGpiInfoKeyProfileId               0x021A4AE0  data
 *   gGpiInfoKeyId               0x021A4D78  data
 *   gGpiInfoKeyFinal               0x021A4C18  data
 */

struct GPIBuffer {
    char *buffer;  /* +0x00 */
    int   size;    /* +0x04 */
    int   len;     /* +0x08 */
    int   pos;     /* +0x0c */
};

struct GPIConnection {
    char pad0[0x198];
    int sessKey;                            /* +0x198 */
    char pad19c[0x210 - 0x19c];
    struct GPIBuffer outputBuffer;          /* +0x210 */
};

extern int gpiAppendStringToBuffer(void **connection, struct GPIBuffer *outputBuffer,
                                   char *buffer);
extern int gpiAppendIntToBuffer(void **connection, struct GPIBuffer *outputBuffer,
                                int num);
extern char gGpiInfoKeyGetProfileSessKey[];
extern char gGpiInfoKeyProfileId[];
extern char gGpiInfoKeyId[];
extern char gGpiInfoKeyFinal[];

int gpiSendGetInfo(void **connection, int profileid, int operationid)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;

    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, gGpiInfoKeyGetProfileSessKey);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, iconnection->sessKey);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, gGpiInfoKeyProfileId);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, profileid);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, gGpiInfoKeyId);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, operationid);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, gGpiInfoKeyFinal);
    return 0;
}
