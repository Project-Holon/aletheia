/*
 * function: func_021FF0A0
 * address: 0x021FF0A0
 * packet: pkt_ov186_021FF0A0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Width: original caller truncates space and sine argument to u16; narrow x local retains the signed halfword update.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B4EC 0x0204B4EC arm
 *   func_0204B49C 0x0204B49C arm
 *   func_0204B5D4 0x0204B5D4 arm
 *   func_0203F684 0x0203F684 arm
 *   func_021FF038 0x021FF038 thumb ov186
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj00153.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
struct Actor;
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
typedef unsigned char  u8;
extern s16 func_0204B4EC(struct Actor *actor, u32 space, u32 axis);
extern void func_0204B49C(struct Actor *actor, s16 value, u32 space, u32 axis);
extern void func_0204B5D4(struct Actor *actor, u32 value, u32 which);
extern s16 func_0203F684(u16);
extern void func_021FF038(u8 *p, u32 mode);
void func_021FF0A0(char *p)
{
    int direction;
    s16 x;
    float value;
    ((struct Obj00153 *)p)->f28=(((struct Obj00153 *)p)->f28+1)%2;
    if(((struct Obj00153 *)p)->f28!=0)return;
    switch(((struct Obj00153 *)p)->f1C){
    case 0:
        func_0204B3DC(((struct Obj00153 *)p)->f4,1);
        ((struct Obj00153 *)p)->f24=0;
        ((struct Obj00153 *)p)->f14=((struct Obj00153 *)p)->f38;
        ((struct Obj00153 *)p)->f1C=1;
        break;
    case 1:
        if(((struct Obj00153 *)p)->f24==3){
            ((struct Obj00153 *)p)->f1C=2;
            if(func_0204B4EC(((struct Obj00153 *)p)->f4,(u16)(((struct Obj00153 *)p)->f44),0)>0)
                value=0.5f+(float)(func_0204B4EC(((struct Obj00153 *)p)->f4,(u16)(((struct Obj00153 *)p)->f44),0)<<12);
            else
                value=(float)(func_0204B4EC(((struct Obj00153 *)p)->f4,(u16)(((struct Obj00153 *)p)->f44),0)<<12)-0.5f;
            ((struct Obj00153 *)p)->f10=(int)value;
            ((struct Obj00153 *)p)->f24=0;
        }else (((struct Obj00153 *)p)->f24)++;
        break;
    case 2:
        direction=-1;
        if(((struct Obj00153 *)p)->f48!=0)direction=1;
        direction=(signed char)direction;
        if(((struct Obj00153 *)p)->f24==4){
            ((struct Obj00153 *)p)->f1C=3;
            ((struct Obj00153 *)p)->f24=0;
        }else{
            ((struct Obj00153 *)p)->f10+=-direction*func_0203F684(((struct Obj00153 *)p)->f20*65535/360);
            ((struct Obj00153 *)p)->f20+=32;
            ((struct Obj00153 *)p)->f20%=360;
            func_0204B49C(((struct Obj00153 *)p)->f4,((struct Obj00153 *)p)->f10>>12,(u16)(((struct Obj00153 *)p)->f44),0);
            (((struct Obj00153 *)p)->f24)++;
        }
        break;
    case 3:
        x=func_0204B4EC(((struct Obj00153 *)p)->f4,(u16)(((struct Obj00153 *)p)->f44),0);
        if(((struct Obj00153 *)p)->f24==0){
            ((struct Obj00153 *)p)->f2C=((struct Obj00153 *)p)->f3C-x;
            ((struct Obj00153 *)p)->f2C/=((struct Obj00153 *)p)->f3A;
            (((struct Obj00153 *)p)->f24)++;
        }else if(((struct Obj00153 *)p)->f24==((struct Obj00153 *)p)->f3A+1){
            x=((struct Obj00153 *)p)->f3C;
            ((struct Obj00153 *)p)->f1C=4;
        }else{
            x+=(s16)((struct Obj00153 *)p)->f2C;
            (((struct Obj00153 *)p)->f24)++;
        }
        func_0204B49C(((struct Obj00153 *)p)->f4,x,(u16)(((struct Obj00153 *)p)->f44),0);
        break;
    case 4:func_021FF038((u8 *)p,2);break;
    }
    if(((struct Obj00153 *)p)->f1C==3){
        if(((struct Obj00153 *)p)->f14>410){
            ((struct Obj00153 *)p)->f14-=410;
            func_0204B5D4(((struct Obj00153 *)p)->f4,((struct Obj00153 *)p)->f14,0);
        }
    }
}
