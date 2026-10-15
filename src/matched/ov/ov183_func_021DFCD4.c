/*
 * function: func_021DFCD4
 * address: 0x021DFCD4
 * packet: pkt_ov183_021DFCD4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: A separate result!=3 guard around the three-case switch removes the extra 8-byte dense dispatch (460 to 452 B).
 * symbols:
 *   func_021E04C8 0x021E04C8 thumb ov183
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021E03B0 0x021E03B0 thumb ov183
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_BTN_TestHitBox 0x021FB4CC thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   BR_PROC_SYS_PushEntry 0x021F9BF4 thumb ov186
 */
#include "../include/Obj00277.h"
#include "../include/Obj00351.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern int func_021E04C8(void);
struct Sub0200852CObj;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void BR_UTIL_StartEffect(int,int,int *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021E03B0(char *,char *,int);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
extern int BR_BTN_TestHitBox(u32 *p, int a1, int a2);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
extern void BR_PROC_SYS_PushEntry(unsigned *,unsigned);
int func_021DFCD4(char *p,char *q)
{
    int result=func_021E04C8();
    if(result!=3) {
    switch(result) {
    case 0: {
        u32 x,y;
        int args[2];
        TOUCHPANEL_GetPointTrg(&x,&y);args[0]=x;args[1]=y;
        BR_UTIL_StartEffect(((struct Obj00277 *)p)->f40,1,args);
        GFL_USE_PlaySeDefaultVolume(0x703);
        ((struct Obj00351 *)q)->f18=19;
        func_021E03B0(p,q,0);
        BR_UTIL_SetWindowText(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)105);
        ((struct Obj00277 *)p)->f50=1;
        return 1;
    }
    case 1: {
        u32 x,y;
        int args[2];
        TOUCHPANEL_GetPointTrg(&x,&y);args[0]=x;args[1]=y;
        BR_UTIL_StartEffect(((struct Obj00277 *)p)->f40,1,args);
        GFL_USE_PlaySeDefaultVolume(0x703);
        ((struct Obj00351 *)q)->f14=0xffff;
        func_021E03B0(p,q,1);
        BR_UTIL_SetWindowText(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)106);
        ((struct Obj00277 *)p)->f50=2;
        return 1;
    }
    case 2: {
        void *v;
        int a,b;
        u32 x,y;
        int args[2];
        v=GAME_DATA_GetMyStatus(((struct Obj00351 *)q)->f10);
        a=func_0200856C(v);b=func_02008570(v);
        if(!a && !b) {
            BR_UTIL_SetWindowText(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)120);
            GFL_USE_PlaySeDefaultVolume(0x704);
            break;
        }
        TOUCHPANEL_GetPointTrg(&x,&y);args[0]=x;args[1]=y;
        BR_UTIL_StartEffect(((struct Obj00277 *)p)->f40,1,args);
        GFL_USE_PlaySeDefaultVolume(0x703);
        if(((struct Obj00351 *)q)->f16==255){((struct Obj00351 *)q)->f16=a;((struct Obj00351 *)q)->f17=b;}
        else{((struct Obj00351 *)q)->f16=255;((struct Obj00351 *)q)->f17=255;}
        func_021E03B0(p,q,2);
        return 0;
    }
    }
    }
    {
        u32 x,y;
        if(TOUCHPANEL_GetPointTrg(&x,&y)) {
            if(BR_BTN_HitTestWithSound((unsigned int *)(((struct Obj00277 *)p)->fC),x,y)) {
                int args[2];
                args[0]=x;args[1]=y;
                BR_UTIL_StartEffect(((struct Obj00277 *)p)->f40,1,args);
                ((struct Obj00277 *)p)->f50=-1;
                BR_PROC_SYS_PopEntry(((struct Obj00351 *)q)->fC);
                return 1;
            }
            if(BR_BTN_TestHitBox((u32 *)(((struct Obj00277 *)p)->f10),x,y)) {
                if(((struct Obj00351 *)q)->f14!=0xffff || ((struct Obj00351 *)q)->f17!=255 || ((struct Obj00351 *)q)->f18!=19) {
                    int args[2];
                    args[0]=x;args[1]=y;
                    GFL_USE_PlaySeDefaultVolume(0x703);
                    BR_UTIL_StartEffect(((struct Obj00277 *)p)->f40,1,args);
                    ((struct Obj00277 *)p)->f50=-1;
                    BR_PROC_SYS_PushEntry(*(unsigned * *)&((struct Obj00351 *)q)->fC,5);
                    return 1;
                }
                GFL_USE_PlaySeDefaultVolume(0x704);
                BR_UTIL_SetWindowText(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)108);
            }
        }
    }
    return 0;
}
