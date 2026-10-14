/*
 * function: POKETRADE_SAVE_StepWaitEvolutionMessage
 * address: 0x021E0958
 * packet: pkt_ov119_021E0958
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_SAVE_StepCheckEvolution 0x021E0A64 thumb ov119
 */
#include "../include/Obj22759.h"
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_SAVE_StepCheckEvolution(char *p);
void POKETRADE_SAVE_StepWaitEvolutionMessage(char *p)
{
    if (POKETRADE_SAVE_IsMessagePrintDone(p) && ((struct Obj22759 *)p)->fF2C > 0xB4) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepCheckEvolution);
    }
}
