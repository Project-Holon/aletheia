/*
 * function: func_021FEC14
 * address: 0x021FEC14
 * packet: pkt_ov186_021FEC14
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: A duration local updated by the zero arm shares the final store, removing the extra branch (248 to 244 B).
 * volatile: 021FECBC writes the engine-B blend register at 04001052.
 * abi: 0204E6E0 returns the word loaded into r0 despite its asm void declaration.
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   func_0207D63C 0x0207D63C arm
 *   FADE_GetSpeed 0x0204E6E0 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   FADE_IsActive 0x0204E804 arm
 *   func_0209C0A4 0x0209C0A4 arm
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj01426.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void FADE_Start(u32,int,int,int);
extern void func_0207D63C(u32,int,int,int,int);
extern int FADE_GetSpeed(void);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern int FADE_IsActive(void);
extern int func_0209C0A4(int,int);
extern u32 _u32_div_f(u32,u32);
int func_021FEC14(char *p,int *state)
{
    switch(*state) {
    case 0: {
        int first,second,a,b,duration;
        if(((struct Obj01426 *)p)->f8==0){first=16;second=0;}
        else if(((struct Obj01426 *)p)->f8==1){first=0;second=16;}
        if(((struct Obj01426 *)p)->f8==0){a=0;b=16;}
        else if(((struct Obj01426 *)p)->f8==1){a=16;b=0;}
        FADE_Start(4,first,second,((struct Obj01426 *)p)->f18);
        func_0207D63C(0x04001050,3,7,a,b);
        ((struct Obj01426 *)p)->f10=0;
        duration=((struct Obj01426 *)p)->f18;
        if(duration==0)duration=func_0209C0A4(16,FADE_GetSpeed());
        ((struct Obj01426 *)p)->f14=duration;
        *state=1;
        break;
    }
    case 1: {
        int a,b;
        int done=1;
        if(((struct Obj01426 *)p)->f8==0){a=_u32_div_f(((struct Obj01426 *)p)->f10<<4,((struct Obj01426 *)p)->f14);b=16-a;}
        else if(((struct Obj01426 *)p)->f8==1){b=_u32_div_f(((struct Obj01426 *)p)->f10<<4,((struct Obj01426 *)p)->f14);a=16-b;}
        *(volatile u16 *)0x04001052=a|(b<<8);
        if(a==0)BG_SYS_SetSubPlaneVisible(3,0);else BG_SYS_SetSubPlaneVisible(3,1);
        done&=((((struct Obj01426 *)p)->f10)++ >= ((struct Obj01426 *)p)->f14);
        if(done & !FADE_IsActive())*state=2;
        break;
    }
    case 2:return 1;
    }
    return 0;
}
