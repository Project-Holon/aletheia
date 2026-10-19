/*
 * file:     dwci_nd.c
 * unit:     yes
 * function: DWCi_Ndi_freeAttr, setAttr, DWCi_NdSetAttr, getNchar, decodeChar, DWCi_Ndi_getDecodeLenBASE64, DWCi_Ndi_getEncodeLenBASE64, DWCi_Ndi_encodeBASE64, DWCi_Ndi_decodeBASE64, strAlloc, DWCi_NdStartup, nhttpCleanupCallback, DWCi_NdCleanupAsync, DWCi_NdCleanupConnectionHandle, DWCi_NdSetError, DWCi_NdCancelAsync, DWCi_Ndi_getApInfo, DWCi_Ndi_getDSdesc, DWCi_Ndi_getUserAgent, req_callback, freeHttpParam, freeHttp, setupHttp, runHttp, DWCi_NdGetFileListAsync, DWCi_NdGetFileAsync, DWCi_NdGetProgress, DWCi_Ndi_response_count, DWCi_Ndi_response_contents, DWCi_Ndi_response_list, DWCi_Ndi_initLockGlobal, DWCi_Ndi_freeLockGlobal, DWCi_Ndi_lockGlobal, DWCi_Ndi_unlockGlobal, DWCi_Ndi_initHttpCallback, DWCi_Ndi_freeHttpCallback, DWCi_Ndi_prepareHttpCallback, DWCi_Ndi_unprepareHttpCallback, DWCi_Ndi_kickThread, DWCi_Ndi_getMacAddress, DWCi_Ndi_strlen, DWCi_Ndi_strncmp, DWCi_Ndi_memclr, DWCi_Ndi_memcpy, DWCi_Ndi_strToInt, DWCi_Ndi_intToStr
 * address:  0x021C5E78
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
 *   gDwciNdAttrEncoded  0x021D3BD8  data
 *   gDwciNdStatics  0x021D3B9C  data
 *   sDwciNdAbcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz  0x021CE0F4  data
 *   DWCi_Ndi_memcpy  0x021C7A44  arm  ov114
 *   NHTTP_Startup  0x021BE648  arm  ov114
 *   gDwciNdMacAddressEncoded  0x021D3BE4  data
 *   gDwciNdUserAgent  0x021D3C69  data
 *   gDwciNdGameCodeEncoded  0x021D3BCD  data
 *   gDwciNdPasswordEncoded  0x021D3C50  data
 *   gDwciNdApInfoEncoded  0x021D3BF5  data
 *   nhttpCleanupCallback   0x021C64E0  arm
 *   NHTTP_GetConnectionStatus  0x021BF3BC  arm  ov114
 *   NHTTP_DeleteConnection  0x021BF184  arm  ov114
 *   DWCi_SetError  0x02059F54  arm
 *   DWC_NdGetProgress  0x021C5E14  arm  ov114
 *   NHTTP_CancelConnection  0x021BF374  arm  ov114
 *   DWCi_Ndi_unprepareHttpCallback  0x021C797C  arm  ov114
 *   DWC_GetApInfo  0x0205CD24  arm
 *   sDwciNdEmptyMacAddress  0x021CE0E4  data
 *   gDwciNdApInfo  0x021D3C8C  data
 *   DWCi_BM_GetWiFiInfo  0x02058518  arm
 *   DWCi_Ndi_intToStrFigure  0x021C7A74  arm  ov114
 *   NHTTP_GetUserParam              0x021BF444  arm  ov114
 *   NHTTP_GetConnectionError        0x021BF488  arm  ov114
 *   NHTTP_GetHeaderField            0x021BE7FC  arm  ov114
 *   DWCi_Ndi_strToInt               0x021C7A5C  arm  ov114
 *   NHTTP_GetBodyBuffer             0x021BF3E4  arm  ov114
 *   DWCi_Ndi_strncmp                0x021C7A24  arm  ov114
 *   DWCi_Ndi_decodeBASE64           0x021C61C0  arm  ov114
 *   DWCi_Ndi_response_count         0x021C75BC  arm  ov114
 *   DWCi_Ndi_response_contents      0x021C7614  arm  ov114
 *   freeHttpParam                   0x021C6B44  arm  ov114
 *   DWCi_Ndi_kickThread             0x021C79AC  arm  ov114
 *   DWCi_NdSetError                 0x021C659C  arm  ov114
 *   sDwciNdHttpstatuscode                      0x021CF47C  data  ov114
 *   sDwciNdReturncd                      0x021CF48C  data  ov114
 *   DWCi_Ndi_getDSdesc              0x021c67fc arm
 *   DWCi_Ndi_prepareHttpCallback    0x021c7934 arm
 *   DWCi_NdCleanupConnectionHandle  0x021c654c arm
 *   NHTTP_CreateConnection          0x021bf04c arm
 *   NHTTP_SetRootCA                 0x021be9c8 arm
 *   NHTTP_SetVerifyOption           0x021be8b8 arm
 *   NHTTP_AddHeaderField            0x021be6bc arm
 *   NHTTP_AddPostDataAscii          0x021be748 arm
 *   DWCi_Ndi_strlen                 0x021c7a18 arm
 *   freeHttp                        0x021c6bec arm
 *   DWCi_Ndi_memclr                 0x021c7a30 arm
 *   DWCi_Ndi_encodeBASE64           0x021c60c8 arm
 *   gDwciNdDsGameCodeEncoded   0x021d3bc4 data
 *   gDwciNdUserIdEncoded   0x021d3c0a data
 *   sDwciNdRootCa   0x021cf37c data
 *   sDwciNdUserAgent   0x021cf498 data
 *   sDwciNdGamecd   0x021cf4a4 data
 *   sDwciNdRhgamecd   0x021cf4ac data
 *   sDwciNdPasswd   0x021cf4b8 data
 *   sDwciNdToken   0x021cf4c0 data
 *   sDwciNdUserid   0x021cf4c8 data
 *   sDwciNdMacadr   0x021cf4d0 data
 *   sDwciNdAction   0x021cf4d8 data
 *   sDwciNdAttr   0x021cf4e0 data
 *   sDwciNdAttr2   0x021cf4e8 data
 *   sDwciNdAttr3   0x021cf4f0 data
 *   sDwciNdApinfo   0x021cf4f8 data
 *   gDwciNdOptionEncoded   0x021d3ccc data
 *   sDwciNdOptionallogdata   0x021cf500 data
 *   NHTTP_StartConnection  0x021BF308  arm  ov114
 *   DWCi_Ndi_intToStr               0x021C7A68  arm  ov114
 *   DWCi_Ndi_getEncodeLenBASE64     0x021C60AC  arm  ov114
 *   runHttp                         0x021C70D4  arm  ov114
 *   DWCiNd_action_list              0x021CE0CE  data  ov114
 *   setupHttp  0x021C6C0C  arm  ov114
 *   sDwciNdYUdgvudhm  0x021CE0D7  data
 *   NHTTP_GetConnectionProgress  0x021BF4B0  arm
 *   sDwciNdContentLength                     0x021CF528  data  ov114
 *   NHTTP_CleanupAsync  0x021BE680  arm
 *   sDwciNdUserAgentFormat  0x021CF464  data
 *   gDwciNdGlobalMutex  0x021D3C38  data
 *   OS_SNPrintf  0x02084F80  arm  arm9
 *   OS_InitMutex  0x02086004  arm  arm9
 *   OS_SendMessage  0x02085DBC  arm  arm9
 *   @17416                          0x021CF510  data
 *   @17417                          0x021CF518  data
 *   @17442  0x021CF51C  data
 *   sGhttpChunkSizeFormat  0x021CF248  data
 *   gDwciNdHttpMutex  0x021D3C20  data
 *   gDwcEncSession  0x021CF7AC  data
 *   OS_LockMutex  0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 *   d_021D3C20   0x021D3C20  data
 *   OS_GetMacAddress  0x02087C6C  arm
 *   DWCi_Ndi_hexToStrFigure  0x021C7B48  arm  ov114
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   NHTTPi_strToInt  0x021BA448  arm  ov114
 *   NHTTPi_intToStr  0x021BA4E4  arm  ov114
 *   strncmp                      0x020949F4  arm
 */
#include "dwci_nd_types.h"

#define FREE(p) gDwciNdStatics.free(p)

/* Game code in the copy of the cartridge header in main memory. */
#define ROM_HEADER_GAME_CODE ((char *)0x02FFFE0C)

typedef struct NdApString {
    char b[13];
} NdApString;

typedef struct NdApInfo {
    int type;
    int idx;
    int pad;
    char bssid[9];
} NdApInfo;

typedef struct NdWiFiInfo {
    unsigned long long macid;
    int pad[3];
} NdWiFiInfo;

extern int DWCi_Ndi_intToStrFigure(char *buffer, unsigned long long value, int figure);
extern int strlen(unsigned char *s);
extern int strncmp(unsigned char *s1, unsigned char *s2, unsigned int n);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
void DWCi_Ndi_memcpy(void *dst, void *src, u32 size);
extern int NHTTP_Startup(void *alloc, void *free, int a);
extern void NHTTP_CleanupAsync(void (*callback)(void));
struct _NHTTPConnection;
extern int NHTTP_GetConnectionStatus(struct _NHTTPConnection *handle_p);
extern int NHTTP_DeleteConnection(struct _NHTTPConnection *handle_p);
extern void DWCi_SetError(int error, int errorCode);
extern int DWC_NdGetProgress(unsigned long *received, unsigned long *contentlen);
extern int NHTTP_CancelConnection(void *handle);
extern int DWC_GetApInfo(NdApInfo *apinfo);
extern void DWCi_BM_GetWiFiInfo(NdWiFiInfo *buf);
extern int OS_SNPrintf(char *dst, unsigned int len, const char *fmt, ...);
extern void *NHTTP_GetUserParam(void *handle);
extern int NHTTP_GetConnectionError(struct _NHTTPConnection *handle_p);
extern int NHTTP_GetHeaderField(void *handle, char *label_p, char **value_pp);
extern int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p);
extern struct _NHTTPConnection *NHTTP_CreateConnection(char *url_p, int method, char *buf_p, unsigned long len, int (*callback)(void *, int, void *), void *userParam_p);
extern int NHTTP_SetRootCA(void *handle_p, void *rootCA_p, int rootCALen);
extern int NHTTP_SetVerifyOption(void *handle, unsigned long verifyOption);
extern int NHTTP_AddHeaderField(void *handle, char *label_p, char *value_p);
extern int NHTTP_AddPostDataAscii(void *handle, char *label_p, char *value_p);
extern int NHTTP_StartConnection(void *handle);
extern int NHTTP_GetConnectionProgress(void *handle, unsigned long *received_p, unsigned long *contentlen_p);
#include "../sdk_os.h"

extern void OS_InitMutex(struct OSMutex *mutex);
extern void OS_LockMutex(struct OSMutex *mutex);
extern void OS_UnlockMutex(struct OSMutex *mutex);
extern int OS_SendMessage(struct OSMessageQueue *mq, void *msg, int flags);
extern void OS_GetMacAddress(unsigned char *macAddress);
extern int DWCi_Ndi_hexToStrFigure(char *p, unsigned long n, int figure);
extern int NHTTPi_strToInt(char *s, int len);
extern int NHTTPi_intToStr(char *p_p, unsigned long n);

void DWCi_Ndi_freeAttr(void);
int setAttr(int id, char *attr);
int DWCi_NdSetAttr(char *attr1, char *attr2, char *attr3);
int getNchar(unsigned char *dst, char *p, int n);
int decodeChar(unsigned char c);
u32 DWCi_Ndi_getDecodeLenBASE64(int len);
int DWCi_Ndi_getEncodeLenBASE64(int n);
int DWCi_Ndi_encodeBASE64(char *encstr, char *srcbin, int length);
int DWCi_Ndi_decodeBASE64(char *decbin, char *str, int length);
char *strAlloc(char *src);
int DWCi_NdStartup(NdAlloc alloc, NdFree free, char *url, char *token, char *gameCode, char *password, DWCNdCallback callback);
void nhttpCleanupCallback(void);
void DWCi_NdCleanupAsync(void (*callback)(void));
int DWCi_NdCleanupConnectionHandle(void *volatile handle);
void DWCi_NdSetError(int err, int serverError);
int DWCi_NdCancelAsync(void);
int DWCi_Ndi_getApInfo(char *apinfo);
int DWCi_Ndi_getDSdesc(char *gamecode, char *userid);
void DWCi_Ndi_getUserAgent(char *buffer);
int req_callback(void *res, int event, void *arg);
void freeHttpParam(tagDWCi_Ndi_HTTPREQ *hrq);
void freeHttp(tagDWCi_Ndi_HTTPREQ *hrq, void *req);
int runHttp(tagDWCi_Ndi_HTTPREQ *hrq, void *req);
int DWCi_NdGetFileListAsync(DWCNdFileInfo *filelist, int offset, int num);
int DWCi_NdGetFileAsync(DWCNdFileInfo *filelist, char *buf, unsigned int bufsize, char *opt);
int DWCi_NdGetProgress(unsigned long *received, unsigned long *contentlen);
int DWCi_Ndi_response_count(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
int DWCi_Ndi_response_contents(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
int DWCi_Ndi_response_list(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
int DWCi_Ndi_initLockGlobal(void);
void DWCi_Ndi_freeLockGlobal(void);
void DWCi_Ndi_lockGlobal(void);
void DWCi_Ndi_unlockGlobal(void);
int DWCi_Ndi_initHttpCallback(void);
void DWCi_Ndi_freeHttpCallback(void);
int DWCi_Ndi_prepareHttpCallback(void);
void DWCi_Ndi_unprepareHttpCallback(void);
void DWCi_Ndi_kickThread(void *threadEvent);
void DWCi_Ndi_getMacAddress(char *macaddr);
unsigned long DWCi_Ndi_strlen(char *p);
int DWCi_Ndi_strncmp(char *str1, char *str2, unsigned long size);
void DWCi_Ndi_memclr(void *p, int size);
int DWCi_Ndi_strToInt(char *s, int len);
int DWCi_Ndi_intToStr(char *p, unsigned long n);

extern char *gDwciNdAttrEncoded[3];
extern const char sDwciNdAbcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz[];
extern char gDwciNdMacAddressEncoded[];
extern char gDwciNdUserAgent[];
extern char gDwciNdGameCodeEncoded[];
extern char gDwciNdPasswordEncoded[];
extern char gDwciNdApInfoEncoded[];
extern NdApString sDwciNdEmptyMacAddress;
extern NdApInfo gDwciNdApInfo;
extern char sDwciNdHttpstatuscode[];
extern char sDwciNdReturncd[];
extern char gDwciNdDsGameCodeEncoded[9];
extern char gDwciNdUserIdEncoded[21];
extern char sDwciNdRootCa[];
extern char sDwciNdUserAgent[];
extern char sDwciNdGamecd[];
extern char sDwciNdRhgamecd[];
extern char sDwciNdPasswd[];
extern char sDwciNdToken[];
extern char sDwciNdUserid[];
extern char sDwciNdMacadr[];
extern char sDwciNdAction[];
extern char sDwciNdAttr[];
extern char sDwciNdAttr2[];
extern char sDwciNdAttr3[];
extern char sDwciNdApinfo[];
extern char gDwciNdOptionEncoded[89];
extern char sDwciNdOptionallogdata[];
extern char DWCiNd_action_list[9];
extern char sDwciNdYUdgvudhm[13];
extern char sDwciNdContentLength[];
extern char sDwciNdUserAgentFormat[];
extern char gDwciNdGlobalMutex[];

/*
 * sdk:      DWCi_Ndi_freeAttr (libdwcnd.TWL.HYB.a dwci_nd.o)
 */
void DWCi_Ndi_freeAttr(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (gDwciNdAttrEncoded[i] != 0) {
            gDwciNdStatics.free(gDwciNdAttrEncoded[i]);
            gDwciNdAttrEncoded[i] = 0;
        }
    }
}

/*
 * sdk:      setAttr (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int setAttr(int id, char *attr)
{
    int encLen;
    int n;
    if (*attr != 0) {
        if ((int)DWCi_Ndi_strlen(attr) > 10) {
            DWCi_NdSetError(5, 0);
            return 0;
        }
        n = DWCi_Ndi_strlen(attr);
        if (n > 10) {
            DWCi_NdSetError(5, 0);
            return 0;
        }
        gDwciNdAttrEncoded[id] = (char *)gDwciNdStatics.alloc(DWCi_Ndi_getEncodeLenBASE64(n) + 1, 4);
        if (gDwciNdAttrEncoded[id] == 0) {
            DWCi_NdSetError(1, 0);
            return 0;
        }
        encLen = DWCi_Ndi_encodeBASE64(gDwciNdAttrEncoded[id], attr, n);
        gDwciNdAttrEncoded[id][encLen] = 0;
    }
    return 1;
}

/*
 * sdk:      DWCi_NdSetAttr (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int DWCi_NdSetAttr(char *attr1, char *attr2, char *attr3)
{
    DWCi_Ndi_lockGlobal();
    DWCi_Ndi_freeAttr();
    if (setAttr(0, attr1) && setAttr(1, attr2) && setAttr(2, attr3)) {
        DWCi_Ndi_unlockGlobal();
        return 1;
    }
    DWCi_Ndi_freeAttr();
    DWCi_Ndi_unlockGlobal();
    return 0;
}

/*
 * sdk:      getNchar (libdwcnd.TWL.HYB.a dwci_nd.o)
 */
int getNchar(unsigned char *dst, char *src, int count)
{
    int i;
    int len;

    len = 0;
    for (i = 0; i < count; i++) {
        if (*src != 0) {
            *dst++ = *src;
            len++;
            src++;
        } else {
            *dst++ = 0;
        }
    }
    return len;
}

/*
 * sdk:      decodeChar (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int decodeChar(unsigned char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 26;
    if (c >= '0' && c <= '9')
        return c - '0' + 52;
    if (c == '.')
        return 62;
    if (c == '-')
        return 63;
    return -1;
}

u32 DWCi_Ndi_getDecodeLenBASE64(int len)
{
    return (len >> 2) * 3;
}

/*
 * Row stride: rounds `n` up into 3-byte triples and scales by 4.
 */
int DWCi_Ndi_getEncodeLenBASE64(int n)
{
    return ((n + 2) / 3) * 4;
}

/*
 * Three levers, all required:
 *   1. `const` on the read-only extern table sDwciNdAbcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz.  Without it the
 *      hoisted `ldr <tbl>, [pc]` grabbed r4 (the lowest free callee-saved)
 *      and the WHOLE callee-saved set rotated one register high
 *      (95 concrete diffs).  With it the allocation matches the image
 *      (r4=0-copy, r5=0, r6=len, r7=length, r8=srcbin, sb=encstr, sl=table).
 *      See docs/idioms/const-on-a-read-only-extern-table-settles-a-register-tie.md.
 *   2. the update block order is `srcbin += n; encstr += 4; len += 4;
 *      length -= n;` (srcbin first, len after encstr).  Other orders emit
 *      subs/add in the wrong place in the tail (47..55 diffs).
 *   3. the four base assignments are ordered base1 (=c[0]>>2), base0, base2,
 *      base3; this settles which scratch register (r1/r2/r3/ip) each byte
 *      load and each masked value lands in.  Declaration order of the base
 *      locals is inert; it is the statement order that colours them.
 *
 * sdk:      DWCi_Ndi_encodeBASE64 (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int DWCi_Ndi_encodeBASE64(char *encstr, char *srcbin, int length)
{
    unsigned char c[3];
    unsigned char base2;
    unsigned char base3;
    unsigned char base1;
    unsigned char base0;
    int n;
    int len = 0;
    n = getNchar(c, srcbin, length > 3 ? 3 : length);
    while (n > 0) {
        if (length < 3)
            c[2] = 0;
        if (length < 2)
            c[1] = 0;
        base1 = (unsigned char)(c[0] >> 2);
        base0 = ((c[0] << 4) | (c[1] >> 4)) & 0x3f;
        base2 = ((c[1] << 2) | (c[2] >> 6)) & 0x3f;
        base3 = c[2] & 0x3f;
        encstr[0] = sDwciNdAbcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz[base1];
        encstr[1] = sDwciNdAbcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz[base0];
        encstr[2] = n > 1 ? sDwciNdAbcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz[base2] : '*';
        encstr[3] = n > 2 ? sDwciNdAbcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz[base3] : '*';
        srcbin += n;
        encstr += 4;
        len += 4;
        length -= n;
        if (length == 0)
            break;
        n = getNchar(c, srcbin, length > 3 ? 3 : length);
    }
    *encstr = 0;
    return len;
}

/*
 * sdk:      DWCi_Ndi_decodeBASE64 (libdwcnd.TWL.HYB.a dwci_nd.o)
 */
int DWCi_Ndi_decodeBASE64(char *decbin, char *str, int length)
{
    unsigned char c[4];
    char dec[3];
    int d;
    int i;
    int n;
    int len;

    len = 0;
    n = getNchar(c, str, 4);
    d = 0;
    while (n > 0 && d >= 0) {
        dec[0] = 0;
        dec[1] = 0;
        dec[2] = 0;
        d = decodeChar(c[0]);
        if (d >= 0) {
            dec[0] = d << 2;
            d = decodeChar(c[1]);
            if (d >= 0) {
                dec[0] |= d >> 4;
                dec[1] = d << 4;
                d = decodeChar(c[2]);
                if (d >= 0) {
                    dec[1] |= d >> 2;
                    dec[2] = d << 6;
                    d = decodeChar(c[3]);
                    if (d >= 0)
                        dec[2] |= d;
                }
            }
        }
        for (i = 0; i < n - 1; i++)
            *decbin++ = dec[i];
        str += n;
        len += n - 1;
        length -= 4;
        if (length <= 0)
            break;
        n = getNchar(c, str, 4);
    }
    *decbin = 0;
    return len;
}

/*
 * sdk:      strAlloc (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
char *strAlloc(char *src)
{
    int n;
    char *dst;
    n = DWCi_Ndi_strlen(src);
    dst = (char *)gDwciNdStatics.alloc(n + 1, 4);
    if (dst) {
        DWCi_Ndi_memcpy(dst, src, n);
        dst[n] = 0;
    }
    return dst;
}

/*
 * sdk:      DWCi_NdStartup (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * Copies the credentials and callbacks into the module statics, encodes the game code,
 * password, MAC address and AP information and starts the HTTP callback machinery.
 */
int DWCi_NdStartup(NdAlloc alloc, NdFree free, char *url, char *token, char *gameCode,
                  char *password, DWCNdCallback callback)
{
    int len;

    gDwciNdStatics.alloc = alloc;
    gDwciNdStatics.free = free;
    gDwciNdStatics.callback = callback;
    gDwciNdStatics.attr1 = 0;
    gDwciNdStatics.attr2 = 0;
    gDwciNdStatics.attr3 = 0;
    gDwciNdStatics.apinfo = 0;
    gDwciNdStatics.handle = 0;
    gDwciNdStatics.token = 0;
    gDwciNdStatics.url = 0;

    DWCi_Ndi_getMacAddress(gDwciNdMacAddressEncoded);
    DWCi_Ndi_getUserAgent(gDwciNdUserAgent);

    gDwciNdStatics.url = strAlloc(url);
    if (gDwciNdStatics.url == 0)
        goto fail;
    gDwciNdStatics.token = strAlloc(token);
    if (gDwciNdStatics.token == 0)
        goto fail;

    len = DWCi_Ndi_encodeBASE64(gDwciNdGameCodeEncoded, gameCode, 4);
    gDwciNdGameCodeEncoded[len] = 0;
    len = DWCi_Ndi_encodeBASE64(gDwciNdPasswordEncoded, password, 16);
    gDwciNdPasswordEncoded[len] = 0;

    if (DWCi_Ndi_initHttpCallback() && DWCi_Ndi_initLockGlobal()) {
        if (NHTTP_Startup(alloc, free, 17) != -1) {
            gDwciNdStatics.apinfo = DWCi_Ndi_getApInfo(gDwciNdApInfoEncoded);
            gDwciNdStatics.initialized = 1;
            return 1;
        }
        DWCi_Ndi_freeLockGlobal();
    }
    gDwciNdStatics.free(gDwciNdStatics.token);
    gDwciNdStatics.free(gDwciNdStatics.url);
    DWCi_NdSetError(8, 0);
    return 0;

fail:
    if (gDwciNdStatics.token != 0)
        gDwciNdStatics.free(gDwciNdStatics.token);
    if (gDwciNdStatics.url != 0)
        gDwciNdStatics.free(gDwciNdStatics.url);
    DWCi_NdSetError(1, 0);
    return 0;
}

void nhttpCleanupCallback(void)
{
    DWCi_Ndi_freeAttr();
    DWCi_Ndi_freeLockGlobal();
    DWCi_Ndi_freeHttpCallback();
    gDwciNdStatics.free(gDwciNdStatics.token);
    gDwciNdStatics.free(gDwciNdStatics.url);
    gDwciNdStatics.cleanup();
}

void DWCi_NdCleanupAsync(void (*callback)(void))
{
    gDwciNdStatics.initialized = 0;
    gDwciNdStatics.cleanup = callback;
    DWCi_NdCleanupConnectionHandle(gDwciNdStatics.handle);
    NHTTP_CleanupAsync(nhttpCleanupCallback);
}

/*
 * sdk:      DWCi_NdCleanupConnectionHandle (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int DWCi_NdCleanupConnectionHandle(void *volatile handle)
{
    int result = 1;
    DWCi_Ndi_lockGlobal();
    if (handle) {
        NHTTP_GetConnectionStatus(handle);
        if (NHTTP_DeleteConnection(handle) != 0)
            result = 0;
        else
            handle = 0;
    }
    DWCi_Ndi_unlockGlobal();
    return result;
}

/*
 * sdk:      DWCi_NdSetError (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
void DWCi_NdSetError(int err, int serverError)
{
    switch (err) {
    case 1:
        DWCi_SetError(9, -31001);
        break;
    case 3:
        DWCi_SetError(14, -31020);
        break;
    case 4:
        DWCi_SetError(13, -31040);
        break;
    case 7:
        DWCi_SetError(13, -31000 - serverError);
        break;
    case 5:
        DWCi_SetError(13, -31040);
        break;
    case 8:
        DWCi_SetError(9, -31009);
        break;
    case 2:
        DWCi_SetError(13, -31010);
        break;
    case 0:
    case 6:
        break;
    default:
        DWCi_SetError(9, -31009);
        break;
    }
}

int DWCi_NdCancelAsync(void)
{
    unsigned long received;
    unsigned long contentlen;
    void *id;
    int rc;
    if (gDwciNdStatics.initialized == 0)
        return 0;
    rc = 0;
    received = 0;
    contentlen = 0;
    DWC_NdGetProgress(&received, &contentlen);
    if (received == contentlen)
        return rc;
    if (DWCi_Ndi_prepareHttpCallback() == 0) {
        DWCi_Ndi_lockGlobal();
        id = gDwciNdStatics.handle;
        DWCi_Ndi_unlockGlobal();
        if (NHTTP_CancelConnection(id) == 0)
            rc = 1;
        return rc;
    }
    DWCi_Ndi_unprepareHttpCallback();
    return rc;
}

/*
 * sdk:      DWCi_Ndi_getApInfo (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int DWCi_Ndi_getApInfo(char *apinfo)
{
    NdApString strAp = sDwciNdEmptyMacAddress;
    if (DWC_GetApInfo(&gDwciNdApInfo)) {
        if (gDwciNdApInfo.type >= 0 && gDwciNdApInfo.type < 10)
            strAp.b[1] = gDwciNdApInfo.type + '0';
        else if (gDwciNdApInfo.type >= 10 && gDwciNdApInfo.type < 100)
            DWCi_Ndi_intToStr(strAp.b, gDwciNdApInfo.type);
        if (gDwciNdApInfo.type == 4 || gDwciNdApInfo.type == 8) {
            if (gDwciNdApInfo.idx >= 0 && gDwciNdApInfo.idx < 10)
                strAp.b[3] = gDwciNdApInfo.idx + '0';
            DWCi_Ndi_memcpy(&strAp.b[4], gDwciNdApInfo.bssid, 9);
        }
        DWCi_Ndi_encodeBASE64(apinfo, strAp.b, 13);
        return 1;
    }
    return 0;
}

/*
 * sdk:      DWCi_Ndi_getDSdesc (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int DWCi_Ndi_getDSdesc(char *gamecode, char *userid)
{
    NdWiFiInfo wifiinfo;
    char strId[13];
    DWCi_Ndi_memclr(&wifiinfo, 20);
    DWCi_BM_GetWiFiInfo(&wifiinfo);
    if (wifiinfo.macid == 0)
        return 0;
    if (DWCi_Ndi_intToStrFigure(strId, wifiinfo.macid, 13) < 0)
        return 0;
    DWCi_Ndi_encodeBASE64(userid, strId, 13);
    DWCi_Ndi_encodeBASE64(gamecode, ROM_HEADER_GAME_CODE, 4);
    return 1;
}

/*
 * Writes the HTTP user agent string "Nitro WiFi SDK/5.3" into a 0x21 byte buffer.
 */
void DWCi_Ndi_getUserAgent(char *buffer)
{
    OS_SNPrintf(buffer, 0x21, sDwciNdUserAgentFormat, 5, 3);
}

int req_callback(void *res, int event, void *arg)
{
    tagDWCi_Ndi_HTTPREQ *hrq;
    int reason;
    void (*callback)(int, int, int);
    void *threadEvent;
    int httpStatus;
    int serverError;
    int result;
    unsigned long bodyBufSize;
    char *strHttpStatus;
    int n;
    char *v;
    int bgn;
    int len;
    int pos;
    char outstr[4];
    int isCode;

    serverError = -1;
    hrq = (tagDWCi_Ndi_HTTPREQ *)NHTTP_GetUserParam(res);
    reason = hrq->reason;
    callback = (void (*)(int, int, int))hrq->callback;
    threadEvent = hrq->threadEvent;
    switch (event) {
    case 4:
        if (NHTTP_GetConnectionError(res) == 8) {
            result = 6;
        } else if (NHTTP_GetHeaderField(res, sDwciNdHttpstatuscode, &strHttpStatus) != 3) {
            result = 3;
        } else {
            httpStatus = DWCi_Ndi_strToInt(strHttpStatus, 3);
            if (httpStatus == 0x12e) {
                isCode = 0;
                n = NHTTP_GetBodyBuffer(res, &v, &bodyBufSize);
                if (n < 0) {
                    result = 3;
                } else {
                    pos = 0;
                    while (pos < n) {
                        bgn = pos;
                        while (v[pos] != '=' && pos < n)
                            pos++;
                        len = pos - bgn;
                        pos++;
                        if (len == 8)
                            isCode = DWCi_Ndi_strncmp(v + bgn, sDwciNdReturncd, 8) == 0;
                        bgn = pos;
                        while (v[pos] != '&' && v[pos] != '\r' && v[pos] != '\0' && pos < n)
                            pos++;
                        len = pos - bgn;
                        pos++;
                        if (isCode) {
                            if (len == 4) {
                                len = DWCi_Ndi_decodeBASE64(outstr, v + bgn, len);
                                outstr[len] = 0;
                                serverError = DWCi_Ndi_strToInt(outstr, len);
                            }
                            break;
                        }
                    }
                    if (serverError < 0)
                        result = 3;
                    else
                        result = 7;
                }
            } else if (httpStatus <= 0 || httpStatus != 0xc8) {
                result = 3;
            } else {
                switch (reason) {
                case 1:
                    result = DWCi_Ndi_response_count(res, hrq) ? 0 : 3;
                    break;
                case 2:
                    result = DWCi_Ndi_response_list(res, hrq) ? 0 : 3;
                    break;
                case 3:
                    result = DWCi_Ndi_response_contents(res, hrq) ? 0 : 3;
                    break;
                }
            }
        }
        freeHttpParam(hrq);
        DWCi_Ndi_unprepareHttpCallback();
        if (callback != 0)
            callback(reason, result, serverError);
        if (threadEvent != 0)
            DWCi_Ndi_kickThread(threadEvent);
        break;
    case 2:
        isCode = 4;
        ((int *)arg)[2] = 0;
        DWCi_NdSetError(isCode, serverError);
        if (callback != 0)
            callback(reason, isCode, serverError);
        break;
    case 3:
        break;
    }
    return 0;
}

/*
 * sdk:      freeHttpParam (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
void freeHttpParam(tagDWCi_Ndi_HTTPREQ *hrq)
{
    if (hrq == 0)
        return;
    switch (hrq->reason) {
    case 1:
        break;
    case 2:
        if (hrq->param.list.strNum) {
            FREE(hrq->param.list.strNum);
            hrq->param.list.strNum = 0;
        }
        if (hrq->param.list.strOffset) {
            FREE(hrq->param.list.strOffset);
            hrq->param.list.strOffset = 0;
        }
        FREE(hrq->param.list.pBuf);
        hrq->param.list.pBuf = 0;
        break;
    case 3:
        FREE(hrq->param.getfile.encName);
        hrq->param.getfile.encName = 0;
        break;
    }
    FREE(hrq);
}

/*
 * Aborts a request that failed during setup: releases its connection, the callback guard
 * and the request context.
 */
void freeHttp(tagDWCi_Ndi_HTTPREQ *hrq, void *req)
{
    DWCi_NdCleanupConnectionHandle(req);
    DWCi_Ndi_unprepareHttpCallback();
    freeHttpParam(hrq);
}

static int setupHttp(tagDWCi_Ndi_HTTPREQ **phrq, void **preq, char *strAction, char *recvbuf, unsigned int recvbufLen, char *opt)
{
    char strTemp[256];
    int n;
    tagDWCi_Ndi_HTTPREQ *hrq;
    void *req;

    if (DWCi_Ndi_getDSdesc(gDwciNdDsGameCodeEncoded, gDwciNdUserIdEncoded) == 0) {
        DWCi_NdSetError(8, 0);
        return 0;
    }
    hrq = (tagDWCi_Ndi_HTTPREQ *)gDwciNdStatics.alloc(0x20, 4);
    if (hrq == 0) {
        DWCi_NdSetError(1, 0);
        return 0;
    }
    hrq->callback = gDwciNdStatics.callback;
    hrq->threadEvent = 0;
    if (DWCi_Ndi_prepareHttpCallback() == 0) {
        freeHttpParam(hrq);
        DWCi_NdSetError(2, 0);
        return 0;
    }
    if (DWCi_NdCleanupConnectionHandle(gDwciNdStatics.handle) == 0)
        return 0;
    req = NHTTP_CreateConnection(gDwciNdStatics.url, 1, recvbuf, recvbufLen, req_callback, hrq);
    if (req == 0) {
        DWCi_Ndi_unprepareHttpCallback();
        freeHttpParam(hrq);
        DWCi_NdSetError(3, 0);
        return 0;
    }
    *phrq = hrq;
    *preq = req;
    if (NHTTP_SetRootCA(req, sDwciNdRootCa, 1) == -1)
        goto fail;
    if (NHTTP_SetVerifyOption(req, 0) == -1)
        goto fail;
    if (NHTTP_AddHeaderField(req, sDwciNdUserAgent, gDwciNdUserAgent) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, sDwciNdGamecd, gDwciNdGameCodeEncoded) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, sDwciNdRhgamecd, gDwciNdDsGameCodeEncoded) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, sDwciNdPasswd, gDwciNdPasswordEncoded) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, sDwciNdToken, gDwciNdStatics.token) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, sDwciNdUserid, gDwciNdUserIdEncoded) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, sDwciNdMacadr, gDwciNdMacAddressEncoded) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, sDwciNdAction, strAction) == -1)
        goto fail;
    if (gDwciNdStatics.attr1 != 0 && NHTTP_AddPostDataAscii(req, sDwciNdAttr, gDwciNdStatics.attr1) == -1)
        goto fail;
    if (gDwciNdStatics.attr2 != 0 && NHTTP_AddPostDataAscii(req, sDwciNdAttr2, gDwciNdStatics.attr2) == -1)
        goto fail;
    if (gDwciNdStatics.attr3 != 0 && NHTTP_AddPostDataAscii(req, sDwciNdAttr3, gDwciNdStatics.attr3) == -1)
        goto fail;
    if (gDwciNdStatics.apinfo != 0 && NHTTP_AddPostDataAscii(req, sDwciNdApinfo, gDwciNdApInfoEncoded) == -1)
        goto fail;
    if (opt != 0) {
        n = DWCi_Ndi_strlen(opt);
        if (n > 0x40) {
            DWCi_NdSetError(5, 0);
            freeHttp(hrq, req);
            return 0;
        }
        DWCi_Ndi_memclr(gDwciNdOptionEncoded, 0x59);
        DWCi_Ndi_encodeBASE64(gDwciNdOptionEncoded, opt, n);
        if (NHTTP_AddPostDataAscii(req, sDwciNdOptionallogdata, gDwciNdOptionEncoded) == -1)
            goto fail;
    }
    DWCi_Ndi_decodeBASE64(strTemp, gDwciNdGameCodeEncoded, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, gDwciNdDsGameCodeEncoded, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, gDwciNdPasswordEncoded, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, gDwciNdStatics.token, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, gDwciNdUserIdEncoded, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, gDwciNdMacAddressEncoded, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, strAction, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, gDwciNdApInfoEncoded, 0x80);
    if (gDwciNdStatics.attr1 != 0)
        DWCi_Ndi_decodeBASE64(strTemp, gDwciNdStatics.attr1, 0x80);
    if (gDwciNdStatics.attr2 != 0)
        DWCi_Ndi_decodeBASE64(strTemp, gDwciNdStatics.attr2, 0x80);
    if (gDwciNdStatics.attr3 != 0)
        DWCi_Ndi_decodeBASE64(strTemp, gDwciNdStatics.attr3, 0x80);
    if (opt != 0)
        DWCi_Ndi_decodeBASE64(strTemp, gDwciNdOptionEncoded, 0x80);
    return 1;
fail:
    freeHttp(hrq, req);
    DWCi_NdSetError(1, 0);
    return 0;
}

/*
 * sdk:      runHttp (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int runHttp(tagDWCi_Ndi_HTTPREQ *hrq, void *req)
{
    int err;
    DWCi_Ndi_lockGlobal();
    err = NHTTP_StartConnection(req);
    if (err) {
        req = 0;
        DWCi_NdSetError(3, (int)req);
        DWCi_Ndi_unlockGlobal();
        return (int)req;
    }
    gDwciNdStatics.handle = req;
    DWCi_Ndi_unlockGlobal();
    return 1;
}

int DWCi_NdGetFileListAsync(DWCNdFileInfo *filelist, int offset, int num)
{
    int lenBuf;
    char *pBuf;
    char *strOffset;
    char *strNum;
    int lenNum;
    int lenOffset;
    tagDWCi_Ndi_HTTPREQ *hrq;
    void *req;
    char strBuf[12];

    lenBuf = num << 8;
    if (lenBuf < 0x80)
        lenBuf = 0x80;
    pBuf = gDwciNdStatics.alloc(lenBuf, 4);
    if (pBuf == 0) {
        DWCi_NdSetError(1, 0);
        return 0;
    }
    lenOffset = DWCi_Ndi_intToStr(strBuf, offset);
    strOffset = gDwciNdStatics.alloc(DWCi_Ndi_getEncodeLenBASE64(lenOffset) + 1, 4);
    if (strOffset == 0) {
        gDwciNdStatics.free(pBuf);
        DWCi_NdSetError(1, 0);
        return 0;
    }
    strOffset[DWCi_Ndi_encodeBASE64(strOffset, strBuf, lenOffset)] = 0;
    lenNum = DWCi_Ndi_intToStr(strBuf, num);
    strNum = gDwciNdStatics.alloc(DWCi_Ndi_getEncodeLenBASE64(lenNum) + 1, 4);
    if (strNum == 0) {
        gDwciNdStatics.free(strOffset);
        gDwciNdStatics.free(pBuf);
        DWCi_NdSetError(1, 0);
        return 0;
    }
    strNum[DWCi_Ndi_encodeBASE64(strNum, strBuf, lenNum)] = 0;
    if (!setupHttp(&hrq, &req, DWCiNd_action_list, pBuf, lenBuf, 0)) {
        gDwciNdStatics.free(strNum);
        gDwciNdStatics.free(strOffset);
        gDwciNdStatics.free(pBuf);
        return 0;
    }
    if (NHTTP_AddPostDataAscii(req, "offset", strOffset) == -1)
        goto error;
    if (NHTTP_AddPostDataAscii(req, "num", strNum) == -1)
        goto error;
    hrq->reason = 2;
    hrq->param.list.filelist = filelist;
    hrq->param.list.strOffset = strOffset;
    hrq->param.list.strNum = strNum;
    hrq->param.list.num = num;
    hrq->param.list.pBuf = pBuf;
    if (runHttp(hrq, req))
        return 1;
    gDwciNdStatics.free(strNum);
    gDwciNdStatics.free(strOffset);
    gDwciNdStatics.free(pBuf);
    return 0;

error:
    gDwciNdStatics.free(strNum);
    gDwciNdStatics.free(strOffset);
    gDwciNdStatics.free(pBuf);
    freeHttp(hrq, req);
    DWCi_NdSetError(1, 0);
    return 0;
}

int DWCi_NdGetFileAsync(DWCNdFileInfo *filelist, char *buf, unsigned int bufsize, char *opt)
{
    tagDWCi_Ndi_HTTPREQ *hrq;
    void *req;
    int fnameLen;
    char *encName;
    int n;

    if (bufsize < filelist->size) {
        DWCi_NdSetError(5, 0);
        return 0;
    }
    fnameLen = DWCi_Ndi_strlen(filelist->name);
    if (fnameLen > 32) {
        DWCi_NdSetError(5, 0);
        return 0;
    }
    if (fnameLen > 0)
        n = DWCi_Ndi_getEncodeLenBASE64(fnameLen);
    else
        n = 0;
    encName = gDwciNdStatics.alloc(n + 1, 4);
    if (encName == 0) {
        DWCi_NdSetError(1, 0);
        return 0;
    }
    if (!setupHttp(&hrq, &req, sDwciNdYUdgvudhm, buf, filelist->size, opt)) {
        gDwciNdStatics.free(encName);
        return 0;
    }
    if (n > 0) {
        encName[DWCi_Ndi_encodeBASE64(encName, filelist->name, fnameLen)] = 0;
        if (NHTTP_AddPostDataAscii(req, "contents", encName) == -1)
            goto error;
    }
    hrq->reason = 3;
    hrq->param.getfile.encName = encName;
    hrq->param.getfile.size = filelist->size;
    if (runHttp(hrq, req))
        return 1;
    gDwciNdStatics.free(encName);
    return 0;

error:
    freeHttp(hrq, req);
    gDwciNdStatics.free(encName);
    DWCi_NdSetError(1, 0);
    return 0;
}

/*
 * sdk:      DWCi_NdGetProgress (libdwcnd.TWL.HYB.a dwci_nd.o)
 */
int DWCi_NdGetProgress(unsigned long *received, unsigned long *contentlen)
{
    if (gDwciNdStatics.initialized == 0)
        return 0;
    return NHTTP_GetConnectionProgress(gDwciNdStatics.handle, received, contentlen) == 0;
}

/*
 * sdk:      DWCi_Ndi_response_count (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int DWCi_Ndi_response_count(void *res, tagDWCi_Ndi_HTTPREQ *hrq)
{
    char *body;
    int bodyLen;
    unsigned long bodyBufSize;
    bodyLen = NHTTP_GetBodyBuffer(res, &body, &bodyBufSize);
    if (bodyLen >= 0) {
        *hrq->param.getcount.count = DWCi_Ndi_strToInt(body, bodyLen);
        return *hrq->param.getcount.count >= 0;
    }
    return 0;
}

/*
 * sdk:      DWCi_Ndi_response_contents (libdwcnd.TWL.HYB.a dwci_nd.o)
 */
int DWCi_Ndi_response_contents(void *res, tagDWCi_Ndi_HTTPREQ *hrq)
{
    char *body;
    int bodyLen;
    unsigned long bodyBufSize;

    bodyLen = NHTTP_GetBodyBuffer(res, &body, &bodyBufSize);
    return bodyLen == hrq->param.getfile.size;
}

int DWCi_Ndi_response_list(void *res, tagDWCi_Ndi_HTTPREQ *hrq)
{
    char *body;
    int bodyLen;
    int n;
    int p;
    int state;
    int bgn;
    int isComplete;
    int detect0x0d;
    DWCNdFileInfo *pfi;
    int size;
    unsigned long bodyBufSize;
    char *contentlen;
    char tempBuf[104];
    int decordedLen;

    isComplete = 0;
    DWCi_Ndi_memclr(hrq->param.getfile.encName, hrq->param.getfile.size * 0xb0);
    if (NHTTP_GetHeaderField(res, sDwciNdContentLength, &contentlen) > 0) {
        if (contentlen[0] == '0' && contentlen[1] == 0)
            return 1;
    }
    bodyLen = NHTTP_GetBodyBuffer(res, &body, &bodyBufSize);
    if (bodyLen > 0) {
        p = 0;
        for (n = 0; n < hrq->param.getfile.size; n++) {
            if (p >= bodyLen) { isComplete = 1; break; }
            pfi = (DWCNdFileInfo *)(hrq->param.getfile.encName + n * 0xb0);
            state = 0;
            bgn = p;
            detect0x0d = 0;
            isComplete = 0;
            for (; p < bodyLen; p++) {
                if (body[p] == 0x0d) {
                    detect0x0d = 1;
                    continue;
                }
                if (detect0x0d) {
                    if (body[p] == 0x0a) {
                        if (state == 5) {
                            if (p - 1 - bgn > 8)
                                goto done;
                            decordedLen = DWCi_Ndi_strToInt(body + bgn, p - 1 - bgn);
                            if (decordedLen < 0)
                                goto done;
                            pfi->size = decordedLen;
                        }
                        p++;
                        isComplete = state >= 5;
                        break;
                    }
                } else if (body[p] == 0x09) {
                    switch (state) {
                    case 0:
                        if (p - bgn > sizeof(pfi->name) - 1)
                            goto done;
                        DWCi_Ndi_memcpy(pfi->name, body + bgn, p - bgn);
                        break;
                    case 1:
                        size = p - bgn;
                        decordedLen = DWCi_Ndi_getDecodeLenBASE64(size);
                        if (decordedLen > sizeof(pfi->explain))
                            goto done;
                        decordedLen = DWCi_Ndi_decodeBASE64(tempBuf, body + bgn, size);
                        if (decordedLen > sizeof(pfi->explain))
                            decordedLen = sizeof(pfi->explain);
                        DWCi_Ndi_memcpy(pfi->explain, tempBuf, decordedLen);
                        pfi->explain[50] = 0;
                        break;
                    case 2:
                        if (p - bgn > sizeof(pfi->param1) - 1)
                            goto done;
                        DWCi_Ndi_memcpy(pfi->param1, body + bgn, p - bgn);
                        break;
                    case 3:
                        if (p - bgn > sizeof(pfi->param2) - 1)
                            goto done;
                        DWCi_Ndi_memcpy(pfi->param2, body + bgn, p - bgn);
                        break;
                    case 4:
                        if (p - bgn > sizeof(pfi->param3) - 1)
                            goto done;
                        DWCi_Ndi_memcpy(pfi->param3, body + bgn, p - bgn);
                        break;
                    case 5:
                        if (p - bgn > 8)
                            goto done;
                        decordedLen = DWCi_Ndi_strToInt(body + bgn, p - bgn);
                        if (decordedLen < 0)
                            goto done;
                        pfi->size = decordedLen;
                        break;
                    }
                    state++;
                    bgn = p + 1;
                }
                detect0x0d = 0;
            }
        }
    }
done:
    return isComplete;
}

int DWCi_Ndi_initLockGlobal(void)
{
    OS_InitMutex((struct OSMutex *)gDwciNdGlobalMutex);
    return 1;
}

void DWCi_Ndi_freeLockGlobal(void)
{
}

/*
 * Tail call of OS_LockMutex on the 0x021D3C38 block.
 */
void DWCi_Ndi_lockGlobal(void)
{
    OS_LockMutex((struct OSMutex *)gDwciNdGlobalMutex);
}

void DWCi_Ndi_unlockGlobal(void)
{
    OS_UnlockMutex((struct OSMutex *)gDwciNdGlobalMutex);
}

int DWCi_Ndi_initHttpCallback(void)
{
    OS_InitMutex((struct OSMutex *)gDwciNdHttpMutex);
    gDwciNdStatics.httpCallbackBusy = 0;
    return 1;
}

void DWCi_Ndi_freeHttpCallback(void)
{
}

int DWCi_Ndi_prepareHttpCallback(void)
{
    int rc;
    OS_LockMutex((struct OSMutex *)gDwciNdHttpMutex);
    rc = (gDwciNdStatics.httpCallbackBusy == 0);
    if (rc)
        gDwciNdStatics.httpCallbackBusy = 1;
    OS_UnlockMutex((struct OSMutex *)gDwciNdHttpMutex);
    return rc;
}

void DWCi_Ndi_unprepareHttpCallback(void)
{
    OS_LockMutex((struct OSMutex *)gDwciNdHttpMutex);
    gDwciNdStatics.httpCallbackBusy = 0;
    OS_UnlockMutex((struct OSMutex *)gDwciNdHttpMutex);
}

/*
 * Wakes the thread waiting on `threadEvent`.
 */
void DWCi_Ndi_kickThread(void *threadEvent)
{
    OS_SendMessage(threadEvent, 0, 0);
}

/*
 * sdk:      DWCi_Ndi_getMacAddress (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
void DWCi_Ndi_getMacAddress(char *macaddr)
{
    unsigned char madr[6];
    char strmadr[12];
    int i;
    OS_GetMacAddress(madr);
    for (i = 0; i < 6; i++)
        DWCi_Ndi_hexToStrFigure(strmadr + i * 2, madr[i], 2);
    DWCi_Ndi_encodeBASE64(macaddr, strmadr, 12);
}

/*
 * strlen thunk.
 */
unsigned long DWCi_Ndi_strlen(char *str)
{
    return strlen((unsigned char *)str);
}

/*
 * strncmp thunk.
 */
int DWCi_Ndi_strncmp(char *str1, char *str2, unsigned long size)
{
    return strncmp((unsigned char *)str1, (unsigned char *)str2, size);
}

/*
 * Clears `size` bytes at `p`.
 */
void DWCi_Ndi_memclr(void *dst, int size)
{
    MI_CpuFill8(dst, 0, size);
}

/*
 * Copies `size` bytes.
 */
void DWCi_Ndi_memcpy(void *dst, void *src, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}

/*
 * Converts the first `len` characters of `s` to an integer.
 */
int DWCi_Ndi_strToInt(char *s, int len)
{
    return NHTTPi_strToInt(s, len);
}

/*
 * Writes the decimal text of `n` to `p`.
 */
int DWCi_Ndi_intToStr(char *buf, unsigned long value)
{
    return NHTTPi_intToStr(buf, value);
}
