/*
 * file:     unit_021BF520.c
 * unit:     yes
 * function: func_021BF520, func_021BF540, func_021BF558, func_021BF57C, func_021BF5B8, func_021BF5D8, func_021BF67C, func_021BF6C4, func_021BF6EC, func_021BF880, func_021BF8C0, func_021BFA08, func_021BFA70, func_021BFAF0, func_021BFB20
 * address:  0x021BF520
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
 *   func_021C2344  0x021C2344  arm  ov114
 *   func_021C2350  0x021C2350  arm  ov114
 *   g_021D3B20  0x021D3B20  data
 *   func_021C1FF8  0x021C1FF8  arm  ov114
 *   func_021C204C  0x021C204C  arm  ov114
 *   func_021BFB20  0x021BFB20  arm  ov114
 *   func_021C2270  0x021C2270  arm  ov114
 *   func_021BF8C0  0x021BF8C0  arm  ov114
 *   DWC_Free       0x0205A1B0  arm
 *   func_021BFA70  0x021BFA70  arm  ov114
 *   func_021BF6EC  0x021BF6EC  arm  ov114
 *   func_02059F54  0x02059F54  arm
 *   func_0205A16C  0x0205A16C  arm
 *   DWC_Alloc   0x0205A16C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_021C20A4  0x021C20A4  arm  ov114
 *   func_021C22EC  0x021C22EC  arm  ov114
 *   func_021C22A4  0x021C22A4  arm  ov114
 *   d_021D3B20    0x021D3B20  data  ov114  a4
 */
typedef unsigned int u32;

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

typedef struct ParamList {
    int count;
    DWCGHTTPParamEntry *head;
} ParamList;

extern int func_021C2344(int, void *);
extern int func_021C2350(void);
extern void func_021C1FF8(void);
extern void func_021C204C(void);
extern int func_02059F38(void);
extern void func_021C2270(void);
extern void func_021BFB20(void);
extern void DWC_Free(int name, void *ptr, int size);
extern void func_021C22A4(int request);
extern void func_021C22EC(int a, int b);
extern void *func_0205A16C(int name, unsigned long size);
extern void func_0205A1B0(int name, void *ptr, unsigned long size);
extern void func_02059F54(int error, int errorCode);
extern void *DWC_Alloc(int name, unsigned long size);
extern int func_021C20A4(char *url, char *headers, char *buffer, int bufferSize, void *post,
                         int throttle, int blocking, void *progressCallback, void *completedCallback, void *param);
int func_021BF520(int a);
int func_021BF540(void);
int func_021BF558(void);
int func_021BF57C(void);
int func_021BF5B8(void);
int func_021BF5D8(int request, int result, char *buffer, int bufferLen, void *param);
void func_021BF67C(int request, int state, char *buffer, int bufferLen, int bytesReceived, int totalSize, DWCGHTTPParamEntry *parameter);
void func_021BF6C4(char *url, int bufferlen, int buffer_clear, ProgressCb progressCallback, CompletedCb completedCallback, void *param);
int func_021BF6EC(char *url, int bufferlen, int buffer_clear, void **post, ProgressCb progressCallback, CompletedCb completedCallback, void *param);
void func_021BF880(int req);
int func_021BF8C0(int result);
DWCGHTTPParamEntry *func_021BFA08(DWCGHTTPParam *param);
void func_021BFA70(DWCGHTTPParamEntry *x);
DWCGHTTPParamEntry *func_021BFAF0(u32 key);
extern ParamList g_021D3B20;
extern ParamList d_021D3B20;

/*
 * Predicate: true when `a` is the sole entry of the 0x021CE544 table.
 */
int func_021BF520(int a)
{
    return func_021C2344(a, (void *)0x021CE544) == 1;
}



/*
 * Predicate: true when the census reports exactly one entry.
 */
int func_021BF540(void)
{
    return func_021C2350() == 1;
}



/*
 * Bumps the 0x021D3B20 generation counter and reports success.
 */
int func_021BF558(void)
{
    func_021C1FF8();
    g_021D3B20.count++;
    return 1;
}



/*
 * sdk:      DWC_ShutdownGHTTP (dwc_ghttp.o)
 */
int func_021BF57C(void)
{
    if (g_021D3B20.count <= 0) {
        return 1;
    }
    func_021C204C();
    if (--g_021D3B20.count == 0) {
        func_021BFB20();
    }
    return 1;
}



int func_021BF5B8(void)
{
    if (func_02059F38() != 0)
        return 0;
    func_021C2270();
    return 1;
}



/*
 * sdk:      GHTTPCompletedCallback (dwc_ghttp.o)
 */
int func_021BF5D8(int request, int result, char *buffer, int bufferLen, void *param)
{
    DWCGHTTPParamEntry *parameter;
    CompletedCb callback;
    int buffer_clear;

    parameter = param;
    callback = parameter->param.completedCallback;
    buffer_clear = parameter->param.buffer_clear;
    if (callback != 0) {
        if (result == 0) {
            callback(buffer, bufferLen, result, parameter->param.param);
        } else if (result == 0x12) {
            callback(0, 0, result, parameter->param.param);
        } else {
            func_021BF8C0(result);
            callback(0, 0, result, parameter->param.param);
        }
    }
    if (result != 0 || buffer_clear == 1) {
        if (parameter == 0 || parameter->buf == 0) {
            buffer_clear = 1;
        } else {
            DWC_Free(6, parameter->buf, 0);
        }
    }
    func_021BFA70(parameter);
    return buffer_clear != 0;
}



void func_021BF67C(int request, int state, char *buffer, int bufferLen, int bytesReceived, int totalSize, DWCGHTTPParamEntry *parameter)
{
    ProgressCb callback = parameter->param.progressCallback;

    if (callback == 0) {
        return;
    }
    callback(state, buffer, bufferLen, bytesReceived, totalSize, parameter->param.param);
}


/*
 * Forwards six arguments with a zero in the fourth slot.
 */
void func_021BF6C4(char *url, int bufferlen, int buffer_clear, ProgressCb progressCallback, CompletedCb completedCallback, void *param)
{
    func_021BF6EC(url, bufferlen, buffer_clear, 0, progressCallback, completedCallback, param);
}


/*
 * sdk:      DWCi_GHTTPGetEx (libdwcghttp.TWL.HYB.a(dwc_ghttp.o))
 */
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




/*
 * sdk:      DWC_CancelGHTTPRequest (dwc_ghttp.o)
 */
void func_021BF880(int req)
{
    DWCGHTTPParamEntry *entry;

    func_021C22A4(req);
    entry = func_021BFAF0(req);
    if (entry == 0) {
        return;
    }
    if (entry->buf != 0) {
        DWC_Free(6, entry->buf, 0);
    }
    func_021BFA70(entry);
}




/*
 * sdk:      DWCi_HandleGHTTPError (libdwcghttp.TWL.HYB.a(dwc_ghttp.o))
 */
int func_021BF8C0(int result)
{
    int errorCode;
    int dwcError;

    dwcError = 7;
    errorCode = -98000;
    if (result == 0)
        return 0;
    switch (result) {
    case -7:
        errorCode += -800;
        break;
    case -6:
        errorCode += -810;
        break;
    case -5:
        errorCode += -840;
        break;
    case -4:
    case -3:
    case -2:
        errorCode += -820;
        break;
    case -1:
        errorCode += -830;
        break;
    case 1:
    case 20:
        dwcError = 9;
        errorCode += -1;
        break;
    case 2:
        errorCode += -840;
        break;
    case 3:
        errorCode += -850;
        break;
    case 4:
        errorCode += -30;
        break;
    case 5:
        errorCode += -50;
        break;
    case 6:
    case 11:
    case 12:
        errorCode += -20;
        break;
    case 7:
        errorCode += -860;
        break;
    case 8:
    case 9:
    case 10:
        errorCode += -870;
        break;
    case 13:
    case 14:
        errorCode += -880;
        break;
    case 15:
        errorCode += -890;
        break;
    case 16:
        errorCode += -900;
        break;
    case 17:
        errorCode += -910;
        break;
    }
    func_02059F54(dwcError, errorCode);
    return result;
}



DWCGHTTPParamEntry *func_021BFA08(DWCGHTTPParam *param)
{
    DWCGHTTPParamEntry *entry;

    entry = DWC_Alloc(6, 0x20);
    if (entry == 0) {
        return 0;
    }
    entry->param = *param;
    entry->nextentry = 0;
    entry->buf = 0;
    if (g_021D3B20.head == 0) {
        g_021D3B20.head = entry;
        return entry;
    }
    entry->nextentry = g_021D3B20.head;
    g_021D3B20.head = entry;
    return entry;
}



/*
 * Singly linked list removal.  The if/else with a lone `p = q` arm is
 * deliberate: it makes armcc if-convert that assignment to `movne` and
 * branch over the found arm, which is the only shape that reproduces the
 * original loop.  See
 * docs/idioms/a-lone-move-arm-if-converts-to-movne.md
 */
void func_021BFA70(DWCGHTTPParamEntry *x)
{
    DWCGHTTPParamEntry *p = d_021D3B20.head;
    DWCGHTTPParamEntry *q;
    if (p == 0)
        return;
    if (p == x) {
        DWCGHTTPParamEntry *nx = p->nextentry;
        func_0205A1B0(6, p, 0);
        d_021D3B20.head = nx;
        return;
    }
    q = p->nextentry;
    if (q == 0)
        return;
    for (;;) {
        if (q != x) {
            p = q;
        } else {
            DWCGHTTPParamEntry *n = p->nextentry;
            p->nextentry = n->nextentry;
            func_0205A1B0(6, n, 0);
            return;
        }
        q = q->nextentry;
        if (q == 0)
            return;
    }
}



/*
 * Linear search of the 0x021d3b20 list for the node whose +0x18 key matches;
 * NULL when absent.  The compound condition and the named base pointer are
 * what leave the single shared test block at 0x021bfb00 with the entry
 * jumping to it; the base is not folded into the pool word.
 */
DWCGHTTPParamEntry *func_021BFAF0(u32 key)
{
    ParamList *base = (ParamList *)0x021d3b20;
    DWCGHTTPParamEntry *p = base->head;

    while (p != 0 && (u32)p->req != key)
        p = p->nextentry;
    return p;
}



/*
 * sdk:      DWCi_RemoveAllDWCGHTTPParamEntry (dwc_ghttp.o)
 */
void func_021BFB20(void)
{
    DWCGHTTPParamEntry *cursor;
    DWCGHTTPParamEntry *target;

    cursor = g_021D3B20.head;
    while (cursor != 0) {
        target = cursor;
        cursor = cursor->nextentry;
        if (target->buf != 0) {
            DWC_Free(6, target->buf, 0);
        }
        DWC_Free(6, target, 0);
    }
    g_021D3B20.head = 0;
}
