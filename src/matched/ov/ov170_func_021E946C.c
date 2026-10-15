/*
 * function: BOX2_SEQ_StateEnterItemMenu
 * address: 0x021E946C
 * packet: pkt_ov170_021E946C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_SEQ_StateItemMenu 0x021E2334 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23945.h"
#include "../include/Obj23946.h"
typedef unsigned char  u8;
extern u8 func_020355C4(void); extern void CURSOR_MOVE_SetState(void *,int); extern void BOX2_SEQ_SetCursorDraw(char **,int); extern int BOX2_SEQ_StateItemMenu(unsigned char *);
void BOX2_SEQ_StateEnterItemMenu(unsigned char *p){if(func_020355C4()==1)CURSOR_MOVE_SetState(((struct Obj23945 *)(*(unsigned char * *)&((struct Obj00000 *)p)->f2C))->f70,0);else {CURSOR_MOVE_SetState(((struct Obj23946 *)(*(unsigned char * *)&((struct Obj00000 *)p)->f2C))->f70,1);BOX2_SEQ_SetCursorDraw((char **)p,0);}BOX2_SEQ_StateItemMenu(p);}
