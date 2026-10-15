/*
 * function: SHINKA_DEMO_UpdateBgm
 * address:  0x02204DE0
 * packet:   pkt_02204DE0
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GFL_USE_StepBgmLoad 0x020063B4 thumb
 *   SHINKA_DEMO_PopBgm 0x02204F40 thumb ov195
 */
#include "../include/Obj03902.h"
#include "../include/Obj24944.h"

extern int GFL_USE_IsBgmFading(void);
extern int GFL_USE_IsBgmPlaying(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern u32 GFL_USE_StepBgmLoad(u8 *a0, u32 *a1, u32 a2);
extern void SHINKA_DEMO_PopBgm(int a, int *p);

void SHINKA_DEMO_UpdateBgm(char *a, char *b)
{
    switch (((struct Obj03902 *)b)->f30) {
    case 0:
        break;
    case 1:
        if (GFL_USE_IsBgmFading() == 0) {
            if (((struct Obj24944 *)a)->fC != 0) {
                GFL_USE_SetBgmPlayerParam((void *)1);
                GFL_USE_PushBgm();
            }
            ((struct Obj03902 *)b)->f30 = 0;
        }
        break;
    case 2:
        if (GFL_USE_IsBgmPlaying() == 0)
            ((struct Obj03902 *)b)->f30 = 0;
        break;
    case 3:
        if (GFL_USE_StepBgmLoad((u8 *)0x3f3, (u32 *)(b + 0x34), 0) != 0)
            ((struct Obj03902 *)b)->f30 = 4;
        break;
    case 4:
    case 5:
        break;
    case 6:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            ((struct Obj03902 *)b)->f30 = 0;
        }
        break;
    case 7:
        if (GFL_USE_StepBgmLoad((u8 *)0x519, (u32 *)(b + 0x34), 0) != 0)
            ((struct Obj03902 *)b)->f30 = 8;
        break;
    case 8:
        if (GFL_USE_IsBgmPlaying() == 0)
            SHINKA_DEMO_PopBgm((int)a, (int *)b);
        break;
    case 9:
        if (GFL_USE_IsBgmPlaying() == 0)
            SHINKA_DEMO_PopBgm((int)a, (int *)b);
        break;
    }
}
