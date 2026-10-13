/*
 * function: PMS_INPUT_VIEW_TaskSetWordwinScroll
 * address: 0x021BAAF0
 * packet: pkt_ov110_021BAAF0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_GetTopRow 0x021BF7AC thumb ov110
 *   PMSIV_WORDWIN_DrawListFrom 0x021BFA40 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj13775.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned PMS_INPUT_GetTopRow(u8 *);
extern void PMSIV_WORDWIN_DrawListFrom(u8 *,unsigned);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskSetWordwinScroll(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj00135 *)p)->f0; PMSIV_WORDWIN_DrawListFrom(*(u8 * *)&((struct Obj13775 *)q)->f5C,PMS_INPUT_GetTopRow(*(u8 * *)&((struct Obj13775 *)q)->f18)); PMS_INPUT_VIEW_EndTask(p); }
