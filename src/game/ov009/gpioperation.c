/*
 * file:     gpioperation.c
 * unit:     yes
 * function: func_0218DD88, func_0218E114, func_0218E1CC, func_0218E240, func_0218E290, func_0218E2DC, func_0218E318
 * address:  0x0218DD88
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
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   func_020923B0  0x020923B0  arm
 *   func_02189DFC  0x02189DFC  arm  ov009
 *   g_021A4DF8     0x021A4DF8  data
 *   gsimalloc          0x0217EAB0  arm
 *   gpiSetErrorString  0x02193734  arm
 *   func_0217EB9C  0x0217EB9C  arm  ov009
 *   func_0217EB2C  0x0217EB2C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_0218AE9C  0x0218AE9C  arm  ov009
 *   func_0218FB68  0x0218FB68  arm  ov009
 *   func_0218FDD8  0x0218FDD8  arm  ov009
 *   func_0218BDB8  0x0218BDB8  arm  ov009
 *   func_0219305C  0x0219305C  arm  ov009
 *   func_0219316C  0x0219316C  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021A4E08  0x021A4E08  data
 */
typedef struct GPICallback {
    void (*callback)(void **, void *, void *);
    void *param;
} GPICallback;

typedef struct GPIOperation_s {
    int type;                        /* 0x00 */
    void *data;                      /* 0x04 */
    int blocking;                    /* 0x08 */
    GPICallback callback;            /* 0x0C */
    int state;                       /* 0x14 */
    int id;                          /* 0x18 */
    int result;                      /* 0x1C */
    struct GPIOperation_s *pnext;    /* 0x20 */
} GPIOperation;

typedef struct GPIConnection {
    char pad000[0x1A0];
    int profileid;                   /* 0x1A0 */
    char pad1A4[0x234 - 0x1A4];
    int nextOperationID;             /* 0x234 */
    int numSearches;                 /* 0x238 */
    char pad23C[0x5B8 - 0x23C];
    int errorCode;                   /* 0x5B8 */
    char pad5BC[0x5C4 - 0x5BC];
    GPIOperation *operationList;     /* 0x5C4 */
} GPIConnection;

typedef struct GPConnectResponseArg {
    int result;
    int profile;
    char uniquenick[24];
} GPConnectResponseArg;

typedef struct GPNewProfileResponseArg {
    int result;
    int profile;
} GPNewProfileResponseArg;

typedef struct GPDeleteProfileResponseArg {
    int result;
    int profile;
} GPDeleteProfileResponseArg;

typedef struct GPGetInfoResponseArg {
    int result;
    char pad004[0x200];
} GPGetInfoResponseArg;

typedef struct GPProfileSearchResponseArg {
    int result;
    int numMatches;
    int more;
    void *matches;
} GPProfileSearchResponseArg;

typedef struct GPRegisterUniqueNickResponseArg {
    int result;
} GPRegisterUniqueNickResponseArg;

typedef struct GPRegisterCdKeyResponseArg {
    int result;
} GPRegisterCdKeyResponseArg;

typedef unsigned long u32;

struct GPISearchData {
    char pad0[4];
    int sock;
    void *a;
    char pad1[0xc];
    void *b;
};

extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(void **connection, char *errorString);
extern void *func_020923B0(void *dst, int c, unsigned long n);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, const GPIOperation *operation, int type);
extern void *gsimalloc(u32 size);
extern void gpiSetErrorString(void **connection, char *errorString);
extern int func_0217EB9C(int sock, int how);
extern int func_0217EB2C(int sock);
extern void func_0217EAE0(void *ptr);
extern int func_0218AE9C(void **connection, GPIOperation *operation, char *input);
extern int func_0218FB68(void **connection, GPIOperation *operation, char *input);
extern int func_0218FDD8(void **connection, GPIOperation *operation, char *input);
extern int func_0218BDB8(void **connection, GPIOperation *operation, char *input);
extern int func_0219305C(void **connection, GPIOperation *operation, char *input);
extern int func_0219316C(void **connection, GPIOperation *operation, char *input);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
int func_0218DD88(void **connection, const GPIOperation *operation);
int gpiAddOperation(void **connection, int type, void *data, GPIOperation **op, int blocking, void (*callback)(void **, void *, void *), void *param);
/*
 * sdk: gpiDestroyOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void func_0218E1CC(void **connection, GPIOperation *operation);
/*
 * sdk: gpiRemoveOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void func_0218E240(void **connection, GPIOperation *operation);
/*
 * sdk: gpiFindOperationByID (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
int func_0218E290(void **connection, GPIOperation **operation, int id);
/*
 * Walks the +0x5c4 list; true as soon as a node has a non-zero +8 word and * a first word other than 3.
 */
int func_0218E2DC(char *p);
/*
 * sdk: gpiProcessOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
int func_0218E318(void **connection, GPIOperation *operation, char *input);
extern char g_021A4DF8[];
extern char g_021A4E08[];


/*
 * sdk:      gpiFailedOpCallback (libdwcgsgp.TWL.HYB.a gpioperation.o)
 *
 * Dispatches a completed GSI GP operation: allocates the response struct for
 * the operation type, zeroes it, copies operation->result into it and calls
 * func_02189DFC to hand it to the application callback.
 *
 * The 60-byte residue in cases 1/4/5/6 was the load of `operation->result`
 * trading places with the tail of the inline zeroing store run. Declaring the
 * `operation` parameter (and the matching parameter of func_02189DFC)
 * `const GPIOperation *` lets the scheduler hoist the load through the
 * otherwise-aliasing stores. Same idiom as
 * docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_0218DD88.c  *     --func func_0218DD88 --addr 0x0218DD88 --region ov009 --arm --lang c99 --diff
 */
int func_0218DD88(void **connection, const GPIOperation *operation)
{
    GPICallback callback;
    GPIConnection *iconnection;

    iconnection = (GPIConnection *)*connection;
    callback = operation->callback;
    if (callback.callback) {
        switch (operation->type) {
        case 0: {
            GPConnectResponseArg *arg;
            arg = (GPConnectResponseArg *)func_0217EAB0(sizeof(GPConnectResponseArg));
            if (arg == 0) {
                func_02193734(connection, g_021A4DF8);
                return 1;
            }
            func_020923B0(arg, 0, sizeof(GPConnectResponseArg));
            arg->result = operation->result;
            if (iconnection->errorCode == 0x201) {
                arg->profile = iconnection->profileid;
                iconnection->profileid = 0;
            }
            {
                int __result__ = func_02189DFC(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 1: {
            GPNewProfileResponseArg *arg;
            arg = (GPNewProfileResponseArg *)func_0217EAB0(sizeof(GPNewProfileResponseArg));
            if (arg == 0) {
                func_02193734(connection, g_021A4DF8);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPNewProfileResponseArg));
            arg->result = operation->result;
            {
                int __result__ = func_02189DFC(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 5: {
            GPDeleteProfileResponseArg *arg;
            arg = (GPDeleteProfileResponseArg *)func_0217EAB0(sizeof(GPDeleteProfileResponseArg));
            if (arg == 0) {
                func_02193734(connection, g_021A4DF8);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPDeleteProfileResponseArg));
            arg->result = operation->result;
            {
                int __result__ = func_02189DFC(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 2: {
            GPGetInfoResponseArg *arg;
            arg = (GPGetInfoResponseArg *)func_0217EAB0(sizeof(GPGetInfoResponseArg));
            if (arg == 0) {
                func_02193734(connection, g_021A4DF8);
                return 1;
            }
            func_020923B0(arg, 0, sizeof(GPGetInfoResponseArg));
            arg->result = operation->result;
            {
                int __result__ = func_02189DFC(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 3: {
            GPProfileSearchResponseArg *arg;
            arg = (GPProfileSearchResponseArg *)func_0217EAB0(sizeof(GPProfileSearchResponseArg));
            if (arg == 0) {
                func_02193734(connection, g_021A4DF8);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPProfileSearchResponseArg));
            arg->result = operation->result;
            arg->matches = 0;
            {
                int __result__ = func_02189DFC(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 4: {
            GPRegisterUniqueNickResponseArg *arg;
            arg = (GPRegisterUniqueNickResponseArg *)func_0217EAB0(sizeof(GPRegisterUniqueNickResponseArg));
            if (arg == 0) {
                func_02193734(connection, g_021A4DF8);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPRegisterUniqueNickResponseArg));
            arg->result = operation->result;
            {
                int __result__ = func_02189DFC(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 6: {
            GPRegisterCdKeyResponseArg *arg;
            arg = (GPRegisterCdKeyResponseArg *)func_0217EAB0(sizeof(GPRegisterCdKeyResponseArg));
            if (arg == 0) {
                func_02193734(connection, g_021A4DF8);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPRegisterCdKeyResponseArg));
            arg->result = operation->result;
            {
                int __result__ = func_02189DFC(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }
        }
    }

    return 0;
}



int gpiAddOperation(void **connection, int type, void *data,
                    GPIOperation **op, int blocking,
                    void (*callback)(void **, void *, void *), void *param)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
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
    operation->callback.callback = callback;
    operation->callback.param = param;
    operation->pnext = iconnection->operationList;
    iconnection->operationList = operation;
    *op = operation;
    return 0;
}



/*
 * sdk:      gpiDestroyOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void func_0218E1CC(void **connection, GPIOperation *operation)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;

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




/*
 * sdk:      gpiRemoveOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void func_0218E240(void **connection, GPIOperation *operation)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIOperation *pcurr;
    GPIOperation *pprev = 0;

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
int func_0218E290(void **connection, GPIOperation **operation, int id)
{
    GPIOperation *op;

    for (op = ((GPIConnection *)*connection)->operationList; op != 0; op = op->pnext) {
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



/*
 * Walks the +0x5c4 list; true as soon as a node has a non-zero +8 word and
 * a first word other than 3.
 */
int func_0218E2DC(char *p)
{
    char *q = *(char **)(*(char **)p + 0x5c4);

    while (q != 0) {
        if (*(int *)(q + 8) != 0 && *(int *)q != 3) return 1;
        q = *(char **)(q + 0x20);
    }
    return 0;
}




/*
 * sdk:      gpiProcessOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
int func_0218E318(void **connection, GPIOperation *operation, char *input)
{
    int result = 0;

    switch (operation->type) {
    case 0:
        result = func_0218AE9C(connection, (GPIOperation *)operation, input);
        break;
    case 1:
        result = func_0218FB68(connection, (GPIOperation *)operation, input);
        break;
    case 5:
        result = func_0218FDD8(connection, (GPIOperation *)operation, input);
        break;
    case 2:
        result = func_0218BDB8(connection, (GPIOperation *)operation, input);
        break;
    case 4:
        result = func_0219305C(connection, (GPIOperation *)operation, input);
        break;
    case 6:
        result = func_0219316C(connection, (GPIOperation *)operation, input);
        break;
    default:
        func_0217D254(1, (char *)4, 1, g_021A4E08, operation->type);
        break;
    }
    if (result != 0)
        operation->result = result;
    return result;
}
