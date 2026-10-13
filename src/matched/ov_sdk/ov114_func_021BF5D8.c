/*
 * function: func_021BF5D8
 * address:  0x021BF5D8
 * packet:   pkt_ov114_021BF5D8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GHTTPCompletedCallback (dwc_ghttp.o)
 *
 * symbols:
 *   DWCi_HandleGHTTPError  0x021BF8C0  arm  ov114
 *   DWC_Free       0x0205A1B0  arm
 *   DWCi_RemoveDWCGHTTPParamEntry  0x021BFA70  arm  ov114
 */

typedef void (*CompletedCallback)(char *buffer, int bufferLen, int result, void *param);
typedef struct Entry {
    void *param;
    CompletedCallback callback;
    int unk8;
    int unkc;
    int buffer_clear;
    void *data;
} Entry;
extern int DWCi_HandleGHTTPError(int result);
extern void DWC_Free(int name, void *ptr, int size);
struct Node;
extern void DWCi_RemoveDWCGHTTPParamEntry(struct Node *x);

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
            DWCi_HandleGHTTPError(result);
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
    DWCi_RemoveDWCGHTTPParamEntry((struct Node *)parameter);
    return buffer_clear != 0;
}
