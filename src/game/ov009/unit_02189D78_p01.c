/*
 * file:     unit_02189D78_p01.c
 * unit:     yes
 * function: func_02189D78, func_02189DFC
 * address:  0x02189D78
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
 *   g_021A45C8     0x021A45C8  data
 */
typedef struct {
    int callback;
    int param;
} GPICallback;

typedef struct {
    GPICallback callback;
    int arg;
    int type;
    int operationID;
    int pnext;
} GPICallbackData;

extern int *func_0217EAB0(int size);
extern void func_02193734(int *connection, int string);
int func_02189D78(int *connection, int a1, int a2);
int func_02189DFC(int *connection, GPICallback callback, int arg, int *operation, int type);
extern char g_021A45C8[];


/*
 * Fetch the connection's registered callback from iconnection+0x1a8, build a
 * 0x10-byte argument record ({arg1, iconnection+0x5b8, iconnection, arg2})
 * and hand both to func_02189DFC with callbackType 1.
 */
int func_02189D78(int *connection, int a1, int a2)
{
    int *ic = (int *)*connection;
    GPICallback cb;
    int *data;

    if (a2 == 1)
        ic[0x5bc / 4] = 1;
    cb.callback = ic[0x1a8 / 4];
    cb.param = ic[0x1ac / 4];
    if (cb.callback == 0)
        return cb.param;
    data = (int *)func_0217EAB0(0x10);
    if (data != 0) {
        data[0] = a1;
        data[3] = a2;
        data[1] = ic[0x5b8 / 4];
        data[2] = (int)ic;
    }
    return func_02189DFC(connection, cb, (int)data, 0, 1);
}


/*
 * gpiAddCallback: allocate a GPICallbackData (0x18 bytes), copy in the
 * callback struct, arg, type and the operation id (0 when operation is
 * NULL), then append it to the connection's callback list at +0x5dc (head) /
 * +0x5e0 (tail) with the next pointer at +0x14.
 *
 * The GPICallback parameter is a two-word struct passed by value, which is
 * why the prologue homes all four argument registers (push {r0-r3}) and the
 * epilogue is `pop {r4,r5,r6,lr}; add sp,#0x10; bx lr`.
 */
int func_02189DFC(int *connection, GPICallback callback, int arg, int *operation, int type)
{
    int *ic = (int *)*connection;
    GPICallbackData *data;

    data = (GPICallbackData *)func_0217EAB0(0x18);
    if (data == 0) {
        func_02193734(connection, (int)g_021A45C8);
        return 1;
    }
    data->callback = callback;
    data->arg = arg;
    if (operation != 0)
        data->operationID = *(int *)((char *)operation + 0x18);
    else
        data->operationID = 0;
    data->type = type;
    data->pnext = 0;
    if (ic[0x5dc / 4] == 0)
        ic[0x5dc / 4] = (int)data;
    if (ic[0x5e0 / 4] != 0)
        *(int *)(ic[0x5e0 / 4] + 0x14) = (int)data;
    ic[0x5e0 / 4] = (int)data;
    return 0;
}
