/*
 * function: gpDenyBuddyRequest
 * address:  0x02185EE4
 * packet:   pkt_ov009_02185EE4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpDenyBuddyRequest (gp.o)
 *
 * symbols:
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   gsifree  0x0217EAE0  arm   ov009
 *   gpiCanFreeProfile  0x02190140  arm   ov009
 *   gpiRemoveProfile  0x0218FF24  arm   ov009
 *   g_021A4024     0x021A4024  data  ov009
 */

typedef struct GPIProfile {
    unsigned char pad0[0x14];
    void *f14;
    int f18;
} GPIProfile;

typedef struct GPIConnection {
    unsigned char pad0[0x100];
    int f100;
    unsigned char pad1[0x108 - 0x104];
    int f108;
    unsigned char pad2[0x1F4 - 0x10C];
    int f1F4;
} GPIConnection;

extern void gpiSetErrorString(int *p, int b);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern void gsifree(void *ptr);
extern int gpiCanFreeProfile(char *p);
extern void gpiRemoveProfile(const int *p, void *profile);
extern char g_021A4024[];

int gpDenyBuddyRequest(void **connection, int profile)
{
    GPIProfile *pProfile;
    GPIConnection *iconnection;

    if (connection == 0 || (iconnection = (GPIConnection *)*connection) == 0)
        return 2;
    if (iconnection->f108 != 0)
        return 0;
    if (iconnection->f1F4 == 4) {
        gpiSetErrorString((int *)connection, (int)g_021A4024);
        return 2;
    }
    if (!func_0218FD9C(connection, profile, &pProfile))
        return 0;
    pProfile->f18--;
    if (iconnection->f100 == 0 && pProfile->f18 <= 0) {
        gsifree(pProfile->f14);
        pProfile->f14 = 0;
        if (gpiCanFreeProfile((char *)pProfile))
            gpiRemoveProfile((const int *)connection, pProfile);
    }
    return 0;
}
