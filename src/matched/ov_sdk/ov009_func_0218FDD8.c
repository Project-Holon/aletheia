/*
 * function: func_0218FDD8
 * address:  0x0218FDD8
 * packet:   pkt_ov009_0218FDD8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessDeleteProfle (libdwcgsgp.TWL.HYB.a gpiprofile.o)
 *
 * symbols:
 *   func_0219329C  0x0219329c  arm   ov009
 *   func_020949F4  0x020949f4  arm
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189d78  arm   ov009
 *   func_0217EAB0  0x0217eab0  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_02189DFC  0x02189dfc  arm   ov009
 *   func_0218E240  0x0218e240  arm   ov009
 *   g_021A5224     0x021a5224  data
 *   g_021A51D8     0x021a51d8  data
 *   g_021A5214     0x021a5214  data
 */

typedef struct GPICallback {
    void (*callback)(void **, void *, void *);
    void *param;
} GPICallback;

typedef struct GPIOperation_s {
    int type;
    void *data;
    int blocking;
    GPICallback callback;
} GPIOperation;

typedef struct {
    int result;
    int profile;
} GPDeleteProfileResponseArg;

typedef struct {
    char pad[0x1a0];
    int profileid;
} GPIConnection;

extern int func_0219329C(void **connection, char *input, int callErrorCallback);
extern int func_020949F4(const char *, const char *, unsigned int);
extern void func_02193710(void **connection, int errorCode, char *errorString);
extern void func_02189D78(void **connection, int result, int fatal);
extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(void **connection, char *errorString);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern void func_0218E240(void **connection, GPIOperation *operation);
extern char g_021A5224[];
extern char g_021A51D8[];
extern char g_021A5214[];

int func_0218FDD8(void **connection, GPIOperation *operation, char *input)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPICallback callback;
    GPDeleteProfileResponseArg *arg;
    int __result__;

    if (func_0219329C(connection, input, 1))
        return 4;
    if (func_020949F4(input, g_021A5224, 5) != 0) {
        func_02193710(connection, 1, g_021A51D8);
        func_02189D78(connection, 3, 1);
        return 3;
    }
    callback = operation->callback;
    if (operation->callback.callback != 0) {
        arg = (GPDeleteProfileResponseArg *)func_0217EAB0(sizeof(GPDeleteProfileResponseArg));
        if (arg == 0) {
            func_02193734(connection, g_021A5214);
            return 1;
        }
        arg->profile = iconnection->profileid;
        arg->result = 0;
        __result__ = func_02189DFC(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    func_0218E240(connection, operation);
    return 0;
}
