/*
 * function: POKETRADE_PROC_StepBuildTradeRecord
 * address: 0x021DAAE4
 * packet: pkt_ov119_021DAAE4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_BuildTradeRecords 0x021DC62C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepSendTradeData 0x021DAA7C thumb ov119
 */
#include "../include/Obj13891.h"
extern void POKETRADE_PROC_BuildTradeRecords(char *,int);
extern void POKETRADE_PROC_SetStep(void *p, int v);
extern void POKETRADE_PROC_StepSendTradeData(char *);
void POKETRADE_PROC_StepBuildTradeRecord(char *p) {
 POKETRADE_PROC_BuildTradeRecords(p,((struct Obj13891 *)p)->fF2C-1);
 if(((struct Obj13891 *)p)->fF2C>=24) POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendTradeData);
}
