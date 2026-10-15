/*
 * function: gsiSoapTaskCancel
 * address:  0x0218002C
 * packet:   pkt_ov009_0218002C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiSoapTaskCancel (gssoap.o)
 *
 * symbols:
 *   ghttpCancelRequest                  0x021C22A4  arm
 */

typedef struct GSSoapTask {
    char pad0[0x28];
    int request;
    int result;
    int completed;
} GSSoapTask;

extern void ghttpCancelRequest(int request);

void gsiSoapTaskCancel(void *theTask)
{
    GSSoapTask *soapTask = (GSSoapTask *)theTask;
    if (soapTask->completed != 0)
        return;
    if (soapTask->request >= 0)
        ghttpCancelRequest(soapTask->request);
    soapTask->result = 18;
}
