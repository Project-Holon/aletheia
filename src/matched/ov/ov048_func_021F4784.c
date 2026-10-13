/*
 * function: GIMMICK_OBJ_ELBOARD_Advance
 * address: 0x021F4784
 * packet: pkt_ov048_021F4784
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GIMMICK_OBJ_ELBOARD_UpdateLine 0x021F4B7C thumb ov048
 */
#include "../include/Obj09839.h"
extern void GIMMICK_OBJ_ELBOARD_UpdateLine(int *a,int *b,int c);
void GIMMICK_OBJ_ELBOARD_Advance(unsigned char *p,int c) { int i; for(i=0;i<p[2];i++) GIMMICK_OBJ_ELBOARD_UpdateLine((int *)p,((int **)((struct Obj09839 *)p)->f8)[i],c); ((struct Obj09839 *)p)->f18+=c; }
