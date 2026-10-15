/*
 * function: gpGetBuddyIndex
 * address:  0x02186108
 * packet:   pkt_ov009_02186108
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpGetBuddyIndex (gp.o)
 *
 * symbols:
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 */

typedef struct GPIProfile {
    int f0;
    int f4;
    int *f8;
    int *fC;
} GPIProfile;

typedef struct GPIConnection {
    unsigned char pad[0x108];
    int f108;
} GPIConnection;

extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);

int gpGetBuddyIndex(void **connection, int profile, int *index)
{
    GPIProfile *pProfile;

    if (connection == 0 || *connection == 0)
        return 2;
    if (((GPIConnection *)*connection)->f108 != 0) {
        *index = 0;
        return 0;
    }
    if (func_0218FD9C(connection, profile, &pProfile) && pProfile->f8 != 0)
        *index = *pProfile->f8;
    else if (func_0218FD9C(connection, profile, &pProfile) && pProfile->fC != 0)
        *index = *pProfile->fC;
    else
        *index = -1;
    return 0;
}
