/*
 * function: gsiCoreCreateTask
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
 *   gsimalloc                  0x0217EAB0  arm ov009
 *   MSL_C_LIB_MemsetPtr                  0x020923B0  arm
 */

typedef struct GSTask {
    char pad0[0xc];
    int b0c;
    char pad10[0x38 - 0x10];
} GSTask;

extern void *gsimalloc(unsigned long size);
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, unsigned long n);

GSTask *gsiCoreCreateTask(void)
{
    GSTask *aTask = (GSTask *)gsimalloc(sizeof(GSTask));
    if (aTask == 0)
        return 0;
    MSL_C_LIB_MemsetPtr(aTask, 0, sizeof(GSTask));
    aTask->b0c = 1;
    return aTask;
}
