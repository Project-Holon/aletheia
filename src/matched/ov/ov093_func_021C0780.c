/*
 * function: BTL_SERVER_FLOW_SetPokeCounter
 * address:  0x021C0780
 * packet:   pkt_ov093_021C0780
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_POKEPARAM_SetCounter  0x021D69A0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_POKEPARAM_SetCounter(u8 *base, int idx, u8 val);

void BTL_SERVER_FLOW_SetPokeCounter(u8 *p, u8 *a, int i, u8 v)
{
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x25, BTL_POKEPARAM_GetPokeId(a), (u8)i, v);
    BTL_POKEPARAM_SetCounter(a, i, v);
}
