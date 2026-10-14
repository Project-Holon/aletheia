/*
 * function: func_021DA254
 * address: 0x021DA254
 * packet: pkt_ov119_021DA254
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_NEGO_AddSelectedAsOffer 0x021DD5B4 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepShowCancelMessage 0x021DF5D8 thumb ov119
 */
#include "../include/Obj00001.h"
extern int POKETRADE_NEGO_AddSelectedAsOffer(char *p, int a, int b);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepShowCancelMessage(char *p);
void func_021DA254(char *p) {
 if(POKETRADE_NEGO_AddSelectedAsOffer(p,((struct Obj00001 *)p)->fF84,((struct Obj00001 *)p)->fF88)) POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepShowCancelMessage);
}
