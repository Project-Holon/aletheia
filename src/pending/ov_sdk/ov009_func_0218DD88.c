/*
 * function: func_0218DD88
 * address:  0x0218DD88
 * packet:   pkt_ov009_0218DD88
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gpiFailedOpCallback (libdwcgsgp.TWL.HYB.a gpioperation.o)
 *
 * symbols:
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   func_020923B0  0x020923B0  arm
 *   func_02189DFC  0x02189DFC  arm  ov009
 *   g_021A4DF8     0x021A4DF8  data
 *
 * notes: DIFF, 60 bytes, same size (908). Cases 0 (0x20) and 2 (0x204) call
 * memset in the object; cases 1, 5, 4, 6 zero with inline strb runs, which
 * __builtin__clear reproduces. Residue in those four cases only: the object
 * schedules `ldr r0, [r7, #0x1c]` (operation->result) above the last clear
 * strb and colours it r0; ours keeps it after the run in r1, then orders
 * mov r0, r8 before the stores. Case 3 (16-byte clear loop) is exact.
 * Tried: memset named call (not inlined by any dsi build), clear on
 * (char *)arg and sizeof(*arg), a result temp read before the clear (hoists
 * to the top), a zero struct assignment, dsi 1.2 through 1.6sp1 (1.2-1.3p1
 * give the same 60 bytes).
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

extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(void **connection, char *errorString);
extern void *func_020923B0(void *dst, int c, unsigned long n);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);

int func_0218DD88(void **connection, GPIOperation *operation)
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
