/*
 * function: func_021BF6EC
 * address:  0x021BF6EC
 * packet:   pkt_ov114_021BF6EC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GHTTPGetEx (libdwcghttp.TWL.HYB.a(dwc_ghttp.o))
 *
 * symbols:
 *   func_02059F38  0x02059F38  arm
 *   func_021BFA08  0x021BFA08  arm  ov114
 *   func_021BF8C0  0x021BF8C0  arm  ov114
 *   func_0205A16C  0x0205A16C  arm
 *   func_021BFA70  0x021BFA70  arm  ov114
 *   func_021C20A4  0x021C20A4  arm  ov114
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_021C22EC  0x021C22EC  arm  ov114
 *   func_021BF67C  0x021BF67C  arm  ov114
 *   func_021BF5D8  0x021BF5D8  arm  ov114
 */

typedef void (*ProgressCb)(int state, char *buf, int buflen, int received, int total, void *param);
typedef void (*CompletedCb)(char *buf, int buflen, int result, void *param);

typedef struct {
    void *param;
    CompletedCb completedCallback;
    ProgressCb progressCallback;
    void (*postCallback)(int, int, int, int, void *);
    int buffer_clear;
} DWCGHTTPParam;

typedef struct DWCGHTTPParamEntry {
    DWCGHTTPParam param;
    char *buf;
    int req;
    struct DWCGHTTPParamEntry *nextentry;
} DWCGHTTPParamEntry;

extern int func_02059F38(void);
extern DWCGHTTPParamEntry *func_021BFA08(DWCGHTTPParam *param);
extern int func_021BF8C0(int result);
extern void *func_0205A16C(int name, unsigned long size);
extern void func_021BFA70(DWCGHTTPParamEntry *entry);
extern int func_021C20A4(char *url, char *headers, char *buffer, int bufferSize, void *post,
                         int throttle, int blocking, void *progressCallback, void *completedCallback, void *param);
extern void func_0205A1B0(int name, void *ptr, unsigned long size);
extern void func_021C22EC(int request, unsigned int maxRecvTime);
extern void func_021BF67C();
extern int func_021BF5D8();

int func_021BF6EC(char *url, int bufferlen, int buffer_clear, void **post,
                  ProgressCb progressCallback, CompletedCb completedCallback, void *param)
{
    char *buffer = 0;
    int req;
    DWCGHTTPParamEntry *entry;
    DWCGHTTPParam parameter_instance;

    if (func_02059F38())
        return -1;
    parameter_instance.param = param;
    parameter_instance.completedCallback = completedCallback;
    parameter_instance.progressCallback = progressCallback;
    parameter_instance.buffer_clear = buffer_clear;
    entry = func_021BFA08(&parameter_instance);
    if (entry == 0) {
        func_021BF8C0(-5);
        completedCallback(0, 0, -5, param);
        return -5;
    }
    if (bufferlen > 0) {
        buffer = func_0205A16C(6, bufferlen);
        if (buffer == 0) {
            func_021BF8C0(-5);
            completedCallback(0, 0, -5, param);
            func_021BFA70(entry);
            return -5;
        }
        entry->buf = buffer;
    }
    req = func_021C20A4(url, 0, buffer, bufferlen, post == 0 ? 0 : *post, 0, 0,
                        progressCallback == 0 ? 0 : (void *)func_021BF67C, (void *)func_021BF5D8, entry);
    if (req < 0) {
        func_021BF8C0(req);
        completedCallback(0, 0, req, param);
        if (entry->buf != 0)
            func_0205A1B0(6, entry->buf, 0);
        func_021BFA70(entry);
    }
    entry->req = req;
    func_021C22EC(req, 1);
    return req;
}
