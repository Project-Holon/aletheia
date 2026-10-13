/*
 * function: IRC_COMPATIBLE_MENU_HandleChoice
 * address: 0x021B81B0
 * packet: pkt_ov102_021B81B0
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_020870D0 0x020870D0 arm
 * func_0209C2B0 0x0209C2B0 arm
 * IRC_COMPATIBLE_MENU_UpdateButtons 0x021B8624 thumb ov102
 * IRC_COMPATIBLE_MENU_IsButtonPressed 0x021B86FC thumb ov102
 * IRC_COMPATIBLE_MENU_PollChoice 0x021B870C thumb ov102
 * IRC_COMPATIBLE_MENU_SetButtonsEnabled 0x021B86F8 thumb ov102
 * IRC_APPBAR_IsPressed 0x021B7254 thumb ov101
 * IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 * IRC_APPBAR_SetActive 0x021B72A0 thumb ov101
 * IRC_APPBAR_SetLabel 0x021B72A8 thumb ov101
 * COMPATIBLE_IRC_SYS_ResetStep 0x021B63BC thumb ov101
 * IRC_COMPATIBLE_MENU_SetHandler 0x021B7F08 thumb ov102
 * IRC_COMPATIBLE_MENU_PrintMessage 0x021B7DFC thumb ov102
 * IRC_COMPATIBLE_MENU_HandleFinish 0x021B82DC thumb ov102
 * IRC_COMPATIBLE_MENU_HandleQuit 0x021B838C thumb ov102
 * IRC_COMPATIBLE_MENU_HandleStartTests 0x021B7F24 thumb ov102
 */
#include "../include/Obj01917.h"
#include "../include/Obj22149.h"
#include "../include/Obj22150.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned long long func_020870D0(void);
extern u32 func_0209C2B0(u32,u32);
extern void IRC_COMPATIBLE_MENU_UpdateButtons(u8 *);
extern int IRC_COMPATIBLE_MENU_IsButtonPressed(u8 *);
extern int IRC_COMPATIBLE_MENU_PollChoice(u8 *p, int *out);
extern void IRC_COMPATIBLE_MENU_SetButtonsEnabled(u8 *,u32);
extern int IRC_APPBAR_IsPressed(int *p);
extern int IRC_APPBAR_GetResult(int *p);
extern void IRC_APPBAR_SetActive(int p, int b);
extern void IRC_APPBAR_SetLabel(unsigned *p, unsigned b);
extern void COMPATIBLE_IRC_SYS_ResetStep(int *p);
extern void IRC_COMPATIBLE_MENU_SetHandler(unsigned p, unsigned x);
extern void IRC_COMPATIBLE_MENU_PrintMessage(u8 *,void *,int,int,short);
extern void IRC_COMPATIBLE_MENU_HandleFinish(u8 *,u16 *),IRC_COMPATIBLE_MENU_HandleQuit(u8 *,u16 *),IRC_COMPATIBLE_MENU_HandleStartTests(u8 *,u16 *);
void IRC_COMPATIBLE_MENU_HandleChoice(u8 *p,u16 *state)
{
    switch(*state) {
    case 0:
        ((struct Obj01917 *)p)->f494=2;
        ((struct Obj01917 *)p)->f4A0=0;
        ((struct Obj01917 *)p)->f490=func_0209C2B0((u32)func_020870D0()<<6,33514);
        *state=1;
        break;
    case 1:
        IRC_COMPATIBLE_MENU_UpdateButtons(p+0xc0);
        if(IRC_COMPATIBLE_MENU_IsButtonPressed(p+0xc0)) IRC_APPBAR_SetActive((int)(((struct Obj01917 *)p)->f468),0);
        if(IRC_COMPATIBLE_MENU_PollChoice(p+0xc0,(int *)(p+0x494))) {
            switch(((struct Obj01917 *)p)->f494) {
            case 0: *state=2; break;
            case 1:
                ((struct Obj22149 *)(*(u8 * *)&((struct Obj01917 *)p)->f48C))->fC=1;
                IRC_COMPATIBLE_MENU_SetHandler((unsigned int)p,(unsigned int)IRC_COMPATIBLE_MENU_HandleFinish);
                break;
            }
        }
        ((struct Obj01917 *)p)->f498=func_0209C2B0((u32)func_020870D0()<<6,33514)-((struct Obj01917 *)p)->f490;
        if(IRC_APPBAR_IsPressed(((struct Obj01917 *)p)->f468)) IRC_COMPATIBLE_MENU_SetButtonsEnabled(p+0xc0,0);
        if(IRC_APPBAR_GetResult(((struct Obj01917 *)p)->f468)==1) {
            COMPATIBLE_IRC_SYS_ResetStep(((struct Obj22150 *)(*(u8 * *)&((struct Obj01917 *)p)->f48C))->f4);
            IRC_COMPATIBLE_MENU_SetHandler((unsigned int)p,(unsigned int)IRC_COMPATIBLE_MENU_HandleQuit);
        }
        break;
    case 2:
        IRC_COMPATIBLE_MENU_PrintMessage(p+0xac,p+0x9c,3,0,0);
        IRC_APPBAR_SetLabel(((struct Obj01917 *)p)->f468,1);
        IRC_APPBAR_SetActive((int)(((struct Obj01917 *)p)->f468),0);
        IRC_COMPATIBLE_MENU_SetHandler((unsigned int)p,(unsigned int)IRC_COMPATIBLE_MENU_HandleStartTests);
        break;
    }
}
