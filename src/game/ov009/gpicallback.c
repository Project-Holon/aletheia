/*
 * file:     gpicallback.c
 * unit:     yes
 * function: gpiCallErrorCallback, gpiAddCallback, gpiCallCallback, gpiProcessCallbacks
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
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   gGpiCallbackErrorOutOfMemory     0x021A45C8  data
 *   gsifree  0x0217EAE0  arm   ov009
 *   gpiDeleteBuddy  0x021890E0  arm   ov009
 */
#include "gpi_types.h"

typedef struct GPErrorArg {
    int result;
    int errorCode;
    char *errorString;
} GPErrorArg;

typedef struct GPTransferCallbackArg {
    int transfer;
    int type;
    int index;
    int num;
    char *message;
} GPTransferCallbackArg;

typedef struct GPGetProfileBuddyListArg {
    int result;
    int profile;
    int numProfiles;
    int reserved;
    void *profiles;
} GPGetProfileBuddyListArg;

#include "gsmemory.h"
#include "gpiutility.h"
#include "gpibuddy.h"
int gpiCallErrorCallback(void **connection, int result, int fatal);
int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
void gpiCallCallback(void **connection, GPICallbackData *data);
int gpiProcessCallbacks(void **connection, int blockingOperationID);
extern char gGpiCallbackErrorOutOfMemory[];




/*
 * Fetch the connection's registered callback, build a 0x10-byte argument
 * record ({arg1, connection+0x5b8, connection, arg2}) and hand both to
 * gpiAddCallback with callbackType 1.
 */
/*
 * Fetch the connection's registered callback from iconnection+0x1a8, build a
 * 0x10-byte argument record ({arg1, iconnection+0x5b8, iconnection, arg2})
 * and hand both to gpiAddCallback with callbackType 1.
 */
int gpiCallErrorCallback(void **connection, int result, int fatal)
{
    GPIConnection *ic = (GPIConnection *)*connection;
    GPICallback cb;
    int *data;

    if (fatal == 1)
        ic->fatalError = 1;
    cb.callback = ic->callbacks[0].callback;
    cb.param = ic->callbacks[0].param;
    if (cb.callback == 0)
        return (sptr)cb.param;
    data = (int *)gsimalloc(0x10);
    if (data != 0) {
        data[0] = result;
        data[3] = fatal;
        data[1] = ic->errorCode;
        data[2] = (sptr)ic;
    }
    return gpiAddCallback(connection, cb, data, 0, 1);
}




/*
 * gpiAddCallback: allocate a GPICallbackData (0x18 bytes), copy in the
 * callback struct, arg, type and the operation id (0 when operation is
 * NULL), then append it to the connection's callback list.
 *
 * The GPICallback parameter is a two-word struct passed by value, which is
 * why the prologue homes all four argument registers (push {r0-r3}) and the
 * epilogue is `pop {r4,r5,r6,lr}; add sp,#0x10; bx lr`.
 */
int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type)
{
    GPIConnection *ic = (GPIConnection *)*connection;
    GPICallbackData *data;

    data = (GPICallbackData *)gsimalloc(0x18);
    if (data == 0) {
        gpiSetErrorString(connection, gGpiCallbackErrorOutOfMemory);
        return 1;
    }
    data->callback = callback;
    data->arg = arg;
    if (operation != 0)
        data->operationID = operation->id;
    else
        data->operationID = 0;
    data->type = type;
    data->pnext = 0;
    if (ic->callbackList == 0)
        ic->callbackList = data;
    if (ic->lastCallback != 0)
        ic->lastCallback->pnext = data;
    ic->lastCallback = data;
    return 0;
}



/*
 * sdk:      gpiCallCallback (gpicallback.o)
 *
 * Types 2 and 11 are separate branches with the same body; the compiler
 * cross-jumps them, as it does 7/15 and 8/13 (and the tail of 9 and 14).
 */
void gpiCallCallback(void **connection, GPICallbackData *data)
{
    data->callback.callback(connection, data->arg, data->callback.param);

    if (data->type == 2) {
        gsifree(((GPErrorArg *)data->arg)->errorString);
        ((GPErrorArg *)data->arg)->errorString = 0;
    } else if (data->type == 11) {
        gsifree(((GPErrorArg *)data->arg)->errorString);
        ((GPErrorArg *)data->arg)->errorString = 0;
    } else if (data->type == 3) {
        int i;
        GPGetUserNicksResponseArg *arg = (GPGetUserNicksResponseArg *)data->arg;
        for (i = 0; i < arg->numNicks; i++) {
            gsifree(arg->nicks[i]);
            arg->nicks[i] = 0;
            gsifree(arg->uniquenicks[i]);
            arg->uniquenicks[i] = 0;
        }
        gsifree(arg->nicks);
        arg->nicks = 0;
        gsifree(arg->uniquenicks);
        arg->uniquenicks = 0;
    } else if (data->type == 4) {
        GPFindPlayersResponseArg *arg = (GPFindPlayersResponseArg *)data->arg;
        gsifree(arg->matches);
        arg->matches = 0;
    } else if (data->type == 7) {
        GPTransferCallbackArg *arg = (GPTransferCallbackArg *)data->arg;
        if (arg->message) {
            gsifree(arg->message);
            arg->message = 0;
        }
    } else if (data->type == 8) {
        GPGetReverseBuddiesResponseArg *arg = (GPGetReverseBuddiesResponseArg *)data->arg;
        if (arg->profiles) {
            gsifree(arg->profiles);
            arg->profiles = 0;
        }
    } else if (data->type == 9) {
        GPSuggestUniqueNickResponseArg *arg = (GPSuggestUniqueNickResponseArg *)data->arg;
        int i;
        for (i = 0; i < arg->numSuggestedNicks; i++) {
            gsifree(arg->suggestedNicks[i]);
            arg->suggestedNicks[i] = 0;
        }
        gsifree(arg->suggestedNicks);
        arg->suggestedNicks = 0;
    } else if (data->type == 12) {
        gpiDeleteBuddy(connection, *(int *)data->arg, 0);
    } else if (data->type == 13) {
        GPGetReverseBuddiesListResponseArg *arg = (GPGetReverseBuddiesListResponseArg *)data->arg;
        if (arg->matches) {
            gsifree(arg->matches);
            arg->matches = 0;
        }
    } else if (data->type == 14) {
        GPGetBuddyStatusInfoKeysArg *arg = (GPGetBuddyStatusInfoKeysArg *)data->arg;
        if (arg->numKeys != 0) {
            int i;
            for (i = 0; i < arg->numKeys; i++) {
                gsifree(arg->keys[i]);
                arg->keys[i] = 0;
                gsifree(arg->values[i]);
                arg->values[i] = 0;
            }
            gsifree(arg->keys);
            arg->keys = 0;
            gsifree(arg->values);
            arg->values = 0;
        }
    } else if (data->type == 15) {
        GPGetProfileBuddyListArg *arg = (GPGetProfileBuddyListArg *)data->arg;
        if (arg->profiles) {
            gsifree(arg->profiles);
            arg->profiles = 0;
        }
    }

    gsifree(data->arg);
    data->arg = 0;
    gsifree(data);
}


int gpiProcessCallbacks(void **connection, int blockingOperationID)
{
    GPIConnection *iconnection;
    GPICallbackData *list;
    GPICallbackData *last;
    GPICallbackData *pcurr;
    GPICallbackData *pprev;
    GPICallbackData *pnext;

    iconnection = (GPIConnection *)*connection;
    if (blockingOperationID) {
        list = iconnection->callbackList;
        last = iconnection->lastCallback;
        iconnection->callbackList = 0;
        iconnection->lastCallback = 0;
        pprev = 0;
        for (pcurr = list; pcurr; pcurr = pnext) {
            pnext = pcurr->pnext;
            if (pcurr->operationID == blockingOperationID || pcurr->type == 1) {
                if (pprev)
                    pprev->pnext = pnext;
                else
                    list = pnext;
                if (last == pcurr)
                    last = pprev;
                gpiCallCallback(connection, pcurr);
            } else {
                pprev = pcurr;
            }
        }
        if (iconnection->callbackList)
            iconnection->lastCallback->pnext = list;
        else
            iconnection->callbackList = list;
        iconnection->lastCallback = last;
        return 0;
    } else {
        while (iconnection->callbackList) {
            list = iconnection->callbackList;
            iconnection->callbackList = 0;
            iconnection->lastCallback = 0;
            while (list) {
                pnext = list->pnext;
                gpiCallCallback(connection, list);
                list = pnext;
            }
        }
    }
    return 0;
}
