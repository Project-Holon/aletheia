/*
 * function: B_BAG_MAIN_StateWaitPrintWipe
 * address: 0x0220CBB4
 * packet: pkt_ov197_0220CBB4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 */
#include "../include/Obj14547.h"
#include "../include/Obj25065.h"
struct PrintSys;
extern unsigned PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void WIPE_SYS_Start(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
int B_BAG_MAIN_StateWaitPrintWipe(char *p){if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj14547 *)p)->f18)==1){WIPE_SYS_Start((void *)4,1,1,0,6,1,((struct Obj25065 *)(*(char * *)&((struct Obj14547 *)p)->f0))->fC);return 3;}return 2;}
