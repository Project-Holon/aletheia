/*
 * function: func_0218005C
 * address:  0x0218005C
 * packet:   pkt_ov009_0218005C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiSoapTaskCallback (gssoap.o)
 *
 * symbols:

 */

typedef struct GSSoapTask {
    void (*callback)(int, void *, void *, void *);
    char pad4[0xc];
    void *f10;
    void *f14;
    char pad18[8];
    void *f20;
    char pad24[8];
    int result;
} GSSoapTask;

void func_0218005C(void *theTask)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)theTask;
    aSoapTask->callback(aSoapTask->result, aSoapTask->f10, aSoapTask->f14, aSoapTask->f20);
}
