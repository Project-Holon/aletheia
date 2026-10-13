/*
 * function: BTL_CLIENT_StepFaintMon
 * address:  0x021D2320
 * packet:   pkt_ov093_021D2320
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTLV_CORE_StartMonReset  0x021EA40C  thumb  ov093
 *   BTLV_CORE_WaitMonReset  0x021EA428  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_ResetAllEffects  0x021D646C  thumb  ov093
 */
#include "../include/Obj06240.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern void BTLV_CORE_StartMonReset(char *ctx, int a);
extern int BTLV_CORE_WaitMonReset(u32 *p);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_ResetAllEffects(void *p);

int BTL_CLIENT_StepFaintMon(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        BTLV_CORE_StartMonReset(((struct Obj06240 *)p)->f54, BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj06240 *)p)->f0, ((struct Obj06240 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonReset(((struct Obj06240 *)p)->f54)) {
            BTL_POKEPARAM_ResetAllEffects(BTL_SIDE_GetPokeByIdThunk(((struct Obj06240 *)p)->f4, (u8)(*c)));
            return 1;
        }
        break;
    }
    return 0;
}
