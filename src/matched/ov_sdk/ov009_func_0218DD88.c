/*
 * function: gpiFailedOpCallback
 * address:  0x0218DD88
 * packet:   pkt_ov009_0218DD88
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   gpiAddCallback  0x02189DFC  arm  ov009
 *   g_021A4DF8     0x021A4DF8  data
 */
typedef struct GPICallback {
    void *callback;
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
    char pad1A4[0x414];
    int errorCode;                   /* 0x5B8 */
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

extern char g_021A4DF8[];

extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(void **connection, char *errorString);
extern void *MSL_C_LIB_MemsetPtr(void *dst, int c, unsigned long n);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, const GPIOperation *operation, int type);

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
                gpiSetErrorString(connection, g_021A4DF8);
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
                gpiSetErrorString(connection, g_021A4DF8);
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
                gpiSetErrorString(connection, g_021A4DF8);
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
                gpiSetErrorString(connection, g_021A4DF8);
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
                gpiSetErrorString(connection, g_021A4DF8);
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
                gpiSetErrorString(connection, g_021A4DF8);
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
                gpiSetErrorString(connection, g_021A4DF8);
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
