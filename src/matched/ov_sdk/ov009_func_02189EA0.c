/*
 * function: func_02189EA0
 * address:  0x02189EA0
 * packet:   pkt_ov009_02189EA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiCallCallback (gpicallback.o)
 *
 * symbols:
 *   func_0217EAE0  0x0217EAE0  arm   ov009
 *   func_021890E0  0x021890E0  arm   ov009
 *
 * Types 2 and 11 are separate branches with the same body; the compiler
 * cross-jumps them, as it does 7/15 and 8/13 (and the tail of 9 and 14).
 */

typedef struct GPICallbackData {
    void (*callback)(void **, void *, void *);
    void *param;
    void *arg;
    int type;
} GPICallbackData;

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

extern void func_0217EAE0(void *ptr);
extern int func_021890E0(void **connection, int profile, int sendServerRequest);

void func_02189EA0(void **connection, GPICallbackData *data)
{
    data->callback(connection, data->arg, data->param);

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
