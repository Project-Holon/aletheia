/*
 * function: DELIVERY_IRC_StepFinish
 * address:  0x021579B0
 * packet:   pkt_ov010_021579B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0203F328  0x0203F328  arm
 *   DELIVERY_IRC_SetStepAtLine  0x02157960  thumb  ov010
 *   DELIVERY_IRC_StepEnd  0x021579AC  thumb  ov010
 */
#include "../include/Obj01335.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int GFL_NET_GetRunState(void);
extern void func_02082D44(void *, void *, u32);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_0203F328(u16 *p, u32 size, u32 seed);
extern void DELIVERY_IRC_SetStepAtLine(int a, int b, int c);
extern void DELIVERY_IRC_StepEnd(void);

void DELIVERY_IRC_StepFinish(u8 *p)
{
    if (GFL_NET_GetRunState() != 0)
        return;
    if (p[0x675] == 0) {
        if (((struct Obj01335 *)p)->f66C == 1) {
            p[0x674] = 3;
        } else {
            p[0x674] = 1;
            func_02082D44(p + 0x7C, ((struct Obj01335 *)p)->fC, ((struct Obj01335 *)p)->f8);
            if (((struct Obj01335 *)p)->f672 != func_0203F1FC(*(const u8 * *)&((struct Obj01335 *)p)->fC, ((struct Obj01335 *)p)->f8))
                p[0x674] = 2;
            func_0203F328(((struct Obj01335 *)p)->fC, ((struct Obj01335 *)p)->f8, ((struct Obj01335 *)p)->f668);
        }
    } else {
        if (p[0x676] == 1)
            p[0x674] = 1;
        else
            p[0x674] = 3;
    }
    DELIVERY_IRC_SetStepAtLine((int)p, (int)DELIVERY_IRC_StepEnd, 0xF8);
}
