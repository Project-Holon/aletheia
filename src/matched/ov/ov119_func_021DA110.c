/*
 * function: POKETRADE_PROC_ShowSelectMessage
 * address: 0x021DA110
 * packet: pkt_ov119_021DA110
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowAtPos 0x021E0FF4 thumb ov119
 *   POKETRADE_2D_UpdateVisibleColumns 0x021E4E64 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepWaitKeyAfterMessage 0x021DA064 thumb ov119
 */
#include "../include/Obj00001.h"

typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowAtPos(void *,int,int);
extern void POKETRADE_2D_UpdateVisibleColumns(int a, char *p, int b);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepWaitKeyAfterMessage(char *p);
void POKETRADE_PROC_ShowSelectMessage(char *p)
{
    MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 0x8E, (void *)(*(int *)&((struct Obj00001 *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowAtPos(p,1,0);
    ((struct Obj00001 *)p)->f1080 = -1;
    POKETRADE_2D_UpdateVisibleColumns(*(int *)&((struct Obj00001 *)p)->f828, p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepWaitKeyAfterMessage);
}
