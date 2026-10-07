/*
 * file:     unit_02187010_p02.c
 * unit:     yes
 * function: func_02188B0C, func_02188BA0, func_02188FD8
 * address:  0x02188B0C
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
 *   func_0218DA40  0x0218DA40  arm   ov009
 *   func_021889A0  0x021889A0  arm   ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0217EAE0  0x0217EAE0  arm   ov009
 *   g_021A4468     0x021A4468  data  ov009
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
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
 *   g_021A4480     0x021A4480  data
 *   g_021A4488     0x021A4488  data
 *   gpiGetProfile           0x0218FD9C  arm
 *   gpiSetErrorString       0x02193734  arm
 *   gpiSendAuthBuddyRequest 0x02187010  arm
 *   gsifree                 0x0217EAE0  arm
 *   gpiCanFreeProfile       0x02190140  arm
 *   gpiRemoveProfile        0x0218FF24  arm
 */
typedef struct GPIPeer_02188B0C {
    unsigned char pad[0x10];
    int profile;
} GPIPeer_02188B0C;

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

typedef struct GPIPeer_02188BA0 {
    char pad0[0x10];
    int profile;
    char pad14[0x44 - 0x14];
    GPIPeerOp *firstOp;
} GPIPeer_02188BA0;

typedef struct GPIBuddyStatusInfo {
    char pad0[0x38];
    void *extendedInfoKeys;
} GPIBuddyStatusInfo;

typedef struct GPIProfile_02188BA0 {
    char pad0[0xc];
    GPIBuddyStatusInfo *buddyStatusInfo;
} GPIProfile_02188BA0;

typedef struct GPGetBuddyStatusInfoKeysArg {
    int profile;
    char **keys;
    char **values;
    int numKeys;
} GPGetBuddyStatusInfoKeysArg;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct GPIConnection GPIConnection;

typedef struct GPIProfile_02188FD8 GPIProfile_02188FD8;

extern int func_0218DA40(void **connection, char **buffer);
extern int func_021889A0(void **connection, int profileid, int type, char *message,
                         int sendOption, void *peerOp);
extern int func_020948E0(const char *s1, const char *s2);
extern void func_0217EAE0(void *ptr);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile_02188BA0 **pProfile);
extern void func_02193734(int *p, int b);
extern void *func_0217EAB0(unsigned long size);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, void *operation, int type);
extern int func_0219359C(int *connection, const char *buffer, int *index, char *key, char *value);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern int func_020964E0(u32 a0);
extern int func_0209477C(const u8 *s);
extern void func_0217F8B4(const char *input, char *output, int inlen, int *outlen, int encodingType);
extern char *func_0217F1E0(char *src);
extern int func_0218D9A8(void **connection, void *keys, char *keyName, char **keyValue);
extern int func_0218D878(void **connection, void *keys, char *theKeyName, char *theKeyValue);
extern int func_0218D900(void **connection, void *keys, char *keyName, char *newValue);
extern void func_0218F900(GPIPeer_02188BA0 *peer, GPIPeerOp *operation);
extern int gpiGetProfile(void **connection, int profileid, GPIProfile_02188FD8 **pProfile);
extern void gpiSetErrorString(void **connection, char *errorString);
extern int gpiSendAuthBuddyRequest(void **connection, GPIProfile_02188FD8 *profile);
extern void gsifree(void *ptr);
extern int gpiCanFreeProfile(GPIProfile_02188FD8 *profile);
extern void gpiRemoveProfile(void **connection, GPIProfile_02188FD8 *profile);
int func_02188B0C(void **connection, GPIPeer_02188B0C *peer);
int func_02188BA0(void **connection, GPIPeer_02188BA0 *peer, char *buffer);
int gpiAuthBuddyRequest(void **connection, int profile);
extern char g_021A4468[];
extern char g_021A446C[];
extern char g_021A4480[];
extern char g_021A4488[];


/*
 * sdk:      gpiBuddyHandleKeyRequest (gpibuddy.o)
 */
int func_02188B0C(void **connection, GPIPeer_02188B0C *peer)
{
    char *message;
    int result;

    if ((result = func_0218DA40(connection, &message)) != 0)
        return result;
    if (message == 0)
        message = g_021A4468;
    if ((result = func_021889A0(connection, peer->profile, 0x69, message, 0xB00, 0)) != 0)
        return result;
    {
        char *m = message;
        if (func_020948E0(m, g_021A4468) != 0)
            func_0217EAE0(m);
    }
    return 0;
}


/*
 * sdk:      gpiBuddyHandleKeyReply (gpibuddy.o)
 */
int func_02188BA0(void **connection, GPIPeer_02188BA0 *peer, char *buffer)
{
    GPIProfile_02188BA0 *pProfile;

    if (!func_0218FD9C(connection, peer->profile, &pProfile)) {
        func_02193734((int *)connection, (int)g_021A446C);
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

        func_0219359C((int *)connection, buffer, &index, keyName, keyVal);
        if (func_020948E0(keyName, g_021A4480) != 0) {
            func_02193710((int *)connection, 1, (int)g_021A4488);
            func_02189D78((int *)connection, 3, 0);
            return 3;
        }
        numKeys = func_020964E0((u32)keyVal);
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
                func_0219359C((int *)connection, buffer, &index, keyName, keyVal);
                func_0217F8B4(keyName, decodeKey, (int)func_0209477C((const u8 *)keyName), &decodedLen, 2);
                decodeKey[decodedLen] = '\0';
                func_0217F8B4(keyVal, decodeVal, (int)func_0209477C((const u8 *)keyVal), &decodedLen, 2);
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


int gpiAuthBuddyRequest(void **connection, int profile)
{
    GPIConnection *iconnection;
    GPIProfile_02188FD8 *pProfile;
    int __result__;

    iconnection = (GPIConnection *)*connection;

    if (!gpiGetProfile(connection, profile, &pProfile)) {
        gpiSetErrorString(connection, g_021A446C);
        return 2;
    }
    if (*(int *)((char *)pProfile + 0x14) == 0) {
        gpiSetErrorString(connection, g_021A446C);
        return 2;
    }

    __result__ = gpiSendAuthBuddyRequest(connection, pProfile);
    if (__result__ != 0)
        return __result__;

    *(int *)((char *)pProfile + 0x18) = *(int *)((char *)pProfile + 0x18) - 1;

    if (*(int *)((char *)iconnection + 0x100) == 0
        && *(int *)((char *)pProfile + 0x18) <= 0) {
        gsifree(*(void **)((char *)pProfile + 0x14));
        *(int *)((char *)pProfile + 0x14) = 0;
        if (gpiCanFreeProfile(pProfile))
            gpiRemoveProfile(connection, pProfile);
    }

    return 0;
}
