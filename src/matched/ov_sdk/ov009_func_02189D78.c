/*
 * function: gpiCallErrorCallback
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
 * and hand both to gpiAddCallback with callbackType 1.
 *
 * symbols:
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   gpiAddCallback  0x02189DFC  arm  ov009
 */

typedef struct {
    int callback;
    int param;
} GPICallback;

extern int *gsimalloc(int size);
extern int gpiAddCallback(int *connection, GPICallback callback, int arg, int *operation, int type);

int gpiCallErrorCallback(int *connection, int a1, int a2)
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
    data = (int *)gsimalloc(0x10);
    if (data != 0) {
        data[0] = a1;
        data[3] = a2;
        data[1] = ic[0x5b8 / 4];
        data[2] = (int)ic;
    }
    return gpiAddCallback(connection, cb, (int)data, 0, 1);
}
