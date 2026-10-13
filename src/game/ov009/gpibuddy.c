/*
 * file:     gpibuddy.c
 * unit:     yes
 * function: gpiSendAuthBuddyRequest, gpiProcessRecvBuddyMessage, gpiProcessRecvBuddyStatusInfo, func_02188638, func_021888C0, func_021889A0, func_02188B0C, func_02188BA0, func_02188FD8, func_021890A4, func_021890E0, func_02189300
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
 *   func_0219329C  0x0219329C  arm   ov009
 *   func_02193378  0x02193378  arm   ov009
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189D78  arm   ov009
 *   func_020964E0  0x020964E0  arm
 *   func_02094B20  0x02094B20  arm
 *   func_0218FCD8  0x0218FCD8  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_0217EAB0  0x0217EAB0  arm   ov009
 *   g_021A4450     0x021A4450  data
 *   g_021A4458     0x021A4458  data
 *   g_021A4460     0x021A4460  data
 *   func_0219327C  0x0219327C  arm   ov009
 *   func_0218946C  0x0218946C  arm   ov009
 *   func_0218949C  0x0218949C  arm   ov009
 *   g_021A4464     0x021A4464  data  ov009
 *   func_0218F0B8  0x0218F0B8  arm   ov009
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   func_0218F150  0x0218F150  arm   ov009
 *   func_0218F1E0  0x0218F1E0  arm   ov009
 *   func_0218F248  0x0218F248  arm   ov009
 *   func_0218F884  0x0218F884  arm   ov009
 *   func_0218F350  0x0218F350  arm   ov009
 *   func_0218DA40  0x0218DA40  arm   ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0217EAE0  0x0217EAE0  arm   ov009
 *   g_021A4468     0x021A4468  data  ov009
 *   func_02189DFC  0x02189DFC  arm   ov009
 *   func_0219359C  0x0219359C  arm   ov009
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
 *   gpiCanFreeProfile       0x02190140  arm
 *   gpiRemoveProfile        0x0218FF24  arm
 *   func_0218FFFC  0x0218FFFC  arm   ov009
 *   func_021841B0  0x021841B0  arm   ov009
 *   g_021A44AC     0x021A44AC  data
 *   g_021A44B8     0x021A44B8  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "gpi_types.h"

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
extern int gpiAppendStringToBuffer(void **connection, GPIBuffer *outputBuffer, char *buffer);
extern int gpiAppendIntToBuffer(void **connection, GPIBuffer *outputBuffer, int num);
extern int gpiValueForKey(char *command, char *key, char *value, int len);
extern void gpiSetError(void **connection, int errorCode, char *errorString);
extern void gpiCallErrorCallback(void **connection, int result, int fatal);
extern int atoi(const char *s);
extern long gsiTimeNitro(long *timer);
extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(void **connection, char *errorString);
extern unsigned long strlen(const char *s);
extern char *strcpy(char *dst, const char *src);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg,
                          void *operation, int type);
extern GPIProfile *gpiProfileListAdd(void **connection, int id);
extern char *strstr(const char *s, const char *t);
extern void gsifree(void *ptr);
extern char *goastrdup(char *src);
extern void strzcpy(char *dest, char *src, unsigned long len);
extern void gsDebugFormat(int theCat, int theType, int theLevel, char *theTokenStr, ...);
extern void gpiRemoveBuddyStatusInfo(void *buddyStatusInfo);
extern unsigned long gsiSafeStrcpyA(char *dst, char *src, unsigned long size);
extern int gpiSendBuddyMessage(void **connection, int profileid, int type,
                               char *message, int sendOption, void *peerOp);
extern void *memset(void *dst, int ch, unsigned long n);
extern void gpiRemoveBuddyStatus(void *buddyStatus);
extern void *ArrayNew(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void gpiStatusInfoKeyFree(void *ptr);
extern int func_0219329C(void **connection, char *input, int flag);
extern int func_02193378(char *command, char *key, int *index, char *value, int len);
extern void func_02193710(void **connection, int code, char *string);
extern int func_02189D78(void **connection, int result, int fatal);
extern int func_020964E0(const char *s);
extern char *func_02094B20(const char *s1, const char *s2);
extern GPIProfile *func_0218FCD8(void **connection, int id);
extern void func_02193734(void **connection, char *string);
extern void *func_0217EAB0(unsigned long size);
extern void func_0219327C(char *dest, char *src, int len);
extern int func_0218946C(void **connection, GPIBuffer *buffer, const char *string);
extern int func_0218949C(void **connection, GPIBuffer *buffer, int value);
extern GPIPeer *func_0218F0B8(void **connection, int profileid);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern GPIPeer *func_0218F150(void **connection, int profileid, int initiate);
extern int func_0218F1E0(void **connection, GPIPeer *peer);
extern int func_0218F248(void **connection, GPIPeer *peer);
extern void func_0218F884(GPIPeer *peer, GPIPeerOp *operation);
extern GPResult func_0218F350(void **connection, GPIPeer *peer, int type, char *message);
extern int func_0218DA40(void **connection, char **buffer);
extern int func_020948E0(const char *s1, const char *s2);
extern void func_0217EAE0(void *ptr);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern int func_0219359C(void **connection, char *buffer, int *index, char *key, char *value);
extern int func_0209477C(const u8 *s);
extern void func_0217F8B4(const char *input, char *output, int inlen, int *outlen, int encodingType);
extern char *func_0217F1E0(char *src);
extern int func_0218D9A8(void **connection, void *keys, char *keyName, char **keyValue);
extern int func_0218D878(void **connection, void *keys, char *theKeyName, char *theKeyValue);
extern int func_0218D900(void **connection, void *keys, char *keyName, char *newValue);
extern void func_0218F900(GPIPeer *peer, GPIPeerOp *operation);
extern int gpiGetProfile(void **connection, int profileid, GPIProfile **pProfile);
extern int gpiCanFreeProfile(GPIProfile *profile);
extern void gpiRemoveProfile(void **connection, GPIProfile *profile);
extern int func_0218FFFC(void **connection, int (*func)(void **, GPIProfile *, void *), void *data);
extern void func_021841B0(void *array);
int gpiSendAuthBuddyRequest(void **connection, GPIProfile *profile);
int func_02188638(void **connection, char *input);
int func_021888C0(void **connection, int profileid, int type, char *message);
int func_021889A0(void **connection, int profileid, int type, char *message, int sendOption, GPIPeerOp *peerOp);
int func_02188B0C(void **connection, GPIPeer *peer);
int func_02188BA0(void **connection, GPIPeer *peer, char *buffer);
int gpiAuthBuddyRequest(void **connection, int profile);
int func_021890A4(int unused, GPIProfile *profile, int baseIndex);
int func_021890E0(void **connection, int profile, int sendServerRequest);
int func_02189300(void **connection, int id, int isDeleted);
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
int func_02188638(void **connection, char *input)
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

    if (func_0219329C(connection, input, 1))
        return 4;

    if (!func_02193378(input, g_021A4450, &index, buffer, sizeof(buffer))) {
        func_02193710(connection, 1, g_021A4280);
        func_02189D78(connection, 3, 1);
        return 3;
    }
    num = func_020964E0(buffer);

    str = func_02094B20(input, g_021A4458);
    if (str == 0) {
        func_02193710(connection, 1, g_021A4280);
        func_02189D78(connection, 3, 1);
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
            if (!func_02193378(input, g_021A4460, &index, buffer, sizeof(buffer))) {
                func_02193710(connection, 1, g_021A4280);
                func_02189D78(connection, 3, 1);
                return 3;
            }
        }

        profileid = func_020964E0(buffer);
        profile = func_0218FCD8(connection, profileid);
        if (profile == 0) {
            func_02193734(connection, g_021A42BC);
            return 1;
        }
        profile->buddyStatus = (GPIBuddyStatus *)func_0217EAB0(sizeof(GPIBuddyStatus));
        if (profile->buddyStatus == 0) {
            func_02193734(connection, g_021A42BC);
            return 1;
        }
        __builtin__clear(profile->buddyStatus, sizeof(GPIBuddyStatus));
        profile->buddyStatus->buddyIndex = iconnection->profileList.numBuddies++;
        profile->buddyStatus->status = 0;
        func_02189300(connection, profileid, 0);
    }
    return 0;
}







/*
 * sdk:      gpiSendServerBuddyMessage (gpibuddy.o)
 */
int func_021888C0(void **connection, int profileid, int type, char *message)
{
    GPIConnection *iconnection;
    char buffer[3501];

    iconnection = (GPIConnection *)*connection;
    func_0219327C(buffer, message, 3501);
    func_0218946C(connection, &iconnection->outputBuffer, g_021A4278);
    func_0218949C(connection, &iconnection->outputBuffer, type);
    func_0218946C(connection, &iconnection->outputBuffer, g_021A424C);
    func_0218949C(connection, &iconnection->outputBuffer, iconnection->sessKey);
    func_0218946C(connection, &iconnection->outputBuffer, g_021A4464);
    func_0218949C(connection, &iconnection->outputBuffer, profileid);
    func_0218946C(connection, &iconnection->outputBuffer, g_021A42CC);
    func_0218946C(connection, &iconnection->outputBuffer, buffer);
    func_0218946C(connection, &iconnection->outputBuffer, g_021A4270);
    return 0;
}







int func_021889A0(void **connection, int profileid, int type, char *message, int sendOption, GPIPeerOp *peerOp)
{
    GPResult result;
    GPIProfile *profile;
    GPIPeer *peer;

    peer = func_0218F0B8(connection, profileid);
    if (peer == 0) {
        if (!func_0218FD9C(connection, profileid, &profile) || profile->buddyStatusInfo == 0 || profile->buddyStatusInfo->port == 0) {
            if (sendOption == 0xb00)
                return GP_NETWORK_ERROR;
            return func_021888C0(connection, profileid, type, message);
        }
        peer = func_0218F150(connection, profileid, 1);
        if (peer == 0)
            return GP_MEMORY_ERROR;
        if (profile->peerSig == 0) {
            result = func_0218F1E0(connection, peer);
            if (result != GP_NO_ERROR)
                return result;
        } else {
            result = func_0218F248(connection, peer);
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
                return func_021888C0(connection, profileid, type, message);
        }
    }
    if (peerOp != 0)
        func_0218F884(peer, peerOp);
    result = func_0218F350(connection, peer, type, message);
    if (result != GP_NO_ERROR)
        return result;
    return GP_NO_ERROR;
}






/*
 * sdk:      gpiBuddyHandleKeyRequest (gpibuddy.o)
 */
int func_02188B0C(void **connection, GPIPeer *peer)
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
int func_021890A4(int unused, GPIProfile *profile, int baseIndex)
{
    if (profile->buddyStatus != 0 && profile->buddyStatus->buddyIndex > baseIndex)
        profile->buddyStatus->buddyIndex--;
    else if (profile->buddyStatusInfo != 0 && profile->buddyStatusInfo->buddyIndex > baseIndex)
        profile->buddyStatusInfo->buddyIndex--;
    return 1;
}



int func_021890E0(void **connection, int profile, int sendServerRequest)
{
    GPIProfile *pProfile;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int index;

    if (!func_0218FD9C(connection, profile, &pProfile)) {
        func_02193734(connection, g_021A446C);
        return 2;
    }

    if (sendServerRequest == 1) {
        func_0218946C(connection, &iconnection->outputBuffer, g_021A44AC);
        func_0218946C(connection, &iconnection->outputBuffer, g_021A424C);
        func_0218949C(connection, &iconnection->outputBuffer, iconnection->sessKey);
        func_0218946C(connection, &iconnection->outputBuffer, g_021A44B8);
        func_0218949C(connection, &iconnection->outputBuffer, pProfile->profileId);
        func_0218946C(connection, &iconnection->outputBuffer, g_021A4270);
    }
    func_02189300(connection, profile, 1);

    if (pProfile->buddyStatus) {
        index = pProfile->buddyStatus->buddyIndex;
        func_0217EAE0(pProfile->buddyStatus->statusString);
        pProfile->buddyStatus->statusString = 0;
        func_0217EAE0(pProfile->buddyStatus->locationString);
        pProfile->buddyStatus->locationString = 0;
        func_0217EAE0(pProfile->buddyStatus);
        pProfile->buddyStatus = 0;
        iconnection->profileList.numBuddies--;
        func_0218FFFC(connection, (int (*)(void **, GPIProfile *, void *))func_021890A4, (void *)index);
    }
    if (pProfile->buddyStatusInfo) {
        index = pProfile->buddyStatusInfo->buddyIndex;
        func_0217EAE0(pProfile->buddyStatusInfo->richStatus);
        pProfile->buddyStatusInfo->richStatus = 0;
        func_0217EAE0(pProfile->buddyStatusInfo->gameType);
        pProfile->buddyStatusInfo->gameType = 0;
        func_0217EAE0(pProfile->buddyStatusInfo->gameVariant);
        pProfile->buddyStatusInfo->gameVariant = 0;
        func_0217EAE0(pProfile->buddyStatusInfo->gameMapName);
        pProfile->buddyStatusInfo->gameMapName = 0;
        func_0217EAE0(pProfile->buddyStatusInfo);
        pProfile->buddyStatusInfo = 0;
        if (pProfile->buddyStatusInfo->extendedInfoKeys) {
            func_021841B0(pProfile->buddyStatusInfo->extendedInfoKeys);
            pProfile->buddyStatusInfo->extendedInfoKeys = 0;
        }
        iconnection->profileList.numBuddies--;
        func_0218FFFC(connection, (int (*)(void **, GPIProfile *, void *))func_021890A4, (void *)index);
    }
    return 0;
}


int func_02189300(void **connection, int id, int isDeleted)
{
    GPIProfile *pProfile;

    if (id <= 0) {
        func_02193734(connection, g_021A446C);
        return 2;
    }
    if (func_0218FD9C(connection, id, &pProfile))
        pProfile->deletedLocally = isDeleted;
    return 0;
}
