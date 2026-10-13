/*
 * file:     gpicallback.c
 * unit:     yes
 * function: func_02189D78, func_02189DFC, func_02189EA0, func_0218A0E4
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
 *   func_0217EAE0  0x0217EAE0  arm   ov009
 *   func_021890E0  0x021890E0  arm   ov009
 */
typedef struct GPICallback {
    void (*callback)(void **, void *, void *);
    void *param;
} GPICallback;

typedef struct GPICallbackData {
    GPICallback callback;
    void *arg;
    int type;
    int operationID;
    struct GPICallbackData *pnext;
} GPICallbackData;

typedef struct GPIConnection {
    unsigned char pad0[0x1A8];
    GPICallback callback;
    unsigned char pad1B0[0x5B8 - 0x1B0];
    int f5B8;
    int f5BC;
    unsigned char pad5C0[0x5DC - 0x5C0];
    GPICallbackData *callbackList;
    GPICallbackData *lastCallback;
} GPIConnection;

typedef struct GPErrorArg {
    int result;
    int errorCode;
    char *errorString;
} GPErrorArg;

typedef struct GPGetUserNicksResponseArg {
    char pad0[0x38];
    int numNicks;
    char **nicks;
    char **uniquenicks;
} GPGetUserNicksResponseArg;

typedef struct GPFindPlayersResponseArg {
    int result;
    int numMatches;
    int more;
    void *matches;
} GPFindPlayersResponseArg;

typedef struct GPTransferCallbackArg {
    int transfer;
    int type;
    int index;
    int num;
    char *message;
} GPTransferCallbackArg;

typedef struct GPGetReverseBuddiesResponseArg {
    int result;
    int numProfiles;
    void *profiles;
} GPGetReverseBuddiesResponseArg;

typedef struct GPSuggestUniqueNickResponseArg {
    int result;
    int numSuggestedNicks;
    char **suggestedNicks;
} GPSuggestUniqueNickResponseArg;

typedef struct GPGetReverseBuddiesListResponseArg {
    int result;
    int numOfUniqueMatchs;
    void *matches;
} GPGetReverseBuddiesListResponseArg;

typedef struct GPGetBuddyStatusInfoKeysArg {
    int profile;
    char **keys;
    char **values;
    int numKeys;
} GPGetBuddyStatusInfoKeysArg;

typedef struct GPGetProfileBuddyListArg {
    int result;
    int profile;
    int numProfiles;
    int reserved;
    void *profiles;
} GPGetProfileBuddyListArg;

extern void *func_0217EAB0(int size);
extern void func_02193734(void **connection, void *string);
extern void func_0217EAE0(void *ptr);
extern int func_021890E0(void **connection, int profile, int sendServerRequest);
int func_02189D78(void **connection, int a1, int a2);
int func_02189DFC(void **connection, GPICallback callback, void *arg, int *operation, int type);
void func_02189EA0(void **connection, GPICallbackData *data);
int func_0218A0E4(void **connection, int blockingOperationID);
extern char g_021A45C8[];




/*
 * Fetch the connection's registered callback, build a 0x10-byte argument
 * record ({arg1, connection+0x5b8, connection, arg2}) and hand both to
 * func_02189DFC with callbackType 1.
 */
/*
 * Fetch the connection's registered callback from iconnection+0x1a8, build a
 * 0x10-byte argument record ({arg1, iconnection+0x5b8, iconnection, arg2})
 * and hand both to func_02189DFC with callbackType 1.
 */
int func_02189D78(void **connection, int a1, int a2)
{
    GPIConnection *ic = (GPIConnection *)*connection;
    GPICallback cb;
    int *data;

    if (a2 == 1)
        ic->f5BC = 1;
    cb.callback = ic->callback.callback;
    cb.param = ic->callback.param;
    if (cb.callback == 0)
        return (int)cb.param;
    data = (int *)func_0217EAB0(0x10);
    if (data != 0) {
        data[0] = a1;
        data[3] = a2;
        data[1] = ic->f5B8;
        data[2] = (int)ic;
    }
    return func_02189DFC(connection, cb, data, 0, 1);
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
int func_02189DFC(void **connection, GPICallback callback, void *arg, int *operation, int type)
{
    GPIConnection *ic = (GPIConnection *)*connection;
    GPICallbackData *data;

    data = (GPICallbackData *)func_0217EAB0(0x18);
    if (data == 0) {
        func_02193734(connection, g_021A45C8);
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
void func_02189EA0(void **connection, GPICallbackData *data)
{
    data->callback.callback(connection, data->arg, data->callback.param);

    if (data->type == 2) {
        func_0217EAE0(((GPErrorArg *)data->arg)->errorString);
        ((GPErrorArg *)data->arg)->errorString = 0;
    } else if (data->type == 11) {
        func_0217EAE0(((GPErrorArg *)data->arg)->errorString);
        ((GPErrorArg *)data->arg)->errorString = 0;
    } else if (data->type == 3) {
        int i;
        GPGetUserNicksResponseArg *arg = (GPGetUserNicksResponseArg *)data->arg;
        for (i = 0; i < arg->numNicks; i++) {
            func_0217EAE0(arg->nicks[i]);
            arg->nicks[i] = 0;
            func_0217EAE0(arg->uniquenicks[i]);
            arg->uniquenicks[i] = 0;
        }
        func_0217EAE0(arg->nicks);
        arg->nicks = 0;
        func_0217EAE0(arg->uniquenicks);
        arg->uniquenicks = 0;
    } else if (data->type == 4) {
        GPFindPlayersResponseArg *arg = (GPFindPlayersResponseArg *)data->arg;
        func_0217EAE0(arg->matches);
        arg->matches = 0;
    } else if (data->type == 7) {
        GPTransferCallbackArg *arg = (GPTransferCallbackArg *)data->arg;
        if (arg->message) {
            func_0217EAE0(arg->message);
            arg->message = 0;
        }
    } else if (data->type == 8) {
        GPGetReverseBuddiesResponseArg *arg = (GPGetReverseBuddiesResponseArg *)data->arg;
        if (arg->profiles) {
            func_0217EAE0(arg->profiles);
            arg->profiles = 0;
        }
    } else if (data->type == 9) {
        GPSuggestUniqueNickResponseArg *arg = (GPSuggestUniqueNickResponseArg *)data->arg;
        int i;
        for (i = 0; i < arg->numSuggestedNicks; i++) {
            func_0217EAE0(arg->suggestedNicks[i]);
            arg->suggestedNicks[i] = 0;
        }
        func_0217EAE0(arg->suggestedNicks);
        arg->suggestedNicks = 0;
    } else if (data->type == 12) {
        func_021890E0(connection, *(int *)data->arg, 0);
    } else if (data->type == 13) {
        GPGetReverseBuddiesListResponseArg *arg = (GPGetReverseBuddiesListResponseArg *)data->arg;
        if (arg->matches) {
            func_0217EAE0(arg->matches);
            arg->matches = 0;
        }
    } else if (data->type == 14) {
        GPGetBuddyStatusInfoKeysArg *arg = (GPGetBuddyStatusInfoKeysArg *)data->arg;
        if (arg->numKeys != 0) {
            int i;
            for (i = 0; i < arg->numKeys; i++) {
                func_0217EAE0(arg->keys[i]);
                arg->keys[i] = 0;
                func_0217EAE0(arg->values[i]);
                arg->values[i] = 0;
            }
            func_0217EAE0(arg->keys);
            arg->keys = 0;
            func_0217EAE0(arg->values);
            arg->values = 0;
        }
    } else if (data->type == 15) {
        GPGetProfileBuddyListArg *arg = (GPGetProfileBuddyListArg *)data->arg;
        if (arg->profiles) {
            func_0217EAE0(arg->profiles);
            arg->profiles = 0;
        }
    }

    func_0217EAE0(data->arg);
    data->arg = 0;
    func_0217EAE0(data);
}


int func_0218A0E4(void **connection, int blockingOperationID)
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
                func_02189EA0(connection, pcurr);
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
                func_02189EA0(connection, list);
                list = pnext;
            }
        }
    }
    return 0;
}
