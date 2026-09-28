/*
 * function: gpProcess
 * address:  0x02185948
 * packet:   pkt_ov009_02185948
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpProcess (gp.o)
 *
 * symbols:
 *   gpiProcess  0x02186E9C  arm
 */

typedef struct GPIConnection GPIConnection;

extern int gpiProcess(void **connection, int blockingOperationID);

int gpProcess(void **connection)
{
    GPIConnection *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return 0;
    return gpiProcess(connection, 0);
}
