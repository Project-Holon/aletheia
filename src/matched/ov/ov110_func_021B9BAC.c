/*
 * function: func_021B9BAC
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
 *   func_021BCA84 0x021BCA84 thumb ov110
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021BADE8 0x021BADE8 thumb ov110
 */
#include "../include/Obj03239.h"
struct PrintSys;
extern void CLACT_DrawSystem(void);
extern void func_021BCA84(unsigned char *);
extern unsigned int PRINTSYS_QUE_Main(struct PrintSys *);
extern void func_021BADE8(unsigned char *);
void func_021B9BAC(int a,unsigned char *b) { CLACT_DrawSystem(); if(((struct Obj03239 *)b)->f64) func_021BCA84(((struct Obj03239 *)b)->f64); if(((struct Obj03239 *)b)->f7C) { PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj03239 *)b)->f7C); func_021BADE8(b); } }
