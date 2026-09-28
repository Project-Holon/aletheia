/*
 * function: func_0217CB5C
 * address:  0x0217CB5C
 * packet:   pkt_ov009_0217CB5C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiCoreTaskDispatchCallback (gscore.o)
 *
 * symbols:

 */

typedef struct GSTask {
    char pad0[0x1c];
    int pending;
    void *obj20;
    char pad24[4];
    void (*cb28)(void *, int);
} GSTask;

void func_0217CB5C(GSTask *theTask, int theResult)
{
    if (theTask->pending) {
        void (*cb)(void *, int);
        theTask->pending = 0;
        cb = theTask->cb28;
        if (cb != 0)
            cb(theTask->obj20, theResult);
    }
}