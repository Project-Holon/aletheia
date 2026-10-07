/*
 * file:     unit_021BF520_p01.c
 * unit:     yes
 * function: func_021BF520, func_021BF540, func_021BF558, func_021BF57C, func_021BF5B8, func_021BF5D8, func_021BF67C
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
 */
#include "../../matched/include/G_Init.h"

struct Node;
typedef unsigned char u8;

typedef unsigned int u32;

typedef void (*CompletedCallback)(char *buffer, int bufferLen, int result, void *param);

typedef struct Entry {
    void *param;
    CompletedCallback callback;
    int unk8;
    int unkc;
    int buffer_clear;
    void *data;
} Entry;

typedef void (*ProgressCallback)(int state, char *buffer, int bufferLen, int bytesReceived, int totalSize, void *param);

typedef struct {
    void *param;
    int unk4;
    ProgressCallback callback;
} Parameter;

extern int func_021C2344(int, void *);
extern int func_021C2350(void);
extern void func_021C1FF8(void);
extern void func_021C204C(void);
extern void func_021BFB20(void);
extern int func_02059F38(void);
extern void func_021C2270(void);
extern int func_021BF8C0(int result);
extern void DWC_Free(int name, void *ptr, int size);
extern void func_021BFA70(struct Node *x);
int func_021BF520(int a);
int func_021BF540(void);
int func_021BF558(void);
int func_021BF57C(void);
int func_021BF5B8(void);
int func_021BF5D8(int request, int result, char *buffer, int bufferLen, void *param);
void func_021BF67C(int request, int state, char *buffer, int bufferLen, int bytesReceived, int totalSize, Parameter *parameter);
extern int g_021D3B20[];


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
    g_021D3B20[0]++;
    return 1;
}


/*
 * sdk:      DWC_ShutdownGHTTP (dwc_ghttp.o)
 */
int func_021BF57C(void)
{
    if ((*(int *)&g_021D3B20) <= 0) {
        return 1;
    }
    func_021C204C();
    if (--(*(int *)&g_021D3B20) == 0) {
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
    Entry *parameter;
    CompletedCallback callback;
    int buffer_clear;

    parameter = (Entry *)param;
    callback = parameter->callback;
    buffer_clear = parameter->buffer_clear;
    if (callback != 0) {
        if (result == 0) {
            callback(buffer, bufferLen, result, parameter->param);
        } else if (result == 0x12) {
            callback(0, 0, result, parameter->param);
        } else {
            func_021BF8C0(result);
            callback(0, 0, result, parameter->param);
        }
    }
    if (result != 0 || buffer_clear == 1) {
        if (parameter == 0 || parameter->data == 0) {
            buffer_clear = 1;
        } else {
            DWC_Free(6, parameter->data, 0);
        }
    }
    func_021BFA70((struct Node *)parameter);
    return buffer_clear != 0;
}


void func_021BF67C(int request, int state, char *buffer, int bufferLen, int bytesReceived, int totalSize, Parameter *parameter)
{
    ProgressCallback callback = parameter->callback;

    if (callback == 0) {
        return;
    }
    callback(state, buffer, bufferLen, bytesReceived, totalSize, parameter->param);
}
