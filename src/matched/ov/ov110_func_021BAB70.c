/*
 * function: PMS_INPUT_VIEW_TaskSetCategoryScroll
 * address: 0x021BAB70
 * packet: pkt_ov110_021BAB70
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_INPUT_GetCursorPos 0x021BF724 thumb ov110
 *   PMSIV_CATEGORY_StartSelectAnim 0x021BBB84 thumb ov110
 *   PMSIV_CATEGORY_IsSelectAnimDone 0x021BBC10 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj10269.h"
#include "../include/Obj10270.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 PMS_INPUT_GetCursorPos(u8 *);
extern void PMSIV_CATEGORY_StartSelectAnim(u8 *,unsigned);
extern int PMSIV_CATEGORY_IsSelectAnimDone(u8 *);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskSetCategoryScroll(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj10269 *)p)->f0; switch(((struct Obj10269 *)p)->f14) { case 0: PMSIV_CATEGORY_StartSelectAnim(*(u8 * *)&((struct Obj10270 *)q)->f58,PMS_INPUT_GetCursorPos(*(u8 * *)&((struct Obj10270 *)q)->f18)); (((struct Obj10269 *)p)->f14)++; break; case 1: if(PMSIV_CATEGORY_IsSelectAnimDone(*(u8 * *)&((struct Obj10270 *)q)->f58)) PMS_INPUT_VIEW_EndTask(p); break; } }
