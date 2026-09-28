/*
 * function: gpGetNumBuddies
 * address:  0x02185FA4
 * packet:   pkt_ov009_02185FA4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpGetNumBuddies (gp.o)
 */

typedef struct GPIConnection GPIConnection;

int gpGetNumBuddies(void **connection, int *numBuddies)
{
    GPIConnection *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0) {
        *numBuddies = 0;
        return 0;
    }
    *numBuddies = *(int *)((char *)iconnection + 0x5d0);
    return 0;
}
