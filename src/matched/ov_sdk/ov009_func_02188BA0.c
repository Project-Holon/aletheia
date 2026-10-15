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
 *   strcmp  0x020948E0  arm
 *   func_0217EAB0  0x0217EAB0  arm   ov009
 *   func_02189DFC  0x02189DFC  arm   ov009
 *   func_0219359C  0x0219359C  arm   ov009
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189D78  arm   ov009
 *   atoi  0x020964E0  arm
 *   strlen  0x0209477C  arm
 *   B64Decode  0x0217F8B4  arm   ov009
 *   goastrdup  0x0217F1E0  arm   ov009
 *   func_0218D9A8  0x0218D9A8  arm   ov009
 *   func_0218D878  0x0218D878  arm   ov009
 *   func_0218D900  0x0218D900  arm   ov009
 *   gpiPeerRemoveOp  0x0218F900  arm   ov009
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
typedef unsigned int   u32;
extern void func_02193734(int *p, int b);
extern int strcmp(const char *a, const char *b);
extern void *func_0217EAB0(unsigned long size);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, void *operation, int type);
typedef unsigned char  u8;
extern int func_0219359C(int *connection, const char *buffer, int *index, char *key, char *value);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern int atoi(u32 a0);
extern int strlen(const u8 *s);
extern void B64Decode(const char *input, char *output, int inlen, int *outlen, int encodingType);
extern char *goastrdup(char *src);
extern int func_0218D9A8(void **connection, void *keys, char *keyName, char **keyValue);
extern int func_0218D878(void **connection, void *keys, char *theKeyName, char *theKeyValue);
extern int func_0218D900(void **connection, void *keys, char *keyName, char *newValue);
extern void gpiPeerRemoveOp(GPIPeer *peer, GPIPeerOp *operation);
extern char g_021A446C[];
extern char g_021A4468[];
extern char g_021A4480[];
extern char g_021A4488[];

int func_02188BA0(void **connection, GPIPeer *peer, char *buffer)
{
    GPIProfile *pProfile;

    if (!func_0218FD9C(connection, peer->profile, &pProfile)) {
        func_02193734((int *)connection, (int)g_021A446C);
        return 2;
    }

    if (strcmp(buffer, g_021A4468) == 0) {
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
            gpiPeerRemoveOp(peer, anIterator);
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

        func_0219359C((int *)connection, buffer, &index, keyName, keyVal);
        if (strcmp(keyName, g_021A4480) != 0) {
            func_02193710((int *)connection, 1, (int)g_021A4488);
            func_02189D78((int *)connection, 3, 0);
            return 3;
        }
        numKeys = atoi((u32)keyVal);
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
                gpiPeerRemoveOp(peer, anIterator);
            }
        } else {
            keys = func_0217EAB0(sizeof(char *) * numKeys);
            values = func_0217EAB0(sizeof(char *) * numKeys);
            for (i = 0; i < numKeys; i++) {
                func_0219359C((int *)connection, buffer, &index, keyName, keyVal);
                B64Decode(keyName, decodeKey, (int)strlen((const u8 *)keyName), &decodedLen, 2);
                decodeKey[decodedLen] = '\0';
                B64Decode(keyVal, decodeVal, (int)strlen((const u8 *)keyVal), &decodedLen, 2);
                decodeVal[decodedLen] = '\0';
                keys[i] = goastrdup(decodeKey);
                values[i] = goastrdup(decodeVal);
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
                    gpiPeerRemoveOp(peer, anIterator);
                }
            }
        }
    }
    return 0;
}
