/*
 * function: BTL_SERVER_FLOW_PushCriticalHitMessage
 * address:  0x021C59C4
 * packet:   pkt_ov093_021C59C4
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
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);

void BTL_SERVER_FLOW_PushCriticalHitMessage(u8 *p, u32 n, u8 **a, u8 *b, int flag)
{
    u32 i;
    for (i = 0; i < n; i++) {
        if (b[i]) {
            if (flag) {
                BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x180, BTL_POKEPARAM_GetPokeId(a[i]), 0xffff0000);
            } else {
                BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, 0x51, 0xffff0000);
            }
        }
    }
}
