/*
 * function: func_0217CF24
 * address:  0x0217CF24
 * packet:   pkt_ov009_0217CF24
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiCoreCreateTask (gscore.o)
 *
 * symbols:
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   func_020923B0                  0x020923B0  arm
 */

typedef struct GSTask {
    char pad0[0xc];
    int b0c;
    char pad10[0x38 - 0x10];
} GSTask;

extern void *func_0217EAB0(unsigned long size);
extern void *func_020923B0(void *p, int c, unsigned long n);

GSTask *func_0217CF24(void)
{
    GSTask *aTask = (GSTask *)func_0217EAB0(sizeof(GSTask));
    if (aTask == 0)
        return 0;
    func_020923B0(aTask, 0, sizeof(GSTask));
    aTask->b0c = 1;
    return aTask;
}
