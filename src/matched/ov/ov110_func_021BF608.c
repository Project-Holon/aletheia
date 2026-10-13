/*
 * function: PMS_INPUT_SubHandleCancel
 * address: 0x021BF608
 * packet: pkt_ov110_021BF608
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_SetExitState 0x021BF6CC thumb ov110
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_VIEW_GetMenuResult 0x021BAC0C thumb ov110
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 *   PMS_INPUT_SetHandler 0x021BD7A0 thumb ov110
 *   PMS_INPUT_HandleFinish 0x021BF4C4 thumb ov110
 *   PMS_INPUT_ClearSubHandler 0x021BF500 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PMS_INPUT_SetExitState(u8 *,u8,u8);
extern void PMS_INPUT_VIEW_StartTask(u8 *p, int id);
extern int PMS_INPUT_VIEW_GetMenuResult(u8 *p);
extern int PMS_INPUT_VIEW_IsIdle(unsigned int a);
extern void PMS_INPUT_SetHandler(u8 *,void (*)(void));
extern int PMS_INPUT_HandleFinish(u8 *p, int *q);
extern void PMS_INPUT_ClearSubHandler(u8 *);
void PMS_INPUT_SubHandleCancel(u8 *p,u32 *q) {
    switch(*q) {
    case 0: PMS_INPUT_SetExitState(p+107,1,1); ((struct Obj00012 *)p)->f48=1; PMS_INPUT_VIEW_StartTask(((struct Obj00012 *)p)->f14,21); *q=1; break;
    case 1:
        switch(PMS_INPUT_VIEW_GetMenuResult(((struct Obj00012 *)p)->f14)) {
        case 0: PMS_INPUT_VIEW_StartTask(((struct Obj00012 *)p)->f14,23); *q=2; break;
        case 1: PMS_INPUT_SetHandler(p,(void (*)(void))PMS_INPUT_HandleFinish); *q=2; break;
        }
        break;
    case 2: if(PMS_INPUT_VIEW_IsIdle((unsigned int)(((struct Obj00012 *)p)->f14))) PMS_INPUT_ClearSubHandler(p); break;
    }
}
