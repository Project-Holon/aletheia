/*
 * file:     gpi.c
 * unit:     yes
 * function: gpiInitialize, gpiDestroy, gpiResetProfile, gpiReset, gpiProcessConnectionManager, gpiProcess
 * address:  0x02186664
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
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   gpiInitProfiles  0x0218FB14  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   SocketStartUp  0x0217F25C  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   srand  0x020946C8  arm
 *   gpiDisconnect  0x0218B760  arm  ov009
 *   gpiStatusInfoKeysDestroy  0x0218D840  arm  ov009
 *   TableFree  0x021846B4  arm  ov009
 *   gpiStatusInfoKeysInit  0x0218D7F4  arm  ov009
 *   gpiRemoveOperation  0x0218E240  arm  ov009
 *   gpiProfileMap  0x0218FFFC  arm  ov009
 *   current_time                     0x0217F264  arm
 *   gpiAddLocalInfo                  0x0218C5FC  arm
 *   gpiSendFromBuffer                0x0218998C  arm
 *   gpiRecvToBuffer                  0x02189780  arm
 *   gpiSetError                      0x02193710  arm
 *   gpiCallErrorCallback             0x02189D78  arm
 *   gsDebugFormat                    0x0217D254  arm
 *   gsirealloc                       0x0217EAC8  arm
 *   gpiSetErrorString                0x02193734  arm
 *   gpiFindOperationByID             0x0218E290  arm
 *   gpiProcessOperation              0x0218E318  arm
 *   gpiCheckForError                 0x0219329C  arm
 *   gpiProcessRecvBuddyMessage       0x021870B8  arm
 *   gpiValueForKey                   0x02193418  arm
 *   gpiProcessRecvBuddyStatusInfo    0x02187D60  arm
 *   gpiProcessRecvBuddyList          0x02188638  arm
 *   gpiProcessRecvBlockedList        0x02190188  arm
 *   gpiProcessRemoteAuthResponse     0x0218B914  arm
 *   gpiOperationsAreBlocking         0x0218E2DC  arm
 *   msleep                           0x0217F2BC  arm
 *   gpiAppendStringToBuffer          0x0218946C  arm
 *   strstr                           0x02094B20  arm
 *   memcpy                           0x02092344  arm
 *   memmove                          0x02092364  arm
 *   atoi                             0x020964E0  arm
 *   strncmp                          0x020949F4  arm
 *   d_021A412C                       0x021A412C  data
 *   d_021A4130                       0x021A4130  data
 *   d_021A415C                       0x021A415C  data
 *   d_021A4164                       0x021A4164  data
 *   d_021A4170                       0x021A4170  data
 *   d_021A4180                       0x021A4180  data
 *   d_021A4188                       0x021A4188  data
 *   d_021A41B0                       0x021A41B0  data
 *   d_021A41B8                       0x021A41B8  data
 *   d_021A41C0                       0x021A41C0  data
 *   d_021A41C8                       0x021A41C8  data
 *   d_021A41D0                       0x021A41D0  data
 *   d_021A41D8                       0x021A41D8  data
 *   d_021A41E0                       0x021A41E0  data
 *   d_021A41E8                       0x021A41E8  data
 *   d_021A420C                       0x021A420C  data
 *   d_021A4234                       0x021A4234  data
 */
#include "../../matched/arm9_sdk/libc/strncmp/string.h"
#include "gpi_types.h"

#include "gsmemory.h"
#include "../arm9/msl_string_mem.h"
extern int   gpiInitProfiles(void **pp);
#include "gsplatformutil.h"
#include "../arm9/msl_stdlib.h"
#include "gpiconnect.h"
#include "gpikeys.h"
struct HashImplementation;
#include "hashtable.h"
#include "gpioperation.h"
extern int gpiProfileMap(GPConnection *connection, int (*func)(GPConnection *, GPIProfile *, void *), void *data);
typedef int _GPResult;
#include "gpiinfo.h"
#include "gpibuffer.h"
#include "gpiutility.h"
#include "gpicallback.h"
#include "gsdebug.h"
extern int gpiProcessRecvBuddyMessage(void **connection, char *input);
extern int gpiProcessRecvBuddyStatusInfo(void **connection, char *input);
#include "gpibuddy.h"
extern int gpiProcessRecvBlockedList(void **connection, char *input);
extern char *strstr(const char *s1, const char *s2);
#include "../arm9/msl_strtod.h"
/*
 * gpiInitialize (gpi_engine?): allocate the 0x638-byte GP connection block, * clear it, seed the state words, hand its address to gpiInitProfiles, clear * nine 8-byte pairs, run the two sub-initialisers, then publish the block * through *out. p lives on the stack because &p is taken.
 */
int gpiInitialize(void **connection, int productID, int namespaceID, int partnerID);
/*
 * sdk: gpiDestroy (gpi.o)
 */
void gpiDestroy(void **connection);
/*
 * sdk: gpiResetProfile (gpi.o) * * The object keeps profile in r1 (a leading unused parameter takes r0).
 */
int gpiResetProfile(int unused, GPIProfile *profile);
int gpiReset(GPConnection *connection);
int gpiProcessConnectionManager(void **connection);
extern char d_021A412C[], d_021A4130[], d_021A415C[], d_021A4164[];
extern char d_021A4170[], d_021A4180[], d_021A4188[], d_021A41B0[];
extern char d_021A41B8[], d_021A41C0[], d_021A41C8[], d_021A41D0[];
extern char d_021A41D8[], d_021A41E0[], d_021A41E8[], d_021A420C[];
extern char d_021A4234[];
#include "gpipeer.h"
#include "gpisearch.h"
extern int gpiReset(void **connection);




/*
 * gpiInitialize (gpi_engine?): allocate the 0x638-byte GP connection block,
 * clear it, seed the state words, hand its address to gpiInitProfiles, clear
 * nine 8-byte pairs, run the two sub-initialisers, then publish the block
 * through *connection.  p lives on the stack because &p is taken.
 */
int gpiInitialize(void **connection, int productID, int namespaceID, int partnerID)
{
    char *p;
    int i;

    *connection = 0;
    p = gsimalloc(0x638);
    if (p == 0)
        return 1;
    MSL_C_LIB_MemsetPtr(p, 0, 0x638);
    p[0] = 0;
    *(int *)(p + 0x5b8) = 0;
    *(int *)(p + 0x100) = 1;
    *(int *)(p + 0x104) = 0;
    *(int *)(p + 0x108) = 0;
    *(int *)(p + 0x10c) = 0;
    *(int *)(p + 0x60c) = productID;
    *(int *)(p + 0x610) = namespaceID;
    *(int *)(p + 0x1a4) = partnerID;

    if (gpiInitProfiles((void **)&p) == 0) {
        gsifree(p);
        return 1;
    }

    *(int *)(p + 0x5c0) = 0;
    for (i = 0; i < 9; i++) {
        *(int *)(p + i * 8 + 0x1a8) = 0;
        *(int *)(p + i * 8 + 0x1ac) = 0;
    }

    i = gpiReset((void **)&p);
    if (i != 0) {
        gpiDestroy((void **)&p);
        return i;
    }

    SocketStartUp();
    srand(current_time());
    *connection = p;
    return 0;
}




/*
 * sdk:      gpiDestroy (gpi.o)
 */
void gpiDestroy(void **connection)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;

    gpiDisconnect(connection, 1);
    gpiStatusInfoKeysDestroy(connection);
    TableFree(iconnection->profileList.profileTable);
    gsifree(iconnection);
    *connection = 0;
}




/*
 * sdk:      gpiResetProfile (gpi.o)
 *
 * The object keeps profile in r1 (a leading unused parameter takes r0).
 */
int gpiResetProfile(int unused, GPIProfile *profile)
{
    profile->buddyStatus = 0;
    profile->buddyStatusInfo = 0;
    profile->authSig = 0;
    profile->requestCount = 0;
    profile->peerSig = 0;
    profile->blocked = 0;
    profile->buddyOrBlockCache = 0;
    return 1;
}



/*
 * sdk:      gpiReset (libdwcgsgp.TWL.HYB.a gpi.o)
 */
int gpiReset(GPConnection *connection)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int result;

    iconnection->nick[0] = '\0';
    iconnection->uniquenick[0] = '\0';
    iconnection->email[0] = '\0';
    iconnection->cmSocket = -1;
    iconnection->connectState = 0;
    iconnection->socketBuffer.len = 0;
    iconnection->socketBuffer.pos = 0;
    iconnection->socketBuffer.size = 0;
    gsifree(iconnection->socketBuffer.buffer);
    iconnection->socketBuffer.buffer = 0;
    iconnection->socketBuffer.buffer = 0;
    iconnection->inputBufferSize = 0;
    gsifree(iconnection->inputBuffer);
    iconnection->inputBuffer = 0;
    iconnection->inputBuffer = 0;
    iconnection->outputBuffer.len = 0;
    iconnection->outputBuffer.pos = 0;
    iconnection->outputBuffer.size = 0;
    gsifree(iconnection->outputBuffer.buffer);
    iconnection->outputBuffer.buffer = 0;
    iconnection->outputBuffer.buffer = 0;
    iconnection->updateproBuffer.len = 0;
    iconnection->updateproBuffer.pos = 0;
    iconnection->updateproBuffer.size = 0;
    gsifree(iconnection->updateproBuffer.buffer);
    iconnection->updateproBuffer.buffer = 0;
    iconnection->updateproBuffer.buffer = 0;
    iconnection->updateuiBuffer.len = 0;
    iconnection->updateuiBuffer.pos = 0;
    iconnection->updateuiBuffer.size = 0;
    gsifree(iconnection->updateuiBuffer.buffer);
    iconnection->updateuiBuffer.buffer = 0;
    iconnection->updateuiBuffer.buffer = 0;

    gpiStatusInfoKeysDestroy(connection);
    result = gpiStatusInfoKeysInit((GPConnection *)&iconnection);
    if (result != 0)
    {
        gpiDestroy((GPConnection *)&iconnection);
        return result;
    }

    iconnection->nextOperationID = 2;
    while (iconnection->operationList != 0)
        gpiRemoveOperation(connection, (GPIOperation *)iconnection->operationList);
    iconnection->operationList = 0;
    iconnection->profileList.numBuddies = 0;
    iconnection->profileList.numBlocked = 0;
    gpiProfileMap(connection, (int (*)(GPConnection *, GPIProfile *, void *))gpiResetProfile, 0);
    iconnection->userid = 0;
    iconnection->profileid = 0;
    iconnection->sessKey = 0;
    iconnection->numSearches = 0;
    iconnection->fatalError = 0;
    iconnection->peerList = 0;
    iconnection->lastStatusState = -1;
    iconnection->lastStatusString[0] = '\0';
    iconnection->lastLocationString[0] = '\0';
    iconnection->kaTransmit = 0;
    return 0;
}


int gpiProcessConnectionManager(void **connection)
{
    GPIConnection *ic;
    unsigned long now;
    GPIOperation *operation;
    int len;
    int connClosed;
    int result;
    int id;
    char *str;
    char *next;
    char *tempPtr;
    int loop;

    connClosed = 0;
    ic = (GPIConnection *)*connection;
    now = current_time();

    do {
        gpiAddLocalInfo(connection, (GPIBuffer *)&ic->outputBuffer);
        if (ic->outputBuffer.len > 0)
            ic->kaTransmit = now;
        result = gpiSendFromBuffer(connection, ic->cmSocket, &ic->outputBuffer,
                                   &connClosed, 1, d_021A412C);
        if (result)
            return result;
        result = gpiRecvToBuffer(connection, ic->cmSocket, (GPIBuffer *)&ic->socketBuffer,
                                 &len, &connClosed, d_021A412C);
        if (result) {
            if (result != 3)
                return result;
            gpiSetError(connection, (int)5, d_021A4130);
            result = 3;
            gpiCallErrorCallback(connection, result, 1);
            return result;
        }

        while ((str = (char *)strstr(ic->socketBuffer.buffer, d_021A415C)) != 0) {
            ic->kaTransmit = now;
            *str = 0;
            gsDebugFormat(1, 0, 0x20, d_021A4164, ic->socketBuffer.buffer);
            len = (int)(str - ic->socketBuffer.buffer);
            if (len > ic->inputBufferSize) {
                ic->inputBufferSize = ic->inputBufferSize + (len < 0x4000 ? 0x4000 : len);
                tempPtr = (char *)gsirealloc(ic->inputBuffer, ic->inputBufferSize + 1);
                if (tempPtr == 0) {
                    gpiSetErrorString(connection, d_021A4170);
                    return 1;
                }
                ic->inputBuffer = tempPtr;
            }
            memcpy(ic->inputBuffer, ic->socketBuffer.buffer, len + 1);
            ic->socketBuffer.len = ic->socketBuffer.len - ((str + 7) - ic->socketBuffer.buffer);
            memmove(ic->socketBuffer.buffer, str + 7, ic->socketBuffer.len + 1);
            str = ic->inputBuffer;
            next = (char *)strstr(str, d_021A4180);
            if (next) {
                id = atoi((next + 4));
                if (!gpiFindOperationByID(connection, &operation, id)) {
                    gsDebugFormat(1, 0, 1, d_021A4188, id);
                } else {
                    result = gpiProcessOperation(connection, operation, ic->inputBuffer);
                    if (result)
                        return result;
                }
            } else {
                if (gpiCheckForError(connection, str, 1))
                    return 4;
                str = ic->inputBuffer;
                if (strncmp(str, d_021A41B0, 4) == 0) {
                    result = gpiProcessRecvBuddyMessage(connection, str);
                    if (result)
                        return result;
                } else if (strncmp(str, d_021A41B8, 4) == 0) {
                } else if (strncmp(str, d_021A41C0, 4) == 0) {
                    gpiValueForKey(str, d_021A41C0, ic->loginTicket, 0x19);
                } else if (strncmp(str, d_021A41C8, 5) == 0) {
                    result = gpiProcessRecvBuddyStatusInfo(connection, str);
                    if (result)
                        return result;
                } else if (strncmp(str, d_021A41D0, 5) == 0) {
                    result = gpiProcessRecvBuddyList(connection, str);
                    if (result)
                        return result;
                } else if (strncmp(str, d_021A41D8, 5) == 0) {
                    result = gpiProcessRecvBlockedList(connection, str);
                    if (result)
                        return result;
                } else if (strncmp(str, d_021A41E0, 5) == 0) {
                    result = gpiProcessRemoteAuthResponse(connection, str);
                    if (result)
                        return result;
                } else {
                    gsDebugFormat(1, 0, 1, d_021A41E8);
                }
            }
        }

        if (connClosed != 0 && ic->connectState != 5) {
            gpiSetError(connection, (int)7, d_021A420C);
            gpiCallErrorCallback(connection, 3, 1);
            return 0;
        }
        loop = gpiOperationsAreBlocking((char *)connection);
        if (loop)
            msleep(10);
    } while (loop);

    if ((now - ic->kaTransmit) > 120000) {
        gpiAppendStringToBuffer(connection, &ic->outputBuffer, d_021A4234);
        ic->kaTransmit = now;
    }
    return 0;
}

int gpiProcess(void **connection, int blockingOperationID)
{
    GPIConnection *iconnection;
    GPIOperation *operation;
    int result;
    int loop;
    int __result__;

    iconnection = (GPIConnection *)*connection;
    result = 0;

    if (iconnection->connectState == 1) {
        do {
            result = gpiCheckConnect(connection);
            if (result == 0 && blockingOperationID != 0
                && iconnection->connectState == 1)
                loop = 1;
            else
                loop = 0;
            if (loop)
                msleep(10);
        } while (loop);

        if (result != 0) {
            if (gpiFindOperationByID(connection, &operation, 1))
                operation->result = 4;
        }
    }

    if (iconnection->connectState == 3
        || iconnection->connectState == 2
        || iconnection->connectState == 5) {
        if (result == 0)
            result = gpiProcessConnectionManager(connection);
        if (result == 0)
            result = gpiProcessPeers(connection);
    }
    if (result == 0)
        result = gpiProcessSearches(connection);

    operation = *(GPIOperation **)((char *)iconnection + 0x5c4);
    while (operation != 0) {
        if (operation->result == 0) {
            operation = operation->pnext;
        } else {
            GPIOperation *op;
            gpiFailedOpCallback(connection, operation);
            op = operation;
            operation = op->pnext;
            gpiRemoveOperation(connection, op);
        }
    }

    __result__ = gpiProcessCallbacks(connection, blockingOperationID);
    if (__result__ != 0)
        return __result__;
    if (*(int *)((char *)iconnection + 0x5bc) != 0) {
        gpiDisconnect(connection, 0);
        gpiReset(connection);
    }
    return result;
}
