/*
 * function: func_0219305C
 * address:  0x0219305C
 * packet:   pkt_ov009_0219305C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessRegisterUniqueNick (libdwcgsgp.TWL.HYB.a gpiunique.o)
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
 *   g_021A56C8     0x021a56c8  data
 *   g_021A56D0     0x021a56d0  data
 *   g_021A5700     0x021a5700  data
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
} GPRegisterUniqueNickResponseArg;

extern int func_0219329C(void **connection, char *input, int callErrorCallback);
extern int func_020949F4(const char *, const char *, unsigned int);
extern void func_02193710(void **connection, int errorCode, char *errorString);
extern void func_02189D78(void **connection, int result, int fatal);
extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(void **connection, char *errorString);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern void func_0218E240(void **connection, GPIOperation *operation);
extern char g_021A56C8[];
extern char g_021A56D0[];
extern char g_021A5700[];

int func_0219305C(void **connection, GPIOperation *operation, char *input)
{
    GPICallback callback;
    GPRegisterUniqueNickResponseArg *arg;
    int __result__;

    if (func_0219329C(connection, input, 1))
        return 4;
    if (func_020949F4(input, g_021A56C8, 4) != 0) {
        func_02193710(connection, 1, g_021A56D0);
        __result__ = 3;
        func_02189D78(connection, __result__, 1);
        return __result__;
    }
    callback = operation->callback;
    if (callback.callback != 0) {
        arg = (GPRegisterUniqueNickResponseArg *)func_0217EAB0(sizeof(GPRegisterUniqueNickResponseArg));
        if (arg == 0) {
            func_02193734(connection, g_021A5700);
            return 1;
        }
        arg->result = 0;
        __result__ = func_02189DFC(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    func_0218E240(connection, operation);
    return 0;
}
