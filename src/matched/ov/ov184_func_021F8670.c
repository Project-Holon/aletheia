/*
 * function: BR_DOWNLOAD_HandleTouch
 * address: 0x021F8670
 * packet: pkt_ov184_021F8670
 * region: ov184
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_DOWNLOAD_StepClose 0x021F8624 thumb ov184
 *   BR_DOWNLOAD_DownloadTask 0x021F86EC thumb ov184
 */
#include "../include/Obj05483.h"
#include "../include/Obj24700.h"
#include "../include/Obj24701.h"
typedef unsigned int   u32;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
extern void BR_UTIL_StartEffect(int,int,int *);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_DOWNLOAD_StepClose(int,int *,char *);
extern void BR_DOWNLOAD_DownloadTask(int *task, unsigned *state, char *p);
void BR_DOWNLOAD_HandleTouch(int a,int b,char *p)
{
    int x,y;
    if (TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))) {
        if (BR_BTN_HitTestWithSound((unsigned int *)(((struct Obj05483 *)p)->f4),x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            BR_UTIL_StartEffect(((struct Obj05483 *)p)->f18,1,pair);
            ((struct Obj24700 *)(*(char * *)&((struct Obj05483 *)p)->f30))->f1C=0;
            BR_UTIL_SetTaskStep((int *)a,(int)BR_DOWNLOAD_StepClose);
        }
        if (BR_BTN_HitTestWithSound((unsigned int *)(((struct Obj05483 *)p)->f8),x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            BR_UTIL_StartEffect(((struct Obj05483 *)p)->f18,1,pair);
            ((struct Obj24701 *)(*(char * *)&((struct Obj05483 *)p)->f30))->f1C=1;
            BR_UTIL_SetTaskStep((int *)a,(int)BR_DOWNLOAD_DownloadTask);
        }
    }
}
