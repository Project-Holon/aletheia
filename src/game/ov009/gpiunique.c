/*
 * file:     gpiunique.c
 * unit:     yes
 * function: func_0219305C, func_0219316C
 * address:  0x0219305C
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
 *   g_021A5710     0x021a5710  data
 */
struct GPIOperation;
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

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {
    int result;
} GPRegisterCdKeyResponseArg;

extern int func_0219329C(int *connection, const char *input, int fatal);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(int *p, int b);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern void func_0218E240(void **connection, struct GPIOperation *operation);
int func_0219305C(void **connection, GPIOperation *operation, char *input);
int func_0219316C(void **connection, GPIOperation *operation, char *input);
extern char g_021A56C8[];
extern char g_021A56D0[];
extern char g_021A5700[];
extern char g_021A5710[];


/*
 * sdk:      gpiProcessRegisterUniqueNick (libdwcgsgp.TWL.HYB.a gpiunique.o)
 */
int func_0219305C(void **connection, GPIOperation *operation, char *input)
{
    GPICallback callback;
    GPRegisterUniqueNickResponseArg *arg;
    int __result__;

    if (func_0219329C((int *)connection, input, 1))
        return 4;
    if (func_020949F4((const u8 *)input, (const u8 *)g_021A56C8, 4) != 0) {
        func_02193710((int *)connection, 1, (int)g_021A56D0);
        __result__ = 3;
        func_02189D78((int *)connection, __result__, 1);
        return __result__;
    }
    callback = operation->callback;
    if (callback.callback != 0) {
        arg = (GPRegisterUniqueNickResponseArg *)func_0217EAB0(sizeof(GPRegisterUniqueNickResponseArg));
        if (arg == 0) {
            func_02193734((int *)connection, (int)g_021A5700);
            return 1;
        }
        arg->result = 0;
        __result__ = func_02189DFC(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    func_0218E240(connection, (struct GPIOperation *)operation);
    return 0;
}


/*
 * sdk:      gpiProcessRegisterCdKey (libdwcgsgp.TWL.HYB.a gpiunique.o)
 */
int func_0219316C(void **connection, GPIOperation *operation, char *input)
{
    GPICallback callback;
    GPRegisterCdKeyResponseArg *arg;
    int __result__;

    if (func_0219329C((int *)connection, input, 1))
        return 4;
    if (func_020949F4((const u8 *)input, (const u8 *)g_021A5710, 4) != 0) {
        func_02193710((int *)connection, 1, (int)g_021A56D0);
        __result__ = 3;
        func_02189D78((int *)connection, __result__, 1);
        return __result__;
    }
    callback = operation->callback;
    if (callback.callback != 0) {
        arg = (GPRegisterCdKeyResponseArg *)func_0217EAB0(sizeof(GPRegisterCdKeyResponseArg));
        if (arg == 0) {
            func_02193734((int *)connection, (int)g_021A5700);
            return 1;
        }
        arg->result = 0;
        __result__ = func_02189DFC(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    func_0218E240(connection, (struct GPIOperation *)operation);
    return 0;
}
