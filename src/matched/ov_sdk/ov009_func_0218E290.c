/*
 * function: gpiFindOperationByID
 * address:  0x0218E290
 * packet:   pkt_ov009_0218E290
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiFindOperationByID (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 *
 * symbols:
 */

struct GPIConnection {
    char pad[0x5c4];
    struct GPIOperation *operationList;
};

struct GPIOperation {
    int type;
    void *data;
    char pad[0x10];
    int id;
    int result;
    struct GPIOperation *pnext;
};

int gpiFindOperationByID(void **connection, struct GPIOperation **operation, int id)
{
    struct GPIOperation *op;

    for (op = ((struct GPIConnection *)*connection)->operationList; op != 0; op = op->pnext) {
        if (op->id == id) {
            if (operation != 0)
                *operation = op;
            return 1;
        }
    }
    if (operation != 0)
        *operation = 0;
    return 0;
}
