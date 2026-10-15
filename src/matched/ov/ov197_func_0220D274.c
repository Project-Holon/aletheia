/*
 * function: B_BAG_MAIN_StateWaitPrintSetMode
 * address: 0x0220D274
 * packet: pkt_ov197_0220D274
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   B_BAG_MAIN_SwitchPage 0x0220D848 thumb ov197
 */
#include "../include/Obj10838.h"
struct PrintSys;
extern unsigned PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void B_BAG_MAIN_SwitchPage(char *,int);
int B_BAG_MAIN_StateWaitPrintSetMode(char *p){if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj10838 *)p)->f18)==1){B_BAG_MAIN_SwitchPage(p,((struct Obj10838 *)p)->f532);return ((struct Obj10838 *)p)->f531;}return 10;}
