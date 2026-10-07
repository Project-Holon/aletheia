/*
 * file:     unit_021C5E78_p06.c
 * unit:     yes
 * function: func_021C68BC, func_021C6B44
 * address:  0x021C68BC
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
 *   NHTTP_GetUserParam              0x021BF444  arm  ov114
 *   NHTTP_GetConnectionError        0x021BF488  arm  ov114
 *   NHTTP_GetHeaderField            0x021BE7FC  arm  ov114
 *   DWCi_Ndi_strToInt               0x021C7A5C  arm  ov114
 *   NHTTP_GetBodyBuffer             0x021BF3E4  arm  ov114
 *   DWCi_Ndi_strncmp                0x021C7A24  arm  ov114
 *   DWCi_Ndi_decodeBASE64           0x021C61C0  arm  ov114
 *   DWCi_Ndi_response_count         0x021C75BC  arm  ov114
 *   DWCi_Ndi_response_list          0x021C7644  arm  ov114
 *   DWCi_Ndi_response_contents      0x021C7614  arm  ov114
 *   freeHttpParam                   0x021C6B44  arm  ov114
 *   DWCi_Ndi_unprepareHttpCallback  0x021C797C  arm  ov114
 *   DWCi_Ndi_kickThread             0x021C79AC  arm  ov114
 *   DWCi_NdSetError                 0x021C659C  arm  ov114
 *   g_021CF47C                      0x021CF47C  data  ov114
 *   g_021CF48C                      0x021CF48C  data  ov114
 *   g_021D3B9C  0x021D3B9C  data
 */
#define FREE(p) ((void (*)(void *))g_021D3B9C[5])(p)
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct tagDWCi_Ndi_HTTPREQ {
    int reason;
    void *callback;
    void *threadEvent;
    int pad[5];
} tagDWCi_Ndi_HTTPREQ;

extern void *NHTTP_GetUserParam(void *handle);
extern int NHTTP_GetConnectionError(void *handle);
extern int NHTTP_GetHeaderField(void *handle, char *label_p, char **value_pp);
extern int DWCi_Ndi_strToInt(char *p, int len);
extern int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p);
extern int DWCi_Ndi_strncmp(char *p1, char *p2, unsigned long size);
extern int DWCi_Ndi_decodeBASE64(char *decbin, char *str, int length);
extern int DWCi_Ndi_response_count(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
extern int DWCi_Ndi_response_list(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
extern int DWCi_Ndi_response_contents(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
extern void freeHttpParam(tagDWCi_Ndi_HTTPREQ *hrq);
extern void DWCi_Ndi_unprepareHttpCallback(void);
extern void DWCi_Ndi_kickThread(void *threadEvent);
extern void DWCi_NdSetError(int err, int servererror);
int req_callback(void *res, int event, void *arg);
void func_021C6B44(int *hrq);
extern char g_021CF47C[];
extern char g_021CF48C[];
extern int g_021D3B9C[];


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
        } else if (NHTTP_GetHeaderField(res, g_021CF47C, &strHttpStatus) != 3) {
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
                            isCode = DWCi_Ndi_strncmp(v + bgn, g_021CF48C, 8) == 0;
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
void func_021C6B44(int *hrq)
{
	if (hrq == 0)
		return;
	switch (hrq[0]) {
	case 1:
		break;
	case 2:
		if (hrq[7]) {
			FREE((void *)hrq[7]);
			hrq[7] = 0;
		}
		if (hrq[6]) {
			FREE((void *)hrq[6]);
			hrq[6] = 0;
		}
		FREE((void *)hrq[5]);
		hrq[5] = 0;
		break;
	case 3:
		FREE((void *)hrq[3]);
		hrq[3] = 0;
		break;
	}
	FREE(hrq);
}
