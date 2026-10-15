/*
 * function: BOX2_SEQ_AddMsgFrame
 * address: 0x021EB79C
 * packet: pkt_ov170_021EB79C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_DrawFrameDefault 0x021EB6F0 thumb ov170
 *   BOX2_SEQ_AddBmpWinFrame 0x021EB708 thumb ov170
 */
#include "../include/Obj01558.h"
#include "../include/Obj23969.h"
#include "../include/Obj23970.h"
#include "../include/Obj23971.h"
extern void BOX2_SEQ_DrawFrameDefault(int a, int b, int c);extern void BOX2_SEQ_AddBmpWinFrame(void *,unsigned,void *);
void BOX2_SEQ_AddMsgFrame(unsigned char *p){if(((struct Obj23969 *)(*(unsigned char * *)&((struct Obj01558 *)p)->f0))->f24==4)BOX2_SEQ_DrawFrameDefault((int)p,22,71);else BOX2_SEQ_DrawFrameDefault((int)p,22,69);BOX2_SEQ_AddBmpWinFrame(((struct Obj23970 *)(*(unsigned char * *)&((struct Obj01558 *)p)->f2C))->f74,10,((struct Obj23971 *)(*(unsigned char * *)&((struct Obj01558 *)p)->f2C))->f144);}
