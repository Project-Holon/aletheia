/*
 * function: func_02188BA0
 * address:  0x02188BA0
 * packet:   pkt_ov009_02188BA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiBuddyHandleKeyReply (gpibuddy.o)
 *
 * symbols:
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0217EAB0  0x0217EAB0  arm   ov009
 *   func_02189DFC  0x02189DFC  arm   ov009
 *   func_0219359C  0x0219359C  arm   ov009
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189D78  arm   ov009
 *   func_020964E0  0x020964E0  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0217F8B4  0x0217F8B4  arm   ov009
 *   func_0217F1E0  0x0217F1E0  arm   ov009
 *   func_0218D9A8  0x0218D9A8  arm   ov009
 *   func_0218D878  0x0218D878  arm   ov009
 *   func_0218D900  0x0218D900  arm   ov009
 *   func_0218F900  0x0218F900  arm   ov009
 *   g_021A446C     0x021A446C  data
 *   g_021A4468     0x021A4468  data
 *   g_021A4480     0x021A4480  data
 *   g_021A4488     0x021A4488  data
 */

typedef void (*GPCallback)(void **connection, void *arg, void *param);

typedef struct GPICallback {
    GPCallback callback;
    void *param;
} GPICallback;

typedef struct GPIPeerOp {
    int state;
    void *userData;
    GPCallback callback;
    struct GPIPeerOp *next;
    int type;
} GPIPeerOp;

typedef struct GPIPeer {
    char pad0[0x10];
    int profile;
    char pad14[0x44 - 0x14];
    GPIPeerOp *firstOp;
} GPIPeer;

typedef struct GPIBuddyStatusInfo {
    char pad0[0x38];
    void *extendedInfoKeys;
} GPIBuddyStatusInfo;

typedef struct GPIProfile {
    char pad0[0xc];
    GPIBuddyStatusInfo *buddyStatusInfo;
} GPIProfile;

typedef struct GPGetBuddyStatusInfoKeysArg {
    int profile;
    char **keys;
    char **values;
    int numKeys;
} GPGetBuddyStatusInfoKeysArg;

extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern void func_02193734(void **connection, char *errorString);
extern int func_020948E0(const char *a, const char *b);
extern void *func_0217EAB0(unsigned long size);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, void *operation, int type);
extern int func_0219359C(void **connection, char *buffer, int *index, char *key, char *value);
extern void func_02193710(void **connection, int errorCode, char *errorString);
extern void func_02189D78(void **connection, int result, int fatal);
extern int func_020964E0(const char *s);
extern unsigned long func_0209477C(const char *s);
extern void func_0217F8B4(const char *input, char *output, int inlen, int *outlen, int encodingType);
extern char *func_0217F1E0(char *src);
extern int func_0218D9A8(void **connection, void *keys, char *keyName, char **keyValue);
extern int func_0218D878(void **connection, void *keys, char *theKeyName, char *theKeyValue);
extern int func_0218D900(void **connection, void *keys, char *keyName, char *newValue);
extern void func_0218F900(GPIPeer *peer, GPIPeerOp *operation);
extern char g_021A446C[];
extern char g_021A4468[];
extern char g_021A4480[];
extern char g_021A4488[];

int func_02188BA0(void **connection, GPIPeer *peer, char *buffer)
{
    GPIProfile *pProfile;

    if (!func_0218FD9C(connection, peer->profile, &pProfile)) {
        func_02193734(connection, g_021A446C);
        return 2;
    }

    if (func_020948E0(buffer, g_021A4468) == 0) {
        GPIPeerOp *anIterator;
        for (anIterator = peer->firstOp; anIterator != 0; anIterator = anIterator->next)
            if (anIterator->type == 0x68)
                break;
        if (!anIterator)
            return 0;
        else if (anIterator->type == 0x68 && anIterator->callback != 0) {
            GPICallback callback;
            GPGetBuddyStatusInfoKeysArg *arg = func_0217EAB0(sizeof(GPGetBuddyStatusInfoKeysArg));
            callback.callback = anIterator->callback;
            callback.param = anIterator->userData;
            arg->keys = 0;
            arg->numKeys = 0;
            arg->values = 0;
            arg->profile = peer->profile;
            func_02189DFC(connection, callback, arg, 0, 0);
            func_0218F900(peer, anIterator);
        }
    } else {
        char keyName[512];
        char keyVal[512];
        char decodeKey[512];
        char decodeVal[512];
        char **keys;
        char **values;
        int decodedLen;
        int numKeys;
        int i;
        int index;
        char *checkKey;

        decodedLen = 0;
        index = 0;
        checkKey = 0;

        func_0219359C(connection, buffer, &index, keyName, keyVal);
        if (func_020948E0(keyName, g_021A4480) != 0) {
            func_02193710(connection, 1, g_021A4488);
            func_02189D78(connection, 3, 0);
            return 3;
        }
        numKeys = func_020964E0(keyVal);
        if (numKeys == 0) {
            GPIPeerOp *anIterator;
            for (anIterator = peer->firstOp; anIterator != 0; anIterator = anIterator->next)
                if (anIterator->type == 0x68)
                    break;
            if (!anIterator)
                return 0;
            else if (anIterator->type == 0x68 && anIterator->callback != 0) {
                GPICallback callback;
                GPGetBuddyStatusInfoKeysArg *arg = func_0217EAB0(sizeof(GPGetBuddyStatusInfoKeysArg));
                callback.callback = anIterator->callback;
                callback.param = anIterator->userData;
                arg->keys = 0;
                arg->numKeys = 0;
                arg->values = 0;
                arg->profile = peer->profile;
                func_02189DFC(connection, callback, arg, 0, 0);
                func_0218F900(peer, anIterator);
            }
        } else {
            keys = func_0217EAB0(sizeof(char *) * numKeys);
            values = func_0217EAB0(sizeof(char *) * numKeys);
            for (i = 0; i < numKeys; i++) {
                func_0219359C(connection, buffer, &index, keyName, keyVal);
                func_0217F8B4(keyName, decodeKey, (int)func_0209477C(keyName), &decodedLen, 2);
                decodeKey[decodedLen] = '\0';
                func_0217F8B4(keyVal, decodeVal, (int)func_0209477C(keyVal), &decodedLen, 2);
                decodeVal[decodedLen] = '\0';
                keys[i] = func_0217F1E0(decodeKey);
                values[i] = func_0217F1E0(decodeVal);
                if (func_0218D9A8(connection, pProfile->buddyStatusInfo->extendedInfoKeys, decodeKey, &checkKey) == 0 && checkKey == 0)
                    func_0218D878(connection, pProfile->buddyStatusInfo->extendedInfoKeys, decodeKey, decodeVal);
                else
                    func_0218D900(connection, pProfile->buddyStatusInfo->extendedInfoKeys, decodeKey, decodeVal);
            }

            {
                GPIPeerOp *anIterator;
                for (anIterator = peer->firstOp; anIterator != 0; anIterator = anIterator->next)
                    if (anIterator->type == 0x68)
                        break;
                if (!anIterator)
                    return 0;
                else if (anIterator->type == 0x68 && anIterator->callback != 0) {
                    GPICallback callback;
                    GPGetBuddyStatusInfoKeysArg *arg = func_0217EAB0(sizeof(GPGetBuddyStatusInfoKeysArg));
                    callback.callback = anIterator->callback;
                    callback.param = anIterator->userData;
                    arg->numKeys = numKeys;
                    arg->keys = keys;
                    arg->values = values;
                    arg->profile = peer->profile;
                    func_02189DFC(connection, callback, arg, 0, 0xe);
                    func_0218F900(peer, anIterator);
                }
            }
        }
    }
    return 0;
}
