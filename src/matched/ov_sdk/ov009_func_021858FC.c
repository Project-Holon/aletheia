/*
 * function: gpInitialize
 * address:  0x021858FC
 * packet:   pkt_ov009_021858FC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpInitialize (gp.o)
 *
 * symbols:
 *   gpiInitialize   0x02186664  arm
 *   __GSIACResult   0x021ACEF8  data
 */

extern int __GSIACResult;
extern int gpiInitialize(void **connection, int productID, int namespaceID, int partnerID);

int gpInitialize(void **connection, int productID, int namespaceID, int partnerID)
{
    if (__GSIACResult != 1)
        return 2;
    if (connection == 0)
        return 2;
    return gpiInitialize(connection, productID, namespaceID, partnerID);
}
