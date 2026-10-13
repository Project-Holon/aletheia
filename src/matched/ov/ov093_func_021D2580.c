/*
 * function: BTL_CLIENT_StepUpdateMonGauge
 * address:  0x021D2580
 * packet:   pkt_ov093_021D2580
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTLV_CORE_StartMonSpriteUpdate  0x021EA384  thumb  ov093
 *   BTLV_CORE_WaitMonSpriteUpdate  0x021EA3A0  thumb  ov093
 */
#include "../include/Obj07783.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern void BTLV_CORE_StartMonSpriteUpdate(char *ctx, int a);
extern int BTLV_CORE_WaitMonSpriteUpdate(u32 *p);

int BTL_CLIENT_StepUpdateMonGauge(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        BTLV_CORE_StartMonSpriteUpdate(((struct Obj07783 *)p)->f54, BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj07783 *)p)->f0, ((struct Obj07783 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonSpriteUpdate(((struct Obj07783 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}
