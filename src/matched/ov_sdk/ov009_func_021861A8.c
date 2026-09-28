/*
 * function: gpIsBuddy
 * address:  0x021861A8
 * packet:   pkt_ov009_021861A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpIsBuddy (gp.o)
 *
 * symbols:
 *   gpiGetProfile  0x0218FD9C  arm
 */

typedef struct GPIConnection GPIConnection;
typedef struct GPIProfile GPIProfile;

extern int gpiGetProfile(void **connection, int profileid, GPIProfile **pProfile);

int gpIsBuddy(void **connection, int profile)
{
    GPIConnection *iconnection;
    GPIProfile *pProfile;

    if (!connection || !*connection)
        return 0;
    iconnection = (GPIConnection *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return 0;
    if (gpiGetProfile(connection, profile, &pProfile) && *(int *)((char *)pProfile + 8) != 0)
        return 1;
    if (gpiGetProfile(connection, profile, &pProfile) && *(int *)((char *)pProfile + 0xc) != 0)
        return 1;
    return 0;
}
