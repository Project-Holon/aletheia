/*
 * file:     dwc_http.c
 * unit:     yes
 * function: DWC_Http_Create, DWC_Http_FinishHeader, DWC_Http_StartThread, DWC_Http_Abort, DWCi_Http_Yield, DWCi_Http_InitCpsSocket, DWCi_Http_Resolve, DWCi_Http_CheckHeaderReceived, DWCi_Http_Thread, DWC_Http_Destroy, DWCi_Http_WriteBasicHeader, DWC_Http_Add_HeaderItem, DWC_Http_Add_PostBase64Item, DWC_Http_Add_Body, DWCi_Http_CPSCallback, DWCi_Http_AllocBuffer, DWCi_Http_FreeBuffer, DWCi_Http_ReallocBuffer, DWCi_Http_SetHostinfo, DWCi_Http_AddResult, DWC_Http_ParseResult, DWC_Http_GetResult, DWC_Http_GetBase64DecodedResult, DWC_Http_GetRawResult, DWCi_Http_DestroyResult
 * address:  0x0217956C
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   DWCi_Http_AllocBuffer  0x0217A0D4  arm  ov009
 *   strstr  0x02094B20  arm
 *   strlen  0x0209477C  arm
 *   OS_SNPrintf  0x02084F80  arm
 *   gDwcHttpHeaderConnection     0x021A25C0  data
 *   gDwcHttpHeaderConnectionClose     0x021A25CC  data
 *   gDwcHttpHeaderTerminator     0x021A25D4  data
 *   gDwcHttpContentLengthFmt     0x021A25DC  data
 *   gDwcHttpHeaderContentLength     0x021A25E0  data
 *   OS_InitMutex           0x02086004  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_CreateThread        0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   gDwcHttpFlag             0x021ACE58  data
 *   OS_LockMutex    0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 *   OS_GetLowEntropyData   0x02088168  arm
 *   CPS_SslAddRandomSeed   0x02162248  arm
 *   OS_Sleep               0x02085a38  arm
 *   MI_CpuFill8      0x02082bcc  arm
 *   CPS_SocRegister  0x0215aa5c  arm
 *   CPS_Resolve  0x0215C910  arm
 *   atoi  0x020964E0  arm
 *   gDwcHttpContentLengthPrefix     0x021A25F0  data
 *   gDwcHttpCrLf     0x021A2604  data
 *   DWCi_Http_InitCpsSocket  0x0217988C  arm  ov009
 *   CPS_SocUse  0x0215AB10  arm  ov009
 *   CPS_SetRootCa  0x02160108  arm  ov009
 *   CPS_SetSsl  0x02162E94  arm  ov009
 *   CPS_SocBind  0x0215AAB0  arm  ov009
 *   CPS_TcpConnect  0x0215AC60  arm  ov009
 *   CPS_SocRelease  0x0215AB5C  arm  ov009
 *   CPS_SocUnRegister  0x0215AA70  arm  ov009
 *   CPS_SocWrite  0x0215B470  arm  ov009
 *   CPS_SocFlush  0x0215B584  arm  ov009
 *   DWCi_Http_Yield  0x02179814  arm  ov009
 *   OS_GetTick  0x020870D0  arm
 *   CPS_SocGetLength  0x0215B504  arm  ov009
 *   CPS_SocRead  0x0215AEB0  arm  ov009
 *   MI_CpuCopy8  0x02082D44  arm
 *   OS_LockMutex  0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 *   CPS_SocConsume  0x0215B064  arm  ov009
 *   _ll_udiv       0x0209C00C  arm
 *   CPS_TcpShutdown  0x0215AD00  arm  ov009
 *   CPS_TcpClose  0x0215AD3C  arm  ov009
 *   DWCi_Http_CPSCallback  0x0217A0C8  arm  ov009
 *   gDwcHttpRootCaList     0x021A2590  data ov009
 *   gCpsMyIp     0x021A82BC  data ov009
 *   DWCi_Http_DestroyResult  0x0217A808  arm  ov009
 *   DWCi_Http_FreeBuffer  0x0217A120  arm  ov009
 *   gDwcHttpPostFormat     0x021A2608  data
 *   gDwcHttpGetFormat     0x021A265C  data
 *   memmove  0x02092364  arm
 *   gDwcHttpHeaderFmt     0x021A267C  data
 *   DWC_Base64Encode  0x02059B40  arm
 *   gDwcHttpParamFmt     0x021A2688  data ov009
 *   gDwcHttpParamAmpFmt     0x021A268C  data ov009
 *   gDwcHttpValueFmt     0x021A2694  data
 *   MI_CpuCopy8  0x02082D44  arm
 *   strncpy  0x02094860  arm
 *   gDwcHttpSchemeHttp     0x021A2698  data ov009
 *   gDwcHttpSchemeHttps     0x021A26A0  data ov009
 *   gDwcHttpColon     0x021A26AC  data ov009
 *   gDwcHttpSlash     0x021A26B0  data ov009
 *   strcpy  0x02094798  arm
 *   strncmp  0x020949F4  arm
 *   gDwcHttpSpace     0x021A26B4  data ov009
 *   gDwcHttpLabelHttpResult     0x021A26B8  data ov009
 *   gDwcHttpStatusOk     0x021A26C4  data ov009
 *   gDwcHttpColonSpace     0x021A26C8  data ov009
 *   gDwcHttpEquals     0x021A26CC  data ov009
 *   gDwcHttpAmpersand     0x021A26D0  data ov009
 *   strcmp  0x020948e0  arm
 *   strlen              0x0209477c  arm
 *   DWC_Base64Decode    0x02059cbc  arm
 *   strcpy              0x02094798  arm
 */
#include "dwc_http_types.h"

#include "../sdk_dwc.h"

#include "../types.h"

#include "cps_ssl_types.h"

#include "../sdk_os.h"


typedef struct DWCHttpParseResult {
    DWCHttpLabelValue *entry;
    int len;
    int index;
} DWCHttpParseResult;

#include "../arm9/mi_memory.h"
#include "../arm9/os_printf.h"
#include "../arm9/os_mutex.h"
extern void OS_GetLowEntropyData(unsigned long *buffer);
#include "ssl.h"
#include "cps_network.h"
#include "../arm9/os_tick.h"
#include "../arm9/dwc_base64.h"
#include "../arm9/msl_string_str.h"
int DWC_Http_Create(DWCHttp *http, DWCHttpParam *param);
int DWC_Http_FinishHeader(DWCHttp *http);
void DWC_Http_StartThread(DWCHttp *http, unsigned long prio);
void DWC_Http_Abort(DWCHttp *http);
u32 DWCi_Http_Resolve(const DWCHttp *p);
int DWCi_Http_CheckHeaderReceived(DWCHttp *http);
void DWCi_Http_Thread(void *arg);
void DWC_Http_Destroy(DWCHttp *http);
int DWCi_Http_WriteBasicHeader(DWCHttp *http);
int DWC_Http_Add_HeaderItem(DWCHttp *http, char *label, char *data);
int DWC_Http_Add_PostBase64Item(DWCHttp *http, char *label, char *data, unsigned long data_len);
int DWC_Http_Add_Body(DWCHttp *http, char *data);
int DWCi_Http_CPSCallback(int result, CPSSslConnection *con, int level);
int DWCi_Http_ReallocBuffer(DWCHttp *http, DWCHttpBuffer *buf, int size);
int DWCi_Http_SetHostinfo(DWCHttp *http, char *url);
int DWCi_Http_AddResult(DWCHttp *http, DWCHttpParseResult *result, char *label, char *value);
int DWC_Http_ParseResult(DWCHttp *http, int noparsebody);
char *DWC_Http_GetResult(DWCHttp *http, char *label);
int DWC_Http_GetBase64DecodedResult(DWCHttp *http, char *label, char *buffer, unsigned long buffer_len);
int DWC_Http_GetRawResult(DWCHttp *http, char *label, char *buffer, int buffer_len);
static int DWCi_Http_AllocBuffer(DWCHttp *http, DWCHttpBuffer *buf, unsigned long size);
static void DWCi_Http_FreeBuffer(DWCHttp *http, DWCHttpBuffer *buf);
static void DWCi_Http_DestroyResult(DWCHttp *http, DWCHttpLabelValue *array_entry, int array_len);
extern char gDwcHttpHeaderConnection[];
extern char gDwcHttpHeaderConnectionClose[];
extern char gDwcHttpHeaderTerminator[];
extern char gDwcHttpContentLengthFmt[];
extern char gDwcHttpHeaderContentLength[];
extern int gDwcHttpFlag;
extern char gDwcHttpContentLengthPrefix[];
extern char gDwcHttpCrLf[];
extern SOCLCaInfo *gDwcHttpRootCaList[12];
extern unsigned long gCpsMyIp;
extern char gDwcHttpPostFormat[];
extern char gDwcHttpGetFormat[];
extern char gDwcHttpHeaderFmt[];
extern const char gDwcHttpParamFmt[];
extern const char gDwcHttpParamAmpFmt[];
extern char gDwcHttpValueFmt[];
extern const char gDwcHttpSchemeHttp[];
extern const char gDwcHttpSchemeHttps[];
extern const char gDwcHttpColon[];
extern const char gDwcHttpSlash[];
extern const char gDwcHttpSpace[];
extern char gDwcHttpLabelHttpResult[];
extern const char gDwcHttpStatusOk[];
extern const char gDwcHttpColonSpace[];
extern const char gDwcHttpEquals[];
extern const char gDwcHttpAmpersand[];

#include "../arm9/msl_strtod.h"
#include "../arm9/msl_string_mem.h"
/*
 * sdk:      DWC_Http_Create (libdwcauth.TWL.HYB.a dwc_http.o)
 */
int DWC_Http_Create(DWCHttp *http, DWCHttpParam *param)
{
    DWCAuthAlloc alloc = param->alloc;

    MI_CpuFill8(http, 0, sizeof(DWCHttp));
    http->content_len = -1;
    http->receivedbody_len = -1;
    http->param = *param;

    http->lowrecvbuf = alloc(0, 0xb68);
    if (http->lowrecvbuf == 0) {
        http->error = 1;
        return 1;
    }
    http->lowsendbuf = alloc(0, 0x5ea);
    if (http->lowsendbuf == 0) {
        http->error = 1;
        return 1;
    }
    if (!DWCi_Http_AllocBuffer(http, &http->rep, http->param.len_recvbuf)) {
        http->error = 1;
        return 1;
    }
    if (!DWCi_Http_SetHostinfo((DWCHttp *)((DWCHttp *)http), param->url)) {
        http->error = 1;
        return 1;
    }
    http->error = DWCi_Http_WriteBasicHeader(http);
    if (http->error == 0)
        http->initflag = 0xff;
    return http->error;
}

/*
 * sdk:      DWC_Http_FinishHeader (dwc_http.o)
 */
int DWC_Http_FinishHeader(DWCHttp *http)
{
    char str_contentlen[8];
    int contentlen;

    if (DWC_Http_Add_HeaderItem(http, gDwcHttpHeaderConnection, gDwcHttpHeaderConnectionClose)) {
        return 1;
    }
    contentlen = strlen((strstr((http->req.buffer), gDwcHttpHeaderTerminator) + 4));
    if (contentlen != 0) {
        OS_SNPrintf(str_contentlen, 7, gDwcHttpContentLengthFmt, contentlen);
        if (DWC_Http_Add_HeaderItem(http, gDwcHttpHeaderContentLength, str_contentlen)) {
            return 1;
        }
    }
    return 0;
}

/*
 * sdk:      DWC_Http_StartThread (dwc_http.o)
 */
void DWC_Http_StartThread(DWCHttp *http, unsigned long prio)
{
    http->abort = 0;
    OS_InitMutex(&http->mutex);
    OS_InitMutex(&http->content_len_mutex);
    if (http->param.ignoreca == 1) {
        gDwcHttpFlag = 1;
    } else {
        gDwcHttpFlag = 0;
    }
    if (http->thread.id != 0 && !OS_IsThreadTerminated(&http->thread)) {
        return;
    }
    OS_CreateThread(&http->thread, DWCi_Http_Thread, http, http->stack + 0x1000, 0x1000, prio);
    OS_WakeupThreadDirect(&http->thread);
}

void DWC_Http_Abort(DWCHttp *http)
{
    if (http->initflag != 0xff) {
        return;
    }
    OS_LockMutex(&http->mutex);
    http->abort = 1;
    OS_UnlockMutex(&http->mutex);
}

static int DWCi_Http_Yield(DWCHttp *http)
{
    if (http->ssl_enabled == 1) {
        OS_GetLowEntropyData(http->lowentropydata);
        CPS_SslAddRandomSeed((char *)http->lowentropydata, 0x20);
    }
    OS_LockMutex(&http->mutex);
    if (http->abort == 1) {
        OS_UnlockMutex(&http->mutex);
        return 0;
    }
    OS_UnlockMutex(&http->mutex);
    OS_Sleep(10);
    return 1;
}

static void DWCi_Http_InitCpsSocket(DWCHttp *http)
{
    MI_CpuFill8(&http->soc, 0, sizeof(http->soc));
    http->soc.rcvbuf.size = 0xb68;
    http->soc.rcvbuf.data = http->lowrecvbuf;
    http->soc.sndbuf.size = 0x5ea;
    http->soc.sndbuf.data = http->lowsendbuf;
    CPS_SocRegister(&http->soc);
}

/*
 * Tail call on the word at +0x1124 of the object.
 */
u32 DWCi_Http_Resolve(const DWCHttp *p)
{
    return CPS_Resolve(p->hostname);
}

/*
 * sdk:      DWCi_Http_CheckHeaderReceived (dwc_http.o)
 */
int DWCi_Http_CheckHeaderReceived(DWCHttp *http)
{
    char content_temp;
    char *content_end;
    char *content_length;
    char *endof_header;
    DWCHttpBuffer *rep;
    char *hdr;

    hdr = http->rep.buffer;
    rep = &http->rep;
    if (strstr(hdr, gDwcHttpHeaderTerminator) == 0) {
        return 0;
    }
    endof_header = (char *)(strstr(hdr, gDwcHttpHeaderTerminator) + 4);
    OS_LockMutex(&http->content_len_mutex);
    http->receivedbody_len = rep->write_index - endof_header;
    OS_UnlockMutex(&http->content_len_mutex);
    content_length = (char *)strstr(rep->buffer, gDwcHttpContentLengthPrefix);
    if (content_length == 0) {
        return 1;
    }
    content_length += strlen(gDwcHttpContentLengthPrefix);
    content_end = (char *)strstr(content_length, gDwcHttpCrLf);
    content_temp = *content_end;
    *content_end = 0;
    OS_LockMutex(&http->content_len_mutex);
    http->content_len = atoi(content_length);
    OS_UnlockMutex(&http->content_len_mutex);
    *content_end = content_temp;
    return 1;
}

/*
 * sdk:      DWCi_Http_Thread (libdwcauth.TWL.HYB.a dwc_http.o)
 */
void DWCi_Http_Thread(void *arg)
{
    DWCHttp *http = (DWCHttp *)arg;
    CPSSoc *soc = &http->soc;
    CPSSslConnection *con = &http->con;
    DWCHttpBuffer *rep = &http->rep;
    unsigned int copy_length;
    unsigned long ip;
    unsigned char *s;
    long len;
    unsigned long long lastactivetime;
    unsigned long long nowtime;
    int timeout;
    unsigned long tcpconnect;
    int header_received = 0;

    timeout = http->param.timeout;
    if (timeout <= 0)
        timeout = 60000;

    DWCi_Http_InitCpsSocket(http);
    ip = DWCi_Http_Resolve(http);
    if (ip == 0) {
        http->error = 2;
        return;
    }
    http->hostip = ip;
    CPS_SocUse();

    if (http->ssl_enabled == 1) {
        MI_CpuFill8(con, 0, sizeof(CPSSslConnection));
        con->f810 = DWCi_Http_CPSCallback;
        con->hostName = http->hostname;
        soc->con = con;
        CPS_SetRootCa(gDwcHttpRootCaList, 12);
        CPS_SetSsl(1);
    }

    CPS_SocBind(0, http->port, ip);
    tcpconnect = CPS_TcpConnect();
    if (tcpconnect != 0) {
        http->error = 3;
        CPS_SocRelease();
        CPS_SocUnRegister();
        return;
    }

    s = (unsigned char *)http->req.buffer;
    len = CPS_SocWrite(s, strlen((const char *)s));
    if (len <= 0) {
        http->error = 5;
        goto fail;
    }
    CPS_SocFlush();
    if (!DWCi_Http_Yield(http)) {
        http->error = 7;
        goto fail;
    }

    rep->write_index = rep->buffer;
    rep->buffer_tail = rep->buffer + rep->length;
    lastactivetime = OS_GetTick();

    for (;;) {
        if (gCpsMyIp == 0) {
            http->error = 5;
            goto fail;
        }
        len = CPS_SocGetLength();
        if (len < 0)
            break;
        if (len > 0) {
            lastactivetime = OS_GetTick();
            s = CPS_SocRead((unsigned long *)&len);
            if (s == 0)
                break;
            copy_length = (len < rep->buffer_tail - 1 - rep->write_index)
                              ? len : rep->buffer_tail - 1 - rep->write_index;
            MI_CpuCopy8(s, rep->write_index, copy_length);
            rep->write_index += copy_length;
            *rep->write_index = 0;
            if (header_received == 1) {
                OS_LockMutex(&http->content_len_mutex);
                http->receivedbody_len += copy_length;
                OS_UnlockMutex(&http->content_len_mutex);
            } else {
                header_received = DWCi_Http_CheckHeaderReceived(http);
            }
            if (len > copy_length) {
                CPS_SocConsume(len);
                break;
            }
            CPS_SocConsume(copy_length);
        }
        if (http->content_len >= 0 && http->receivedbody_len >= http->content_len)
            break;
        nowtime = OS_GetTick();
        if (((nowtime - lastactivetime) << 6) / 33514 > timeout) {
            http->error = 6;
            goto fail;
        }
        if (!DWCi_Http_Yield(http)) {
            http->error = 7;
            goto fail;
        }
    }

    CPS_TcpShutdown();
    CPS_TcpClose();
    CPS_SocRelease();
    CPS_SocUnRegister();
    http->error = 8;
    return;

fail:
    CPS_TcpShutdown();
    CPS_TcpClose();
    CPS_SocRelease();
    CPS_SocUnRegister();
}

/*
 * sdk:      DWC_Http_Destroy (dwc_http.o)
 */
void DWC_Http_Destroy(DWCHttp *http)
{
    DWCAuthFree free =
        http->param.free;

    if (http == 0) {
        return;
    }
    DWCi_Http_DestroyResult(http, http->labelvalue, 0x20);
    DWCi_Http_FreeBuffer(http, &http->rep);
    DWCi_Http_FreeBuffer(http, &http->req);
    if (http->lowrecvbuf != 0) {
        free(0, http->lowrecvbuf, 0);
        http->lowrecvbuf = 0;
    }
    if (http->lowsendbuf != 0) {
        free(0, http->lowsendbuf, 0);
        http->lowsendbuf = 0;
    }
    MI_CpuFill8(http, 0, sizeof(*http));
}

/*
 * sdk:      DWCi_Http_WriteBasicHeader (dwc_http.o)
 */
int DWCi_Http_WriteBasicHeader(DWCHttp *http)
{
    char *format;
    DWCHttpBuffer *req;
    int result_len;

    req = &http->req;
    if (http->param.action == 0) {
        format = gDwcHttpPostFormat;
    } else {
        format = gDwcHttpGetFormat;
    }
    result_len = strlen((http->hostname)) +
                 (strlen(format) - 4 + strlen((http->filepath)));
    if (DWCi_Http_AllocBuffer(http, &http->req, result_len + 0x400) != 1) {
        return 1;
    }
    result_len = OS_SNPrintf(req->write_index, req->length, format, http->filepath, http->hostname);
    req->write_index += result_len;
    return 0;
}

/*
 * sdk:      DWC_Http_Add_HeaderItem (dwc_http.o)
 */
int DWC_Http_Add_HeaderItem(DWCHttp *http, char *label, char *data)
{
    DWCHttpBuffer *temp_buffer;
    int buf_remain;
    int result_len;
    char temp;
    char *temp_index;

    temp_buffer = &http->req;
    result_len = strlen(data) +
                 (strlen(gDwcHttpHeaderFmt) - 4 + strlen(label));
    buf_remain = temp_buffer->buffer_tail - temp_buffer->write_index;
    if (result_len + 1 > buf_remain) {
        if (DWCi_Http_ReallocBuffer(http, temp_buffer, result_len - buf_remain + 1) == 0) {
            return 1;
        }
    }
    temp_index = (char *)strstr(temp_buffer->buffer, gDwcHttpHeaderTerminator) + 2;
    temp = *temp_index;
    memmove(temp_index + result_len, temp_index, strlen(temp_index) + 1);
    temp_index[OS_SNPrintf(temp_index, result_len + 1, gDwcHttpHeaderFmt, label, data)] = temp;
    temp_buffer->write_index += result_len;
    return 0;
}

/*
 * sdk:      DWC_Http_Add_PostBase64Item (libdwcauth.TWL.HYB.a dwc_http.o)
 */
int DWC_Http_Add_PostBase64Item(DWCHttp *http, char *label, char *data, unsigned long data_len)
{
    int result_len;
    int result_base64;
    int buf_remain;
    DWCHttpBuffer *temp_buffer;
    const char *format;

    temp_buffer = &http->req;
    if (http->num_postitem == 0)
        format = gDwcHttpParamFmt;
    else
        format = gDwcHttpParamAmpFmt;

    http->num_postitem++;

    result_base64 = DWC_Base64Encode(data, data_len, 0, 0);
    result_len = result_base64 + (strlen(format) - 2 + strlen(label));
    buf_remain = temp_buffer->buffer_tail - temp_buffer->write_index;
    if (result_len > buf_remain) {
        if (!DWCi_Http_ReallocBuffer(http, temp_buffer, result_len - buf_remain + 1))
            return 1;
        buf_remain = temp_buffer->buffer_tail - temp_buffer->write_index;
    }

    result_len = OS_SNPrintf(temp_buffer->write_index, buf_remain, format, label);
    temp_buffer->write_index += result_len;

    result_len = DWC_Base64Encode(data, data_len, temp_buffer->write_index,
                               temp_buffer->buffer_tail - temp_buffer->write_index - 1);
    if (result_len < 0)
        return 1;
    temp_buffer->write_index += result_base64;
    *temp_buffer->write_index = 0;
    return 0;
}

/*
 * sdk:      DWC_Http_Add_Body (dwc_http.o)
 */
int DWC_Http_Add_Body(DWCHttp *http, char *data)
{
    int result_len;
    int buf_remain;
    int temp;
    DWCHttpBuffer *temp_buffer;

    temp_buffer = &http->req;
    result_len = strlen(data);
    buf_remain = temp_buffer->buffer_tail - temp_buffer->write_index;
    if (result_len > buf_remain) {
        if (DWCi_Http_ReallocBuffer(http, temp_buffer, result_len - buf_remain + 1) == 0) {
            return 1;
        }
        buf_remain = temp_buffer->buffer_tail - temp_buffer->write_index;
    }
    temp = OS_SNPrintf(temp_buffer->write_index, buf_remain, gDwcHttpValueFmt, data);
    if (temp != result_len) {
        return 1;
    }
    temp_buffer->write_index += temp;
    return 0;
}

int DWCi_Http_CPSCallback(int result, CPSSslConnection *con, int level)
{
	if (result & 0x8000)
		result &= ~0x8000;
	return result;
}

static int DWCi_Http_AllocBuffer(DWCHttp *http, DWCHttpBuffer *buf, unsigned long size)
{
    DWCAuthAlloc alloc = http->param.alloc;
    void *p;

    if (size == 0)
        return 0;

    p = alloc(0, size);
    buf->buffer = p;
    if (p == 0)
        return 0;

    buf->write_index = p;
    buf->buffer_tail = (char *)p + size;
    buf->length = size;
    return 1;
}

static void DWCi_Http_FreeBuffer(DWCHttp *http, DWCHttpBuffer *buf)
{
    DWCAuthFree free = http->param.free;

    if (buf->buffer != 0) {
        free(0, buf->buffer, 0);
    }
    MI_CpuFill8(buf, 0, sizeof(*buf));
}

/*
 * sdk:      DWCi_Http_ReallocBuffer (dwc_http.o)
 */
int DWCi_Http_ReallocBuffer(DWCHttp *http, DWCHttpBuffer *buf, int size)
{
    DWCAuthAlloc alloc;
    DWCAuthFree free;
    char *newptr;

    alloc = http->param.alloc;
    free = http->param.free;
    if (size <= 0) {
        return 0;
    }
    newptr = alloc(0, buf->length + size);
    if (newptr == 0) {
        return 0;
    }
    MI_CpuCopy8(buf->buffer, newptr, buf->length);
    free(0, buf->buffer, 0);
    if (newptr == 0) {
        return 0;
    }
    buf->write_index = buf->write_index + (newptr - buf->buffer);
    buf->length = buf->length + size;
    buf->buffer = newptr;
    buf->buffer_tail = newptr + buf->length;
    return 1;
}

int DWCi_Http_SetHostinfo(DWCHttp *http, char *url)
{
    char *temp;
    char *portnum = 0;

    if ((unsigned long)strlen(url) >= 256)
        return 0;
    strncpy(http->url, url, 256);
    if ((unsigned long)strlen(url) != (unsigned long)strlen(http->url))
        return 0;

    if ((char *)strstr(http->url, gDwcHttpSchemeHttp) != 0) {
        http->hostname = &http->url[7];
        http->ssl_enabled = 0;
        http->port = 80;
    } else {
        temp = (char *)strstr(http->url, gDwcHttpSchemeHttps);
        if (temp == 0)
            return 0;
        http->hostname = temp + 8;
        http->ssl_enabled = 1;
        http->port = 443;
    }

    temp = (char *)strstr(http->hostname, gDwcHttpColon);
    if (temp != 0) {
        *temp = 0;
        portnum = temp + 1;
    }
    temp = (char *)strstr(http->hostname, gDwcHttpSlash);
    if (temp != 0) {
        *temp = 0;
        http->filepath = temp + 1;
    } else {
        http->filepath = 0;
    }
    if (portnum != 0)
        http->port = atoi(portnum);
    return 1;
}

/*
 * sdk:      DWCi_Http_AddResult (libdwcauth.TWL.HYB.a dwc_http.o)
 */
int DWCi_Http_AddResult(DWCHttp *http, DWCHttpParseResult *result, char *label, char *value)
{
    DWCAuthAlloc alloc = http->param.alloc;
    DWCAuthFree free = http->param.free;

    if (result->index > result->len)
        return 0;

    result->entry[result->index].label = alloc(0, strlen(label) + 1);
    if (result->entry[result->index].label != 0) {
        result->entry[result->index].value = alloc(0, strlen(value) + 1);
        if (result->entry[result->index].value != 0) {
            strcpy(result->entry[result->index].label, label);
            strcpy(result->entry[result->index].value, value);
            result->index++;
            return 1;
        }
    }

    if (result->entry[result->index].label != 0) {
        free(0, result->entry[result->index].label, 0);
        result->entry[result->index].label = 0;
    }
    if (result->entry[result->index].value != 0) {
        free(0, result->entry[result->index].value, 0);
        result->entry[result->index].value = 0;
    }
    return 0;
}

/*
 * sdk:      DWC_Http_ParseResult (libdwcauth.TWL.HYB.a dwc_http.o)
 */
int DWC_Http_ParseResult(DWCHttp *http, int noparsebody)
{
    char *buffer;
    char *p_char1;
    char *p_char2;
    char p_char1_temp;
    char p_char2_temp;
    char *httpbody_top;
    char *httpbody_end;
    char *index;
    char *value;
    char temp;
    DWCHttpParseResult parse_result;

    parse_result.entry = http->labelvalue;
    parse_result.len = 32;
    parse_result.index = 0;
    MI_CpuFill8(http->labelvalue, 0, sizeof(http->labelvalue));

    buffer = http->rep.buffer;
    httpbody_top = (char *)strstr(buffer, gDwcHttpHeaderTerminator);
    if (httpbody_top == 0)
        return 0;
    httpbody_end = httpbody_top + 4 + strlen((httpbody_top + 4));

    p_char1 = (char *)strstr(buffer, gDwcHttpSpace);
    if (p_char1 == 0)
        return 0;
    temp = p_char1[4];
    p_char1[4] = 0;
    if (DWCi_Http_AddResult((DWCHttp *)http, (DWCHttpParseResult *)&parse_result, gDwcHttpLabelHttpResult, p_char1 + 1) != 1) {
        p_char1[4] = temp;
        return 0;
    }
    p_char1[4] = temp;

    if (noparsebody == 1 || strncmp((p_char1 + 1), gDwcHttpStatusOk, 3) != 0)
        return 1;

    index = (char *)strstr((p_char1 + 5), gDwcHttpCrLf);
    if (index == 0)
        return 0;
    index += 2;

    while (*index != '\r' && *(index + 1) != '\n') {
        p_char1 = (char *)strstr(index, gDwcHttpColonSpace);
        if (p_char1 == 0)
            break;
        p_char1_temp = *p_char1;
        value = p_char1 + 2;
        *p_char1 = 0;
        p_char2 = (char *)strstr(value, gDwcHttpCrLf);
        if (p_char2 == 0) {
            *p_char1 = p_char1_temp;
            break;
        }
        p_char2_temp = *p_char2;
        *p_char2 = 0;
        if (DWCi_Http_AddResult((DWCHttp *)http, (DWCHttpParseResult *)&parse_result, index, value) != 1) {
            *p_char1 = p_char1_temp;
            *p_char2 = p_char2_temp;
            return 0;
        }
        index = value + strlen(value) + 2;
        *p_char1 = p_char1_temp;
        *p_char2 = p_char2_temp;
    }

    index = httpbody_top + 4;
    while (index < httpbody_end) {
        buffer = (char *)strstr(index, gDwcHttpEquals);
        if (buffer == 0)
            break;
        p_char1_temp = *buffer;
        p_char1 = buffer + 1;
        *buffer = 0;
        p_char2 = (char *)strstr(p_char1, gDwcHttpAmpersand);
        if (p_char2 == 0)
            p_char2 = (char *)strstr(p_char1, gDwcHttpCrLf);
        if (p_char2 != 0) {
            p_char2_temp = *p_char2;
            *p_char2 = 0;
        }
        if (DWCi_Http_AddResult((DWCHttp *)http, (DWCHttpParseResult *)&parse_result, index, p_char1) != 1) {
            *buffer = p_char1_temp;
            if (p_char2 != 0)
                *p_char2 = p_char2_temp;
            return 0;
        }
        index = p_char1 + strlen(p_char1) + 1;
        *buffer = p_char1_temp;
        if (p_char2 != 0)
            *p_char2 = p_char2_temp;
    }
    return 1;
}

char *DWC_Http_GetResult(DWCHttp *http, char *label)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (http->labelvalue[i].label == 0)
            break;
        if (strcmp(label, http->labelvalue[i].label) == 0)
            return http->labelvalue[i].value;
    }
    return 0;
}

int DWC_Http_GetBase64DecodedResult(DWCHttp *http, char *label, char *buffer, unsigned long buffer_len)
{
    char *value = DWC_Http_GetResult(http, label);
    int result_len;

    if (value == 0)
        return 0;

    result_len = DWC_Base64Decode(value, strlen(value), buffer, buffer_len);
    if (result_len == -1)
        return result_len;
    if (result_len < buffer_len)
        buffer[result_len] = 0;
    return result_len;
}

int DWC_Http_GetRawResult(DWCHttp *http, char *label, char *buffer, int buffer_len)
{
    char *value = DWC_Http_GetResult(http, label);
    int value_len;

    if (value == 0)
        return 0;

    value_len = strlen(value);
    if (value_len >= buffer_len)
        return 0;
    strcpy(buffer, value);
    return 1;
}

static void DWCi_Http_DestroyResult(DWCHttp *http, DWCHttpLabelValue *array_entry, int array_len)
{
    DWCAuthFree free = http->param.free;
    int i;

    for (i = 0; i < array_len; i++) {
        if (array_entry[i].label != 0) {
            free(0, array_entry[i].label, 0);
            array_entry[i].label = 0;
        }
        if (array_entry[i].value != 0) {
            free(0, array_entry[i].value, 0);
            array_entry[i].value = 0;
        }
    }
}
