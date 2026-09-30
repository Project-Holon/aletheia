/*
 * function: req_callback
 * address:  0x021C68BC
 * packet:   pkt_ov114_021C68BC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  full body.  Frame, block layout and cold-block sinking now EXACT
 *           (single shared epilogue via `goto end;`; event==2 handler spelled
 *           as a `goto ev2;` to a block written after `done:`, so the image's
 *           cold placement is reproduced).  Compiled 648 == listing extent
 *           648, 398 concrete bytes differ, all the callee-saved rotation:
 *           image res=r8/event=sl/arg=r4/reason=r5/callback=r6/serverError=r7,
 *           ours res=r7/event=r6/arg=r5/reason=sl/callback=sb/serverError=r8,
 *           plus the split ldm {r5,r6} vs two ldr.  Tried DWARF declaration
 *           order both ways; allocation does not follow it (541/533).
 *           Idiom used: an-early-return-branching-to-a-shared-epilogue-is-a-goto.
 *
 * sdk:      req_callback (libdwcnd.TWL.HYB.a dwci_nd.o)
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
 */

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
extern char g_021CF47C[];
extern char g_021CF48C[];

int req_callback(void *res, int event, void *arg)
{
    int isCode;
    char outstr[4];
    int pos;
    int len;
    int bgn;
    char *v;
    int n;
    char *strHttpStatus;
    unsigned long bodyBufSize;
    int result;
    int serverError;
    int httpStatus;
    void *threadEvent;
    void (*callback)(int, int, int);
    int reason;
    tagDWCi_Ndi_HTTPREQ *hrq;

    serverError = -1;
    hrq = (tagDWCi_Ndi_HTTPREQ *)NHTTP_GetUserParam(res);
    reason = hrq->reason;
    callback = (void (*)(int, int, int))hrq->callback;
    threadEvent = hrq->threadEvent;
    if (event == 2)
        goto ev2;
    if (event != 4)
        goto end;
    if (NHTTP_GetConnectionError(res) == 8) {
        result = 6;
        goto done;
    }
    if (NHTTP_GetHeaderField(res, g_021CF47C, &strHttpStatus) != 3) {
        result = 3;
        goto done;
    }
    httpStatus = DWCi_Ndi_strToInt(strHttpStatus, 3);
    if (httpStatus == 0x12e) {
        pos = 0;
        n = NHTTP_GetBodyBuffer(res, &v, &bodyBufSize);
        if (n < 0) {
            result = 3;
            goto done;
        }
        result = 0;
        if (n > 0) {
            for (;;) {
                int matched;
                int bgn2;

                bgn = pos;
                while (pos < n && v[pos] != '=')
                    pos++;
                matched = 0;
                if (pos - bgn == 8)
                    matched = DWCi_Ndi_strncmp(v + bgn, g_021CF48C, 8) == 0;
                bgn2 = ++pos;
                while (pos < n && v[pos] != '&' && v[pos] != 0xd && v[pos] != 0)
                    pos++;
                len = pos - bgn2;
                pos++;
                if (matched) {
                    if (len != 4)
                        break;
                    outstr[DWCi_Ndi_decodeBASE64(outstr, v + bgn2, len)] = 0;
                    serverError = DWCi_Ndi_strToInt(outstr, len);
                    break;
                }
                if (pos >= n)
                    break;
            }
        }
        result = serverError < 0 ? 3 : 7;
    } else if (httpStatus > 0 && httpStatus == 0xc8) {
        switch (reason) {
        case 1:
            result = DWCi_Ndi_response_count(res, hrq);
            break;
        case 2:
            result = DWCi_Ndi_response_list(res, hrq);
            break;
        case 3:
            result = DWCi_Ndi_response_contents(res, hrq);
            break;
        }
        if (result != 0)
            result = 8;
    } else {
        result = 3;
    }

done:
    freeHttpParam(hrq);
    DWCi_Ndi_unprepareHttpCallback();
    if (callback != 0)
        callback(reason, result, serverError);
    if (threadEvent != 0)
        DWCi_Ndi_kickThread(threadEvent);
    goto end;

ev2:
    isCode = 4;
    ((int *)arg)[2] = 0;
    DWCi_NdSetError(4, serverError);
    if (callback != 0)
        callback(reason, isCode, serverError);

end:
    return 0;
}
