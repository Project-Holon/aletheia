/*
 * file:     mi_init.c
 * function: MI_Init
 * address:  0x0208361C
 * packet:   pkt_0208361C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MI_Init (libmi.TWL.HYB.a mi_init.o)
 *
 * symbols:
 *   MI_SetWramBank                 0x020821B0  arm
 *   OS_IsRunOnTwl                  0x02085D3C  arm
 *   MI_InitNDma                    0x0272FB10  arm
 *   MI_StopDma                     0x020825F0  arm
 */

#include "mi_wram.h"
#include "os_emulator.h"
#include "../twl/mi_ndma.h"
#include "mi_dma.h"

void MI_Init(void)
{
    MI_SetWramBank(3);
    if (OS_IsRunOnTwl()) {
        MI_InitNDma();
    }
    MI_StopDma(0);
}
