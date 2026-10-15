/*
 * function: POKETRADE_PROC_StepMenuChoice
 * address: 0x021D9D60
 * packet: pkt_ov119_021D9D60
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   POKETRADE_SAVE_CloseTaskMenu 0x021E12F8 thumb ov119
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepSendIntroReady 0x021D9CFC thumb ov119
 *   POKETRADE_PROC_StepResetGrid 0x021DBA80 thumb ov119
 */
#include "../include/Obj00001.h"

typedef unsigned int   u32;
struct MsgBank;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern unsigned char APP_TASKMENU_GetCursorPos(const unsigned char *p);
typedef unsigned char  u8;
extern void POKETRADE_SAVE_CloseTaskMenu(char *p);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepSendIntroReady(u8 *p);
extern void POKETRADE_PROC_StepResetGrid(char *p);
void POKETRADE_PROC_StepMenuChoice(char *p) {
    int v;
    if (APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {
        v=APP_TASKMENU_GetCursorPos((const unsigned char *)(*(int *)&((struct Obj00001 *)p)->f64C));
        POKETRADE_SAVE_CloseTaskMenu(p);
        *(int *)&((struct Obj00001 *)p)->f64C=0;
        if (v==0) {
            MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),6,(void *)(*(int *)&((struct Obj00001 *)p)->f738));
            POKETRADE_SAVE_OpenMessageWindowTop(p);
            POKETRADE_SAVE_ShowTimeIcon(p);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendIntroReady);
            return;
        }
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepResetGrid);
    }
}
