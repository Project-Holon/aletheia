/*
 * function: func_0217FF70
 * address:  0x0217FF70
 * packet:   pkt_ov009_0217FF70
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiSoapTaskThink (gssoap.o)
 *
 * symbols:
 *   func_021C2284                  0x021C2284  arm
 */

typedef struct GSSoapTask {
    char pad0[0x28];
    int request;
    int result;
    int completed;
} GSSoapTask;

extern int func_021C2284(int request);

int func_0217FF70(void *theTask)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)theTask;
    if (aSoapTask->completed != 0)
        return 4;
    func_021C2284(aSoapTask->request);
    return 1;
}
