/*
 * function: gpiDestroy
 * address:  0x02186788
 * packet:   pkt_ov009_02186788
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiDestroy (gpi.o)
 *
 * symbols:
 *   gpiDisconnect  0x0218B760  arm  ov009
 *   gpiStatusInfoKeysDestroy  0x0218D840  arm  ov009
 *   func_021846B4  0x021846B4  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 */

typedef struct GPIConnection {
    unsigned char pad[0x5C8];
    void *f5C8;
} GPIConnection;

extern void gpiDisconnect(void **connection, int tellServer);
extern void gpiStatusInfoKeysDestroy(void **connection);
extern void func_021846B4(void *table);
extern void gsifree(void *ptr);

void gpiDestroy(void **connection)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;

    gpiDisconnect(connection, 1);
    gpiStatusInfoKeysDestroy(connection);
    func_021846B4(iconnection->f5C8);
    gsifree(iconnection);
    *connection = 0;
}
