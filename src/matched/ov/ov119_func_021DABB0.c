/*
 * function: POKETRADE_PROC_StepLoadBoxIconGfx
 * address: 0x021DABB0
 * packet: pkt_ov119_021DABB0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_LoadBoxIconGfx 0x021E5098 thumb ov119
 *   POKETRADE_2D_UpdateVisibleColumns 0x021E4E64 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepSendBoxInfo 0x021DAB34 thumb ov119
 */
#include "../include/Obj00001.h"
extern void POKETRADE_2D_LoadBoxIconGfx(char *,int);
extern void POKETRADE_2D_UpdateVisibleColumns(int a, char *p, int b);
extern void POKETRADE_PROC_SetStep(void *p, int v);
extern void POKETRADE_PROC_StepSendBoxInfo(char *);
void POKETRADE_PROC_StepLoadBoxIconGfx(char *p) {
 POKETRADE_2D_LoadBoxIconGfx(p,((struct Obj00001 *)p)->fF2C-1);
 if(((struct Obj00001 *)p)->fF2C>25) {
  POKETRADE_2D_UpdateVisibleColumns(*(int *)&((struct Obj00001 *)p)->f828,p,0);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendBoxInfo);
 }
}
