/*
 * function: BTL_REC_SEL_PrintStep
 * address: 0x021BA190
 * packet: pkt_ov214_021BA190
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 */
#include "../include/Obj04632.h"

typedef unsigned int u32;
extern unsigned PRINTSYS_PrintStreamGetState(void*);
typedef signed int     s32;
typedef unsigned char  u8;
struct Rec;
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamReleasePause(void*);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern void UI_SetInputMode(u8 v);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
int BTL_REC_SEL_PrintStep(int unused,char*p)
{
    int result=0;
    switch(PRINTSYS_PrintStreamGetState(*(void* *)&((struct Obj04632 *)p)->f5C)){
    case 0:
        if((KEY_GetCont()&3)||TOUCHPANEL_GetCont()){
            PRINTSYS_PrintStreamShortWait(*(void* *)&((struct Obj04632 *)p)->f5C,0);
            if(KEY_GetCont()&3)UI_SetInputMode(0);else UI_SetInputMode(1);
        }
        break;
    case 1:
        if((KEY_GetTrg()&3)||TOUCHPANEL_GetTrg()){
            GFL_USE_PlaySeDefaultVolume(0x547);
            PRINTSYS_PrintStreamReleasePause(*(void* *)&((struct Obj04632 *)p)->f5C);
            if(KEY_GetTrg()&3)UI_SetInputMode(0);else UI_SetInputMode(1);
        }
        break;
    case 2:
        if(((struct Obj04632 *)p)->f64)--((struct Obj04632 *)p)->f64;
        else if(((struct Obj04632 *)p)->f60){
            if((KEY_GetTrg()&3)||TOUCHPANEL_GetTrg()){
                if(KEY_GetTrg()&3)UI_SetInputMode(0);else UI_SetInputMode(1);
                ((struct Obj04632 *)p)->f60=0;
                result=1;
            }
        }else result=1;
        break;
    }
    return result;
}
