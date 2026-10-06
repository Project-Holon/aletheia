/*
 * function: func_0218C72C
 * address:  0x0218C72C
 * packet:   pkt_ov009_0218C72C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSendUserInfo (gpiinfo.o)
 *
 * symbols:
 *   func_0218946C  0x0218946C  arm   ov009
 */

typedef struct GPIConnection {
    unsigned char pad[0x5E4];
    unsigned char outputBuffer[0x10];
} GPIConnection;

extern int func_0218946C(int *connection, int *buffer, const char *string);

int func_0218C72C(void **connection, char *info, char *value)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int result;

    if ((result = func_0218946C((int *)connection, (int *)((char *)iconnection + 0x1f4 + 0x400), info)) != 0)
        return result;
    if ((result = func_0218946C((int *)connection, (int *)((char *)iconnection + 0x1f4 + 0x400), value)) != 0)
        return result;
    return 0;
}
