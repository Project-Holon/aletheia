/*
 * function: func_021BA190
 * address: 0x021BA190
 * packet: pkt_ov214_021BA190
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203630C 0x0203630C arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_0201CE38 0x0201CE38 thumb
 */
#include "../include/Obj04632.h"

typedef unsigned int u32;
extern unsigned func_0201CE30(void*);
typedef signed int     s32;
typedef unsigned char  u8;
struct Rec;
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void*);
extern unsigned int func_0203630C(void);
extern int TOUCHPANEL_GetCont(void);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern void func_020061E4(unsigned);
int func_021BA190(int unused,char*p)
{
    int result=0;
    switch(func_0201CE30(*(void* *)&((struct Obj04632 *)p)->f5C)){
    case 0:
        if((func_0203630C()&3)||TOUCHPANEL_GetCont()){
            func_0201CE5C(*(void* *)&((struct Obj04632 *)p)->f5C,0);
            if(func_0203630C()&3)func_020355D8(0);else func_020355D8(1);
        }
        break;
    case 1:
        if((func_020362DC()&3)||TOUCHPANEL_GetTrg()){
            func_020061E4(0x547);
            func_0201CE38(*(void* *)&((struct Obj04632 *)p)->f5C);
            if(func_020362DC()&3)func_020355D8(0);else func_020355D8(1);
        }
        break;
    case 2:
        if(((struct Obj04632 *)p)->f64)--((struct Obj04632 *)p)->f64;
        else if(((struct Obj04632 *)p)->f60){
            if((func_020362DC()&3)||TOUCHPANEL_GetTrg()){
                if(func_020362DC()&3)func_020355D8(0);else func_020355D8(1);
                ((struct Obj04632 *)p)->f60=0;
                result=1;
            }
        }else result=1;
        break;
    }
    return result;
}
