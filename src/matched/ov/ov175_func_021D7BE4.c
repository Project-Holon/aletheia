/*
 * function: func_021D7BE4
 * address: 0x021D7BE4
 * packet: pkt_ov175_021D7BE4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021D9A1C 0x021D9A1C thumb ov175
 *   func_021D9A30 0x021D9A30 thumb ov175
 *   func_021D9064 0x021D9064 thumb ov175
 *   func_021D7BE4 0x021D7BE4 thumb ov175
 *   func_021D7E18 0x021D7E18 thumb ov175
 *   func_021D8E30 0x021D8E30 thumb ov175
 *   func_021D9344 0x021D9344 thumb ov175
 *   func_021D8EC8 0x021D8EC8 thumb ov175
 *   func_021D965C 0x021D965C thumb ov175
 *   func_021D97E4 0x021D97E4 thumb ov175
 *   func_021D97B8 0x021D97B8 thumb ov175
 *   func_021D98E4 0x021D98E4 thumb ov175
 *   func_021D9A08 0x021D9A08 thumb ov175
 *   func_021D99F4 0x021D99F4 thumb ov175
 *   func_021D9A50 0x021D9A50 thumb ov175
 *   func_021D95B0 0x021D95B0 thumb ov175
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj00013.h"
#include "../include/Obj24233.h"
typedef unsigned long u32;
struct Obj;
typedef unsigned char  u8;
extern void func_021E8738(int *p, int a, int b, int c);
extern void func_021E8AB4(u32,u32);
extern void func_021E8AA0(int *p, int v);
extern void func_021E8AB8(u32);
extern int func_021E8844(const int *p);
extern int func_021D9F04(char *,void *,void *);
extern void func_021D9A1C(char *,void *);
extern u32 func_021D9A30(char *);
extern void func_021D9064(void *obj, int unused, u8 *p);
extern void func_021D7E18(u32 sys, int *state, struct Obj *obj);
extern void func_021D8E30(u32 sys, int *state, char *ctx);
extern void func_021D9344(u32 sys, int *state, char *p);
extern void func_021D8EC8(u32 sys, int *state, char *p);
extern void func_021D95B0(u32 sys, int *state, char *ctx);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_021D965C(struct Obj *),func_021D97E4(char *,u32);
extern u32 func_021D97B8(char *);
extern void func_021D98E4(u32 *p, int mode);
extern void func_021D99F4(char *);
extern void func_021D9A50(char *,char *);
extern int func_021D9A08(char *);
void func_021D7BE4(u32 sys,int *state,char *p)
{
    char *q=*(char * *)&((struct Obj00013 *)p)->f104;
    int v;
    switch(*state) {
    case 0:
        switch(func_021D9F04(*(char * *)&((struct Obj00013 *)p)->f34,0,0)) {
        case 0:*state=1;break;
        case 1:case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;
        }break;
    case 1:if(((struct Obj00013 *)p)->f1C==0) {
            func_021D965C((struct Obj *)p);func_021D97E4(p,0);*state=2;
        } else *state=3;
        break;
    case 2:if(func_021D97B8(p)) *state=3;break;
    case 3:func_02040588(0,1);
        func_021E8738((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,74,1);
        func_021E8AB4(sys,4);*state=16;break;
    case 4:func_021D98E4((u32 *)p,3);*state=5;break;
    case 5:v=func_021D9A08(p);
        if(v!=-1) {
            func_021D99F4(p);
            switch(v) {
            case 0:*state=10;break;
            case 1:*state=7;break;
            case 2:*state=6;break;
            }
        }break;
    case 6:func_021E8AA0((int *)sys,(int)func_021D8E30);break;
    case 7:func_021D9A1C(p,func_021D9344);*state=8;break;
    case 8:v=func_021D9A30(p);
        if(v==1 || v==2) *state=1;
        else if(v==0) *state=9;
        else if(v==3) func_021E8AA0((int *)sys,(int)func_021D9064);
        switch(func_021D9F04(*(char * *)&((struct Obj00013 *)p)->f34,0,0)) {
        case 1:case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;
        }break;
    case 9:func_021E8AA0((int *)sys,(int)func_021D8EC8);break;
    case 10:func_021D9A50(*(char * *)&((struct Obj24233 *)q)->f14,p);
        func_021E8738((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,24,2);
        func_021E8AB4(sys,11);*state=16;break;
    case 11:func_021D9A1C(p,func_021D95B0);*state=12;break;
    case 12:v=func_021D9A30(p);
        if(v==0) *state=13;
        else if(v==1) *state=13;
        else if(v==3) func_021E8AA0((int *)sys,(int)func_021D9064);
        switch(func_021D9F04(*(char * *)&((struct Obj00013 *)p)->f34,0,0)) {
        case 1:func_021E8AA0((int *)sys,(int)func_021D7BE4);break;
        case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;
        }break;
    case 13:func_021E8AA0((int *)sys,(int)func_021D7E18);break;
    case 14:func_021E8738((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,120,1);
        *state=16;func_021E8AB4(sys,15);break;
    case 15:func_021E8AA0((int *)sys,(int)func_021D8EC8);break;
    case 16:if(func_021E8844((const int *)(((struct Obj00013 *)p)->f2C)))func_021E8AB8(sys);break;
    }
}
