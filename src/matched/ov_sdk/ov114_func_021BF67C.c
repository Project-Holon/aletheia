/*
 * function: func_021BF67C
 * address:  0x021BF67C
 * packet:   pkt_ov114_021BF67C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GHTTPProgressCallback (dwc_ghttp.o)
 *
 * symbols:
 */

typedef void (*ProgressCallback)(int state, char *buffer, int bufferLen, int bytesReceived, int totalSize, void *param);
typedef struct {
    void *param;
    int unk4;
    ProgressCallback callback;
} Parameter;

void func_021BF67C(int request, int state, char *buffer, int bufferLen, int bytesReceived, int totalSize, Parameter *parameter)
{
    ProgressCallback callback = parameter->callback;

    if (callback == 0) {
        return;
    }
    callback(state, buffer, bufferLen, bytesReceived, totalSize, parameter->param);
}
