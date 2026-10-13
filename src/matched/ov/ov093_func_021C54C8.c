/*
 * function: BTL_SERVER_FLOW_PushConfusionMessage
 * address:  0x021C54C8
 * packet:   pkt_ov093_021C54C8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_PushPokeEffectAnim  0x021C5480  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_SERVER_FLOW_PushPokeEffectAnim(u8 *p, u8 *a, int b);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);

void BTL_SERVER_FLOW_PushConfusionMessage(u8 *p, u8 *a)
{
    BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 0x25B);
    BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x15C, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
}
