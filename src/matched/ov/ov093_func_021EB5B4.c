/*
 * function: BTLV_SCU_ProcQuickEntry
 * address:  0x021EB5B4
 * packet:   pkt_ov093_021EB5B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetSlotFromViewPos  0x021B8ED8  thumb  ov093
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   BTLV_EFFECT_SetPokeSpriteKey  0x021F7EE8  thumb  ov094
 *   BTLV_SCU_ShowMonSlot  0x021EDA04  thumb  ov093
 *   BTLV_SCU_StartBrightnessFade  0x021EB584  thumb  ov093
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 */
#include "../include/Obj10117.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_MAIN_GetSlotFromViewPos(u8 *p, u8 k);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
struct E;
struct Work;
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern void BTLV_EFFECT_SetPokeSpriteKey(void *, int);
extern void BTLV_SCU_ShowMonSlot(struct E *e);
extern void BTLV_SCU_StartBrightnessFade(int);
extern int BTLV_EFFECT_IsBusy(void);
int BTLV_SCU_ProcQuickEntry(u8 *p, int *state, u8 *src, u8 n)
{
    switch (*state) {
    case 0: {
        u32 c;
        u32 i;
        u8 k;
        for (i = 0; i < n; i++) {
            c = src[i];
            k = BTL_MAIN_GetSlotFromViewPos(*(u8 * *)&((struct Obj10117 *)p)->f134, c);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon((struct Work *)BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj10117 *)p)->f138, k)), c);
            BTLV_SCU_ShowMonSlot((struct E *)(p + 0x48 + k * 12));
        }
        *state = *state + 1;
        break;
    }
    case 1:
        if (p[0x150] != 0)
            return 1;
        BTLV_SCU_StartBrightnessFade(-3);
        *state = *state + 1;
        break;
    case 2:
        if (BTLV_EFFECT_IsBusy() == 0)
            return 1;
        break;
    }
    return 0;
}
