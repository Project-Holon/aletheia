/*
 * function: gpiAddCallback
 * address:  0x02189DFC
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiAddCallback: allocate a GPICallbackData (0x18 bytes), copy in the
 * callback struct, arg, type and the operation id (0 when operation is
 * NULL), then append it to the connection's callback list at +0x5dc (head) /
 * +0x5e0 (tail) with the next pointer at +0x14.
 *
 * The GPICallback parameter is a two-word struct passed by value, which is
 * why the prologue homes all four argument registers (push {r0-r3}) and the
 * epilogue is `pop {r4,r5,r6,lr}; add sp,#0x10; bx lr`.
 *
 * symbols:
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   gGpiCallbackErrorOutOfMemory     0x021A45C8  data
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

extern int *gsimalloc(int size);
extern void gpiSetErrorString(int *connection, int string);
extern char gGpiCallbackErrorOutOfMemory[];

int gpiAddCallback(int *connection, GPICallback callback, int arg, int *operation, int type)
{
    int *ic = (int *)*connection;
    GPICallbackData *data;

    data = (GPICallbackData *)gsimalloc(0x18);
    if (data == 0) {
        gpiSetErrorString(connection, (int)gGpiCallbackErrorOutOfMemory);
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
