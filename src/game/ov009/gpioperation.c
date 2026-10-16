/*
 * file:     gpioperation.c
 * unit:     yes
 * function: gpiFailedOpCallback, gpiAddOperation, gpiDestroyOperation, gpiRemoveOperation, gpiFindOperationByID, gpiOperationsAreBlocking, gpiProcessOperation
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
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   gpiAddCallback  0x02189DFC  arm  ov009
 *   gGpiOperationErrorOutOfMemory     0x021A4DF8  data
 *   gsimalloc          0x0217EAB0  arm
 *   gpiSetErrorString  0x02193734  arm
 *   shutdown  0x0217EB9C  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   gpiProcessConnect  0x0218AE9C  arm  ov009
 *   gpiProcessNewProfile  0x0218FB68  arm  ov009
 *   gpiProcessDeleteProfle  0x0218FDD8  arm  ov009
 *   gpiProcessGetInfo  0x0218BDB8  arm  ov009
 *   gpiProcessRegisterUniqueNick  0x0219305C  arm  ov009
 *   gpiProcessRegisterCdKey  0x0219316C  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gGpiOperationDebugInvalidTypeFmt  0x021A4E08  data
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

extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(void **connection, char *errorString);
extern void *MSL_C_LIB_MemsetPtr(void *dst, int c, unsigned long n);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, const GPIOperation *operation, int type);
extern void *gsimalloc(u32 size);
extern void gpiSetErrorString(void **connection, char *errorString);
extern int shutdown(int sock, int how);
extern int closesocket(int sock);
extern void gsifree(void *ptr);
extern int gpiProcessConnect(void **connection, GPIOperation *operation, char *input);
extern int gpiProcessNewProfile(void **connection, GPIOperation *operation, char *input);
extern int gpiProcessDeleteProfle(void **connection, GPIOperation *operation, char *input);
extern int gpiProcessGetInfo(void **connection, GPIOperation *operation, char *input);
extern int gpiProcessRegisterUniqueNick(void **connection, GPIOperation *operation, char *input);
extern int gpiProcessRegisterCdKey(void **connection, GPIOperation *operation, char *input);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
int gpiFailedOpCallback(void **connection, const GPIOperation *operation);
int gpiAddOperation(void **connection, int type, void *data, GPIOperation **op, int blocking, void (*callback)(void **, void *, void *), void *param);
/*
 * sdk: gpiDestroyOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void gpiDestroyOperation(void **connection, GPIOperation *operation);
/*
 * sdk: gpiRemoveOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void gpiRemoveOperation(void **connection, GPIOperation *operation);
/*
 * sdk: gpiFindOperationByID (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
int gpiFindOperationByID(void **connection, GPIOperation **operation, int id);
/*
 * Walks the +0x5c4 list; true as soon as a node has a non-zero +8 word and * a first word other than 3.
 */
int gpiOperationsAreBlocking(char *p);
/*
 * sdk: gpiProcessOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
int gpiProcessOperation(void **connection, GPIOperation *operation, char *input);
extern char gGpiOperationErrorOutOfMemory[];
extern char gGpiOperationDebugInvalidTypeFmt[];


/*
 * sdk:      gpiFailedOpCallback (libdwcgsgp.TWL.HYB.a gpioperation.o)
 *
 * Dispatches a completed GSI GP operation: allocates the response struct for
 * the operation type, zeroes it, copies operation->result into it and calls
 * gpiAddCallback to hand it to the application callback.
 *
 * The 60-byte residue in cases 1/4/5/6 was the load of `operation->result`
 * trading places with the tail of the inline zeroing store run. Declaring the
 * `operation` parameter (and the matching parameter of gpiAddCallback)
 * `const GPIOperation *` lets the scheduler hoist the load through the
 * otherwise-aliasing stores. Same idiom as
 * docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_0218DD88.c  *     --func gpiFailedOpCallback --addr 0x0218DD88 --region ov009 --arm --lang c99 --diff
 */
int gpiFailedOpCallback(void **connection, const GPIOperation *operation)
{
    GPICallback callback;
    GPIConnection *iconnection;

    iconnection = (GPIConnection *)*connection;
    callback = operation->callback;
    if (callback.callback) {
        switch (operation->type) {
        case 0: {
            GPConnectResponseArg *arg;
            arg = (GPConnectResponseArg *)gsimalloc(sizeof(GPConnectResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            MSL_C_LIB_MemsetPtr(arg, 0, sizeof(GPConnectResponseArg));
            arg->result = operation->result;
            if (iconnection->errorCode == 0x201) {
                arg->profile = iconnection->profileid;
                iconnection->profileid = 0;
            }
            {
                int __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 1: {
            GPNewProfileResponseArg *arg;
            arg = (GPNewProfileResponseArg *)gsimalloc(sizeof(GPNewProfileResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPNewProfileResponseArg));
            arg->result = operation->result;
            {
                int __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 5: {
            GPDeleteProfileResponseArg *arg;
            arg = (GPDeleteProfileResponseArg *)gsimalloc(sizeof(GPDeleteProfileResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPDeleteProfileResponseArg));
            arg->result = operation->result;
            {
                int __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 2: {
            GPGetInfoResponseArg *arg;
            arg = (GPGetInfoResponseArg *)gsimalloc(sizeof(GPGetInfoResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            MSL_C_LIB_MemsetPtr(arg, 0, sizeof(GPGetInfoResponseArg));
            arg->result = operation->result;
            {
                int __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 3: {
            GPProfileSearchResponseArg *arg;
            arg = (GPProfileSearchResponseArg *)gsimalloc(sizeof(GPProfileSearchResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPProfileSearchResponseArg));
            arg->result = operation->result;
            arg->matches = 0;
            {
                int __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 4: {
            GPRegisterUniqueNickResponseArg *arg;
            arg = (GPRegisterUniqueNickResponseArg *)gsimalloc(sizeof(GPRegisterUniqueNickResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPRegisterUniqueNickResponseArg));
            arg->result = operation->result;
            {
                int __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 6: {
            GPRegisterCdKeyResponseArg *arg;
            arg = (GPRegisterCdKeyResponseArg *)gsimalloc(sizeof(GPRegisterCdKeyResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPRegisterCdKeyResponseArg));
            arg->result = operation->result;
            {
                int __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
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
void gpiDestroyOperation(void **connection, GPIOperation *operation)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;

    if (operation->type == 3) {
        struct GPISearchData *data = (struct GPISearchData *)operation->data;

        iconnection->numSearches--;
        shutdown(data->sock, 2);
        closesocket(data->sock);
        gsifree(data->b);
        data->b = 0;
        gsifree(data->a);
        data->a = 0;
    }
    gsifree(operation->data);
    operation->data = 0;
    gsifree(operation);
}




/*
 * sdk:      gpiRemoveOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void gpiRemoveOperation(void **connection, GPIOperation *operation)
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
            gpiDestroyOperation(connection, operation);
            return;
        }
        pprev = pcurr;
    }
}



/*
 * sdk:      gpiFindOperationByID (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
int gpiFindOperationByID(void **connection, GPIOperation **operation, int id)
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
int gpiOperationsAreBlocking(char *p)
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
int gpiProcessOperation(void **connection, GPIOperation *operation, char *input)
{
    int result = 0;

    switch (operation->type) {
    case 0:
        result = gpiProcessConnect(connection, (GPIOperation *)operation, input);
        break;
    case 1:
        result = gpiProcessNewProfile(connection, (GPIOperation *)operation, input);
        break;
    case 5:
        result = gpiProcessDeleteProfle(connection, (GPIOperation *)operation, input);
        break;
    case 2:
        result = gpiProcessGetInfo(connection, (GPIOperation *)operation, input);
        break;
    case 4:
        result = gpiProcessRegisterUniqueNick(connection, (GPIOperation *)operation, input);
        break;
    case 6:
        result = gpiProcessRegisterCdKey(connection, (GPIOperation *)operation, input);
        break;
    default:
        gsDebugFormat(1, (char *)4, 1, gGpiOperationDebugInvalidTypeFmt, operation->type);
        break;
    }
    if (result != 0)
        operation->result = result;
    return result;
}
