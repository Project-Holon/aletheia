/*
 * function: func_021B8364
 * address: 0x021B8364
 * packet: pkt_ov103_021B8364
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021B7250 0x021B7250 thumb ov101
 * func_021B727C 0x021B727C thumb ov101
 * func_021B8358 0x021B8358 thumb ov103
 * func_021B9214 0x021B9214 thumb ov103
 * func_021B8138 0x021B8138 thumb ov103
 * func_021B824C 0x021B824C thumb ov103
 * func_021B7954 0x021B7954 thumb ov103
 * func_021B8CA0 0x021B8CA0 thumb ov103
 * func_02006210 0x02006210 thumb
 * func_021B9060 0x021B9060 thumb ov103
 * func_021B8D54 0x021B8D54 thumb ov103
 * func_021B8CB0 0x021B8CB0 thumb ov103
 * func_020061E4 0x020061E4 thumb
 * func_021B8348 0x021B8348 thumb ov103
 * func_021B8338 0x021B8338 thumb ov103
 * func_021B856C 0x021B856C thumb ov103
 * func_021B82DC 0x021B82DC thumb ov103
 * func_021B6480 0x021B6480 thumb ov101
 * func_021B8A44 0x021B8A44 thumb ov103
 * d_021B925C 0x021B925C data a4
 */
#include "../include/Obj01388.h"
#include "../include/Obj22192.h"
#include "../include/Obj22194.h"
#include "../include/Obj22196.h"
#include "../include/Obj22197.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021B7250(int *);
extern int func_021B727C(int);
extern void func_021B8358(u8 *);
extern int func_021B9214(void *);
extern void func_021B8138(u8 *,void *,int,int,s16);
extern void func_021B824C(u8 *,void *,int,u8 *,s16,s16,int);
extern u8 *func_021B7954(u8 *);
extern void func_021B8CA0(u8 *,int,int);
extern void func_02006210(void);
extern void func_021B9060(int,u16);
extern int func_021B8D54(u32 *,u32 *);
extern void func_021B8CB0(u8 *,int,int,int);
extern void func_020061E4(u32);
extern void func_021B8348(u32 p, u32 a, u16 b);
extern void func_021B8338(u32 p, u32 a);
extern void func_021B856C(u8 *,u16 *),func_021B8A44(u8 *,u16 *);
extern void func_021B82DC(u8 *,u8 *,int);
extern int func_021B6480(int *);
extern u32 d_021B925C[];
void func_021B8364(u8 *p,u16 *state)
{
    u32 *pos;
    u8 *q;
    int i;
    pos=(u32 *)(p+0xa3c);
    if(func_021B7250(*(int * *)&((struct Obj01388 *)p)->fA38)==1) {
        ((struct Obj22192 *)(*(u8 * *)&((struct Obj01388 *)p)->fB0C))->fC=1;
        func_021B8358(p);
    } else if(!func_021B727C(*(int *)&((struct Obj01388 *)p)->fA38)) {
        switch(*state) {
        case 0:
            if(func_021B9214(p+0xa4c))
                func_021B8138(p+0x184,p+0x174,17,0,0);
            else if(**(void ** *)&((struct Obj01388 *)p)->fB0C)
                func_021B824C(p+0x184,p+0x174,0,*(u8 * *)&((struct Obj22194 *)(*(u8 * *)&((struct Obj01388 *)p)->fB0C))->f8,0,0,55);
            else func_021B8138(p+0x184,p+0x174,0,0,0);
            q=func_021B7954(p);
            for(i=0;i<2;i++) func_021B8CA0(q,i,0);
            func_02006210();
            func_021B9060(1,55);
            ((struct Obj01388 *)p)->f740=0;
            *state=1;
            break;
        case 1:
            if(func_021B8D54(d_021B925C,pos)) {
                func_021B9060(0,55);
                ((struct Obj01388 *)p)->f740=0;
                ((struct Obj01388 *)p)->f744=0;
                q=func_021B7954(p);
                func_021B8CA0(q,0,1);
                func_021B8CB0(q,0,pos[0],pos[1]);
                func_020061E4(0x651);
                if(func_021B9214(p+0xa4c)) {
                    func_021B8138(p+0x184,p+0x174,2,0,0);
                    func_021B9060(3,55);
                    func_021B8348((u32)p,(u32)func_021B856C,1);
                } else {
                    if(**(void ** *)&((struct Obj01388 *)p)->fB0C)
                        func_021B824C(p+0x184,p+0x174,1,*(u8 * *)&((struct Obj22196 *)(*(u8 * *)&((struct Obj01388 *)p)->fB0C))->f8,0,0,55);
                    else func_021B8138(p+0x184,p+0x174,1,0,0);
                    func_021B8338((u32)p,(u32)func_021B856C);
                }
            } else if(!func_021B9214(p+0xa4c)) {
                if((((struct Obj01388 *)p)->f740)++>=180) {
                    ((struct Obj01388 *)p)->f740=0;
                    ((struct Obj01388 *)p)->f744^=1;
                    if(((struct Obj01388 *)p)->f744) func_021B82DC(p+0x184,p,11);
                    else func_021B82DC(p+0x184,p,0);
                }
            }
            break;
        }
    }
    if(func_021B6480(*(int * *)&((struct Obj22197 *)(*(u8 * *)&((struct Obj01388 *)p)->fB0C))->f4))
        func_021B8338((u32)p,(u32)func_021B8A44);
}
