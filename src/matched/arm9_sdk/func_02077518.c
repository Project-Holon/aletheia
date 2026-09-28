/*
 * function: func_02077518
 * address:  0x02077518
 * packet:   pkt_02077518
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_CheckPulledOutCore (libcard.TWL.HYB.a card_pullout.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   CARDi_PulledOutCallback  0x02077410  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef unsigned long u32;
typedef volatile u32 vu32;
typedef int BOOL;

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void CARDi_PulledOutCallback(int tag, u32 data, BOOL err);

void func_02077518(u32 id)
{
    vu32 iplCardID = *(u32 *)0x02FFFC00;

    if (id != iplCardID)
    {
        u32 bak_cpsr = OS_DisableInterrupts();

        CARDi_PulledOutCallback(14, 0x11, 0);
        (void)OS_RestoreInterrupts(bak_cpsr);
    }
}
