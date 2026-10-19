/*
 * file:     d_nhttp.c
 * unit:     yes
 * function: NHTTP_Startup, NHTTP_CleanupAsync, NHTTP_Cleanup, NHTTP_GetError, NHTTP_AddHeaderField, NHTTP_AddRequestHeaderField, NHTTP_AddPostDataAscii, NHTTP_AddPostDataRaw, NHTTP_GetHeaderField, NHTTP_GetHeaderAll, NHTTP_GetResultCode, NHTTP_SetVerifyOption, NHTTP_SetBasicAuthorization, NHTTP_SetRootCA, NHTTP_SetRequestRootCA
 * address:  0x021BE648
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * libnhttp public interface: startup, cleanup, header and post data setters, response readers.
 *
 * symbols:
 *   NHTTPi_Startup  0x021BA88C  arm  ov114
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *   NHTTPi_CleanupAsync  0x021BA988  arm  ov114
 *   NHTTPi_GetError  0x021BAA14  arm  ov114
 *   NHTTPi_GetRequest  0x021BEC10  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *   NHTTPi_GetBgnEndInfoP 0x021BEF3C arm ov114
 *   NHTTPi_AddRequestHeaderField 0x021BAC38 arm ov114
 *   NHTTPi_AddRequestPostDataAscii 0x021BAC58 arm ov114
 *   NHTTP_GetResponseHeaderField  0x021BBCF0  arm  ov114
 *   NHTTPi_GetResponse  0x021BEC2C  arm  ov114
 *   NHTTPi_GetResponseHeaderAll 0x021BBDFC arm ov114
 *   NHTTPi_strnlen 0x021BA124 arm ov114
 *   NHTTPi_memclr 0x021BA13C arm ov114
 *   NHTTPi_memcpy 0x021BA100 arm ov114
 *   NHTTPi_Base64Encode 0x021BA714 arm ov114
 *   sNHTTPBasicAuthColon 0x021CE53C data
 */
#include "nhttp_types.h"

extern NHTTPSysInfo *NHTTPi_GetSystemInfoP(void);
extern int NHTTPi_Startup(NHTTPSysInfo *sysInfo_p, void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio);
extern void NHTTPi_CleanupAsync(NHTTPSysInfo *sysInfo_p, void (*callback)(void));
extern u32 NHTTPi_GetError(NHTTPBgnEndInfo *bgnEndInfo_p);
extern NHTTPMutexInfo *NHTTPi_GetMutexInfoP(NHTTPSysInfo *sysInfo_p);
struct _NHTTPMutexInfo;
extern void *NHTTPi_GetRequest(NHTTPMutexInfo *mutexInfo_p, void *handle_p);
extern NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(NHTTPSysInfo *sysInfo_p);
extern int NHTTPi_AddRequestHeaderField(NHTTPReq *req_p, NHTTPBgnEndInfo *bgnEndInfo_p, char *label_p, char *value_p);
extern int NHTTPi_AddRequestPostDataAscii(NHTTPReq *req_p, NHTTPBgnEndInfo *bgnEndInfo_p, char *label_p, char *value_p);
extern void *NHTTPi_GetResponse(NHTTPMutexInfo *mutexInfo_p, void *handle_p);
extern int NHTTP_GetResponseHeaderField(NHTTPRes *res_p, char *label_p, char **value_pp);
extern int NHTTPi_GetResponseHeaderAll(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPRes *res_p, char **value_pp);
extern int NHTTPi_strnlen(char *s, int max);
extern void NHTTPi_memclr(void *dst_p, int size);
extern void NHTTPi_memcpy(void *dst, void *src, u32 size);
extern int NHTTPi_Base64Encode(char *dst_p, const char *src_p);
int NHTTP_Startup(void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio);
void NHTTP_CleanupAsync(void (*callback)(void));
void NHTTP_Cleanup(void);
u32 NHTTP_GetError(void);
void NHTTP_AddHeaderField(void *handle_p, char *label_p, char *value_p);
int NHTTP_AddRequestHeaderField(NHTTPReq *req_p, char *label_p, char *value_p);
int NHTTP_AddPostDataAscii(void *handle_p, char *label_p, char *value_p);
int NHTTP_AddPostDataRaw(void *handle_p, void *value_p, unsigned long length);
int NHTTP_GetHeaderField(void *handle_p, char *label_p, char **value_pp);
int NHTTP_GetHeaderAll(void *handle_p, char **value_pp);
int NHTTP_GetResultCode(void *handle_p);
int NHTTP_SetVerifyOption(void *handle_p, int verifyOption);
int NHTTP_SetBasicAuthorization(void *handle_p, char *username_p, char *password_p);
int NHTTP_SetRootCA(void *handle_p, void *rootCA_p, int rootCALen);
int NHTTP_SetRequestRootCA(NHTTPReq *req_p, void *rootCA_p, int rootCALen);
extern char sNHTTPBasicAuthColon[];



/*
 * NHTTP_Startup: -1 when the library could not start.
 */
int NHTTP_Startup(void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio)
{
    return -(NHTTPi_Startup(NHTTPi_GetSystemInfoP(), alloc, free, threadprio) == 0);
}



void NHTTP_CleanupAsync(void (*callback)(void))
{
    NHTTPi_CleanupAsync(NHTTPi_GetSystemInfoP(), callback);
}



/*
 * Tears the module down with a null callback.
 */
void NHTTP_Cleanup(void)
{
    NHTTPi_CleanupAsync(NHTTPi_GetSystemInfoP(), 0);
}


u32 NHTTP_GetError(void)
{
    return NHTTPi_GetError(&NHTTPi_GetSystemInfoP()->bgnEndInfo);
}








void NHTTP_AddHeaderField(void *handle_p, char *label_p, char *value_p)
{
    NHTTP_AddRequestHeaderField(NHTTPi_GetRequest(NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP()), handle_p), label_p, value_p);
}








int NHTTP_AddRequestHeaderField(NHTTPReq *req_p, char *label_p, char *value_p)
{
    NHTTPBgnEndInfo *bgnEndInfo_p;

    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(NHTTPi_GetSystemInfoP());
    if (req_p == 0) {
        return -1;
    }
    if (req_p->isStarted != 0) {
        return -1;
    }
    return -(NHTTPi_AddRequestHeaderField(req_p, bgnEndInfo_p, label_p, value_p) == 0);
}







int NHTTP_AddPostDataAscii(void *handle_p, char *label_p, char *value_p)
{
    NHTTPSysInfo *sysInfo_p = NHTTPi_GetSystemInfoP();
    NHTTPBgnEndInfo *bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    NHTTPReq *req_p = NHTTPi_GetRequest(mutexInfo_p, handle_p);
    return -(NHTTPi_AddRequestPostDataAscii(req_p, bgnEndInfo_p, label_p, value_p) == 0);
}






int NHTTP_AddPostDataRaw(void *handle_p, void *value_p, unsigned long length)
{
    NHTTPReq *req_p;
    NHTTPMutexInfo *mutexInfo_p;

    mutexInfo_p = NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP());
    req_p = NHTTPi_GetRequest(mutexInfo_p, handle_p);
    if (req_p == 0) {
        return -1;
    }
    if (req_p->isStarted != 0) {
        return -1;
    }
    if (req_p->datalist_p != 0) {
        return -1;
    }
    req_p->isRawData = 1;
    req_p->rawPostData_p = value_p;
    req_p->rawPostDataLen = length;
    return 0;
}






/*
 * Keyed lookup then dispatch; -1 when the key is unknown.
 */
int NHTTP_GetHeaderField(void *handle_p, char *label_p, char **value_pp)
{
    NHTTPRes *res_p = NHTTPi_GetResponse(NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP()), handle_p);
    if (res_p == 0)
        return -1;
    return NHTTP_GetResponseHeaderField(res_p, label_p, value_pp);
}







int NHTTP_GetHeaderAll(void *handle_p, char **value_pp)
{
    NHTTPSysInfo *sysInfo_p = NHTTPi_GetSystemInfoP();
    NHTTPBgnEndInfo *bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    NHTTPRes *res_p = NHTTPi_GetResponse(mutexInfo_p, handle_p);
    if (res_p == 0) {
        return -1;
    }
    return NHTTPi_GetResponseHeaderAll(bgnEndInfo_p, res_p, value_pp);
}







/*
 * Result code read: -1 unknown key, -1 when the header is not parsed, else the HTTP status.
 */
int NHTTP_GetResultCode(void *handle_p)
{
    NHTTPRes *res_p = NHTTPi_GetResponse(NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP()), handle_p);
    if (res_p == 0)
        return -1;
    if (res_p->isHeaderParse != 0)
        return res_p->httpStatus;
    return -1;
}







int NHTTP_SetVerifyOption(void *handle_p, int verifyOption)
{
    NHTTPReq *req_p = NHTTPi_GetRequest(NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP()), handle_p);
    if (req_p == 0)
        return -1;
    req_p->verifyOption = verifyOption;
    return 0;
}




/*
 * sdk:      NHTTP_SetBasicAuthorization (libnhttp.TWL.HYB.a(d_nhttp.o))
 */
int NHTTP_SetBasicAuthorization(void *handle_p, char *username_p, char *password_p)
{
    char tmpbuf[65];
    int password_len;
    int username_len;
    NHTTPReq *req_p;
    NHTTPMutexInfo *mutexInfo_p;

    mutexInfo_p = NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP());
    req_p = NHTTPi_GetRequest(mutexInfo_p, handle_p);
    if (req_p == 0 || username_p == 0 || password_p == 0) {
        return -1;
    }
    username_len = NHTTPi_strnlen(username_p, 0x21);
    password_len = NHTTPi_strnlen(password_p, 0x21);
    if (username_len <= 0x20 && password_len <= 0x20) {
        NHTTPi_memclr(tmpbuf, 0x41);
        NHTTPi_memcpy(tmpbuf, username_p, username_len);
        NHTTPi_memcpy(tmpbuf + username_len, sNHTTPBasicAuthColon, 1);
        NHTTPi_memcpy(tmpbuf + (username_len + 1), password_p, password_len);
        req_p->basicAuthLen = NHTTPi_Base64Encode(req_p->basicAuth, tmpbuf);
    } else {
        return -1;
    }
    return 0;
}




int NHTTP_SetRootCA(void *handle_p, void *rootCA_p, int rootCALen)
{
    return NHTTP_SetRequestRootCA(NHTTPi_GetRequest(NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP()), handle_p), rootCA_p, rootCALen);
}




int NHTTP_SetRequestRootCA(NHTTPReq *req_p, void *rootCA_p, int rootCALen)
{
    if (req_p == 0)
        return -1;
    req_p->rootCAIndex = 0;
    req_p->rootCAChainLen = 0;
    req_p->rootCA_p = rootCA_p;
    req_p->rootCALen = rootCALen;
    return 0;
}
