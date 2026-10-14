/*
 * function: GURU2_MAIN_StatePlayRound
 * address: 0x021DF060
 * packet: pkt_ov137_021DF060
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_TickTimeout 0x021E161C thumb ov137
 *   GURU2_MAIN_GetEntranceEffectActive 0x021E1210 thumb ov137
 *   GURU2_MAIN_StartEntranceEffect 0x021E11F4 thumb ov137
 *   GURU2_MAIN_GetScreenFlashFlag 0x021E1400 thumb ov137
 *   GURU2_MAIN_IsTouched 0x021E04C4 thumb ov137
 *   GURU2_MAIN_StartScreenFlash 0x021E140C thumb ov137
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_MAIN_GetEntranceEffectState 0x021E1204 thumb ov137
 *   GURU2_MAIN_AddAngle 0x021E0634 thumb ov137
 *   GURU2_MAIN_RotateAll 0x021E1604 thumb ov137
 */
#include "../include/Obj01415.h"
#include "../include/Obj05429.h"
#include "../include/Obj23755.h"
typedef unsigned short u16;
typedef struct {int a,b;u16 values[5];u16 flag;} Msg;
extern int GURU2_MAIN_TickTimeout(char *);
extern int GURU2_MAIN_GetEntranceEffectActive(char *);
extern u16 GURU2_MAIN_GetScreenFlashFlag(char *p);
extern int GURU2_MAIN_IsTouched(char *);
extern int GURU2_MAIN_GetEntranceEffectState(char *);
typedef unsigned char  u8;
extern void GURU2_MAIN_StartEntranceEffect(char *);
extern void GURU2_MAIN_StartScreenFlash(char *);
extern void GURU2_MAIN_AddAngle(u8 *p, int a);
extern void GURU2_MAIN_RotateAll(char *,int);
extern int GURU2_COMM_Send(void *,int,void *,int);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
int GURU2_MAIN_StatePlayRound(char *p)
{
    char *s;
    Msg msg;
    int state,i,rate;
    state=GURU2_MAIN_TickTimeout(p);
    if(state==1 && GURU2_MAIN_GetEntranceEffectActive(p)==0 && ((struct Obj01415 *)p)->f5C==0) ((struct Obj01415 *)p)->f20=1;
    if(((struct Obj01415 *)p)->f6A==1) {((struct Obj01415 *)p)->f0=28;return 1;}
    if(state==0) {
        if(((struct Obj01415 *)p)->f34 && GURU2_MAIN_GetEntranceEffectActive(p)==0) GURU2_MAIN_StartEntranceEffect(p);
        if(GURU2_MAIN_GetScreenFlashFlag(p)==0 && GURU2_MAIN_IsTouched(p)==1) {
            if(GURU2_MAIN_GetEntranceEffectActive(p)==0) ((struct Obj01415 *)p)->f38=1;
            GURU2_MAIN_StartScreenFlash(p);
        }
        if(((struct Obj01415 *)p)->f38) {
            if(GURU2_COMM_Send(((struct Obj23755 *)(*(char * *)&((struct Obj01415 *)p)->fD8))->f18,0x2807,p+0x38,1)==1) ((struct Obj01415 *)p)->f38=0;
        }
    }
    s=p+0xe0;
    if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
        if(((struct Obj01415 *)p)->f8<300) {
            ((struct Obj05429 *)s)->f48+=95;
            if(((struct Obj05429 *)s)->f48>=0x7000) ((struct Obj05429 *)s)->f48=0x7000;
        } else {
            ((struct Obj05429 *)s)->f48-=95;
            if(((struct Obj05429 *)s)->f48<0x4000) ((struct Obj05429 *)s)->f48=0x4000;
        }
    }
    if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
        msg.a=((struct Obj01415 *)p)->f11C;
        msg.flag=((struct Obj01415 *)p)->f20;
        msg.b=((struct Obj01415 *)p)->f33C;
        for(i=0;i<((struct Obj01415 *)p)->f30;i++) msg.values[i]=*(int *)(p+i*0xb4+0x2fc)/4096;
        GURU2_COMM_Send(((struct Obj01415 *)p)->fDC,0x2808,&msg,20);
    }
    if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
        rate=((struct Obj01415 *)p)->f128;
        if(GURU2_MAIN_GetEntranceEffectState(p)==1) GURU2_MAIN_AddAngle((u8 *)(p+0xe0),rate*2);
        else GURU2_MAIN_RotateAll(p,rate);
    }
    return 0;
}
