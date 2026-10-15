/*
 * function: BTL_REC_SEL_TickTimer
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
 *   BTL_REC_SEL_DrawCounter 0x021BA794 thumb ov214
 *   BTL_REC_SEL_ResetTimer 0x021BA6F0 thumb ov214
 */
#include "../include/Obj00202.h"
typedef unsigned short u16;
typedef struct {int a,b,c;} Obj;
typedef unsigned char  u8;
extern u8 func_02035630(void);
extern void BTL_REC_SEL_DrawCounter(Obj*,char*,u16);
extern void BTL_REC_SEL_ResetTimer(void *obj, char *p);
void BTL_REC_SEL_TickTimer(Obj*obj,char*p)
{
    unsigned threshold;
    if(func_02035630()==30)threshold=30;else threshold=60;
    if(obj->c && !((struct Obj00202 *)p)->fB4 && (((struct Obj00202 *)p)->fAC>=threshold || *(int *)&((struct Obj00202 *)p)->fB0)){
        BTL_REC_SEL_DrawCounter(obj,p,((struct Obj00202 *)p)->fAC/threshold);
        if(((struct Obj00202 *)p)->fAC>=threshold){
            --((struct Obj00202 *)p)->fAC;
            if(((struct Obj00202 *)p)->fAC==threshold-1)((struct Obj00202 *)p)->fB8=1;
        }else{
            --((struct Obj00202 *)p)->fB0;
            if(!((struct Obj00202 *)p)->fB0)BTL_REC_SEL_ResetTimer(obj,p);
        }
    }
}
