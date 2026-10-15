/*
 * function: BR_DOWNLOAD_DownloadTask
 * address: 0x021F86EC
 * packet: pkt_ov184_021F86EC
 * region: ov184
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_DOWNLOAD_ResetSlots 0x021F89D0 thumb ov184
 *   BR_DOWNLOAD_End3d 0x021F88E0 thumb ov184
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_NET_StartRequest 0x021FF54C thumb ov186
 *   BR_NET_IsIdle 0x021FF648 thumb ov186
 *   BR_NET_PollErrorMessage 0x021FF72C thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_UTIL_ClearTaskStep 0x021FD744 thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 */
#include "../include/Obj00548.h"
#include "../include/Obj24704.h"
#include "../include/Obj24705.h"
#include "../include/Obj24708.h"
#include "../include/Obj24709.h"
#include "../include/Obj24710.h"
#include "../include/Obj24711.h"
#include "../include/Obj24714.h"
typedef unsigned short u16;
typedef struct Cfg {int a,b;} Cfg;
typedef struct Pair {int x,y;} Pair;
extern void BR_FADE_Start(int,int,int,int);
extern int BR_FADE_GetResult(int *);
typedef unsigned int   u32;
extern void BR_DOWNLOAD_ResetSlots(int *a, char *p);
extern void BR_DOWNLOAD_End3d(char *,char *);
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern void BR_UTIL_StartEffect(int,int,Pair *);
extern void MI_CpuFill8(void *,int,unsigned);
extern void BR_NET_StartRequest(char *p, int kind, const int *values);
extern int BR_NET_IsIdle(char *);
extern int BR_NET_PollErrorMessage(char *,int *);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int BR_UTIL_ClearTaskStep(int *a);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
void BR_DOWNLOAD_DownloadTask(int *task,unsigned *state,char *p)
{
    Pair initial;
    Cfg cfg;
    int out,x,y;
    Pair pair;
    switch(*state) {
    case 0:BR_FADE_Start(**(int * *)&((struct Obj00548 *)p)->f30,4,3,1);*state=1;break;
    case 1:if(BR_FADE_GetResult(**(int ** *)&((struct Obj00548 *)p)->f30)) *state=2;break;
    case 2:
        BR_DOWNLOAD_ResetSlots((int *)p,*(char * *)&((struct Obj00548 *)p)->f30);
        BR_DOWNLOAD_End3d(p,*(char * *)&((struct Obj00548 *)p)->f30);
        ((struct Obj00548 *)p)->f10=BR_UTIL_CreateTextWin(((struct Obj24704 *)(*(char * *)&((struct Obj00548 *)p)->f30))->fC,(void *)(((struct Obj00548 *)p)->f20),((struct Obj00548 *)p)->f24);
        BR_UTIL_SetWindowText(((struct Obj00548 *)p)->f10,(char *)(((struct Obj24705 *)(*(char * *)&((struct Obj00548 *)p)->f30))->fC),(void *)0x145);
        initial.x=0x80;initial.y=0x60;
        BR_UTIL_StartEffect(((struct Obj00548 *)p)->f14,4,&initial);
        *state=3;break;
    case 3:BR_FADE_Start(**(int * *)&((struct Obj00548 *)p)->f30,4,3,0);*state=4;break;
    case 4:if(BR_FADE_GetResult(**(int ** *)&((struct Obj00548 *)p)->f30)) *state=5;break;
    case 5:
        MI_CpuFill8(&cfg,0,8);
        cfg.a=((struct Obj00548 *)p)->f28;
        BR_NET_StartRequest(*(char * *)&((struct Obj24708 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f14,0,(const int *)(&cfg));
        *(int *)&((struct Obj00548 *)p)->f2C=0;
        *state=6;break;
    case 6:
        ((struct Obj00548 *)p)->f2C=((struct Obj00548 *)p)->f2C+1;
        if(BR_NET_IsIdle(*(char * *)&((struct Obj24709 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f14) && ((struct Obj00548 *)p)->f2C>0x60) {
            BR_UTIL_StartEffect(((struct Obj00548 *)p)->f14,0,0);*state=7;
        }break;
    case 7:
        if(!BR_NET_PollErrorMessage(*(char * *)&((struct Obj24710 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f14,&out)) *state=9;
        else {BR_UTIL_SetWindowText(((struct Obj00548 *)p)->f10,(char *)(((struct Obj24711 *)(*(char * *)&((struct Obj00548 *)p)->f30))->fC),(void *)out);*state=8;}
        break;
    case 8:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));pair.x=x;pair.y=y;
            BR_UTIL_StartEffect(((struct Obj00548 *)p)->f18,1,&pair);
            GFL_USE_PlaySeDefaultVolume(0x703);*state=9;
        }break;
    case 9:BR_FADE_Start(**(int * *)&((struct Obj00548 *)p)->f30,2,3,1);*state=10;break;
    case 10:if(BR_FADE_GetResult(**(int ** *)&((struct Obj00548 *)p)->f30)) *state=11;break;
    case 11:BR_UTIL_ClearTaskStep(task);BR_PROC_SYS_PopEntry((unsigned int *)(((struct Obj24714 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f10));break;
    }
}
