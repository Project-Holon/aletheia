/*
 * function: gsiSoapTaskThink
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
 *   ghttpRequestThink                  0x021C2284  arm
 */

typedef struct GSSoapTask {
    char pad0[0x28];
    int request;
    int result;
    int completed;
} GSSoapTask;

extern int ghttpRequestThink(int request);

int gsiSoapTaskThink(void *theTask)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)theTask;
    if (aSoapTask->completed != 0)
        return 4;
    ghttpRequestThink(aSoapTask->request);
    return 1;
}
