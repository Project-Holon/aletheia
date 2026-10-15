/*
 * function: POKETRADE_PROC_StepConfirmSendOffer
 * address: 0x021DBC3C
 * packet: pkt_ov119_021DBC3C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_NEGO_AddSelectedAsOffer 0x021DD5B4 thumb ov119
 *   POKETRADE_PROC_SendSideMon 0x021DB0A0 thumb ov119
 *   POKETRADE_PROC_RequestBoxRedraw 0x021D8B38 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepBrowseGrid 0x021DBE70 thumb ov119
 */
#include "../include/Obj00001.h"
extern int POKETRADE_PROC_IsHostSide(void *);
extern int POKETRADE_NEGO_AddSelectedAsOffer(char *p, int a, int b);
extern int POKETRADE_PROC_SendSideMon(char *p);
extern void POKETRADE_PROC_RequestBoxRedraw(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepBrowseGrid(char *p);
void POKETRADE_PROC_StepConfirmSendOffer(char *p) {
 if(POKETRADE_PROC_IsHostSide(p)) { if(POKETRADE_NEGO_AddSelectedAsOffer(p,((struct Obj00001 *)p)->fF84,((struct Obj00001 *)p)->fF88)==0) return; }
 else { if(POKETRADE_PROC_SendSideMon(p)==0) return; }
 ((struct Obj00001 *)p)->fF98=-1; ((struct Obj00001 *)p)->fF94=-1;
 ((struct Obj00001 *)p)->fF7C=-1; ((struct Obj00001 *)p)->fF80=-1;
 POKETRADE_PROC_RequestBoxRedraw(p); POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);
}
