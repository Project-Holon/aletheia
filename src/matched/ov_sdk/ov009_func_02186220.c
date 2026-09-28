/*
 * function: gpDeleteBuddy
 * address:  0x02186220
 * packet:   pkt_ov009_02186220
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpDeleteBuddy (gp.o)
 *
 * symbols:
 *   gpiSetErrorString  0x02193734  arm
 *   gpiDeleteBuddy     0x021890E0  arm
 *   g_021A4024         0x021A4024  data
 */

typedef struct GPIConnection GPIConnection;

extern char g_021A4024[];
extern void gpiSetErrorString(void **connection, char *errorString);
extern int gpiDeleteBuddy(void **connection, int profile, int sendServerRequest);

int gpDeleteBuddy(void **connection, int profile)
{
    GPIConnection *iconnection;
    int __result__;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return 0;
    if (*(int *)((char *)iconnection + 0x1f4) == 4) {
        gpiSetErrorString(connection, g_021A4024);
        return 2;
    }
    __result__ = gpiDeleteBuddy(connection, profile, 1);
    if (__result__ == 0)
        return 0;
    return __result__;
}
