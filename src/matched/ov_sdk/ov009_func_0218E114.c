/*
 * function: gpiAddOperation
 * address:  0x0218E114
 * packet:   pkt_ov009_0218E114
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiAddOperation (gpioperation.o)
 *
 * symbols:
 *   gsimalloc          0x0217EAB0  arm
 *   gpiSetErrorString  0x02193734  arm
 *   gGpiOperationErrorOutOfMemory         0x021A4DF8  data
 */

typedef unsigned long u32;

struct GPICallback {
    void (*handler)(void **, void *, void *);  /* +0x0c */
    void *param;                               /* +0x10 */
};

struct GPIOperation_s {
    int type;                            /* +0x00 */
    void *data;                          /* +0x04 */
    int blocking;                        /* +0x08 */
    struct GPICallback callback;         /* +0x0c */
    int state;                           /* +0x14 */
    int id;                              /* +0x18 */
    int result;                          /* +0x1c */
    struct GPIOperation_s *pnext;        /* +0x20 */
};

struct GPIConnection {
    char pad0[0x234];
    int nextOperationID;                       /* +0x234 */
    char pad238[0x5c4 - 0x238];
    struct GPIOperation_s *operationList;      /* +0x5c4 */
};

extern void *gsimalloc(u32 size);
extern void gpiSetErrorString(void **connection, char *errorString);
extern char gGpiOperationErrorOutOfMemory[];

int gpiAddOperation(void **connection, int type, void *data,
                    struct GPIOperation_s **op, int blocking,
                    void (*callback)(void **, void *, void *), void *param)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;
    struct GPIOperation_s *operation;

    operation = (struct GPIOperation_s *)gsimalloc(0x24);
    if (operation == 0) {
        gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
        return 1;
    }
    operation->type = type;
    operation->data = data;
    operation->blocking = blocking;
    operation->state = 0;
    if (type == 0) {
        operation->id = 1;
    } else {
        operation->id = iconnection->nextOperationID++;
        if (iconnection->nextOperationID < 2)
            iconnection->nextOperationID = 2;
    }
    operation->result = 0;
    operation->callback.handler = callback;
    operation->callback.param = param;
    operation->pnext = iconnection->operationList;
    iconnection->operationList = operation;
    *op = operation;
    return 0;
}
