/*
 * function: func_021BA6A0
 * address: 0x021BA6A0
 * packet: pkt_ov214_021BA6A0
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035630 0x02035630 arm
 *   func_021BA794 0x021BA794 thumb ov214
 */
#include "../../matched/include/Obj00202.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_02035630(void);
extern void func_021BA794(void *, void *, unsigned int);
void func_021BA6A0(void *obj, char *p, u32 v)
{
    u32 threshold;
    if (func_02035630() == 30) threshold = 30;
    else threshold = 60;
    ((struct Obj00202 *)p)->fAC = threshold * (v + 1) - 1;
    ((struct Obj00202 *)p)->fB0 = threshold >> 1;
    ((struct Obj00202 *)p)->fB4 = 0;
    ((struct Obj00202 *)p)->fB8 = 0;
    ((struct Obj00202 *)p)->fBC = 0;
    ((struct Obj00202 *)p)->fC0 = 0;
    func_021BA794(obj, p, v);
}
