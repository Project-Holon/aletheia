/*
 * function: POKETRADE_PROC_StepOpenSubScreen
 * address: 0x021DB41C
 * packet: pkt_ov119_021DB41C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_LoadSubScreenGfx 0x021E5C64 thumb ov119
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindow 0x021E0EF4 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepSubScreenList 0x021DB304 thumb ov119
 */
#include "../include/Obj01055.h"
extern void POKETRADE_2D_LoadSubScreenGfx(char *p);
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindow(char *p, int flag, int x, int y, int w, int h);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepSubScreenList(char *p);
void POKETRADE_PROC_StepOpenSubScreen(char *p)
{
    POKETRADE_2D_LoadSubScreenGfx(p);
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj01055 *)p)->f720),0x33,(void *)(*(int *)&((struct Obj01055 *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindow(p,1,1,1,0x1d,4);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSubScreenList);
}
