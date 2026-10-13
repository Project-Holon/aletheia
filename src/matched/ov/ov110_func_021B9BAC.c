/*
 * function: PMS_INPUT_VIEW_MainTask
 * address: 0x021B9BAC
 * packet: pkt_ov110_021B9BAC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DrawSystem 0x0204A600 arm
 *   PMSIV_MENU_Update 0x021BCA84 thumb ov110
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PMS_INPUT_VIEW_FlushHelpText 0x021BADE8 thumb ov110
 */
#include "../include/Obj03239.h"
struct PrintSys;
extern void CLACT_DrawSystem(void);
extern void PMSIV_MENU_Update(unsigned char *);
extern unsigned int PRINTSYS_QUE_Main(struct PrintSys *);
extern void PMS_INPUT_VIEW_FlushHelpText(unsigned char *);
void PMS_INPUT_VIEW_MainTask(int a,unsigned char *b) { CLACT_DrawSystem(); if(((struct Obj03239 *)b)->f64) PMSIV_MENU_Update(((struct Obj03239 *)b)->f64); if(((struct Obj03239 *)b)->f7C) { PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj03239 *)b)->f7C); PMS_INPUT_VIEW_FlushHelpText(b); } }
