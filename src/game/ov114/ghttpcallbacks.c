/*
 * file:     ghttpcallbacks.c
 * unit:     yes
 * function: ghiCallCompletedCallback, ghiCallProgressCallback, ghiCallPostCallback, ghiInitLock, ghiFreeLock, ghiLock, ghiUnlock
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
 *   sGhttpSocketError    0x021CE598  data  a4
 *   gsDebugFormat 0x0217D254  arm
 *   ArrayLength  0x02184200 arm ov009
 */
#include "ghttp_types.h"

#include "../ov009/gsdebug.h"
#include "../ov009/darray.h"
void ghiCallCompletedCallback(GHIConnection *connection);
/*
 * sdk:      ghiCallProgressCallback (ghttpcallbacks)
 */
void ghiCallProgressCallback(GHIConnection *connection, char *buffer, int bufferLen);
void ghiCallPostCallback(GHIConnection *connection);
void ghiInitLock(void);
void ghiFreeLock(void);
void ghiLock(void);
void ghiUnlock(void);
extern char sGhttpSocketError[];



/*
 * sdk:      ghiCallCompletedCallback (ghttpcallbacks)
 */
void ghiCallCompletedCallback(GHIConnection *connection)
{
    if (connection->result != 0)
        gsDebugFormat(8, 0, 2, sGhttpSocketError, connection->socketError);
    if (connection->completedCallback != 0) {
        char *fileData = connection->type == 0 ? connection->getFileBuffer.data : 0;
        int freeFileData = connection->completedCallback(connection->request, connection->result, fileData, connection->fileBytesReceived, connection->callbackParam);
        if (fileData == 0)
            return;
        if (freeFileData == 0)
            connection->getFileBuffer.dontFree = 1;
    }
}



/*
 * sdk:      ghiCallProgressCallback (ghttpcallbacks)
 */
void ghiCallProgressCallback(GHIConnection *connection, char *buffer, int bufferLen)
{
    if (connection->progressCallback != 0)
        connection->progressCallback(connection->request, connection->state, buffer, bufferLen, connection->fileBytesReceived, connection->totalSize, connection->callbackParam);
}



/*
 * sdk:      ghiCallPostCallback (ghttpcallbacks)
 */
void ghiCallPostCallback(GHIConnection *connection)
{
    if (connection->postingState.callback != 0)
        connection->postingState.callback(connection->request, connection->postingState.bytesPosted, connection->postingState.totalBytes, connection->postingState.index, ArrayLength(connection->postingState.states), connection->callbackParam);
}


/*
 * Empty ARM stub: `bx lr`.
 */
void ghiInitLock(void)
{
}


void ghiFreeLock(void)
{
}


void ghiLock(void)
{
}


void ghiUnlock(void)
{
}
