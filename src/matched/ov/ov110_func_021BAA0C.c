/*
 * unit: yes
 * function: PMS_INPUT_VIEW_TaskSetMenuDecide, PMS_INPUT_VIEW_TaskEndOnly1
 * address: 0x021BAA0C
 * packet: pkt_ov110_021BAA0C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_GetCancelSelected 0x021BF71C thumb ov110
 *   PMSIV_MENU_SetDecideEntry 0x021BCFBC thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj22334.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 PMS_INPUT_GetCancelSelected(u8 *);
typedef unsigned int   u32;
extern void PMSIV_MENU_SetDecideEntry(char *p, u32 index, int value);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskSetMenuDecide(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj00135 *)p)->f0; PMSIV_MENU_SetDecideEntry((char *)(*(u8 * *)&((struct Obj22334 *)q)->f64),(u8)PMS_INPUT_GetCancelSelected(*(u8 * *)&((struct Obj00135 *)p)->f4),1); PMS_INPUT_VIEW_EndTask(p); }
void PMS_INPUT_VIEW_TaskEndOnly1(int a,u8 *p) { PMS_INPUT_VIEW_EndTask(p); }
