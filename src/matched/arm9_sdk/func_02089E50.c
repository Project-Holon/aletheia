/*
 * function: func_02089E50
 * address:  0x02089E50
 * packet:   pkt_02089E50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PxiFifoCallback (snd_command.o)
 *
 * symbols:
 *   OS_DisableInterrupts   0x02087988  arm
 *   SNDi_CallAlarmHandler  0x0208A010  arm
 *   OS_RestoreInterrupts   0x0208799C  arm
 */

typedef unsigned long u32;
typedef int BOOL;

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void SNDi_CallAlarmHandler(int msg);

void func_02089E50(int tag, u32 data, BOOL err)
{
    unsigned long enabled = OS_DisableInterrupts();

    SNDi_CallAlarmHandler((int)data);
    (void)OS_RestoreInterrupts(enabled);
}
