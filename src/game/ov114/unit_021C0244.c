/*
 * file:     unit_021C0244.c
 * unit:     yes
 * function: func_021C0244, func_021C02C8, func_021C0318
 * address:  0x021C0244
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021CE598    0x021CE598  data  a4
 *   func_0217D254 0x0217D254  arm
 *   ArrayLength  0x02184200 arm ov009
 */
#include "ghttp_types.h"


extern int func_0217D254(int, int, int, void *, int);
extern int ArrayLength(void *array);
void func_021C0244(GHIConnection *ctx);
void func_021C02C8(GHIConnection *connection, char *buffer, int bufferLen);
void func_021C0318(GHIConnection *connection);
extern int d_021CE598[];


void func_021C0244(GHIConnection *ctx)
{
    if (ctx->result != 0)
        func_0217D254(8, 0, 2, d_021CE598, ctx->socketError);
    if (ctx->completedCallback != 0) {
        char *r5 = ctx->type == 0 ? ctx->getFileBuffer.data : 0;
        int res = ctx->completedCallback(ctx->request, ctx->result, r5, ctx->fileBytesReceived, ctx->callbackParam);
        if (r5 == 0)
            return;
        if (res == 0)
            ctx->getFileBuffer.dontFree = 1;
    }
}


void func_021C02C8(GHIConnection *connection, char *buffer, int bufferLen)
{
    if (connection->progressCallback != 0)
        connection->progressCallback(connection->request, connection->state, buffer, bufferLen, connection->fileBytesReceived, connection->totalSize, connection->callbackParam);
}


/*
 * sdk:      ghiCallPostCallback (ghttpcallbacks)
 */
void func_021C0318(GHIConnection *connection)
{
    if (connection->postingState.callback != 0)
        connection->postingState.callback(connection->request, connection->postingState.bytesPosted, connection->postingState.totalBytes, connection->postingState.index, ArrayLength(connection->postingState.states), connection->callbackParam);
}
