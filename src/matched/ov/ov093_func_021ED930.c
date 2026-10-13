/*
 * function: BTLV_SCU_InitMonSlots
 * address:  0x021ED930
 * packet:   pkt_ov093_021ED930
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   BTL_MAIN_GetRuleSlotSpan  0x021B8640  thumb  ov093
 *   BTLV_SCU_InitMonSlot  0x021ED9A4  thumb  ov093
 */
#include "../include/Obj10122.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 BTL_MAIN_GetRule(void **p);
extern unsigned int BTL_MAIN_GetRuleSlotSpan(unsigned int **p);
struct E;
extern void BTLV_SCU_InitMonSlot(struct E *e, u8 *o, u8 k);

void BTLV_SCU_InitMonSlots(char *s)
{
    u32 i;
    u32 n;

    for (i = 0; i <= 6; i++) {
        *(u8 *)(s + i * 12 + 0x53) = 0;
        *(int *)(s + i * 12 + 0x48) = 0;
    }
    if (BTL_MAIN_GetRule(((struct Obj10122 *)s)->f134) != 3) {
        n = BTL_MAIN_GetRuleSlotSpan(((struct Obj10122 *)s)->f134);
    } else {
        n = 5;
    }
    for (i = 0; i <= n; i++) {
        BTLV_SCU_InitMonSlot((struct E *)(s + 0x48 + i * 12), (u8 *)s, i);
    }
}
