/*
 * function: gpiAuthBuddyRequest
 * address:  0x02188FD8
 * packet:   pkt_ov009_02188FD8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      gpiAuthBuddyRequest (gpibuddy.o)
 *
 * symbols:
 *   gpiGetProfile           0x0218FD9C  arm
 *   gpiSetErrorString       0x02193734  arm
 *   gpiSendAuthBuddyRequest 0x02187010  arm
 *   gsifree                 0x0217EAE0  arm
 *   gpiCanFreeProfile       0x02190140  arm
 *   gpiRemoveProfile        0x0218FF24  arm
 *   g_021A446C              0x021A446C  data
 */

typedef struct GPIConnection GPIConnection;
typedef struct GPIProfile GPIProfile;

extern char g_021A446C[];
extern int gpiGetProfile(void **connection, int profileid, GPIProfile **pProfile);
extern void gpiSetErrorString(void **connection, char *errorString);
extern int gpiSendAuthBuddyRequest(void **connection, GPIProfile *profile);
extern void gsifree(void *ptr);
extern int gpiCanFreeProfile(GPIProfile *profile);
extern void gpiRemoveProfile(void **connection, GPIProfile *profile);

int gpiAuthBuddyRequest(void **connection, int profile)
{
    GPIConnection *iconnection;
    GPIProfile *pProfile;
    int __result__;

    iconnection = (GPIConnection *)*connection;

    if (!gpiGetProfile(connection, profile, &pProfile)) {
        gpiSetErrorString(connection, g_021A446C);
        return 2;
    }
    if (*(int *)((char *)pProfile + 0x14) == 0) {
        gpiSetErrorString(connection, g_021A446C);
        return 2;
    }

    __result__ = gpiSendAuthBuddyRequest(connection, pProfile);
    if (__result__ != 0)
        return __result__;

    *(int *)((char *)pProfile + 0x18) = *(int *)((char *)pProfile + 0x18) - 1;

    if (*(int *)((char *)iconnection + 0x100) == 0
        && *(int *)((char *)pProfile + 0x18) <= 0) {
        gsifree(*(void **)((char *)pProfile + 0x14));
        *(int *)((char *)pProfile + 0x14) = 0;
        if (gpiCanFreeProfile(pProfile))
            gpiRemoveProfile(connection, pProfile);
    }

    return 0;
}
