/*
 * function: PMS_INPUT_HandleWordList
 * address: 0x021BEDEC
 * packet: pkt_ov110_021BEDEC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_HandleWordListInput 0x021BF1C4 thumb ov110
 *   PMS_INPUT_VIEW_IsTaskNotRunning 0x021B9C90 thumb ov110
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 *   PMS_INPUT_SetHandler 0x021BD7A0 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void PMS_INPUT_HandleWordListInput(u8 *,void *);
extern int PMS_INPUT_VIEW_IsTaskNotRunning(unsigned int a, int b);
extern void PMS_INPUT_VIEW_StartTask(u8 *p, int id);
extern int PMS_INPUT_VIEW_IsIdle(unsigned int a);
extern void PMS_INPUT_SetHandler(u8 *,void *);
int PMS_INPUT_HandleWordList(u8 *p,u32 *q) {
    switch(*q) {
    case 0: PMS_INPUT_HandleWordListInput(p,q); break;
    case 1: if(PMS_INPUT_VIEW_IsTaskNotRunning((unsigned int)(((struct Obj00012 *)p)->f14),20)) *q=0; break;
    case 2: if(PMS_INPUT_VIEW_IsTaskNotRunning((unsigned int)(((struct Obj00012 *)p)->f14),20)) { PMS_INPUT_VIEW_StartTask(((struct Obj00012 *)p)->f14,19); *q=0; } break;
    case 3: if(PMS_INPUT_VIEW_IsTaskNotRunning((unsigned int)(((struct Obj00012 *)p)->f14),31)) *q=0; break;
    case 4: if(PMS_INPUT_VIEW_IsIdle((unsigned int)(((struct Obj00012 *)p)->f14))) { PMS_INPUT_SetHandler(p,((struct Obj00012 *)p)->f28); *q=0; } break;
    }
    return 0;
}
