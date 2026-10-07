/*
 * function: func_0217FF14
 * address:  0x0217FF14
 * packet:   pkt_ov009_0217FF14
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiSoapTaskHttpCompletedCallback (gssoap.o)
 *
 * symbols:
 *   func_02181C2C                  0x02181C2C  arm ov009
 *   func_02181D10                  0x02181D10  arm ov009
 */

typedef struct GSSoapTask {
    char pad0[0x14];
    void *stream;
    char *buffer;
    char pad1c[0x28 - 0x1c];
    int request;
    int result;
    int completed;
} GSSoapTask;

extern void *func_02181C2C(void);
extern int func_02181D10(void *stream, char *data, int len);

int func_0217FF14(int request, int result, char *buffer, int bufferLen, void *param)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)param;
    int parseResult;

    aSoapTask->result = result;
    aSoapTask->completed = 1;
    aSoapTask->buffer = buffer;
    if (result == 0) {
        aSoapTask->stream = func_02181C2C();
        if (aSoapTask->stream == 0) {
            aSoapTask->result = 1;
        } else {
            parseResult = func_02181D10(aSoapTask->stream, buffer, bufferLen);
            if (parseResult == 0)
                aSoapTask->result = 7;
        }
    }
    return 0;
}
