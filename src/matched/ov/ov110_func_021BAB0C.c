/*
 * function: PMS_INPUT_VIEW_TaskUpdateMenuDecide
 * address: 0x021BAB0C
 * packet: pkt_ov110_021BAB0C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSIV_MENU_StartPress 0x021BCEE4 thumb ov110
 *   PMSIV_MENU_IsPressDone 0x021BCF38 thumb ov110
 *   PMSIV_MENU_SetActiveEntry 0x021BCF7C thumb ov110
 *   PMS_INPUT_GetCursorPos 0x021BF724 thumb ov110
 *   PMS_INPUT_GetSavedCursorPos 0x021BF72C thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj04443.h"
#include "../include/Obj10268.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PMSIV_MENU_StartPress(char *p, u32 mode);
extern int PMSIV_MENU_IsPressDone(char *p, u32 mode);
extern void PMSIV_MENU_SetActiveEntry(u8 *p, int n, int v);
extern u16 PMS_INPUT_GetCursorPos(u8 *);
extern u16 PMS_INPUT_GetSavedCursorPos(u8 *);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskUpdateMenuDecide(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 * *)&((struct Obj10268 *)p)->f0;
    switch(((struct Obj10268 *)p)->f14) {
    case 0:
        PMSIV_MENU_StartPress((char *)(*(u8 * *)&((struct Obj04443 *)q)->f64),2);
        ++((struct Obj10268 *)p)->f14;
        break;
    case 1:
        if(PMSIV_MENU_IsPressDone((char *)(*(u8 * *)&((struct Obj04443 *)q)->f64),2)) {
            if(**(u32 * *)&((struct Obj04443 *)q)->f78==0 && PMS_INPUT_GetCursorPos(*(u8 * *)&((struct Obj04443 *)q)->f18)==253 && PMS_INPUT_GetSavedCursorPos(*(u8 * *)&((struct Obj04443 *)q)->f18)==253)
                PMSIV_MENU_SetActiveEntry(*(u8 * *)&((struct Obj04443 *)q)->f64,1,1);
            else PMSIV_MENU_SetActiveEntry(*(u8 * *)&((struct Obj04443 *)q)->f64,0,0);
            PMS_INPUT_VIEW_EndTask(p);
        }
        break;
    }
}
