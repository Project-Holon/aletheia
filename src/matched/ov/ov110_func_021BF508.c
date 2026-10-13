/*
 * function: PMS_INPUT_SubHandleOpen
 * address: 0x021BF508
 * packet: pkt_ov110_021BF508
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 *   PMS_INPUT_ClearSubHandler 0x021BF500 thumb ov110
 */
#include "../include/Obj13796.h"
typedef unsigned char u8;
extern void PMS_INPUT_VIEW_StartTask(u8 *,int);
extern int PMS_INPUT_VIEW_IsIdle(unsigned);
extern void PMS_INPUT_ClearSubHandler(u8 *);
void PMS_INPUT_SubHandleOpen(u8 *p,int *q) {
 switch(*q) {
 case 0: PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj13796 *)p)->f14,2); ++*q; break;
 case 1: if(PMS_INPUT_VIEW_IsIdle(*(unsigned *)&((struct Obj13796 *)p)->f14)!=0) PMS_INPUT_ClearSubHandler(p); break;
 }
}
