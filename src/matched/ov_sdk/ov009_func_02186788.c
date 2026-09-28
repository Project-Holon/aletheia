/*
 * function: func_02186788
 * address:  0x02186788
 * packet:   pkt_ov009_02186788
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      gpiDestroy (gpi.o)
 *
 * symbols:
 *   func_0218B760  0x0218B760  arm  ov009
 *   func_0218D840  0x0218D840  arm  ov009
 *   func_021846B4  0x021846B4  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 */

typedef struct GPIConnection {
    unsigned char pad[0x5C8];
    void *f5C8;
} GPIConnection;

extern void func_0218B760(void **connection, int tellServer);
extern void func_0218D840(void **connection);
extern void func_021846B4(void *table);
extern void func_0217EAE0(void *ptr);

void func_02186788(void **connection)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;

    func_0218B760(connection, 1);
    func_0218D840(connection);
    func_021846B4(iconnection->f5C8);
    func_0217EAE0(iconnection);
    *connection = 0;
}
