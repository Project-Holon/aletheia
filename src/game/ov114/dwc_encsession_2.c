/*
 * file:     dwc_encsession_2.c
 * unit:     yes
 * function: DWCi_EncSessionCompleteCallback, DWCi_EncSessionEncrypt, DWCi_EncSessionInitialize, DWCi_EncSetError, DWCi_EncSessionProcess, DWCi_EncSessionCancel, DWCi_EncSessionShutdown, DWCi_EncSessionGetResponse, DWCi_EncSessionGetPrivateAsync, DWCi_EncSessionGetAsync
 * address:  0x021C9B64
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from dwc_encsession.c by tools/splitfile.py.
 *
 * symbols:
 *   gDwcEncSession     0x021CF7AC  data
 *   strncpy  0x02094860  arm
 *   func_0205A16C  0x0205A16C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_020816B8  0x020816B8  arm
 *   strncmp  0x020949F4  arm
 *   B64Encode  0x0217FA90  arm  ov009
 *   func_02092344  0x02092344  arm
 *   strlen  0x0209477C  arm
 *   func_0205A29C  0x0205A29C  arm
 *   DWCi_EncSetError  0x021CA06C  arm  ov114
 *   sDwcEncSessionHash  0x021CF84C  data
 *   sDwcEncSessionError  0x021CF854  data
 *   strtoul  0x02095EAC  arm
 *   DWC_InitGHTTP  0x021BF558  arm  ov114
 *   gDwcEncServerUrl  0x021CF7A8  data
 *   sDwcEncSessionHttpGamestatsGsNintendowifiNet  0x021CF85C  data
 *   sDwcEncSessionHttpSdkdevGamespyComGames  0x021CF884  data
 *   sDwcEncSessionHttpIshikawaServebeerComGames  0x021CF8A8  data
 *   CTRDGi_IsTaskAvailable  0x02059F38  arm
 *   DWC_GetGHTTPDataEx  0x021BF6C4  arm  ov114
 *   DWC_ProcessGHTTP  0x021BF5B8  arm  ov114
 *   DWC_CancelGHTTPRequest  0x021BF880  arm  ov114
 *   DWC_Free       0x0205A1B0  arm
 *   DWCi_GsFree    0x0205A29C  arm
 *   DWC_ShutdownGHTTP  0x021BF57C  arm  ov114
 *   OS_SNPrintf  0x02084F80  arm
 *   OS_SPrintf  0x02084F40  arm
 *   sDwcEncSessionData  0x021CF8D0  data
 *   sDwcEncSessionPidFormat  0x021CF8D8  data
 *   sDwcEncSessionPid  0x021CF8DC  data
 *   sDwcEncSessionZeroHash  0x021CF900  data
 *   sDwcEncSessionEmptyString  0x021CF92C  data
 *   sDwcEncSessionPidHashData  0x021CF8E4  data
 *   b64size 0x021C9858 arm ov114
 *   my_randinit 0x021C9890 arm ov114
 *   my_rand 0x021C98A4 arm ov114
 *   DWCi_EncValidateKey 0x021C98E0 arm ov114
 *   DWCi_EncSessionValidateResponse 0x021C99D0 arm ov114
 *   DWCi_EncSessionProgressCallback 0x021C9B60 arm ov114
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "dwc_encsession_types.h"
#include "dwc_ghttp_types.h"

typedef union {
    char data[84];
    struct {
        char secretKey[20];
        char multiplier[8];
        char increment[8];
        char modulus[8];
        char checksumMask[8];
        char gameName[32];
    } info;
} DWCEncInitData;

typedef struct {
    long pid;
    u32 size;
} DWCEncPutHeader;

extern int strncmp(const char *a, const char *b, unsigned long n);
extern char *strncpy(char *dst, const char *src, unsigned long n);
extern void *DWC_Alloc(int name, u32 size);
extern void DWC_Free(int name, void *ptr, u32 size);
extern void B64Encode(const char *input, char *output, int inlen, int encodingType);
extern void func_020816B8(void *digest, void *data, u32 len);
extern void *func_02092344();
extern void DWCi_EncSetError(void);
extern void DWCi_GsFree(void *ptr);
extern unsigned long strtoul(const char *str, char **endptr, int base);
extern int DWC_InitGHTTP();
extern int CTRDGi_IsTaskAvailable(void);
extern void DWCi_SetError(int mode, long value);
extern int DWC_GetGHTTPDataEx(char *url, int bufferLen, int bufferClear, DWCGHTTPProgressCallback progressCallback, DWCGHTTPCompletedCallback completedCallback, void *param);
extern int DWC_ProcessGHTTP(void);
extern void DWC_CancelGHTTPRequest(int request);
extern int DWC_ShutdownGHTTP(void);
extern int OS_SNPrintf(char *dst, u32 len, const char *fmt, ...);
extern int OS_SPrintf(char *dst, const char *fmt, ...);

unsigned long b64size(unsigned long len);
void my_randinit(u32 seed);
unsigned char my_rand(void);
int DWCi_EncValidateKey(char *gameName, const char *secretKey, unsigned long multiplier, unsigned long increment, unsigned long modulus, unsigned long checksumMask);
int DWCi_EncSessionValidateResponse(char *response, int responseLen);
void DWCi_EncSessionProgressCallback(int state, const char *buffer, int bufferLen, int bytesReceived, int totalSize, void *param);

void DWCi_EncSessionCompleteCallback(char *buffer, int bufferLen, int result, void *param);
int DWCi_EncSessionEncrypt(u8 *outBuffer, u8 *header, u32 headerLen, u8 *source, u32 sourceLen);
void DWCi_EncSessionInitialize(int server, char *initData);
int DWCi_EncSessionProcess(void);
void DWCi_EncSessionCancel(void);
void DWCi_EncSessionShutdown(void);
u32 DWCi_EncSessionGetResponse(u32 *outLen);
int DWCi_EncSessionGetPrivateAsync(char *url, long pid, void *data, u32 size, DWCEncResponseCallback callback, int reuseHash);
int DWCi_EncSessionGetAsync(char *url, long pid, void *data, u32 size, DWCEncResponseCallback callback);

extern char sDwcEncSessionHash[];
extern char sDwcEncSessionError[];
extern char *gDwcEncServerUrl;
extern char sDwcEncSessionHttpGamestatsGsNintendowifiNet[];
extern char sDwcEncSessionHttpSdkdevGamespyComGames[];
extern char sDwcEncSessionHttpIshikawaServebeerComGames[];
extern char sDwcEncSessionData[];
extern char sDwcEncSessionPidFormat[];
extern char sDwcEncSessionPid[];
extern char sDwcEncSessionZeroHash[];
extern char sDwcEncSessionEmptyString[];
extern char sDwcEncSessionPidHashData[];

/*
 * Completion callback of the session HTTP requests.  State 5 receives the 32-byte
 * server challenge and builds the request hash from it; state 7 receives the response,
 * validates and delivers it.  Any other result moves the session to the error state.
 *
 * The 20-byte secretKey copy is memcpy(scratch, gDwcEncSession.secretKey, 20)
 * declared through a string.h header, so mwccarm inlines it as the rolled two-byte loop
 * and picks the object's source/dest pointer registers (r3 pool load, ip = stack+0x11).
 * A struct assignment spelled the same copy but swapped them.
 */
void DWCi_EncSessionCompleteCallback(char *buffer, int bufferLen, int result, void *param)
{
    gDwcEncSession.requestId = -1;
    if (gDwcEncSession.state == 1)
        return;
    if (result == 0) {
        switch (gDwcEncSession.state) {
        case 5:
            if (bufferLen == 32) {
                int i;
                u8 *hash = (u8 *)gDwcEncSession.hashPosition + 20;
                char scratch[52];
                char hexDigits[17] = "0123456789abcdef";

                memcpy(scratch, gDwcEncSession.secretKey, 20);
                func_02092344(scratch + 20, buffer, 32);
                func_020816B8(hash, scratch, 52);
                for (i = 0; i < 20; i++) {
                    gDwcEncSession.hashPosition[i * 2] = hexDigits[hash[i] >> 4];
                    gDwcEncSession.hashPosition[i * 2 + 1] = hexDigits[hash[i] & 15];
                }
                gDwcEncSession.hashPosition[-strlen(sDwcEncSessionHash)] = '&';
                strncpy(gDwcEncSession.lastHash, gDwcEncSession.hashPosition, 41);
                gDwcEncSession.state = 6;
            } else {
                DWCi_EncSetError();
            }
            DWCi_GsFree(buffer);
            break;
        case 7:
            if (strncmp(buffer, sDwcEncSessionError, strlen(sDwcEncSessionError)) == 0) {
                DWCi_GsFree(buffer);
                DWCi_EncSetError();
                return;
            }
            if (gDwcEncSession.responseBuffer != 0) {
                DWCi_GsFree(gDwcEncSession.responseBuffer);
                gDwcEncSession.responseBuffer = 0;
            }
            if (!DWCi_EncSessionValidateResponse(buffer, bufferLen)) {
                DWCi_GsFree(buffer);
                DWCi_EncSetError();
                return;
            }
            if (gDwcEncSession.callback != 0 && !gDwcEncSession.callback((unsigned int *)buffer, bufferLen)) {
                DWCi_GsFree(buffer);
                DWCi_EncSetError();
                return;
            }
            gDwcEncSession.responseBuffer = buffer;
            gDwcEncSession.responseBufferLen = bufferLen;
            gDwcEncSession.state = 8;
            break;
        }
    } else {
        DWCi_EncSetError();
    }
}

/*
 * Builds the encrypted request body: 4-byte checksum, header and payload, XORed with the
 * PRNG stream seeded by the byte sum, then base64-encoded into outBuffer.
 * Returns 2 when the scratch allocation fails.
 */
int DWCi_EncSessionEncrypt(u8 *outBuffer, u8 *header, u32 headerLen, u8 *source, u32 sourceLen)
{
    u8 *scratch;
    u32 sum = 0;
    int i;

    scratch = DWC_Alloc(8, sourceLen + headerLen + 4);
    if (scratch == 0)
        return 2;
    for (i = 0; i < (int)headerLen; i++)
        scratch[4 + i] = header[i];
    for (i = 0; i < (int)sourceLen; i++)
        scratch[4 + headerLen + i] = source[i];
    for (i = 0; i < (int)(sourceLen + headerLen); i++)
        sum += scratch[4 + i];
    my_randinit(sum);
    for (i = 0; i < (int)(sourceLen + headerLen); i++)
        scratch[4 + i] ^= my_rand();
    sum ^= gDwcEncSession.checksumMask;
    scratch[0] = (u8)(sum >> 24);
    scratch[1] = (u8)(sum >> 16);
    scratch[2] = (u8)(sum >> 8);
    scratch[3] = (u8)sum;
    B64Encode((char *)scratch, (char *)outBuffer, sourceLen + headerLen + 4, 2);
    DWC_Free(8, scratch, 0);
    outBuffer[b64size(sourceLen + headerLen + 4)] = 0;
    return 0;
}

/*
 * Selects the server URL, parses the hex-encoded cipher constants out of the init block and
 * stores them in the session.
 */
void DWCi_EncSessionInitialize(int server, char *initData)
{
    u32 multiplier;
    u32 increment;
    u32 modulus;
    u32 checksumMask;
    DWCEncInitData *init;
    char secretKey[21];
    char buffer[9] = {0};

    gDwcEncSession.requestId = -1;
    gDwcEncSession.request = 0;
    gDwcEncSession.hashPosition = 0;
    gDwcEncSession.payload = 0;
    gDwcEncSession.responseBuffer = 0;
    gDwcEncSession.responseBufferLen = 0;

    switch (server) {
    case 0:
        gDwcEncServerUrl = sDwcEncSessionHttpGamestatsGsNintendowifiNet;
        break;
    case 1:
        gDwcEncServerUrl = sDwcEncSessionHttpSdkdevGamespyComGames;
        break;
    case 2:
        gDwcEncServerUrl = sDwcEncSessionHttpIshikawaServebeerComGames;
        break;
    }

    init = (DWCEncInitData *)initData;
    strncpy(secretKey, init->info.secretKey, 20);
    secretKey[20] = '\0';
    multiplier = strtoul(strncpy(buffer, init->info.multiplier, 8), 0, 16);
    increment = strtoul(strncpy(buffer, init->info.increment, 8), 0, 16);
    modulus = strtoul(strncpy(buffer, init->info.modulus, 8), 0, 16);
    checksumMask = strtoul(strncpy(buffer, init->info.checksumMask, 8), 0, 16);
    DWCi_EncValidateKey(init->info.gameName, secretKey, multiplier, increment, modulus, checksumMask);
    DWC_InitGHTTP(0);
    gDwcEncSession.state = 3;
    gDwcEncSession.isInitialized = 1;
}

/*
 * Moves the session to the error state, reporting a DWC error when the cartridge task is unavailable.
 */
void DWCi_EncSetError(void)
{
    if (!CTRDGi_IsTaskAvailable())
        DWCi_SetError(6, 0xFFFEA048);
    gDwcEncSession.state = 1;
}

/*
 * Drives the session state machine: states 4 and 6 start the challenge and the real request,
 * 5 and 7 wait for them to finish.  Returns the new state.
 */
int DWCi_EncSessionProcess(void)
{
    switch (gDwcEncSession.state) {
    case 1:
        DWCi_EncSetError();
        break;
    case 4:
        gDwcEncSession.requestId = DWC_GetGHTTPDataEx(gDwcEncSession.request, 0, 0, DWCi_EncSessionProgressCallback, DWCi_EncSessionCompleteCallback, 0);
        if (gDwcEncSession.requestId >= 0) {
            gDwcEncSession.state = 5;
        } else {
            DWCi_EncSetError();
        }
        break;
    case 5:
        if (DWC_ProcessGHTTP() == 0) {
            DWCi_EncSetError();
        }
        break;
    case 6:
        gDwcEncSession.requestId = DWC_GetGHTTPDataEx(gDwcEncSession.request, 0, 0, DWCi_EncSessionProgressCallback, DWCi_EncSessionCompleteCallback, 0);
        if (gDwcEncSession.requestId >= 0) {
            gDwcEncSession.state = 7;
        } else {
            DWCi_EncSetError();
        }
        break;
    case 7:
        if (DWC_ProcessGHTTP() == 0) {
            DWCi_EncSetError();
        }
        break;
    case 8:
        break;
    }
    return gDwcEncSession.state;
}

/*
 * Cancels the pending HTTP request and resets the session state.
 */
void DWCi_EncSessionCancel(void)
{
    int requestId = gDwcEncSession.requestId;
    if (requestId >= 0)
        DWC_CancelGHTTPRequest(requestId);
    gDwcEncSession.state = 0;
}

/*
 * Frees the request and response buffers and shuts the GHTTP layer down.
 */
void DWCi_EncSessionShutdown(void)
{
    if (gDwcEncSession.isInitialized == 0) {
        return;
    }
    if (gDwcEncSession.request != 0) {
        DWC_Free(8, gDwcEncSession.request, 0);
        gDwcEncSession.request = 0;
    }
    if (gDwcEncSession.responseBuffer != 0) {
        DWCi_GsFree(gDwcEncSession.responseBuffer);
        gDwcEncSession.responseBufferLen = 0;
        gDwcEncSession.responseBuffer = 0;
    }
    DWC_ShutdownGHTTP();
    gDwcEncSession.state = 2;
    gDwcEncSession.isInitialized = 0;
}

/*
 * Returns the decoded response body and stores its length in *outLen.
 */
u32 DWCi_EncSessionGetResponse(u32 *outLen)
{
    *outLen = gDwcEncSession.decodedBufferLen;
    return (u32)gDwcEncSession.decodedBuffer;
}

/*
 * Builds the request URL (server, game name, url, pid, hash placeholder), encrypts the
 * payload into it and arms the session; state 6 reuses the previous hash, state 4 asks the
 * server for a challenge first.  Returns 3 when no valid key is set, 2 when allocation fails.
 *
 * The block-scoped `p` (request pointer loaded once before strlen) is the spelling that keeps
 * the load in r6 across the call.  strlen is declared returning unsigned long, which gives the
 * `strb r2, [r1, -r0]` form.
 */
int DWCi_EncSessionGetPrivateAsync(char *url, long pid, void *data, u32 size, DWCEncResponseCallback callback, int reuseHash)
{
    DWCEncPutHeader putHeader;
    char pidText[16];
    int result;

    if (gDwcEncSession.isKeyValid != 1)
        return 3;
    if (gDwcEncSession.request != 0) {
        DWC_Free(8, gDwcEncSession.request, 0);
        gDwcEncSession.request = 0;
    }
    gDwcEncSession.request = DWC_Alloc(8,
        strlen(gDwcEncServerUrl) + strlen(gDwcEncSession.gameName) + strlen(url)
        + strlen(sDwcEncSessionPid) + OS_SNPrintf(pidText, 16, sDwcEncSessionPidFormat, pid)
        + strlen(sDwcEncSessionHash) + 40 + 1 + strlen(sDwcEncSessionData) + b64size(size + 12));
    if (gDwcEncSession.request == 0)
        return 2;
    OS_SPrintf(gDwcEncSession.request, sDwcEncSessionPidHashData, gDwcEncServerUrl, gDwcEncSession.gameName, url, pid, sDwcEncSessionZeroHash, sDwcEncSessionEmptyString);
    {
        char *p = gDwcEncSession.request;
        gDwcEncSession.payload = p + strlen(p);
    }
    gDwcEncSession.hashPosition = gDwcEncSession.payload - strlen(sDwcEncSessionData) - 40;
    putHeader.pid = pid;
    putHeader.size = size;
    result = DWCi_EncSessionEncrypt((u8 *)gDwcEncSession.payload, (u8 *)&putHeader, 8, data, size);
    if (result == 2) {
        DWC_Free(8, gDwcEncSession.request, 0);
        gDwcEncSession.request = 0;
        return 2;
    }
    if (reuseHash) {
        func_02092344(gDwcEncSession.hashPosition, gDwcEncSession.lastHash, 40);
        gDwcEncSession.state = 6;
    } else {
        gDwcEncSession.hashPosition[-strlen(sDwcEncSessionHash)] = '\0';
        gDwcEncSession.state = 4;
    }
    gDwcEncSession.callback = callback;
    return 0;
}

/*
 * GetPrivateAsync without hash reuse.
 */
int DWCi_EncSessionGetAsync(char *url, long pid, void *data, u32 size, DWCEncResponseCallback callback)
{
    return DWCi_EncSessionGetPrivateAsync(url, pid, data, size, callback, 0);
}
