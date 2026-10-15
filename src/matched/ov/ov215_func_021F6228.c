/*
 * function: EGG_DEMO_MENU_WaitText
 * address: 0x021F6228
 * packet: pkt_ov215_021F6228
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 */
#include "../include/Obj10940.h"

typedef unsigned int u32;
extern unsigned PRINTSYS_PrintStreamGetState(void *);
extern unsigned int KEY_GetCont(void);
typedef signed int     s32;
struct Rec;
extern int TOUCHPANEL_GetCont(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *);
int EGG_DEMO_MENU_WaitText(void *unused,char *p)
{
    int result=0;
    switch(PRINTSYS_PrintStreamGetState(((struct Obj10940 *)p)->f50)) {
    case 0:
        if((KEY_GetCont()&3)!=0 || TOUCHPANEL_GetCont()!=0)
            PRINTSYS_PrintStreamShortWait(((struct Obj10940 *)p)->f50,0);
        break;
    case 1:
        if((KEY_GetTrg()&3)!=0 || TOUCHPANEL_GetTrg()!=0)
            PRINTSYS_PrintStreamReleasePause(((struct Obj10940 *)p)->f50);
        break;
    case 2:
        result=1;
        break;
    }
    return result;
}
