/*
 * function: gpGetLoginTicket
 * address:  0x02186618
 * packet:   pkt_ov009_02186618
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpGetLoginTicket (gp.o)
 */

typedef struct GPIConnection GPIConnection;

int gpGetLoginTicket(void **connection, char *loginTicket)
{
    GPIConnection *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection *)*connection;
    __memcpy(loginTicket, (char *)iconnection + 0x614, 25);
    return 0;
}
