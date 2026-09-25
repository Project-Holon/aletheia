/*
 * function: func_02189D78
 * address:  0x02189D78
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Fetch the connection's registered callback from iconnection+0x1a8, build a
 * 0x10-byte argument record ({arg1, iconnection+0x5b8, iconnection, arg2})
 * and hand both to func_02189DFC with callbackType 1.
 *
 * symbols:
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02189DFC  0x02189DFC  arm  ov009
 */

typedef struct {
    int callback;
    int param;
} GPICallback;

extern int *func_0217EAB0(int size);
extern int func_02189DFC(int *connection, GPICallback callback, int arg, int *operation, int type);

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
