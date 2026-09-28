/*
 * function: func_0208C988
 * address:  0x0208C988
 * packet:   pkt_0208C988
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SCFG_SetCpuSpeed (libscfg.TWL.HYB.a scfg_proc.o)
 *
 * symbols:
 *   OS_DisableInterrupts           0x02087988  arm
 *   SCFGi_SwitchCpuSpeed           0x01FF87D4  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 */

typedef unsigned long u32;
typedef volatile unsigned short vu16;
typedef u32 OSIntrMode;

#define reg_SCFG_CLK (*(vu16 *)0x04004004)

OSIntrMode OS_DisableInterrupts(void);
OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
void SCFGi_SwitchCpuSpeed(int cpuSpeed);

void func_0208C988(int cpuSpeed)
{
    OSIntrMode enable = OS_DisableInterrupts();

    if (cpuSpeed != (reg_SCFG_CLK & 1)) {
        SCFGi_SwitchCpuSpeed(cpuSpeed);
    }
    (void)OS_RestoreInterrupts(enable);
}
