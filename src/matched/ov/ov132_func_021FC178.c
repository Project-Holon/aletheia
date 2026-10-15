/*
 * function: SCRIPT_COMMAND_TaskMoveEffect
 * address: 0x021FC178
 * packet: pkt_ov132_021FC178
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACT_SCRIPT_TickSlot 0x021FAEE8 thumb ov132
 *   STA_ACT_SCRIPT_RemoveTask 0x021FADF8 thumb ov132
 *   STA_ACT_EFFECT_StartEffect 0x021F9F74 thumb ov132
 */
#include "../include/Obj02851.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern int STA_ACT_SCRIPT_TickSlot(char *p);
extern void STA_ACT_SCRIPT_RemoveTask(char *p, char *q);
extern u32 func_02005728(u32 range);
extern void STA_ACT_EFFECT_StartEffect(void *, u16, void *);
void SCRIPT_COMMAND_TaskMoveEffect(int a, char *p)
{
    u32 v[3];
    int s;
    s=STA_ACT_SCRIPT_TickSlot(p);
    if(s==2) {
        STA_ACT_SCRIPT_RemoveTask(((struct Obj02851 *)p)->f30,((struct Obj02851 *)p)->f34);
        return;
    }
    if(s==1) {
        v[0]=(((struct Obj02851 *)p)->f14+func_02005728((u32)(((struct Obj02851 *)p)->f20)))>>4;
        v[1]=(0xc0000-(((struct Obj02851 *)p)->f18+func_02005728((u32)(((struct Obj02851 *)p)->f24))))>>4;
        v[2]=((struct Obj02851 *)p)->f1C+func_02005728((u32)(((struct Obj02851 *)p)->f28));
        STA_ACT_EFFECT_StartEffect(((struct Obj02851 *)p)->f10,((struct Obj02851 *)p)->f2C,v);
    }
}
