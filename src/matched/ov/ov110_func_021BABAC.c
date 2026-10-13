/*
 * function: PMS_INPUT_VIEW_TaskSetWordwinPage
 * address: 0x021BABAC
 * packet: pkt_ov110_021BABAC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_INPUT_GetCursorCell 0x021BF784 thumb ov110
 *   PMSIV_WORDWIN_StartPickAnim 0x021C00AC thumb ov110
 *   PMSIV_WORDWIN_IsPickAnimDone 0x021C00FC thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj10271.h"
#include "../include/Obj10272.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned PMS_INPUT_GetCursorCell(u8 *);
extern void PMSIV_WORDWIN_StartPickAnim(u8 *,unsigned);
extern int PMSIV_WORDWIN_IsPickAnimDone(u8 *);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskSetWordwinPage(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj10271 *)p)->f0; switch(((struct Obj10271 *)p)->f14) { case 0: PMSIV_WORDWIN_StartPickAnim(*(u8 * *)&((struct Obj10272 *)q)->f5C,PMS_INPUT_GetCursorCell(*(u8 * *)&((struct Obj10272 *)q)->f18)); (((struct Obj10271 *)p)->f14)++; break; case 1: if(PMSIV_WORDWIN_IsPickAnimDone(*(u8 * *)&((struct Obj10272 *)q)->f5C)) PMS_INPUT_VIEW_EndTask(p); break; } }
