/*
 * file:     ghttpEncryption.c
 * unit:     yes
 * function: ghttpSetRequestEncryptionEngine, ghiEncyptorSetRootCAList, ghiEncryptorCleanupRootCAList, ghiCompareCertUrl, ghiEncryptorGetRootCAList, ghiFreeCertificateInfo, ghiEncryptorSetTwlRootCA, ghiEncryptorCleanupTwlRootCA, SslAuthCallback, ghiTwlSSLInit, ghiEncryptorSslInitFunc, ghiEncryptorSslStartFunc, ghiEncryptorSslSendFunc, ghiEncryptorSslReceiveFunc, ghiEncryptorSslEncryptFunc, ghiEncryptorSslDecryptFunc, ghiEncryptorSslCleanupFunc
 * address:  0x021C109C
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
 *   ghiRequestToConnection      0x021C0DA4 arm ov114
 *   strncmp                     0x020949F4 arm
 *   sGhttpHttps                  0x021CE74C data
 *   ghiEncryptorSslInitFunc     0x021C1920 arm ov114
 *   ghiEncryptorSslStartFunc    0x021C1A78 arm ov114
 *   ghiEncryptorSslCleanupFunc  0x021C1C98 arm ov114
 *   ghiEncryptorSslEncryptFunc  0x021C1C88 arm ov114
 *   ghiEncryptorSslDecryptFunc  0x021C1C90 arm ov114
 *   sGhttpEmptyString    0x021CE758  data  a4
 *   sGhttpSslNullPointerOrEmpty    0x021CE75C  data  a4
 *   sGhttpEncryptionFileName    0x021CE7B0  data  a4
 *   sFuncNameGhiEncyptorSetRootCAList    0x021CE6AE  data  a1
 *   strcmp 0x020948E0  arm
 *   gsDebugFormat 0x0217D254  arm
 *   ghiGetServerAddressFromUrl  0x021c1020  arm   ov114
 *   ArraySearch  0x021843e8  arm   ov009
 *   gsifree  0x0217eae0  arm   ov009
 *   ArrayNth  0x02184208  arm   ov009
 *   ghiCompareCertUrl  0x021c121c  arm   ov114
 *   gGhttpRootCaTable     0x021d3b40  data  ov114
 *   sFuncNameGhiEncryptorGetRootCAList     0x021ce6f9  data  ov114
 *   sGhttpSslNullPointerOrEmpty2     0x021ce7c4  data  ov114
 *   sGhttpSslCouldNotFindUrl     0x021ce818  data
 *   ArrayNew  0x02184144  arm   ov009
 *   ArrayInsertSorted  0x021842D0  arm   ov009
 *   sFuncNameGhiEncryptorSetTwlRootCA     0x021CE6E0  data
 *   sGhttpSslOutOfMemoryCannot     0x021CE858  data
 *   ArrayDeleteAt  0x0218437C  arm   ov009
 *   ArrayLength  0x02184200  arm   ov009
 *   ArrayFree  0x021841B0  arm   ov009
 *   sFuncNameGhiEncryptorCleanupTwlRootCA     0x021CE72E  data
 *   sGhttpSslNullPointerOrEmpty3     0x021CE8A4  data
 *   sFuncNameSslAuthCallback                       0x021ce686 data
 *   sGhttpSslReceivedCertficate                       0x021ce8f8 data
 *   sGhttpLSCnI                       0x021ce920 data
 *   sGhttpCertificateIsOutOfDate                       0x021ce93c data
 *   sGhttpSslServerNameDoesNot                       0x021ce970 data
 *   sGhttpSslNoRootCaInstalled                       0x021ce9ac data
 *   sGhttpSslBadSignatureDoNot                       0x021ce9e4 data
 *   sGhttpSslUnknownSignatureAlgorithm                       0x021cea14 data
 *   sGhttpSslUnknownPublicKeyAlrorithm                       0x021cea44 data
 *   OS_GetLowEntropyData  0x02088168  arm
 *   CPS_SslAddRandomSeed  0x02162248  arm   ov009
 *   gsimalloc  0x0217eab0  arm   ov009
 *   MSL_C_LIB_MemsetPtr  0x020923b0  arm
 *   gGhttpSslRandomSeed     0x021d3b44  data  ov114
 *   sFuncNameGhiTwlSSLInit     0x021ce678  data  ov114
 *   sGhttpTwlFailedToAllocateMemory     0x021cea74  data  ov114
 *   sGhttpTwlUninitializedCertificateList     0x021ceab4  data  ov114
 *   sFuncNameGhiEncryptorSslInitFunc     0x021ce696  data
 *   sGhttpEncryptionLocationFormat     0x021ceae8  data
 *   sGhttpFailedToAllocateSslInterface     0x021ceaf8  data
 *   sGhttpGamespySslTwlCertificateIs     0x021ceb40  data
 *   sGhttpGamespySslTwlEngineInitialized     0x021ceb7c  data
 *   SOCL_EnableSsl                    0x0215fc80 arm  ov009
 *   sFuncNameGhiEncryptorSslStartFunc                       0x021ce6c7 data
 *   sGhttpGamespySslTwlInvalidProcessing                       0x021cebb0 data
 *   sGhttpGamespySslTwlCannotCreate                       0x021cebfc data
 *   sGhttpGamespySslTwlSocketLibrary                       0x021cec58 data
 *   sGhttpGamespySslTwlInsufficientResources                       0x021cec9c data
 *   sGhttpGamespySslTwlSocEnablessl                       0x021cecd4 data
 *   sGhttpReturnSuccess                       0x021ced20 data
 *   sFuncNameGhiEncryptorSslCleanupFunc    0x021CE713  data  a1
 *   sGhttpGamespySslTwlEngineCleanup    0x021CED3C  data  a4
 */
#include "../ov009/gsmemory.h"
#include "ghttp_types.h"
#include "../ov009/gsdebug.h"
#include "../arm9/os_entropy.h"

#include "../ov009/cps_ssl_types.h"
/* One entry of the root CA table: server URL, its CA list and a use count. */
typedef struct GHTTPCertificateInfo {
    char *serverUrl;
    void *caList;
    int reserved;
    int refCount;
} GHTTPCertificateInfo;

typedef void (*GHTTPArrayElementFreeFunc)(void *element);
typedef int (*GHTTPArrayCompareFunc)(void *a, void *b);


typedef struct GHTTPTwlCaList {
    void *certs;
    int count;
} GHTTPTwlCaList;

#include "ghttpconnection.h"
#include "../arm9/msl_string_str.h"
extern int ghiEncryptorSslInitFunc(GHIConnection *connection, GHIEncryptor *encryptor);
extern int ghiEncryptorSslStartFunc(GHIConnection *connection, GHIEncryptor *encryptor);
extern int ghiEncryptorSslCleanupFunc(GHIConnection *connection, GHIEncryptor *encryptor);
extern int ghiEncryptorSslEncryptFunc(GHIConnection *connection, void *encryptor, const char *plainText, int plainTextLen, char *cipherText, int *cipherTextLen);
extern int ghiEncryptorSslDecryptFunc(GHIConnection *connection, void *encryptor, char *readPos, int *readLen, char *writePos, int *writeLen);
struct DArrayImplementation;
#include "../ov009/darray.h"
struct DArrayImplementation;
#include "../ov009/ssl.h"
typedef unsigned int size_t;
#include "../arm9/msl_string_mem.h"
#include "../ov009/socl_ssl.h"
int ghttpSetRequestEncryptionEngine(int request, int engine);
int ghiEncyptorSetRootCAList(char *url, void *theRootCAList);
int ghiEncryptorCleanupRootCAList(char *url);
int ghiCompareCertUrl(void *a, void *b);
void *ghiEncryptorGetRootCAList(char *url);
void ghiFreeCertificateInfo(void *element);
int ghiEncryptorSetTwlRootCA(char *url, void *theRootCAList);
int ghiEncryptorCleanupTwlRootCA(char *url);
int SslAuthCallback(int result, CPSSslConnection *con, int level);
CPSSslConnection *ghiTwlSSLInit(char *url);
int ghiEncryptorSslSendFunc(void *connection, void *encryptor, char *buffer, int bufferLen, int *bytesSent);
int ghiEncryptorSslReceiveFunc(void *connection, void *encryptor, char *buffer, int *bufferLen);
extern char sGhttpHttps[];
extern char sGhttpEmptyString[];
extern char sGhttpSslNullPointerOrEmpty[];
extern char sGhttpEncryptionFileName[];
extern char sFuncNameGhiEncyptorSetRootCAList[];
extern void *gGhttpRootCaTable;
extern char sFuncNameGhiEncryptorGetRootCAList[];
extern char sGhttpSslNullPointerOrEmpty2[];
extern char sGhttpSslCouldNotFindUrl[];
extern char sFuncNameGhiEncryptorSetTwlRootCA[];
extern char sGhttpSslOutOfMemoryCannot[];
extern char sFuncNameGhiEncryptorCleanupTwlRootCA[];
extern char sGhttpSslNullPointerOrEmpty3[];
extern char sFuncNameSslAuthCallback[];       /* __FUNCTION__ */
extern char sGhttpSslReceivedCertficate[];
extern char sGhttpLSCnI[];
extern char sGhttpCertificateIsOutOfDate[];
extern char sGhttpSslServerNameDoesNot[];
extern char sGhttpSslNoRootCaInstalled[];
extern char sGhttpSslBadSignatureDoNot[];
extern char sGhttpSslUnknownSignatureAlgorithm[];
extern char sGhttpSslUnknownPublicKeyAlrorithm[];
extern u32 gGhttpSslRandomSeed[8];
extern char sFuncNameGhiTwlSSLInit[];
extern char sGhttpTwlFailedToAllocateMemory[];
extern char sGhttpTwlUninitializedCertificateList[];
extern char sFuncNameGhiEncryptorSslInitFunc[];
extern char sGhttpEncryptionLocationFormat[];
extern char sGhttpFailedToAllocateSslInterface[];
extern char sGhttpGamespySslTwlCertificateIs[];
extern char sGhttpGamespySslTwlEngineInitialized[];
extern char sFuncNameGhiEncryptorSslStartFunc[];       /* __FUNCTION__ */
extern char sGhttpGamespySslTwlInvalidProcessing[];
extern char sGhttpGamespySslTwlCannotCreate[];
extern char sGhttpGamespySslTwlSocketLibrary[];
extern char sGhttpGamespySslTwlInsufficientResources[];
extern char sGhttpGamespySslTwlSocEnablessl[];
extern char sGhttpReturnSuccess[];
extern char sFuncNameGhiEncryptorSslCleanupFunc[];
extern char sGhttpGamespySslTwlEngineCleanup[];



/*
 * sdk:      ghttpSetRequestEncryptionEngine (ghttpencryption)
 */
int ghttpSetRequestEncryptionEngine(int request, int engine)
{
    GHIConnection *connection;

    connection = ghiRequestToConnection(request);
    if (connection == 0)
        return 0;
    if (engine == 5)
        engine = 4;
    if (connection->encryptor.engine == engine)
        return 1;
    if (connection->encryptor.mInterface != 0 && connection->encryptor.engine != engine)
        return 0;
    if (engine == 0)
    {
        if (strncmp((u8 *)connection->URL, (u8 *)sGhttpHttps, 8) == 0)
            return 0;
    }
    connection->encryptor.engine = engine;
    if (engine == 0)
    {
        connection->encryptor.mInterface = 0;
        return 1;
    }
    connection->encryptor.mInterface = 0;
    connection->encryptor.initFunc = ghiEncryptorSslInitFunc;
    connection->encryptor.startFunc = ghiEncryptorSslStartFunc;
    connection->encryptor.cleanupFunc = (void (*)(GHIConnection *, void *))ghiEncryptorSslCleanupFunc;
    connection->encryptor.encryptFunc = ghiEncryptorSslEncryptFunc;
    connection->encryptor.decryptFunc = ghiEncryptorSslDecryptFunc;
    connection->encryptor.interfaceCreated = 0;
    connection->encryptor.initialized = 0;
    connection->encryptor.sessionEstablished = 0;
    connection->encryptor.encryptOnBuffer = 1;
    connection->encryptor.encryptOnSend = 0;
    connection->encryptor.handshaking = 0;
    connection->handleStatus = 1;
    return 1;
}



int ghiEncyptorSetRootCAList(char *url, void *theRootCAList)
{
    if (theRootCAList != 0 && url != 0) {
        if (strcmp(url, sGhttpEmptyString) != 0)
            goto done;
    }
    gsDebugFormat(8, 4, 1, sGhttpSslNullPointerOrEmpty, sGhttpEncryptionFileName, sFuncNameGhiEncyptorSetRootCAList, 0x74, url, theRootCAList);
    return 0;
done:
    return ghiEncryptorSetTwlRootCA(url, theRootCAList);
}


int ghiEncryptorCleanupRootCAList(char *url)
{
    return ghiEncryptorCleanupTwlRootCA(url);
}



int ghiCompareCertUrl(void *a, void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}



/*
 * sdk:      ghiEncryptorGetRootCAList (libdwcgsghttp.TWL.HYB.a ghttpencryption.o)
 */
void *ghiEncryptorGetRootCAList(char *url)
{
    GHTTPCertificateInfo certInfo;
    GHTTPCertificateInfo *certInfoToReturn;
    int pos;

    if (url == 0 || gGhttpRootCaTable == 0 || strcmp(url, sGhttpEmptyString) == 0) {
        gsDebugFormat(8, 4, 1, sGhttpSslNullPointerOrEmpty2, sGhttpEncryptionFileName, sFuncNameGhiEncryptorGetRootCAList, 0x312, url, gGhttpRootCaTable);
        return 0;
    }
    certInfo.serverUrl = ghiGetServerAddressFromUrl(url);
    pos = ArraySearch(gGhttpRootCaTable, &certInfo, ghiCompareCertUrl, 0, 1);
    gsifree(certInfo.serverUrl);
    if (pos == -1) {
        gsDebugFormat(8, 4, 1, sGhttpSslCouldNotFindUrl, sGhttpEncryptionFileName, sFuncNameGhiEncryptorGetRootCAList, 0x323, url);
        return 0;
    }
    certInfoToReturn = ArrayNth(gGhttpRootCaTable, pos);
    return certInfoToReturn->caList;
}



/*
 * Array element destructor: frees the server URL and clears the entry.
 */
void ghiFreeCertificateInfo(void *element)
{
    GHTTPCertificateInfo *info = element;
    char *serverUrl = info->serverUrl;

    info->caList = 0;
    gsifree(serverUrl);
    info->serverUrl = 0;
}



/*
 * sdk:      ghiEncryptorSetTwlRootCA (libdwcgsghttp.TWL.HYB.a(ghttpencryption.o))
 */
int ghiEncryptorSetTwlRootCA(char *url, void *theRootCAList)
{
    GHTTPCertificateInfo certInfo;
    int pos;
    GHTTPCertificateInfo *certInfoToUpdate;

    if (url == 0 || theRootCAList == 0 || strcmp(url, sGhttpEmptyString) == 0) {
        gsDebugFormat(8, 4, 1, sGhttpSslNullPointerOrEmpty, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSetTwlRootCA, 0x345, url, theRootCAList);
        return 0;
    }
    if (gGhttpRootCaTable == 0) {
        gGhttpRootCaTable = ArrayNew(sizeof(GHTTPCertificateInfo), 1, ghiFreeCertificateInfo);
        if (gGhttpRootCaTable == 0) {
            gsDebugFormat(8, 2, 1, sGhttpSslOutOfMemoryCannot, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSetTwlRootCA, 0x354);
            return 0;
        }
    }
    certInfo.serverUrl = ghiGetServerAddressFromUrl(url);
    certInfo.caList = theRootCAList;
    certInfo.refCount = 1;
    pos = ArraySearch(gGhttpRootCaTable, &certInfo, ghiCompareCertUrl, 0, 1);
    if (pos == -1) {
        ArrayInsertSorted(gGhttpRootCaTable, &certInfo, ghiCompareCertUrl);
    } else {
        gsifree(certInfo.serverUrl);
        certInfoToUpdate = ArrayNth(gGhttpRootCaTable, pos);
        certInfoToUpdate->refCount++;
    }
    return 1;
}



/*
 * sdk:      ghiEncryptorCleanupTwlRootCA (libdwcgsghttp.TWL.HYB.a(ghttpencryption.o))
 */
int ghiEncryptorCleanupTwlRootCA(char *url)
{
    int result;
    GHTTPCertificateInfo certInfo;
    int pos;
    GHTTPCertificateInfo *certInfoToUpdate;

    result = 1;
    if (url == 0 || gGhttpRootCaTable == 0 || strcmp(url, sGhttpEmptyString) == 0) {
        gsDebugFormat(8, 4, 1, sGhttpSslNullPointerOrEmpty3, sGhttpEncryptionFileName, sFuncNameGhiEncryptorCleanupTwlRootCA, 0x37b, url, gGhttpRootCaTable);
        return 0;
    }
    certInfo.serverUrl = ghiGetServerAddressFromUrl(url);
    pos = ArraySearch(gGhttpRootCaTable, &certInfo, ghiCompareCertUrl, 0, 1);
    if (pos == -1) {
        gsDebugFormat(8, 4, 1, sGhttpSslCouldNotFindUrl, sGhttpEncryptionFileName, sFuncNameGhiEncryptorCleanupTwlRootCA, 0x38a, url);
        result = 0;
    } else {
        certInfoToUpdate = ArrayNth(gGhttpRootCaTable, pos);
        certInfoToUpdate->refCount--;
        if (certInfoToUpdate->refCount <= 0) {
            ArrayDeleteAt((struct DArrayImplementation *)gGhttpRootCaTable, pos);
            if (ArrayLength(gGhttpRootCaTable) == 0) {
                ArrayFree(gGhttpRootCaTable);
                gGhttpRootCaTable = 0;
            }
        }
    }
    gsifree(certInfo.serverUrl);
    return result;
}



/*
 * sdk:      SslAuthCallback (ghttpencryption.o, static)
 */
int SslAuthCallback(int result, CPSSslConnection *con, int level)
{
    gsDebugFormat(8, 4, 8, sGhttpSslReceivedCertficate, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 938);
    gsDebugFormat(8, 4, 8, sGhttpLSCnI, level, con->subjectDn, con->commonName, con->dn);

    if (result & 0x8000) {
        gsDebugFormat(8, 4, 2, sGhttpCertificateIsOutOfDate, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 946);
        result &= ~0x8000;
    }
    if (result & 0x4000) {
        gsDebugFormat(8, 4, 2, sGhttpSslServerNameDoesNot, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 954);
        result &= ~0x4000;
    }

    switch (result & 0xff) {
    case 0:
        break;
    case 1:
        gsDebugFormat(8, 4, 2, sGhttpSslNoRootCaInstalled, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 963);
        break;
    case 2:
        gsDebugFormat(8, 4, 2, sGhttpSslBadSignatureDoNot, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 969);
        break;
    case 3:
        gsDebugFormat(8, 4, 2, sGhttpSslUnknownSignatureAlgorithm, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 975);
        break;
    case 4:
        gsDebugFormat(8, 4, 2, sGhttpSslUnknownPublicKeyAlrorithm, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 981);
        break;
    }
    return result;
}



/*
 * sdk:      ghiTwlSSLInit (libdwcgsghttp.TWL.HYB.a ghttpencryption.o)
 */
CPSSslConnection *ghiTwlSSLInit(char *url)
{
    GHTTPTwlCaList *rootCaList;
    CPSSslConnection *sslCon = 0;

    rootCaList = ghiEncryptorGetRootCAList(url);
    if (rootCaList != 0) {
        if (rootCaList->certs != 0 && rootCaList->count > 0) {
            OS_GetLowEntropyData(gGhttpSslRandomSeed);
            CPS_SslAddRandomSeed(gGhttpSslRandomSeed, 0x20);
            sslCon = gsimalloc(0x830);
            if (sslCon != 0) {
                MSL_C_LIB_MemsetPtr(sslCon, 0, 0x830);
                sslCon->hostName = 0;
                sslCon->rootCa = (SOCLCaInfo **)rootCaList->certs;
                sslCon->rootCaNum = rootCaList->count;
                sslCon->f810 = SslAuthCallback;
            } else {
                gsDebugFormat(8, 2, 2, sGhttpTwlFailedToAllocateMemory, sGhttpEncryptionFileName, sFuncNameGhiTwlSSLInit, 0x3fc);
            }
        } else {
            gsDebugFormat(8, 2, 2, sGhttpTwlUninitializedCertificateList, sGhttpEncryptionFileName, sFuncNameGhiTwlSSLInit, 0x403);
        }
    } else {
        gsDebugFormat(8, 2, 2, sGhttpTwlUninitializedCertificateList, sGhttpEncryptionFileName, sFuncNameGhiTwlSSLInit, 0x40a);
    }
    return sslCon;
}



int ghiEncryptorSslInitFunc(GHIConnection *connection, GHIEncryptor *theEncryptor)
{
    GsTwlSslInterface *sslInterface;

    gsDebugFormat(8, 4, 0xf, sGhttpEncryptionLocationFormat, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslInitFunc, 0x417);
    theEncryptor->mInterface = gsimalloc(8);
    if (theEncryptor->mInterface == 0) {
        gsDebugFormat(8, 2, 2, sGhttpFailedToAllocateSslInterface, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslInitFunc, 0x425, 8);
        return 3;
    }
    {
        char *zeroBytes = (char *)theEncryptor->mInterface;
        zeroBytes[0] = 0;
        zeroBytes[1] = 0;
        zeroBytes[2] = 0;
        zeroBytes[3] = 0;
        zeroBytes[4] = 0;
        zeroBytes[5] = 0;
        zeroBytes[6] = 0;
        zeroBytes[7] = 0;
    }
    sslInterface = theEncryptor->mInterface;
    sslInterface->con = ghiTwlSSLInit(connection->URL);
    sslInterface->connected = 0;
    if (sslInterface->con == 0) {
        gsDebugFormat(8, 4, 0xf, sGhttpGamespySslTwlCertificateIs, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslInitFunc, 0x431);
        return 3;
    }
    theEncryptor->interfaceCreated = 1;
    theEncryptor->initialized = 0;
    theEncryptor->sessionEstablished = 0;
    theEncryptor->encryptOnBuffer = 0;
    theEncryptor->encryptOnSend = 1;
    theEncryptor->handshaking = 1;
    gsDebugFormat(8, 4, 0xf, sGhttpGamespySslTwlEngineInitialized, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslInitFunc, 0x43d);
    return 1;
}



/*
 * sdk:      ghiEncryptorSslStartFunc (ghttpencryption.o)
 */
int ghiEncryptorSslStartFunc(GHIConnection *connection, GHIEncryptor *theEncryptor)
{
    GsTwlSslInterface *sslInterface = theEncryptor->mInterface;

    gsDebugFormat(8, 4, 15, sGhttpEncryptionLocationFormat, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslStartFunc, 1100);

    if (sslInterface->connected == 0) {
        int result = SOCL_EnableSsl(connection->socket, sslInterface->con);
        if (result < 0) {
            switch (result) {
            case -28:
                gsDebugFormat(8, 4, 15, sGhttpGamespySslTwlInvalidProcessing, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslStartFunc, 1113);
                break;
            case -33:
                gsDebugFormat(8, 4, 15, sGhttpGamespySslTwlCannotCreate, sFuncNameGhiEncryptorSslStartFunc, 1118);
                break;
            case -39:
                gsDebugFormat(8, 4, 15, sGhttpGamespySslTwlSocketLibrary, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslStartFunc, 1124);
                break;
            case -42:
                gsDebugFormat(8, 4, 15, sGhttpGamespySslTwlInsufficientResources, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslStartFunc, 1129);
                break;
            default:
                gsDebugFormat(8, 4, 15, sGhttpGamespySslTwlSocEnablessl, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslStartFunc, 1135, result);
                break;
            }
            connection->completed = 1;
            connection->result = 6;
            connection->socketError = result;
            return 3;
        }
        sslInterface->connected = 1;
    }

    theEncryptor->initialized = 1;
    theEncryptor->sessionEstablished = 1;
    gsDebugFormat(8, 4, 15, sGhttpReturnSuccess, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslStartFunc, 1154);
    return 1;
}



/*
 * Send stub of the engine table: reports success without sending.
 */
int ghiEncryptorSslSendFunc(void *connection, void *encryptor, char *buffer, int bufferLen, int *bytesSent)
{
    return 1;
}



int ghiEncryptorSslReceiveFunc(void *connection, void *encryptor, char *buffer, int *bufferLen)
{
    /* receive stub: reports success without reading */
    return 1;
}



int ghiEncryptorSslEncryptFunc(GHIConnection *connection, void *encryptor, const char *plainText, int plainTextLen, char *cipherText, int *cipherTextLen)
{
    return 3;
}



/*
 * sdk:      ghiEncryptorSslDecryptFunc (libdwcgsghttp.TWL.HYB.a(ghttpencryption.o))
 */
int ghiEncryptorSslDecryptFunc(GHIConnection *connection, void *encryptor, char *readPos, int *readLen, char *writePos, int *writeLen)
{
    return 3;
}



int ghiEncryptorSslCleanupFunc(GHIConnection *connection, GHIEncryptor *encryptor)
{
    gsDebugFormat(8, 4, 0xf, sGhttpGamespySslTwlEngineCleanup, sGhttpEncryptionFileName, sFuncNameGhiEncryptorSslCleanupFunc, 0x4d5);
    if (encryptor != 0) {
        GsTwlSslInterface *sslInterface = encryptor->mInterface;
        if (sslInterface != 0) {
            if (sslInterface->con != 0)
                gsifree(sslInterface->con);
            gsifree(sslInterface);
            encryptor->mInterface = 0;
        }
        encryptor->interfaceCreated = 0;
        encryptor->initialized = 0;
        encryptor->sessionEstablished = 0;
    }
    return 1;
}
