/*
 * function: BTL_SERVER_FLOW_PushSignedChangeMessage
 * address:  0x021C5A4C
 * packet:   pkt_ov093_021C5A4C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 */
#include "../include/Obj13335.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);

void BTL_SERVER_FLOW_PushSignedChangeMessage(u8 *p, u8 *a, int b, int c)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    if (c > 0) {
        BTL_SERVER_CMD_PushVariable(((struct Obj13335 *)p)->fC, 0x5b, 0x99, n, b, 0xffff0000);
    } else {
        BTL_SERVER_CMD_PushVariable(((struct Obj13335 *)p)->fC, 0x5b, 0xae, n, b, 0xffff0000);
    }
}
