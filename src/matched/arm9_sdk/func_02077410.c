/*
 * function: func_02077410
 * address:  0x02077410
 * packet:   pkt_02077410
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      CARDi_PulledOutCallback (libcard.TWL.HYB.a card_pullout.o)
 *
 * symbols:
 *   CARDi_NotifyEvent  0x02076100  arm
 *   CARD_TerminateForPulledOut  0x020774C0  arm
 *   OS_Terminate  0x02088234  arm
 *   CARDiSlotResetCount  0x02150B00  data
 */

typedef unsigned long u32;
typedef int BOOL;

struct CARDPulledOutState {
    u32 slot_reset_count;
    BOOL is_pulled_out;
    BOOL (*callback)(void);
};

extern struct CARDPulledOutState CARDiSlotResetCount;

extern void CARDi_NotifyEvent(u32 event, void *arg);
extern void CARD_TerminateForPulledOut(void);
extern void OS_Terminate(void);

void func_02077410(int tag, u32 data, BOOL err)
{
#pragma unused(tag, err)
    u32 command = data & 0x3F;

    if (command == 0x11)
    {
        if (!CARDiSlotResetCount.is_pulled_out)
        {
            BOOL isTerminateImm = 1;

            CARDiSlotResetCount.is_pulled_out = 1;
            CARDi_NotifyEvent(1, 0);
            if (CARDiSlotResetCount.callback)
            {
                isTerminateImm = (*CARDiSlotResetCount.callback)();
            }
            if (isTerminateImm)
            {
                CARD_TerminateForPulledOut();
            }
        }
    }
    else if (command == 2)
    {
        CARDiSlotResetCount.slot_reset_count++;
        CARDiSlotResetCount.is_pulled_out = 0;
        CARDi_NotifyEvent(2, 0);
    }
    else
    {
        OS_Terminate();
    }
}
