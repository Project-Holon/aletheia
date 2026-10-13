/*
 * function: BTL_SERVER_FLOW_SetSickCont
 * address:  0x021C5C1C
 * packet:   pkt_ov093_021C5C1C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_SetSickCont  0x021D6034  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { int x; } S;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_POKEPARAM_SetSickCont(u8 *a, int k, S s);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int BTLV_CORE_IsSlotKind1Index15(S s);

void BTL_SERVER_FLOW_SetSickCont(u8 *p, u8 *a, int k, S s)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    BTL_POKEPARAM_SetSickCont(a, k, s);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0xf, n, (u8)k, s.x);
    if (k < 6) {
        if (k == 5 && BTLV_CORE_IsSlotKind1Index15(s)) k = 6;
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x35, n, k);
    }
}
