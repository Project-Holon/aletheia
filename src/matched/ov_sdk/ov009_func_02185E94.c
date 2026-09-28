/*
 * function: gpAuthBuddyRequest
 * address:  0x02185E94
 * packet:   pkt_ov009_02185E94
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpAuthBuddyRequest (gp.o)
 *
 * symbols:
 *   gpiSetErrorString    0x02193734  arm
 *   gpiAuthBuddyRequest  0x02188FD8  arm
 *   g_021A4024           0x021A4024  data
 */

typedef struct GPIConnection GPIConnection;

extern char g_021A4024[];
extern void gpiSetErrorString(void **connection, char *errorString);
extern int gpiAuthBuddyRequest(void **connection, int profile);

int gpAuthBuddyRequest(void **connection, int profile)
{
    GPIConnection *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return 0;
    if (*(int *)((char *)iconnection + 0x1f4) == 4) {
        gpiSetErrorString(connection, g_021A4024);
        return 2;
    }
    return gpiAuthBuddyRequest(connection, profile);
}
