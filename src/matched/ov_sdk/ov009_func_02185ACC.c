/*
 * function: gpDisconnect
 * address:  0x02185ACC
 * packet:   pkt_ov009_02185ACC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpDisconnect (gp.o)
 *
 * symbols:
 *   gpiDisconnect  0x0218B760  arm
 *   gpiReset       0x021867E8  arm
 */

typedef struct GPIConnection GPIConnection;

extern void gpiDisconnect(void **connection, int tellServer);
extern int gpiReset(void **connection);

void gpDisconnect(void **connection)
{
    GPIConnection *iconnection;
    int oldState;

    if (!connection || !*connection)
        return;
    iconnection = (GPIConnection *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return;
    oldState = *(int *)((char *)iconnection + 0x1f4);
    gpiDisconnect(connection, 1);
    gpiReset(connection);
    if (oldState == 3)
        *(int *)((char *)iconnection + 0x1f4) = 4;
}
