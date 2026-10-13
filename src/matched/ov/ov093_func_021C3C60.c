/*
 * function: BTL_SERVER_FLOW_TryRegisterFieldSlot
 * address:  0x021C3C60
 * packet:   pkt_ov093_021C3C60
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The handed address 0x021C3C62 is the second label after `push {r0-r3}`
 * (0x021C3C60). The third parameter is a one-word struct passed by value
 * (its home slot is read through `add r7, sp, #0x20`).
 *
 * symbols:
 *   BTL_FIELD_RegisterStaticSlot  0x021EF8C8  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTLV_CORE_GetSlotPosition  0x021E8A98  thumb  ov093
 *   BTL_FIELD_SetStaticSlotValue  0x021EF8F8  thumb  ov093
 */
#include "../include/Obj13331.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { int x; } S;
extern int BTL_FIELD_RegisterStaticSlot(int a, S c);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int BTLV_CORE_GetSlotPosition(S c);
extern void BTL_FIELD_SetStaticSlotValue(int a, int r);

int BTL_SERVER_FLOW_TryRegisterFieldSlot(u8 *p, int a, S c, int d)
{
    int r;
    if (BTL_FIELD_RegisterStaticSlot(a, c)) {
        BTL_SERVER_CMD_Push(((struct Obj13331 *)p)->fC, 0x21, (u8)a, c.x);
        return 1;
    }
    if (d) {
        r = BTLV_CORE_GetSlotPosition(c);
        if (r != 0x1f) {
            BTL_FIELD_SetStaticSlotValue(a, r);
            BTL_SERVER_CMD_Push(((struct Obj13331 *)p)->fC, 0x22, (u8)a, r);
            return 1;
        }
    }
    return 0;
}
