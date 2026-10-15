/*
 * file:     gpibuddy.c
 * unit:     yes
 * function: gpiSendAuthBuddyRequest, gpiProcessRecvBuddyMessage, gpiProcessRecvBuddyStatusInfo, gpiProcessRecvBuddyList, gpiSendServerBuddyMessage, gpiSendBuddyMessage, gpiBuddyHandleKeyRequest, gpiBuddyHandleKeyReply, func_02188FD8, gpiFixBuddyIndices, gpiDeleteBuddy, gpiBuddyDeletedLocally
 * address:  0x02187010
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
 *   gpiAppendStringToBuffer  0x0218946C  arm
 *   gpiAppendIntToBuffer     0x0218949C  arm
 *   g_021A4240               0x021A4240  data
 *   g_021A424C               0x021A424C  data
 *   g_021A4258               0x021A4258  data
 *   g_021A4268               0x021A4268  data
 *   g_021A4270               0x021A4270  data
 *   gpiValueForKey                0x02193418 arm ov009
 *   gpiSetError                   0x02193710 arm ov009
 *   gpiCallErrorCallback          0x02189D78 arm ov009
 *   atoi                          0x020964E0 arm
 *   gsiTimeNitro                  0x02184098 arm ov009
 *   gsimalloc                     0x0217EAB0 arm ov009
 *   gpiSetErrorString             0x02193734 arm ov009
 *   strlen                        0x0209477C arm
 *   strcpy                        0x02094798 arm
 *   gpiAddCallback                0x02189DFC arm ov009
 *   gpiProfileListAdd             0x0218FCD8 arm ov009
 *   strstr                        0x02094B20 arm
 *   gsifree                       0x0217EAE0 arm ov009
 *   goastrdup                     0x0217F1E0 arm ov009
 *   strzcpy                       0x0219327C arm ov009
 *   gsDebugFormat                 0x0217D254 arm ov009
 *   gpiRemoveBuddyStatusInfo      0x021900EC arm ov009
 *   gsiSafeStrcpyA                0x021803BC arm ov009
 *   gpiSendBuddyMessage           0x021889A0 arm ov009
 *   memset                        0x020923B0 arm
 *   g_021A4278                    0x021A4278 data
 *   g_021A4280                    0x021A4280 data
 *   g_021A42B0                    0x021A42B0 data
 *   g_021A42B4                    0x021A42B4 data
 *   g_021A42BC                    0x021A42BC data
 *   g_021A42CC                    0x021A42CC data
 *   g_021A42D4                    0x021A42D4 data
 *   g_021A42E0                    0x021A42E0 data
 *   g_021A437C                    0x021A437C data
 *   g_021A4380                    0x021A4380 data
 *   g_021A4388                    0x021A4388 data
 *   g_021A4390                    0x021A4390 data
 *   g_021A4398                    0x021A4398 data
 *   g_021A439C                    0x021A439C data
 *   g_021A43A4                    0x021A43A4 data
 *   g_021A43A8                    0x021A43A8 data
 *   gpiRemoveBuddyStatus          0x021900BC arm ov009
 *   ArrayNew                      0x02184144 arm ov009
 *   g_021A43AC                    0x021A43AC data
 *   g_021A43B8                    0x021A43B8 data
 *   g_021A43C0                    0x021A43C0 data
 *   g_021A43C8                    0x021A43C8 data
 *   g_021A43D0                    0x021A43D0 data
 *   g_021A43DC                    0x021A43DC data
 *   g_021A43E8                    0x021A43E8 data
 *   g_021A43F0                    0x021A43F0 data
 *   g_021A43F8                    0x021A43F8 data
 *   g_021A4404                    0x021A4404 data
 *   g_021A4410                    0x021A4410 data
 *   g_021A441C                    0x021A441C data
 *   g_021A4428                    0x021A4428 data
 *   g_021A4434                    0x021A4434 data
 *   g_021A4440                    0x021A4440 data
 *   gpiCheckForError  0x0219329C  arm   ov009
 *   gpiValueForKeyWithIndex  0x02193378  arm   ov009
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189D78  arm   ov009
 *   atoi  0x020964E0  arm
 *   strstr  0x02094B20  arm
 *   gpiProfileListAdd  0x0218FCD8  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gsimalloc  0x0217EAB0  arm   ov009
 *   g_021A4450     0x021A4450  data
 *   g_021A4458     0x021A4458  data
 *   g_021A4460     0x021A4460  data
 *   strzcpy  0x0219327C  arm   ov009
 *   gpiAppendStringToBuffer  0x0218946C  arm   ov009
 *   gpiAppendIntToBuffer  0x0218949C  arm   ov009
 *   g_021A4464     0x021A4464  data  ov009
 *   gpiGetPeerByProfile  0x0218F0B8  arm   ov009
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   gpiAddPeer  0x0218F150  arm   ov009
 *   func_0218F1E0  0x0218F1E0  arm   ov009
 *   gpiPeerStartConnect  0x0218F248  arm   ov009
 *   func_0218F884  0x0218F884  arm   ov009
 *   gpiPeerAddMessage  0x0218F350  arm   ov009
 *   gpiSaveKeysToBuffer  0x0218DA40  arm   ov009
 *   strcmp  0x020948E0  arm
 *   gsifree  0x0217EAE0  arm   ov009
 *   g_021A4468     0x021A4468  data  ov009
 *   gpiAddCallback  0x02189DFC  arm   ov009
 *   gpiReadKeyAndValue  0x0219359C  arm   ov009
 *   strlen  0x0209477C  arm
 *   B64Decode  0x0217F8B4  arm   ov009
 *   goastrdup  0x0217F1E0  arm   ov009
 *   gpiStatusInfoCheckKey  0x0218D9A8  arm   ov009
 *   gpiStatusInfoAddKey  0x0218D878  arm   ov009
 *   gpiStatusInfoSetKey  0x0218D900  arm   ov009
 *   gpiPeerRemoveOp  0x0218F900  arm   ov009
 *   g_021A446C     0x021A446C  data
 *   g_021A4480     0x021A4480  data
 *   g_021A4488     0x021A4488  data
 *   gpiGetProfile           0x0218FD9C  arm
 *   gpiCanFreeProfile       0x02190140  arm
 *   gpiRemoveProfile        0x0218FF24  arm
 *   func_0218FFFC  0x0218FFFC  arm   ov009
 *   func_021841B0  0x021841B0  arm   ov009
 *   g_021A44AC     0x021A44AC  data
 *   g_021A44B8     0x021A44B8  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "gpi_types.h"
extern int strcmp(const char *s1, const char *s2);
extern char *strstr(const char *s, const char *t);
extern int atoi(const char *s);

#define Error(connection, result, errorString) \
{ \
    gpiSetErrorString(connection, errorString); \
    return (result); \
}
#define CallbackFatalError(connection, result, errorCode, errorString) \
{ \
    gpiSetError(connection, errorCode, errorString); \
    gpiCallErrorCallback(connection, result, 1); \
    return (result); \
}
#define freeclear(mem) { gsifree(mem); (mem) = 0; }
#define CHECK_RESULT(result) \
{ \
    GPResult __result__ = (result); \
    if (__result__ != GP_NO_ERROR) \
        return __result__; \
}
#define PARSE_KEY(k) do { \
    if (!gpiValueForKey(input, (k), buffer, 0x400)) { \
        gpiSetError(connection, 1, g_021A4280); \
        gpiCallErrorCallback(connection, 3, 1); \
        return 3; \
    } \
} while (0)
extern int gpiAppendIntToBuffer(void **connection, GPIBuffer *outputBuffer, int num);
extern int gpiValueForKey(char *command, char *key, char *value, int len);
extern void gpiSetError(void **connection, int errorCode, char *errorString);
extern long gsiTimeNitro(long *timer);
extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(void **connection, char *errorString);
extern char *strcpy(char *dst, const char *src);
extern GPIProfile *gpiProfileListAdd(void **connection, int id);
extern void gsifree(void *ptr);
extern char *goastrdup(char *src);
extern void gsDebugFormat(int theCat, int theType, int theLevel, char *theTokenStr, ...);
extern void gpiRemoveBuddyStatusInfo(void *buddyStatusInfo);
extern unsigned long gsiSafeStrcpyA(char *dst, char *src, unsigned long size);
extern void gpiRemoveBuddyStatus(void *buddyStatus);
extern void *ArrayNew(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void gpiStatusInfoKeyFree(void *ptr);
extern int gpiCheckForError(void **connection, char *input, int flag);
extern int gpiValueForKeyWithIndex(char *command, char *key, int *index, char *value, int len);
extern void gpiSetError(void **connection, int code, char *string);
extern int gpiCallErrorCallback(void **connection, int result, int fatal);
extern GPIProfile *gpiProfileListAdd(void **connection, int id);
extern void gpiSetErrorString(void **connection, char *string);
extern void *gsimalloc(unsigned long size);
extern void strzcpy(char *dest, char *src, int len);
extern int gpiAppendStringToBuffer(void **connection, GPIBuffer *buffer, const char *string);
extern int gpiAppendIntToBuffer(void **connection, GPIBuffer *buffer, int value);
extern GPIPeer *gpiGetPeerByProfile(void **connection, int profileid);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern GPIPeer *gpiAddPeer(void **connection, int profileid, int initiate);
extern int func_0218F1E0(void **connection, GPIPeer *peer);
extern int gpiPeerStartConnect(void **connection, GPIPeer *peer);
extern void func_0218F884(GPIPeer *peer, GPIPeerOp *operation);
extern GPResult gpiPeerAddMessage(void **connection, GPIPeer *peer, int type, char *message);
extern int gpiSaveKeysToBuffer(void **connection, char **buffer);
extern void gsifree(void *ptr);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern int gpiReadKeyAndValue(void **connection, char *buffer, int *index, char *key, char *value);
extern void B64Decode(const char *input, char *output, int inlen, int *outlen, int encodingType);
extern int gpiStatusInfoCheckKey(void **connection, void *keys, char *keyName, char **keyValue);
extern int gpiStatusInfoAddKey(void **connection, void *keys, char *theKeyName, char *theKeyValue);
extern int gpiStatusInfoSetKey(void **connection, void *keys, char *keyName, char *newValue);
extern void gpiPeerRemoveOp(GPIPeer *peer, GPIPeerOp *operation);
extern int gpiGetProfile(void **connection, int profileid, GPIProfile **pProfile);
extern int gpiCanFreeProfile(GPIProfile *profile);
extern void gpiRemoveProfile(void **connection, GPIProfile *profile);
extern int func_0218FFFC(void **connection, int (*func)(void **, GPIProfile *, void *), void *data);
extern void func_021841B0(void *array);
int gpiSendAuthBuddyRequest(void **connection, GPIProfile *profile);
int gpiProcessRecvBuddyList(void **connection, char *input);
int gpiSendServerBuddyMessage(void **connection, int profileid, int type, char *message);
int gpiSendBuddyMessage(void **connection, int profileid, int type, char *message, int sendOption, GPIPeerOp *peerOp);
int gpiBuddyHandleKeyRequest(void **connection, GPIPeer *peer);
int gpiBuddyHandleKeyReply(void **connection, GPIPeer *peer, char *buffer);
int gpiAuthBuddyRequest(void **connection, int profile);
int gpiFixBuddyIndices(int unused, GPIProfile *profile, int baseIndex);
int gpiDeleteBuddy(void **connection, int profile, int sendServerRequest);
int gpiBuddyDeletedLocally(void **connection, int id, int isDeleted);
extern char g_021A4240[];
extern char g_021A424C[];
extern char g_021A4258[];
extern char g_021A4268[];
extern char g_021A4270[];
extern char g_021A4278[];             /* "\bm\"  */
extern char g_021A4280[];             /* "Unexpected data was received ..." */
extern char g_021A42B0[];             /* "\f\"  */
extern char g_021A42B4[];             /* "\date\" */
extern char g_021A42BC[];             /* "Out of memory." */
extern char g_021A42CC[];             /* "\msg\" */
extern char g_021A42D4[];             /* "|signed|" */
extern char g_021A42E0[];             /* "Deliberately ignoring ..." */
extern char g_021A437C[];             /* "|s|"  */
extern char g_021A4380[];             /* "|ss|" */
extern char g_021A4388[];             /* "|ls|" */
extern char g_021A4390[];             /* "|ip|" */
extern char g_021A4398[];             /* "|p|"  */
extern char g_021A439C[];             /* "|qm|" */
extern char g_021A43A4[];             /* "|l|"  */
extern char g_021A43A8[];             /* "1"    */
extern char g_021A43AC[];
extern char g_021A43B8[];
extern char g_021A43C0[];
extern char g_021A43C8[];
extern char g_021A43D0[];
extern char g_021A43DC[];
extern char g_021A43E8[];
extern char g_021A43F0[];
extern char g_021A43F8[];
extern char g_021A4404[];
extern char g_021A4410[];
extern char g_021A441C[];
extern char g_021A4428[];
extern char g_021A4434[];
extern char g_021A4440[];
extern char g_021A4450[];
extern char g_021A4458[];
extern char g_021A4460[];
extern char g_021A4464[];
extern char g_021A4468[];
extern char g_021A446C[];
extern char g_021A4480[];
extern char g_021A4488[];
extern char g_021A44AC[];
extern char g_021A44B8[];






int gpiSendAuthBuddyRequest(void **connection, GPIProfile *profile)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;

    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4240);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A424C);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, *(int *)((char *)iconnection + 0x198));
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4258);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, *(int *)profile);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4268);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, *(char **)((char *)profile + 0x14));
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4270);
    return 0;
}





static GPResult gpiProcessRecvBuddyMessage(void **connection, char *input)
{
    char buffer[4096];
    int type;
    int profileid;
    long date;
    GPICallback callback;
    GPIProfile *profile;
    GPIBuddyStatus *buddyStatus;
    char intValue[16];
    char *str;
    unsigned short port;
    int productID;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    char strTemp[256];

    if (!gpiValueForKey(input, g_021A4278, buffer, sizeof(buffer)))
        CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
    type = atoi(buffer);

    if (!gpiValueForKey(input, g_021A42B0, buffer, sizeof(buffer)))
        CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
    profileid = atoi(buffer);

    if (!gpiValueForKey(input, g_021A42B4, buffer, sizeof(buffer)))
        date = gsiTimeNitro(0);
    else
        date = atoi(buffer);

    switch (type) {
    case 1:
        callback = iconnection->callbacks[3];
        if (callback.callback != 0) {
            GPRecvBuddyMessageArg *arg;
            arg = (GPRecvBuddyMessageArg *)gsimalloc(sizeof(GPRecvBuddyMessageArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            if (!gpiValueForKey(input, g_021A42CC, buffer, sizeof(buffer)))
                CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
            arg->message = (char *)gsimalloc(strlen(buffer) + 1);
            if (arg->message == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            strcpy(arg->message, buffer);
            arg->profile = profileid;
            arg->date = (unsigned int)date;
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 2));
        }
        break;

    case 5:
        callback = iconnection->callbacks[4];
        if (callback.callback != 0) {
            GPRecvBuddyUTMArg *arg;
            arg = (GPRecvBuddyUTMArg *)gsimalloc(sizeof(GPRecvBuddyUTMArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            if (!gpiValueForKey(input, g_021A42CC, buffer, sizeof(buffer)))
                CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
            arg->message = (char *)gsimalloc(strlen(buffer) + 1);
            if (arg->message == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            strcpy(arg->message, buffer);
            arg->profile = profileid;
            arg->date = (unsigned int)date;
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 11));
        }
        break;

    case 2:
        profile = gpiProfileListAdd(connection, profileid);
        if (!profile)
            Error(connection, GP_MEMORY_ERROR, g_021A42BC);
        if (!gpiValueForKey(input, g_021A42CC, buffer, sizeof(buffer)))
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        str = strstr(buffer, g_021A42D4);
        if (!str)
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        *str = 0;
        str += 8;
        if (strlen(str) != 32)
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        freeclear(profile->authSig);
        profile->authSig = goastrdup(str);
        profile->requestCount++;
        callback = iconnection->callbacks[1];
        if (callback.callback != 0) {
            GPRecvBuddyRequestArg *arg;
            arg = (GPRecvBuddyRequestArg *)gsimalloc(sizeof(GPRecvBuddyRequestArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            strzcpy(arg->reason, buffer, 1025);
            arg->profile = profileid;
            arg->date = (unsigned int)date;
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 6));
        }
        break;

    case 4:
        callback = iconnection->callbacks[7];
        if (callback.callback != 0) {
            GPRecvBuddyAuthArg *arg;
            arg = (GPRecvBuddyAuthArg *)gsimalloc(sizeof(GPRecvBuddyAuthArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            arg->profile = profileid;
            arg->date = (unsigned int)date;
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 10));
        }
        break;

    case 6:
        callback = iconnection->callbacks[8];
        if (callback.callback != 0) {
            GPRecvBuddyRevokeArg *arg;
            arg = (GPRecvBuddyRevokeArg *)gsimalloc(sizeof(GPRecvBuddyRevokeArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            arg->profile = profileid;
            arg->date = (unsigned int)date;
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 12));
        }
        break;

    case 100:
        profile = gpiProfileListAdd(connection, profileid);
        if (!profile)
            Error(connection, GP_MEMORY_ERROR, g_021A42BC);
        if (iconnection->connectState == 3 && profile->deletedLocally) {
            gsDebugFormat(1, 4, 2, g_021A42E0, profileid);
            break;
        }
        if (profile->blocked)
            break;
        if (!profile->buddyStatus) {
            profile->buddyStatus = (GPIBuddyStatus *)gsimalloc(sizeof(GPIBuddyStatus));
            if (!profile->buddyStatus)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            memset(profile->buddyStatus, 0, sizeof(GPIBuddyStatus));
            if (profile->buddyStatusInfo) {
                profile->buddyStatus->buddyIndex = *(int *)profile->buddyStatusInfo;
                gpiRemoveBuddyStatusInfo(profile->buddyStatusInfo);
                profile->buddyStatusInfo = 0;
            } else
                profile->buddyStatus->buddyIndex = iconnection->profileList.numBuddies++;
        }
        buddyStatus = profile->buddyStatus;

        if (!gpiValueForKey(input, g_021A42CC, buffer, sizeof(buffer)))
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);

        if (!gpiValueForKey(buffer, g_021A437C, intValue, sizeof(intValue)))
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        buddyStatus->status = atoi(intValue);

        freeclear(buddyStatus->statusString);
        if (!gpiValueForKey(buffer, g_021A4380, strTemp, 256))
            strTemp[0] = 0;
        buddyStatus->statusString = goastrdup(strTemp);
        if (!buddyStatus->statusString)
            Error(connection, GP_MEMORY_ERROR, g_021A42BC);

        freeclear(buddyStatus->locationString);
        if (!gpiValueForKey(buffer, g_021A4388, strTemp, 256))
            strTemp[0] = 0;
        buddyStatus->locationString = goastrdup(strTemp);
        if (!buddyStatus->locationString)
            Error(connection, GP_MEMORY_ERROR, g_021A42BC);

        if (!gpiValueForKey(buffer, g_021A4390, intValue, sizeof(intValue)))
            buddyStatus->ip = 0;
        else
            buddyStatus->ip = (((unsigned int)atoi(intValue) >> 24) & 0xff) |
                              (((unsigned int)atoi(intValue) >> 8) & 0xff00) |
                              (((unsigned int)atoi(intValue) << 8) & 0xff0000) |
                              (((unsigned int)atoi(intValue) << 24) & 0xff000000);

        if (!gpiValueForKey(buffer, g_021A4398, intValue, sizeof(intValue)))
            buddyStatus->port = 0;
        else {
            port = (unsigned short)atoi(intValue);
            buddyStatus->port = (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00));
        }

        if (!gpiValueForKey(buffer, g_021A439C, intValue, sizeof(intValue)))
            buddyStatus->quietModeFlags = 0;
        else
            buddyStatus->quietModeFlags = atoi(intValue);

        callback = iconnection->callbacks[2];
        if (callback.callback != 0) {
            GPRecvBuddyStatusArg *arg;
            arg = (GPRecvBuddyStatusArg *)gsimalloc(sizeof(GPRecvBuddyStatusArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            arg->profile = profileid;
            arg->buddyIndex = buddyStatus->buddyIndex;
            arg->date = (unsigned int)date;
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 5));
        }
        break;

    case 101:
        if (!gpiValueForKey(input, g_021A42CC, buffer, sizeof(buffer)))
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        str = strstr(buffer, g_021A4398);
        if (!str)
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        str += 3;
        if (!*str)
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        productID = atoi(str);
        str = strstr(buffer, g_021A43A4);
        if (str)
            strzcpy(strTemp, str + 3, 256);
        else
            strTemp[0] = 0;
        callback = iconnection->callbacks[5];
        if (callback.callback != 0) {
            GPRecvGameInviteArg *arg;
            arg = (GPRecvGameInviteArg *)gsimalloc(sizeof(GPRecvGameInviteArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            arg->profile = profileid;
            arg->productID = productID;
            gsiSafeStrcpyA(arg->location, strTemp, 256);
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 0));
        }
        break;

    case 102:
        if (!gpiValueForKey(input, g_021A42CC, buffer, sizeof(buffer)))
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        gpiSendBuddyMessage(connection, profileid, 103, g_021A43A8, 0, 0);
        break;
    }

    return GP_NO_ERROR;
}






static int gpiProcessRecvBuddyStatusInfo(void **connection, char *input)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    char buffer[1024];
    int flag = 0;
    int rc;
    int profileid;
    long date;
    GPIProfile *profile;
    GPIBuddyStatusInfo *buddyStatus;
    GPICallback callback;
    GPRecvBuddyStatusArg *anArg;

    date = gsiTimeNitro(0);

    PARSE_KEY(g_021A43AC);
    profileid = atoi(buffer);
    profile = gpiProfileListAdd(connection, profileid);
    if (profile == 0) {
        gpiSetErrorString(connection, g_021A42BC);
        return 1;
    }
    if (profile->blocked == 0 && profile->deletedLocally == 0) {

    if (profile->buddyStatusInfo == 0) {
        profile->buddyStatusInfo = (GPIBuddyStatusInfo *)gsimalloc(0x3c);
        if (profile->buddyStatusInfo == 0) {
            gpiSetErrorString(connection, g_021A42BC);
            return 1;
        }
        memset(profile->buddyStatusInfo, 0, 0x3c);
        if (profile->buddyStatus != 0) {
            profile->buddyStatusInfo->buddyIndex = profile->buddyStatus->buddyIndex;
            gpiRemoveBuddyStatus((void *)profile->buddyStatus);
            profile->buddyStatus = 0;
        } else {
            profile->buddyStatusInfo->buddyIndex = iconnection->profileList.numBuddies++;
        }
        flag = 1;
        profile->buddyStatusInfo->extendedInfoKeys = ArrayNew(8, 1, gpiStatusInfoKeyFree);
        if (profile->buddyStatusInfo->extendedInfoKeys == 0) {
            gpiSetErrorString(connection, g_021A42BC);
            return flag;
        }
    }

    buddyStatus = profile->buddyStatusInfo;

    PARSE_KEY(g_021A43B8);
    buddyStatus->statusState = atoi(buffer);

    PARSE_KEY(g_021A43C0);
    buddyStatus->ip = (((unsigned int)atoi(buffer) >> 24) & 0xff) |
                         (((unsigned int)atoi(buffer) >> 8) & 0xff00) |
                         (((unsigned int)atoi(buffer) << 8) & 0xff0000) |
                         (((unsigned int)atoi(buffer) << 24) & 0xff000000);

    PARSE_KEY(g_021A43C8);
    buddyStatus->port = (unsigned short)atoi(buffer);

    PARSE_KEY(g_021A43D0);
    buddyStatus->unk24 = (((unsigned int)atoi(buffer) >> 24) & 0xff) |
                         (((unsigned int)atoi(buffer) >> 8) & 0xff00) |
                         (((unsigned int)atoi(buffer) << 8) & 0xff0000) |
                         (((unsigned int)atoi(buffer) << 24) & 0xff000000);

    PARSE_KEY(g_021A43DC);
    buddyStatus->unk28 = (((unsigned int)atoi(buffer) >> 24) & 0xff) |
                         (((unsigned int)atoi(buffer) >> 8) & 0xff00) |
                         (((unsigned int)atoi(buffer) << 8) & 0xff0000) |
                         (((unsigned int)atoi(buffer) << 24) & 0xff000000);

    PARSE_KEY(g_021A43E8);
    buddyStatus->unk2c = (unsigned short)atoi(buffer);

    PARSE_KEY(g_021A43F0);
    buddyStatus->unk2e = (unsigned short)atoi(buffer);

    PARSE_KEY(g_021A43F8);
    buddyStatus->unk18 = atoi(buffer);
    gsifree(buddyStatus->richStatus);
    buddyStatus->richStatus = 0;

    PARSE_KEY(g_021A4404);
    buddyStatus->richStatus = goastrdup(buffer);
    gsifree(buddyStatus->gameType);
    buddyStatus->gameType = 0;

    PARSE_KEY(g_021A4410);
    buddyStatus->gameType = goastrdup(buffer);
    gsifree(buddyStatus->gameVariant);
    buddyStatus->gameVariant = 0;

    PARSE_KEY(g_021A441C);
    buddyStatus->gameVariant = goastrdup(buffer);
    gsifree(buddyStatus->gameMapName);
    buddyStatus->gameMapName = 0;

    PARSE_KEY(g_021A4428);
    buddyStatus->gameMapName = goastrdup(buffer);

    PARSE_KEY(g_021A4434);
    buddyStatus->unk34 = atoi(buffer);

    PARSE_KEY(g_021A4440);
    buddyStatus->unk30 = atoi(buffer);

    callback = iconnection->callbacks[2];
    if (callback.callback != 0) {
        anArg = (GPRecvBuddyStatusArg *)gsimalloc(0xc);
        if (anArg == 0) {
            gpiSetErrorString(connection, g_021A42BC);
            return 1;
        }
        anArg->date = date;
        anArg->buddyIndex = buddyStatus->buddyIndex;
        anArg->profile = profileid;
        rc = gpiAddCallback(connection, callback, anArg, 0, 0);
        if (rc != 0)
            return rc;
    }
    }
    return 0;
}







/*
 * sdk:      gpiProcessRecvBuddyList (gpibuddy.o)
 *
 * The 28-byte byte-store zero loop after gsimalloc is __builtin__clear on
 * the new GPIBuddyStatus (no memset call in the object).
 */
int gpiProcessRecvBuddyList(void **connection, char *input)
{
    int i;
    int num;
    unsigned int j;
    int index = 0;
    char c;
    char *str;
    char buffer[512];
    GPIProfile *profile;
    int profileid;
    GPIConnection *iconnection = (GPIConnection *)*connection;

    if (gpiCheckForError(connection, input, 1))
        return 4;

    if (!gpiValueForKeyWithIndex(input, g_021A4450, &index, buffer, sizeof(buffer))) {
        gpiSetError(connection, 1, g_021A4280);
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }
    num = atoi(buffer);

    str = strstr(input, g_021A4458);
    if (str == 0) {
        gpiSetError(connection, 1, g_021A4280);
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }
    index += 6;

    for (i = 0; i < num; i++) {
        if (i == 0) {
            for (j = 0; (j < sizeof(buffer)) && ((c = str[j + 6]) != '\0') && (c != ','); j++)
                buffer[j] = c;
            buffer[j] = '\0';
            index += j;
        } else {
            if (!gpiValueForKeyWithIndex(input, g_021A4460, &index, buffer, sizeof(buffer))) {
                gpiSetError(connection, 1, g_021A4280);
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
        }

        profileid = atoi(buffer);
        profile = gpiProfileListAdd(connection, profileid);
        if (profile == 0) {
            gpiSetErrorString(connection, g_021A42BC);
            return 1;
        }
        profile->buddyStatus = (GPIBuddyStatus *)gsimalloc(sizeof(GPIBuddyStatus));
        if (profile->buddyStatus == 0) {
            gpiSetErrorString(connection, g_021A42BC);
            return 1;
        }
        __builtin__clear(profile->buddyStatus, sizeof(GPIBuddyStatus));
        profile->buddyStatus->buddyIndex = iconnection->profileList.numBuddies++;
        profile->buddyStatus->status = 0;
        gpiBuddyDeletedLocally(connection, profileid, 0);
    }
    return 0;
}







/*
 * sdk:      gpiSendServerBuddyMessage (gpibuddy.o)
 */
int gpiSendServerBuddyMessage(void **connection, int profileid, int type, char *message)
{
    GPIConnection *iconnection;
    char buffer[3501];

    iconnection = (GPIConnection *)*connection;
    strzcpy(buffer, message, 3501);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4278);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, type);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A424C);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, iconnection->sessKey);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4464);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, profileid);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A42CC);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, buffer);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4270);
    return 0;
}







int gpiSendBuddyMessage(void **connection, int profileid, int type, char *message, int sendOption, GPIPeerOp *peerOp)
{
    GPResult result;
    GPIProfile *profile;
    GPIPeer *peer;

    peer = gpiGetPeerByProfile(connection, profileid);
    if (peer == 0) {
        if (!func_0218FD9C(connection, profileid, &profile) || profile->buddyStatusInfo == 0 || profile->buddyStatusInfo->port == 0) {
            if (sendOption == 0xb00)
                return GP_NETWORK_ERROR;
            return gpiSendServerBuddyMessage(connection, profileid, type, message);
        }
        peer = gpiAddPeer(connection, profileid, 1);
        if (peer == 0)
            return GP_MEMORY_ERROR;
        if (profile->peerSig == 0) {
            result = func_0218F1E0(connection, peer);
            if (result != GP_NO_ERROR)
                return result;
        } else {
            result = gpiPeerStartConnect(connection, peer);
            if (result != GP_NO_ERROR)
                return result;
        }
    } else if (peer->state == 0x6a) {
        if (func_0218FD9C(connection, profileid, &profile)) {
            if (profile->buddyStatusInfo != 0)
                profile->buddyStatusInfo->port = 0;
            if (sendOption == 0xb00)
                return GP_NETWORK_ERROR;
            if (type < 100)
                return gpiSendServerBuddyMessage(connection, profileid, type, message);
        }
    }
    if (peerOp != 0)
        func_0218F884(peer, peerOp);
    result = gpiPeerAddMessage(connection, peer, type, message);
    if (result != GP_NO_ERROR)
        return result;
    return GP_NO_ERROR;
}






/*
 * sdk:      gpiBuddyHandleKeyRequest (gpibuddy.o)
 */
int gpiBuddyHandleKeyRequest(void **connection, GPIPeer *peer)
{
    char *message;
    int result;

    if ((result = gpiSaveKeysToBuffer(connection, &message)) != 0)
        return result;
    if (message == 0)
        message = g_021A4468;
    if ((result = gpiSendBuddyMessage(connection, peer->profile, 0x69, message, 0xB00, 0)) != 0)
        return result;
    {
        char *m = message;
        if (strcmp(m, g_021A4468) != 0)
            gsifree(m);
    }
    return 0;
}






/*
 * sdk:      gpiBuddyHandleKeyReply (gpibuddy.o)
 */
int gpiBuddyHandleKeyReply(void **connection, GPIPeer *peer, char *buffer)
{
    GPIProfile *pProfile;

    if (!func_0218FD9C(connection, peer->profile, &pProfile)) {
        gpiSetErrorString(connection, g_021A446C);
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
            GPGetBuddyStatusInfoKeysArg *arg = gsimalloc(sizeof(GPGetBuddyStatusInfoKeysArg));
            callback.callback = anIterator->callback;
            callback.param = anIterator->userData;
            arg->keys = 0;
            arg->numKeys = 0;
            arg->values = 0;
            arg->profile = peer->profile;
            gpiAddCallback(connection, callback, arg, 0, 0);
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

        gpiReadKeyAndValue(connection, buffer, &index, keyName, keyVal);
        if (strcmp(keyName, g_021A4480) != 0) {
            gpiSetError(connection, 1, g_021A4488);
            gpiCallErrorCallback(connection, 3, 0);
            return 3;
        }
        numKeys = atoi(keyVal);
        if (numKeys == 0) {
            GPIPeerOp *anIterator;
            for (anIterator = peer->firstOp; anIterator != 0; anIterator = anIterator->next)
                if (anIterator->type == 0x68)
                    break;
            if (!anIterator)
                return 0;
            else if (anIterator->type == 0x68 && anIterator->callback != 0) {
                GPICallback callback;
                GPGetBuddyStatusInfoKeysArg *arg = gsimalloc(sizeof(GPGetBuddyStatusInfoKeysArg));
                callback.callback = anIterator->callback;
                callback.param = anIterator->userData;
                arg->keys = 0;
                arg->numKeys = 0;
                arg->values = 0;
                arg->profile = peer->profile;
                gpiAddCallback(connection, callback, arg, 0, 0);
                gpiPeerRemoveOp(peer, anIterator);
            }
        } else {
            keys = gsimalloc(sizeof(char *) * numKeys);
            values = gsimalloc(sizeof(char *) * numKeys);
            for (i = 0; i < numKeys; i++) {
                gpiReadKeyAndValue(connection, buffer, &index, keyName, keyVal);
                B64Decode(keyName, decodeKey, (int)strlen((const char *)keyName), &decodedLen, 2);
                decodeKey[decodedLen] = '\0';
                B64Decode(keyVal, decodeVal, (int)strlen((const char *)keyVal), &decodedLen, 2);
                decodeVal[decodedLen] = '\0';
                keys[i] = goastrdup(decodeKey);
                values[i] = goastrdup(decodeVal);
                if (gpiStatusInfoCheckKey(connection, pProfile->buddyStatusInfo->extendedInfoKeys, decodeKey, &checkKey) == 0 && checkKey == 0)
                    gpiStatusInfoAddKey(connection, pProfile->buddyStatusInfo->extendedInfoKeys, decodeKey, decodeVal);
                else
                    gpiStatusInfoSetKey(connection, pProfile->buddyStatusInfo->extendedInfoKeys, decodeKey, decodeVal);
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
                    GPGetBuddyStatusInfoKeysArg *arg = gsimalloc(sizeof(GPGetBuddyStatusInfoKeysArg));
                    callback.callback = anIterator->callback;
                    callback.param = anIterator->userData;
                    arg->numKeys = numKeys;
                    arg->keys = keys;
                    arg->values = values;
                    arg->profile = peer->profile;
                    gpiAddCallback(connection, callback, arg, 0, 0xe);
                    gpiPeerRemoveOp(peer, anIterator);
                }
            }
        }
    }
    return 0;
}






int gpiAuthBuddyRequest(void **connection, int profile)
{
    GPIConnection *iconnection;
    GPIProfile *pProfile;
    int __result__;

    iconnection = (GPIConnection *)*connection;

    if (!gpiGetProfile(connection, profile, &pProfile)) {
        gpiSetErrorString(connection, g_021A446C);
        return 2;
    }
    if (pProfile->authSig == 0) {
        gpiSetErrorString(connection, g_021A446C);
        return 2;
    }

    __result__ = gpiSendAuthBuddyRequest(connection, pProfile);
    if (__result__ != 0)
        return __result__;

    pProfile->requestCount = pProfile->requestCount - 1;

    if (iconnection->infoCaching == 0
        && pProfile->requestCount <= 0) {
        gsifree(pProfile->authSig);
        pProfile->authSig = 0;
        if (gpiCanFreeProfile(pProfile))
            gpiRemoveProfile(connection, pProfile);
    }

    return 0;
}





/*
 * sdk:      gpiFixBuddyIndices (gpibuddy.o)
 */
int gpiFixBuddyIndices(int unused, GPIProfile *profile, int baseIndex)
{
    if (profile->buddyStatus != 0 && profile->buddyStatus->buddyIndex > baseIndex)
        profile->buddyStatus->buddyIndex--;
    else if (profile->buddyStatusInfo != 0 && profile->buddyStatusInfo->buddyIndex > baseIndex)
        profile->buddyStatusInfo->buddyIndex--;
    return 1;
}



int gpiDeleteBuddy(void **connection, int profile, int sendServerRequest)
{
    GPIProfile *pProfile;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int index;

    if (!func_0218FD9C(connection, profile, &pProfile)) {
        gpiSetErrorString(connection, g_021A446C);
        return 2;
    }

    if (sendServerRequest == 1) {
        gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A44AC);
        gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A424C);
        gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, iconnection->sessKey);
        gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A44B8);
        gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, pProfile->profileId);
        gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4270);
    }
    gpiBuddyDeletedLocally(connection, profile, 1);

    if (pProfile->buddyStatus) {
        index = pProfile->buddyStatus->buddyIndex;
        gsifree(pProfile->buddyStatus->statusString);
        pProfile->buddyStatus->statusString = 0;
        gsifree(pProfile->buddyStatus->locationString);
        pProfile->buddyStatus->locationString = 0;
        gsifree(pProfile->buddyStatus);
        pProfile->buddyStatus = 0;
        iconnection->profileList.numBuddies--;
        func_0218FFFC(connection, (int (*)(void **, GPIProfile *, void *))gpiFixBuddyIndices, (void *)index);
    }
    if (pProfile->buddyStatusInfo) {
        index = pProfile->buddyStatusInfo->buddyIndex;
        gsifree(pProfile->buddyStatusInfo->richStatus);
        pProfile->buddyStatusInfo->richStatus = 0;
        gsifree(pProfile->buddyStatusInfo->gameType);
        pProfile->buddyStatusInfo->gameType = 0;
        gsifree(pProfile->buddyStatusInfo->gameVariant);
        pProfile->buddyStatusInfo->gameVariant = 0;
        gsifree(pProfile->buddyStatusInfo->gameMapName);
        pProfile->buddyStatusInfo->gameMapName = 0;
        gsifree(pProfile->buddyStatusInfo);
        pProfile->buddyStatusInfo = 0;
        if (pProfile->buddyStatusInfo->extendedInfoKeys) {
            func_021841B0(pProfile->buddyStatusInfo->extendedInfoKeys);
            pProfile->buddyStatusInfo->extendedInfoKeys = 0;
        }
        iconnection->profileList.numBuddies--;
        func_0218FFFC(connection, (int (*)(void **, GPIProfile *, void *))gpiFixBuddyIndices, (void *)index);
    }
    return 0;
}


int gpiBuddyDeletedLocally(void **connection, int id, int isDeleted)
{
    GPIProfile *pProfile;

    if (id <= 0) {
        gpiSetErrorString(connection, g_021A446C);
        return 2;
    }
    if (func_0218FD9C(connection, id, &pProfile))
        pProfile->deletedLocally = isDeleted;
    return 0;
}
