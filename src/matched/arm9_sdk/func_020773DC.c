/*
 * function: CARD_InitPulledOutCallback
 * address:  0x020773DC
 * packet:   pkt_020773DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARD_InitPulledOutCallback (libcard.TWL.HYB.a card_pullout.o)
 *
 * symbols:
 *   PXI_Init  0x02088498  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   CARDiSlotResetCount  0x02150B00  data
 *   CARDi_PulledOutCallback  0x02077410  arm
 */

#include "../include/G_CARDPulledOutState.h"

typedef unsigned long u32;
typedef int BOOL;

extern struct CARDPulledOutState CARDiSlotResetCount;

extern void PXI_Init(void);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int, u32, BOOL));
extern void CARDi_PulledOutCallback(int tag, u32 data, BOOL err);

void CARD_InitPulledOutCallback(void)
{
    PXI_Init();
    CARDiSlotResetCount.slot_reset_count = 0;
    CARDiSlotResetCount.is_pulled_out = 0;
    PXI_SetFifoRecvCallback(14, CARDi_PulledOutCallback);
    CARDiSlotResetCount.callback = 0;
}
