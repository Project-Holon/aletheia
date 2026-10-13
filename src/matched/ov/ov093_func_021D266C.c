/*
 * function: BTL_CLIENT_StepRotatePositions
 * address:  0x021D266C
 * packet:   pkt_ov093_021D266C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetSlotNthOfClient  0x021B8DEC  thumb  ov093
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTL_SIDE_GetSlotOfClient  0x021B9AEC  thumb  ov093
 *   BTL_SLOT_Swap  0x021B9C10  thumb  ov093
 *   func_021EA904  0x021EA904  thumb  ov093
 *   func_021EA950  0x021EA950  thumb  ov093
 */
#include "../include/Obj04364.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_MAIN_GetSlotNthOfClient(void *p, u32 k);
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern char *BTL_SIDE_GetSlotOfClient(char *p, int i);
extern void BTL_SLOT_Swap(u32 *p, int a, int b);
extern void func_021EA904(void *w, u32 a, u32 b, u32 c, int d, int e);
extern int func_021EA950(void *w);

int BTL_CLIENT_StepRotatePositions(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 a = c[0];
        u32 b = (u8)c[1];
        u32 d = (u8)c[2];
        int x = BTL_MAIN_GetSlotNthOfClient(((struct Obj04364 *)p)->f0, b);
        int y = BTL_MAIN_GetSlotNthOfClient(((struct Obj04364 *)p)->f0, d);
        u32 m = BTL_MAIN_GetViewPosOfSlot(((struct Obj04364 *)p)->f0, b);
        u32 n = BTL_MAIN_GetViewPosOfSlot(((struct Obj04364 *)p)->f0, d);
        BTL_SLOT_Swap((u32 *)BTL_SIDE_GetSlotOfClient(((struct Obj04364 *)p)->f4, a), x, y);
        func_021EA904(((struct Obj04364 *)p)->f54, a, m, n, x, y);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA950(((struct Obj04364 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}
