/*
 * function: func_021B7A70
 * address: 0x021B7A70
 * packet: pkt_ov133_021B7A70
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C60 0x02035C60 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_021B7F54 0x021B7F54 thumb ov133
 *   func_021B7F00 0x021B7F00 thumb ov133
 *   func_021BA148 0x021BA148 thumb ov133
 *   func_021BA100 0x021BA100 thumb ov133
 *   func_021B8930 0x021B8930 thumb ov133
 *   func_021B8FF4 0x021B8FF4 thumb ov133
 *   func_021B7CFC 0x021B7CFC thumb ov133
 *   func_021BA18C 0x021BA18C thumb ov133
 *   func_021B8140 0x021B8140 thumb ov133
 *   func_021BA098 0x021BA098 thumb ov133
 *   func_021B8444 0x021B8444 thumb ov133
 *   func_021B82E8 0x021B82E8 thumb ov133
 *   func_021B8680 0x021B8680 thumb ov133
 *   func_021B8254 0x021B8254 thumb ov133
 *   func_021B765C 0x021B765C thumb ov133
 *   func_020061E4 0x020061E4 thumb
 *   _fflt 0x0209BDBC arm
 *   _fmul 0x0209C77C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_02035C60(void);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern void func_021B7F54(u8 *,int);
extern void func_021BA148(u8 *p, u8 *q);
extern void func_021BA100(u8 *p, u8 *q);
extern int func_021B7F00(u8 *,void *,u32);
extern int func_021B8930(u8 *);
extern int func_021B8FF4(int,int,int,float);
extern int func_021BA18C(char *p);
extern void func_021B7CFC(u8 *,int,int);
extern void func_021B8140(u8 *);
extern void func_021BA098(u8 *);
extern void func_021B8444(u8 *);
extern void func_021B82E8(u8 *,int);
extern void func_021B8680(u8 *);
extern void func_021B8254(u8 *);
extern void *func_021B765C(u8 *p, u16 base, s16 speed, u16 rx, u16 ry);
extern void func_020061E4(u32);
void func_021B7A70(u8 *p)
{
    int moved=0,other=0,hit=0,outer,n,dx,dy;
    if(((struct Obj00004 *)p)->f183C==0){((struct Obj00004 *)p)->f14=func_02035C60();((struct Obj00004 *)p)->f18=TOUCHPANEL_GetPointCont((u32 *)(p+0x1c),(u32 *)(p+0x20));}
    if(((struct Obj00004 *)p)->f14!=0 || ((struct Obj00004 *)p)->f18!=0){
        if(((struct Obj00004 *)p)->f20>176)((struct Obj00004 *)p)->f20=176;
        if(((struct Obj00004 *)p)->f20<16)((struct Obj00004 *)p)->f20=16;
        if(((struct Obj00004 *)p)->f3C==2 && *(u8 * *)&((struct Obj00004 *)p)->f38)func_021B7F54(p,1);
        else if(((struct Obj00004 *)p)->f14==1){
            hit=func_021B7F00(p,((struct Obj00004 *)p)->f1824,3);
            if(hit==1){func_021BA148(((struct Obj00004 *)p)->f1824,*(u8 * *)&((struct Obj00004 *)p)->f38);func_021BA100(((struct Obj00004 *)p)->f1820,*(u8 * *)&((struct Obj00004 *)p)->f38);func_021B7F54(p,0);}
            else other=func_021B8930(p);
        }
        if(hit==0 && other==0 && ((*(u8 * *)&((struct Obj00004 *)p)->f38==0 && ((struct Obj00004 *)p)->f14==1)||((struct Obj00004 *)p)->f3C==1)){
            dy=(s16)(((struct Obj00004 *)p)->f20-80);dx=(s16)(*(u32 *)&((struct Obj00004 *)p)->f1C-128);
            hit=func_021B8FF4(dx,dy,28,0.5384615659713745f);
            outer=func_021B8FF4(dx,dy,68,0.739130437374115f);
            if(hit==0 && outer==1){moved=1;func_021B7CFC(p,dx,dy);}
            else if((hit==0 && outer==0)||(hit==1 && outer==1)){
                if(func_021BA18C(((struct Obj00004 *)p)->f1820)==0 && ((struct Obj00004 *)p)->f3C==1 && *(u8 * *)&((struct Obj00004 *)p)->f38){
                    n=((struct Obj00004 *)p)->f182E;if(n<0)n=-n;
                    if(n<364)func_021B8140(p);
                }
            }
            if(moved==0 && ((struct Obj00004 *)p)->f14==1)func_021B7F00(p,((struct Obj00004 *)p)->f1820,2);
        }
        if(((struct Obj00004 *)p)->f14!=0 && *(u8 * *)&((struct Obj00004 *)p)->f38==0 && ((struct Obj00004 *)p)->f20>160 && *(u32 *)&((struct Obj00004 *)p)->f1C>96 && *(u32 *)&((struct Obj00004 *)p)->f1C<160){
            ((struct Obj00004 *)p)->fC=2;((struct Obj00004 *)p)->f10=0;func_020061E4(0x622);func_021BA098(p);
        }
    }else {
        dy=(s16)(((struct Obj00004 *)p)->f28-80);dx=(s16)(((struct Obj00004 *)p)->f24-128);
        hit=func_021B8FF4(dx,dy,28,0.5384615659713745f);outer=func_021B8FF4(dx,dy,68,0.739130437374115f);
        if(((struct Obj00004 *)p)->f3C==2 && *(u8 * *)&((struct Obj00004 *)p)->f38){
            if(((struct Obj00004 *)p)->f34!=10)func_021B8444(p);
            else if(hit==0 && outer==1)func_021B82E8(p,0);
            else if(hit==1)func_021B8680(p);
            else func_021B8254(p);
        }
        ((struct Obj00004 *)p)->f30=0;*(int *)&((struct Obj00004 *)p)->f38=0;((struct Obj00004 *)p)->f3C=0;((struct Obj00004 *)p)->f40=0;((struct Obj00004 *)p)->f34=10;
    }
    if(((struct Obj00004 *)p)->f182E!=0 && moved==0){
        n=((struct Obj00004 *)p)->f182C+0x10000-((struct Obj00004 *)p)->f182E;if(n<0)n+=0x10000;if(n>=0x10000)n-=0x10000;
        ((struct Obj00004 *)p)->f182C=n;func_021B765C(p,((struct Obj00004 *)p)->f182C,((struct Obj00004 *)p)->f182E,72,48);
        if(((struct Obj00004 *)p)->f182E>128 || ((struct Obj00004 *)p)->f182E<-128)((struct Obj00004 *)p)->f182E*=0.75f;
        else ((struct Obj00004 *)p)->f182E=0;
    }
    ((struct Obj00004 *)p)->f24=*(u32 *)&((struct Obj00004 *)p)->f1C;((struct Obj00004 *)p)->f28=((struct Obj00004 *)p)->f20;
}
