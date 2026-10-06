/*
 * function: func_021B856C
 * address: 0x021B856C
 * packet: pkt_ov103_021B856C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021B7250 0x021B7250 thumb ov101
 * func_021B727C 0x021B727C thumb ov101
 * func_021B8358 0x021B8358 thumb ov103
 * func_021B8D9C 0x021B8D9C thumb ov103
 * func_021B91B4 0x021B91B4 thumb ov103
 * func_021B9214 0x021B9214 thumb ov103
 * func_021B91A8 0x021B91A8 thumb ov103
 * func_021B8138 0x021B8138 thumb ov103
 * func_021B824C 0x021B824C thumb ov103
 * func_021B9060 0x021B9060 thumb ov103
 * func_021B7954 0x021B7954 thumb ov103
 * func_021B8CA0 0x021B8CA0 thumb ov103
 * func_021B8CB0 0x021B8CB0 thumb ov103
 * func_021B8338 0x021B8338 thumb ov103
 * func_021B8728 0x021B8728 thumb ov103
 * func_021B8364 0x021B8364 thumb ov103
 * func_021B8A44 0x021B8A44 thumb ov103
 * func_021B6480 0x021B6480 thumb ov101
 * func_020061E4 0x020061E4 thumb
 * d_021B925C 0x021B925C data a4
 * d_021B926C 0x021B926C data a4
 */
#include "../include/Obj04428.h"
#include "../include/Obj22198.h"
#include "../include/Obj22200.h"
#include "../include/Obj22201.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021B7250(int *);
extern int func_021B727C(int);
extern void func_021B8358(u8 *);
extern int func_021B8D9C(u32 *,u32 *);
extern int func_021B91B4(u8 *,u32 *);
extern int func_021B9214(void *);
extern void func_021B91A8(void *);
extern void func_021B8138(u8 *,void *,int,int,s16);
extern void func_021B824C(u8 *,void *,int,u8 *,s16,s16,int);
extern void func_021B9060(int,u16);
extern u8 *func_021B7954(u8 *);
extern void func_021B8CA0(u8 **p, int i, int v);
extern void func_021B8CB0(u8 *,int,int,int);
extern void func_021B8338(u32 p, u32 a);
extern void func_021B8728(u8 *,u16 *),func_021B8364(u8 *,u16 *),func_021B8A44(u8 *,u16 *);
extern int func_021B6480(int *);
extern void func_020061E4(u32);
extern u32 d_021B925C[],d_021B926C[];
void func_021B856C(u8 *p,u16 *state)
{
    u32 xy[2];
    u32 *pos;
    u8 *history,*q;
    pos=(u32 *)(p+0xa44);
    history=p+0xa4c;
    if(func_021B7250(*(int * *)&((struct Obj04428 *)p)->fA38)==1) {
        ((struct Obj22198 *)(*(u8 * *)&((struct Obj04428 *)p)->fB0C))->fC=1;
        func_021B8358(p);
    } else if(!func_021B727C(*(int *)&((struct Obj04428 *)p)->fA38)) {
        switch(*state) {
        case 0:
            if(func_021B8D9C(d_021B925C,xy)) {
                if(func_021B91B4(history,d_021B925C)) {
                    func_021B8138(p+0x184,p+0x174,2,0,0);
                    func_021B9060(3,55);
                    *state=1;
                }
                q=func_021B7954(p);
                func_021B8CA0((u8 **)q,0,1);
                func_021B8CB0(q,0,xy[0],xy[1]);
            } else {
                if(func_021B9214(history)) {
                    func_021B8138(p+0x184,p+0x174,2,0,0);
                    func_021B9060(3,55);
                    *state=1;
                } else func_021B91A8(history);
                *state=2;
            }
            break;
        case 1:
            if(func_021B8D9C(d_021B926C,pos)) {
                func_021B9060(0,55);
                if(**(void ** *)&((struct Obj04428 *)p)->fB0C)
                    func_021B824C(p+0x184,p+0x174,1,*(u8 * *)&((struct Obj22200 *)(*(u8 * *)&((struct Obj04428 *)p)->fB0C))->f8,0,0,55);
                else func_021B8138(p+0x184,p+0x174,1,0,0);
                func_021B8338((u32)p,(u32)func_021B8728);
                q=func_021B7954(p);
                func_021B8CA0((u8 **)q,1,1);
                func_021B8CB0(q,1,pos[0],pos[1]);
                func_020061E4(0x656);
            } else if(!func_021B8D9C(d_021B925C,xy)) *state=2;
            break;
        case 2:
            (((struct Obj04428 *)p)->f738)++;
            func_021B8338((u32)p,(u32)func_021B8364);
            break;
        }
    }
    if(func_021B6480(*(int * *)&((struct Obj22201 *)(*(u8 * *)&((struct Obj04428 *)p)->fB0C))->f4))
        func_021B8338((u32)p,(u32)func_021B8A44);
}
