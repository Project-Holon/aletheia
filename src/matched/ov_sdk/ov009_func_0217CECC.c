/*
 * function: func_0217CECC
 * address:  0x0217CECC
 * packet:   pkt_ov009_0217CECC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiCoreCancelTask (gscore.o)
 *
 * symbols:
 *   func_0217CA20                  0x0217CA20  arm ov009
 *   func_0217F108                  0x0217F108  arm ov009
 *   func_0217F114                  0x0217F114  arm ov009
 */

typedef struct GSCoreMgr {
    char pad0[0x10];
    int cs;
} GSCoreMgr;
typedef struct GSTask {
    char pad0[0x14];
    int f14;
    int f18;
    void *obj1c;
    void *obj20;
    char pad24[8];
    void (*cb2c)(void *);
} GSTask;

extern GSCoreMgr *func_0217CA20(void);
extern void func_0217F108(void *cs);
extern void func_0217F114(void *cs);

void func_0217CECC(GSTask *theTask)
{
    GSCoreMgr *aCore = func_0217CA20();
    func_0217F108(&aCore->cs);
    if (theTask->f14 != 0 && theTask->f18 == 0) {
        theTask->f18 = 1;
        if (theTask->cb2c != 0)
            theTask->cb2c(theTask->obj20);
    }
    func_0217F114(&aCore->cs);
}
