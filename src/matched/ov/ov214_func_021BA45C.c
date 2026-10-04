/*
 * function: func_021BA45C
 * address: 0x021BA45C
 * packet: pkt_ov214_021BA45C
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: BA794's third argument is narrowed at 021BA49A..A0; caller
 * extern uses u16 despite its own source's unsigned parameter.
 * symbols:
 *   func_02035630 0x02035630 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021BA794 0x021BA794 thumb ov214
 *   func_021BA6F0 0x021BA6F0 thumb ov214
 */
#include "../include/Obj00202.h"
typedef unsigned short u16;
typedef struct {int a,b,c;} Obj;
typedef unsigned char  u8;
extern u8 func_02035630(void);
extern void func_021BA794(Obj*,char*,u16);
extern void func_021BA6F0(void *obj, char *p);
void func_021BA45C(Obj*obj,char*p)
{
    unsigned threshold;
    if(func_02035630()==30)threshold=30;else threshold=60;
    if(obj->c && !((struct Obj00202 *)p)->fB4 && (((struct Obj00202 *)p)->fAC>=threshold || *(int *)&((struct Obj00202 *)p)->fB0)){
        func_021BA794(obj,p,((struct Obj00202 *)p)->fAC/threshold);
        if(((struct Obj00202 *)p)->fAC>=threshold){
            --((struct Obj00202 *)p)->fAC;
            if(((struct Obj00202 *)p)->fAC==threshold-1)((struct Obj00202 *)p)->fB8=1;
        }else{
            --((struct Obj00202 *)p)->fB0;
            if(!((struct Obj00202 *)p)->fB0)func_021BA6F0(obj,p);
        }
    }
}
