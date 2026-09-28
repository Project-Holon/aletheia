/*
 * function: func_0218002C
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
 *   func_021C22A4                  0x021C22A4  arm
 */

typedef struct GSSoapTask {
    char pad0[0x28];
    int request;
    int result;
    int completed;
} GSSoapTask;

extern void func_021C22A4(int request);

void func_0218002C(void *theTask)
{
    GSSoapTask *soapTask = (GSSoapTask *)theTask;
    if (soapTask->completed != 0)
        return;
    if (soapTask->request >= 0)
        func_021C22A4(soapTask->request);
    soapTask->result = 18;
}
