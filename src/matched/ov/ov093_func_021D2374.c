/*
 * function: BTL_CLIENT_StepReviveMon
 * address:  0x021D2374
 * packet:   pkt_ov093_021D2374
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTLV_CORE_StartMonRefresh  0x021EA438  thumb  ov093
 *   BTLV_CORE_WaitMonRefresh  0x021EA448  thumb  ov093
 */
#include "../include/Obj07782.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern void BTLV_CORE_StartMonRefresh(u32 *p, u32 a2);
extern int BTLV_CORE_WaitMonRefresh(u32 *p);

int BTL_CLIENT_StepReviveMon(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        BTLV_CORE_StartMonRefresh(((struct Obj07782 *)p)->f54, BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj07782 *)p)->f0, ((struct Obj07782 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonRefresh(((struct Obj07782 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}
