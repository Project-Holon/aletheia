/*
 * function: BR_POKESEARCH_NetworkTask
 * address: 0x021F8790
 * packet: pkt_ov185_021F8790
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_NET_StartRequest 0x021FF54C thumb ov186
 *   BR_NET_IsIdle 0x021FF648 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_NET_PollErrorMessage 0x021FF72C thumb ov186
 *   BR_NET_GetDownloadEntries 0x021FF660 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_POKESEARCH_DownloadDoneTask 0x021F88B0 thumb ov185
 *   BR_POKESEARCH_RefreshTask 0x021F8A0C thumb ov185
 */
#include "../include/Obj01276.h"
#include "../include/Obj24723.h"
#include "../include/Obj24724.h"
#include "../include/Obj24725.h"
#include "../include/Obj24726.h"
#include "../include/Obj24727.h"
#include "../include/Obj24728.h"
typedef unsigned short u16;
typedef struct Cfg {u16 heap;unsigned char rest[6];} Cfg;
typedef struct Pair {int x,y;} Pair;
extern void MI_CpuFill8(void *,int,unsigned);
typedef unsigned int   u32;
extern void BR_NET_StartRequest(char *p, int kind, const int *values);
extern int BR_NET_IsIdle(char *),BR_NET_PollErrorMessage(char *,int *),BR_NET_GetDownloadEntries(char *,int,int,int *);
extern void BR_UTIL_StartEffect(int,int,Pair *);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void BR_POKESEARCH_DownloadDoneTask(int a, int *state, char *p);
extern void BR_POKESEARCH_RefreshTask(int *sys, int *state, char *p);
void BR_POKESEARCH_NetworkTask(int *task,unsigned *state,char *p)
{
    Cfg cfg;
    int out,x,y;
    Pair pair;
    switch(*state) {
    case 0:
        MI_CpuFill8(&cfg,0,8);
        cfg.heap=((struct Obj01276 *)p)->f8;
        ((struct Obj01276 *)p)->fA=0;
        BR_NET_StartRequest(*(char * *)&((struct Obj24723 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14,1,(const int *)(&cfg));
        *state=1; break;
    case 1:
        ((struct Obj01276 *)p)->fA=((struct Obj01276 *)p)->fA+1;
        if(BR_NET_IsIdle(*(char * *)&((struct Obj24724 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14) && ((struct Obj01276 *)p)->fA>0x60) {
            BR_UTIL_StartEffect(((struct Obj01276 *)p)->f38,0,0);
            *state=2;
        }
        break;
    case 2:
        if(!BR_NET_PollErrorMessage(*(char * *)&((struct Obj24725 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14,&out)) {
            if(BR_NET_GetDownloadEntries(*(char * *)&((struct Obj24726 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14,(int)(p+0x40),5,(int *)(p+0x54)) && ((struct Obj01276 *)p)->f54) {
                ((struct Obj01276 *)p)->fC=0;
                BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_DownloadDoneTask);
                break;
            }
            *state=3;
            BR_UTIL_SetWindowText(((struct Obj01276 *)p)->f4,((struct Obj24727 *)(*(char * *)&((struct Obj01276 *)p)->f34))->fC,(void *)0x14d);
        }else{
            *state=3;
            BR_UTIL_SetWindowText(((struct Obj01276 *)p)->f4,((struct Obj24728 *)(*(char * *)&((struct Obj01276 *)p)->f34))->fC,(void *)out);
        }
        break;
    case 3:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));
            pair.x=x;pair.y=y;
            BR_UTIL_StartEffect(((struct Obj01276 *)p)->f3C,1,&pair);
            GFL_USE_PlaySeDefaultVolume(0x703);
            BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_RefreshTask);
        }
        break;
    }
}
