/*
 * function: gpiRemoveOperation
 * address:  0x0218E240
 * packet:   pkt_ov009_0218E240
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiRemoveOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 *
 * symbols:
 *   gpiDestroyOperation  0x0218E1CC  arm  ov009
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

extern void gpiDestroyOperation(void **connection, struct GPIOperation *operation);

void gpiRemoveOperation(void **connection, struct GPIOperation *operation)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;
    struct GPIOperation *pcurr;
    struct GPIOperation *pprev = 0;

    for (pcurr = iconnection->operationList; pcurr != 0; pcurr = pcurr->pnext) {
        if (pcurr == operation) {
            if (pprev == 0)
                iconnection->operationList = pcurr->pnext;
            else
                pprev->pnext = operation->pnext;
            gpiDestroyOperation(connection, operation);
            return;
        }
        pprev = pcurr;
    }
}
