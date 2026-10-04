/*
 * function: func_021DF060
 * address: 0x021DF060
 * packet: pkt_ov137_021DF060
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E161C 0x021E161C thumb ov137
 *   func_021E1210 0x021E1210 thumb ov137
 *   func_021E11F4 0x021E11F4 thumb ov137
 *   func_021E1400 0x021E1400 thumb ov137
 *   func_021E04C4 0x021E04C4 thumb ov137
 *   func_021E140C 0x021E140C thumb ov137
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   func_02039338 0x02039338 arm
 *   func_021E1204 0x021E1204 thumb ov137
 *   func_021E0634 0x021E0634 thumb ov137
 *   func_021E1604 0x021E1604 thumb ov137
 */
#include "../include/Obj01415.h"
#include "../include/Obj05429.h"
#include "../include/Obj23755.h"
typedef unsigned short u16;
typedef struct {int a,b;u16 values[5];u16 flag;} Msg;
extern int func_021E161C(char *);
extern int func_021E1210(char *);
extern u16 func_021E1400(char *p);
extern int func_021E04C4(char *);
extern int func_021E1204(char *);
extern void func_021E11F4(char *),func_021E140C(char *),func_021E0634(char *,int),func_021E1604(char *,int);
extern int func_021DCBC4(void *,int,void *,int);
extern u16 func_02039338(void);
int func_021DF060(char *p)
{
    char *s;
    Msg msg;
    int state,i,rate;
    state=func_021E161C(p);
    if(state==1 && func_021E1210(p)==0 && ((struct Obj01415 *)p)->f5C==0) ((struct Obj01415 *)p)->f20=1;
    if(((struct Obj01415 *)p)->f6A==1) {((struct Obj01415 *)p)->f0=28;return 1;}
    if(state==0) {
        if(((struct Obj01415 *)p)->f34 && func_021E1210(p)==0) func_021E11F4(p);
        if(func_021E1400(p)==0 && func_021E04C4(p)==1) {
            if(func_021E1210(p)==0) ((struct Obj01415 *)p)->f38=1;
            func_021E140C(p);
        }
        if(((struct Obj01415 *)p)->f38) {
            if(func_021DCBC4(((struct Obj23755 *)(*(char * *)&((struct Obj01415 *)p)->fD8))->f18,0x2807,p+0x38,1)==1) ((struct Obj01415 *)p)->f38=0;
        }
    }
    s=p+0xe0;
    if(func_02039338()==0) {
        if(((struct Obj01415 *)p)->f8<300) {
            ((struct Obj05429 *)s)->f48+=95;
            if(((struct Obj05429 *)s)->f48>=0x7000) ((struct Obj05429 *)s)->f48=0x7000;
        } else {
            ((struct Obj05429 *)s)->f48-=95;
            if(((struct Obj05429 *)s)->f48<0x4000) ((struct Obj05429 *)s)->f48=0x4000;
        }
    }
    if(func_02039338()==0) {
        msg.a=((struct Obj01415 *)p)->f11C;
        msg.flag=((struct Obj01415 *)p)->f20;
        msg.b=((struct Obj01415 *)p)->f33C;
        for(i=0;i<((struct Obj01415 *)p)->f30;i++) msg.values[i]=*(int *)(p+i*0xb4+0x2fc)/4096;
        func_021DCBC4(((struct Obj01415 *)p)->fDC,0x2808,&msg,20);
    }
    if(func_02039338()==0) {
        rate=((struct Obj01415 *)p)->f128;
        if(func_021E1204(p)==1) func_021E0634(p+0xe0,rate*2);
        else func_021E1604(p,rate);
    }
    return 0;
}
