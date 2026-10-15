/*
 * function: gsiSoapTaskHttpCompletedCallback
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
 *   gsXmlCreateStreamReader                  0x02181C2C  arm ov009
 *   gsXmlParseBuffer                  0x02181D10  arm ov009
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

extern void *gsXmlCreateStreamReader(void);
extern int gsXmlParseBuffer(void *stream, char *data, int len);

int gsiSoapTaskHttpCompletedCallback(int request, int result, char *buffer, int bufferLen, void *param)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)param;
    int parseResult;

    aSoapTask->result = result;
    aSoapTask->completed = 1;
    aSoapTask->buffer = buffer;
    if (result == 0) {
        aSoapTask->stream = gsXmlCreateStreamReader();
        if (aSoapTask->stream == 0) {
            aSoapTask->result = 1;
        } else {
            parseResult = gsXmlParseBuffer(aSoapTask->stream, buffer, bufferLen);
            if (parseResult == 0)
                aSoapTask->result = 7;
        }
    }
    return 0;
}
