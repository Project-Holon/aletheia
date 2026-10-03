/*
 * function: func_0217CD94
 * address:  0x0217CD94
 * packet:   pkt_ov009_0217CD94
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsCoreShutdown (gscore.o)
 *
 * symbols:
 *   func_0217CA20                  0x0217CA20  arm ov009
 *   func_0217F108                  0x0217F108  arm ov009
 *   func_0217F0D8                  0x0217F0D8  arm ov009
 *   func_0217F114                  0x0217F114  arm ov009
 *   func_02184200                  0x02184200  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   func_0217CECC                  0x0217CECC  arm ov009
 */

typedef struct GSTask GSTask;
typedef struct GSCoreMgr {
    unsigned int refs;
    char pad4[4];
    int active;
    int shutdown;
    int cs;
    char pad14[0x28 - 0x14];
    void *tasks;
} GSCoreMgr;

extern void *func_0217CA20(void);
extern void func_0217F108(void *cs);
extern unsigned int func_0217F0D8(unsigned int *value);
extern void func_0217F114(void *cs);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern void func_0217CECC(struct GSTask *theTask);

void func_0217CD94(void)
{
    GSCoreMgr *aCore = func_0217CA20();
    int i;
    int len;

    if (aCore->active == 0)
        return;
    func_0217F108(&aCore->cs);
    if (func_0217F0D8(&aCore->refs) != 0) {
        func_0217F114(&aCore->cs);
        return;
    }
    aCore->shutdown = 1;
    len = func_02184200(aCore->tasks);
    for (i = 0; i < len; i++)
        func_0217CECC(*(GSTask **)func_02184208(aCore->tasks, i));
    func_0217F114(&aCore->cs);
}
