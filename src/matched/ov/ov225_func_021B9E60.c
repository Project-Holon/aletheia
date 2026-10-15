/*
 * function: func_021B9E60
 * address: 0x021B9E60
 * packet: pkt_ov225_021B9E60
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   MANUAL_GRAPHIC_DrawScreen 0x021B99F4 thumb ov225
 */
#include "../include/Obj08467.h"
struct PrintSys;extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);extern void MANUAL_GRAPHIC_DrawScreen(char *);
void func_021B9E60(char *p){PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj08467 *)p)->f10);PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj08467 *)p)->f14);PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj08467 *)p)->f18);MANUAL_GRAPHIC_DrawScreen(*(char * *)&((struct Obj08467 *)p)->f8);}
