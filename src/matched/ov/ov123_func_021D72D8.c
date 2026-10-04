/*
 * function: func_021D72D8
 * address: 0x021D72D8
 * packet: pkt_ov123_021D72D8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D57D0 0x021D57D0 thumb ov123
 *   func_021D5960 0x021D5960 thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D62D0 0x021D62D0 thumb ov123
 *   func_021D6650 0x021D6650 thumb ov123
 *   func_021D6458 0x021D6458 thumb ov123
 *   func_021D652C 0x021D652C thumb ov123
 *   func_021D7204 0x021D7204 thumb ov123
 *   func_021D7180 0x021D7180 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 */
#include "../include/Obj01254.h"
typedef unsigned short u16;
typedef struct { u16 f0; char *f4; void (*f8)(char *); } Callback;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern int func_02012DD0(u8 *p);
extern void func_021D584C(char *);
extern void func_021D57D0(char *,int,int,int);
extern void func_021D5960(char *,int,int);
extern void func_021D62B4(char *,int);
extern void func_021D62BC(char *,int,int);
extern void func_021D62D0(char *,int,int);
extern void func_021D6650(char *,int);
extern int func_020185F0(void *);
extern void func_021D6458(char *,int,int);
extern void func_021D652C(char *);
extern void func_020061E4(u32 a);
extern void func_021D7204(char *);
extern void func_021D7180(int a);
extern void func_021D6EE0(char *,int,int);
void func_021D72D8(char *p)
{
    Callback cb;
    func_02009448(((struct Obj01254 *)p)->f28);
    if (func_02012DD0(((struct Obj01254 *)p)->f2C)==2) {
        ((struct Obj01254 *)p)->fAD=0;
        ((struct Obj01254 *)p)->fAB=0;
        ((struct Obj01254 *)p)->fAE=0;
        func_021D584C(*(char * *)&((struct Obj01254 *)p)->f18);
        func_021D57D0(*(char * *)&((struct Obj01254 *)p)->f18,45,0,*(int *)&((struct Obj01254 *)p)->fC);
        func_021D5960(*(char * *)&((struct Obj01254 *)p)->f18,1,4);
        func_021D62B4(*(char * *)&((struct Obj01254 *)p)->f14,0);
        func_021D62BC(*(char * *)&((struct Obj01254 *)p)->f14,6,7);
        func_021D62BC(*(char * *)&((struct Obj01254 *)p)->f14,0,1);
        cb.f0=0; cb.f4=p; cb.f8=func_021D7204;
        func_021D62D0(*(char * *)&((struct Obj01254 *)p)->f14,0,(int)&cb);
        func_021D6650(*(char * *)&((struct Obj01254 *)p)->f14,0);
        func_021D6458(*(char * *)&((struct Obj01254 *)p)->f14,func_020185F0(((struct Obj01254 *)p)->fC),0);
        func_021D652C(*(char * *)&((struct Obj01254 *)p)->f14);
        func_020061E4(0x658);
        func_021D6EE0(p,(int)func_021D7180,0x295);
    }
}
