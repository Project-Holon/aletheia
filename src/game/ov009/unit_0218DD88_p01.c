/*
 * file:     unit_0218DD88_p01.c
 * unit:     yes
 * function: func_0218E114, func_0218E1CC
 * address:  0x0218E114
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
 *   gsimalloc          0x0217EAB0  arm
 *   gpiSetErrorString  0x02193734  arm
 *   g_021A4DF8         0x021A4DF8  data
 *   func_0217EB9C  0x0217EB9C  arm  ov009
 *   func_0217EB2C  0x0217EB2C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
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

struct GPIConnection_0218E114 {
    char pad0[0x234];
    int nextOperationID;                       /* +0x234 */
    char pad238[0x5c4 - 0x238];
    struct GPIOperation_s *operationList;      /* +0x5c4 */
};

struct GPIConnection_0218E1CC {
    char pad[0x238];
    int numSearches;
};

struct GPIOperation {
    int type;
    void *data;
};

struct GPISearchData {
    char pad0[4];
    int sock;
    void *a;
    char pad1[0xc];
    void *b;
};

extern void *gsimalloc(u32 size);
extern void gpiSetErrorString(void **connection, char *errorString);
extern int func_0217EB9C(int sock, int how);
extern int func_0217EB2C(int sock);
extern void func_0217EAE0(void *ptr);
int gpiAddOperation(void **connection, int type, void *data, struct GPIOperation_s **op, int blocking, void (*callback)(void **, void *, void *), void *param);
void func_0218E1CC(void **connection, struct GPIOperation *operation);
extern char g_021A4DF8[];


int gpiAddOperation(void **connection, int type, void *data,
                    struct GPIOperation_s **op, int blocking,
                    void (*callback)(void **, void *, void *), void *param)
{
    struct GPIConnection_0218E114 *iconnection = (struct GPIConnection_0218E114 *)*connection;
    struct GPIOperation_s *operation;

    operation = (struct GPIOperation_s *)gsimalloc(0x24);
    if (operation == 0) {
        gpiSetErrorString(connection, g_021A4DF8);
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


/*
 * sdk:      gpiDestroyOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void func_0218E1CC(void **connection, struct GPIOperation *operation)
{
    struct GPIConnection_0218E1CC *iconnection = (struct GPIConnection_0218E1CC *)*connection;

    if (operation->type == 3) {
        struct GPISearchData *data = (struct GPISearchData *)operation->data;

        iconnection->numSearches--;
        func_0217EB9C(data->sock, 2);
        func_0217EB2C(data->sock);
        func_0217EAE0(data->b);
        data->b = 0;
        func_0217EAE0(data->a);
        data->a = 0;
    }
    func_0217EAE0(operation->data);
    operation->data = 0;
    func_0217EAE0(operation);
}
