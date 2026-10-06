/*
 * function: func_0217C2EC
 * address: 0x0217C2EC
 * packet: pkt_ov176_0217C2EC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217D028 0x0217D028 thumb ov176
 *   func_0217D1A0 0x0217D1A0 thumb ov176
 *   func_0217D188 0x0217D188 thumb ov176
 *   func_0217D194 0x0217D194 thumb ov176
 *   func_0217D174 0x0217D174 thumb ov176
 *   func_0217CFE8 0x0217CFE8 thumb ov176
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_0217CEAC 0x0217CEAC thumb ov176
 *   func_0217CFDC 0x0217CFDC thumb ov176
 *   func_0217CFD0 0x0217CFD0 thumb ov176
 *   func_0200AE14 0x0200AE14 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200B110 0x0200B110 thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217D010 0x0217D010 thumb ov176
 *   func_0217D000 0x0217D000 thumb ov176
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_0217D2F0 0x0217D2F0 thumb ov176
 *   func_0200E918 0x0200E918 thumb
 *   func_0200AE54 0x0200AE54 thumb
 *   func_0217CC78 0x0217CC78 thumb ov176
 *   func_0217C628 0x0217C628 thumb ov176
 *   func_0200BBD8 0x0200BBD8 thumb
 *   func_0200BA38 0x0200BA38 thumb
 */
#include "../include/Obj00053.h"
#include "../include/Obj24408.h"
#include "../include/Obj24409.h"
#include "../include/Obj24410.h"
typedef unsigned char u8;
typedef unsigned u32;
extern void func_0217D028(u8 *);
extern void func_0217D1A0(u8 *,int);
extern int func_0217D188(u8 *);
extern int func_0217D194(int *p);
extern void func_0217D174(int *);
extern void func_0217CFE8(void *,int,int);
extern void func_021E8AB4(u32,u32);
typedef signed int     s32;
typedef unsigned short u16;
struct Big;
struct Obj;
struct Reg;
struct Reg2;
extern void func_0217CEAC(u8 *p, int mode);
extern int func_0217CFDC(int *p);
extern void func_0217CFD0(int *p);
extern void * func_0200AE14(void *);
extern void *func_02012EBC(struct Big *p);
extern void * func_0200BAC8(void *);
extern void func_0200B110(struct Reg2 *p, u32 id, s32 value);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
extern void func_021E8AA0(int *,int);
extern void func_0217D010(u8 *,int);
extern int func_0217D000(u8 *);
extern void func_021E8AB8(u32);
extern void func_0217D2F0(u8 *,u8 *);
extern u8 func_0200E918(const u8 *base, u32 idx);
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern void func_0217CC78(int *a, int *state, u8 *p);
extern void func_0217C628(int *sys, u32 *state, u8 *p);
extern void func_0200BBD8(struct Obj *p, int v);
extern u32 func_0200BA38(u32 v);
void func_0217C2EC(int *sys,u32 *state,u8 *p)
{
    switch(*state){
    case 0:func_0217D2F0(*(u8 * *)&((struct Obj00053 *)p)->f1BC,p);if(*(int *)&((struct Obj00053 *)p)->f10)*state=4;else{func_0217D028(p);func_0217D1A0(p,0);*state=1;}break;
    case 1:if(func_0217D188(p))*state=2;break;
    case 2:if(((struct Obj24408 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C4))->fC)*state=3;else *state=4;break;
    case 3:func_0217CFE8(p,39,1);*state=25;func_021E8AB4((u32)sys,4);break;
    case 4:{
        void *v=func_0200AE14(((struct Obj00053 *)p)->f38);
        unsigned sel=func_0200E918(*(u8 * *)&((struct Obj00053 *)p)->f34,0);
        if(sel>=func_0200AE54(v,22))func_021E8AA0(sys,(int)func_0217CC78);else *state=5;break;
    }
    case 5:func_0217CFE8(p,12,1);*state=25;func_021E8AB4((u32)sys,6);break;
    case 6:func_0217CEAC(p,1);*state=7;break;
    case 7:{
        int v=func_0217CFDC((int *)p);
        if(v!=-1){func_0217CFD0((int *)p);
            if(((struct Obj00053 *)p)->f1D0&&((struct Obj24409 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C4))->fC==0){
                switch(v){case 0:*state=23;break;case 1:*state=19;break;case 2:*state=8;break;}
            }else switch(v){case 0:*state=23;break;case 1:*state=8;break;}
        }break;
    }
    case 8:func_0217CFE8(p,17,1);*state=25;func_021E8AB4((u32)sys,9);break;
    case 9:func_0217CEAC(p,3);*state=10;break;
    case 10:{
        int v=func_0217CFDC((int *)p);
        if(v!=-1){func_0217CFD0((int *)p);switch(v){case 0:*state=11;break;case 1:*state=5;break;}}break;
    }
    case 11:func_0217CFE8(p,18,1);*state=25;func_021E8AB4((u32)sys,12);break;
    case 12:func_0217CEAC(p,3);*state=13;break;
    case 13:{
        int v=func_0217CFDC((int *)p);
        if(v!=-1){func_0217CFD0((int *)p);switch(v){case 0:*state=14;break;case 1:*state=5;break;}}break;
    }
    case 14:func_0217CFE8(p,10,2);*state=25;func_021E8AB4((u32)sys,15);break;
    case 15:func_0200B110(((struct Obj00053 *)p)->f38,10,4);func_0200BBD8(func_0200BAC8(func_02012EBC(((struct Obj00053 *)p)->f1B8)),2);func_02012DAC(*(int *)&((struct Obj00053 *)p)->f1B8);*state=16;break;
    case 16:switch((u32)func_02012DD0(*(u8 * *)&((struct Obj00053 *)p)->f1B8)){case 2:case 3:*state=17;break;case 0:case 1:break;}break;
    case 17:func_0217D1A0(p,1);func_0217CFE8(p,19,1);*state=25;func_021E8AB4((u32)sys,18);break;
    case 18:if(func_0217D194((int *)p)){func_0217D174((int *)p);*state=24;}break;
    case 19:if(func_0200BA38((u8)(((struct Obj24410 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C0))->f44)))*state=20;else *state=21;break;
    case 20:func_0217CFE8(p,16,1);*state=25;func_021E8AB4((u32)sys,22);break;
    case 21:func_0217CFE8(p,34,1);*state=25;func_021E8AB4((u32)sys,5);break;
    case 22:func_0217D010(p,4);break;
    case 23:func_021E8AA0(sys,(int)func_0217C628);break;
    case 24:func_0217D010(p,1);break;
    case 25:if(func_0217D000(p))func_021E8AB8((u32)sys);break;
    }
}
