/*
 * function: func_021B7CFC
 * address: 0x021B7CFC
 * packet: pkt_ov133_021B7CFC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F768 0x0203F768 arm
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021BA25C 0x021BA25C thumb ov133
 *   func_021B765C 0x021B765C thumb ov133
 *   func_020061E4 0x020061E4 thumb
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj00220.h"
#include "../include/Obj23311.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_0203F768(int,int,int,int,int,int,int);
extern void *func_021BA184(char *p);
extern u32 func_021BA208(u8 *p);
extern u32 func_021BA20C(u8 *p);
extern int func_021BA25C(u8 *,int,int);
extern void *func_021B765C(u8 *p, u16 base, s16 speed, u16 rx, u16 ry);
extern void func_020061E4(u32);
void func_021B7CFC(u8 *p, int unused_x, int unused_y)
{
    int y0,y1,angle,hit,n;
    u8 *e,*data;
    y0=(((struct Obj00220 *)p)->f28*72)/48;
    y1=(((struct Obj00220 *)p)->f20*72)/48;
    angle=func_0203F768(((struct Obj00220 *)p)->f24,y0,((struct Obj00220 *)p)->f1C,y1,128,80,72);
    ((struct Obj00220 *)p)->f1830+=(u16)(angle<0?-angle:angle);
    if(((struct Obj00220 *)p)->f14==1 || ((struct Obj00220 *)p)->f1830>=0x71c){
        e=func_021BA184(((struct Obj00220 *)p)->f181C);hit=0;
        if(((struct Obj00220 *)p)->f14==1)*(u16 *)&((struct Obj00220 *)p)->f182E=0;
        ((struct Obj00220 *)p)->f1830=0;*(u8 * *)&((struct Obj00220 *)p)->f38=0;
        while(e){
            data=(u8 *)func_021BA20C(e);
            if(func_021BA25C(e,((struct Obj00220 *)p)->f1C,*(int *)&((struct Obj00220 *)p)->f20)==1){
                hit=1;
                if(((struct Obj23311 *)data)->fC==0){*(u8 * *)&((struct Obj00220 *)p)->f38=e;((struct Obj00220 *)p)->f3C=1;e=0;}
            }
            if(*(u8 * *)&((struct Obj00220 *)p)->f38==0)e=(u8 *)func_021BA208(e);
        }
        if(((struct Obj00220 *)p)->f14==1 && hit==1 && *(u8 * *)&((struct Obj00220 *)p)->f38==0){((struct Obj00220 *)p)->f3C=1;func_020061E4(0x557);}
    }
    if(((struct Obj00220 *)p)->f30==1){
        if((angle<0?-angle:angle)>227 && (angle<0?-angle:angle)<0x4000){
            n=((struct Obj00220 *)p)->f182C+0x10000-angle;
            if(n<0)n+=0x10000;
            if(n>=0x10000)n-=0x10000;
            ((struct Obj00220 *)p)->f182C=n;
            func_021B765C(p,((struct Obj00220 *)p)->f182C,(s16)angle,72,48);
            if(angle>=0 && ((struct Obj00220 *)p)->f182E>0 && angle<((struct Obj00220 *)p)->f182E)
                ((struct Obj00220 *)p)->f182E=(((struct Obj00220 *)p)->f182E+angle)/2;
            else if(angle<=0 && ((struct Obj00220 *)p)->f182E<0 && angle>((struct Obj00220 *)p)->f182E)
                ((struct Obj00220 *)p)->f182E=(((struct Obj00220 *)p)->f182E+angle)/2;
            else ((struct Obj00220 *)p)->f182E=angle;
            n=((struct Obj00220 *)p)->f182E;
            if((n>0 && ((struct Obj00220 *)p)->f1838>0)||(n<0 && ((struct Obj00220 *)p)->f1838<0))((struct Obj00220 *)p)->f1838=0;
            else if(n>0 && ((struct Obj00220 *)p)->f1838>-0x3000){
                if(n*15>((struct Obj00220 *)p)->f1838*-10)((struct Obj00220 *)p)->f1838-=256;
            } else if(n<0 && ((struct Obj00220 *)p)->f1838<0x3000){
                if(n*-15>((struct Obj00220 *)p)->f1838*10)((struct Obj00220 *)p)->f1838+=256;
            }
        }else ((struct Obj00220 *)p)->f182E=0;
    }
    ((struct Obj00220 *)p)->f30=1;
}
