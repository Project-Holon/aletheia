/*
 * function: func_021DAB0C
 * address: 0x021DAB0C
 * packet: pkt_ov119_021DAB0C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_BuildMarkingTablesFrom 0x021E3E00 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DAAE4 0x021DAAE4 thumb ov119
 */
#include "../include/Obj13892.h"
extern int POKETRADE_2D_BuildMarkingTablesFrom(char *,int);
extern void POKETRADE_PROC_SetStep(void *p, int v);
extern void func_021DAAE4(char *);
void func_021DAB0C(char *p) {
 if(POKETRADE_2D_BuildMarkingTablesFrom(p,((struct Obj13892 *)p)->fF2C-1)) {
  ((struct Obj13892 *)p)->fF2C=0;
  POKETRADE_PROC_SetStep(p,(int)func_021DAAE4);
 }
}
