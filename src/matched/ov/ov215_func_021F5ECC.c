/*
 * function: func_021F5ECC
 * address:  0x021F5ECC
 * packet:   pkt_021F5ECC
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   func_02005F38  0x02005F38  thumb
 *   GFL_USE_StepBgmLoad  0x020063B4  thumb
 *   func_021F5FEC  0x021F5FEC  thumb ov215
 */
#include "../include/Obj04634.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int  GFL_USE_IsBgmFading(void);
extern int GFL_USE_PushBgm(void);
extern int  func_02005F38(void);
extern u32 GFL_USE_StepBgmLoad(u8 *a0, u32 *a1, u32 a2);
extern void func_021F5FEC(void *, void *);

void func_021F5ECC(u8 *p, u8 *q)
{
    switch (((struct Obj04634 *)q)->f18) {
    case 0:
        break;
    case 1:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            ((struct Obj04634 *)q)->f18 = 0;
        }
        break;
    case 2:
        if (func_02005F38() == 0)
            ((struct Obj04634 *)q)->f18 = 0;
        break;
    case 3:
        if (GFL_USE_StepBgmLoad((u8 *)0x3F3, (u32 *)(q + 0x24), 0) != 0)
            ((struct Obj04634 *)q)->f18 = 4;
        break;
    case 4:
        break;
    case 5:
        if (GFL_USE_StepBgmLoad((u8 *)0x519, (u32 *)(q + 0x24), 0) != 0)
            ((struct Obj04634 *)q)->f18 = 6;
        break;
    case 6:
        if (func_02005F38() == 0) {
            func_021F5FEC(p, q);
            ((struct Obj04634 *)q)->f18 = 4;
        }
        break;
    case 7:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            ((struct Obj04634 *)q)->f18 = 0;
        }
        break;
    }
}
