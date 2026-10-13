/*
 * function: PMS_INPUT_HandleFinish
 * address: 0x021BF4C4
 * packet: pkt_ov110_021BF4C4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 */
#include "../include/Obj13793.h"
typedef unsigned char u8;
extern void PMS_INPUT_VIEW_StartTask(u8 *,int);
extern int PMS_INPUT_VIEW_IsIdle(unsigned);
int PMS_INPUT_HandleFinish(u8 *p,int *q) {
 switch(*q) {
 case 0: PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj13793 *)p)->f14,1); ++*q; break;
 case 1: if(PMS_INPUT_VIEW_IsIdle(*(unsigned *)&((struct Obj13793 *)p)->f14)!=0) return 1; break;
 }
 return 0;
}
