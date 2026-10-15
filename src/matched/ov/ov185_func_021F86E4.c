/*
 * function: BR_POKESEARCH_HandleTouch
 * address: 0x021F86E4
 * packet: pkt_ov185_021F86E4
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_POKESEARCH_HitTab 0x021F8FC8 thumb ov185
 *   BR_POKESEARCH_HitPrev 0x021F9008 thumb ov185
 *   BR_POKESEARCH_HitNext 0x021F9048 thumb ov185
 *   BR_POKESEARCH_ExitTask 0x021F8950 thumb ov185
 *   BR_POKESEARCH_ChangeCategoryTask 0x021F8C30 thumb ov185
 *   BR_POKESEARCH_ChangePageTask 0x021F8B5C thumb ov185
 */
#include "../include/Obj02525.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
extern void BR_UTIL_StartEffect(int,int,int *);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern int BR_POKESEARCH_HitTab(int,int,int);
extern int BR_POKESEARCH_HitPrev(int,int,int);
extern int BR_POKESEARCH_HitNext(char *p, unsigned x, unsigned y);
extern void BR_POKESEARCH_ExitTask(int *sys, int *state, char *p);
extern void BR_POKESEARCH_ChangeCategoryTask(int *task, int *state, char *p);
extern void BR_POKESEARCH_ChangePageTask(int *task, int *state, char *p);
void BR_POKESEARCH_HandleTouch(int a,int b,char *p)
{
    int x,y;
    if (TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))) {
        if (BR_BTN_HitTestWithSound((unsigned int *)(((struct Obj02525 *)p)->f18),x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            BR_UTIL_StartEffect(((struct Obj02525 *)p)->f3C,1,pair);
            BR_UTIL_SetTaskStep((int *)a,(int)BR_POKESEARCH_ExitTask);
        }
        if (BR_POKESEARCH_HitTab((int)p,x,y)) BR_UTIL_SetTaskStep((int *)a,(int)BR_POKESEARCH_ChangeCategoryTask);
        if (BR_POKESEARCH_HitPrev((int)p,x,y)) {
            int index=((struct Obj02525 *)p)->fC-1;
            if (index<0) ((struct Obj02525 *)p)->fC=((struct Obj02525 *)p)->f54-1;
            else ((struct Obj02525 *)p)->fC=index;
            BR_UTIL_SetTaskStep((int *)a,(int)BR_POKESEARCH_ChangePageTask);
        }
        if (BR_POKESEARCH_HitNext((char *)((int)p),x,y)) {
            ((struct Obj02525 *)p)->fC=((struct Obj02525 *)p)->fC+1;
            ((struct Obj02525 *)p)->fC=(int)((struct Obj02525 *)p)->fC % ((struct Obj02525 *)p)->f54;
            BR_UTIL_SetTaskStep((int *)a,(int)BR_POKESEARCH_ChangePageTask);
        }
    }
}
