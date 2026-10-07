/*
 * file:     unit_0218DD88_p02.c
 * unit:     yes
 * function: func_0218E240, func_0218E290
 * address:  0x0218E240
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218E1CC  0x0218E1CC  arm  ov009
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

extern void func_0218E1CC(void **connection, struct GPIOperation *operation);
void func_0218E240(void **connection, struct GPIOperation *operation);
int func_0218E290(void **connection, struct GPIOperation **operation, int id);


/*
 * sdk:      gpiRemoveOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void func_0218E240(void **connection, struct GPIOperation *operation)
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
            func_0218E1CC(connection, operation);
            return;
        }
        pprev = pcurr;
    }
}


/*
 * sdk:      gpiFindOperationByID (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
int func_0218E290(void **connection, struct GPIOperation **operation, int id)
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
